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

    Attribute* m_attributes;
    int m_numAttributes;

    void* __thiscall getAttribute(void* arg);
    const hkVariant* getAttribute(const char* name) const;
    const hkVariant* FindEntry(const char* name) const;
};
