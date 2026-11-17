#pragma once

#include "hkMoppBvTreeShapeBase.h"
#include "hkpSingleShapeContainer.h"

class hkpShapeCollection;

// pdb: class hkpMoppBvTreeShape, size 0x40, bases: hkMoppBvTreeShapeBase, 2 members
class hkpMoppBvTreeShape : public hkMoppBvTreeShapeBase
{
public:
    static const ClassMemberDescriptor Members[];

    virtual ~hkpMoppBvTreeShape() throw();
    virtual void calcContentStatistics(hkStatisticsCollector* pCollector, const hkClass* pCls) const throw();
    virtual const hkpShapeContainer* GetShapeContainer() const;
    virtual int CalcSizeForSpu(const PhysicsShape& kInput, int iSpuBufferSizeLeft) const;
    virtual void CalculateAabb(const hkTransform& kLocalToWorld, hkReal fTolerance, hkAabb& kOut) const;
    virtual hkBool IntersectRayWithShape(const ShapeRayCastQuery& kInput, ShapeRayCastOutput& results) const;
    virtual void CastRayWithCollector(const ShapeRayCastQuery& kInput, const hkpCdBody& kBody,
                                      hkpRayHitCollector& kCollector) const;
    virtual Vector4Comparison CastRayBundle(const ShapeRayBundleCastInput& kInput, ShapeRayCastOutputArray& kOutput,
                                            hkVector4ComparisonParameter kMask) const;
    virtual void GetObbHits(const hkTransform& obbToMopp, const hkVector4& kObbExtent,
                            hkReal fTolerance, hkArray<hkpShapeKey>& kHits) const;
    virtual void GetAabbHits(const hkAabb& kAabb, hkArray<hkpShapeKey>& kHits) const;
    virtual hkUint32 GetAabbHitsToBuffer(const hkAabb& kAabb, hkpShapeKey* pHits, int iMaxNumKeys) const;

    using hkMoppBvTreeShapeBase::GetAabbHits;

    const hkpShapeCollection* getShapeCollection() const;
    void hkMoppBvTreeShapeBase_queryAabb(const hkAabb& aabb, hkArray<unsigned int>& hits) const;
    Vector4Comparison castRayBundleImpl(const ShapeRayBundleCastInput& input, ShapeRayCastOutputArray& results,
                                  hkVector4ComparisonParameter mask) const throw();

    hkpSingleShapeContainer m_child; // src: XBOX_RETAIL_PDB +0x30 (old: m_pChildAtom)
    mutable int m_childSize; // src: XBOX_RETAIL_PDB +0x38 (old: m_iChildSize)
    int unk3C;
};
