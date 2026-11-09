#pragma once

#include "AssociatedItemEffect.h"
#include "NiPoint3.h"

class SelectedRecord;
class SummonOwner;

// pdb: class SummonCreatureEffect, size 0x74, bases: AssociatedItemEffect, 7 members
class SummonCreatureEffect : public AssociatedItemEffect
{
public:
    SummonCreatureEffect(MagicCaster* apCaster, MagicItem* apSpell, EffectItem* apEffect);
    virtual ~SummonCreatureEffect();

    virtual ActiveEffect* Copy();
    virtual void Update(float afElapsedSeconds);
    virtual unsigned short GetSaveSize(Actor* apActor);
    virtual void SaveGame(Actor* apActor);
    virtual void LoadGame(Actor* apActor);
    virtual void InitLoadGame(Actor* apActor);
    virtual void Start();
    virtual void Finish();

    void FUN_00828590();
    void* FUN_00828560(unsigned int flags);
    SummonOwner* GetSummoner();
    void Unsummon();
    SummonCreatureEffect* CloneObject();
    void DoSummon(Actor* pOwner);
    void DoSummon(int pOwner);
    bool SelectRecord(void* context, int flags, SelectedRecord* output);
    bool SelectRecord(Actor* ref, int iUnk, NiPoint3* pPos);
    int __thiscall GetZero(int a, int b, int c);
    bool SummonCreatureEffect_CheckSummonLocation(int apSummoned, SelectedRecord* location);
    void LimitPlayerSummonedCreatures();
    void CleanupSummonedCreature();
    void LoadAssociatedItemEffect(Actor* apActor);
    void Start_008287e0();
    void Update_00828ba0(int afSecondsElapsed);
    unsigned short __thiscall GetSaveSize_00829720(Actor* apActor);
    void SaveGame_008297a0(int apActor);
    void InitLoadGame_00829900(void* apActor);

    Actor* pSummonedCreature;
    unsigned char bTargetSet;
    unsigned char unk51[3];
    float fAppearTime;
    NiPoint3 AppearLocation;
    NiPoint3 AppearRotation;
    unsigned char bPlacement;
    unsigned char bcached;
};
