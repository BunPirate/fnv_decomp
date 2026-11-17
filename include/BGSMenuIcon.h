#pragma once

#include "TESForm.h"
#include "TESIcon.h"

// pdb: class BGSMenuIcon, size 0x24, bases: TESForm, TESIcon, 0 members
class BGSMenuIcon : public TESForm, public TESIcon
{
public:
    BGSMenuIcon();
    virtual ~BGSMenuIcon();
    virtual void SaveForm(void);
    virtual void CopyFrom(const TESForm* apCopy);
    virtual bool Compare(TESForm* form);

    bool Load(TESFile* apFile);
    const char* __thiscall GetFullName(void);
    void SetFormID(unsigned int id, int flag);
    void SetEditorID(const char* name);
};
