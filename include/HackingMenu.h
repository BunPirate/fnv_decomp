#pragma once

#include "Menu.h"
#include "BSSoundHandle.h"

class HackEntry;
class Entry28;
class ScriptObj;

// pdb: class HackingMenu, size 0x1dc, bases: Menu, 28 members
class HackingMenu : public Menu
{
public:
    class AnimState
    {
    public:
        int unk00;
        int unk04;
        int unk08;
        int unk0c;
        int unk10;
        int unk14;
        int unk18;
        int unk1c;
        int unk20;
        int unk24;
        int unk28;

        AnimState();
        ~AnimState();
        void AssignString(int);
        void AnimatingText_Update();
    };

    class ListState
    {
    public:
        int a;
        int b;
        int c;

        ListState();
        ~ListState();
        bool NiTListBase_DFALL_NiTListItem_BSAnimGroupSequence_const_BSAnimGroupSequence_const_IsEmpty();
        ScriptObj* RemoveHead();
        void FUN_004ed900();
    };

    class PairState
    {
    public:
        int a;
        int b;

        PairState();
        ~PairState();
        void HackingMenu_WordList_Flush();
    };

    virtual ~HackingMenu();
    virtual void AssignTileByID(int, Tile*);
    virtual void HandleSelection(int, Tile*);
    virtual void HandleMouseoverTileAlt(unsigned int, Tile*);
    virtual void UpdateDialog();
    virtual int GetClass();
    virtual bool HandleMenuInput(int, float);
    virtual bool HandleControllerInput(int, Tile*);

    union
    {
        unsigned char layoutExtension[0xB8];
        HackEntry* entries[46];
        struct
        {
            int unk028;
            int unk02c;
            int unk030;
            int unk034;
            int unk038;
            int unk03c;
            int unk040;
            int unk044;
            int unk048;
            int unk04c;
            int unk050;
            int unk054;
            int unk058;
            int unk05c;
            int unk060;
            int unk064;
            int unk068;
            int unk06c;
            int unk070;
            int unk074;
            int unk078;
            int unk07c;
            int unk080;
            int unk084;
            int unk088;
            int unk08c;
            int unk090;
            int unk094;
            int unk098;
            int unk09c;
            int unk0a0;
            int unk0a4;
            int unk0a8;
            int unk0ac;
            int unk0b0;
            int unk0b4;
            int unk0b8;
            int unk0bc;
            int unk0c0;
            int unk0c4;
            int unk0c8;
            int unk0cc;
            int unk0d0;
            int unk0d4;
            int unk0d8;
            int unk0dc;
        };
    };
    AnimState xEntryText; // src: XBOX_RETAIL_PDB +0xe0 (old: anim)
    union
    {
        Tile* m_pTiles[8];
        struct
        {
            int unk10c;
            int unk110;
            int unk114;
            int unk118;
            int unk11c;
            int unk120;
            int unk124;
            int unk128;
        };
    };
    BSSoundHandle Sounds[5]; // src: XBOX_RETAIL_PDB +0x12c (old: sounds)
    ListState xLogTiles; // src: XBOX_RETAIL_PDB +0x168 (old: list168)
    ListState xGuessTiles; // src: XBOX_RETAIL_PDB +0x174 (old: list174)
    PairState wordList; // src: XBOX_RETAIL_PDB +0x180 (old: pair180)
    ListState xUsedBonuses; // src: XBOX_RETAIL_PDB +0x188 (old: list188)
    int pTerminal; // src: XBOX_RETAIL_PDB +0x194 (old: unk194)
    int pTerminalRef; // src: XBOX_RETAIL_PDB +0x198 (old: unk198)
    int pPassword; // src: XBOX_RETAIL_PDB +0x19c (old: unk19c)
    int iNumGuesses; // src: XBOX_RETAIL_PDB +0x1a0 (old: unk1a0)
    int iTotGuesses; // src: XBOX_RETAIL_PDB +0x1a4 (old: unk1a4)
    int iWordsHave; // src: XBOX_RETAIL_PDB +0x1a8 (old: unk1a8)
    int iWordLength; // src: XBOX_RETAIL_PDB +0x1ac (old: unk1ac)
    int iBufferPos; // src: XBOX_RETAIL_PDB +0x1b0 (old: unk1b0)
    int iYStart; // src: XBOX_RETAIL_PDB +0x1b4 (old: unk1b4)
    int iYInterval; // src: XBOX_RETAIL_PDB +0x1b8 (old: unk1b8)
    int iLastOffset; // src: XBOX_RETAIL_PDB +0x1bc (old: unk1bc)
    int pLastTarget; // src: XBOX_RETAIL_PDB +0x1c0 (old: unk1c0)
    int eStage; // src: XBOX_RETAIL_PDB +0x1c4 (old: m_iStage)
    Tile* pOverTile; // src: XBOX_RETAIL_PDB +0x1c8 (old: m_pkCursorTile)
    int iCursorX; // src: XBOX_RETAIL_PDB +0x1cc (old: m_iCursorIndex)
    int dwAccessTime; // src: XBOX_RETAIL_PDB +0x1d0 (old: unk1d0)
    int pCursorVis; // src: XBOX_RETAIL_PDB +0x1d4 (old: unk1d4)
    bool bSuppressEntry; // src: XBOX_RETAIL_PDB +0x1d8 (old: m_bBlink)
    unsigned char bUsedReset[3]; // src: XBOX_RETAIL_PDB +0x1d9 (old: unk1d9)

    HackingMenu();
    void* Destroy(unsigned int flags);
    void ClearTilePayloadPair();
    void SetTile(int aiID, Tile* apTile);
    bool HasAllSlots(int*);
    int GetCharHit();
    Tile* FindTile(int aiIndex, int aiCol);
    bool HandleKey(int aiButton, int afValue);
    void HandleClick(int m_uiSoundID, int iUnk);
    int __thiscall GetClass_00765870();
    void DoLeave_00767ff0(int, void*);
    void __thiscall AccessTerminal();
    void __thiscall TransitionToComputersMenu();
    unsigned int __thiscall CommonPositions(const char*, const char*);
    void __thiscall Prepare(unsigned int);
    void __thiscall UpdateFade();
    void __thiscall FormatHexWord(unsigned short, char*);
    void __thiscall ScrollLog(unsigned int, const unsigned int*);
    void DoShutdown();
    void GetGarbageString(int, const char*);
    void __thiscall UpdateCursorPos();
    void MakeGuessBlock();
    void RemoveRandomWord();
    void MakePasswordFile();
    void DoIntro();
    void UpdateHighlight();
    void __thiscall ClearEntry();
    void __thiscall UpdateScrollingCursor(HackEntry*);
    void __thiscall UpdateScrollingCursor(Entry28*);
};
