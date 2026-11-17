#pragma once

class hkClass;

// pdb: structure hkVariant, size 0x8, 2 members
class hkVariant
{
public:
    void* m_object;
    const hkClass* m_class;
};
