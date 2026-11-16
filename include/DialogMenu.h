#pragma once

#include "Menu.h"
#include "ListBox_int_.h"
#include "BSSoundHandle.h"
#include "DialogMenuPoint2.h"

class Tile;
class MenuTopic;
class TopicMenuController;
class MobileObject;
class TESTopic;
class TESSound;
class ImageSpaceModifierInstanceDOF;

// pdb: class DialogMenu, size 0x13c, bases: Menu, 22 members
class DialogMenu : public Menu
{
public:
    enum DialogState
    {
        eCameraZoomIn,
        eLoadSpeech,
        eSpeechIdle,
        ePlaySpeech,
        eCameraZoomOut,
        eServiceFadeOut
    };

    enum GoodbyeState
    {
        eInDialogue,
        eNaturalGoodbye,
        eForceGoodbye,
        eInvalidChoiceList
    };

    DialogMenu();
    void* ScalarDeletingDestructor(unsigned int);
    virtual ~DialogMenu();
    virtual void AssignTileByID(int id, Tile* tile);
    virtual void HandleSelection(int, Tile*);
    virtual void UpdateDialog();
    virtual int GetClass();
    virtual bool HandleMenuInput(int aiButton, float afValue);

    DialogState eDialogState; // src: XBOX_RETAIL_PDB +0x28 (old: m_eDialogState)
    GoodbyeState eGoodbyeState; // src: XBOX_RETAIL_PDB +0x2c (old: m_eGoodbyeState)
    Tile* pTiles[4]; // src: XBOX_RETAIL_PDB +0x30 (old: m_pTiles)
    ListBox_int_ lbResponseList; // src: XBOX_RETAIL_PDB +0x40 (old: m_kResponseListBox)
    TopicMenuController* pTopicManager; // src: XBOX_RETAIL_PDB +0x70 (old: pDialogueItem)
    BSSoundHandle hSpeechFile; // src: XBOX_RETAIL_PDB +0x74 (old: m_kActorProcessResult)
    MobileObject* pSpeaker; // src: XBOX_RETAIL_PDB +0x80 (old: m_pDialogueSpeaker)
    char strCurrTopicID[128]; // src: XBOX_RETAIL_PDB +0x84 (old: m_cCurrentTopicLabel)
    bool bResponseShown; // src: XBOX_RETAIL_PDB +0x104 (old: m_bResponseStarted)
    unsigned char layoutPadding105[3];
    float fElapsedSecs; // src: XBOX_RETAIL_PDB +0x108 (old: m_fCameraTransitionTime)
    unsigned int uiIgnoreInputStartTime; // src: XBOX_RETAIL_PDB +0x10c (old: m_uiDialogMenuFlags)
    DialogMenuPoint2 DOFDepth; // src: XBOX_RETAIL_PDB +0x110 (old: m_kDialogMenuPoint1)
    DialogMenuPoint2 DOFRange; // src: XBOX_RETAIL_PDB +0x118 (old: m_kDialogMenuPoint2)
    DialogMenuPoint2 DOFStrength; // src: XBOX_RETAIL_PDB +0x120 (old: m_kDialogMenuPoint3)
    float fPercentZoomed; // src: XBOX_RETAIL_PDB +0x128 (old: m_fCameraTransitionAlpha)
    ImageSpaceModifierInstanceDOF* pDepthOfFieldInstance; // src: XBOX_RETAIL_PDB +0x12c (old: m_pDialogueDepthOfFieldModifier)
    bool bIsIn3rdPerson; // src: XBOX_RETAIL_PDB +0x130 (old: m_bPauseRequested)
    bool bPaused;
    unsigned char layoutPadding132[2];
    DialogState ePausedState; // src: XBOX_RETAIL_PDB +0x134 (old: m_eStateBeforePause)
    bool bInServiceMenu; // src: XBOX_RETAIL_PDB +0x138 (old: m_bServiceDialogue)
    bool bShowingTutorial; // src: XBOX_RETAIL_PDB +0x139 (old: m_bSuppressDialogueText)
    bool bDoServiceLoad; // src: XBOX_RETAIL_PDB +0x13a (old: m_bServiceMenuRequested)
    unsigned char layoutPadding13B[1];

    void SetActive(bool abActive);
    void RefreshTopics();
    void SetCurrentTopic(MenuTopic* topic);
    DialogState BeginDialogueResponse(bool);
    void LoadTopicsList();
    bool AreTilesInitialized();
    bool DialogMenu_IsWellFormedMenu();
    TESSound* GetCastSound();

    static int ms_iDialogMenuValue;
    static void DialogMenu_Close();
    static Tile* DialogMenu_Create(MobileObject*, TESTopic*, MobileObject*);
    static void* DialogMenu_Create(void*, void*, void*);
};
