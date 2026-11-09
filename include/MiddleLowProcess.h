#pragma once

#include "LowProcess.h"
#include "ActorValueModifierList.h"

#pragma pack(push, 4)
// pdb: class MiddleLowProcess, size 0xc8, bases: LowProcess, 2 members
class MiddleLowProcess : public LowProcess
{
public:
    virtual bool vf519(Actor*, float); // RTTI slot 519 = 0x0091dd30, ret 8, AL result

    int iHourPackageEvaluated;
    ActorValueModifierList pTemporaryModifiers;

    virtual int GetProcessInteger() const;
    void SetProcessInteger(int);
    float GetCurrentActorValue(TESActorBase*, ActorValue::Index, Actor*);
    void AlterActorValue(Actor*, ActorValue::Index, float);
};
#pragma pack(pop)
