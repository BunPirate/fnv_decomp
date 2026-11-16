#pragma once

#include "BaseFormComponent.h"

class TESForm;
class TESRace;

// pdb: class TESRaceForm, size 0x8, bases: BaseFormComponent, 1 members
class TESRaceForm : public BaseFormComponent
{
public:
    TESRaceForm();

    void InitializeComponent();
    void ClearComponent();
    void BaseFormRecord(BaseFormComponent* apCopyFC);
    bool IsEqualToBase(BaseFormComponent* component);
    void Save();
    void InitItem(TESForm* apOwner);
    void Initialize(unsigned int flags);
    static TESRace* GetFormRace(TESForm* apForm);
    TESRace* GetFormRace();
    TESRace* GetFormRace() const;
    static char* GetFormRaceEditorID(TESForm* form);
    char* GetFormRaceEditorID();
    void SetFormRace(TESRace* race);

    TESRace* m_pRace;
};
