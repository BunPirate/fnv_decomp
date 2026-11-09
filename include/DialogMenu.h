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

    DialogState eDialogState;
    GoodbyeState eGoodbyeState;
    Tile* pTiles[4];
    ListBox_int_ lbResponseList;
    TopicMenuController* pTopicManager;
    BSSoundHandle hSpeechFile;
    MobileObject* pSpeaker;
    char strCurrTopicID[128];
    bool bResponseShown;
    unsigned char layoutPadding105[3];
    float fElapsedSecs;
    unsigned int uiIgnoreInputStartTime;
    DialogMenuPoint2 DOFDepth;
    DialogMenuPoint2 DOFRange;
    DialogMenuPoint2 DOFStrength;
    float fPercentZoomed;
    ImageSpaceModifierInstanceDOF* pDepthOfFieldInstance;
    bool bIsIn3rdPerson;
    bool bPaused;
    unsigned char layoutPadding132[2];
    DialogState ePausedState;
    bool bInServiceMenu;
    bool bShowingTutorial;
    bool bDoServiceLoad;
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
