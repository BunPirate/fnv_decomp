#pragma once

#include "NiPoint3.h"

class BGSDebris;

#include "_D3DBLEND.h"
#include "_D3DBLENDOP.h"
#include "_NDLZCMPFUNC.h"
// pdb: structure EffectShaderData, size 0x134, 73 members
class EffectShaderData
{
  public:
    EffectShaderData();
    void Initialize();
    void Endian();
    unsigned char cFlags;
    unsigned char layoutPadding1[3];
    _D3DBLEND eTextureBlendModeSource;
    _D3DBLENDOP eTextureBlendOperation;
    _NDLZCMPFUNC eTextureZTestFunction;
    unsigned int iFillColor;
    float fFillAlphaFadeInTime;
    float fFillAlphaFullTime;
    float fFillAlphaFadeOutTime;
    float fFillAlphaPersistentPercent;
    float fFillAlphaPulseAmplitude;
    float fFillAlphaPulseFrequency;
    float fFillTextureUAnimSpeed;
    float fFillTextureVAnimSpeed;
    float fEdgeExponentValue;
    unsigned int iEdgeColor;
    float fEdgeAlphaFadeInTime;
    float fEdgeAlphaFullTime;
    float fEdgeAlphaFadeOutTime;
    float fEdgeAlphaPersistentPercent;
    float fEdgeAlphaPulseAmplitude;
    float fEdgeAlphaPulseFrequency;
    float fFillAlphaFullPercent;
    float fEdgeAlphaFullPercent;
    _D3DBLEND eTextureBlendModeDest;
    _D3DBLEND eParticleBlendModeSource;
    _D3DBLENDOP eParticleBlendOperation;
    _NDLZCMPFUNC eParticleZTestFunction;
    _D3DBLEND eParticleBlendModeDest;
    float fParticleFadeInTime;
    float fParticleFullTime;
    float fParticleFadeOutTime;
    float fParticleFull;
    float fParticlePersistent;
    float fParticleLifetime;
    float fParticleLifeVar;
    float fParticleNormalSpeed;
    float fParticleNormalAcc;
    NiPoint3 ParticleVelocity;
    NiPoint3 ParticleAcceleration;
    float fParticleScale1;
    float fParticleScale2;
    float fParticleScale1Time;
    float fParticleScale2Time;
    unsigned int iParticleColor1;
    unsigned int iParticleColor2;
    unsigned int iParticleColor3;
    float fParticleColor1Alpha;
    float fParticleColor2Alpha;
    float fParticleColor3Alpha;
    float fParticleColor1Time;
    float fParticleColor2Time;
    float fParticleColor3Time;
    float fParticleNormalSpeedVar;
    float fParticleRotate;
    float fParticleRotateVar;
    float fParticleRotateSpeed;
    float fParticleRotateSpeedVar;
    BGSDebris* pAddonModels;
    float fAlphaTestStartTime;
    float fAlphaTestEndTime;
    float fAlphaTestStartValue;
    float fAlphaTestEndValue;
    float fAlphaEdgeWidth;
    unsigned int iAlphaEdgeColor;
    float fExplosionSpeed;
    unsigned int iParticleTextureCountX;
    unsigned int iParticleTextureCountY;
    float fAddOnFadeInTime;
    float fAddOnFadeOutTime;
    float fAddOnScaleStart;
    float fAddOnScaleEnd;
    float fAddOnScaleInTime;
    float fAddOnScaleOutTime;
};
