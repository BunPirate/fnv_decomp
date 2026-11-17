// speedtree/librandom_source/idvrandom_decls.h: declares RandomNumberGenerator

// pdb: class CIdvRandom, size 0x1, 0 members
class CIdvRandom // src: XBOX_RETAIL_PDB 0x00b3f100 (first retail link of 3 high-tier links to its methods; old: RandomNumberGenerator)
{
  public:
    CIdvRandom();
    void Reseed(long lSeed);
    float GenerateRandomFloat(float low, float fMax);
};
extern bool SIdvRandomImpl_m_bInit; // src: XBOX_RETAIL_PDB 0x011f8eb8 (old: DAT_011f8eb8)
extern "C" __int64 __cdecl _time64(__int64*);
