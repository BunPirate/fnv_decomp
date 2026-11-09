#pragma once

#include "NiExtraData.h"

// pdb: class NiSCMExtraData, size 0x30, bases: NiExtraData, 3 members
class NiSCMExtraData : public NiExtraData
{
public:
    void* Destroy(unsigned int);

    char m_auiNumEntries[24];
    void* m_apkEntries;
    char _pad2[4];
    void* m_2c;
};
