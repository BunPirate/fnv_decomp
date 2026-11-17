#pragma once

#include "BaseFormComponent.h"

class TESForm;

// pdb: class TESAttackDamageForm, size 0x8, bases: BaseFormComponent, 1 members
class TESAttackDamageForm : public BaseFormComponent
{
public:
    TESAttackDamageForm();
    ~TESAttackDamageForm();
    TESAttackDamageForm& operator=(const TESAttackDamageForm&);

    virtual void Free();
    virtual unsigned short GetAttackDamage();

    void InitializeComponent();
    void ClearComponent();
    void BaseFormRecord(BaseFormComponent* component);
    bool IsEqualToBase(BaseFormComponent* apCompareFC);
    static unsigned short GetAttackDamage(TESForm* form);
    void SetAttackDamage(unsigned short damage);
    unsigned short GetDamage();
    int GetResult();

    unsigned short sAttackDamage; // src: XBOX_RETAIL_PDB +0x4 (old: m_usAttackDamage)
    unsigned char layoutPadding6[2];
};
