#pragma once

#include "Menu.h"
#include "ListBox_ItemChange___.h"

class RepairTile;

// pdb: class RepairMenu, size 0x8c, bases: Menu, 2 members
class RepairMenu : public Menu
{
public:
    Tile* pTiles[13]; // src: XBOX_RETAIL_PDB +0x28 (old: m_pTiles)
    ListBox_ItemChange___ lbRepairList; // src: XBOX_RETAIL_PDB +0x5c (old: m_kItemList)

    __declspec(property(get=GetRepairList)) ListBox_ItemChange___& m_kRepairList;
    ListBox_ItemChange___& GetRepairList() { return lbRepairList; }

    RepairMenu();
    virtual ~RepairMenu();
    virtual void AssignTileByID(int tileID, Tile* tile);
    virtual int GetClass();

    void UpdateRepairList();
    bool IsWellFormedMenu_007b5730();
    void ApplyRepair(void*);
    void RefreshRepairMenu();
    void HandleRepairAction(int aiID, RepairTile* apTarget);
    void SetRepairMenuText(const char* astrMessage);

    static Tile* Create();
};

