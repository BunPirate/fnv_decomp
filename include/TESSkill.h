#pragma once

#include "TESForm.h"
#include "TESDescription.h"
#include "TESTexture.h"

// pdb: class TESSkill, size 0x60, bases: TESForm, TESDescription, TESTexture, 2 members
class TESSkill : public TESForm, public TESDescription, public TESTexture
{
public:
    TESSkill();
    virtual ~TESSkill();

    virtual void InitializeComponent();
    virtual bool __thiscall LoadForm(TESFile* file);
    virtual void SaveForm(void);
    virtual void CopyFrom(const TESForm* apCopy);
    virtual bool Compare(TESForm* form);

    void* DeleteThis(unsigned int flags);
    void ClearSourceFiles();
    void ResetData();
    void InitializeData_00617e80();

    unsigned char data[0x34];
};
