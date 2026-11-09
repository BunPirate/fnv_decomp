#pragma once

#include "hkpHeightFieldShape.h"
#include "hkVector4.h"

// pdb: class hkpPlaneShape, size 0x40, bases: hkpHeightFieldShape, 3 members
class hkpPlaneShape : public hkpHeightFieldShape
{
public:
    virtual void vf12();

    hkVector4 m_plane;
    hkVector4 m_aabbCenter;
    hkVector4 m_aabbHalfExtents;
};
