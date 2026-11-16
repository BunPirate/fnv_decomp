#pragma once

#include "Menu.h"
#include "BSSoundHandle.h"
#include "HotkeyWheelDisplay.h"
#include "GameTimerRecord.h"
#include "ShadowSceneLight.h"

class Actor;
class Tile;
class TESObjectREFR;
class NiControllerSequence;
class RegionObjectEntry;
class HUDMainMenu__MessageData;
class HUDMainMenu__SubtitleData;
class HUDMainMenu__QuestObjective;
class HUDMainMenu__XPUpdate;
class HUDMainMenu__RadiationUpdate;


// pdb: class HUDMainMenu, size 0x278, bases: Menu, 36 members
class HUDMainMenu : public Menu
{
public:
    enum HUD_MENU_MODE
    {
        HMM_NONE = 0,
        HMM_CHANGED = 1,
        HMM_RUN_AND_GUN = 2,
        HMM_PIPBOY = 3,
        HMM_START = 4,
        HMM_LOAD = 5,
        HMM_DIALOGUE = 6,
        HMM_VATS = 7,
        HMM_VATS_PLAYBACK = 8,
        HMM_CONTAINER = 9,
        HMM_SIT_SLEEP_ANIM = 10,
        HMM_SIT_SLEEP = 11,
        HMM_MOVEMENT_DISABLED = 12,
        HMM_PIPBOY_DISABLED = 13,
        HMM_CHARGEN_MENU = 14,
        HMM_HACKING = 15,
        HMM_TERMINAL = 16,
        HMM_MESSAGE_MENU = 17,
        HMM_SPECIAL_BOOK = 18,
        HMM_LOVE_TESTER = 19,
        HMM_VANITY = 20,
        HMM_AUTO_VANITY = 21,
        HMM_IRON_SIGHTS = 22,
        HMM_SNIPER_RIFLE = 23,
        HMM_MOVIE = 24,
        HMM_CASINO_GAME = 25,
    };

    HUDMainMenu();
    virtual ~HUDMainMenu();
    virtual void AssignTileByID(int aTileID, Tile* apTile);
    virtual int GetClass();

    Tile* pTiles[87]; // src: XBOX_RETAIL_PDB +0x28 (old: m_pTiles)
    Tile* pActive; // src: XBOX_RETAIL_PDB +0x184 (old: m_pAdditionalHudTile)
    float fSeenLevel; // src: XBOX_RETAIL_PDB +0x188 (old: m_fMessageDisplayTimer)
    BSSimpleList<HUDMainMenu__MessageData*> xMessages; // src: XBOX_RETAIL_PDB +0x18c (old: m_kMessageList)
    unsigned int uiMessageStartTime; // src: XBOX_RETAIL_PDB +0x194 (old: m_uiMessageCount)
    BSSimpleArray<HUDMainMenu__SubtitleData*, 1024> xSubtitles; // src: XBOX_RETAIL_PDB +0x198 (old: m_kSubtitleArray)
    HUDMainMenu__SubtitleData* pCurrSubtitle; // src: XBOX_RETAIL_PDB +0x1a8 (old: m_pCurrentSubtitle)
    BSSoundHandle GeigerSound; // src: XBOX_RETAIL_PDB +0x1ac (old: m_kTargetDisplayData)
    TESObjectREFR* pLastObject; // src: XBOX_RETAIL_PDB +0x1b8 (old: m_pCrosshairReference)
    int iHUDVisibilityMenuModeFlags; // src: XBOX_RETAIL_PDB +0x1bc (old: m_iHudValueFirstBeforeMode)
    int iHUDVisibilityUserSettings; // src: XBOX_RETAIL_PDB +0x1c0 (old: m_iHudValueSecondBeforeMode)
    HUD_MENU_MODE eMenuMode; // src: XBOX_RETAIL_PDB +0x1c4 (old: m_eHudMenuMode)
    HotkeyWheelDisplay HKWheel; // src: XBOX_RETAIL_PDB +0x1c8 (old: m_kMenuData)
    bool bScopeVisible; // src: XBOX_RETAIL_PDB +0x1fc (old: m_bHudModeActive)
    unsigned char layoutPadding1FD[3];
    NiControllerSequence* pBreathMeterAnim; // src: XBOX_RETAIL_PDB +0x200 (old: m_pHudAnimationSequence)
    bool bXPMeterFinishedMoving; // src: XBOX_RETAIL_PDB +0x204 (old: m_bSequenceActive)
    bool bForceObjectiveReminders; // src: XBOX_RETAIL_PDB +0x205 (old: m_bHudAnimationActive)
    unsigned char layoutPadding206[2];
    unsigned int uiKillRegionDisplay; // src: XBOX_RETAIL_PDB +0x208 (old: m_uiHudAnimationCounter)
    BSSimpleList<RegionObjectEntry*>* pQuestList; // src: XBOX_RETAIL_PDB +0x20c (old: m_pRegionObjectListObj)
    int iCompassImageWidth; // src: XBOX_RETAIL_PDB +0x210 (old: m_iHudValueFirstAfterUpdateList)
    int iCompassDisplayWidth; // src: XBOX_RETAIL_PDB +0x214 (old: m_iHudValueSecondAfterUpdateList)
    int iCompassHalfAngle; // src: XBOX_RETAIL_PDB +0x218 (old: m_iHudValueThirdAfterUpdateList)
    Actor* pCurrentEnemy; // src: XBOX_RETAIL_PDB +0x21c (old: m_pTargetActor)
    bool bWasSneaking; // src: XBOX_RETAIL_PDB +0x220 (old: m_bTargetActorVisible)
    unsigned char layoutPadding221[3];
    GameTimerRecord HudTimer; // src: XBOX_RETAIL_PDB +0x224 (old: m_cBuffer)
    unsigned int iEnemyHealthTimer; // src: XBOX_RETAIL_PDB +0x244 (old: m_uiHudValueFirstAfterActor)
    unsigned int uiQuestReminderTimer; // src: XBOX_RETAIL_PDB +0x248 (old: m_uiHudValueSecondAfterActor)
    int uiDDTdisplayTimer; // src: XBOX_RETAIL_PDB +0x24c (old: m_iHudValueFirstAfterUnsignedValues)
    int uiEnemyDDTdisplayTimer; // src: XBOX_RETAIL_PDB +0x250 (old: m_iHudValueSecondAfterUnsignedValues)
    bool bKillQuestUpdates; // src: XBOX_RETAIL_PDB +0x254 (old: m_bQuestObjectiveUpdatesEnabled)
    unsigned char layoutPadding255[3];
    BSSimpleList<HUDMainMenu__QuestObjective*> xQuestObjectives; // src: XBOX_RETAIL_PDB +0x258 (old: m_kQuestObjectives)
    bool bQuestNameShowing; // src: XBOX_RETAIL_PDB +0x260 (old: m_bQuestObjectiveUpdatePending)
    bool bObjectiveNameShowing; // src: XBOX_RETAIL_PDB +0x261 (old: m_bXPUpdatePending)
    unsigned char layoutPadding262[2];
    BSSimpleList<HUDMainMenu__XPUpdate*> xXPUpdates; // src: XBOX_RETAIL_PDB +0x264 (old: m_kXPUpdates)
    BSSimpleList<HUDMainMenu__RadiationUpdate*> xRadiationUpdates; // src: XBOX_RETAIL_PDB +0x26c (old: m_kRadiationUpdates)
    float fShake; // src: XBOX_RETAIL_PDB +0x274 (old: m_fRadiationUpdateTimer)

    void HUDMainMenu_KillQuestUpdates();

    static HUDMainMenu* g_pHudMainMenuInstance;
    static void HUDMainMenu_SetTargetType(TESObjectREFR*, bool);
    static void HUDMainMenu_SetGunScopeVisible(bool);
    static bool UpdateTargetReference(TESObjectREFR*, bool, bool);
    bool RefreshTargetDisplay();
    static void UpdateTargetActor(Actor* apActor);
    static void UpdateVisibilityState(int aeMenuMode);
};
