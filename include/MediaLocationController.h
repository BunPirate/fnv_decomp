#pragma once

#include "TESForm.h"
#include "TESFullName.h"
#include "MagicTarget.h"

class MediaSet;
class TESFaction;
class TESObjectREFR;

#include "FIGHT_REACTION.h"

// pdb: class MediaLocationController, size 0xb8, bases: TESForm, TESFullName, 32 members
struct MediaLocationController : public TESForm, public TESFullName
{
public:
    enum DEADREPFLAGS
    {
        DEADFACTION_CONDITIONAL_NEUTRAL,
        DEADFACTION_CONDITIONAL_ENEMY,
        DEADFACTION_CONDITIONAL_ALLY,
        DEADFACTION_CONDITIONAL_FRIEND,
        DEADFACTION_LOCATION,
        DEADFACTION_NONE
    };

    MediaLocationController();

    virtual bool LoadForm(TESFile* apFile);
    virtual void InitItem();
    virtual void ClearData();

    bool Load(TESFile* apFile);
    void InitItemList(BSSimpleList<MediaSet*>* plist);
    MediaSet* GetRandomListItem(BSSimpleList<MediaSet*>* list);
    bool Update(bool abInCombat);
    bool IsMediaLocationActive();
    DEADREPFLAGS GetDeadRep();
    void ResetFormData();
    int GetLoop();
    bool GetByteAtOffset55();

    unsigned int uiLocationDelay; // src: XBOX_RETAIL_PDB +0x24 (old: m_fUpdateCooldown)
    unsigned int uiLayerTime; // src: XBOX_RETAIL_PDB +0x28 (old: m_uiFirstCounter)
    unsigned int uiLoopTime; // src: XBOX_RETAIL_PDB +0x2c (old: m_uiSecondCounter)
    unsigned int uiMediaStartTime; // src: XBOX_RETAIL_PDB +0x30 (old: m_uiThirdCounter)
    bool bIsActive;
    bool bInTension; // src: XBOX_RETAIL_PDB +0x35 (old: m_bCountWasNonzero)
    bool bInCombat; // src: XBOX_RETAIL_PDB +0x36 (old: m_bActorStateFlag)
    bool bIsDay; // src: XBOX_RETAIL_PDB +0x37 (old: m_bConditionWasTrue)
    bool bIsConditional; // src: XBOX_RETAIL_PDB +0x38 (old: m_bConditionActive)
    unsigned char layoutPadding39[3];
    float fCurrentPlayerRadius; // src: XBOX_RETAIL_PDB +0x3c (old: m_fLocationDistance)
    unsigned int uiFoundHostileActors; // src: XBOX_RETAIL_PDB +0x40 (old: m_uiPerceivedActorCount)
    unsigned int uiFoundFactionActors; // src: XBOX_RETAIL_PDB +0x44 (old: m_uiPreviousPerceivedActorCount)
    FIGHT_REACTION eCurrentFactionReaction; // src: XBOX_RETAIL_PDB +0x48 (old: m_eCurrentFightReaction)
    char cCurrentLayer; // src: XBOX_RETAIL_PDB +0x4c (old: m_cMediaState)
    unsigned char layoutPadding4D[3];
    MediaSet* pCurrentMediaSet; // src: XBOX_RETAIL_PDB +0x50 (old: m_pMediaSet)
    TESFullName MediaLocationControllerName; // src: XBOX_RETAIL_PDB +0x54 (old: m_kLocationName)
    TESFaction* pFaction;
    FIGHT_REACTION rFactionConditional; // src: XBOX_RETAIL_PDB +0x64 (old: m_eRequiredFightReaction)
    TESObjectREFR* pAudioMarker; // src: XBOX_RETAIL_PDB +0x68 (old: m_pReference)
    int iFlags;
    float fLayerTwoPercent; // src: XBOX_RETAIL_PDB +0x70 (old: m_fLowerWeightThreshold)
    float fLayerThreePercent; // src: XBOX_RETAIL_PDB +0x74 (old: m_fUpperWeightThreshold)
    float fRetriggerDelay; // src: XBOX_RETAIL_PDB +0x78 (old: m_fMediaSelectionValue)
    float fLocationDelay; // src: XBOX_RETAIL_PDB +0x7c (old: m_fUpdateInterval)
    unsigned int uiDayStart; // src: XBOX_RETAIL_PDB +0x80 (old: m_uiShortDelay)
    unsigned int uiNightStart; // src: XBOX_RETAIL_PDB +0x84 (old: m_uiLongDelay)
    BSSimpleList<MediaSet*> lConditionalNeutralList; // src: XBOX_RETAIL_PDB +0x88 (old: m_kMediaSetList1)
    BSSimpleList<MediaSet*> lConditionalAllyList; // src: XBOX_RETAIL_PDB +0x90 (old: m_kMediaSetList2)
    BSSimpleList<MediaSet*> lConditionalFriendList; // src: XBOX_RETAIL_PDB +0x98 (old: m_kMediaSetList3)
    BSSimpleList<MediaSet*> lConditionalEnemyList; // src: XBOX_RETAIL_PDB +0xa0 (old: m_kMediaSetList4)
    BSSimpleList<MediaSet*> lLocationList; // src: XBOX_RETAIL_PDB +0xa8 (old: m_kMediaSetList5)
    BSSimpleList<MediaSet*> lBattleList; // src: XBOX_RETAIL_PDB +0xb0 (old: m_kMediaSetList6)
};
