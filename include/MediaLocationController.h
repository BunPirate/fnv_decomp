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

    unsigned int uiLocationDelay;
    unsigned int uiLayerTime;
    unsigned int uiLoopTime;
    unsigned int uiMediaStartTime;
    bool bIsActive;
    bool bInTension;
    bool bInCombat;
    bool bIsDay;
    bool bIsConditional;
    unsigned char layoutPadding39[3];
    float fCurrentPlayerRadius;
    unsigned int uiFoundHostileActors;
    unsigned int uiFoundFactionActors;
    FIGHT_REACTION eCurrentFactionReaction;
    char cCurrentLayer;
    unsigned char layoutPadding4D[3];
    MediaSet* pCurrentMediaSet;
    TESFullName MediaLocationControllerName;
    TESFaction* pFaction;
    FIGHT_REACTION rFactionConditional;
    TESObjectREFR* pAudioMarker;
    int iFlags;
    float fLayerTwoPercent;
    float fLayerThreePercent;
    float fRetriggerDelay;
    float fLocationDelay;
    unsigned int uiDayStart;
    unsigned int uiNightStart;
    BSSimpleList<MediaSet*> lConditionalNeutralList;
    BSSimpleList<MediaSet*> lConditionalAllyList;
    BSSimpleList<MediaSet*> lConditionalFriendList;
    BSSimpleList<MediaSet*> lConditionalEnemyList;
    BSSimpleList<MediaSet*> lLocationList;
    BSSimpleList<MediaSet*> lBattleList;
};
