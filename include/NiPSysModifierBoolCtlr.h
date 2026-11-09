#pragma once

#include "NiPSysModifierCtlr.h"
#include "StrArr.h"

// pdb: class NiPSysModifierBoolCtlr, size 0x40, bases: NiPSysModifierCtlr, 0 members
class NiPSysModifierBoolCtlr : public NiPSysModifierCtlr
{
public:
    NiPSysModifierBoolCtlr() throw();

    virtual void vf60(bool* value);
    virtual void vf61(int value);

    void AppendModifierInfo(StrArr* strings);
};
