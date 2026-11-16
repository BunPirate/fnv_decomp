#pragma once

#include "hkStringPtr.h"
#include "hkaAnimation.h"

class hkxAttribute;

// pdb: structure hkxAttributeGroup, size 0x10, 2 members
class hkxAttributeGroup
{
public:
    hkStringPtr m_name;
    hkArray<hkxAttribute> m_attributes; // src: XBOX_RETAIL_PDB +0x4 (old: m_pCustomAttributes)
};
