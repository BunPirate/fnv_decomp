#pragma once

#include "NiObject.h"

// pdb: class NiTask, size 0xc, bases: NiObject, 1 members
class NiTask : public NiObject
{
public:
    virtual ~NiTask();
    virtual const NiRTTI* GetRTTI() const;

    virtual void vf35();
    virtual void vf36();
    virtual bool vf37();

    bool Clear_006824e0();

    int m_eStatus;
};
