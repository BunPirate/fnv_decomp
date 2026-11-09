#pragma once

#include "NiInterpolator.h"
#include "NiFixedString.h"
#include "NiQuatTransform.h"

class NiAVObjectPalette;

// pdb: class NiLookAtInterpolator, size 0x44, bases: NiInterpolator, 5 members
class NiLookAtInterpolator : public NiInterpolator
{
  public:
    NiLookAtInterpolator(unsigned int pkLookAt, unsigned int eAxis, bool bFlip);
    virtual ~NiLookAtInterpolator();

    virtual const NiRTTI* GetRTTI() const;
    virtual NiObject* MakeClone(CloningProcess& arCloning);
    virtual void LoadBinary(NiStream& arStream);
    virtual bool RegisterStreamables(NiStream& arStream);
    virtual void SaveBinary(NiStream& kStream);
    virtual bool IsEqual(NiObject* apObject) const;
    virtual void GetViewerStrings(NiViewerStringsArray* pkStrings);
    virtual void ProcessClone(CloningProcess& arCloning);
    virtual bool UpdateTransform(float fTime, NiObjectNET* pkInterpTarget, NiQuatTransform& kValue);
    virtual bool IsTransformValueSupported() const;
    virtual void Collapse();
    virtual void GetInterpolatorTimeRange(float& arBeginKeyTime, float& arEndKeyTime) const;
    virtual void SetActiveTimeRange(float fStartTime, float fEndTime);
    virtual NiInterpolator* CloneForTimeRange(float fStartTime, float fEndTime);
    virtual bool IsPoseValue();
    virtual bool IsTimeVarying();

    void __thiscall CopyMembers(NiLookAtInterpolator* pkDest, CloningProcess& kCloning);
    void* __thiscall FUN_00a4c5c0(unsigned int flags);
    void SetLookAtName(const NiFixedString& kName);
    bool ResolveTargetObject(NiAVObjectPalette* pkPalette);
    void __thiscall GetItemsRange(float* fBeginKeyTime, float* fEndKeyTime);

    unsigned short m_uFlags;
    unsigned short unk0E;
    NiAVObject* m_pkLookAt;
    NiFixedString m_kLookAtName;
    NiQuatTransform m_kTransformValue;
    NiInterpolator* m_aspInterpolators[3];
};
