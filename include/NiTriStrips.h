#pragma once

#include "NiTriBasedGeom.h"

class NiTriStripsData;

// pdb: class NiTriStrips, size 0xf0 (here 0xc4), bases: NiTriBasedGeom, 0 members
class NiTriStrips : public NiTriBasedGeom
{
  public:
    NiTriStrips() throw();
    NiTriStrips(NiTriStripsData* pkModelData);
    virtual ~NiTriStrips() throw();

};
