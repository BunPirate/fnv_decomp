#pragma once

class Tile;
class InventoryStackRecord;

class HotkeyWheelDisplay
{
public:
    Tile* pWheel;
    Tile* pHotkeyTilesA[8];
    bool bSelectingHotkey;
    unsigned char layoutPadding25[3];
    int iLastHighlightedHotkey;
    int iUT_HighlightedHotkey;
    int iUT_HighlightedText;

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
