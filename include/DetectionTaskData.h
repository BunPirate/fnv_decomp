#pragma once

#include "MobileObjectTaskletData.h"

// pdb: class DetectionTaskData, size 0x40, bases: MobileObjectTaskletData, 2 members
class DetectionTaskData : public MobileObjectTaskletData
{
public:
    float fNumber; // src: XBOX_RETAIL_PDB +0x38 (old: m_fDetectionValue)
    int iUpdated; // src: XBOX_RETAIL_PDB +0x3c (old: m_iDetectionState)
};
