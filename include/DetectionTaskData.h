#pragma once

#include "MobileObjectTaskletData.h"

// pdb: class DetectionTaskData, size 0x40, bases: MobileObjectTaskletData, 2 members
class DetectionTaskData : public MobileObjectTaskletData
{
public:
    float fNumber;
    int iUpdated;
};
