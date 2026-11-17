#pragma once

#include "NiObject.h"

class NiAVObject;
class NiFixedString;
class StrArr;

// pdb: class NiAVObjectPalette, size 0x8, bases: NiObject, 0 members
class NiAVObjectPalette : public NiObject
{
public:
    virtual NiAVObject* FindAVObject(const NiFixedString& kName);
    virtual void AddNamedAVObject(const NiFixedString& kName, NiAVObject* pkObject);

    NiAVObject* FindAVObject(NiFixedString& kName);
    void AppendString(StrArr* pkStrings);
};
