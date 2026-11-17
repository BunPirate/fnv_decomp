#pragma once

#include "NiSingleInterpController.h"
#include "NiFixedString.h"
#include "NiPSysModifier.h"

// pdb: class NiPSysModifierCtlr, size 0x40, bases: NiSingleInterpController, 2 members
class NiPSysModifierCtlr : public NiSingleInterpController
{
public:
    virtual void LoadBinary(NiStream& kStream);
    virtual void LinkObject(NiStream& kStream);
    virtual void ProcessClone(CloningProcess& kCloning);
    virtual void vf59();

    void CopyMemberData(NiPSysModifierCtlr* destination, CloningProcess& process);
    void CopyMemberData(NiPSysModifierCtlr* source, void* process);

    NiFixedString m_kModifierName; // src: XBOX_RETAIL_PDB +0x38 (old: m_kTargetModifierName)
    NiPSysModifier* m_pkModifier; // src: XBOX_RETAIL_PDB +0x3c (old: m_pkTargetModifier)
};
