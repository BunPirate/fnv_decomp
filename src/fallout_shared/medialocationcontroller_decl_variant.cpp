
// src/fallout_shared/medialocationcontroller_decl_variant.cpp - declaration variant unit created 2026-10-26 by decl_variants.py for paused function 0x00595310: the skeleton of src/fallout_shared/medialocationcontroller.cpp
// with declarations corrected to what the original code does (medialocationcontroller_update_decls.h: class MediaLocationController : public TESForm, pu -> class MediaLocationController : public TESForm, pu). Move the function to its real unit once
// that unit declares it this way.

#include "../../include/Actor.h"
#include "../../include/BGSDefaultObjectManager.h"
#include "../../include/BSAudio.h"
#include "../../include/MediaLocationController.h"
#include "../../include/MediaSet.h"
#include "../../include/MediaSetEntry.h"
#include "../../include/NiPoint3.h"
#include "../../include/PlayerCharacter.h"
#include "../../include/TESFaction.h"
#include "../../include/TESObjectREFR.h"
#include "../../include/TESDataHandler.h"
unsigned int __cdecl GetRandomNumberInRange(int aiMin, int aiMax);
int __cdecl Warning(const char* apFormat, ...);
extern TESDataHandler* g_dataHandler;

// @fnv 0x00595310
// pdb: MediaLocationController::MediaLocationController | MediaLocationController.obj | retail, upstream name already matches, high
MediaLocationController::MediaLocationController()
{
    SetFormType(static_cast<ENUM_FORM_ID>(0x70));
    iFlags = 4;
    fLayerTwoPercent = 0.33f;
    fLayerThreePercent = 0.66f;
    fLocationDelay = 0.0f;
    uiDayStart = 64;
    uiNightStart = 336;
    lConditionalNeutralList.RemoveAll();
    lConditionalAllyList.RemoveAll();
    lConditionalFriendList.RemoveAll();
    lConditionalEnemyList.RemoveAll();
    lLocationList.RemoveAll();
    lBattleList.RemoveAll();
    pFaction = 0;
    rFactionConditional = FIGHT_REACTION_FIGHT_REACTION_ENEMY;
    pAudioMarker = 0;
    uiLocationDelay = 0;
    uiLayerTime = 0;
    uiLoopTime = 0;
    uiMediaStartTime = 0;
    bInTension = false;
    bInCombat = false;
    bIsDay = false;
    bIsConditional = false;
    cCurrentLayer = 0;
    pCurrentMediaSet = 0;
    uiFoundHostileActors = 0;
    uiFoundFactionActors = 0;
    eCurrentFactionReaction = FIGHT_REACTION_FIGHT_REACTION_ENEMY;
}
