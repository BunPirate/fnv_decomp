#pragma once

#include "Menu.h"

// pdb: class QuantityMenu, size 0x44, bases: Menu, 2 members
class QuantityMenu : public Menu
{
public:
    virtual ~QuantityMenu();

    unsigned char pTiles[0x1c];

    QuantityMenu();
    bool HandleButton(int aiButton, float afValue);
    int GetMenuID_00720a30();
    void* FUN_00720a40(unsigned int flags);
    void ClearGlobalAndDestroyMenu();
};
