#pragma once

#include "Random.h"

// pdb: class PosGen, size 0x14, bases: Random, 4 members
class PosGen : public Random
{
public:
    PosGen();
    virtual ~PosGen();
    virtual float Next();
    virtual FloatIntPair* vf04(FloatIntPair* value);
    void Build(bool sym);

    float xi;
    float* sx;
    float* sfx; // src: XBOX_RETAIL_PDB +0xc (old: m_pYValues)
    bool NotReady;
    unsigned char layoutPadding11[3];
};
