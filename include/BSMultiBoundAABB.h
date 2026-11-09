#pragma once

#include "BSMultiBoundShape.h"
#include "NiPoint3.h"
#include "NiPoint3.h"
#include "Vec4.h"

// pdb: class BSMultiBoundAABB, size 0x24, bases: BSMultiBoundShape, 2 members
class BSMultiBoundAABB : public BSMultiBoundShape
{
public:
    NiPoint3 Center;
    NiPoint3 HalfExtents;

    BSMultiBoundAABB();
    virtual ~BSMultiBoundAABB();
    virtual int GetDebugGeomShapeSize();
    virtual void SetGridPosition(const NiPoint3& center);

    const Vec57& extent();
    void setExtent(const Vec57& extent);

    float GetPointLength();
    void BSMultiBoundAABB_GetVertices(NiPoint3* apPoints);
    void GetNiBound(Vec4* aBound);
    void* FUN_004a7060(unsigned int flags);
};
