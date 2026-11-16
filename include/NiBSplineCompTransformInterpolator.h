#pragma once

#include "NiBSplineTransformInterpolator.h"

// pdb: class NiBSplineCompTransformInterpolator, size 0x60, bases: NiBSplineTransformInterpolator, 1 members
class NiBSplineCompTransformInterpolator : public NiBSplineTransformInterpolator
{
public:
    virtual void LoadBinary(NiStream& kStream);
    virtual bool UpdateTransform(float time, NiObjectNET* target, NiQuatTransform& value);

    void CopyMemberData(NiBSplineCompTransformInterpolator* destination, CloningProcess& cloningProcess);
    bool Update(float fTime, NiObjectNET* pkInterpTarget, NiQuatTransform& kValue);

    float m_afCompScalars[6]; // src: XBOX_RETAIL_PDB +0x48 (old: m_afOffsetAndHalfRange)
};
