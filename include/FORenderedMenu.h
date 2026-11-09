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

    NiPointer<NiGeometry> spScreenTriShape;
    NiPointer<NiAVObject> spScreenParent;
    NiPointer<NiScreenElements> spPartialScreenGeometry;
    NiPointer<NiTexture> spDefaultTex;
    NiPointer<NiAVObject> m_pRenderedMenuObject;
    Tile* pMenuTile;
    NiPointer<NiPointLight> spLight;
    ShadowSceneNode* pLightShadowSceneNode;
    NiPointer<NiCamera> spCamera;
    bool bInitialized;
    bool bScaledTexCoords;
    bool bUsePartialScreenGeometry;
    unsigned char unk2B[1];
    NiColor ScreenLightColor;
    float fScreenLightBaseIntensity;
    float fScreenLightFlickerIntensity;
    float fBlurRadius;
    float fBlurIntensity;
    float fScanlineScale;
    bool bDoScanlines;
    bool m_bBurstActive;
    unsigned char unk4E[2];
    float fBurstStartTime;
    float fBurstDuration;
    float fBurstMaximumIntensity;
    float fBurstCurrentIntensity;
    bool bVertHoldActive;
    unsigned char unk61[3];
    float fVertHoldStartTime;
    float fVertHoldDuration;
    float fVertHoldSpeed;
    float fVertHoldCurrentPosition;
    bool bShudderActive;
    unsigned char unk75[3];
    float fShudderStartTime;
    float fShudderDuration;
    float fShudderIntensity;
    float fShudderFrequency;
    float fShudderCurrentPosition;
    float fPulseCurrentBrighten;
    float fPulseCurrentRadius;
    bool bPulseAffectsLight;
    bool bDistortActive;
    unsigned char unk96[2];
    float fDistortStartTime;
    float fDistortPosition;
    float fDistortDuration;
    float fNextDistortTime;
    NiColorA BackgroundColor;
    bool bMenuOpen;
    bool bMenuRendering;
    unsigned char unkBA[2];
    NiPointer<NiTexture> spScanlinesTexture;
    NiColorA TintColor;
    bool bHidQuantity;
    bool bHidTutorial;
    bool bHidMessage;
    unsigned char unkD3[1];
    NiPointer<BSShaderAccumulator> spAccumulator;
};
