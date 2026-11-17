#pragma once

#include "NiBoolInterpController.h"

// pdb: class NiVisController, size 0x38 (here 0x3c), bases: NiBoolInterpController, 0 members
class NiVisController : public NiBoolInterpController
{
public:
    void GetVisibility(bool& bValue);

    NiBoolInterpController* m_pkBoolInterpController;
};
