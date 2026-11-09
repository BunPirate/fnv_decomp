#pragma once

#include "NiGeometry.h"

// pdb: class NiParticles, size 0xf0 (here 0xc4), bases: NiGeometry, 0 members
class NiParticles : public NiGeometry
{
  public:
    NiParticles();
    virtual ~NiParticles();
    virtual const NiRTTI* GetRTTI() const;
    virtual void CalculateConsistency(bool bTool);
};
