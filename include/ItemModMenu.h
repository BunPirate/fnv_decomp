#pragma once

#include "Menu.h"
#include "ListBox_ItemChange___.h"

class Tile;
class EqEntry;

// pdb: class ItemModMenu, size 0x90, bases: Menu, 2 members
class ItemModMenu : public Menu
{
public:
    Tile* pTiles[14]; // src: XBOX_RETAIL_PDB +0x28 (old: m_pTiles)
    ListBox_ItemChange___ lbItemModList; // src: XBOX_RETAIL_PDB +0x60 (old: m_kItemList)

    ItemModMenu();
    Tile* __cdecl Create();
    virtual ~ItemModMenu();
    virtual void HandleSelection(int, Tile*) override;
    virtual int GetClass() override;
    virtual bool HandleMenuInput(int, float) override;

    void* DestroyIfFlagged(unsigned int);
    void UpdateItemModTile(int, Tile*);
    bool ItemModItem(EqEntry*);
    void DoEnter(int, int);
};
