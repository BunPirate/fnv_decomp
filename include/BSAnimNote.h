#pragma once

#include "NiObject.h"

class TimedTextEntry;

// pdb: class BSAnimNote, size 0x10, bases: NiObject, 2 members
class BSAnimNote : public NiObject
{
  public:
    virtual ~BSAnimNote();
    virtual void GetViewerStrings(NiViewerStringsArray* apStrings);
    virtual bool __thiscall vf35(const TimedTextEntry* apTextKey);

    void BaseGetViewerStrings(NiViewerStringsArray* pStrings);

    unsigned char eType[4];
    float fTime;
};
