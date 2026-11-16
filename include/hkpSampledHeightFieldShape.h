#pragma once

#include "hkpHeightFieldShape.h"
#include "hkVector4.h"

typedef int hkInt32;
typedef unsigned char hkUint8;

// pdb: class hkpSampledHeightFieldShape, size 0x60, bases: hkpHeightFieldShape, 9 members
class hkpSampledHeightFieldShape : public hkpHeightFieldShape
{
public:
    enum HeightFieldType
    {
        HEIGHTFIELD_STORAGE = 0,
        HEIGHTFIELD_COMPRESSED = 1,
        HEIGHTFIELD_USER = 2,
        HEIGHTFIELD_MAX_ID = 3
    };


    virtual void v12();
    virtual hkReal GetHeightAtGridPoint(int x, int z) const;
    virtual hkBool IsTriangleWindingFlipped() const;

    hkReal getHeightAt(int x, int z) const throw();
    hkReal getScaledHeight(int x, int z) const throw();

    hkInt32 m_xRes; // src: XBOX_RETAIL_PDB +0x10 (old: m_iXResolution)
    hkInt32 m_zRes; // src: XBOX_RETAIL_PDB +0x14 (old: m_iZResolution)
    hkReal m_heightCenter; // src: XBOX_RETAIL_PDB +0x18 (old: m_fHeightScale)
    hkBool m_useProjectionBasedHeight; // src: XBOX_RETAIL_PDB +0x1c (old: m_bUseProjectionBasedHeight)
    hkUint8 m_heightfieldType; // src: XBOX_RETAIL_PDB +0x1d (old: m_ucHeightFieldType)
    char pad1E[0x2];
    hkVector4 m_intToFloatScale; // src: XBOX_RETAIL_PDB +0x20 (old: m_kHeightScaleVector)
    hkVector4 m_floatToIntScale; // src: XBOX_RETAIL_PDB +0x30 (old: m_kInverseScale)
    hkVector4 m_floatToIntOffsetFloorCorrected; // src: XBOX_RETAIL_PDB +0x40 (old: m_kOffset)
    hkVector4 m_extents; // src: XBOX_RETAIL_PDB +0x50 (old: SetCenterPosition)
};
