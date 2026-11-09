#pragma once

#include "NiMemObject.h"

// pdb: class NiGeometryGroupManager, size 0x4, bases: NiMemObject, 0 members
class NiGeometryGroupManager : public NiMemObject
{
public:
    enum RepackingBehavior
    {
        STATIC,
        UNSHARED,
        DYNAMIC
    };

    virtual void* vf00(unsigned int);
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
};
