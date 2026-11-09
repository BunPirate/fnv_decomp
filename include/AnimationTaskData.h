#pragma once

#include "MobileObjectTaskletData.h"

// pdb: class AnimationTaskData, size 0x38, bases: MobileObjectTaskletData, 0 members
class AnimationTaskData : public MobileObjectTaskletData
{
public:
    AnimationTaskData(BSTFreeList<MobileObjectTaskletContext>* apList);
    virtual void ProcessMobileObject(MobileObject* apMob);
};
