#pragma once

#include "NiObject.h"
#include "StrArr.h"

// pdb: class NiSequence, size 0x34, bases: NiObject, 5 members
class NiSequence : public NiObject
{
public:
    NiSequence* NiSequence_ctor(const char* pcName, unsigned int uiInitSize, unsigned int uiGrowBy);
    virtual void LoadBinary(NiStream& kStream);

    char* m_pcName;
    StrArr m_kStringArray;
    char m_kCtrl[0x14];
    unsigned int m_uiSequenceValue;
};
