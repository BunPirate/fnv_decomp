#pragma once

#include "bhkShapeCollection.h"

class StripsShape;
class NiNode;

// pdb: class bhkNiTriStripsShape, size 0x14 (here 0x20), bases: bhkShapeCollection, 0 members
class bhkNiTriStripsShape : public bhkShapeCollection
{
public:
    virtual void BuildDisplayGeometry_00ca6b60(NiNode* apNode, int arDefColor);
    virtual void vf56();
    virtual void vf57();

    float GetScaleValue();
    static NiObject* __cdecl CreateObject();

    int unk00;
    int unk04;
    StripsShape* m_pShape;
};
