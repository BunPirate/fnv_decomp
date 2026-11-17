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
    _D3DBLEND eTextureBlendModeSource; // src: XBOX_RETAIL_PDB +0x4 (old: m_eDestinationBlend)
    _D3DBLENDOP eTextureBlendOperation; // src: XBOX_RETAIL_PDB +0x8 (old: m_eBlendOperation)
    _NDLZCMPFUNC eTextureZTestFunction; // src: XBOX_RETAIL_PDB +0xc (old: m_eDepthCompareFunction)
    unsigned int iFillColor; // src: XBOX_RETAIL_PDB +0x10 (old: BlendDepthState)
    float fFillAlphaFadeInTime; // src: XBOX_RETAIL_PDB +0x14 (old: BlendDepthParameters)
    float fFillAlphaFullTime; // src: XBOX_RETAIL_PDB +0x18 (old: DepthCompareParameters)
    float fFillAlphaFadeOutTime; // src: XBOX_RETAIL_PDB +0x1c (old: IndexedFloatParameters)
    float fFillAlphaPersistentPercent; // src: XBOX_RETAIL_PDB +0x20 (old: ShaderFloatParameterSet)
    float fFillAlphaPulseAmplitude; // src: XBOX_RETAIL_PDB +0x24 (old: ShaderParameterFormatSet)
    float fFillAlphaPulseFrequency; // src: XBOX_RETAIL_PDB +0x28 (old: SevenFloatParameterRecord)
    float fFillTextureUAnimSpeed; // src: XBOX_RETAIL_PDB +0x2c (old: SixFloatAndUnsignedIntegerRecord)
    float fFillTextureVAnimSpeed; // src: XBOX_RETAIL_PDB +0x30 (old: SixFloatUnsignedIntegerAndFloatRecord)
    float fEdgeExponentValue; // src: XBOX_RETAIL_PDB +0x34 (old: ExtendedFloatFlagParameters)
    unsigned int iEdgeColor; // src: XBOX_RETAIL_PDB +0x38 (old: ShaderFloatParameterBlock)
    float fEdgeAlphaFadeInTime; // src: XBOX_RETAIL_PDB +0x3c (old: SixFloatRecordWithMiddleFlag)
    float fEdgeAlphaFullTime; // src: XBOX_RETAIL_PDB +0x40 (old: FloatFlagParameters)
    float fEdgeAlphaFadeOutTime; // src: XBOX_RETAIL_PDB +0x44 (old: SixFloatRecordWithLeadingFlag)
    float fEdgeAlphaPersistentPercent; // src: XBOX_RETAIL_PDB +0x48 (old: BlendFloatParameters)
    float fEdgeAlphaPulseAmplitude; // src: XBOX_RETAIL_PDB +0x4c (old: AlphaBlendParameters)
    float fEdgeAlphaPulseFrequency; // src: XBOX_RETAIL_PDB +0x50 (old: BlendStateParameters)
    float fFillAlphaFullPercent; // src: XBOX_RETAIL_PDB +0x54 (old: BlendFactorState)
    float fEdgeAlphaFullPercent; // src: XBOX_RETAIL_PDB +0x58 (old: BlendModeConfiguration)
    _D3DBLEND eTextureBlendModeDest; // src: XBOX_RETAIL_PDB +0x5c (old: m_eSourceBlend)
    _D3DBLEND eParticleBlendModeSource; // src: XBOX_RETAIL_PDB +0x60 (old: m_eAlphaSourceBlend)
    _D3DBLENDOP eParticleBlendOperation; // src: XBOX_RETAIL_PDB +0x64 (old: m_eAlphaBlendOperation)
    _NDLZCMPFUNC eParticleZTestFunction; // src: XBOX_RETAIL_PDB +0x68 (old: m_eAlphaDepthCompareFunction)
    _D3DBLEND eParticleBlendModeDest; // src: XBOX_RETAIL_PDB +0x6c (old: m_eAlphaDestinationBlend)
    float fParticleFadeInTime; // src: XBOX_RETAIL_PDB +0x70 (old: AlphaBlendSettings)
    float fParticleFullTime; // src: XBOX_RETAIL_PDB +0x74 (old: m_fAlphaBlendParameter)
    float fParticleFadeOutTime; // src: XBOX_RETAIL_PDB +0x78 (old: BlendFactorParameters)
    float fParticleFull; // src: XBOX_RETAIL_PDB +0x7c (old: m_fShaderFloatParameter1)
    float fParticlePersistent; // src: XBOX_RETAIL_PDB +0x80 (old: m_fShaderFloatParameter2)
    float fParticleLifetime; // src: XBOX_RETAIL_PDB +0x84 (old: m_fShaderFloatParameter3)
    float fParticleLifeVar; // src: XBOX_RETAIL_PDB +0x88 (old: m_fShaderFloatParameter4)
    float fParticleNormalSpeed; // src: XBOX_RETAIL_PDB +0x8c (old: m_fShaderFloatParameter5)
    float fParticleNormalAcc; // src: XBOX_RETAIL_PDB +0x90 (old: m_fShaderFloatParameter6)
    NiPoint3 ParticleVelocity; // src: XBOX_RETAIL_PDB +0x94 (old: VelocityState)
    NiPoint3 ParticleAcceleration; // src: XBOX_RETAIL_PDB +0xa0 (old: m_kVectorState2)
    float fParticleScale1; // src: XBOX_RETAIL_PDB +0xac (old: m_fShaderFloatParameter7)
    float fParticleScale2; // src: XBOX_RETAIL_PDB +0xb0 (old: m_fShaderFloatParameter8)
    float fParticleScale1Time; // src: XBOX_RETAIL_PDB +0xb4 (old: m_fShaderFloatParameter9)
    float fParticleScale2Time; // src: XBOX_RETAIL_PDB +0xb8 (old: m_fShaderFloatParameter10)
    unsigned int iParticleColor1; // src: XBOX_RETAIL_PDB +0xbc (old: m_uiColorParameter1)
    unsigned int iParticleColor2; // src: XBOX_RETAIL_PDB +0xc0 (old: m_uiColorParameter2)
    unsigned int iParticleColor3; // src: XBOX_RETAIL_PDB +0xc4 (old: m_uiColorParameter3)
    float fParticleColor1Alpha; // src: XBOX_RETAIL_PDB +0xc8 (old: m_fShaderFloatParameter11)
    float fParticleColor2Alpha; // src: XBOX_RETAIL_PDB +0xcc (old: m_fShaderFloatParameter12)
    float fParticleColor3Alpha; // src: XBOX_RETAIL_PDB +0xd0 (old: m_fShaderFloatParameter13)
    float fParticleColor1Time; // src: XBOX_RETAIL_PDB +0xd4 (old: m_fShaderFloatParameter14)
    float fParticleColor2Time; // src: XBOX_RETAIL_PDB +0xd8 (old: m_fShaderFloatParameter15)
    float fParticleColor3Time; // src: XBOX_RETAIL_PDB +0xdc (old: m_fShaderFloatParameter16)
    float fParticleNormalSpeedVar; // src: XBOX_RETAIL_PDB +0xe0 (old: m_fShaderFloatParameter17)
    float fParticleRotate; // src: XBOX_RETAIL_PDB +0xe4 (old: m_fShaderFloatParameter18)
    float fParticleRotateVar; // src: XBOX_RETAIL_PDB +0xe8 (old: m_fShaderFloatParameter19)
    float fParticleRotateSpeed; // src: XBOX_RETAIL_PDB +0xec (old: m_fShaderFloatParameter20)
    float fParticleRotateSpeedVar; // src: XBOX_RETAIL_PDB +0xf0 (old: m_fShaderFloatParameter21)
    BGSDebris* pAddonModels;
    float fAlphaTestStartTime; // src: XBOX_RETAIL_PDB +0xf8 (old: DebrisModelSettings)
    float fAlphaTestEndTime; // src: XBOX_RETAIL_PDB +0xfc (old: EffectShaderAddonData)
    float fAlphaTestStartValue; // src: XBOX_RETAIL_PDB +0x100 (old: DebrisColorSettings)
    float fAlphaTestEndValue; // src: XBOX_RETAIL_PDB +0x104 (old: EffectShaderColorData)
    float fAlphaEdgeWidth; // src: XBOX_RETAIL_PDB +0x108 (old: EffectShaderParameters)
    unsigned int iAlphaEdgeColor; // src: XBOX_RETAIL_PDB +0x10c (old: m_uiBaseColor)
    float fExplosionSpeed; // src: XBOX_RETAIL_PDB +0x110 (old: m_fFloatAfterDefaultColor)
    unsigned int iParticleTextureCountX; // src: XBOX_RETAIL_PDB +0x114 (old: m_uiIntegerParameter1)
    unsigned int iParticleTextureCountY; // src: XBOX_RETAIL_PDB +0x118 (old: m_uiIntegerParameter2)
    float fAddOnFadeInTime; // src: XBOX_RETAIL_PDB +0x11c (old: m_fFirstValueAfterIntegerFields)
    float fAddOnFadeOutTime; // src: XBOX_RETAIL_PDB +0x120 (old: m_fSecondValueAfterIntegerFields)
    float fAddOnScaleStart; // src: XBOX_RETAIL_PDB +0x124 (old: UnsignedIntAndSixFloatData)
    float fAddOnScaleEnd; // src: XBOX_RETAIL_PDB +0x128 (old: SixFloatValueSet)
    float fAddOnScaleInTime; // src: XBOX_RETAIL_PDB +0x12c (old: FiveFloatData)
    float fAddOnScaleOutTime; // src: XBOX_RETAIL_PDB +0x130 (old: FourFloatValueSet)
};
