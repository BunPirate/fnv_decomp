#pragma once

#include "NiInterpController.h"

class TreadEntry;

// pdb: class BSMultiTargetTreadTransfController, size 0x44 (here 0x38), bases: NiInterpController, 4 members
class BSMultiTargetTreadTransfController : public NiInterpController
{
public:
    virtual NiInterpolator* GetInterpolator(unsigned short index) const;

    TreadEntry* entries;
};
