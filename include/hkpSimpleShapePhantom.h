#pragma once

#include "hkpShapePhantom.h"
#include "hkaAnimation.h"
#include "hkBool.h"

class hkpSimpleShapePhantomCollisionDetail;

// pdb: class hkpSimpleShapePhantom, size 0x170, bases: hkpShapePhantom, 2 members
class hkpSimpleShapePhantom : public hkpShapePhantom
{
public:
    hkArray<hkpSimpleShapePhantomCollisionDetail> m_collisionDetails; // src: XBOX_RETAIL_PDB +0x160 (old: m_kCollisionDetails)
    hkBool m_orderDirty; // src: XBOX_RETAIL_PDB +0x16c (old: m_bOrderDirty)
    char pad16D[0x3];
};
