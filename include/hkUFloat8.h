#pragma once

// pdb: class hkUFloat8, size 0x1, 1 members
class hkUFloat8
{
public:
    union
    {
        unsigned char m_value;
        unsigned char value;
    };

    void FindFloatTableIndex(const float*);
};
