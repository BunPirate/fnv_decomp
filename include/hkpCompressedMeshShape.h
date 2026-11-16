#pragma once

#include "hkpShapeCollection.h"
#include "hkArray.h"
#include "hkTransform.h"
#include "hkVector4.h"
#include "hkAabb.h"

class hkpCompressedMeshShapeBigTriangle;
class hkpCompressedMeshShapeChunk;
class hkpCompressedMeshShapeConvexPiece;
class hkpNamedMeshMaterial;

class __declspec(novtable) hkpCompressedMeshShape : public hkpShapeCollection
{
public:
    enum MaterialType
    {
        MATERIAL_NONE = 0,
        MATERIAL_SINGLE_VALUE_PER_CHUNK = 1,
        MATERIAL_ONE_BYTE_PER_TRIANGLE = 2,
        MATERIAL_TWO_BYTES_PER_TRIANGLE = 3,
        MATERIAL_FOUR_BYTES_PER_TRIANGLE = 4
    };

    hkpCompressedMeshShape(float radius);
    hkpCompressedMeshShape(FinishingFlag flag) throw();

    unsigned int GetShapeIndexMask();
    void SetWeldingType(unsigned char weldingType);
    void __thiscall SetAttribute(unsigned long instanceMask, unsigned short attributeValue);

    virtual ~hkpCompressedMeshShape() throw();
    virtual void calcContentStatistics(hkStatisticsCollector* collector, const hkClass* cls) const;
    virtual int CalcSizeForSpu(const PhysicsShape& input, int spuBufferSizeLeft) const;
    virtual void CalculateAabb(const hkTransform& localToWorld, hkReal tolerance, hkAabb& out) const;
    virtual void vf11(int);
    virtual void vf12(int, int);

    int m_bitsPerIndex; // src: XBOX_RETAIL_PDB +0x18 (old: m_iBitsPerIndex)
    int m_bitsPerWIndex; // src: XBOX_RETAIL_PDB +0x1c (old: m_iBitsPerWIndex)
    int m_wIndexMask; // src: XBOX_RETAIL_PDB +0x20 (old: m_iNumBitsForIndex)
    int m_indexMask; // src: XBOX_RETAIL_PDB +0x24 (old: m_iNumBitsForWIndex)
    float m_radius; // src: XBOX_RETAIL_PDB +0x28 (old: m_fSphereRadius)
    unsigned char m_weldingType; // src: XBOX_RETAIL_PDB +0x2c (old: m_eWeldingType)
    unsigned char m_materialType; // src: XBOX_RETAIL_PDB +0x2d (old: m_ucMaterialType)
    char pad2E[0x2];
    hkArray<unsigned int> m_materials; // src: XBOX_RETAIL_PDB +0x30 (old: m_kMaterials)
    hkArray<unsigned short> m_materials16; // src: XBOX_RETAIL_PDB +0x3c (old: m_kMaterialIndices16)
    hkArray<unsigned char> m_materials8; // src: XBOX_RETAIL_PDB +0x48 (old: m_kMaterialIndices8)
    hkArray<hkTransform> m_transforms; // src: XBOX_RETAIL_PDB +0x54 (old: m_kTransforms)
    hkArray<hkVector4> m_bigVertices; // src: XBOX_RETAIL_PDB +0x60 (old: m_kBigVertices)
    hkArray<hkpCompressedMeshShapeBigTriangle> m_bigTriangles; // src: XBOX_RETAIL_PDB +0x6c (old: m_kBigTriangles)
    hkArray<hkpCompressedMeshShapeChunk> m_chunks; // src: XBOX_RETAIL_PDB +0x78 (old: m_kChunks)
    hkArray<hkpCompressedMeshShapeConvexPiece> m_convexPieces; // src: XBOX_RETAIL_PDB +0x84 (old: m_kConvexPieces)
    float m_error; // src: XBOX_RETAIL_PDB +0x90 (old: m_eScriptError)
    char pad94[0xC];
    hkAabb m_bounds; // src: XBOX_RETAIL_PDB +0xa0 (old: m_kBounds)
    void* m_meshMaterials; // src: XBOX_RETAIL_PDB +0xc0 (old: m_pUserData)
    unsigned short m_materialStriding; // src: XBOX_RETAIL_PDB +0xc4 (old: m_iIndexStriding)
    unsigned short m_numMaterials; // src: XBOX_RETAIL_PDB +0xc6 (old: m_iNumTriangles)
    hkArray<hkpNamedMeshMaterial> m_namedMaterials; // src: XBOX_RETAIL_PDB +0xc8 (old: m_kNamedMaterials)
    char padD4[0x1C];
};
