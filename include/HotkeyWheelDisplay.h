#pragma once

class Tile;
class InventoryStackRecord;

class HotkeyWheelDisplay
{
public:
    Tile* pWheel; // src: XBOX_RETAIL_PDB +0x0 (old: m_pWheelTile)
    Tile* pHotkeyTilesA[8]; // src: XBOX_RETAIL_PDB +0x4 (old: m_ppHotkeySlotTiles)
    bool bSelectingHotkey; // src: XBOX_RETAIL_PDB +0x24 (old: m_bHasHotkeySelection)
    unsigned char layoutPadding25[3];
    int iLastHighlightedHotkey; // src: XBOX_RETAIL_PDB +0x28 (old: m_iTileValueIdAtOffset28)
    int iUT_HighlightedHotkey; // src: XBOX_RETAIL_PDB +0x2c (old: m_iTileValueIdAtOffset2C)
    int iUT_HighlightedText; // src: XBOX_RETAIL_PDB +0x30 (old: m_iTileValueIdAtOffset30)

    HotkeyWheelDisplay();
    ~HotkeyWheelDisplay();
    bool GetVisible();
    void SetVisible(bool);
    void RefreshHotkeyWheel();
    void Initialize(Tile*);
    int SetHotkeyItem(int, int);
    void SetHotkeyItem(InventoryStackRecord*);
    int SetHotkeyItem(unsigned int, bool);
    int HandleHotkeyInput(int, int);
    int GetSelectedHotkeyIndex(int);
    int DispatchByType(int key);
};
