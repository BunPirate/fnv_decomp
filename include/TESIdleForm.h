#pragma once

#include "TESForm.h"
#include "TESModelAnim.h"
#include "PerkEntryConditionSet.h"

class NiFormArray;
class TESObjectREFR;
class IdleReplayDelayEntry;

class IdleAnimationData
{
public:
    unsigned char m_ucAnimationGroupSection;
    unsigned char m_ucLoopingMin;
    unsigned char m_ucLoopingMax;
    unsigned char unk03;
    unsigned short m_usReplayDelay;
    unsigned char m_ucIdleFlags;
    unsigned char unk07;

    void SwapEndian();
};

// pdb: class TESIdleForm, size 0x54, bases: TESForm, TESModelAnim, 6 members
class TESIdleForm : public TESForm, public TESModelAnim
{
public:
    PerkEntryConditionSet Conditions;
    IdleAnimationData data;
    NiFormArray* pChildIdles; // src: XBOX_RETAIL_PDB +0x40 (old: m_pParentPath)
    TESIdleForm* pParentIdle; // src: XBOX_RETAIL_PDB +0x44 (old: m_pParentIdleForm)
    TESIdleForm* pPrevIdle; // src: XBOX_RETAIL_PDB +0x48 (old: m_pIdleForm)
    unsigned char cFormEditorID[8]; // src: XBOX_RETAIL_PDB +0x4c (old: unk4C)

    TESIdleForm();
    virtual ~TESIdleForm();
    virtual void ClearData();
    virtual void InitItem();
    virtual char* GetName() const;

    const char* GetEditorID();
    void ResetFormData();
    void UnregisterIdleForm();
    bool IsFlag40Set();
    bool TESIdleForm_GetAllowNoFile();
    NiFormArray* AssignParentPath();
    unsigned int GetChildCount();
    TESIdleForm* GetChildByIndex(unsigned int index);
    bool Load(TESFile* file);
    // TESForm vtable slot 8 (vftable 0x1049d0c slot 8 = 0x5fe810)
    bool LoadForm(TESFile* apFile);
    bool InitParents();
    void FixNextIdles(NiFormArray* apArray);
    bool CheckIdleFile();
    TESIdleForm* FindIdleFormForObject(
        TESObjectREFR* actionRef, TESObjectREFR* targetRef,
        BSSimpleList<IdleReplayDelayEntry*>* replayDelays);
    bool IsValidForReferences(
        TESObjectREFR* actionRef, TESObjectREFR* targetRef, bool recurseUp);
    int GetFlagsMasked();
    void* FUN_0067f390();
    unsigned int GetHavokWorldObjectCountInSceneGraph_0084e3a0();
    unsigned char GetRandomValue();
    unsigned short GetField3C();
};
