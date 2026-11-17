
#include "../../../../../../../../../include/hkpShapeContainer.h"


// src/havok/physics/internal/collide/mopp/builder/mediator/shape/hkpmoppshapemediator.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/physics/internal/collide/mopp/builder/mediator/shape/hkpmoppshapemediator.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// @fnv 0x00dd51f0
int __stdcall ReadIntField(const void* a, int* piValue)
{
    *piValue = *(const int*)((const char*)a + 4);
    return 1;
}

struct FUN_00dd5260_T
{
    int a;
    int b;
    int c;
    int d;
    int e;
};

// Copies the five-int struct pointed to by pSrc into the struct pointed to by pDst.
// @fnv 0x00dd5260
// src: XBOX_PDB 0x00dd5260
void __stdcall hkpMoppShapeMediator_splitPrimitive(FUN_00dd5260_T* pSrc, int a1, int a2, int a3, FUN_00dd5260_T* pDst)
{
    *pDst = *pSrc;
}

struct FUN_00dd5210_Record
{
    int value;
    int reserved;
    int unk08;
    int unk0c;
    int unk10;
};

struct FUN_00dd5210_Object
{
    int unk00;
    int unk04;
    hkpShapeContainer* unk08;
    int unk0c;
    void FillRecords(FUN_00dd5210_Record* primitives);
};

// Fills count records with successive shape keys from unk08.
// @fnv 0x00dd5210
// pdb: hkpMoppShapeMediator::getPrimitives | hkpMoppShapeMediator.obj | retail, vtable slot, high
// pdb params: primitives
void FUN_00dd5210_Object::FillRecords(FUN_00dd5210_Record* primitives)
{
    int count = unk0c;
    hkpShapeKey value = unk08->GetFirstKey();
    if (count > 0)
    {
        do
        {
            primitives->value = value;
            primitives->reserved = 0;
            ++primitives;
            value = unk08->GetNextShapeKey(value);
            --count;
        } while (count != 0);
    }
}

struct SpawnedBase
{
    virtual ~SpawnedBase()
    {}
};

class FUN_00dd52a0_cls : public SpawnedBase
{
  public:
    short unk04;
    unsigned short m_flag06;
    hkpShapeContainer* m_src08;
    int m_result0c;

    FUN_00dd52a0_cls* hkpMoppShapeMediator_ctor(hkpShapeContainer* shapeArray);
};

// Sets m_flag06 to 1, destroys the base, stores src and its child shape count, and returns this.
// @fnv 0x00dd52a0
// src: XBOX_RETAIL_PDB 0x00dd52a0
// pdb: hkpMoppShapeMediator::hkpMoppShapeMediator | hkpMoppShapeMediator.obj | retail, call graph, high
// pdb params: shapeArray
FUN_00dd52a0_cls* FUN_00dd52a0_cls::hkpMoppShapeMediator_ctor(hkpShapeContainer* shapeArray)
{
    m_flag06 = 1;
    this->SpawnedBase::~SpawnedBase();
    m_src08 = shapeArray;
    m_result0c = shapeArray->GetNumChildShapes();
    return this;
}

struct CpuAllocator
{
    virtual void slot00();
    virtual void slot04();
    virtual void Invoke(void* block, unsigned int size);
};
struct CpuAllocatorHolder
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    CpuAllocator* allocator;
};
CpuAllocatorHolder* __cdecl hkMemoryRouter_getInstance();
struct CpuObject
{
    unsigned int unk00;
    unsigned short size;
    void InitializeFields_00dd51d0();
    CpuObject* FUN_00dd55a0(unsigned int flags);
};
// @fnv 0x00dd55a0
// pdb: hkpMoppShapeMediator::`scalar deleting destructor' | hkpMoppShapeMediator.obj | debug, vtable slot, medium
CpuObject* CpuObject::FUN_00dd55a0(unsigned int flags)
{
    InitializeFields_00dd51d0();
    if (flags & 1)
    {
        CpuAllocatorHolder* holder = hkMemoryRouter_getInstance();
        holder->allocator->Invoke(this, size);
    }
    return this;
}

// @fnv 0x00dd51e0
// src: COMMUNITY 0x00dd51e0
void __stdcall nullsub_83(int, int)
{}

struct FnvCpu_FUN_00dd5290_CpuObject
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    int value;
    int GetValue();
};
// @fnv 0x00dd5290
// src: GUESS 0x00dd5290 (confidence: low)
int FnvCpu_FUN_00dd5290_CpuObject::GetValue()
{
    return value;
}

// Exe-matched intrinsic packet; __m128 remains an ABI compatibility alias.
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;
extern "C"
{
    __m128 _mm_xor_ps(__m128, __m128);
}

extern __m128 DAT_010c44d0;

#include "../../../../../../../../../include/hkVector4.h"
__forceinline void hkVector4::setNeg4(const hkVector4& v) { m_vComponents = _mm_xor_ps(v.m_vComponents, DAT_010c44d0); }


struct __declspec(align(16)) hkpShapeBuffer
{
    int m_data[128];
};

struct ProjectionSample
{
    hkpShapeKey m_key;
    int m_unk04;
    hkReal m_kMinimumCorner;
    hkReal m_kMaximumCorner;
    int m_unk10;
};

struct ProjectionShape
{
    int unk00;
    int unk04;
    hkpShapeContainer* m_container;

    void ComputeProjectionRange(const hkVector4& direction, int directionIndex, ProjectionSample* primitives, int numPrimitives,
                                hkReal* absMinOut, hkReal* absMaxOut);
};

// @fnv 0x00dd52d0
// pdb: hkpMoppShapeMediator::projectPrimitives | hkpMoppShapeMediator.obj | retail, vtable slot, high
// pdb params: direction, directionIndex, primitives, numPrimitives, absMinOut, absMaxOut
void ProjectionShape::ComputeProjectionRange(const hkVector4& direction, int directionIndex, ProjectionSample* primitives,
                                             int numPrimitives, hkReal* absMinOut, hkReal* absMaxOut)
{
    hkpShapeBuffer buffer;
    hkReal fMinCorner;
    hkReal fMaxCorner;
    hkReal minProj;
    hkReal maxProj;
    {
        hkpShapeKey key = primitives[0].m_key;
        const hkpShape* pShape = m_container->GetShapeForKey(key, buffer);
        if (pShape)
        {
            fMaxCorner = pShape->getMaximumProjection(direction);
            hkVector4 negDirection;
            negDirection.setNeg4(direction);
            fMinCorner = -pShape->getMaximumProjection(negDirection);
        }
        else
        {
            fMinCorner = 0.0f;
            fMaxCorner = 0.0f;
        }
        primitives[0].m_kMinimumCorner = fMinCorner;
        primitives[0].m_kMaximumCorner = fMaxCorner;
        maxProj = fMaxCorner;
        minProj = fMinCorner;
    }
    for (int i = 1; i < numPrimitives; i++)
    {
        hkpShapeKey key = primitives[i].m_key;
        const hkpShape* pShape = m_container->GetShapeForKey(key, buffer);
        if (pShape)
        {
            fMaxCorner = pShape->getMaximumProjection(direction);
            hkVector4 negDirection;
            negDirection.setNeg4(direction);
            fMinCorner = -pShape->getMaximumProjection(negDirection);
        }
        else
        {
            fMinCorner = 0.0f;
            fMaxCorner = 0.0f;
        }
        primitives[i].m_kMinimumCorner = fMinCorner;
        primitives[i].m_kMaximumCorner = fMaxCorner;
        if (fMinCorner < minProj)
        {
            minProj = fMinCorner;
        }
        if (fMaxCorner > maxProj)
        {
            maxProj = fMaxCorner;
        }
    }
    *absMinOut = minProj;
    *absMaxOut = maxProj;
}
