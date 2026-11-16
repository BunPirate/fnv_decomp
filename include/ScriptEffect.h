#pragma once

#include "ActiveEffect.h"
#include "Script.h"
#include "ScriptLocals.h"

// pdb: class ScriptEffect, size 0x50, bases: ActiveEffect, 2 members
class ScriptEffect : public ActiveEffect
{
public:
    virtual ~ScriptEffect();
    virtual ActiveEffect* Copy();
    virtual void Update(float afSecondsElapsed);
    virtual unsigned short GetSaveSize(Actor* apActor);
    virtual void SaveGame(Actor* apActor);
    virtual void SaveGame(BGSSaveFormBuffer* apSaveGameBuffer);
    virtual void LoadGame(Actor* apActor);
    virtual void LoadGame(BGSLoadFormBuffer* apLoadGameBuffer);
    virtual void Revert(Actor* apActor);
    virtual void CopyData(ActiveEffect* apOther);
    virtual void Start();
    virtual void Finish();

    Script* pScript;
    ScriptLocals* pEffectLocals; // src: XBOX_RETAIL_PDB +0x4c (old: m_pScriptLocals)

    ScriptEffect(MagicCaster* apCaster, MagicItem* apSpell, EffectItem* apEffect);
    void Destroy(bool);
};
