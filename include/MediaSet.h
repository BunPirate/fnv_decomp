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

    unsigned int uiMinLayerUpdate; // src: XBOX_RETAIL_PDB +0x24 (old: m_uiMediaValue1)
    unsigned int uiSeekTime; // src: XBOX_RETAIL_PDB +0x28 (old: m_uiMediaValue2)
    unsigned int uiLoopUpdate; // src: XBOX_RETAIL_PDB +0x2c (old: m_uiMediaValue3)
    bool bStarted; // src: XBOX_RETAIL_PDB +0x30 (old: bEffectFlag)
    bool bInCombat; // src: XBOX_RETAIL_PDB +0x31 (old: m_bActorStateFlag)
    bool bInTension; // src: XBOX_RETAIL_PDB +0x32 (old: m_bCountWasNonzero)
    bool bIsDay; // src: XBOX_RETAIL_PDB +0x33 (old: m_bConditionWasTrue)
    char cCurrentLayer; // src: XBOX_RETAIL_PDB +0x34 (old: m_cMediaState)
    TESFullName MediaSetName; // src: XBOX_RETAIL_PDB +0x38 (old: m_kFullName)
    MEDIASETTYPE Type;
    MediaSetEntry pMLOne; // src: XBOX_RETAIL_PDB +0x48 (old: m_kMediaSetEntry1)
    MediaSetEntry pMLTwo; // src: XBOX_RETAIL_PDB +0x58 (old: m_kMediaSetEntry2)
    MediaSetEntry pMLThree; // src: XBOX_RETAIL_PDB +0x68 (old: m_kMediaSetEntry3)
    MediaSetEntry pMLFour; // src: XBOX_RETAIL_PDB +0x78 (old: m_kMediaSetEntry4)
    MediaSetEntry pMLFive; // src: XBOX_RETAIL_PDB +0x88 (old: m_kMediaSetEntry5)
    MediaSetEntry pMLSix; // src: XBOX_RETAIL_PDB +0x98 (old: m_kMediaSetEntry6)
    char cEnableFlags; // src: XBOX_RETAIL_PDB +0xa8 (old: m_cMediaFlag)
    float fOne; // src: XBOX_RETAIL_PDB +0xac (old: m_fMediaParameter1)
    float fTwo; // src: XBOX_RETAIL_PDB +0xb0 (old: fSkillValueBonus)
    float fThree; // src: XBOX_RETAIL_PDB +0xb4 (old: m_fMediaParameter3)
    float fFour; // src: XBOX_RETAIL_PDB +0xb8 (old: m_fMediaValue)
    TESSound* pSoundOne; // src: XBOX_RETAIL_PDB +0xbc (old: m_pSound1)
    TESSound* pSoundTwo; // src: XBOX_RETAIL_PDB +0xc0 (old: m_pSound2)

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
