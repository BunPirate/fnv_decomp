#pragma once

#include "hkpShapePhantom.h"
#include "hkaAnimation.h"
#include "hkBool.h"

class hkpSimpleShapePhantomCollisionDetail;

// pdb: class hkpSimpleShapePhantom, size 0x170, bases: hkpShapePhantom, 2 members
class hkpSimpleShapePhantom : public hkpShapePhantom
{
public:
    hkArray<hkpSimpleShapePhantomCollisionDetail> m_collisionDetails;
    hkBool m_orderDirty;
    char pad16D[0x3];
};
