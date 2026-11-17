#pragma once

#include "NiAVObject.h"
#include "NiColor.h"
#include "NiColorA.h"

class NiGeometry;
class NiScreenElements;
class NiTexture;
class NiPointLight;
class NiCamera;
class NiNode;
class Tile;
class ShadowSceneNode;
class BSShaderAccumulator;
class Target82;
class Arg;

// pdb: class FORenderedMenu, size 0xd8, 52 members
class FORenderedMenu
{
public:
    virtual ~FORenderedMenu();
    virtual void vf1();
    virtual void* v2();
    virtual void Render_007fba00(void*, void*, Target82*);
    virtual void vf4();
    virtual bool UpdateScreenEffect();
    virtual bool Pick_007fb790(bool abDown, int a2, int a3);
    virtual void vf7();
    virtual void vf8();
    virtual void OnMenuOpen();
    virtual void ResetNifs();
    virtual float BaseProcess_GetActorAlpha();
    virtual void v12();
    virtual void v13();
    virtual void HandleStaticEffect(float afTime);
    virtual void UpdateVertHold(float afTime);
    virtual void HandleShudderEffect(float afTime);
    virtual void HandlePulseEffect(float afDuration);
    virtual void UpdateNodePosition(float fTime);
    virtual void UpdateDistortTimer(float dt);
    virtual void DoEffect(Arg*, void*, int);

    bool GetInitialized();
    NiAVObject* GetMenuRoot();
    void ClearMenuLight();
    bool CreateMenuLight(const char*, ShadowSceneNode*);
    void SetDefaultTexture(NiTexture*);
    unsigned int GetCurrentTimeMilliseconds();
    void TriggerBurst(float afBurstDuration, float afBurstIntensity, float afSoundChance);
    NiNode* GetSceneNode();
    void FORenderedMenuRaceSex_LightButton(int);
    bool IsUnk28Set();
    void SetScreenTexture(int);
    void OnMenuOpen_007fb040();
    void ResetMenuState();
    bool Pick_007fb790(void* pkUnused, float* pfX, float* pfY);

    NiPointer<NiGeometry> spScreenTriShape; // src: XBOX_RETAIL_PDB +0x4 (old: m_pMenuBackgroundScreenGeometry)
    NiPointer<NiAVObject> spScreenParent; // src: XBOX_RETAIL_PDB +0x8 (old: m_pMenuRoot)
    NiPointer<NiScreenElements> spPartialScreenGeometry; // src: XBOX_RETAIL_PDB +0xc (old: m_pScreenGeometry)
    NiPointer<NiTexture> spDefaultTex; // src: XBOX_RETAIL_PDB +0x10 (old: m_pDefaultTexture)
    NiPointer<NiAVObject> m_pRenderedMenuObject;
    Tile* pMenuTile; // src: XBOX_RETAIL_PDB +0x18 (old: m_pFourthMenuObject)
    NiPointer<NiPointLight> spLight; // src: XBOX_RETAIL_PDB +0x1c (old: m_pMenuLight)
    ShadowSceneNode* pLightShadowSceneNode; // src: XBOX_RETAIL_PDB +0x20 (old: m_pSecondaryMenuObject)
    NiPointer<NiCamera> spCamera; // src: XBOX_RETAIL_PDB +0x24 (old: m_pMenuLightParameters)
    bool bInitialized;
    bool bScaledTexCoords; // src: XBOX_RETAIL_PDB +0x29 (old: m_bUseMenuImageSpaceEffects)
    bool bUsePartialScreenGeometry; // src: XBOX_RETAIL_PDB +0x2a (old: m_bEnableFlicker)
    unsigned char unk2B[1];
    NiColor ScreenLightColor; // src: XBOX_RETAIL_PDB +0x2c (old: m_kScreenLightColor)
    float fScreenLightBaseIntensity;
    float fScreenLightFlickerIntensity; // src: XBOX_RETAIL_PDB +0x3c (old: m_fFlicker)
    float fBlurRadius;
    float fBlurIntensity;
    float fScanlineScale; // src: XBOX_RETAIL_PDB +0x48 (old: m_fScanlineScale)
    bool bDoScanlines; // src: XBOX_RETAIL_PDB +0x4c (old: m_bDoScanlines)
    bool m_bBurstActive;
    unsigned char unk4E[2];
    float fBurstStartTime; // src: XBOX_RETAIL_PDB +0x50 (old: m_fBurstElapsedTime)
    float fBurstDuration;
    float fBurstMaximumIntensity; // src: XBOX_RETAIL_PDB +0x58 (old: m_fBurstIntensity)
    float fBurstCurrentIntensity; // src: XBOX_RETAIL_PDB +0x5c (old: m_fBurstSoundChance)
    bool bVertHoldActive; // src: XBOX_RETAIL_PDB +0x60 (old: m_bBurstSoundPlayed)
    unsigned char unk61[3];
    float fVertHoldStartTime; // src: XBOX_RETAIL_PDB +0x64 (old: m_fShudderIntensity)
    float fVertHoldDuration; // src: XBOX_RETAIL_PDB +0x68 (old: m_fShudderDuration)
    float fVertHoldSpeed; // src: XBOX_RETAIL_PDB +0x6c (old: m_fShudderFrequency)
    float fVertHoldCurrentPosition; // src: XBOX_RETAIL_PDB +0x70 (old: m_fVerticalHoldDuration)
    bool bShudderActive; // src: XBOX_RETAIL_PDB +0x74 (old: m_bVerticalHoldActive)
    unsigned char unk75[3];
    float fShudderStartTime; // src: XBOX_RETAIL_PDB +0x78 (old: m_fVerticalHoldSpeed)
    float fShudderDuration; // src: XBOX_RETAIL_PDB +0x7c (old: m_fVerticalHoldRate)
    float fShudderIntensity; // src: XBOX_RETAIL_PDB +0x80 (old: m_fVerticalHoldChance)
    float fShudderFrequency; // src: XBOX_RETAIL_PDB +0x84 (old: m_fShudderChance)
    float fShudderCurrentPosition; // src: XBOX_RETAIL_PDB +0x88 (old: m_fPulseRadiusIntensity)
    float fPulseCurrentBrighten; // src: XBOX_RETAIL_PDB +0x8c (old: m_fPulseBrightenIntensity)
    float fPulseCurrentRadius; // src: XBOX_RETAIL_PDB +0x90 (old: m_fPulseRate)
    bool bPulseAffectsLight; // src: XBOX_RETAIL_PDB +0x94 (old: m_bPulseActive)
    bool bDistortActive; // src: XBOX_RETAIL_PDB +0x95 (old: m_bShudderActive)
    unsigned char unk96[2];
    float fDistortStartTime; // src: XBOX_RETAIL_PDB +0x98 (old: m_fDistortHorizontalScale)
    float fDistortPosition; // src: XBOX_RETAIL_PDB +0x9c (old: m_fDistortVerticalScale)
    float fDistortDuration;
    float fNextDistortTime; // src: XBOX_RETAIL_PDB +0xa4 (old: m_fDistortTimeRemaining)
    NiColorA BackgroundColor;
    bool bMenuOpen; // src: XBOX_RETAIL_PDB +0xb8 (old: m_bMenuLightEnabled)
    bool bMenuRendering; // src: XBOX_RETAIL_PDB +0xb9 (old: m_bMenuLightCreated)
    unsigned char unkBA[2];
    NiPointer<NiTexture> spScanlinesTexture; // src: XBOX_RETAIL_PDB +0xbc (old: m_pMenuLightShadowNode)
    NiColorA TintColor; // src: XBOX_RETAIL_PDB +0xc0 (old: m_kMenuLightColor)
    bool bHidQuantity; // src: XBOX_RETAIL_PDB +0xd0 (old: m_bMenuLightVisible)
    bool bHidTutorial; // src: XBOX_RETAIL_PDB +0xd1 (old: m_bMenuLightShadowed)
    bool bHidMessage; // src: XBOX_RETAIL_PDB +0xd2 (old: m_bMenuLightAttached)
    unsigned char unkD3[1];
    NiPointer<BSShaderAccumulator> spAccumulator; // src: XBOX_RETAIL_PDB +0xd4 (old: m_pMenuLightNode)
};
