#pragma once

#include "BSSimpleArray.h"
#include "FootIK_DATA.h"

class LookIK_DATA__LookIK_Head_DATA;

// pdb: structure LookIK_DATA, size 0x24, 3 members
class LookIK_DATA
{
public:
    LookIK_DATA();
    ~LookIK_DATA();

    bool bEnabled;
    unsigned char layoutPadding1[3];
    BSSimpleArray<const char*, 1024> HeadSystemsNameA; // src: XBOX_RETAIL_PDB +0x4 (old: m_kLookNames)
    BSSimpleArray<LookIK_DATA__LookIK_Head_DATA, 1024> HeadSystemsA; // src: XBOX_RETAIL_PDB +0x14 (old: m_kHeadData)
};
