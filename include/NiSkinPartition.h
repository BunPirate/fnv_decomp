#pragma once

#include "NiObject.h"

// pdb: class NiSkinPartition, size 0x10 (here 0x8), bases: NiObject, 2 members
class NiSkinPartition : public NiObject
{
public:
    class Partition
    {
    public:
        virtual ~Partition();
        unsigned short* m_pusBones; // src: XBOX_RETAIL_PDB +0x4 (old: m_pusBonePalette)
        float* m_pfWeights; // src: XBOX_RETAIL_PDB +0x8 (old: m_pfVertexWeights)
        unsigned short* m_pusVertexMap; // src: XBOX_RETAIL_PDB +0xc (old: m_pusSourceVertexIndices)
        unsigned char* m_pucBonePalette; // src: XBOX_RETAIL_PDB +0x10 (old: m_pucBoneIndices)
        unsigned short* m_pusTriList;
        unsigned short* m_pusStripLengths;
        unsigned short m_usVertices;
        unsigned short m_usTriangles;
        unsigned short m_usBones; // src: XBOX_RETAIL_PDB +0x20 (old: m_usBoneCount)
        unsigned short m_usStrips;
        unsigned short m_usBonesPerVertex; // src: XBOX_RETAIL_PDB +0x24 (old: m_usWeightsPerVertex)
        void* m_pkBuffData; // src: XBOX_RETAIL_PDB +0x28 (old: m_pkGeometryRendererData)

        unsigned int NiSkinPartition_Partition_GetStripLengthSum();
    };
};
