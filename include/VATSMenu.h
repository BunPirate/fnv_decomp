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
    void* pActive;
    bool bDebounceMenuButton;
    char layoutExtension_padad[3];
    ActionList lbActions;
    float fActionPoints;
    float fActionPointsBase;
    float fClipAmmo;
    float fTotalAmmo;
    float fQueuedClipAmmo;
    float fQueuedTotalAmmo;
    bool bHeadingReached;
    bool bMetersShown;
    bool bTargetsLit;
    bool bClosing;
    float fProbableEnemyDamage;
    void* pCurrentLimb;
    bool bConcentratedFirePerk;
    char layoutExtension_pad105[3];
    void* pLastLimb;
    bool bStickReset;
    bool bTargetStickReset;
    bool bMouseOverButton;
    bool bSelectLeftHeld;
    bool bSelectRightHeld;
    char layoutExtension_pad111[3];
    unsigned int uiSelectTimer;
    bool bDataInTemporaryVATSCommand;
    char layoutExtension_pad119[3];
    TargetCommand pTemporaryVATSCommand;

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
    void VATSMenu_BuildMetersForTarget(BSSimpleList<TargetX*>* apTarget);
    BSSimpleList<ChanceX*>* FindEntryForRef();
    LimbListM* FindListEntryByValue(int aiLimb);
    void UpdateLimbHighlight();
    void VATSMenu_UpdateQueuedActionList(TargetCommand* apCommand, bool abForcedReload, bool bSpecialAttack);
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
