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

    float m_fSpeed; // src: XBOX_RETAIL_PDB +0x18 (old: m_fEmissionSpeed)
    float m_fSpeedVar; // src: XBOX_RETAIL_PDB +0x1c (old: m_fSpeedVariation)
    float m_fDeclination; // src: XBOX_RETAIL_PDB +0x20 (old: m_fEmissionDeclination)
    float m_fDeclinationVar; // src: XBOX_RETAIL_PDB +0x24 (old: m_fDeclinationVariation)
    float m_fPlanarAngle; // src: XBOX_RETAIL_PDB +0x28 (old: m_fEmissionPlanarAngle)
    float m_fPlanarAngleVar; // src: XBOX_RETAIL_PDB +0x2c (old: m_fPlanarAngleVariation)
    NiColorA m_kInitialColor; // src: XBOX_RETAIL_PDB +0x30 (old: m_kParticleColor)
    float m_fInitialRadius; // src: XBOX_RETAIL_PDB +0x40 (old: m_fEmissionRadius)
    float m_fRadiusVar; // src: XBOX_RETAIL_PDB +0x44 (old: m_fRadiusVariation)
    float m_fLifeSpan; // src: XBOX_RETAIL_PDB +0x48 (old: m_fYValue)
    float m_fLifeSpanVar; // src: XBOX_RETAIL_PDB +0x4c (old: m_fLifeSpanVariation)
    float m_fScale;
};
