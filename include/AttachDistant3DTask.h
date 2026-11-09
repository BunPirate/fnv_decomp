#pragma once

#include "IOTask.h"

// pdb: class AttachDistant3DTask, size 0x20 (here 0x18), bases: IOTask, 2 members
class AttachDistant3DTask : public IOTask
{
public:
    virtual ~AttachDistant3DTask();

    void* FUN_00440680(unsigned int flags);
    void FUN_004406b0();
};
