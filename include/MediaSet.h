#pragma once

#include "TESForm.h"
#include "TESFullName.h"
#include "MediaSetEntry.h"

class MediaLocationController;
class TESSound;

// pdb: class MediaSet, size 0xc4, bases: TESForm, TESFullName, 23 members
class MediaSet : public TESForm, public TESFullName
{
public:
    typedef ::MediaSetEntry MediaSetEntry;

    enum MEDIASETTYPE
    {
        BATTLE = 0,
        LAYER_LOCATION = 1,
        LAYER_DUNGEON = 2,
        INCIDENTAL = 3,
        SETTYPE_COUNT = 4
    };

    unsigned int uiMinLayerUpdate;
    unsigned int uiSeekTime;
    unsigned int uiLoopUpdate;
    bool bStarted;
    bool bInCombat;
    bool bInTension;
    bool bIsDay;
    char cCurrentLayer;
    TESFullName MediaSetName;
    MEDIASETTYPE Type;
    MediaSetEntry pMLOne;
    MediaSetEntry pMLTwo;
    MediaSetEntry pMLThree;
    MediaSetEntry pMLFour;
    MediaSetEntry pMLFive;
    MediaSetEntry pMLSix;
    char cEnableFlags;
    float fOne;
    float fTwo;
    float fThree;
    float fFour;
    TESSound* pSoundOne;
    TESSound* pSoundTwo;

    virtual void InitItem();
    virtual void ClearData();

    MediaSet();
    virtual ~MediaSet();
    void ResetFormData();
    void SaveMediaSet();
    bool UpdateLayerLocation(unsigned int, bool, MediaLocationController*);
    bool PointLocation(unsigned int, bool, MediaLocationController*);
    bool UpdateBattleState(bool, unsigned int, int);
    void UpdateIncidental(unsigned int);
    bool Update(unsigned int ticks, bool abInCombat, MediaLocationController* pController);
    void Reset();
    MEDIASETTYPE GetType();
};
