#pragma once

#include "BaseFormComponent.h"

class TESForm;

// pdb: class BGSClipRoundsForm, size 0x8, bases: BaseFormComponent, 1 members
class BGSClipRoundsForm : public BaseFormComponent
{
public:
    BGSClipRoundsForm();
    ~BGSClipRoundsForm();
    BGSClipRoundsForm& operator=(const BGSClipRoundsForm&);

    virtual void Init();
    virtual void Free();
    virtual void CopyFromBase(BaseFormComponent* apCopyFC);
    virtual bool CompareWithBase(BaseFormComponent* apCompareFC);

    void InitializeComponent();
    void ClearComponent();
    void Save();
    void BaseFormRecord(BaseFormComponent* component);
    bool IsEqualToBase(BaseFormComponent* component);
    static int GetClipRounds(TESForm* form);
    int GetClipRounds();
    void SetFormClipRounds(int rounds);

    unsigned char cClipRounds;
    unsigned char layoutPadding5[3];
};
