#pragma once

#include "bhkShapeCollection.h"

// pdb: class bhkPackedNiTriStripsShape, size 0x14, bases: bhkShapeCollection, 0 members
class bhkPackedNiTriStripsShape : public bhkShapeCollection
{
public:
    bhkPackedNiTriStripsShape();
    static NiObject* __cdecl CreateObject();

    virtual void vf56();
};
