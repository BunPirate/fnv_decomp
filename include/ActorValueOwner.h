#pragma once

namespace ActorValue
{
    enum Index;
}

class Actor;
class TESForm;

// pdb: class ActorValueOwner, size 0x4, 0 members
class ActorValueOwner
{
public:
    ActorValueOwner();

    virtual int GetBaseActorValue(ActorValue::Index actorValue);
    virtual float GetBaseActorValueFloat(ActorValue::Index actorValue);
    virtual int GetActorValue(ActorValue::Index aiWhich);
    virtual float GetCurrentActorValue(ActorValue::Index actorValue);
    virtual float GetPermanentActorValueFloat(ActorValue::Index actorValue);
    virtual float GetTemporaryActorValue(ActorValue::Index actorValue);
    virtual float GetDamageActorValue(ActorValue::Index actorValue);
    virtual int GetPermanentActorValue(ActorValue::Index actorValue);
    virtual float GetPermanentActorValueAdjustment(ActorValue::Index actorValue);
    virtual TESForm* GetActorValueOwnerForm();
    virtual unsigned short GetActorValueOwnerType();

    Actor* GetActorOwner();
    float GetActorValueFloatByIndex(ActorValue::Index aiWhich);
    float GetActorValueFloatByIndex(int aiWhich);
    int GetActorValueAsInteger(ActorValue::Index aiWhich);
    int GetActorValueAsInteger(int aiWhich);
};
