#pragma once

#include "TESBoundObject.h"
#include "TESLeveledList.h"
#include "TESModelTextureSwap.h"

class TESActorBase;

// pdb: class TESLevCreature, size 0x70, bases: TESBoundObject, TESLeveledList, TESModelTextureSwap, 1 members
class TESLevCreature : public TESBoundObject, public TESLeveledList, public TESModelTextureSwap
{
public:
    TESLevCreature();
    virtual ~TESLevCreature();

    virtual void InitItem();

    bool Load(TESFile* apFile);
    bool LoadForm(TESFile* file);

    TESActorBase* pTemplate;
};
