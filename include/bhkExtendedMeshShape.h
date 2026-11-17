#pragma once

#include "bhkShapeCollection.h"

// pdb: class bhkExtendedMeshShape, size 0x18 (here 0x14), bases: bhkShapeCollection, 1 members
class bhkExtendedMeshShape : public bhkShapeCollection
{
public:
    virtual void vf56();
    virtual void vf57();

    static NiObject* __cdecl CreateObject();
};
