#pragma once

#include "NiKeyBasedInterpolator.h"
#include "NiAVObject.h"
#include "NiQuatTransform.h"
#include "NiPoint3.h"

class NiTransformData;

// pdb: class NiTransformInterpolator, size 0x48, bases: NiKeyBasedInterpolator, 7 members
class NiTransformInterpolator : public NiKeyBasedInterpolator
{
  public:
    NiTransformInterpolator(NiQuatTransform) throw();
    NiTransformInterpolator(NiTransformData*);
    virtual ~NiTransformInterpolator();
    NiTransformInterpolator& operator=(const NiTransformInterpolator&);

    virtual const NiRTTI* GetRTTI() const;
    virtual NiObject* MakeClone(CloningProcess&);
    virtual void LoadBinary(NiStream&);
    virtual void LinkObject(NiStream&);
    virtual bool RegisterStreamables(NiStream&);
    virtual void SaveBinary(NiStream&);
    virtual bool IsEqual(NiObject*) const;
    virtual void GetViewerStrings(NiViewerStringsArray*);
    virtual bool UpdateTransform(float, NiObjectNET*, NiQuatTransform&);
    virtual bool IsTransformValueSupported() const;
    virtual void Collapse();
    virtual void GetInterpolatorTimeRange(float&, float&) const;
    virtual void SetActiveTimeRange(float, float);
    virtual NiInterpolator* CloneForTimeRange(float, float);
    virtual unsigned short GetKeyChannelCount() const;
    virtual unsigned int GetColorKeyCount(unsigned short) const;
    virtual void vf57();
    virtual void vf58();
    virtual NiAnimationKey* GetChannelKeys(unsigned short) const;
    virtual unsigned char GetColorKeySize(unsigned short) const;
    virtual void vf61(unsigned short);

    void CopyMembers(NiTransformInterpolator*, CloningProcess&);
    void CopyMemberData(int);
    bool Update(float, NiObjectNET*, NiQuatTransform&);

    NiQuatTransform m_kTransformValue;
    NiPointer<NiTransformData> m_spData;
    unsigned short m_usLastTransIdx;
    unsigned short m_usLastRotIdx;
    unsigned short m_usLastScaleIdx;
    unsigned char layoutPadding36[2];
    NiPoint3 m_origTranslate;
    bool bPose;
    unsigned char layoutPadding45[3];
};
