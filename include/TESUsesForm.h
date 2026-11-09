#pragma once

#include "BaseFormComponent.h"

class TESForm;

// pdb: class TESUsesForm, size 0x8, bases: BaseFormComponent, 1 members
class TESUsesForm : public BaseFormComponent
{
public:
    ~TESUsesForm();

    void InitializeComponent();
    void ClearComponent();
    void Save();
    void BaseFormRecord(BaseFormComponent* component);
    bool IsEqualToBase(BaseFormComponent* component);
    static int GetFormUses(TESForm* form);
    int GetFormUses();
    void SetFormUses(int uses);

    unsigned char iUses;
    char _pad_5[3];
};
