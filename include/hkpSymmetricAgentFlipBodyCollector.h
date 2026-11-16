#pragma once

#include "hkpCdBodyPairCollector.h"

// pdb: class hkpSymmetricAgentFlipBodyCollector, size 0xc, bases: hkpCdBodyPairCollector, 1 members
class hkpSymmetricAgentFlipBodyCollector : public hkpCdBodyPairCollector
{
public:
    void addBody();
    void reset();

    unsigned char unk04[4];
    void* m_collector; // src: XBOX_RETAIL_PDB +0x8 (old: payload)
};
