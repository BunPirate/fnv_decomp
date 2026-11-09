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
    int iCurrentPage;
    Tile* pMapTile;
    float fWaveformAnimationStartTime;
    bool bShowingAllNotes;
    char pad8d[3];
    BGSNote* m_pSelectedNote;
    unsigned int uiNoteEnterStartTime;
    MapSoundList m_kSoundList;
    MapArray<BSStringT<char> > SubtitlesToShow;
    BSSimpleList<BSSoundHandle>* m_pkActiveSoundList;
    bool bSoundsLoading;
    char padbd[3];
    float fSoundDurationMillis;
    int iSoundPlayStartTime;
    float fOldPipboyRadioVolume;
    TESQuest* pDisplayedQuest;
    RegionObjectEntry* pDisplayedQuestTarget;
    Tile* pHighlightedMapMarker;
    BSSimpleList<TESObjectREFR*> WorldMapMarkerList, LocalMapMarkerList;
    NiPoint2 MapNWCorner, MapSECorner;
    TESForm* PlayerMarkerSpace;
    NiPoint3 PlayerMarkerPos;
    TESForm* pMapSpace;
    TESWorldSpace* pRootMapSpace;
    bool bRootSpaceChanged;
    char pad111[3];
    TESObjectREFR* pMapPlayerRef;
    TESObjectREFR* pFastTravelMarker;
    TESObjectCELL* pAdjustNorthRotationCell;
    NiPoint2 WorldMapDragStart;
    unsigned int uiNextLocalMapGrid;
    bool bFogOfWarEnabled;
    char pad12d[3];
    ListBox<TESQuest*> lbQuestsList;
    ListBox<BGSNote*> lbNotesList;
    ListBox<TESObjectREFR*> lbRadioStationsList;
    ListBox<BGSQuestObjective*> lbQuestObjectivesList;
    ListBox<TESChallenge*> lbChallengeList;
    MapArray<Tile*> debugWaypoints;

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
