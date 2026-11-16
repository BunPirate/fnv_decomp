#pragma once

#include "MobileObjectTaskletData.h"

class MobileObject;

// pdb: class ActorUpdateTaskData, size 0x3c, bases: MobileObjectTaskletData, 1 members
class ActorUpdateTaskData : public MobileObjectTaskletData
{
public:
    ActorUpdateTaskData(BSTFreeList<MobileObjectTaskletContext>* apList);

    unsigned int iUpdated; // src: XBOX_RETAIL_PDB +0x38 (old: uiRunCount)

    void UpdateActorTask(MobileObject* apMob);
};
