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

    Tile* pTiles[87];
    Tile* pActive;
    float fSeenLevel;
    BSSimpleList<HUDMainMenu__MessageData*> xMessages;
    unsigned int uiMessageStartTime;
    BSSimpleArray<HUDMainMenu__SubtitleData*, 1024> xSubtitles;
    HUDMainMenu__SubtitleData* pCurrSubtitle;
    BSSoundHandle GeigerSound;
    TESObjectREFR* pLastObject;
    int iHUDVisibilityMenuModeFlags;
    int iHUDVisibilityUserSettings;
    HUD_MENU_MODE eMenuMode;
    HotkeyWheelDisplay HKWheel;
    bool bScopeVisible;
    unsigned char layoutPadding1FD[3];
    NiControllerSequence* pBreathMeterAnim;
    bool bXPMeterFinishedMoving;
    bool bForceObjectiveReminders;
    unsigned char layoutPadding206[2];
    unsigned int uiKillRegionDisplay;
    BSSimpleList<RegionObjectEntry*>* pQuestList;
    int iCompassImageWidth;
    int iCompassDisplayWidth;
    int iCompassHalfAngle;
    Actor* pCurrentEnemy;
    bool bWasSneaking;
    unsigned char layoutPadding221[3];
    GameTimerRecord HudTimer;
    unsigned int iEnemyHealthTimer;
    unsigned int uiQuestReminderTimer;
    int uiDDTdisplayTimer;
    int uiEnemyDDTdisplayTimer;
    bool bKillQuestUpdates;
    unsigned char layoutPadding255[3];
    BSSimpleList<HUDMainMenu__QuestObjective*> xQuestObjectives;
    bool bQuestNameShowing;
    bool bObjectiveNameShowing;
    unsigned char layoutPadding262[2];
    BSSimpleList<HUDMainMenu__XPUpdate*> xXPUpdates;
    BSSimpleList<HUDMainMenu__RadiationUpdate*> xRadiationUpdates;
    float fShake;

    void HUDMainMenu_KillQuestUpdates();

    static HUDMainMenu* g_pHudMainMenuInstance;
    static void HUDMainMenu_SetTargetType(TESObjectREFR*, bool);
    static void HUDMainMenu_SetGunScopeVisible(bool);
    static bool UpdateTargetReference(TESObjectREFR*, bool, bool);
    bool RefreshTargetDisplay();
    static void UpdateTargetActor(Actor* apActor);
    static void UpdateVisibilityState(int aeMenuMode);
};
