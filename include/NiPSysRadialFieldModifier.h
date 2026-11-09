#pragma once

#include "NiPSysFieldModifier.h"

// pdb: class NiPSysRadialFieldModifier, size 0x34, bases: NiPSysFieldModifier, 1 members
class NiPSysRadialFieldModifier : public NiPSysFieldModifier
{
public:
    float m_fRadialType;

    virtual ~NiPSysRadialFieldModifier();

    virtual const NiRTTI* GetRTTI() const;
    virtual NiObject* MakeClone(CloningProcess& arCloning);
    virtual void LoadBinary(NiStream& stream);
    virtual void SaveBinary(NiStream& stream);
    virtual bool IsEqual(NiObject* object) const;
    virtual void GetViewerStrings(NiViewerStringsArray* pkStrings);
    virtual void Update(float time, NiPSysData* data);

    void LoadBinary_00c28760(NiStream& stream);
    void SaveBinary_00c27770(NiStream& stream);
};
