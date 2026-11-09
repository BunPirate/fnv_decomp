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

    hkaSkeleton* m_skeletonA;
    hkaSkeleton* m_skeletonB;
    hkArray<hkaSkeletonMapperDataSimpleMapping> m_simpleMappings;
    hkArray<hkaSkeletonMapperDataChainMapping> m_chainMappings;
    hkArray<hkInt16> m_unmappedBones;
    char pad2C[0x4];
    hkQsTransform m_extractedMotionMapping;
    hkBool m_bKeepUnmappedLocal;
    char pad61[0x3];
    hkInt32 m_eMappingType;
    char pad68[0x8];
};
#pragma pack(pop)
