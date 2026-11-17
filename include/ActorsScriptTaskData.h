#pragma once

#include "MobileObjectTaskletData.h"

// pdb: class ActorsScriptTaskData, size 0x40, bases: MobileObjectTaskletData, 2 members
class ActorsScriptTaskData : public MobileObjectTaskletData
{
public:
    ActorsScriptTaskData(BSTFreeList<MobileObjectTaskletContext>* apList);

    BSSimpleList<MobileObject*>* pprevmoblist; // src: XBOX_RETAIL_PDB +0x38 (old: pPrevObjectList)
    unsigned int iUpdated; // src: XBOX_RETAIL_PDB +0x3c (old: uiRunCount)
};
