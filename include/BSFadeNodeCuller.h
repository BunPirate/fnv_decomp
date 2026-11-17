#pragma once

#include "NiCullingProcess.h"

// pdb: class BSFadeNodeCuller, size 0x120 (here 0x90), bases: NiCullingProcess, 0 members
class BSFadeNodeCuller : public NiCullingProcess
{
public:
    virtual void* GetRTTI();
    virtual void vfn_40();

    ~BSFadeNodeCuller();
    void* DeleteThis(unsigned int flags);
};
