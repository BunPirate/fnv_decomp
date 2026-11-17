#pragma once

#include "TESBoundObject.h"
#include "MagicItem.h"

// pdb: class MagicItemObject, size 0x4c, bases: TESBoundObject, MagicItem, 0 members
class MagicItemObject : public TESBoundObject, public MagicItem
{
public:
    MagicItemObject();
    virtual ~MagicItemObject();
    virtual void InitializeComponent();
    virtual void ClearData();
    virtual bool LoadForm(TESFile* file);
    virtual void InitItem();
    virtual void vfn_180();

    // Alternate names for inherited virtual slots.
    void ResetFormData();
    bool Load(TESFile* apFile);

    bool IsFormInitialized() const;
};
