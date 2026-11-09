#pragma once

#include "ActiveEffect.h"

class BodyVirt;
class EffectVirt;
class RBodyAccess;
class TESObjectREFR;

// pdb: class ReanimateEffect, size 0x70, bases: ActiveEffect, 5 members
class ReanimateEffect : public ActiveEffect
{
public:
    virtual ~ReanimateEffect();
    virtual ActiveEffect* Copy();
    virtual void Update(float afElapsedSeconds);
    virtual unsigned short GetSaveSize(Actor* apActor);
    virtual void SaveGame(Actor* apActor);
    virtual void LoadGame(Actor* apActor);
    virtual void FinishLoadGameTES(Actor* apActor);
    virtual void Revert(Actor* apActor);
    virtual bool CanApply(MagicCaster* apCaster);
    virtual bool IsEffectValid(MagicTarget* apTarget);
    virtual void Start();
    virtual void Finish();

    using ActiveEffect::SaveGame;
    using ActiveEffect::LoadGame;
    using ActiveEffect::Revert;

    union
    {
        BodyVirt* pBody;
        RBodyAccess* body;
        EffectVirt* m_48;
    };
    union
    {
        int iState;
        int state;
        int m_4c;
        int unk4c;
    };
    float fSaveTime;
    unsigned char StartPos[12];
    unsigned char StartRot[16];

    ReanimateEffect(MagicCaster* apCaster, MagicItem* apSpell, EffectItem* apEffect);
    void UpdateReanimation(Actor* apActor);
    void StartReanimation();

    unsigned short __thiscall FUN_00804f80(Actor* apActor);
    unsigned short __thiscall GetSaveSize_00827440(Actor* apActor);
    void FUN_00827510(Actor* apActor);
    void __thiscall Revert_008276e0(Actor* apActor);
    void SaveGame_008274a0(Actor* apActor);
    ActiveEffect* Copy_008266a0();
    void __thiscall Finish_00827230();
    void FUN_00805760(Actor* actor);
    bool __thiscall CheckTarget_00827340(TESObjectREFR* apTarget);
};
