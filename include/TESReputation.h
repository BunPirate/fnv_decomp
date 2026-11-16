#pragma once

#include "TESForm.h"
#include "TESFullName.h"
#include "TESIcon.h"
#include "BGSMessageIcon.h"
#include "ReputationLimitData.h"

enum ReputationType
{
    ReputationType_REPUTATION_NEGATIVE = 0,
    ReputationType_REPUTATION_POSITIVE = 1
};

// pdb: class TESReputation, size 0x50, bases: TESForm, TESFullName, TESIcon, BGSMessageIcon, 4 members
class TESReputation : public TESForm, public TESFullName, public TESIcon, public BGSMessageIcon
{
public:
    ReputationLimitData data;
    float fPositiveValue; // src: XBOX_RETAIL_PDB +0x44 (old: m_fFirstReputationValue)
    float fNegativeValue; // src: XBOX_RETAIL_PDB +0x48 (old: m_fSecondReputationValue)
    ReputationType rSound; // src: XBOX_RETAIL_PDB +0x4c (old: m_eReputationType)

    TESReputation();
    virtual ~TESReputation();
    virtual void InitializeComponent();
    virtual bool LoadForm(TESFile* file);

    void ResetFormData();
    bool Load(TESFile* apFile);
    void ReadTypedData(TESFile* apFile, void* apData, unsigned short asSize);
    float GetUnsignedIntegerPointer(ReputationType type);
    static unsigned int* __cdecl GetUnsignedIntegerPointer(unsigned int* value);
    int GetReputationRank(int type);
    const char* GetReputationName();
    const char* TESReputation_GetReputationDesc();
    const char* GetReputationTitle();
    const char* TESReputation_GetThresholdIcon();
    void DisplayReputationTitleChange();
    void ApplyReputationChange(int type, int amount);
    void SetReputation_00615580(int type, float value);
    void AddReputationValue(int RepType, float fValue);
    void RemoveReputationExact(int kind, float amount);
    void RemoveReputation(int kind, int amount);
    float TESReputation_GetPositiveRatio();
    float TESReputation_GetNegativeRatio();
    unsigned int GetSaveFormID();
};
