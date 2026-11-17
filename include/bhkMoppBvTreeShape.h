#pragma once

#include "bhkBvTreeShape.h"

class MoppCodeHeader;

// pdb: class bhkMoppBvTreeShape, size 0x14, bases: bhkBvTreeShape, 0 members
class bhkMoppBvTreeShape : public bhkBvTreeShape
{
public:
    virtual unsigned int slotA8();
    virtual MoppCodeHeader* slotB4(char* pAllocated);

    void bhkSerializable_LoadCInfo(NiStream& arStream);
    unsigned int LoadCInfo(NiStream& arStream);

    static NiObject* __cdecl CreateObject();
};
