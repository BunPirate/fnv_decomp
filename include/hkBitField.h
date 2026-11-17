#pragma once

#include "hkArray.h"

// pdb: class hkBitField, size 0x10, 2 members
class hkBitField
{
  public:
    hkArray<unsigned int> m_words; // src: XBOX_RETAIL_PDB +0x0 (old: m_auiBitFieldWords)
    int m_numBits; // src: XBOX_RETAIL_PDB +0xc (old: m_iNumBits)

    __declspec(noinline) void fillUnusedBits(int fillValue) throw();
    void setSize(int numBits, int fillValue);

    int get(int index) const
    {
        return (m_words[index >> 5] >> (index & 0x1f)) & 1;
    }
};
