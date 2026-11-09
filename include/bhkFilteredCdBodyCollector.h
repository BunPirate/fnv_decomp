#pragma once

#include "hkpAllCdBodyPairCollector.h"

// pdb: class bhkFilteredCdBodyCollector, size 0x114, bases: hkpAllCdBodyPairCollector, 0 members
class bhkFilteredCdBodyCollector : public hkpAllCdBodyPairCollector
{
public:
    virtual ~bhkFilteredCdBodyCollector();
    virtual void vf03();
};
