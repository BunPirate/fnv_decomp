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
    bool bNewGameData;
    unsigned short layoutPadding6;
    GAMEDATA_STATUS eGameDataStatus_;
    char cGameDataDir[1055];
    char cContentInfoDir[1055];
    unsigned short layoutPadding84A;
    int iFreeSpaceKB_;
};
