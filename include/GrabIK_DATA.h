#pragma once

#include "BSSimpleArray.h"

class GrabIK_DATA__GrabIK_Arm_DATA;

// pdb: structure GrabIK_DATA, size 0x24, 3 members
class GrabIK_DATA
{
public:
    GrabIK_DATA();
    ~GrabIK_DATA();

    bool bEnabled;
    unsigned char layoutPadding1[3];
    BSSimpleArray<const char*, 1024> ArmSystemsNameA;
    BSSimpleArray<GrabIK_DATA__GrabIK_Arm_DATA, 1024> ArmSystemsA;
};
