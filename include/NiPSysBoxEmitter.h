#pragma once

#include "NiPSysVolumeEmitter.h"

// pdb: class NiPSysBoxEmitter, size 0x64, bases: NiPSysVolumeEmitter, 3 members
class NiPSysBoxEmitter : public NiPSysVolumeEmitter
{
public:
    virtual void LoadBinary(NiStream& kStream);

    void CopyMembers(NiPSysModifier* pkDest, CloningProcess& kProcess);
    void NiPSysEmitter_CopyMembers(NiPSysModifier* pkDest, CloningProcess& kCloning);

    float m_fEmitterWidth; // src: XBOX_RETAIL_PDB +0x58 (old: width)
    float m_fEmitterHeight; // src: XBOX_RETAIL_PDB +0x5c (old: height)
    float m_fEmitterDepth; // src: XBOX_RETAIL_PDB +0x60 (old: depth)
};
