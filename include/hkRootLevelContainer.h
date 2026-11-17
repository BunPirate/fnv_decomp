#pragma once

#include "hkArray.h"

class hkRootLevelContainerNamedVariant;

// pdb: class hkRootLevelContainer, size 0xc, 1 members
class hkRootLevelContainer
{
public:
    hkArray<hkRootLevelContainerNamedVariant> m_namedVariants; // src: XBOX_RETAIL_PDB +0x0 (old: m_kNamedVariants)

    __forceinline hkRootLevelContainer() {}
    __forceinline ~hkRootLevelContainer() {}
};
