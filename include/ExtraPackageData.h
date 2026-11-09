#pragma once

#include "BSExtraData.h"
#include "ActorPackageData.h"

// pdb: class ExtraPackageData, size 0x10, bases: BSExtraData, 1 members
class ExtraPackageData : public BSExtraData
{
public:
    virtual ~ExtraPackageData();

    ExtraPackageData(ActorPackageData*);

    ActorPackageData* pActorPackageData;
};
