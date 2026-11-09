#pragma once

#include "hkpShapeCollection.h"
#include "hkpSampledHeightFieldShape.h"
#include "hkaAnimation.h"
#include "hkVector4.h"

typedef unsigned short hkUint16;

// pdb: class hkpTriSampledHeightFieldCollection, size 0x40, bases: hkpShapeCollection, 5 members
class hkpTriSampledHeightFieldCollection : public hkpShapeCollection
{
public:
    const hkpSampledHeightFieldShape* getHeightFieldShape() const;

    hkpSampledHeightFieldShape* m_heightfield;
    hkInt32 m_childSize;
    hkReal m_radius;
    hkArray<hkUint16> m_weldingInfo;
    hkVector4 m_triangleExtrusion;
};
