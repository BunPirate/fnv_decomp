#pragma once

#include "hkVariant.h"

// pdb: class hkCustomAttributes, size 0x8, 2 members
class hkCustomAttributes
{
public:
    struct Attribute
    {
        const char* m_name;
        hkVariant m_value;
    };

    Attribute* m_attributes; // src: XBOX_RETAIL_PDB +0x0 (old: m_data)
    int m_numAttributes; // src: XBOX_RETAIL_PDB +0x4 (old: m_iElementCount)

    void* __thiscall getAttribute(void* arg);
    const hkVariant* getAttribute(const char* name) const;
    const hkVariant* FindEntry(const char* name) const;
};
