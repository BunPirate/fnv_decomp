#pragma once

#include "hkpShape.h"

class hkSphere;

// pdb: class hkpSphereRepShape, size 0x10, bases: hkpShape, 0 members
class hkpSphereRepShape : public hkpShape
{
public:
    static const ClassMemberDescriptor Members[];

    hkpSphereRepShape(hkpShapeType type);
    hkpSphereRepShape(FinishingFlag flag);

    int getNumCollisionSpheres() const;
    const hkSphere* getCollisionSpheres(hkSphere* sphereBuffer) const;
};
