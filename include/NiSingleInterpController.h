#pragma once

#include "NiInterpController.h"

// pdb: class NiSingleInterpController, size 0x38, bases: NiInterpController, 1 members
class NiSingleInterpController : public NiInterpController
{
public:
    virtual const NiRTTI* GetRTTI() const;
    virtual void LoadBinary(NiStream& kStream);
    virtual void LinkObject(NiStream& stream);
    virtual bool RegisterStreamables(NiStream& stream);
    virtual void SaveBinary(NiStream& stream);
    virtual bool IsEqual(NiObject* pkObject) const;
    virtual void GetViewerStrings(NiViewerStringsArray* strings);
    virtual void ProcessClone(CloningProcess& kCloning);

    virtual unsigned short GetTargetCount() const;
    virtual const char* GetTargetName(unsigned short index) const;
    virtual unsigned short GetTargetIndex(const char* id) const;
    virtual unsigned short GetTargetIndex(const NiFixedString& id) const;
    virtual NiInterpolator* GetInterpolator(unsigned short index) const;
    virtual void SetInterpolator(NiInterpolator* pkInterpolator, unsigned short usIndex);
    virtual void AdvanceControllerTime();
    virtual void SetActiveTimeRange(float startTime, float endTime);
    virtual bool TargetIsRequired(NiObjectNET* object) const;

    void CopyMemberData(NiSingleInterpController* clone, CloningProcess& process);
    void GetValue(float* value);
    void GetPoseValue(bool& value);

    NiPointer<NiInterpolator> m_spInterpolator; // src: XBOX_RETAIL_PDB +0x34 (old: m_spControllerInterpolator)
};
