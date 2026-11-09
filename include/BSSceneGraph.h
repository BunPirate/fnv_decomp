#pragma once

#include "NiNode.h"

// pdb: class BSSceneGraph, size 0xf0 (here 0xac), bases: NiNode, 5 members
class BSSceneGraph : public NiNode
{
  public:
    virtual const NiRTTI* GetRTTI() const;
    virtual void vf64();
    virtual void vf65();
};
