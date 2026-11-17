// src/havok/physics/collide/shape/misc/transform/hkptransformshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/misc/transform/hkptransformshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../../include/hkClass.h"
#include "../../../../../../../include/hkStatisticsCollector.h"
#include "../../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../include/hkReferencedObject.h"
#include "../../../../../../../include/hkpShape.h"
#include "../../../../../../../include/hkpShapeContainer.h"
#include "../../../../../../../include/hkpSingleShapeContainer.h"
#include "../../../../../../../include/hkQuaternion.h"
#include "../../../../../../../include/hkTransform.h"
#include "../../../../../../../include/hkVector4.h"
#include "../../../../../../../include/hkpTransformShape.h"

// The TLS accessor at 0x00c85750 and heap at +0x10 identify the shared memory-router view.


inline void hkReferencedObject::operator delete(void* p)
{
    hkMemoryRouter::getInstance().heap().blockFree(
        p, static_cast<hkReferencedObject*>(p)->m_memSizeAndFlags);
}

inline hkpShapeContainer::~hkpShapeContainer() {}
inline hkpSingleShapeContainer::~hkpSingleShapeContainer()
{
    if (m_childShape)
        const_cast<hkpShape*>(m_childShape)->removeReference();
}

// Retained locally: the shared header lacks this unit's statistics, SPU-size,
// AABB and projection overrides, SetTransform (0x00cf5950), and deletion helper.
// Child at +0x14 and transform at +0x30 identify all former transform-shape views.

extern const hkClass DAT_01268910;

// @fnv 0x00cf58c0
// pdb: hkpTransformShape::calcContentStatistics | hkpTransformShape.obj | retail, string-set bridge, high
// pdb params: collector, cls
void hkpTransformShape::calcContentStatistics(hkStatisticsCollector* collector, const hkClass* cls) const throw()
{
    collector->beginObject("ChildShape", m_childShape.m_childShape, 0);
    hkReferencedObject::calcContentStatistics(collector, &DAT_01268910);
}

// @fnv 0x00cf58f0
const hkpShapeContainer* hkpTransformShape::GetShapeContainer() const
{
    return &m_childShape;
}

// @fnv 0x00cf5900
// pdb: hkpTransformShape::calcSizeForSpu | hkpTransformShape.obj | retail, vtable slot, high
// pdb params: input, spuBufferSizeLeft
// pdb locals: assertBuf, ostr
int hkpTransformShape::CalcSizeForSpu(const PhysicsShape& input, int spuBufferSizeLeft) const
{
    int result = m_childShape.m_childShape->CalcSizeForSpu(input, spuBufferSizeLeft - 0x70);
    if (result < 0)
        return -1;
    if (result > spuBufferSizeLeft - 0x70)
        return -1;
    if (m_childShape.m_childShape == reinterpret_cast<const hkpShape*>(reinterpret_cast<const char*>(this) + 0x70))
    {
        const_cast<hkpTransformShape*>(this)->m_childShapeSize = 0;
        return result + 0x70;
    }
    const_cast<hkpTransformShape*>(this)->m_childShapeSize = result;
    return 0x70;
}

// Destructs the object, then frees it when flags has bit 0 set, and returns this.
// @fnv 0x00cf5e50
// pdb: hkpTransformShape::`scalar deleting destructor' | hkpTransformShape.obj | retail, vtable slot, high
hkpTransformShape* hkpTransformShape::DestroyAndMaybeFree(unsigned int flags) throw()
{
    this->hkpTransformShape::~hkpTransformShape();
    if (flags & 1)
        hkpTransformShape::operator delete(this);
    return this;
}

extern int DAT_010cc41c;
extern int DAT_010c6fd0;

// @fnv 0x00cf5990
// pdb: hkpTransformShape::~hkpTransformShape | hkpTransformShape.obj | debug, object-file run extension, low
int hkpTransformShape::Initialize(hkpShape* child, const hkTransform& transform)
{
    m_referenceCount = 1;
    m_userData = 0;
    *reinterpret_cast<unsigned int*>(&m_type) = 15;
    *reinterpret_cast<void**>(this) = &DAT_010cc41c;
    *reinterpret_cast<void**>(&m_childShape) = &DAT_010c6fd0;
    m_childShape.m_childShape = child;
    child->addReference();
    SetTransform(transform);
    return reinterpret_cast<int>(this);
}

// @fnv 0x00cf59e0
// pdb: hkpTransformShape::getAabbImpl | hkpTransformShape.obj | retail, vtable slot, high
// pdb params: localToWorld, tolerance, out
// pdb locals: worldTshape
void hkpTransformShape::CalculateAabb(const hkTransform& localToWorld, float tolerance, hkAabb& out) const
{
    // Scalar scratch storage retains the original /GS classification of this temporary.
    struct __declspec(align(16))
    {
        float a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p;
    } storage;
    hkTransform& transformed = reinterpret_cast<hkTransform&>(storage);
    transformed.hkTransform_setMul(localToWorld, m_transform);
    m_childShape.m_childShape->CalculateAabb(transformed, tolerance, out);
}

// @fnv 0x00cf5a20
// pdb: hkpTransformShape::getMaximumProjection | hkpTransformShape.obj | retail, upstream name already matches, high
// pdb params: direction
// pdb locals: localProjection, localDir
float hkpTransformShape::getMaximumProjection(const hkVector4& kDirection) const
{
    const __m128& direction = kDirection.m_vComponents;
    __m128 c0 = m_transform.m_kColumn0;
    __m128 c1 = m_transform.m_kColumn1;
    __m128 c2 = m_transform.m_kColumn2;
    {
        __m128 t = _mm_unpacklo_ps(c0, c1);
        __m128 ct = _mm_unpackhi_ps(c0, c1);
        c0 = _mm_movelh_ps(t, c2);
        c1 = _mm_movehl_ps(c0, t);
        c1 = _mm_shuffle_ps(c1, c2, 0xd4);
        c2 = _mm_shuffle_ps(ct, c2, 0xe4);
    }
    __m128 dir = direction;
    __m128 kDirY = _mm_shuffle_ps(dir, dir, 0x55);
    __m128 kDirX = _mm_shuffle_ps(dir, dir, 0x00);
    __m128 kDirZ = _mm_shuffle_ps(dir, dir, 0xaa);
    hkVector4 localDir;
    *(__m128*)&localDir = _mm_add_ps(_mm_add_ps(_mm_mul_ps(kDirY, c1), _mm_mul_ps(kDirX, c0)), _mm_mul_ps(kDirZ, c2));

    float projection = m_childShape.m_childShape->getMaximumProjection(localDir);

    __m128 support = _mm_mul_ps(_mm_load1_ps(&projection), *(const __m128*)&localDir);
    __m128 kWorldSupport =
        _mm_add_ps(_mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(support, support, 0x55), m_transform.m_kColumn1),
                              _mm_mul_ps(_mm_shuffle_ps(support, support, 0x00), m_transform.m_kColumn0)),
                   _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(support, support, 0xaa), m_transform.m_kColumn2), m_transform.m_vTranslation));
    __m128 prod = _mm_mul_ps(kWorldSupport, direction);
    __m128 sum = _mm_add_ss(_mm_shuffle_ps(prod, prod, 0xaa), _mm_add_ss(_mm_shuffle_ps(prod, prod, 0x55), prod));
    float result;
    _mm_store_ss(&result, sum);
    return result;
}
