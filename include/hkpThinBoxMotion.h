#pragma once

#include "hkpBoxMotion.h"

// pdb: class hkpThinBoxMotion, size 0x120, bases: hkpBoxMotion, 0 members
class hkpThinBoxMotion : public hkpBoxMotion
{
public:
    hkpThinBoxMotion(FinishingFlag flag);
    virtual ~hkpThinBoxMotion() throw();
};
