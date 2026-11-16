#pragma once

#include "Menu.h"
#include "NiPoint2.h"
#include "NiPoint3.h"
#include "BSSoundHandle.h"

class BGSNote;
class BGSQuestObjective;
class MapPoint3;
class PathingPath;
class RegionObjectEntry;
class TESChallenge;
class TESForm;
class TESObjectCELL;
class TESObjectREFR;
class TESQuest;
class TESWorldSpace;
class Tile;
class TileMenu;

template <class T> class BSStringT;

template <class T, unsigned int N = 1024>
class MapArray
{
public:
    MapArray();
    ~MapArray();
    T* data;
    unsigned int size;
    unsigned int capacity;
    unsigned int grow;
    void Clear(bool);
    void Add(const T&);
};

#include "ListBox.h"

class MapSoundList : public BSSimpleList<BSSoundHandle>
{
public:
    MapSoundList();
    ~MapSoundList();
};

// pdb: class MapMenu, size 0x230, bases: Menu, 38 members
class MapMenu : public Menu
{
public:
    virtual ~MapMenu();
    virtual void AssignTileByID(int index, Tile* tile);
    virtual void HandleLeftClickPress(unsigned int, Tile*);
    virtual void HandleSelection(int, Tile*);
    virtual void HandleMouseover(unsigned int, Tile*);
    virtual void HandleMouseoverTileAlt(unsigned int, Tile*);
    virtual void PostDragTileChange(unsigned int, Tile*, Tile*);
    virtual void PreDragTileChange(unsigned int, Tile*, Tile*);
    virtual void HandleActiveMenuClick(unsigned int, Tile*);
    virtual void OnClickHeld(unsigned int, Tile*);
    virtual void HandleMousewheel(unsigned int, Tile*);
    virtual void UpdateDialog();
    virtual bool HandleKeyboardInput(unsigned int);
    virtual int GetClass();
    virtual bool HandleMenuInput(int, float);
    virtual bool HandleControllerInput(int, Tile*);
    virtual void OnUpdateUserTrait(int);
    virtual void HandleControllerConnectOrDisconnect(bool);

    Tile* m_pTiles[22];
    int iCurrentPage; // src: XBOX_RETAIL_PDB +0x80 (old: m_iMapDisplayMode)
    Tile* pMapTile; // src: XBOX_RETAIL_PDB +0x84 (old: m_pMapTile)
    float fWaveformAnimationStartTime; // src: XBOX_RETAIL_PDB +0x88 (old: m_fMapRotation)
    bool bShowingAllNotes; // src: XBOX_RETAIL_PDB +0x8c (old: m_bMapMenuActive)
    char pad8d[3];
    BGSNote* m_pSelectedNote;
    unsigned int uiNoteEnterStartTime; // src: XBOX_RETAIL_PDB +0x94 (old: m_uiMapState)
    MapSoundList m_kSoundList;
    MapArray<BSStringT<char> > SubtitlesToShow;
    BSSimpleList<BSSoundHandle>* m_pkActiveSoundList;
    bool bSoundsLoading; // src: XBOX_RETAIL_PDB +0xbc (old: m_bMapListUpdatePending)
    char padbd[3];
    float fSoundDurationMillis; // src: XBOX_RETAIL_PDB +0xc0 (old: m_fMapZoom)
    int iSoundPlayStartTime; // src: XBOX_RETAIL_PDB +0xc4 (old: m_iMapSelectionIndex)
    float fOldPipboyRadioVolume; // src: XBOX_RETAIL_PDB +0xc8 (old: m_fSavedMusicVolume)
    TESQuest* pDisplayedQuest; // src: XBOX_RETAIL_PDB +0xcc (old: m_pSelectedQuest)
    RegionObjectEntry* pDisplayedQuestTarget; // src: XBOX_RETAIL_PDB +0xd0 (old: m_pSelectedMapMarkerInfo)
    Tile* pHighlightedMapMarker; // src: XBOX_RETAIL_PDB +0xd4 (old: m_pSelectedMarkerTile)
    BSSimpleList<TESObjectREFR*> WorldMapMarkerList, LocalMapMarkerList; // src: XBOX_RETAIL_PDB +0xd8 (old: m_kMapMarkerList)
    NiPoint2 MapNWCorner, MapSECorner; // src: XBOX_RETAIL_PDB MapSECorner +0xf0 (old: m_kMapMaximumPoint); MapNWCorner +0xe8 (old: m_kMapMinimumPoint)
    TESForm* PlayerMarkerSpace; // src: XBOX_RETAIL_PDB +0xf8 (old: m_pCurrentMapSpace)
    NiPoint3 PlayerMarkerPos; // src: XBOX_RETAIL_PDB +0xfc (old: m_kPlayerWorldPosition)
    TESForm* pMapSpace; // src: XBOX_RETAIL_PDB +0x108 (old: m_pCurrentMapForm)
    TESWorldSpace* pRootMapSpace; // src: XBOX_RETAIL_PDB +0x10c (old: m_pCurrentWorldspace)
    bool bRootSpaceChanged; // src: XBOX_RETAIL_PDB +0x110 (old: m_bLocalMapMode)
    char pad111[3];
    TESObjectREFR* pMapPlayerRef; // src: XBOX_RETAIL_PDB +0x114 (old: m_pFirstMapReference)
    TESObjectREFR* pFastTravelMarker; // src: XBOX_RETAIL_PDB +0x118 (old: m_pSecondMapReference)
    TESObjectCELL* pAdjustNorthRotationCell;
    NiPoint2 WorldMapDragStart; // src: XBOX_RETAIL_PDB +0x120 (old: m_kMapOffset)
    unsigned int uiNextLocalMapGrid; // src: XBOX_RETAIL_PDB +0x128 (old: m_uiMapMarkerCount)
    bool bFogOfWarEnabled; // src: XBOX_RETAIL_PDB +0x12c (old: m_bNeedsMapUpdate)
    char pad12d[3];
    ListBox<TESQuest*> lbQuestsList; // src: XBOX_RETAIL_PDB +0x130 (old: m_kQuestListBox)
    ListBox<BGSNote*> lbNotesList; // src: XBOX_RETAIL_PDB +0x160 (old: m_kNoteListBox)
    ListBox<TESObjectREFR*> lbRadioStationsList; // src: XBOX_RETAIL_PDB +0x190 (old: m_kMapMarkerListBox)
    ListBox<BGSQuestObjective*> lbQuestObjectivesList; // src: XBOX_RETAIL_PDB +0x1c0 (old: m_kObjectiveListBox)
    ListBox<TESChallenge*> lbChallengeList; // src: XBOX_RETAIL_PDB +0x1f0 (old: m_kChallengeListBox)
    MapArray<Tile*> debugWaypoints; // src: XBOX_RETAIL_PDB +0x220 (old: m_kMapMarkerTiles)

    void UpdateLocalMap();
    void UpdateWorldMap();
    void UpdateQuestObjectiveList();
    void UpdateNotes();
    void UpdateChallenges();
    void SetNote(BGSNote* apNote);
    void RefreshRadioList();
    void SetCurrentPage(unsigned char);
    void SetCurrentPage(int);
    void FUN_007069f0(unsigned char);
    void UpdateCurrentPage();
    void ToggleNotesChallengeMode(bool);
    void ResetWaveform();
    static void MapMenu_SetKnobPosition(bool);
    TESWorldSpace* CalculatePlayerMarkerSpace(NiPoint3);
    TESWorldSpace* CalculatePlayerMarkerSpace(MapPoint3);
    void Menu_SetRenderedMenu();
    void RefreshMapMenu(bool selected);
    MapMenu();
    static Tile* Create();
    static void UpdateMenu();
    static void ClearAudioLogSubtites();
    static void SetMapPositionToPlayer();
    static void UpdateMapPosition();
    static void OpenMap();
    void UpdateSelectedQuestMarkers();
    void SelectNote(BGSNote*);
    void RefreshMapData();
    void SetMapDisplayMode(bool);
    NiPoint3 WorldToMapPosition(NiPoint3, TESWorldSpace*);
    NiPoint3 MapToWorldPosition(NiPoint3, TESWorldSpace*);
    MapPoint3 WorldToMapPosition(MapPoint3, TESWorldSpace*);
    MapPoint3 MapToWorldCoord(MapPoint3, TESWorldSpace*);
    TESObjectREFR* GetTeleportDestination(TESObjectREFR*, PathingPath*);
    void RefreshMapMarkers();
    void UpdateMapObjectives();
    void UpdateMapHighlight();
    void UpdatePlayerMapMarker();
    void SetFlag8000();
    bool HasNoZeroEntries();
    void SetTileMenu(TileMenu*, bool);
    void SetMenuVisibility(bool);
};
