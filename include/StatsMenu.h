#pragma once

#include "Menu.h"
#include "StatsMenu__HealingOption.h"
#include "StatsMenu__NamedEffectsList.h"
#include "StatsMenu__StatusEffectList.h"
#include "ListBox_enum_ActorValue__Index_.h"
#include "ListBox_enum_MiscStatManager__MiscStatID_.h"
#include "ListBox_PerkRankData___.h"
#include "ListBox_StatsMenu__StatusEffect___.h"
#include "ListBox_TESReputation___.h"

#include "MiscStatManager.h"

// pdb: class StatsMenu, size 0x2a4, bases: Menu, 16 members
class StatsMenu : public Menu
{
public:
    enum Page
    {
        SM_STATUS = 0,
        SM_FIRST_PAGE = 0,
        SM_SPECIAL = 1,
        SM_SKILLS = 2,
        SM_PERKS = 3,
        SM_GENERAL = 4,
        SM_LAST_PAGE = 4,
        SM_PAGE_COUNT = 5
    };

    class BodyPartDisplay
    {
    public:
        int m_iBodyPartCount;
        BSSimpleList<Tile*> m_kBodyPartTileLists[6];
        unsigned int m_auiBodyPartValues[6];

        BodyPartDisplay();
    };

    virtual void AssignTileByID(int, Tile*);
    virtual int GetClass();

    StatsMenu__HealingOption pHealingOptionsA[4];
    StatsMenu__NamedEffectsList xNamedEffects;
    StatsMenu__StatusEffect* pRadiationEffect;
    StatsMenu__StatusEffect* pDehydrationEffect;
    StatsMenu__StatusEffect* pHungerEffect;
    StatsMenu__StatusEffect* pSleepEffect;
    StatsMenu__StatusEffectList xStatusEffects;

    Tile* pTiles[60];
    ListBox_enum_ActorValue__Index_ lbSpecial;
    ListBox_enum_ActorValue__Index_ lbSkills;
    ListBox_PerkRankData___ lbPerks;
    ListBox_enum_MiscStatManager__MiscStatID_ lbGeneral;
    ListBox_StatsMenu__StatusEffect___ lbStatusEffects;
    ListBox_TESReputation___ lbReputation;
    union
    {
        bool m_bUpdateOption;
        unsigned char m_bHealingMode;
    };
    bool bActiveEffectsUpdatedThisFrame;
    unsigned char unk2A2[2];

    static StatsMenu* ms_pInventoryMenu;
    static float GetChartScale();
    static void SetStatsPage(unsigned char page);
    static bool SetTileFlashing(Tile*, unsigned int);
    static void SPECIALUpdateFn(Tile* apTile, ActorValue::Index aeIndex);
    static void UpdateSecondaryActorValueTile(Tile* tile, ActorValue::Index value);
    static void UpdateMiscStatTile(Tile* tile, MiscStatManager__MiscStatID value);
    static void __cdecl UpdatePlayerTitle();
    static void ClearPerks();

    void SetCurrentPage(Page aiPage);
    Page GetCurrentPage();
    void SetCurrentPageFromChar(char a);
    int GetTraitForValue(ActorValue::Index value);
    void UpdateAllActorValues();
    void RefreshActorValueTile(ActorValue::Index value);
    void RefreshMiscStat(MiscStatManager__MiscStatID value);
    void RefreshMiscStat(MiscStatManager::MiscStat value);
    void __thiscall RefreshHealingOptions();
    void FUN_0071f700();
    void* FUN_0071f6d0(unsigned int flags);
};
