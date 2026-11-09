#pragma once

#include "TESForm.h"
#include "TESModelTextureSwap.h"

// pdb: class TESObjectANIO, size 0x3c, bases: TESForm, TESModelTextureSwap, 1 members
class TESObjectANIO : public TESForm, public TESModelTextureSwap
{
public:
    TESObjectANIO();

    virtual bool LoadForm(TESFile* apFile);
    virtual void InitItem();

    bool Load(TESFile* file);

    TESObjectANIO* pIdleAnim;
};
