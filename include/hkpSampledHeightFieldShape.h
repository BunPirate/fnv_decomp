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

    hkInt32 m_xRes;
    hkInt32 m_zRes;
    hkReal m_heightCenter;
    hkBool m_useProjectionBasedHeight;
    hkUint8 m_heightfieldType;
    char pad1E[0x2];
    hkVector4 m_intToFloatScale;
    hkVector4 m_floatToIntScale;
    hkVector4 m_floatToIntOffsetFloorCorrected;
    hkVector4 m_extents;
};
