// fallout/interface/listbox.h: declares StartMenu, TileListBoxCalls_listbox
#ifndef FNV_LISTBOX_MATCH_UNIT_H
#define FNV_LISTBOX_MATCH_UNIT_H


#include <stddef.h>
#include "../../../include/BSSimpleList.h"
#include "../../../include/BSSimpleArray.h"
#include "../../../include/BGSSaveLoadFileEntry.h"
#include "../../../include/NiTListBase_NiTPointerAllocator_unsigned_int__Tile___.h"
#include "../../../include/NiTListBase_NiTPointerAllocator_unsigned_int__Tile_____AntiBloatAllocator.h"
#include "../../../include/NiTPointerAllocator_unsigned_int_.h"
#include "../../../include/NiTPointerListBase_NiTPointerAllocator_unsigned_int__Tile___.h"
#include "../../../include/NiTPointerList_Tile___.h"
#include "../../../include/BSSoundHandle.h"
#include "../../../include/StartMenu.h"
#include "../../../include/Tile.h"
// TileListBoxCalls_listbox: local type (was include/TileListBoxCalls.h, which had no evidence of one real class); its methods are 0x00a011b0 Tile::GetFloat
#include "../../../include/Tile.h"

class TileListBoxCalls_listbox : public Tile
{
  public:
    float GetFloat(int trait);
};
#include "listbox_decls.h"
#include "ListBoxBase.h"

class BGSNote;
class BGSQuestObjective;
class PerkForm;
class InventoryStackRecord;
template <class T> class ListBoxItem;

#include "../../../include/ListBox.h"


int __cdecl GetTileValueID(const char* name, int index);
Tile* __cdecl FindNamedTile(Tile* apTarget, const char* apName);

extern "C" const char kListBoxEnabled[] = "_enabled";
extern "C" const char kListBoxNumFiltered[] = "_number_of_visible_items";
extern "C" const char kListBoxScrollbar[] = "child(lb_scrollbar)";

template <>
// @fnv 0x007d87b0
// pdb: ListBox<BGSSaveLoadFileEntry *>::NumVisible | StartMenu.obj | debug, object-file gap fill, medium
unsigned int ListBox<BGSSaveLoadFileEntry*>::GetVisibleEntryCount()
{
    return m_pListTile != 0
               ? (unsigned int)((TileListBoxCalls_listbox*)m_pListTile)->GetFloat(GetTileValueID(kListBoxNumFiltered, -1))
               : 0;
}

template <>
// @fnv 0x007d8d60
// pdb: ListBox<BGSSaveLoadFileEntry *>::Select | StartMenu.obj | debug, call graph (shared callers), high
// pdb params: apSelectItem
bool ListBox<BGSSaveLoadFileEntry*>::SetSelection(Tile* apSelectItem)
{
    return SetSelection(apSelectItem, 0);
}

template <>
// @fnv 0x007a1910
PerkForm* ListBox<PerkForm*>::GetSelectedData()
{
    return GetSelectedData(m_pSelectedTile);
}

template <>
// @fnv 0x0075a0d0
void ListBox<unsigned int>::Initialize(Tile* container, const char* templateName)
{
    m_pListTile = container;
    pTemplateName = templateName;
    m_pHighlightedTile = FindNamedTile(m_pListTile, kListBoxScrollbar);
}

template <>
// @fnv 0x007cc5d0
unsigned int ListBox<StartMenu::Option*>::AddItem(unsigned int mask)
{
    return ((unsigned int)m_pListTile & mask) != 0;
}

// @fnv 0x00418900
BSSoundHandle& BSSoundHandle::operator=(const BSSoundHandle& other)
{
    iSoundID = other.iSoundID;
    bAssumeSuccess = other.bAssumeSuccess;
    eState = other.eState;
    return *this;
}

template <>
// @fnv 0x007d7630
// pdb: ListBox<BGSSaveLoadFileEntry *>::IsVisible | StartMenu.obj | debug, call graph (shared callers), medium
bool ListBox<BGSSaveLoadFileEntry*>::IsEnabled()
{
    return m_pListTile && m_pListTile->IsVisible();
}

template <>
// @fnv 0x00730ed0
// pdb: ListBox<ItemChange *>::Highlight | BarterMenu.obj | retail, vtable slot, high
// pdb params: apHighlightItem
bool ListBox<InventoryStackRecord*>::Highlight(Tile* apHighlightItem)
{
    if (IsEnabled() && (!apHighlightItem || (((ListBox_int_*)this)->ContainsKey(apHighlightItem) &&
                                  apHighlightItem->ContainsTrait(GetTileValueID(kListBoxEnabled, -1)))))
    {
        m_pSelectedTile = apHighlightItem;
        ResetItems();
        return true;
    }
    else
    {
        return false;
    }
}
template <>
// @fnv 0x00764a00
// pdb: ListBox<int>::Highlight | DialogMenu.obj | retail, vtable slot, high
// pdb params: apHighlightItem
bool ListBox<int>::Highlight(Tile* apHighlightItem)
{
    if (IsEnabled() && (!apHighlightItem || (((ListBox_int_*)this)->ContainsKey(apHighlightItem) &&
                                  apHighlightItem->ContainsTrait(GetTileValueID(kListBoxEnabled, -1)))))
    {
        m_pSelectedTile = apHighlightItem;
        ResetItems();
        return true;
    }
    else
    {
        return false;
    }
}
template <>
// @fnv 0x007a3170
// pdb: ListBox<BGSNote *>::Highlight | MapMenu.obj | retail, vtable slot, high
// pdb params: apHighlightItem
bool ListBox<BGSNote*>::Highlight(Tile* apHighlightItem)
{
    if (IsEnabled() && (!apHighlightItem || (((ListBox_int_*)this)->ContainsKey(apHighlightItem) &&
                                  apHighlightItem->ContainsTrait(GetTileValueID(kListBoxEnabled, -1)))))
    {
        m_pSelectedTile = apHighlightItem;
        ResetItems();
        return true;
    }
    else
    {
        return false;
    }
}
template <>
// @fnv 0x007a4ce0
// pdb: ListBox<BGSQuestObjective *>::Highlight | MapMenu.obj | retail, vtable slot, high
// pdb params: apHighlightItem
bool ListBox<BGSQuestObjective*>::Highlight(Tile* apHighlightItem)
{
    if (IsEnabled() && (!apHighlightItem || (((ListBox_int_*)this)->ContainsKey(apHighlightItem) &&
                                  apHighlightItem->ContainsTrait(GetTileValueID(kListBoxEnabled, -1)))))
    {
        m_pSelectedTile = apHighlightItem;
        ResetItems();
        return true;
    }
    else
    {
        return false;
    }
}

#endif
