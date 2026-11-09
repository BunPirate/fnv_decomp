#pragma once

#include "hkpConvexTransformShapeBase.h"
#include "hkTransform.h"

// pdb: class hkpConvexTransformShape, size 0x60, bases: hkpConvexTransformShapeBase, 1 members
class hkpConvexTransformShape : public hkpConvexTransformShapeBase
{
public:
    hkpConvexTransformShape(const hkpConvexShape* childShape, const hkTransform& transform, int ref = 1);

    const hkTransform& getTransform() const
    {
        return m_transform;
    }

    const hkpConvexShape* GetShapeForKey() const;

    hkTransform m_transform;
};
