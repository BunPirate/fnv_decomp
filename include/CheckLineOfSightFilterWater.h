#pragma once

#include "Pathing__CheckLineOfSightFilter.h"

// pdb: structure CheckLineOfSightFilterWater, size 0x8, bases: Pathing::CheckLineOfSightFilter, 1 members
class CheckLineOfSightFilterWater : public Pathing::CheckLineOfSightFilter
{
public:
    bool m_bCheckWater;
    unsigned char layoutPadding5[3];

    virtual bool IsLineOfSightClear(unsigned int, unsigned int, unsigned int,
                                   unsigned int, unsigned int, unsigned int);
};
