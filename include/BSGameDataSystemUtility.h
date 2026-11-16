#pragma once

#include "GAMEDATA_STATUS.h"

// pdb: class BSGameDataSystemUtility, size 0x850, 6 members
class BSGameDataSystemUtility
{
public:
    virtual void* vf00(unsigned int flags);
    virtual void vf04();
    virtual void Destroy();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();

    bool bIsActive;
    bool bNewGameData; // src: XBOX_RETAIL_PDB +0x5 (old: m_bGameDataFlag)
    unsigned short layoutPadding6;
    GAMEDATA_STATUS eGameDataStatus_; // src: XBOX_RETAIL_PDB +0x8 (old: m_eGameDataStatus)
    char cGameDataDir[1055]; // src: XBOX_RETAIL_PDB +0xc (old: m_acFirstLargeBuffer)
    char cContentInfoDir[1055]; // src: XBOX_RETAIL_PDB +0x42b (old: m_acSecondaryPath)
    unsigned short layoutPadding84A;
    int iFreeSpaceKB_; // src: XBOX_RETAIL_PDB +0x84c (old: m_iBufferValue)
};
