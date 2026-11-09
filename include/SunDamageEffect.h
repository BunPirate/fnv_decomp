#pragma once

#include "ActiveEffect.h"

// pdb: class SunDamageEffect, size 0x50, bases: ActiveEffect, 3 members
class SunDamageEffect : public ActiveEffect
{
public:
    static void* operator new(unsigned int size);
    static void operator delete(void* p);

    SunDamageEffect(MagicCaster*, MagicItem*, EffectItem*);

    ActiveEffect* Copy() override;
    unsigned short GetSaveSize(Actor* apActor) override;
    void SaveGame(Actor* apActor) override;

    void LoadGame(Actor* apActor) override;
    void UpdateEffect(float afSecondsElapsed);
    bool IsCausingDamage();
    double GetDamageAmount();
    void UpdateHitEffect(bool abDamaging);
    int FUN_0055b980();

    float fGlowEffect;
    bool bHitEffectApplied;
    bool bDoNotTakeDamageNextUpdate;
};
