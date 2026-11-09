#pragma once

#include "MobileObjectTaskletData.h"

// pdb: class ActorsScriptTaskData, size 0x40, bases: MobileObjectTaskletData, 2 members
class ActorsScriptTaskData : public MobileObjectTaskletData
{
public:
    ActorsScriptTaskData(BSTFreeList<MobileObjectTaskletContext>* apList);

    BSSimpleList<MobileObject*>* pprevmoblist;
    unsigned int iUpdated;
};
