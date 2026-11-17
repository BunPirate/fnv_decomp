#pragma once

#include "NiPSysModifierCtlr.h"

// pdb: class NiPSysModifierFloatCtlr, size 0x40, bases: NiPSysModifierCtlr, 0 members
class NiPSysModifierFloatCtlr : public NiPSysModifierCtlr
{
public:
    NiPSysModifierFloatCtlr();
    virtual ~NiPSysModifierFloatCtlr();

    virtual void LinkObject(NiStream& kStream) override;
    virtual void GetValue(float* value);
    virtual void SetTargetVal61(float fVal);

    void SetTargetValue(float fValue);
    void GetTargetValue(float& rfValue);
    void UpdateController(float& UpdateData);
    void __thiscall SynchronizePoseInterpolator_00c32e90(NiObject* pkInterp, unsigned short usIndex);
};

