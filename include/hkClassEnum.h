#pragma once

#include "hkClass.h"

class hkClassEnumItem;
class hkCustomAttributes;

class hkStreamWriter;

// pdb: class hkClassEnum, size 0x14, 5 members
class hkClassEnum
{
public:
    void writeSignature(hkStreamWriter* w) const;
    enum FlagValues
    {
        FLAGS_NONE = 0
    };

    char* m_name;
    hkSimpleArray<hkClassEnumItem> m_items;
    hkCustomAttributes* m_attributes; // src: XBOX_RETAIL_PDB +0xc (old: m_pCustomAttributes)
    hkUint32 m_flags;
};
