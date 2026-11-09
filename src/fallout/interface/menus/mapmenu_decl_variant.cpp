
// src/fallout/interface/menus/mapmenu_decl_variant.cpp - declaration variant unit created 2026-10-26 by decl_variants.py for paused function 0x0079af30: the skeleton of src/fallout/interface/menus/mapmenu.cpp
// with declarations corrected to what the original code does (mapmenu_decls.h: MapMenu += void FUN_0079af30(); void UpdateLocalMap(); void RefreshMap(); void UpdateQuestObjectiveList(); void RefreshNotesList(); void RefreshChallengeList(); void FUN_0079b460(bool a); void SetNote(BGSNote* note); void RefreshRadioList();; mapmenu_decls.h: void FUN_007a1a70(); void FUN_007a1c90(); void). Move the function to its real unit once
// that unit declares it this way.

#include "mapmenu_decls_decl_mapmenu.h"
// @fnv 0x007a1930
template <> void ListBox<TESQuest*>::ClearSelection(bool notify)
{
    SetSelectedTile(0, notify);
}

bool MapMenu_ShouldRenderLocalMap();
// @fnv 0x0079af30
// src: XBOX_PDB 0x0079af30
// pdb: MapMenu::UpdateCurrentPage | MapMenu.obj | retail, upstream name already matches, high
// pdb locals: ihighlightIndex, pnewHighlight, pselectedTile
void MapMenu::UpdateCurrentPage()
{
    int selected = -1;
    Tile* index = 0;
    lbQuestsList.SetEnabled(false);
    lbQuestObjectivesList.SetEnabled(false);
    lbNotesList.ListBox_BGSNote_SetEnabled(false);
    lbNotesList.ListBox_BGSNote_SetVisible(false);
    lbChallengeList.ListBox_TESChallenge_SetEnabled(false);
    lbChallengeList.ListBox_BGSNote_SetVisible(false);
    DAT_011da368->m_pTiles[11]->Set(0xfaf, 1);
    DAT_011da368->m_pTiles[12]->Set(0xfa3, 1);
    DAT_011da368->m_pTiles[18]->Set(0xfa3, 0);
    DAT_011da368->m_pTiles[21]->Set(0xfa3, 0);
    switch (DAT_011da368->iCurrentPage)
    {
    case 32:
        DAT_011da368->pMapTile = DAT_011da368->m_pTiles[2];
        if (!MapMenu_ShouldRenderLocalMap())
            DAT_011da368->UpdateLocalMap();
        break;
    case 33:
        DAT_011da368->pMapTile = DAT_011da368->m_pTiles[4];
        DAT_011da368->UpdateWorldMap();
        break;
    case 34:
        DAT_011da368->UpdateQuestObjectiveList();
        break;
    case 35:
        DAT_011da368->m_pTiles[18]->Set(0xfa3, 1);
        if (!DAT_011da36d)
        {
            DAT_011da368->lbNotesList.FUN_007312e0();
            DAT_011da368->UpdateNotes();
            if (m_pSelectedNote && !DAT_011da36d)
            {
                Tile* noteTile = lbNotesList.FindItemData(m_pSelectedNote);
                SetNote(m_pSelectedNote);
                if (noteTile)
                    noteTile->Set(DAT_011da348, 1);
            }
            DAT_011da368->lbNotesList.UpdateScrollSelection(true);
        }
        DAT_011da368->UpdateChallenges();
        ToggleNotesChallengeMode(false);
        break;
    case 36:
        DAT_011da368->m_pTiles[12]->Set(0xfa3, 0);
        selected =
            (int)(lbRadioStationsList.GetHighlightedItem() ? lbRadioStationsList.GetHighlightedItem()->FUN_00a011b0(0xfac)
                                                        : -1.0f);
        DAT_011da368->RefreshRadioList();
        index = lbRadioStationsList.GetTileAt(static_cast<unsigned int>(selected), false);
        if (index)
            InterfaceManager_GetSingleton()->InterfaceManager_SetCurrentFocusTarget(index, 0xfc3, 1);
        lbRadioStationsList.ScrollToHighlight();
        break;
    }
}
