#pragma once

#include "BSExtraData.h"

// pdb: class ExtraSavedAnimation, size 0x10, bases: BSExtraData, 1 members
class ExtraSavedAnimation : public BSExtraData
{
public:
    ExtraSavedAnimation();
    virtual ~ExtraSavedAnimation();

    char* m_pString;
};
