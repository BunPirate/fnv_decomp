#pragma once

#include "NiPSysModifier.h"

// pdb: class NiPSysPositionModifier, size 0x18, bases: NiPSysModifier, 0 members
class NiPSysPositionModifier : public NiPSysModifier
{
public:
    NiPSysPositionModifier() throw();
    NiPSysPositionModifier(const NiFixedString& name, unsigned int updateOrder);
    virtual ~NiPSysPositionModifier();

    virtual const NiRTTI* GetRTTI() const;
    virtual NiObject* MakeClone(CloningProcess& process);
    virtual void LoadBinary(NiStream& kStream);
    virtual void LinkObject(NiStream& stream);
    virtual bool RegisterStreamables(NiStream& stream);
    virtual void SaveBinary(NiStream& stream);
    virtual bool IsEqual(NiObject* object) const;
    virtual void GetViewerStrings(NiViewerStringsArray* strings);
    virtual void Update(float time, NiPSysData* data);


    using NiPSysModifier::m_kName;
    using NiPSysModifier::m_uiUpdateOrder;
    using NiPSysModifier::m_pkTarget;
    using NiPSysModifier::m_bModifierActive;
};
