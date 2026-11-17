#pragma once

#include "NiBlendInterpolator.h"
#include "NiPoint3.h"

// pdb: class NiBlendPoint3Interpolator, size 0x40, bases: NiBlendInterpolator, 2 members
class NiBlendPoint3Interpolator : public NiBlendInterpolator
{
  public:
    NiBlendPoint3Interpolator(bool managerControlled, float weightThreshold, unsigned char arraySize);
    virtual ~NiBlendPoint3Interpolator();

    virtual const NiRTTI* GetRTTI() const;
    virtual NiObject* MakeClone(CloningProcess& cloning);
    virtual void LoadBinary(NiStream& stream);
    virtual void LinkObject(NiStream& stream);
    virtual bool RegisterStreamables(NiStream& stream);
    virtual void SaveBinary(NiStream& kStream);
    virtual bool IsEqual(NiObject* object) const;
    virtual void GetViewerStrings(NiViewerStringsArray* strings);
    virtual bool UpdatePoint3(float time, NiObjectNET* target, NiPoint3& value);
    virtual bool IsPoint3ValueSupported() const;
    virtual bool ControlsTransform(NiInterpolator* interpolator);

    bool Update(float time, NiObjectNET* pkInterpTarget, NiPoint3& value);
    bool StoreSingleValue(float time, NiObjectNET* pkInterpTarget, NiPoint3& value);
    bool UpdateSingleInterpolator(float fTime, NiObjectNET* pkInterpTarget, NiPoint3& kValue);
    NiBlendPoint3Interpolator& operator=(const NiBlendPoint3Interpolator& other);

    NiPoint3 m_kPoint3Value;
    bool m_bValidValue; // src: XBOX_RETAIL_PDB +0x3c (old: m_bValueValid)
};
