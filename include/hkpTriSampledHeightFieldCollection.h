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

    hkpSampledHeightFieldShape* m_heightfield; // src: XBOX_RETAIL_PDB +0x18 (old: m_pHeightFieldShape)
    hkInt32 m_childSize; // src: XBOX_RETAIL_PDB +0x1c (old: m_iChildSize)
    hkReal m_radius; // src: XBOX_RETAIL_PDB +0x20 (old: m_fSphereRadius)
    hkArray<hkUint16> m_weldingInfo; // src: XBOX_RETAIL_PDB +0x24 (old: m_kWeldingInfo)
    hkVector4 m_triangleExtrusion; // src: XBOX_RETAIL_PDB +0x30 (old: m_kTriangleExtrusion)
};
