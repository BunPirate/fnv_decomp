#pragma once

#include "hkaSkeleton.h"
#include "hkBool.h"
#include "hkQsTransform.h"

class hkaSkeletonMapperDataSimpleMapping;
class hkaSkeletonMapperDataChainMapping;

typedef short hkInt16;

#pragma pack(push, 1)
// pdb: class hkaSkeletonMapperData, size 0x70 (here 0x60), 8 members
class hkaSkeletonMapperData
{
public:
    enum MappingType
    {
        HK_RAGDOLL_MAPPING = 0,
        HK_RETARGETING_MAPPING = 1
    };

    hkaSkeleton* m_skeletonA; // src: XBOX_RETAIL_PDB +0x0 (old: m_pSkeletonA)
    hkaSkeleton* m_skeletonB; // src: XBOX_RETAIL_PDB +0x4 (old: m_pSkeletonB)
    hkArray<hkaSkeletonMapperDataSimpleMapping> m_simpleMappings; // src: XBOX_RETAIL_PDB +0x8 (old: m_kSimpleMappings)
    hkArray<hkaSkeletonMapperDataChainMapping> m_chainMappings; // src: XBOX_RETAIL_PDB +0x14 (old: m_kChainMappings)
    hkArray<hkInt16> m_unmappedBones; // src: XBOX_RETAIL_PDB +0x20 (old: m_kUnmappedBones)
    char pad2C[0x4];
    hkQsTransform m_extractedMotionMapping; // src: XBOX_RETAIL_PDB +0x30 (old: m_kExtractedMotionMapping)
    hkBool m_bKeepUnmappedLocal;
    char pad61[0x3];
    hkInt32 m_eMappingType;
    char pad68[0x8];
};
#pragma pack(pop)
