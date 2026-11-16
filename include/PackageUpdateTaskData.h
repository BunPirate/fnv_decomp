#pragma once

#include "MobileObjectTaskletData.h"

// pdb: class PackageUpdateTaskData, size 0x44, bases: MobileObjectTaskletData, 3 members
class PackageUpdateTaskData : public MobileObjectTaskletData
{
public:
    PackageUpdateTaskData(BSTFreeList<MobileObjectTaskletContext>* apList);

    BSSimpleList<MobileObject*>* pprevmoblist; // src: XBOX_RETAIL_PDB +0x38 (old: pPrevObjectList)
    unsigned int iUpdated; // src: XBOX_RETAIL_PDB +0x3c (old: uiUpdatedCount)
    unsigned int iNotUpdated; // src: XBOX_RETAIL_PDB +0x40 (old: uiSkippedCount)

    void RunPackageUpdateTask(unsigned int aiThread);
};
