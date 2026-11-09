#pragma once

#include "NiBSplineInterpolator.h"
#include "NiQuatTransform.h"

// pdb: class NiBSplineTransformInterpolator, size 0x48, bases: NiBSplineInterpolator, 4 members
class NiBSplineTransformInterpolator : public NiBSplineInterpolator
{
public:
    virtual void LoadBinary(NiStream& kStream);

    void CopyUnknownFields(NiBSplineTransformInterpolator* interpolator, CloningProcess& cloning);

    NiQuatTransform m_kTransformValue;
    unsigned int m_kTransCPHandle;
    unsigned int m_kRotCPHandle;
    unsigned int m_kScaleCPHandle;
};
