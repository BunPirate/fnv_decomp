#pragma once

#include "TESObjectARMO.h"

// pdb: class TESObjectARMA, size 0x190, bases: TESObjectARMO, 0 members
class TESObjectARMA : public TESObjectARMO
{
public:
    TESObjectARMA();
    virtual ~TESObjectARMA();
    virtual void InitItem();

    bool Load(TESFile* apFile);
    void ResetFormData();
};
