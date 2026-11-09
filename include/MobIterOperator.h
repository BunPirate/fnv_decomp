#pragma once

#include "BaseProcess.h"

class MobileObject;

// pdb: class MobIterOperator, size 0x8, 1 members
class MobIterOperator
{
public:
    virtual void Operate(MobileObject* mobile);

    PROCESS_TYPE eType;
};
