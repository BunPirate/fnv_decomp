#pragma once

#include "CombatProcedure.h"
#include "TESBoundObject.h"

class CombatItemDebugOutput;
class UCIActor;
class UCIController;

// pdb: class CombatProcedureUseCombatItem, size 0x18, bases: CombatProcedure, 2 members
class CombatProcedureUseCombatItem : public CombatProcedure
{
public:
    CombatProcedureUseCombatItem(TESBoundObject* apItem);

    virtual ~CombatProcedureUseCombatItem();
    virtual void Unk04();
    virtual void d05();
    virtual int GetType();
    virtual void SaveGame(BGSSaveFormBuffer* apSaveGameBuffer);
    virtual void LoadGame(BGSLoadFormBuffer* apBuffer);
    virtual void vf16();

    COMBAT_PROCEDURES GetProcedureType();
    void SetVtableAndInit();
    void* DestroyIfFlagged(unsigned int flags);
    void UpdateCombatItemUse();
    void PrintDebugInfo(CombatItemDebugOutput* apDebugText, unsigned int aeLocation, unsigned int aeJustify);
    void LoadGame_009dac80(BGSLoadFormBuffer* apLoadGameBuffer);
    UCIActor* CombatProcedure_GetAttacker();
    void SetState();

    TESBoundObject* pItem;
    bool bAnimating; // src: XBOX_RETAIL_PDB +0x14 (old: m_bItemFlag)
};
