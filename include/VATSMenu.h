#pragma once

#include "Menu.h"
#include "ListBox_int_.h"

class Tile;
class TESObjectREFR;
class BooleanFloatQuery;
struct ActorX;
struct ActorM;
struct ChanceX;
struct TargetX;
struct LimbM;
struct LimbListM;
struct TargetListM;


// pdb: class VATSMenu, size 0x144, bases: Menu, 26 members
class VATSMenu : public Menu
{
public:
    class ActionList : public ListBox_int_
    {
    public:
        ActionList();
        ~ActionList();
    };

    class TargetCommand
    {
    public:
        int eAction;
        bool bSuccess;
        bool m_kFieldAfterWeaponFlags;
        bool m_bFirstActionFlag;
        bool m_bSecondActionFlag;
        unsigned char m_ucFirstActionCode;
        unsigned char m_ucSecondActionCode;
        char unk0A[2];
        TESObjectREFR* pTarget;
        int m_iActionValue;
        BooleanFloatQuery* m_pActionObject;
        float m_fArmorDamage;
        float m_fHealthDamage;
        float m_fOverrideActionPoints;
        bool m_bFinalActionFlag;
        char unk25[3];

        TargetCommand();
        ~TargetCommand();
        void VATS_COMMAND_Initialize();
    };

    virtual ~VATSMenu();
    virtual void AssignTileByID(int, Tile*);
    virtual void HandleSelection(int, Tile*);
    virtual void HandleMouseover(unsigned int, Tile*);
    virtual void HandleMouseoverTileAlt(unsigned int, Tile*);
    virtual void HandleActiveMenuClick(unsigned int, Tile*);
    virtual void HandleMousewheel(unsigned int, Tile*);
    virtual void UpdateDialog();
    virtual bool HandleKeyboardInput(unsigned int);

    union
    {
        char layoutExtension_pad28[128];
        Tile* m_pTiles[32];
    };
    void* pActive; // src: XBOX_RETAIL_PDB +0xa8 (old: m_pAdditionalHudTile)
    bool bDebounceMenuButton; // src: XBOX_RETAIL_PDB +0xac (old: m_bStateFlag8)
    char layoutExtension_padad[3];
    ActionList lbActions; // src: XBOX_RETAIL_PDB +0xb0 (old: m_acMenuText)
    float fActionPoints; // src: XBOX_RETAIL_PDB +0xe0 (old: m_fOverrideActionPoints)
    float fActionPointsBase; // src: XBOX_RETAIL_PDB +0xe4 (old: m_fValue1)
    float fClipAmmo; // src: XBOX_RETAIL_PDB +0xe8 (old: m_fValue2)
    float fTotalAmmo; // src: XBOX_RETAIL_PDB +0xec (old: m_fValue3)
    float fQueuedClipAmmo; // src: XBOX_RETAIL_PDB +0xf0 (old: m_fValue4)
    float fQueuedTotalAmmo; // src: XBOX_RETAIL_PDB +0xf4 (old: m_fValue5)
    bool bHeadingReached; // src: XBOX_RETAIL_PDB +0xf8 (old: m_bFirstFlag)
    bool bMetersShown; // src: XBOX_RETAIL_PDB +0xf9 (old: m_bStateFlag1)
    bool bTargetsLit; // src: XBOX_RETAIL_PDB +0xfa (old: m_bStateFlag2)
    bool bClosing; // src: XBOX_RETAIL_PDB +0xfb (old: m_bStateFlag3)
    float fProbableEnemyDamage; // src: XBOX_RETAIL_PDB +0xfc (old: m_fHitChance)
    void* pCurrentLimb; // src: XBOX_RETAIL_PDB +0x100 (old: m_pTargetChance)
    bool bConcentratedFirePerk; // src: XBOX_RETAIL_PDB +0x104 (old: m_bStateFlag4)
    char layoutExtension_pad105[3];
    void* pLastLimb; // src: XBOX_RETAIL_PDB +0x108 (old: m_pSelectedChance)
    bool bStickReset; // src: XBOX_RETAIL_PDB +0x10c (old: m_bStateFlag5)
    bool bTargetStickReset; // src: XBOX_RETAIL_PDB +0x10d (old: m_bStateFlag9)
    bool bMouseOverButton; // src: XBOX_RETAIL_PDB +0x10e (old: m_bAdditionalStateFlag)
    bool bSelectLeftHeld; // src: XBOX_RETAIL_PDB +0x10f (old: m_bStateFlag10)
    bool bSelectRightHeld; // src: XBOX_RETAIL_PDB +0x110 (old: m_bStateFlag6)
    char layoutExtension_pad111[3];
    unsigned int uiSelectTimer; // src: XBOX_RETAIL_PDB +0x114 (old: m_uiTargetCount)
    bool bDataInTemporaryVATSCommand; // src: XBOX_RETAIL_PDB +0x118 (old: m_bStateFlag7)
    char layoutExtension_pad119[3];
    TargetCommand pTemporaryVATSCommand; // src: XBOX_RETAIL_PDB +0x11c (old: m_acTargetText)

    VATSMenu();
    void AttachTileByID(int aiID, Tile* apTile);
    int GetSelectedTargetIndex();
    unsigned int Create();
    unsigned int GetFilteredCount();
    unsigned int GetUnfilteredCount();
    int ListBox_BGSQuestObjective_NumUnfiltered();
    int ListBox_enum_MiscStatManager_MiscStatID_NumUnfiltered();

    void HandleClick(int aiID, int aiArg);
    bool HandleKey(int aiKey);
    void DoEnter_007ef7b0(int aiID, int aiArg);
    void DoLeave_007ef830(int aiID, int aiOther);
    void DoWheelMove_007ef760(int aiID, Tile* apTarget);
    void DoStillDown_007ef8b0(int aiID, Tile* apTarget);

    BSSimpleList<TargetX*>* FindListEntryForTarget(ActorX* apTarget);
    TargetListM* FindListEntryForTarget(ActorM* apTarget);
    void BuildMetersForTarget(BSSimpleList<TargetX*>* apTarget);
    BSSimpleList<ChanceX*>* FindEntryForRef();
    LimbListM* FindListEntryByValue(int aiLimb);
    void UpdateLimbHighlight();
    void UpdateQueuedActionList(TargetCommand* apCommand, bool abForcedReload, bool bSpecialAttack);
    float CalculateProbableEnemyHealth();
    void SetMeterChance();
    bool UpdateVatsTargeting();
    void VATSMenu_SetTargetLimb();
    bool UpdateAmmo();
    bool VATSMenu_PickNewTarget();
    int VATSMenu_GetActorValueFromBodyPart(int aeBodyPart);
    int GetConsecutiveMatchCount();
    void UpdateLimbTiles();
    float CalculateVATSChance(LimbListM* apTarget);
    bool VATSMenu_LimbOnScreen(LimbM* apLimb);
    void Update();
};
