// gamebryo2.2/corelibs/niparticle/nipsysemitter.cpp: NiPSysEmitter, Emitter (9 functions)

#include "../../../../include/NiPSysEmitter.h"
#include "../../../../include/NiPSysData.h"
#include "../../../../include/NiParticleSystem.h"
#include "../../../../include/NiPoint3.h"
#include "../../../../include/StrArr.h"
#include "../../../../include/NiStream.h"
#include "../../../../include/NiBinaryStream.h"
#include <windows.h>
// The stream headers do not expose these binary-reader fields yet.
inline void BinaryRead(NiBinaryStream* b, void* p)
{
    unsigned int size = 4;
    unsigned int got = (*reinterpret_cast<NiBinaryStream::ReadFunction*>(reinterpret_cast<char*>(b) + 8))(b, p, 4, &size, 1);
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(b) + 4) += got;
}
inline void ReadFloat(NiStream& s, float& f)
{
    BinaryRead(*reinterpret_cast<NiBinaryStream**>(reinterpret_cast<char*>(&s) + 0x24c), &f);
}

// @fnv 0x00c223b0
// pdb: NiPSysEmitter::LoadBinary | NiPSysEmitter.obj | retail, upstream name already matches, high
// pdb params: kStream
void NiPSysEmitter::LoadBinary(NiStream& kStream)
{
    NiPSysModifier::LoadBinary(kStream);
    ReadFloat(kStream, m_fSpeed);
    ReadFloat(kStream, m_fSpeedVar);
    ReadFloat(kStream, m_fDeclination);
    ReadFloat(kStream, m_fDeclinationVar);
    ReadFloat(kStream, m_fPlanarAngle);
    ReadFloat(kStream, m_fPlanarAngleVar);
    m_kInitialColor.LoadBinary(kStream);
    ReadFloat(kStream, m_fInitialRadius);
    if (*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(&kStream) + 0xd8) >= 0x0A030002)
        ReadFloat(kStream, m_fRadiusVar);
    ReadFloat(kStream, m_fLifeSpan);
    ReadFloat(kStream, m_fLifeSpanVar);
}

void __cdecl FUN_00c31750(void);
void __cdecl _delete(void*, unsigned int);

struct FUN_00c220a0_shell
{
    void* __thiscall FUN_00c220a0(unsigned int flags);
};

// @fnv 0x00c220a0
void* __thiscall FUN_00c220a0_shell::FUN_00c220a0(unsigned int flags)
{
    FUN_00c31750();
    if (flags & 1)
        _delete(this, 0x54);
    return this;
}

struct FUN_00c21fd0_shell : public NiPSysEmitter
{
    void* NiPSysEmitter_GetRTTI();
};

extern char const* const g_01202500_arg1;

// @fnv 0x00c21fd0
// src: COMMUNITY 0x00c21fd0
void* __thiscall FUN_00c21fd0_shell::NiPSysEmitter_GetRTTI()
{
    return (void*)&g_01202500_arg1;
}


struct Base00c319e0
{
    void FUN_00c319e0(StrArr*);
};

struct FUN_00a69720_shell
{
    char* ToString(char const*);
};

char* __cdecl _FUN_00a7d330(char const*);
char* __cdecl NiGetViewerString_00a7d550(char const*, float);

extern char const str_01044b18[];
extern char const str_010bdf30[];
extern char const str_010bdf44[];
extern char const str_010bdf50[];
extern char const str_010bdf64[];
extern char const str_010bdf74[];
extern char const str_010bdf84[];
extern char const str_010bdf9c[];
extern char const str_010bdfac[];
extern char const str_010bdfc4[];
extern char const str_010bdfd0[];

struct FUN_00c22780_shell : public Base00c319e0
{
    void NiPSysEmitter_GetViewerStrings(StrArr* pkStrings);
};

// @fnv 0x00c22780
// src: XBOX_PDB 0x00c22780
// pdb: NiPSysEmitter::GetViewerStrings | NiPSysEmitter.obj | retail, string-set bridge, high
// pdb params: pkStrings
void FUN_00c22780_shell::NiPSysEmitter_GetViewerStrings(StrArr* pkStrings)
{
    char* pString;
    unsigned int index;

    Base00c319e0::FUN_00c319e0(pkStrings);

    pString = _FUN_00a7d330(g_01202500_arg1);
    index = pkStrings->m_usSize;
    if (index >= pkStrings->m_usMaxSize)
        pkStrings->SetSize(index + pkStrings->m_usGrowBy);
    pkStrings->SetAt(index, pString);

    pString = NiGetViewerString_00a7d550(str_01044b18, *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x18));
    index = pkStrings->m_usSize;
    if (index >= pkStrings->m_usMaxSize)
        pkStrings->SetSize(index + pkStrings->m_usGrowBy);
    pkStrings->SetAt(index, pString);

    pString = NiGetViewerString_00a7d550(str_010bdfd0, *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x1c));
    index = pkStrings->m_usSize;
    if (index >= pkStrings->m_usMaxSize)
        pkStrings->SetSize(index + pkStrings->m_usGrowBy);
    pkStrings->SetAt(index, pString);

    pString = NiGetViewerString_00a7d550(str_010bdfc4, *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x20));
    index = pkStrings->m_usSize;
    if (index >= pkStrings->m_usMaxSize)
        pkStrings->SetSize(index + pkStrings->m_usGrowBy);
    pkStrings->SetAt(index, pString);

    pString = NiGetViewerString_00a7d550(str_010bdfac, *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x24));
    index = pkStrings->m_usSize;
    if (index >= pkStrings->m_usMaxSize)
        pkStrings->SetSize(index + pkStrings->m_usGrowBy);
    pkStrings->SetAt(index, pString);

    pString = NiGetViewerString_00a7d550(str_010bdf9c, *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x28));
    index = pkStrings->m_usSize;
    if (index >= pkStrings->m_usMaxSize)
        pkStrings->SetSize(index + pkStrings->m_usGrowBy);
    pkStrings->SetAt(index, pString);

    pString = NiGetViewerString_00a7d550(str_010bdf84, *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x2c));
    index = pkStrings->m_usSize;
    if (index >= pkStrings->m_usMaxSize)
        pkStrings->SetSize(index + pkStrings->m_usGrowBy);
    pkStrings->SetAt(index, pString);

    pString = reinterpret_cast<FUN_00a69720_shell*>(reinterpret_cast<char*>(this) + 0x30)->ToString(str_010bdf74);
    index = pkStrings->m_usSize;
    if (index >= pkStrings->m_usMaxSize)
        pkStrings->SetSize(index + pkStrings->m_usGrowBy);
    pkStrings->SetAt(index, pString);

    pString = NiGetViewerString_00a7d550(str_010bdf64, *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x40));
    index = pkStrings->m_usSize;
    if (index >= pkStrings->m_usMaxSize)
        pkStrings->SetSize(index + pkStrings->m_usGrowBy);
    pkStrings->SetAt(index, pString);

    pString = NiGetViewerString_00a7d550(str_010bdf50, *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x44));
    index = pkStrings->m_usSize;
    if (index >= pkStrings->m_usMaxSize)
        pkStrings->SetSize(index + pkStrings->m_usGrowBy);
    pkStrings->SetAt(index, pString);

    pString = NiGetViewerString_00a7d550(str_010bdf44, *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x48));
    index = pkStrings->m_usSize;
    if (index >= pkStrings->m_usMaxSize)
        pkStrings->SetSize(index + pkStrings->m_usGrowBy);
    pkStrings->SetAt(index, pString);

    pString = NiGetViewerString_00a7d550(str_010bdf30, *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x4c));
    index = pkStrings->m_usSize;
    if (index >= pkStrings->m_usMaxSize)
        pkStrings->SetSize(index + pkStrings->m_usGrowBy);
    pkStrings->SetAt(index, pString);
}

// Equals: thiscall bool compare of two objects (float fields + sub-object)

class FUN_00c226a0_sub
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    bool unk4a4c90(FUN_00c226a0_sub* other);
};

class FUN_00c226a0_cls
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    float m_18;
    float m_1c;
    float m_20;
    float m_24;
    float m_28;
    float m_2c;
    FUN_00c226a0_sub m_30;
    float m_40;
    float m_44;
    float m_48;
    float m_4c;
    bool unk00c31830(FUN_00c226a0_cls* other);
    bool Equals(FUN_00c226a0_cls* pkObject);
};

// @fnv 0x00c226a0
// pdb: NiPSysEmitter::IsEqual | NiPSysEmitter.obj | retail, object-file gap fill, high
// pdb params: pkObject
// pdb locals: pkDest
bool FUN_00c226a0_cls::Equals(FUN_00c226a0_cls* pkObject)
{
    if (unk00c31830(pkObject) && pkObject->m_18 == m_18 && pkObject->m_1c == m_1c && pkObject->m_20 == m_20 &&
        pkObject->m_24 == m_24 && pkObject->m_28 == m_28 && pkObject->m_2c == m_2c && !pkObject->m_30.unk4a4c90(&m_30) &&
        pkObject->m_40 == m_40 && pkObject->m_44 == m_44 && pkObject->m_48 == m_48 && pkObject->m_4c == m_4c)
        return true;
    return false;
}

// @fnv 0x00d070a0
// src: COMMUNITY 0x00d070a0
void __stdcall ThisCall_Nullsub_2Ints(int, int)
{}

extern int __cdecl FUN_00ecadb8();
extern unsigned short DAT_010be248;
extern float DAT_011aeae8;
extern float DAT_011f4ae0[];
extern float DAT_011f52e0[];
inline float RandomFloat0To1()
{
    return (float)(FUN_00ecadb8() / 32767.0);
}
inline float NiSymmetricRandom()
{
    return (float)(2.0 * FUN_00ecadb8() / 32767.0 - 1.0);
}
inline NiPoint3::NiPoint3(float fX, float fY, float fZ)
{
    x = fX;
    y = fY;
    z = fZ;
}
inline NiPoint3 NiPoint3::operator*(float fScalar) const
{
    NiPoint3 kResult;
    kResult.x = x * fScalar;
    kResult.y = y * fScalar;
    kResult.z = z * fScalar;
    return kResult;
}

struct Point3ParameterData
{
    NiPoint3 m_kValue;
    float m_fXValue;
    float m_fYValue;
    float m_fZValue;
    unsigned short m_usFlags;
    unsigned short m_usFirstValue;
};
class Emitter : public NiPSysEmitter
{
  public:
    void NiPSysEmitter_EmitParticles(float fTime, unsigned short usNumParticles, const float* pfAges);
};
inline float NiFastSin(float fAngleDifference)
{
    return DAT_011f52e0[(int)(fAngleDifference * (512.0 / DAT_011aeae8)) & 511];
}
inline float NiFastCos(float fAngleDifference)
{
    return DAT_011f4ae0[(int)(fAngleDifference * (512.0 / DAT_011aeae8)) & 511];
}
// @fnv 0x00c220c0
// src: XBOX_PDB 0x00c220c0
// pdb: NiPSysEmitter::EmitParticles | NiPSysEmitter.obj | retail, upstream name already matches, high
// pdb params: fTime, usNumParticles, pfAges
// pdb locals: pkVertex, pucTextureIndex, pkData, pfSize, pfRadii, pkColor, ucsubTexCount, us, fAge, kDir, fSinDec, fPlan, fLifeSpan, fDec, usNewIndex, pkNewParticle, fSpeed
void Emitter::NiPSysEmitter_EmitParticles(float fTime, unsigned short usNumParticles, const float* pfAges)
{
    NiPSysData* pkData = reinterpret_cast<NiPSysData*>(m_pkTarget->m_spModelData.m_pObject);
    NiPoint3* pkVertex = pkData->m_pkVertex;
    NiColorA* pkColor = pkData->m_pkColor;
    float* pfRadii = pkData->m_pfRadii;
    float* pfSizes = pkData->m_pfSizes;
    unsigned char* pucTex = pkData->m_pucTextureIndices;
    unsigned char ucTexCount = pkData->m_ucSubTextureOffsetCount;
    for (unsigned short us = 0; us < usNumParticles; us++)
    {
        float m_fFirstFloatValue = pfAges[us];
        float fLifeSpan = m_fLifeSpan + (RandomFloat0To1() - 0.5) * m_fLifeSpanVar;
        if (m_fFirstFloatValue > fLifeSpan)
            continue;
        unsigned short usNew = pkData->GetParticleVertexCount();
        if (usNew == DAT_010be248)
            break;
        Point3ParameterData* pkInfo = &pkData->m_pkParticleInfo[usNew];
        float fSpeed = m_fSpeed + (RandomFloat0To1() - 0.5) * m_fSpeedVar;
        float fDec = m_fDeclination + m_fDeclinationVar * NiSymmetricRandom();
        float fPlanar = m_fPlanarAngle + m_fPlanarAngleVar * NiSymmetricRandom();
        float fSinDec = NiFastSin(fDec);
        NiPoint3 kWorldPosition(NiFastCos(fPlanar) * fSinDec, fSinDec * NiFastSin(fPlanar), NiFastCos(fDec));
        pkInfo->m_kValue = kWorldPosition * fSpeed;
        pkInfo->m_fXValue = m_fFirstFloatValue;
        pkInfo->m_fYValue = fLifeSpan;
        pkInfo->m_usFlags = 0;
        GetPositionAndDirection(pkVertex[usNew], pkInfo->m_kValue);
        if (pkColor)
            pkColor[usNew] = m_kInitialColor;
        if (pfRadii)
            pfRadii[usNew] = (m_fInitialRadius + m_fRadiusVar * NiSymmetricRandom()) * m_fScale;
        if (pfSizes)
            pfSizes[usNew] = 1.0f;
        if (pucTex)
            pucTex[usNew] = FUN_00ecadb8() % ucTexCount;
        pkInfo->m_fZValue = fTime - pkInfo->m_fXValue;
        m_pkTarget->InitializeNewParticle(usNew);
    }
}

char* __cdecl FUN_00a5b690(const char* pcString);

extern char* g_pcC21FE0NullString;









// Constructs a particle emitter modifier, storing emission speed, declination, planar angle, color, radius, life span and their variations.
// @fnv 0x00c21fe0
NiPSysEmitter::NiPSysEmitter(const char* pcName, unsigned int uiOrder, float fEmissionSpeed, float fSpeedVar,
                                   float fDeclination, float fDeclinationVar, float fPlanarAngle, float fPlanarAngleVar,
                                   NiColorA kInitialColor, float fInitialRadius, float fLifeSpan,
                                   float fLifeSpanVar, float fRadiusVar)
    : NiPSysModifier(pcName, uiOrder), m_fSpeed(fEmissionSpeed), m_fSpeedVar(fSpeedVar),
      m_fDeclination(fDeclination), m_fDeclinationVar(fDeclinationVar),
      m_fPlanarAngle(fPlanarAngle), m_fPlanarAngleVar(fPlanarAngleVar), m_kInitialColor(kInitialColor),
      m_fInitialRadius(fInitialRadius), m_fRadiusVar(fRadiusVar), m_fLifeSpan(fLifeSpan),
      m_fLifeSpanVar(fLifeSpanVar), m_fScale(1.0f)
{}

struct EmitterColorWriter
{
    void FUN_00a698a0(NiStream& stream);
};
struct S_00c22530_BinaryStream : NiBinaryStream
{

};
struct S_00c22530_Stream : NiStream
{

};
inline void S_00c22530_BinaryRead(S_00c22530_BinaryStream* b, void* p)
{
    unsigned int size = 4;
    typedef unsigned int(__cdecl* ReadElement)(S_00c22530_BinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int got = (*reinterpret_cast<ReadElement*>(reinterpret_cast<char*>(b) + 0xc))(b, p, 4, &size, 1);
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(b) + 4) += got;
}
inline void S_00c22530_ReadFloat(S_00c22530_Stream& s, float& f)
{
    S_00c22530_BinaryRead(*reinterpret_cast<S_00c22530_BinaryStream**>(reinterpret_cast<char*>(&s) + 0x250), &f);
}
struct S_00c22530_Emitter : NiPSysEmitter
{
    void FUN_00c31950(NiStream& kStream);
    void NiPSysEmitter_SaveBinary(S_00c22530_Stream& kStream);
};
// Calls FUN_00c31950, then reads emitter fields and particle color from the stream.
// @fnv 0x00c22530
// src: XBOX_PDB 0x00c22530
// pdb: NiPSysEmitter::SaveBinary | NiPSysEmitter.obj | retail, upstream name already matches, high
// pdb params: kStream
void S_00c22530_Emitter::NiPSysEmitter_SaveBinary(S_00c22530_Stream& kStream)
{
    FUN_00c31950(kStream);
    S_00c22530_ReadFloat(kStream, m_fSpeed);
    S_00c22530_ReadFloat(kStream, m_fSpeedVar);
    S_00c22530_ReadFloat(kStream, m_fDeclination);
    S_00c22530_ReadFloat(kStream, m_fDeclinationVar);
    S_00c22530_ReadFloat(kStream, m_fPlanarAngle);
    S_00c22530_ReadFloat(kStream, m_fPlanarAngleVar);
    reinterpret_cast<EmitterColorWriter*>(&m_kInitialColor)->FUN_00a698a0(kStream);
    S_00c22530_ReadFloat(kStream, m_fInitialRadius);
    S_00c22530_ReadFloat(kStream, m_fRadiusVar);
    S_00c22530_ReadFloat(kStream, m_fLifeSpan);
    S_00c22530_ReadFloat(kStream, m_fLifeSpanVar);
}
