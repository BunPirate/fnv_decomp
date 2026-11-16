#pragma once

#include "BSExtraData.h"
#include "NP.h"

class bhkWorld;

// pdb: class ExtraHavok, size 0x14, bases: BSExtraData, 2 members
class ExtraHavok : public BSExtraData
{
public:
    virtual ~ExtraHavok();

    ExtraHavok(bhkWorld*);
    ExtraHavok(int);

    void FUN_0040ee70();
    void* FUN_0040ee40(unsigned int);

    union
    {
        int pad[1];
        struct
        {
            NP first;
        };
        bhkWorld* m_pHavokWorld;
    };
    NP spCellMopp; // src: XBOX_RETAIL_PDB +0x10 (old: spMopp)
};
