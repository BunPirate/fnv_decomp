#pragma once

#include "NiPSysVolumeEmitter.h"

class NiTransform;
struct StrArr;

// pdb: class NiPSysCylinderEmitter, size 0x60, bases: NiPSysVolumeEmitter, 2 members
class NiPSysCylinderEmitter : public NiPSysVolumeEmitter
{
public:
    virtual void LoadBinary(NiStream& kStream);
    virtual void SaveBinary(NiStream& kStream);

    void* DestroyIfFlagged(unsigned int flags);
    BSFadeNode* CloneFadeNode(CloningProcess& process);
    void AppendShapeParams(StrArr* strings);
    void ComputeVolumeInitialPositionAndVelocity(NiTransform& emitterToPSys, NiPoint3& position, NiPoint3& kVelocity);  // rotates by the transform (0x00524c40), velocity by its m_Rotate

    bool __thiscall IsEqual_00c1f9e0(NiAVObject* pkObject);
    bool __thiscall FUN_00c31b80(NiAVObject* pkObject);

    float m_fEmitterRadius;
    float m_fEmitterHeight;
};
