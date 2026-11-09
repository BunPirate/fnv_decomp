#pragma once

#include "MobileObjectTaskletData.h"

class HighProcess;

// pdb: class MovementTaskData, size 0x3c, bases: MobileObjectTaskletData, 1 members
class MovementTaskData : public MobileObjectTaskletData
{
public:
    MovementTaskData(BSTFreeList<MobileObjectTaskletContext>* apList);
    virtual ~MovementTaskData();
    virtual void SetMobileObjectCount(unsigned int auiObjectCount);
    virtual void ProcessMobileObject(MobileObject* apObject);
    virtual void SetThreadNumber(unsigned int auiThreadNumber);

    unsigned int iUpdated;

    void UpdateMovementTask(HighProcess* apMob);
};
