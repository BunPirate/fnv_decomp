#pragma once

#include "Menu.h"
#include "ListBox_int_.h"
#include "GameTimerRecord.h"

// pdb: class MessageMenu, size 0x94, bases: Menu, 4 members
class MessageMenu : public Menu
{
public:
    Tile* pTiles[6];             // 0x28 // src: XBOX_RETAIL_PDB +0x28 (old: m_pTiles)
    ListBox_int_ lbButtons;    // 0x40 // src: XBOX_RETAIL_PDB +0x40 (old: m_kChoiceList)
    GameTimerRecord MMTimer; // 0x70 // src: XBOX_RETAIL_PDB +0x70 (old: m_kTimerCalls)
    unsigned int uiMessageStartTime; // 0x90 // src: XBOX_RETAIL_PDB +0x90 (old: m_uiMessageCount)

    MessageMenu();
    virtual int GetClass();
    static void SetMessageMenuActive(bool);
};
