#pragma once

#include "Menu.h"

// pdb: class RaceSexMenu, size 0x180 (here 0x1a4), bases: Menu, 18 members
class RaceSexMenu : public Menu
{
public:
    RaceSexMenu();

    void SetTile(int aiID, Tile* apTile);
    void OnRaceSelected(void*);
    int __thiscall GetMenuID_007ac4f0();
    void OnRaceSelected_Thunk(void* apList);
    void OnRaceSelected_Thunk(int aiIndex);

    union
    {
        unsigned char layoutExtension[0x17c];
        struct
        {
            unsigned char unk28[0x50];
            Tile* m_pTiles[24];
            unsigned char unkD8[0xcc];
        };
    };
};
