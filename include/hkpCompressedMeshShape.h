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

    int m_bitsPerIndex;
    int m_bitsPerWIndex;
    int m_wIndexMask;
    int m_indexMask;
    float m_radius;
    unsigned char m_weldingType;
    unsigned char m_materialType;
    char pad2E[0x2];
    hkArray<unsigned int> m_materials;
    hkArray<unsigned short> m_materials16;
    hkArray<unsigned char> m_materials8;
    hkArray<hkTransform> m_transforms;
    hkArray<hkVector4> m_bigVertices;
    hkArray<hkpCompressedMeshShapeBigTriangle> m_bigTriangles;
    hkArray<hkpCompressedMeshShapeChunk> m_chunks;
    hkArray<hkpCompressedMeshShapeConvexPiece> m_convexPieces;
    float m_error;
    char pad94[0xC];
    hkAabb m_bounds;
    void* m_meshMaterials;
    unsigned short m_materialStriding;
    unsigned short m_numMaterials;
    hkArray<hkpNamedMeshMaterial> m_namedMaterials;
    char padD4[0x1C];
};
