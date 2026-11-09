#pragma once

#include "BSExtraData.h"

class TESForm;

// pdb: class ExtraPatrolRefInUseData, size 0x10, bases: BSExtraData, 1 members
class ExtraPatrolRefInUseData : public BSExtraData
{
public:
    virtual ~ExtraPatrolRefInUseData();

    ExtraPatrolRefInUseData(TESForm* apForm);
    bool GetCanBeUsedBy(void* apPotentialUser);

    unsigned int User;
};
