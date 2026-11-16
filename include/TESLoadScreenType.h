#pragma once

#include "TESForm.h"

// pdb: class TESLoadScreenType, size 0x70, bases: TESForm, 1 members
class TESLoadScreenType : public TESForm
{
public:
    TESLoadScreenType();
    virtual ~TESLoadScreenType();
    virtual bool LoadForm(TESFile* apFile);
    virtual void SaveForm(void);
    virtual void CopyFrom(const TESForm* form);
    virtual bool Compare(TESForm* form);

    bool Load(TESFile* apFile);

    unsigned char data[0x58]; // src: XBOX_RETAIL_PDB +0x18 (old: formData)
};
