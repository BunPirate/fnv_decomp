#pragma once

#include "hkpCdBodyPairCollector.h"

// pdb: class hkpFlagCdBodyPairCollector, size 0x8, bases: hkpCdBodyPairCollector, 0 members
class hkpFlagCdBodyPairCollector : public hkpCdBodyPairCollector
{
public:
    bool m_flag;

    hkpFlagCdBodyPairCollector();
    bool DidHit() const { return m_flag; }
};
