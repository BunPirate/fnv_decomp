#pragma once

#include "NiPSysModifierCtlr.h"
#include "NiTPrimitiveSet_float_.h"

// pdb: class NiPSysEmitterCtlr, size 0x5c, bases: NiPSysModifierCtlr, 5 members
class NiPSysEmitterCtlr : public NiPSysModifierCtlr
{
public:
    NiPSysEmitterCtlr();
    NiPSysEmitterCtlr(const char* name) throw();
    virtual ~NiPSysEmitterCtlr();


    virtual void LoadBinary(NiStream& kStream);
    virtual void LinkObject(NiStream& kStream);
    virtual void ProcessClone(CloningProcess& kCloning);
    virtual NiObject* MakeClone(CloningProcess& kCloning);
    virtual void SetInterpolator(NiInterpolator* interpolator, unsigned short index);
    virtual void vf60();

    void CopyMemberData(NiPSysEmitterCtlr* destination, CloningProcess& process);
    void BSPSysMultiTargetEmitterCtlr_CopyMembers(NiPSysEmitterCtlr* destination, void* process);
    NiPSysEmitterCtlr* BSPSysMultiTargetEmitterCtlr_CreateClone(void* process);

    NiPointer<NiInterpolator> m_spEmitterActiveInterpolator; // src: XBOX_RETAIL_PDB +0x40 (old: m_spVisibilityInterpolator)
    NiInterpolator* m_pkLastBirthRateInterpolator; // src: XBOX_RETAIL_PDB +0x44 (old: m_pEmitterActiveInterpolator)
    float m_fLastScaledTime; // src: XBOX_RETAIL_PDB +0x48 (old: m_fScaledLastTime)
    bool m_bLastActive; // src: XBOX_RETAIL_PDB +0x4c (old: m_bIsInitialized)
    unsigned char layoutPadding4D[3];
    NiTPrimitiveSet_float_ m_kParticleAges; // src: XBOX_RETAIL_PDB +0x50 (old: m_kBirthRateKeys)
};
