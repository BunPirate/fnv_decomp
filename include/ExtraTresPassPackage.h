#pragma once

#include "BSExtraData.h"

class TrespassPackage;

// pdb: class ExtraTresPassPackage, size 0x10, bases: BSExtraData, 1 members
class ExtraTresPassPackage : public BSExtraData
{
public:
    ExtraTresPassPackage(TrespassPackage* pack);
    virtual ~ExtraTresPassPackage();

    void FUN_00432900();
    void* FUN_0042c890(unsigned int flags);

    union
    {
        TrespassPackage* package;
        TrespassPackage* pTargetPackage;
    };
};
