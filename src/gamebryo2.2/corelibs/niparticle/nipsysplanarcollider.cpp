
#include "../../../../include/NiAVObject.h"
#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/NiColor.h"
#include "../../../../include/NiPSysCollider.h"
#include "../../../../include/NiPSysPlanarCollider.h"
#include "../../../../include/NiPlane.h"
#include "../../../../include/NiStream.h"
#include "../../../../include/NiTransform.h"
#include "NiRefObject_inline.h"

inline unsigned int NiBinaryStream::Read(void* buffer, unsigned int bytes)
{
    unsigned size;
    m_uiAbsoluteCurrentPos += m_pfnRead(this, buffer, bytes, (size = bytes, &size), 1);
    return bytes;
}

inline void PlanarReadFloat(NiStream& stream, float& value)
{
    stream.m_pkIstr->Read(&value, 4);
}

// Copies the base collider and the three collider parameters into dest, then clones and ref-counts the collider at offset 0x28.
// @fnv 0x00c32510
// pdb: NiPSysCollider::CopyMembers | NiPSysCollider.obj | retail, object-file run extension, low
// pdb params: pkDest, kCloning
void NiPSysPlanarCollider::CopyMemberData(NiPSysPlanarCollider* dest, CloningProcess& process)
{
    NiPSysCollider::CreateVertexBufferSet(dest, process);

    dest->m_fBounce = m_fBounce;
    dest->m_bSpawnOnCollide = m_bSpawnOnCollide;
    dest->m_bDieOnCollide = m_bDieOnCollide;

    NiPSysCollider* sourceNext = *reinterpret_cast<NiPSysCollider**>(reinterpret_cast<char*>(this) + 0x28);
    if (sourceNext)
    {
        NiPSysCollider* next = static_cast<NiPSysCollider*>(sourceNext->MakeClone(process));

        NiPSysCollider* destNext = *reinterpret_cast<NiPSysCollider**>(reinterpret_cast<char*>(dest) + 0x28);
        if (destNext != next)
        {
            if (destNext)
            {
                destNext->DecRefCount();
            }
            *reinterpret_cast<NiPSysCollider**>(reinterpret_cast<char*>(dest) + 0x28) = next;
            if (next)
                next->IncRefCount();
        }
    }
}

// Loads the planar collider's stream fields: two floats, then two NiColor values, after the base collider's LoadBinary.
// @fnv 0x00c29770
// pdb: NiPSysPlanarCollider::LoadBinary | NiPSysPlanarCollider.obj | retail, upstream name already matches, high
// pdb params: kStream
void NiPSysPlanarCollider::LoadBinary(NiStream& kStream)
{
    NiPSysCollider::LoadBinary(kStream);
    kStream.ResetStreamState();
    PlanarReadFloat(kStream, m_fWidth);
    PlanarReadFloat(kStream, m_fHeight);
    reinterpret_cast<NiColor*>(&m_kXAxis)->LoadBinary(kStream);
    reinterpret_cast<NiColor*>(&m_kYAxis)->LoadBinary(kStream);
}

struct GlobalObjectO2_00a7b610;
extern GlobalObjectO2_00a7b610 NiPSysPlanarCollider_ms_RTTI;

// @fnv 0x00c299d0
void* __fastcall GetPlanarColliderRTTI(NiPSysPlanarCollider*, void*)
{
    return &NiPSysPlanarCollider_ms_RTTI;
}

void __cdecl _delete(void*, unsigned int);
// Releases m_pObject, destroys the NiRefObject base, and frees this with _delete when uiFlags has bit 0 set; returns this.
// @fnv 0x00c299e0
// pdb: NiPSysPlanarCollider::`scalar deleting destructor' | NiPSysPlanarCollider.obj | retail, object-file run extension, low
void* __fastcall DestroyPlanarCollider(NiPSysPlanarCollider* self, void*, unsigned int uiFlags)
{
    if (self->m_spNext.m_pObject)
        self->m_spNext.m_pObject->DecRefCount();
    ((NiRefObject*)self)->NiRefObject::~NiRefObject();
    if (uiFlags & 1)
        _delete(self, 0x100);
    return self;
}

extern float DAT_010beaf8;
inline NiPoint3 NiPoint3::operator*(float s) const
{
    NiPoint3 result;
    result.x = x * s;
    result.y = y * s;
    result.z = z * s;
    return result;
}
inline NiPoint3 NiPoint3::operator-(const NiPoint3& p) const
{
    NiPoint3 result;
    result.x = x - p.x;
    result.y = y - p.y;
    result.z = z - p.z;
    return result;
}
struct VelocityState
{
    NiPoint3 velocity;
    unsigned int unk0c, unk10, unk14, unk18;
};
struct BoundDataBlock
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    VelocityState* velocities;
};
extern "C" void ProcessColliderCollision();
typedef void (__thiscall* ProcessColliderCollisionFunction)(NiPSysCollider*, float, BoundDataBlock*, unsigned short);

// Projects the particle velocity onto the plane normal and reflects or removes the normal component, then calls FUN_00c32490.
// @fnv 0x00c29320
void __fastcall ApplyPlanarCollision(NiPSysPlanarCollider* self, void*, float time, BoundDataBlock* particles, unsigned short index)
{
    NiPoint3& velocity = particles->velocities[index].velocity;
    float dot = reinterpret_cast<NiPoint3*>(&self->m_kPlane.m_kNormal)->Dot(velocity);
    NiPoint3 projection = *reinterpret_cast<NiPoint3*>(&self->m_kPlane.m_kNormal) * dot;
    if (self->m_fCollisionTime == time && dot < DAT_010beaf8)
    {
        velocity.x -= projection.x;
        velocity.y -= projection.y;
        velocity.z -= projection.z;
    }
    else
    {
        NiPoint3 twice;
        twice.x = projection.x + projection.x;
        twice.y = projection.y + projection.y;
        twice.z = projection.z + projection.z;
        velocity.x = (float)(velocity.x - twice.x);
        velocity.y = (float)(velocity.y - twice.y);
        velocity.z = (float)(velocity.z - twice.z);
        velocity *= self->m_fBounce;
    }
    reinterpret_cast<ProcessColliderCollisionFunction>(&ProcessColliderCollision)(self, time, particles, index);
}

// The shared base header does not declare its SaveBinary override yet.
extern "C" void SaveColliderBinary();
typedef void (__thiscall* SaveColliderBinaryFunction)(NiPSysCollider*, NiStream&);

// @fnv 0x00c297f0
// pdb: NiPSysPlanarCollider::SaveBinary | NiPSysPlanarCollider.obj | retail, object-file run extension, low
// pdb params: kStream
void __fastcall SavePlanarColliderBinary(NiPSysPlanarCollider* self, void*, NiStream& stream)
{
    reinterpret_cast<SaveColliderBinaryFunction>(&SaveColliderBinary)(self, stream);
    stream.SaveLinkID(self->m_pkColliderObj);
    NiBinaryStream* io = stream.m_pkOstr;
    {
        unsigned int out1 = 4;
        io->m_uiAbsoluteCurrentPos += io->m_pfnWrite(io, &self->m_fWidth, 4, &out1, 1);
    }
    io = stream.m_pkOstr;
    {
        unsigned int out2 = 4;
        io->m_uiAbsoluteCurrentPos += io->m_pfnWrite(io, &self->m_fHeight, 4, &out2, 1);
    }
    self->m_kXAxis.SaveBinary(&stream);
    self->m_kYAxis.SaveBinary(&stream);
}

extern float DAT_011a946c;
extern float DAT_011a9478;
void* __cdecl Object_DispatchCommandFour(unsigned int size);
void* __fastcall InitializePlanarCollider(void*, int, float, int, int, void*, void*, float, float, NiPoint3, NiPoint3);
typedef NiPSysPlanarCollider* (__thiscall* InitializePlanarColliderFunction)(void*, float, int, int, void*, void*, float, float, NiPoint3, NiPoint3);

// @fnv 0x00c29a30
// pdb: NiPSysPlanarCollider::CreateClone | NiPSysPlanarCollider.obj | retail, object-file run extension, low
// pdb params: kCloning
// pdb locals: pkObject
NiPSysPlanarCollider* __fastcall CreatePlanarColliderClone(NiPSysPlanarCollider* self, void*, CloningProcess& process)
{
    NiPSysPlanarCollider* obj;
    void* mem = Object_DispatchCommandFour(0x100);
    if (mem != 0)
    {
        obj = reinterpret_cast<InitializePlanarColliderFunction>(&InitializePlanarCollider)(mem, 1.0f, 0, 0, 0, 0, 1.0f, 1.0f,
                                                     *reinterpret_cast<NiPoint3*>(&DAT_011a946c),
                                                     *reinterpret_cast<NiPoint3*>(&DAT_011a9478));
    }
    else
    {
        obj = 0;
    }
    self->CopyMemberData(obj, process);
    obj->m_fWidth = self->m_fWidth;
    obj->m_fHeight = self->m_fHeight;
    obj->m_kXAxis = self->m_kXAxis;
    obj->m_kYAxis = self->m_kYAxis;
    return obj;
}

// @fnv 0x00c29af0
// pdb: NiPSysPlanarCollider::CreateObject | NiPSysPlanarCollider.obj | retail, object-file run extension, low
// pdb locals: pkObject
int __cdecl CreatePlanarCollider()
{
    void* helper = Object_DispatchCommandFour(0x100);
    if (helper)
    {
        return reinterpret_cast<int>(reinterpret_cast<InitializePlanarColliderFunction>(&InitializePlanarCollider)(helper, 1.0f, 0, 0, 0, 0, 1.0f, 1.0f,
                                                  *reinterpret_cast<NiPoint3*>(&DAT_011a946c),
                                                  *reinterpret_cast<NiPoint3*>(&DAT_011a9478)));
    }
    return 0;
}

// @fnv 0x00c27ac0
void __fastcall LinkPlanarColliderObject(NiPSysPlanarCollider* self, void*, NiStream& stream)
{
    self->NiPSysCollider::LinkObject(stream);
    self->m_pkColliderObj = (NiAVObject*)stream.GetLoadedObject();
}

struct GlobalObjectO2_00a7b610
{
    const char* m_pcName;
};
extern GlobalObjectO2_00a7b610 NiPSysPlanarCollider_ms_RTTI;

char* NiViewerStrings_NiGetViewerString_Title(const char* pcText);
char* NiGetViewerString_00a7d5e0(const char* pcPrefix, const char* pcValue);
char* NiGetViewerString_00a7d550(const char* pcPrefix, float fValue);

// Stand-in for the NiTPrimitiveArray<char*> viewer-string array (vptr, base, max/size/esize/growby).
// Stand-in for the viewer-string NiTPrimitiveArray (vptr, base, max/size/esize/growby).
struct PlanarColliderViewerStrings
{
    void* m_ppVirtualMethodTable;
    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;

    void SetSize(unsigned int uiMaxSize);
    void SetAt(unsigned int uiIndex, char*& element);
    unsigned int SetAtGrow(unsigned int uiIndex, char*& element)
    {
        if (uiIndex >= m_usMaxSize)
            SetSize(uiIndex + m_usGrowBy);
        SetAt(uiIndex, element);
        return uiIndex;
    }
    unsigned int Add(char* element)
    {
        return SetAtGrow(m_usSize, element);
    }
};

// Appends the base collider strings plus collider object name, width, height and X/Y axis strings to pkStrings.
// @fnv 0x00c29b70
// pdb: NiPSysPlanarCollider::GetViewerStrings | NiPSysPlanarCollider.obj | retail, string-set bridge, high
// pdb params: pkStrings
// pdb locals: pcColliderObj
void __fastcall GetPlanarColliderViewerStrings(NiPSysPlanarCollider* self, void*, PlanarColliderViewerStrings* pkStrings)
{
    self->NiPSysCollider::GetViewerStrings(reinterpret_cast<NiViewerStringsArray*>(pkStrings));
    pkStrings->Add(NiViewerStrings_NiGetViewerString_Title(NiPSysPlanarCollider_ms_RTTI.m_pcName));
    NiAVObject* pkObj = self->m_pkColliderObj;
    pkStrings->Add(NiGetViewerString_00a7d5e0("Collider Object", pkObj ? pkObj->m_kName.m_kHandle : "None"));
    pkStrings->Add(NiGetViewerString_00a7d550("Width", self->m_fWidth));
    pkStrings->Add(NiGetViewerString_00a7d550("Height", self->m_fHeight));
    pkStrings->Add(static_cast<const NiPoint3&>(self->m_kXAxis).FormatToBuffer("X-Axis"));
    pkStrings->Add(static_cast<const NiPoint3&>(self->m_kYAxis).FormatToBuffer("Y-Axis"));
}

struct Call_439090_tgt : NiPoint3
{
    bool Call_439090(const NiPoint3& o);
};
// These base implementations are absent from the shared collider method declarations.
extern "C" void AreCollidersEqual();
typedef bool (__thiscall* AreCollidersEqualFunction)(NiPSysCollider*, NiPSysCollider*);

// @fnv 0x00c29870
// pdb: NiPSysPlanarCollider::IsEqual | NiPSysPlanarCollider.obj | retail, object-file gap fill, low
// pdb params: pkObject
// pdb locals: pkDest
bool __fastcall ArePlanarCollidersEqual(NiPSysPlanarCollider* self, void*, NiPSysPlanarCollider* other)
{
    if (!reinterpret_cast<AreCollidersEqualFunction>(&AreCollidersEqual)(self, other))
        return false;
    if ((self->m_pkColliderObj && !other->m_pkColliderObj) ||
        (!self->m_pkColliderObj && other->m_pkColliderObj) ||
        (self->m_pkColliderObj && other->m_pkColliderObj &&
         !self->m_pkColliderObj->IsEqual(other->m_pkColliderObj)))
        return false;
    if (self->m_fWidth != other->m_fWidth || self->m_fHeight != other->m_fHeight ||
        static_cast<Call_439090_tgt&>(self->m_kXAxis).Call_439090(other->m_kXAxis) ||
        static_cast<Call_439090_tgt&>(self->m_kYAxis).Call_439090(other->m_kYAxis))
        return false;
    return true;
}

extern "C" void RegisterColliderStreamables();
typedef bool (__thiscall* RegisterColliderStreamablesFunction)(NiPSysCollider*, NiStream&);

// @fnv 0x00c28d00
bool __fastcall RegisterPlanarColliderStreamables(NiPSysPlanarCollider* self, void*, NiStream& stream)
{
    return reinterpret_cast<RegisterColliderStreamablesFunction>(&RegisterColliderStreamables)(self, stream);
}

extern "C" double __cdecl fabs(double);
extern "C" double __cdecl pow(double, double);
inline float absf(float x)
{
    return (float)fabs(x);
}
extern "C" const double DAT_01012060;
extern "C" unsigned int DAT_012026c4;
extern "C" float DAT_012026c0;
struct PlaneVector : NiPoint3
{
    PlaneVector()
    {}
    PlaneVector(float a, float b, float c)
    {
        x = a;
        y = b;
        z = c;
    }
    PlaneVector(const NiPoint3& p)
    {
        x = p.x;
        y = p.y;
        z = p.z;
    }
    float Dot(const PlaneVector& p) const
    {
        return x * p.x + y * p.y + z * p.z;
    }
    float operator*(const PlaneVector& p) const
    {
        return x * p.x + y * p.y + z * p.z;
    }
    PlaneVector operator*(float s) const
    {
        return PlaneVector(x * s, y * s, z * s);
    }
    PlaneVector operator+(const PlaneVector& p) const
    {
        return PlaneVector(x + p.x, y + p.y, z + p.z);
    }
    PlaneVector operator-(const PlaneVector& p) const
    {
        return PlaneVector(x - p.x, y - p.y, z - p.z);
    }
    PlaneVector& operator+=(PlaneVector p)
    {
        x += p.x;
        y += p.y;
        z += p.z;
        return *this;
    }
    PlaneVector& operator-=(PlaneVector p)
    {
        x -= p.x;
        y -= p.y;
        z -= p.z;
        return *this;
    }
};
inline PlaneVector operator*(float s, const PlaneVector& p)
{
    PlaneVector r;
    const float* src = &p.y;
    float* dst = &r.x;
    for (int i = 1; i < 4; ++i)
        dst[i - 1] = s * src[i - 2];
    return r;
}

inline PlaneVector ScaleVectorD(const PlaneVector& v, float s)
{
    PlaneVector r;
    const float* a = &v.z;
    float* b = &r.z;
    for (int i = -2; i < 1; ++i)
        b[i] = s * a[i];
    return r;
}
inline float SpecialLength(const PlaneVector& p)
{
    double b = p.y;
    double a = p.x;
    double c = p.z;
    double d = a * a;
    d += b * b;
    d += c * c;
    return d;
}
inline float NiPlane::Distance(const NiPoint3& kPoint) const
{
    float d = *reinterpret_cast<const PlaneVector*>(&m_kNormal) * reinterpret_cast<const PlaneVector&>(kPoint);
    return d - m_fConstant;
}
struct RotationHelper
{
    void FUN_004b4500(PlaneVector* result, const NiPoint3* direction);
};
extern "C" void ResolveColliderTail();
typedef NiPSysCollider* (__thiscall* ResolveColliderTailFunction)(NiPSysCollider*, float, float*, BoundDataBlock*, unsigned short);

// Tests a particle against the planar collider's half-space plane, computes a collision fraction if crossing, and falls back to ResolveTail.
// @fnv 0x00c28d10
// Local method declarations for collision entry points absent from the shared header.
struct PlanarColliderFunctions : NiPSysPlanarCollider
{
    NiPSysCollider* TestCollision(float time, float* collisionTime, BoundDataBlock* data, unsigned short particleId);
};

NiPSysCollider* PlanarColliderFunctions::TestCollision(float time, float* collisionTime, BoundDataBlock* data, unsigned short particleId)
{
    bool bCollided = false;
    const PlaneVector& particle = reinterpret_cast<const PlaneVector*>(data->unk20)[particleId];
    const PlaneVector& velocity = reinterpret_cast<const PlaneVector&>(data->velocities[particleId].velocity);
    const PlaneVector& normal = reinterpret_cast<const PlaneVector&>(*reinterpret_cast<NiPoint3*>(&m_kPlane.m_kNormal));
    double planeSum;
    planeSum = normal.y * particle.y;
    const float* planeN = &normal.y;
    const float* planeP = &particle.y;
    for (int i = 2; i < 3; ++i)
        planeSum += planeN[i - 3] * planeP[i - 3];
    const float* nz = &normal.y;
    const float* pz = &particle.z;
    for (int j = 0; 1 > j; ++j)
        planeSum += nz[j + 1] * pz[j + 0];
    float distance = (float)planeSum;
    distance -= m_kPlane.m_fConstant;
    if (DAT_010beaf8 > distance && DAT_010beaf8 > -distance)
    {
        PlaneVector relative = particle - reinterpret_cast<const PlaneVector&>(m_kPosition);
        PlaneVector xAxis, yAxis;
        reinterpret_cast<RotationHelper*>(layoutPadding74)->FUN_004b4500(&xAxis, &m_kXAxis);
        reinterpret_cast<RotationHelper*>(layoutPadding74)->FUN_004b4500(&yAxis, &m_kYAxis);
        NiPoint3 kAlongX = (NiPoint3)xAxis * (float)(double)(relative * xAxis);
        NiPoint3 kAlongY = (NiPoint3)yAxis * (float)(double)(yAxis * relative);
        if (kAlongX.Dot(kAlongX) < m_fHalfSqScaledWidth && kAlongY.Dot(kAlongY) < m_fHalfSqScaledHeight)
        {
            *collisionTime = time;
            m_fCollisionTime = time;
            reinterpret_cast<PlaneVector&>(m_kCollisionPoint) = particle;
            return this;
        }
    }
    else
    {
        float duration;
        duration = *collisionTime - time;
        PlaneVector delta;
        delta.x = duration * velocity.x;
        delta.y = duration * velocity.y;
        delta.z = duration * velocity.z;
        double projectedSum = delta.y * planeN[0];
        const float* nn1 = &normal.x;
        const float* dd1 = &delta.x;
        for (int l1 = 2; l1 < 3; ++l1)
            projectedSum += nn1[l1 - (2)] * dd1[l1 - (2)];
        const float* nn2 = &normal.z;
        const float* dd2 = &delta.z;
        for (int l2 = 2; l2 < 3; ++l2)
            projectedSum += nn2[l2 - (2)] * dd2[l2 - (2)];
        float projected = (float)projectedSum;
        float terminalDistance = projected + distance;
        if (absf(terminalDistance) < DAT_010beaf8)
            terminalDistance = 0.0f;
        if (terminalDistance * distance < DAT_01012060)
        {
            float fraction = (-distance * duration) / projected;
            PlaneVector hitDelta;
            hitDelta.x = fraction * velocity.x;
            hitDelta.y = fraction * velocity.y;
            hitDelta.z = fraction * velocity.z;
            PlaneVector hit;
            hit.x = particle.x + hitDelta.x;
            hit.y = particle.y + hitDelta.y;
            hit.z = particle.z + hitDelta.z;
            if (!(DAT_012026c4 & 1u))
            {
                DAT_012026c4 |= 1u;
                double fTolInit = (float)pow(2.0, -21.0);
                DAT_012026c0 = fTolInit;
            }
            float adjustedDistance;
            adjustedDistance = m_kPlane.Distance(hit);
            if (adjustedDistance * distance < DAT_01012060)
            {
                double absX = absf(hit.x);
                float maxCoord = absX;
                float fAbsY = absf(hit.y);
                if (fAbsY > maxCoord)
                    maxCoord = fAbsY;
                float fAbsZ;
                fAbsZ = absf(hit.z);
                maxCoord = (fAbsZ > maxCoord) ? fAbsZ : maxCoord;
                if (distance < 0.0f)
                {
                    hit -= ScaleVectorD(normal, maxCoord * DAT_012026c0);
                }
                else
                {
                    hit += (maxCoord * DAT_012026c0) * normal;
                }
            }
            PlaneVector relative = hit - reinterpret_cast<const PlaneVector&>(m_kPosition);
            PlaneVector xAxis, yAxis;
            reinterpret_cast<RotationHelper*>(layoutPadding74)->FUN_004b4500(&xAxis, &m_kXAxis);
            reinterpret_cast<RotationHelper*>(layoutPadding74)->FUN_004b4500(&yAxis, &m_kYAxis);
            PlaneVector kAlongX = xAxis * (relative * xAxis);
            PlaneVector kAlongY = yAxis * (yAxis * relative);
            if (SpecialLength(kAlongX) < m_fHalfSqScaledWidth && SpecialLength(kAlongY) < m_fHalfSqScaledHeight)
            {
                *collisionTime = fraction + time;
                reinterpret_cast<PlaneVector&>(m_kCollisionPoint) = hit;
                bCollided = true;
                m_fCollisionTime = fraction + time;
            }
        }
    }
    NiPSysCollider* result;
    result = reinterpret_cast<ResolveColliderTailFunction>(&ResolveColliderTail)(this, time, collisionTime, data, particleId);
    return result ? result : (bCollided ? this : 0);
}

struct Mat36
{
    int d[9];
};

extern int DAT_010beb0c;
extern NiPoint3 _NiPoint3_ZERO;
extern Mat36 DAT_011a9448;

extern "C" void InitializeCollider();
typedef void (__thiscall* InitializeColliderFunction)(NiPSysCollider*, float, int, int, void*);

// Calls the base initializer, stores the collider object and axis vectors, initializes plane and matrix data, and resets two transforms.
// @fnv 0x00c29900
// pdb: NiPSysPlanarCollider::NiPSysPlanarCollider | NiPSysPlanarCollider.obj | retail, call graph, low
// pdb params: fBounce, bSpawnOnCollide, bDieOnCollide, pkSpawnModifier, pkColliderObj, fWidth, fHeight, kXAxis, kYAxis
void* __fastcall InitializePlanarCollider(void* this_ptr, int, float fBounce, int bSpawnOnCollide, int bDieOnCollide,
                              void* pkSpawnModifier, void* pkColliderObj, float m_fGlyphWidthInPixels, float m_fGlyphExtent, NiPoint3 kXAxis,
                              NiPoint3 kYAxis)
{
    reinterpret_cast<InitializeColliderFunction>(&InitializeCollider)(static_cast<NiPSysCollider*>(this_ptr), fBounce, bSpawnOnCollide, bDieOnCollide, pkSpawnModifier);
    *(int**)this_ptr = &DAT_010beb0c;
    *(void**)((char*)this_ptr + 0x2c) = pkColliderObj;
    *(float*)((char*)this_ptr + 0x30) = m_fGlyphWidthInPixels;
    *(float*)((char*)this_ptr + 0x34) = m_fGlyphExtent;
    *(NiPoint3*)((char*)this_ptr + 0x38) = kXAxis;
    *(NiPoint3*)((char*)this_ptr + 0x44) = kYAxis;
    *(float*)((char*)this_ptr + 0x50) = 0.5f;
    *(float*)((char*)this_ptr + 0x54) = 0.5f;
    ((NiPlane*)((char*)this_ptr + 0x58))->NiPlane::NiPlane(_NiPoint3_ZERO, 0.0f);
    *(NiPoint3*)((char*)this_ptr + 0x68) = _NiPoint3_ZERO;
    *(Mat36*)((char*)this_ptr + 0x74) = DAT_011a9448;
    ((NiTransform*)((char*)this_ptr + 0x98))->ResetToIdentity();
    ((NiTransform*)((char*)this_ptr + 0xcc))->ResetToIdentity();
    return this_ptr;
}
