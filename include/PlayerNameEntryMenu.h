#pragma once

#include "Menu.h"

// pdb: class PlayerNameEntryMenu, size 0x60 (here 0x28), bases: Menu, 2 members
class PlayerNameEntryMenu : public Menu
{
public:
    virtual ~PlayerNameEntryMenu();
    void UpdateDialog() override;
    void Finish(const char* name);
};
