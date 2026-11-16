#pragma once
#include "NiPointer.h"

#include "NiKeyBasedInterpolator.h"

class NiBoolData;

// pdb: class NiBoolInterpolator, size 0x18, bases: NiKeyBasedInterpolator, 3 members
class NiBoolInterpolator : public NiKeyBasedInterpolator
{
  public:
    NiBoolInterpolator() throw();
    NiBoolInterpolator(bool abValue) throw();
    NiBoolInterpolator(void* pkBoolData) throw();
    virtual ~NiBoolInterpolator() throw();

    virtual const NiRTTI* GetRTTI() const;
    virtual NiObject* MakeClone(CloningProcess& kCloning);
    virtual void LoadBinary(NiStream& arStream);
    virtual void LinkObject(NiStream& arStream);
    virtual bool RegisterStreamables(NiStream& arStream);
    virtual void SaveBinary(NiStream& arStream);
    virtual bool IsEqual(NiObject* pkObject) const;
    virtual void GetViewerStrings(NiViewerStringsArray* pkStrings);
    virtual bool UpdateBool(float fTime, NiObjectNET* pkInterpTarget, bool& bValue);
    virtual bool IsBoolValueSupported() const;
    virtual void Collapse();
    virtual void GetInterpolatorTimeRange(float& arBeginKeyTime, float& arEndKeyTime) const;
    virtual void SetActiveTimeRange(float afStartTime, float afEndTime);
    virtual NiInterpolator* CloneForTimeRange(float fStartTime, float fEndTime);
    virtual NiBoolInterpolator* IsNiBoolInterpolator() const;
    virtual unsigned short GetKeyChannelCount() const;
    virtual unsigned int GetColorKeyCount(unsigned short usChannel) const;
    virtual void vf57();
    virtual void vf58();
    virtual NiAnimationKey* GetChannelKeys(unsigned short usChannel) const;
    virtual unsigned char GetColorKeySize(unsigned short usChannel) const;
    virtual void vf61(unsigned short usChannel);

    void SetAnimationKeys(void* keys, unsigned int keyType, unsigned int count);
    void CopyMembers(NiBoolInterpolator*, CloningProcess&);
    void SetPoseValue(bool);
    NiStream* LinkObject(NiStream*);
    bool __thiscall RegisterStreamables_00a3c5b0(NiStream*);

    bool m_bBoolValue;
    unsigned char unk0D[3];
    NiPointer<NiBoolData> m_spBoolData;
    unsigned int m_uiLastIdx; // src: XBOX_RETAIL_PDB +0x14 (old: m_uiLastKeyIndex)
};
