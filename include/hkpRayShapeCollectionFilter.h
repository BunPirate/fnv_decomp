#pragma once

#include "hkBool.h"
#include "hkpShapeContainer.h"

class hkpShapeCollection;
struct hkpShapeRayCastInput;
struct ShapeRayCastQuery;
struct hkBoolRet;
struct ClassMemberDescriptor;

// pdb: class hkpRayShapeCollectionFilter, size 0x4, 0 members
class hkpRayShapeCollectionFilter
{
public:
    virtual hkBoolRet IsCollisionEnabled(const ShapeRayCastQuery& aInput,
                                         const hkpShapeCollection& aCollection,
                                         const hkpShapeContainer& bContainer,
                                         hkpShapeKey aKey) const = 0;
    virtual ~hkpRayShapeCollectionFilter();

    hkBool IsCollisionEnabled(const hkpShapeRayCastInput& input,
                              const hkpShape& shape,
                              const hkpShapeContainer& container,
                              unsigned int key) const;

    static const ClassMemberDescriptor Members[];
};
