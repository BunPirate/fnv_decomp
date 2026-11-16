#pragma once

#include "hkpHeightFieldShape.h"
#include "hkVector4.h"

// pdb: class hkpPlaneShape, size 0x40, bases: hkpHeightFieldShape, 3 members
class hkpPlaneShape : public hkpHeightFieldShape
{
public:
    virtual void vf12();

    hkVector4 m_plane; // src: XBOX_RETAIL_PDB +0x10 (old: m_kTriangleNormal)
    hkVector4 m_aabbCenter; // src: XBOX_RETAIL_PDB +0x20 (old: m_kAabbCenter)
    hkVector4 m_aabbHalfExtents; // src: XBOX_RETAIL_PDB +0x30 (old: m_kAabbHalfExtents)
};
