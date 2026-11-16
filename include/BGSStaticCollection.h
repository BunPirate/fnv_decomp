#pragma once

#include "TESBoundObject.h"
#include "TESModelTextureSwap.h"

// pdb: class BGSStaticCollection, size 0x50, bases: TESBoundObject, TESModelTextureSwap, 0 members
class BGSStaticCollection : public TESBoundObject, public TESModelTextureSwap
{
public:
    BGSStaticCollection();

    bool Load(TESFile* apFile);
    virtual bool LoadForm(TESFile* apFile);
    virtual void InitItem();
};
