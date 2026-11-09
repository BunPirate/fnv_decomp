// src/havok/physics/utilities/deprecated/h1group/hkpgroupcollisionfilter.cpp
#include "../../../../../../include/hkBool.h"
#include "../../../../../../include/hkReferencedObject.h"
#include "../../../../../../include/hkpCollidableCollidableFilter.h"
#include "../../../../../../include/hkpShapeCollectionFilter.h"
#include "../../../../../../include/hkpRayCollidableFilter.h"
#include "../../../../../../include/hkpRayShapeCollectionFilter.h"
#include "../../../../../../include/hkpShapeContainer.h"
#include "../../../../../../include/hkpCdBody.h"
#include "../../../../../../include/hkpCollidable.h"

struct hkBoolRet
{
    hkBool m_cBooleanValue;
};

// No shared hkpShapeRayCastInput header is available; filter info is at +0x20 in 0x00e45950.
// pdb: structure hkpShapeRayCastInput, size 0x30 (here 0x24), 4 members
struct hkpShapeRayCastInput
{
    float m_vFrom[4];
    float m_vTo[4];
    unsigned int m_uiFilterInfo;
};

// No shared hkpGroupCollisionFilter header is available; members match the reflected +0x30/+0x34 layout.
class hkpGroupCollisionFilter : public hkReferencedObject,
                                public hkpCollidableCollidableFilter,
                                public hkpShapeCollectionFilter,
                                public hkpRayShapeCollectionFilter,
                                public hkpRayCollidableFilter
{
public:
    virtual hkBool IsCollisionEnabled(const hkpCollidable& kFirst, const hkpCollidable& kSecond) const;
    virtual hkBool IsCollisionEnabled(const CollisionAgentContext& kInput, const hkpCdBody& kFirst,
                                     const hkpCdBody& kSecond, const hkpShapeContainer& bContainer,
                                     hkpShapeKey bKey) const;
    virtual hkBool IsCollisionEnabled(const CollisionAgentContext& kInput, const hkpCdBody& collectionBodyA,
                                     const hkpCdBody& collectionBodyB, const hkpShapeContainer& containerShapeA,
                                     const hkpShapeContainer& containerShapeB, hkpShapeKey uKeyA,
                                     hkpShapeKey uKeyB) const;
    virtual hkBoolRet IsCollisionEnabled(const ShapeRayCastQuery& aInput, const hkpShapeCollection& kShape,
                                     const hkpShapeContainer& bContainer, unsigned int bKey) const;
    virtual hkBool IsCollisionEnabled(const WorldRayCastInput& aInput, const hkpCollidable& collidableB) const;
    hkBool isCollisionEnabled(int iMask, int iValue) const;

    unsigned int m_uiPreTypePadding[2];
    unsigned int m_type;
    unsigned int m_uiPostTypePadding[3];
    hkBool m_noGroupCollisionEnabled;
    char pad31[3];
    unsigned int m_collisionGroups[32];
};

// Returns m_bEnableCollisionTable if mask or value is zero, otherwise ORs selected m_uiCollisionTable entries per mask bits and returns whether value overlaps the result.
// @fnv 0x00e455f0
// src: HAVOK_LIB 0x00e455f0
hkBool hkpGroupCollisionFilter::isCollisionEnabled(int mask, int value) const
{
    if (mask == 0 || value == 0)
    {
        return m_noGroupCollisionEnabled;
    }
    int iAccumulatedMask = 0;
    if (mask & 0xff)
    {
        iAccumulatedMask = (mask & 0x1) ? m_collisionGroups[0] : 0;
        iAccumulatedMask |= (mask & 0x2) ? m_collisionGroups[1] : 0;
        iAccumulatedMask |= (mask & 0x4) ? m_collisionGroups[2] : 0;
        iAccumulatedMask |= (mask & 0x8) ? m_collisionGroups[3] : 0;
        iAccumulatedMask |= (mask & 0x10) ? m_collisionGroups[4] : 0;
        iAccumulatedMask |= (mask & 0x20) ? m_collisionGroups[5] : 0;
        iAccumulatedMask |= (mask & 0x40) ? m_collisionGroups[6] : 0;
        iAccumulatedMask |= (mask & 0x80) ? m_collisionGroups[7] : 0;
    }
    if (mask & 0xff00)
    {
        iAccumulatedMask |= (mask & 0x100) ? m_collisionGroups[8] : 0;
        iAccumulatedMask |= (mask & 0x200) ? m_collisionGroups[9] : 0;
        iAccumulatedMask |= (mask & 0x400) ? m_collisionGroups[10] : 0;
        iAccumulatedMask |= (mask & 0x800) ? m_collisionGroups[11] : 0;
        iAccumulatedMask |= (mask & 0x1000) ? m_collisionGroups[12] : 0;
        iAccumulatedMask |= (mask & 0x2000) ? m_collisionGroups[13] : 0;
        iAccumulatedMask |= (mask & 0x4000) ? m_collisionGroups[14] : 0;
        iAccumulatedMask |= (mask & 0x8000) ? m_collisionGroups[15] : 0;
    }
    if (mask & 0xff0000)
    {
        iAccumulatedMask |= (mask & 0x10000) ? m_collisionGroups[16] : 0;
        iAccumulatedMask |= (mask & 0x20000) ? m_collisionGroups[17] : 0;
        iAccumulatedMask |= (mask & 0x40000) ? m_collisionGroups[18] : 0;
        iAccumulatedMask |= (mask & 0x80000) ? m_collisionGroups[19] : 0;
        iAccumulatedMask |= (mask & 0x100000) ? m_collisionGroups[20] : 0;
        iAccumulatedMask |= (mask & 0x200000) ? m_collisionGroups[21] : 0;
        iAccumulatedMask |= (mask & 0x400000) ? m_collisionGroups[22] : 0;
        iAccumulatedMask |= (mask & 0x800000) ? m_collisionGroups[23] : 0;
    }
    if (mask & 0xff000000)
    {
        iAccumulatedMask |= (mask & 0x1000000) ? m_collisionGroups[24] : 0;
        iAccumulatedMask |= (mask & 0x2000000) ? m_collisionGroups[25] : 0;
        iAccumulatedMask |= (mask & 0x4000000) ? m_collisionGroups[26] : 0;
        iAccumulatedMask |= (mask & 0x8000000) ? m_collisionGroups[27] : 0;
        iAccumulatedMask |= (mask & 0x10000000) ? m_collisionGroups[28] : 0;
        iAccumulatedMask |= (mask & 0x20000000) ? m_collisionGroups[29] : 0;
        iAccumulatedMask |= (mask & 0x40000000) ? m_collisionGroups[30] : 0;
        iAccumulatedMask |= (mask & 0x80000000u) ? m_collisionGroups[31] : 0;
    }
    return (value & iAccumulatedMask) != 0;
}


// @fnv 0x00e45890
// pdb: hkpGroupCollisionFilter::isCollisionEnabled | hkpGroupCollisionFilter.obj | retail, vtable slot, high
// pdb params: a, b
hkBool hkpGroupCollisionFilter::IsCollisionEnabled(const hkpCollidable& a, const hkpCollidable& b) const
{
    return isCollisionEnabled(a.m_broadPhaseHandle.m_collisionFilterInfo, b.m_broadPhaseHandle.m_collisionFilterInfo);
}

// @fnv 0x00e458c0
// pdb: hkpGroupCollisionFilter::isCollisionEnabled | hkpGroupCollisionFilter.obj | retail, vtable slot, high
// pdb params: a, b
hkBool hkpGroupCollisionFilter::IsCollisionEnabled(const CollisionAgentContext& input, const hkpCdBody& a,
                                                const hkpCdBody& b, const hkpShapeContainer& bContainer,
                                                hkpShapeKey bKey) const
{
    unsigned int info = bContainer.GetFilterInfoForKey(bKey);
    const hkpCdBody* root = &a;
    while (root->m_parent)
        root = root->m_parent;
    return isCollisionEnabled(reinterpret_cast<const hkpCollidable*>(root)->m_broadPhaseHandle.m_collisionFilterInfo, info);
}

// @fnv 0x00e45910
// pdb: hkpGroupCollisionFilter::isCollisionEnabled | hkpGroupCollisionFilter.obj | retail, vtable slot, high
// pdb params: a, b
hkBool hkpGroupCollisionFilter::IsCollisionEnabled(const CollisionAgentContext& input, const hkpCdBody& collectionBodyA,
                                                const hkpCdBody& collectionBodyB, const hkpShapeContainer& containerShapeA,
                                                const hkpShapeContainer& containerShapeB, hkpShapeKey keyA,
                                                hkpShapeKey keyB) const
{
    unsigned int infoA = containerShapeA.GetFilterInfoForKey(keyA);
    unsigned int infoB = containerShapeB.GetFilterInfoForKey(keyB);
    return isCollisionEnabled(infoA, infoB);
}

// @fnv 0x00e45950
// pdb: hkpGroupCollisionFilter::isCollisionEnabled | hkpGroupCollisionFilter.obj | retail, vtable slot, high
// pdb params: a, b
hkBoolRet hkpGroupCollisionFilter::IsCollisionEnabled(const ShapeRayCastQuery& aInput, const hkpShapeCollection& shape,
                                                const hkpShapeContainer& bContainer, unsigned int bKey) const
{
    unsigned int info = bContainer.GetFilterInfoForKey(bKey);
    hkBoolRet result = { isCollisionEnabled(reinterpret_cast<const hkpShapeRayCastInput&>(aInput).m_uiFilterInfo, info) };
    return result;
}

// @fnv 0x00e45990
// pdb: hkpGroupCollisionFilter::isCollisionEnabled | hkpGroupCollisionFilter.obj | retail, vtable slot, high
// pdb params: a, b
hkBool hkpGroupCollisionFilter::IsCollisionEnabled(const WorldRayCastInput& aInput, const hkpCollidable& collidableB) const
{
    return isCollisionEnabled(*reinterpret_cast<const unsigned int*>(reinterpret_cast<const char*>(&aInput) + 0x24),
                      collidableB.m_broadPhaseHandle.m_collisionFilterInfo);
}

// sub ecx,0x10; jmp target  ==  MSVC adjustor thunk: Derived overrides a virtual that both of its bases
// declare, so the second base's vtable gets a thunk that moves `this` back by the first base's size (0x10).
struct PrimaryBase
{
    virtual void AdjustThisAndForward_00cbfc00();
    int unk04;
    int unk08;
    int unk0C;
};

struct SecondaryBase
{
    virtual void AdjustThisAndForward_00cbfc00();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00cbfc00
// src: GUESS 0x00cbfc00 (confidence: low)
    virtual void AdjustThisAndForward_00cbfc00();
};

Derived::Derived()
{}
