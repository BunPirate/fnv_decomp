#include "../../../../../../include/hkArray.h"

// src/havok/physics/dynamics/constraint/constraintkit/hkpconstraintconstructionkit.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/constraint/constraintkit/hkpconstraintconstructionkit.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// Exe 0x00d524d0 FUN_00d524d0: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    double m128_f64[2];
} __m128, LocalM128;

extern "C" LocalM128 _mm_setr_ps(float x, float y, float z, float w);
extern "C" void _mm_store_ps(float* p, LocalM128 v);

#include "../../../../../../include/hkVector4.h"

__forceinline void hkVector4::set(float x, float y, float z, float w)
{
    m_vComponents = _mm_setr_ps(x, y, z, w);
}

struct FUN_00d522b0_Ctx
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    void* m_10;
};

struct FUN_00d522b0_Vec
{
    void* m_ptr;
    int m_uiItemCount;
    int m_cap;
};

struct FUN_00d522b0_P
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    FUN_00d522b0_Vec m_verts;
    FUN_00d522b0_Vec m_cmds;
};

extern void* __cdecl hkMemoryRouter_getInstance(void);
extern void __cdecl ResizeAudioStream(void* mem, void* array, int sizeElem);

struct FUN_00d522b0_cls
{
    int m_00;
    FUN_00d522b0_P* m_04;
    int hkpConstraintConstructionKit_setAngularLimit(unsigned char axis, float aX, float aY);
};

// @fnv 0x00d522b0
// src: XBOX_RETAIL_PDB 0x00d522b0
// pdb: hkpConstraintConstructionKit::setAngularLimit | hkpConstraintConstructionKit.obj | retail, object-file gap fill, high
// pdb params: axis, min, max
// pdb locals: limit, assertBuf, ostr
int FUN_00d522b0_cls::hkpConstraintConstructionKit_setAngularLimit(unsigned char axis, float aX, float aY)
{
    FUN_00d522b0_Vec* pCmds = &m_04->m_cmds;
    FUN_00d522b0_Ctx* ctx = (FUN_00d522b0_Ctx*)hkMemoryRouter_getInstance();
    if (pCmds->m_uiItemCount == (pCmds->m_cap & 0x3fffffff))
        ResizeAudioStream(ctx->m_10, pCmds, 4);
    int* piSlot = (int*)pCmds->m_ptr + pCmds->m_uiItemCount;
    *piSlot = 0x11;
    *piSlot = 0x11;
    ++pCmds->m_uiItemCount;

    int flag = axis;

    pCmds = &m_04->m_cmds;
    ctx = (FUN_00d522b0_Ctx*)hkMemoryRouter_getInstance();
    if (pCmds->m_uiItemCount == (pCmds->m_cap & 0x3fffffff))
        ResizeAudioStream(ctx->m_10, pCmds, 4);
    int* piFlagSlot = (int*)pCmds->m_ptr + pCmds->m_uiItemCount;
    *piFlagSlot = flag;
    *piFlagSlot = flag;
    ++pCmds->m_uiItemCount;

    LocalM128 v = _mm_setr_ps(aX, aY, 0.0f, 0.0f);
    int iOldVertexCount = m_04->m_verts.m_uiItemCount;

    FUN_00d522b0_Vec* vert = &m_04->m_verts;
    ctx = (FUN_00d522b0_Ctx*)hkMemoryRouter_getInstance();
    if (vert->m_uiItemCount == (vert->m_cap & 0x3fffffff))
        ResizeAudioStream(ctx->m_10, vert, 16);
    _mm_store_ps((float*)((char*)vert->m_ptr + (vert->m_uiItemCount << 4)), v);
    ++vert->m_uiItemCount;

    FUN_00d522b0_P* p = m_04;
    p->m_04 += 0x30;
    p->m_08 += 1;
    p->m_0c += 1;
    return iOldVertexCount;
}

struct FUN_00d52140_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    unsigned char m_18;
    unsigned char m_19;
    int hkpConstraintConstructionKit_setPivotA(hkVector4* pivot);
    void hkpConstraintConstructionKit_setPivotB(hkVector4* t);
    int hkpConstraintConstructionKit_setPivotsHelper(char* bodyA, char* bodyB, const LocalM128* pivot);
};

// @fnv 0x00d52140
// src: HAVOK_LIB 0x00d52140
// pdb: hkpConstraintConstructionKit::setPivotsHelper | hkpConstraintConstructionKit.obj | retail, upstream name already matches, high
// pdb params: bodyA, bodyB, pivot
// pdb locals: attachB, attachA
int FUN_00d52140_cls::hkpConstraintConstructionKit_setPivotsHelper(char* bodyA, char* bodyB, const LocalM128* pivot)
{
    hkVector4 t1;
    hkVector4 t2;
    t1.hkVector4_setTransformedInversePos((const hkTransform*)(bodyA + 0xf0), (const hkVector4*)pivot);
    t2.hkVector4_setTransformedInversePos((const hkTransform*)(bodyB + 0xf0), (const hkVector4*)pivot);
    int iResult = this->hkpConstraintConstructionKit_setPivotA(&t1);
    this->hkpConstraintConstructionKit_setPivotB(&t2);
    this->m_18 = 1;
    this->m_19 = 1;
    return iResult;
}

struct hkMemoryAllocatorD;

struct hkMemoryRouterD
{
    unsigned int unk, unkCur, unkValue, unk0C;
    hkMemoryAllocatorD* m_pStreamAllocator;

    hkMemoryAllocatorD& heap()
    {
        return *m_pStreamAllocator;
    }
};

void __cdecl ResizeAudioStream(hkMemoryAllocatorD* mem, void* array, int sizeElem);

template <class T> __forceinline void constructWithCopyD(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++)
    {
        p[i] = t;
    }
}

template <class T>
static __forceinline void hkArrayD_AddBack(hkArrayBase<T>& self, const T& t)
{
        hkMemoryAllocatorD& kAlloc = static_cast<hkMemoryRouterD*>(hkMemoryRouter_getInstance())->heap();
        if (self.m_iElementCount == self.getCapacity())
        {
            ResizeAudioStream(&kAlloc, (&self), sizeof(T));
        }
        constructWithCopyD<T>(self.m_data + self.m_iElementCount, 1, t);
        self.m_iElementCount++;
    }

struct hkGeometryBufferD
{
    unsigned int unk;
    int m_iNumBytes;
    int m_iNumCommands;
    int m_iNumParams;
    hkArrayBase<hkVector4> m_params;
    hkArrayBase<int> m_commands;
};

class hkCommandWriterD
{
  public:
    int hkpConstraintConstructionKit_setLinearLimit(unsigned char axis, float fX, float fY);

    unsigned int unk;
    hkGeometryBufferD* m_pBuffer;
};

// Appends a command and a 2D vector parameter to the geometry buffer, updates byte/command/param counts, and returns the parameter index.
// @fnv 0x00d521b0
// src: XBOX_RETAIL_PDB 0x00d521b0
// pdb: hkpConstraintConstructionKit::setLinearLimit | hkpConstraintConstructionKit.obj | retail, object-file gap fill, high
// pdb params: axis, min, max
// pdb locals: limit, assertBuf, ostr
int hkCommandWriterD::hkpConstraintConstructionKit_setLinearLimit(unsigned char axis, float fX, float fY)
{
    hkArrayD_AddBack(m_pBuffer->m_commands, 0x10);
    hkArrayD_AddBack<int>(m_pBuffer->m_commands, axis);
    const int iIndex = m_pBuffer->m_params.GetLogicalSize();
    hkVector4 kParam;
    kParam.set(fX, fY, 0.0f, 0.0f);
    hkArrayD_AddBack(m_pBuffer->m_params, kParam);
    hkGeometryBufferD* pkBuffer = m_pBuffer;
    pkBuffer->m_iNumBytes += 0x40;
    pkBuffer->m_iNumCommands += 1;
    pkBuffer->m_iNumParams += 1;
    return iIndex;
}

#include <math.h>
inline void FillWords328(int* dest, int n, const int& value)
{
    for (int i = 0; i < n; ++i)
        dest[i] = value;
}

extern float DAT_01011d78;
extern float DAT_01016410;

struct Draw328_Holder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void* m_pAllocator;
};

struct Draw328_intarr
{
    int* data;
    int count;
    unsigned int capFlags;
};

struct Draw328_vecarr
{
    LocalM128* data;
    int count;
    unsigned int capFlags;
};

struct Draw328_mgr
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Draw328_vecarr m_vec;
    Draw328_intarr m_auiHeaderValues;
};

struct Draw328_cls
{
    int unk00;
    Draw328_mgr* m_pMgr;

    unsigned int hkpConstraintConstructionKit_setConeLimit(unsigned char axis, float angle);
};

// Appends 0x12 and a1 to m_auiHeaderValues, appends a cosf(a2) vector to m_vec, and returns the previous m_vec count.
// @fnv 0x00d523b0
// src: XBOX_RETAIL_PDB 0x00d523b0
// pdb: hkpConstraintConstructionKit::setConeLimit | hkpConstraintConstructionKit.obj | retail, object-file gap fill, high
// pdb params: axis, angle
// pdb locals: limit, assertBuf, ostr
unsigned int Draw328_cls::hkpConstraintConstructionKit_setConeLimit(unsigned char axis, float angle)
{
    Draw328_intarr* ints = &m_pMgr->m_auiHeaderValues;
    Draw328_Holder* holder = (Draw328_Holder*)hkMemoryRouter_getInstance();
    if (ints->count == (int)(ints->capFlags & 0x3fffffffu))
    {
        ResizeAudioStream(holder->m_pAllocator, ints, 4);
    }
    FillWords328(ints->data + ints->count, 1, 0x12);
    ++ints->count;

    int tag = axis;
    ints = &m_pMgr->m_auiHeaderValues;
    holder = (Draw328_Holder*)hkMemoryRouter_getInstance();
    if (ints->count == (int)(ints->capFlags & 0x3fffffffu))
    {
        ResizeAudioStream(holder->m_pAllocator, ints, 4);
    }
    FillWords328(ints->data + ints->count, 1, tag);
    ++ints->count;

    float x = cosf(angle);
    LocalM128 v = _mm_setr_ps(x, DAT_01016410, DAT_01011d78, DAT_01011d78);

    Draw328_mgr* mgr = m_pMgr;
    unsigned int uiIndex = (unsigned int)mgr->m_vec.count;

    Draw328_vecarr* vec = &mgr->m_vec;
    holder = (Draw328_Holder*)hkMemoryRouter_getInstance();
    if (vec->count == (int)(vec->capFlags & 0x3fffffffu))
    {
        ResizeAudioStream(holder->m_pAllocator, vec, 0x10);
    }
    vec->data[vec->count] = v;
    vec->count++;

    mgr = m_pMgr;
    mgr->unk04 += 0x30;
    mgr->unk08++;
    mgr->unk0c++;
    return uiIndex;
}

struct hkMemAlloc;

struct MemRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    hkMemAlloc* m_pStreamAllocator;
    hkMemAlloc& heap()
    {
        return *m_pStreamAllocator;
    }
};

__forceinline MemRouter* getRouter()
{
    return (MemRouter*)hkMemoryRouter_getInstance();
}

template <class T> __forceinline void hkConstructWithCopy(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++)
    {
        p[i] = t;
    }
}


// hkContainerHeapAllocator::get: hkMemoryRouter::getInstance().heap() (the unit's MemRouter stand-in).
__forceinline hkMemoryAllocator& hkContainerHeapAllocator::get(const void*)
{
    return reinterpret_cast<hkMemoryAllocator&>(getRouter()->heap());
}
template <class T> __forceinline void hkArrayBase<T>::_pushBack(hkMemoryAllocator& alloc, const T& t)
{
    if (m_iElementCount == getCapacity())
    {
        ResizeAudioStream(&alloc, this, sizeof(T));
    }
    hkConstructWithCopy(m_data + m_iElementCount, 1, t);
    m_iElementCount++;
}

struct GeomBuffer
{
    int m_00;
    int m_iVertexCount;
    int m_uiVertexCount;
    int m_numPrims;
    hkArray<hkVector4> m_verts;
    hkArray<int> m_cmds;
};

struct GeomWriter
{
    int m_00;
    GeomBuffer* m_buffer;
    int hkpConstraintConstructionKit_setTwistLimit(unsigned char twistAxis, unsigned char planeAxis, float a3, float a4);
};

// Appends command 0x13 with a1 and a2, then a vector (sin(a3), sin(a4), 0, 0) to the buffer, updates its counters, and returns the vector's index.
// @fnv 0x00d524d0
// src: XBOX_RETAIL_PDB 0x00d524d0
// pdb: hkpConstraintConstructionKit::setTwistLimit | hkpConstraintConstructionKit.obj | retail, object-file gap fill, high
// pdb params: twistAxis, planeAxis, min, max
// pdb locals: limit, assertBuf, ostr
int GeomWriter::hkpConstraintConstructionKit_setTwistLimit(unsigned char twistAxis, unsigned char planeAxis, float a3, float a4)
{
    m_buffer->m_cmds.pushBack(0x13);
    m_buffer->m_cmds.pushBack(twistAxis);
    m_buffer->m_cmds.pushBack(planeAxis);
    hkVector4 v;
    v.set(sin(a3), sin(a4), 0.0f, 0.0f);
    int index = m_buffer->m_verts.m_iElementCount;
    m_buffer->m_verts.pushBack(v);
    GeomBuffer* b = m_buffer;
    b->m_uiVertexCount++;
    b->m_iVertexCount += 0x30;
    b->m_numPrims++;
    return index;
}
