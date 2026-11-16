#pragma once

#include "Menu.h"
#include "ListBox_int_.h"
#include "StrMem.h"
#include "BSSoundHandle.h"

class BGSTerminal;
class BGSNote;
class TextSource;
class TextAnimator;
class TESObjectREFR;

// pdb: class ComputersMenu, size 0xfc, bases: Menu, 15 members
class ComputersMenu : public Menu
{
public:
    class ComputerEntryList : public ListBox_int_
    {
    public:
        bool ContainsKey(Tile*);
        BGSTerminal* FindItemData(Tile*);
        Tile* Insert(BGSTerminal*, int, int, int);
        void Traverse(void (*)(Tile*, TESObjectREFR*), int, int);
        void ListBox_ItemChange_Traverse(void (__cdecl*)(Tile*, void*), int, int);
    };

    ComputersMenu();
    virtual ~ComputersMenu();
    virtual void AssignTileByID(int, Tile*);
    virtual void HandleSelection(int, Tile*);
    virtual void UpdateDialog();
    virtual int GetClass();
    virtual bool HandleControllerInput(int, Tile*);

    union
    {
        unsigned char layoutExtension[0x40];
        Tile* m_pTiles[16];
        struct
        {
            Tile* tile28;
            Tile* tile2c;
            Tile* tile30;
            Tile* tile34;
            Tile* tile38;
            Tile* tile3c;
            Tile* tile40;
            Tile* tile44;
            Tile* tile48;
            Tile* tile4c;
            Tile* tile50;
            Tile* tile54;
            Tile* tile58;
            Tile* tile5c;
            Tile* tile60;
            Tile* tile64;
        };
    };
    ComputerEntryList lbMenuItems; // src: XBOX_RETAIL_PDB +0x68 (old: entries)
    BSSimpleList<BGSTerminal*> TerminalStack; // src: XBOX_RETAIL_PDB +0x98 (old: notes)
    unsigned int uiResultDisplayTimeout; // src: XBOX_RETAIL_PDB +0xa0 (old: unka0)
    void* pCursorVis; // src: XBOX_RETAIL_PDB +0xa4 (old: unka4)
    BGSTerminal* pTerminal; // src: XBOX_RETAIL_PDB +0xa8 (old: terminal)
    TESObjectREFR* pTerminalRef; // src: XBOX_RETAIL_PDB +0xac (old: reference)
    int eMode; // src: XBOX_RETAIL_PDB +0xb0 (old: unkb0)
    StrMem strNoteText; // src: XBOX_RETAIL_PDB +0xb4 (old: text)
    union
    {
        const char* m_pText;
        const char* unkbc;
    };
    bool bTutorial; // src: XBOX_RETAIL_PDB +0xc0 (old: unkc0)
    bool bDisplayFlag; // src: XBOX_RETAIL_PDB +0xc1 (old: bRefreshed)
    unsigned char unkC2[2];
    BSSoundHandle Sounds[3]; // src: XBOX_RETAIL_PDB +0xc4 (old: sounds)
    TextAnimator* pATManager; // src: XBOX_RETAIL_PDB +0xe8 (old: manager)
    void (*NoteActivationFn)(); // src: XBOX_RETAIL_PDB +0xec (old: callbackec)
    void (*callbackf0)();
    void (*callbackf4)();
    int unkf8;

    void CompanionWheelMenu_AttachTileByID(int aiID, Tile* apTile);
    int __thiscall GetMenuId();
    bool __thiscall HasAllTiles(int*);
    bool HandleButtonInput(int, float);
    void UpdateBlink();
    void FinishIntro();
    void DisplayIntro();
    void DisplayNoteText(TextSource*);
    void DisplayNoteText(int);
    void PlayNoteSound(BGSNote*);
    void DoClick(int, Tile*);
    void DoIdle_00758470();
    void DisplayTerminal(int);
    void DisplayTerminal(bool);
    void DisplayPreviousTerminal();
};
