#pragma once

#include "MobileObjectTaskletData.h"

// pdb: class PackageUpdateTaskData, size 0x44, bases: MobileObjectTaskletData, 3 members
class PackageUpdateTaskData : public MobileObjectTaskletData
{
public:
    PackageUpdateTaskData(BSTFreeList<MobileObjectTaskletContext>* apList);

    BSSimpleList<MobileObject*>* pprevmoblist;
    unsigned int iUpdated;
    unsigned int iNotUpdated;

    void RunPackageUpdateTask(unsigned int aiThread);
};
