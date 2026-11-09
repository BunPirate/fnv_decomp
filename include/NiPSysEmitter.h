#pragma once

#include "NiPSysModifier.h"
#include "NiColorA.h"

class NiPoint3;

// pdb: class NiPSysEmitter, size 0x54, bases: NiPSysModifier, 12 members
class NiPSysEmitter : public NiPSysModifier
{
public:
    NiPSysEmitter();
    NiPSysEmitter(const char* pcName, unsigned int uiOrder, float fSpeed, float fSpeedVar,
                  float fDeclination, float fDeclinationVar, float fPlanarAngle,
                  float fPlanarAngleVar, NiColorA kInitialColor, float fInitialRadius,
                  float fLifeSpan, float fLifeSpanVar, float fRadiusVar);
    virtual ~NiPSysEmitter();

    virtual void LoadBinary(NiStream& kStream);
    virtual void LinkObject(NiStream& stream);
    virtual void SaveBinary(NiStream& kStream);
    virtual bool IsEqual(NiObject* pkObject) const;
    virtual void GetViewerStrings(NiViewerStringsArray* strings);

    virtual void vf41(float time, unsigned short numParticles, const float* ages);
    virtual void GetPositionAndDirection(NiPoint3& position, NiPoint3& motionVelocity);

    float m_fSpeed;
    float m_fSpeedVar;
    float m_fDeclination;
    float m_fDeclinationVar;
    float m_fPlanarAngle;
    float m_fPlanarAngleVar;
    NiColorA m_kInitialColor;
    float m_fInitialRadius;
    float m_fRadiusVar;
    float m_fLifeSpan;
    float m_fLifeSpanVar;
    float m_fScale;
};
