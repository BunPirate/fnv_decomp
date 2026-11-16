#pragma once

#include "NiPSysEmitter.h"

class NiAVObject;
class NiTransform;

// pdb: class NiPSysVolumeEmitter, size 0x58, bases: NiPSysEmitter, 1 members
class NiPSysVolumeEmitter : public NiPSysEmitter
{
public:
    NiPSysVolumeEmitter();
    NiPSysVolumeEmitter(const char* pcName, NiAVObject* pkEmitterObj, float fSpeed,
                        float fSpeedVar, float fDeclination, float fDeclinationVar,
                        float fPlanarAngle, float fPlanarAngleVar, NiColorA kInitialColor,
                        float fInitialRadius, float fLifeSpan, float fLifeSpanVar,
                        float fRadiusVar);
    virtual ~NiPSysVolumeEmitter();

    virtual void LoadBinary(NiStream& kStream);
    virtual void LinkObject(NiStream& kStream);
    virtual void SaveBinary(NiStream& kStream);
    virtual bool IsEqual(NiObject* object) const;
    virtual void GetViewerStrings(NiViewerStringsArray* pkStrings);
    virtual void ProcessClone(CloningProcess& process);
    virtual void GetPositionAndDirection(NiPoint3& position, NiPoint3& kVelocity);
    virtual void vf43(NiAVObject* object);
    virtual void vf44(NiTransform& transform, NiPoint3* position, NiPoint3* motionVelocity);

    void LoadBinaryFromStream(NiStream* stream);
    void CopyMemberData(NiPSysVolumeEmitter* pkDest, CloningProcess& kCloning);
    void* DestroyIfFlagged(unsigned int flags);

    NiAVObject* m_pkEmitterObj; // src: XBOX_RETAIL_PDB +0x54 (old: m_pkEmitterObject)
};
