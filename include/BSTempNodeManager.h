#pragma once

#include "NiNode.h"

// pdb: class BSTempNodeManager, size 0xe0 (here 0xac), bases: NiNode, 1 members
class BSTempNodeManager : public NiNode
{
public:
    virtual ~BSTempNodeManager();
    void* FUN_00450630(unsigned int flags);
};
