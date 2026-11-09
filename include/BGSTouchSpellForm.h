#pragma once

#include "BaseFormComponent.h"

class MagicItemForm;
class TESForm;

// pdb: class BGSTouchSpellForm, size 0xc, bases: BaseFormComponent, 2 members
class BGSTouchSpellForm : public BaseFormComponent
{
public:
    BGSTouchSpellForm();
    BGSTouchSpellForm& operator=(const BGSTouchSpellForm&);

    virtual void Init();
    virtual void Free();
    virtual void CopyFromBase(BaseFormComponent* component);
    virtual bool CompareWithBase(BaseFormComponent* component);

    void InitializeComponent();
    void ClearComponent();
    void Save();
    void InitItem(TESForm* apOwner);
    void BaseFormRecord(BaseFormComponent* component);
    bool IsEqualToBase(BaseFormComponent* component);
    void Initialize(unsigned int value);
    void FUN_00483170(unsigned short value);
    static MagicItemForm* GetFormTouchSpell(TESForm* form);
    MagicItemForm* GetFormTouchSpell();
    void SetFormTouchSpell(MagicItemForm* magicItem);
    static unsigned short GetFormTouchSpellAnimation(TESForm* form);
    unsigned short GetFormTouchSpellAnimation();
    void SetFormTouchSpellAnimation(unsigned short animation);

    MagicItemForm* pFormTouchSpell;
    unsigned short iTouchSpellAnimation;
    unsigned char layoutPaddingA[2];
};
