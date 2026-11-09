#pragma once

#include "BSExtraData.h"

class TESForm;

// pdb: class ExtraStartingWorldOrCell, size 0x10, bases: BSExtraData, 1 members
class ExtraStartingWorldOrCell : public BSExtraData
{
public:
    virtual ~ExtraStartingWorldOrCell();
    ExtraStartingWorldOrCell();

    TESForm* m_pStartingWorldOrCell;
};
