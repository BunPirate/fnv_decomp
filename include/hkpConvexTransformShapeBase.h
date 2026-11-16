#pragma once

#include "hkpConvexShape.h"
#include "hkpSingleShapeContainer.h"

// pdb: class hkpConvexTransformShapeBase, size 0x20, bases: hkpConvexShape, 2 members
class hkpConvexTransformShapeBase : public hkpConvexShape
{
public:
    hkpConvexTransformShapeBase(int type, float radius, const hkpConvexShape* childShape, int ref);

    virtual void vf17();

    const hkpConvexShape* GetShapeForKey() const;

    hkpSingleShapeContainer m_childShape; // src: XBOX_RETAIL_PDB +0x14 (old: m_pContainedShape)
    int m_childShapeSize; // src: XBOX_RETAIL_PDB +0x1c (old: m_iChildShapeSize)
};
