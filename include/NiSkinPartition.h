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
        unsigned short* m_pusBones;
        float* m_pfWeights;
        unsigned short* m_pusVertexMap;
        unsigned char* m_pucBonePalette;
        unsigned short* m_pusTriList;
        unsigned short* m_pusStripLengths;
        unsigned short m_usVertices;
        unsigned short m_usTriangles;
        unsigned short m_usBones;
        unsigned short m_usStrips;
        unsigned short m_usBonesPerVertex;
        void* m_pkBuffData;

        unsigned int NiSkinPartition_Partition_GetStripLengthSum();
    };
};
