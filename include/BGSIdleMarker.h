#pragma once

#include "TESBoundObject.h"
#include "BGSIdleCollection.h"

// pdb: class BGSIdleMarker, size 0x40, bases: TESBoundObject, BGSIdleCollection, 0 members
class BGSIdleMarker : public TESBoundObject, public BGSIdleCollection
{
public:
    BGSIdleMarker();
    virtual ~BGSIdleMarker();

    virtual void InitItem(void);
    bool Load(TESFile* apFile);
};
