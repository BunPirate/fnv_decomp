#pragma once

#include "TESPackageData.h"

class TESForm;
class TESTopic;
class TargetLocation;
struct PairOfBytes;

// pdb: class TESDialoguePackageData, size 0x20, bases: TESPackageData, 9 members
class TESDialoguePackageData : public TESPackageData
{
public:
    TESDialoguePackageData();
    TESDialoguePackageData(float initial, unsigned int object, PairOfBytes flags, float scale,
                           unsigned char enabled, unsigned int reference);

    virtual ~TESDialoguePackageData();
    virtual void Copy(TESPatrolPackageData* source);
    virtual bool vf02(TESPackageData* other);
    virtual void vf03();
    virtual void InitItem(TESForm* apOwner);
    virtual void SaveToBuffer(BGSSaveFormBuffer* buffer);
    virtual void vf06(BGSLoadFormBuffer* buffer);
    virtual void vf07(BGSLoadFormBuffer* buffer);

    float fFov; // src: XBOX_RETAIL_PDB +0x4 (old: m_fFirstFloat)
    TESTopic* ptopic; // src: XBOX_RETAIL_PDB +0x8 (old: pMenuTopicEntry)
    TargetLocation* pTargetLocation; // src: XBOX_RETAIL_PDB +0xc (old: m_pTargetLocation)
    bool bNOHeadtracking; // src: XBOX_RETAIL_PDB +0x10 (old: m_bFirstFlag)
    bool bDoNotControlTarget; // src: XBOX_RETAIL_PDB +0x11 (old: m_bFollowingFlag)
    float fDistanceStartTalking; // src: XBOX_RETAIL_PDB +0x14 (old: m_fFloatValue)
    bool bSayTo; // src: XBOX_RETAIL_PDB +0x18 (old: m_bThirdFlag)
    int eTriggerType; // src: XBOX_RETAIL_PDB +0x1c (old: m_iTrailingValue)

    TESDialoguePackageData* Construct(float initial, unsigned int object, PairOfBytes flags, float scale,
                                      unsigned char enabled, unsigned int reference);
    bool TESDialoguePackageData_Compare(void* object);
    void SaveTopicData();
    void SavePackageData(BGSSaveFormBuffer* apSaveGameBuffer);
    void TESDialoguePackageData_LoadGame(BGSLoadFormBuffer* apLoadGameBuffer);
    void TESDialoguePackageData_InitLoadGame(BGSLoadFormBuffer* apLoadGameBuffer);
};
