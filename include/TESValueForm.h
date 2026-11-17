#pragma once

#include "BaseFormComponent.h"

class TESForm;
class TESObjectREFR;
class BGSSaveFormBuffer;
class BGSLoadFormBuffer;

// pdb: class TESValueForm, size 0x8, bases: BaseFormComponent, 1 members
struct TESValueForm : public BaseFormComponent
{
public:
    TESValueForm();
    ~TESValueForm();

    virtual void Init();
    virtual void Free();
    virtual void CopyFromBase(BaseFormComponent* component);
    virtual bool CompareWithBase(BaseFormComponent* component);
    virtual unsigned short GetSaveSize(unsigned int flags);
    virtual void SaveGame(unsigned int flags);
    virtual void LoadGame(unsigned int flags, unsigned int currentFlags);

    void InitializeComponent();
    void ClearComponent();
    void BaseFormRecord(BaseFormComponent* component);
    bool IsEqualToBase(BaseFormComponent* apCompareFC);
    void Save();
    static int GetValueFromForm(TESForm* form);
    unsigned int GetValueFromForm();
    TESObjectREFR* GetValueFromForm(TESForm* apNpc, bool abDetection);
    void SetFormValue(int value);
    void SetFormValue(unsigned int aiValue);
    void SaveGame(BGSSaveFormBuffer* buffer);
    void LoadGame(BGSLoadFormBuffer* buffer);

    unsigned int GetSaveSizeTES(unsigned int flags) const;
    void SaveGameTES(unsigned int flags);
    void LoadGameTES(unsigned int flags, unsigned int currentFlags);
    unsigned long GetSaveSize(unsigned long changedFlags);
    void Save(unsigned long changedFlags);
    void Load(unsigned long changedFlags);

    void CopyComponent(BaseFormComponent* apCopyFC);
    unsigned short GetFlaggedDataSize(unsigned int aiFlags);
    void SaveGame_0048e9e0(unsigned int flags);
    void LoadGame_0048ea10(unsigned int a, unsigned int b);
    void SaveGameBGS_0048ea40(BGSSaveFormBuffer* buffer);

    union
    {
        unsigned int iValue;
        unsigned int uiValue;
        unsigned long value;
    };
};
