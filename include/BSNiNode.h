#pragma once

#include "NiNode.h"

// pdb: class BSNiNode, size 0xd0 (here 0xac), bases: NiNode, 0 members
class BSNiNode : public NiNode
{
  public:
    virtual ~BSNiNode();
    virtual const NiRTTI* GetRTTI() const;
    virtual NiObject* MakeClone(CloningProcess& process);
    virtual void ReparentSkinInstances(NiNode* source, NiNode* target);

    void CopyMemberData(BSNiNode* target, CloningProcess* process);
    static void SetNewName(NiNode* node, char* name);
    void __local_vftable_ctor_closure();
};
