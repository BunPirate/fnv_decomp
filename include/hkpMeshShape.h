#pragma once

#include "hkpShapeCollection.h"
#include "hkVector4.h"
#include "hkaAnimation.h"

class hkpMeshShapeSubpart;
struct MeshFinishFlag;

typedef unsigned short hkUint16;
typedef unsigned char hkUint8;

// pdb: class hkpMeshShape, size 0x60, bases: hkpShapeCollection, 7 members
class hkpMeshShape : public hkpShapeCollection
{
public:
    enum MeshShapeIndexStridingType
    {
        INDICES_INVALID = 0,
        INDICES_INT16 = 1,
        INDICES_INT32 = 2,
        INDICES_MAX_ID = 3
    };

    enum MeshShapeMaterialIndexStridingType
    {
        MATERIAL_INDICES_INVALID = 0,
        MATERIAL_INDICES_INT8 = 1,
        MATERIAL_INDICES_INT16 = 2,
        MATERIAL_INDICES_MAX_ID = 3
    };

    hkpMeshShape(float fRadius, int iNumBitsForSubpartIndex) throw();
    hkpMeshShape(FinishingFlag flag);
    hkpMeshShape(MeshFinishFlag flag);

    virtual void vf13();

    char pad18[0x8];
    hkVector4 m_scaling; // src: XBOX_RETAIL_PDB +0x20 (old: m_kScaling)
    hkInt32 m_numBitsForSubpartIndex; // src: XBOX_RETAIL_PDB +0x30 (old: m_iNumBitsForSubpartIndex)
    hkArray<hkpMeshShapeSubpart> m_subparts; // src: XBOX_RETAIL_PDB +0x34 (old: m_kSubparts)
    hkArray<hkUint16> m_weldingInfo; // src: XBOX_RETAIL_PDB +0x40 (old: m_kWeldingInfo)
    hkUint8 m_weldingType; // src: XBOX_RETAIL_PDB +0x4c (old: m_eWeldingType)
    char pad4D[0x3];
    hkReal m_radius; // src: XBOX_RETAIL_PDB +0x50 (old: m_fSphereRadius)
    hkInt32 m_pad[3]; // src: XBOX_RETAIL_PDB +0x54 (old: m_auiShapeKeys)
};
