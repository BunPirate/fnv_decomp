#pragma once

#include <stddef.h>
#include "NiNode.h"

// pdb: class NiSortAdjustNode, size 0xe0 (here 0xac), bases: NiNode, 1 members
class NiSortAdjustNode : public NiNode
{
  public:
    NiSortAdjustNode(unsigned int uiChildCount);
    NiSortAdjustNode(int mode = 0);
    virtual ~NiSortAdjustNode();


    void SetSelectiveUpdate(bool bValue);
    void SetSelectiveUpdateTransforms(bool bValue);
    void SetArraySize(unsigned int size);
    void* __thiscall Destructor(unsigned int flags);
};
