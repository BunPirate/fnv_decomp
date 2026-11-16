#pragma once

#include "MobIterOperator.h"

class Actor;
class TESBoundObject;

// pdb: class Reset3DMobIterator, size 0x10, bases: MobIterOperator, 2 members
class Reset3DMobIterator : public MobIterOperator
{
public:
    TESBoundObject* pActorBase; // src: XBOX_RETAIL_PDB +0x8 (old: base)
    bool cFlags; // src: XBOX_RETAIL_PDB +0xc (old: reset)

    Reset3DMobIterator();
    void Tesscriptfunctions_UpdateState_005d8b10();
    void FUN_006ecd40(int);
    virtual void Operate(MobileObject* mobile);
    void operator()(Actor* actor);
};
