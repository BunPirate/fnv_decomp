
// bscore/bsrandom.inl
//
// Inline helpers over the MersenneTwister random-number service. The original file
// defines each helper on a single line; the bodies below are expanded for
// review but compile to the same /Od out-of-line comdat copies.
#include "bsrandom.h"

// @fnv 0x00476c00
// pdb: BSRandom::QInstance | BGSDestructibleObjectForm.obj | debug, call graph, medium
inline MersenneTwister* MersenneTwister::GetRandomGenerator()
{
    static MersenneTwister s_instance;
    return &s_instance;
}

// @fnv 0x00476b70
// pdb: RandomFloat | BGSDestructibleObjectForm.obj | retail, upstream name already matches, high
// pdb params: afMin, afMax
float RandomFloat(float afMin, float afMax)
{
    return MersenneTwister::GetRandomGenerator()->Float(afMin, afMax);
}

// @fnv 0x005c5420
// pdb: RandomFloat0To1 | TESScriptFunctions.obj | debug, upstream name already matches, high
float RandomFloat0To1()
{
    return MersenneTwister::GetRandomGenerator()->Float0To1();
}

// @fnv 0x004dff00
// pdb: RandomBool | ScreenCustomSplatter.obj | debug, call graph, high
// pdb params: afPercentTrue
bool RandomBoolean(float afPercentTrue)
{
    return MersenneTwister::GetRandomGenerator()->Bool(afPercentTrue);
}

// @fnv 0x004dff60
// pdb: BSRandom::Float0To1 | ScreenCustomSplatter.obj | debug, call graph, medium
// pdb locals: r
float MersenneTwister::Float0To1()
{
    unsigned int value = GetRandomUInt();
    return (float)(value * (1.0 / 4294967296.0));
}

// @fnv 0x004dff20
// pdb: BSRandom::Bool | ScreenCustomSplatter.obj | debug, call graph, medium
// pdb params: afPercentTrue
bool MersenneTwister::Bool(float chance)
{
    return chance >= Float0To1();
}

#include "bsrandom_singleton.h"
// @fnv 0x0049fef0
// pdb: BGSDecalManager::GetInstance | BGSDecalManager.obj | debug, call graph, medium
bsrandom_singleton::MersenneTwister* bsrandom_singleton::MersenneTwister::GetRandomGenerator()
{
    if (!DAT_011c57f8)
        DAT_011c57f8 = new MersenneTwister;
    return DAT_011c57f8;
}
