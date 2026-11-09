#pragma once

#include "BaseFormComponent.h"

class TESForm;

// pdb: class TESQualityForm, size 0x8, bases: BaseFormComponent, 1 members
class TESQualityForm : public BaseFormComponent
{
public:
    ~TESQualityForm();

    void InitializeComponent();
    void ClearComponent();
    void Save();
    void BaseFormRecord(BaseFormComponent* component);
    bool IsEqualToBase(BaseFormComponent* component);
    static unsigned char GetFormQuality(TESForm* form);
    unsigned char GetFormQuality();
    void SetFormQuality(unsigned char quality);

    unsigned char cQuality;
    char _pad_5[3];
};
