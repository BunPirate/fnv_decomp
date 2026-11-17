#pragma once

#include "NiRefObject.h"
#include "BSOcclusionPlane.h"

template <class T> class NiTPointerList;
class P2Obj;

// pdb: class BSPortalGraph, size 0x78 (here 0x8), bases: NiRefObject, 10 members
class BSPortalGraph : public NiRefObject
{
public:
    NiTPointerList<BSOcclusionPlane*>& GetOccluderList();
    void BSPortalGraph_AttachAlwaysRenderChild(P2Obj* pkChild);
    void BSPortalGraph_DetachAlwaysRenderChild(P2Obj* pkChild);
};
