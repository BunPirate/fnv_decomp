#pragma once

#include "hkArray.h"

// pdb: class hkBitField, size 0x10, 2 members
class hkBitField
{
  public:
    hkArray<unsigned int> m_words;
    int m_numBits;

    __declspec(noinline) void fillUnusedBits(int fillValue) throw();
    void setSize(int numBits, int fillValue);

    int get(int index) const
    {
        return (m_words[index >> 5] >> (index & 0x1f)) & 1;
    }
};
