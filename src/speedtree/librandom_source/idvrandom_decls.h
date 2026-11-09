// speedtree/librandom_source/idvrandom_decls.h: declares RandomNumberGenerator

// pdb: class CIdvRandom, size 0x1, 0 members
class CIdvRandom
{
  public:
    CIdvRandom();
    void Reseed(long lSeed);
    float GenerateRandomFloat(float low, float fMax);
};
extern bool SIdvRandomImpl_m_bInit;
extern "C" __int64 __cdecl _time64(__int64*);
