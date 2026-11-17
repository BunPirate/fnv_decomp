#pragma once

#include "NiGeometryGroup.h"

// pdb: class NiUnsharedGeometryGroup, size 0xc, bases: NiGeometryGroup, 0 members
class NiUnsharedGeometryGroup : public NiGeometryGroup
{
public:
    virtual ~NiUnsharedGeometryGroup();

    void* __thiscall Destroy(unsigned int flags);
    static NiGeometryGroup* Create();

};
