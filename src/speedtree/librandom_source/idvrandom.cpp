// speedtree/librandom_source/idvrandom.cpp: RandomNumberGenerator, Uniform (8 functions)

#include "../../../include/Random.h"
#include "idvrandom_decls.h"

// @fnv 0x00b3f100
// pdb: CIdvRandom::CIdvRandom | IdvRandom.obj | retail, call graph (shared callers), high
CIdvRandom::CIdvRandom()
{
    if (!SIdvRandomImpl_m_bInit)
        Reseed(-1);
}

// @fnv 0x00b3f160
// src: XBOX_RETAIL_PDB 0x00b3f160
// pdb: CIdvRandom::Reseed | IdvRandom.obj | retail, call graph, high
// pdb params: lSeed
// pdb locals: nNewSeed, nTimeValue
void CIdvRandom::Reseed(long lSeed)
{
    if (lSeed == -1)
    {
        long randomSeed = 12345;
        if (SIdvRandomImpl_m_bInit)
            randomSeed = (long)GenerateRandomFloat(0.0f, 2147483648.0f);
        long currentTime = (long)_time64(0);
        if (randomSeed > currentTime)
            Random::Set((double)currentTime / randomSeed);
        else
            Random::Set((double)randomSeed / currentTime);
    }
    else
    {
        if (lSeed <= 1)
            lSeed = 1;
        Random::SetLong(lSeed);
    }
    SIdvRandomImpl_m_bInit = true;
}

// @fnv 0x00b3f270
int Random::vf06()
{
    return 1;
}

extern Random SIdvRandomImpl_m_cUniform; // src: XBOX_RETAIL_PDB 0x011f8ebc (old: DAT_011f8ebc)
// Linearly interpolates between fMin and afMax using a random sample.
// @fnv 0x00b3f130
// pdb: CIdvRandom::GetUniform | IdvRandom.obj | retail, call graph, high
// pdb params: fMin, fMax
float CIdvRandom::GenerateRandomFloat(float fMin, float fMax)
{
    return (float)((fMax - fMin) * (double)SIdvRandomImpl_m_cUniform.Random::Next() + fMin);
}

struct FloatIntPair
{
    float f;
    int i;
};
// Sets p->i to 0 and p->f to 0.5, then returns p.
// @fnv 0x00b3f210
FloatIntPair* Random::vf04(FloatIntPair* pValue)
{
    pValue->i = 0;
    pValue->f = 0.5f;
    return pValue;
}

extern float DAT_010a58ec;
// Sets p->i to 0 and p->f to DAT_010a58ec, then returns p.
// @fnv 0x00b3f240
FloatIntPair* Random::vf05(FloatIntPair* pValue)
{
    pValue->i = 0;
    pValue->f = DAT_010a58ec;
    return pValue;
}
extern double _gModifierZero;
// pdb: class Uniform, size 0x4 (here 0x1), bases: Random, 0 members
struct Uniform
{
    float Next();
    float Density_00b3f2a0(float x) const;
};

// @fnv 0x00b3f280
// pdb: Uniform::Next | IdvRandom.obj | debug, upstream name already matches, high
float Uniform::Next()
{
    return ((Random*)this)->Random::Next();
}

// Returns 1.0f when x is within [_gModifierZero, 1.0], otherwise 0.0f.
// @fnv 0x00b3f2a0
// src: XBOX_PDB 0x00b3f2a0
float Uniform::Density_00b3f2a0(float afValue) const
{
    return (afValue < _gModifierZero || afValue > 1.0) ? 0.0f : 1.0f;
}
