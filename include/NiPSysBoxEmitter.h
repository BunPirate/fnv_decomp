#pragma once

#include "NiPSysVolumeEmitter.h"

// pdb: class NiPSysBoxEmitter, size 0x64, bases: NiPSysVolumeEmitter, 3 members
class NiPSysBoxEmitter : public NiPSysVolumeEmitter
{
public:
    virtual void LoadBinary(NiStream& kStream);

    void CopyMembers(NiPSysModifier* pkDest, CloningProcess& kProcess);
    void NiPSysEmitter_CopyMembers(NiPSysModifier* pkDest, CloningProcess& kCloning);

    float m_fEmitterWidth;
    float m_fEmitterHeight;
    float m_fEmitterDepth;
};
