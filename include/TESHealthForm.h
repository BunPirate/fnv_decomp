#pragma once

#include "BaseFormComponent.h"

class TESForm;

// pdb: class TESHealthForm, size 0x8, bases: BaseFormComponent, 1 members
class TESHealthForm : public BaseFormComponent
{
public:
    unsigned int iHealth; // src: XBOX_RETAIL_PDB +0x4 (old: m_uiHealthValue)

    TESHealthForm();
    ~TESHealthForm();

    virtual unsigned int GetHealth();

    void InitializeComponent();
    void ClearComponent();
    void BaseFormRecord(BaseFormComponent* component);
    bool IsEqualToBase(BaseFormComponent* apCompareFC);
    void Save();
    unsigned int GetBaseHealth();
    static TESHealthForm* GetFormAsHealthForm(TESForm* form);
    static unsigned int GetBaseHealth(TESForm* form);
    void SetFormHealth(unsigned int health);
};
