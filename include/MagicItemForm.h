#pragma once

#include "TESForm.h"
#include "MagicItem.h"

// pdb: class MagicItemForm, size 0x34, bases: TESForm, MagicItem, 0 members
class MagicItemForm : public TESForm, public MagicItem
{
public:
    MagicItemForm();
    virtual ~MagicItemForm();

    virtual bool LoadForm(TESFile* file);
    virtual void SaveForm();
    virtual void InitItem();
    virtual void SetAltered(bool abValue);
    virtual void CopyFrom(const TESForm* apCopy);
    virtual bool Compare(TESForm* form);
    virtual void Endian();

    bool Load(TESFile* file);
};
