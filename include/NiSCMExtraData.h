#pragma once

#include "NiExtraData.h"

// pdb: class NiSCMExtraData, size 0x30, bases: NiExtraData, 3 members
class NiSCMExtraData : public NiExtraData
{
public:
    void* Destroy(unsigned int);

    char m_auiNumEntries[24]; // src: XBOX_RETAIL_PDB +0xc (old: _pad)
    void* m_apkEntries; // src: XBOX_RETAIL_PDB +0x24 (old: m_24)
    char _pad2[4];
    void* m_2c;
};
