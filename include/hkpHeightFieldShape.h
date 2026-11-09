#pragma once

#include "hkpShape.h"

class hkSphere;
struct CollisionSphereData;

// pdb: class hkpHeightFieldShape, size 0x10, bases: hkpShape, 0 members
class hkpHeightFieldShape : public hkpShape
{
public:
    virtual void CollideSpheres(const CollisionSphereData& input, hkSphere* hitResults);
};
