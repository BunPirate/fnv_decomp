#pragma once

#include "BSSimpleArray.h"

#include "FootIK_DATA__FootIKSystem_DATA.h"
#include "GrabIK_DATA.h"

class FootIK_DATA__FootIK_Leg_DATA;

// pdb: structure FootIK_DATA, size 0x40, 4 members
class FootIK_DATA
{
public:
    FootIK_DATA();
    ~FootIK_DATA();

    bool bEnabled;
    unsigned char layoutPadding1[3];
    FootIK_DATA__FootIKSystem_DATA SystemData;
    BSSimpleArray<const char*, 1024> LegSystemsNameA;
    BSSimpleArray<FootIK_DATA__FootIK_Leg_DATA, 1024> LegSystemsA;
};
