#pragma once

#include "Menu.h"
#include "ListBox_int_.h"
#include "GameTimerRecord.h"

// pdb: class MessageMenu, size 0x94, bases: Menu, 4 members
class MessageMenu : public Menu
{
public:
    Tile* pTiles[6];             // 0x28
    ListBox_int_ lbButtons;    // 0x40
    GameTimerRecord MMTimer; // 0x70
    unsigned int uiMessageStartTime; // 0x90

    MessageMenu();
    virtual int GetClass();
    static void SetMessageMenuActive(bool);
};
