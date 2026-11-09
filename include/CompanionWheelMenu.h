#pragma once

#include "Menu.h"
#include "BSSoundHandle.h"

class Actor;
class TESTopic;

// CompanionWheelMenu (FNV menu class 1075): ctor 0x00754b40 installs vftable 0x01071d0c; MenuSystem::GetMenuById
// allocates 0x88. Offsets from the ctor, the tile setter 0x00754c00 (index 0..15 into +0x28) and companionwheelmenu.cpp
// (the four toggles 0x007560c0/0x007561b0/0x007562b0/0x007563a0 flip the bytes at +0x6c..+0x6f).
// pdb: class CompanionWheelMenu, size 0x88, bases: Menu, 10 members
class CompanionWheelMenu : public Menu
{
public:
    CompanionWheelMenu();
    virtual ~CompanionWheelMenu();
    virtual void HandleSelection(int aiID, Tile* apTarget);  // 0x007552e0
    virtual void UpdateDialog();  // 0x00755480: clears the text tile at its timeout, steers the wheel by the stick
    virtual int GetClass();
    virtual bool HandleMenuInput(int aiButton, float afValue);  // 0x007556b0

    void CompanionWheelMenu_SetButtonAsHighlighted(int aiID, bool bForceRefresh);  // 0x007557d0
    void SetButtonAsHighlighted(float fInputStickAngle);           // selects the tile under the stick angle
    void SetTileText(const char* apText);       // 0x00755d90
    void Do_ToggleNearFar();      // 0x007560c0
    void Do_ToggleRangedMelee();                  // 0x007562b0
    void Do_ToggleStayFollow();                  // 0x007563a0
    void CompanionWheelMenu_Do_ToggleAggressivePassive();                    // 0x007561b0
    void HealCompanion();                       // 0x00756490
    void CompanionWheelMenu_Do_OpenInventory();
    void Do_Backup();                        // opens the companion's dialogue and closes the wheel
    void UpdateCompanionInteraction();          // 0x00756980
    void PlayTopicResponse(TESTopic* apTopic);  // 0x007573d0
    void RunTopicResultScripts(TESTopic* apTopic);  // 0x007575b0

    Tile* pTiles[16];               // +0x28
    Actor* m_pRelatedCompanion;              // +0x68
    bool m_bFollowingLong; // +0x6c, toggled by 0x007560c0
    bool m_bAggressiveStance;               // +0x6d, toggled by 0x007561b0
    bool m_bRangedCombat;      // +0x6e, toggled by 0x007562b0
    bool m_bFollowing;             // +0x6f, toggled by 0x007563a0
    int m_CurrentlySelectedTile;                  // +0x70, -1 in the ctor; the selected tile index (SelectTile 0x007557d0)
    bool bTalkToOnClose;                    // +0x74, 0 in the ctor
    unsigned int m_nTimeToClearSubtitle;    // +0x78, tick count at which UpdateDialog clears tile 12's text (set by 0x00757690)
    BSSoundHandle m_hCurrentReactivityBark;     // +0x7c, built by 0x0041a250
};
