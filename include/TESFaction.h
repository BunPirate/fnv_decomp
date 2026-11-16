#pragma once

#include "TESForm.h"
#include "TESFullName.h"
#include "TESReactionForm.h"
#include "FactionSaveData.h"

class FactionRankPresentation;
class TESReputation;
enum FIGHT_REACTION;

struct _FightReaction
{
    enum Type
    {
        NEUTRAL = 0,
        ENEMY = 1,
        ALLY = 2,
        FRIEND = 3,
        COUNT
    };
};

// pdb: class TESFaction, size 0x4c, bases: TESForm, TESFullName, TESReactionForm, 5 members
class TESFaction : public TESForm, public TESFullName, public TESReactionForm
{
public:
    struct Rank;

    TESFaction();
    virtual ~TESFaction();

    virtual void ClearData();
    virtual void Revert(BGSLoadFormBuffer* apLoadGameBuffer);
    virtual void InitItem();

    void ResetFormData();
    void InitLoadGame(BGSLoadFormBuffer* apLoadGameBuffer);
    void ClearRankDataList();
    virtual void LoadGame(BGSLoadFormBuffer* apLoadGameBuffer);
    int InitializeFaction();
    BSSimpleList<FactionRankPresentation*>* GetRankDataList();
    bool Load(TESFile* file);
    bool GetPCAnEnemy() const;
    FIGHT_REACTION TESFaction_GetFactionReaction(TESFaction* faction);
    void SetFactionFightReaction(TESFaction* apFaction, _FightReaction::Type aiFightReaction);
    bool IsHiddenFlagSet();
    unsigned int GetFormID();
    bool GetEvil();
    void ForwardCall_0047eb90(bool value);

    FactionSaveData data;
    TESReputation* pReputation; // src: XBOX_RETAIL_PDB +0x38 (old: pReputationData)
    BSSimpleList<FactionRankPresentation*> m_rankDataList; // src: XBOX_RETAIL_PDB +0x3c (old: m_kRankDataList)
    int iMajorCrime; // src: XBOX_RETAIL_PDB +0x44 (old: m_iFirstFactionValue)
    int iMinorCrime; // src: XBOX_RETAIL_PDB +0x48 (old: m_iSecondFactionValue)
};
