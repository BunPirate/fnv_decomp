#pragma once

#include "FORenderedMenu.h"
#include "NiAVObject.h"
#include "BSSoundHandle.h"

class NiNode;
class NiGeometry;
class NiScreenElements;
class NiColorA;

// pdb: class FOPipboyManager, size 0x170, bases: FORenderedMenu, 22 members
class FOPipboyManager : public FORenderedMenu
{
public:
    FOPipboyManager();
    virtual ~FOPipboyManager();
    virtual void OnMenuOpen();

    void Init(bool);
    void ActivateButton(const unsigned int aiButton);
    bool IsUnk28Set();
    bool GetByteAtOffsetB9();
    void FORenderedMenu_SetScreenGeometry(NiAVObject*);
    void InitLight();
    void SetScreenLightFlickerIntensity(float);
    void SetIntensity(float);
    void SetQuad(const NiColorA&);
    void SetBlurIntensity(float);
    void SetScanlines(bool, float);
    void SetPipBoyObjectVisibility(bool, bool, bool);
    void SetKnobTargetAndRate(int aiKnob, float afTarget, float afRate);
    void UpdateFade(float now);
    void UpdatePipboyLightFade(float afTime);
    void InitKnobs();
    void InitButtons();
    void SetDataGlowEnabled(bool);
    void UpdatePipboyLight(int);
    void SetTabKnobPosition(int aiNewPos, bool abPlaySounds);
    bool CheckOrangeButtonsClicked(bool press, bool release, float& x, float& y, int& button);
    NiAVObject* SkyObject_GetNiNode();
    void SetTarget_00705fc0(NiNode*);
    void NiTexturingProperty_Map_SetTexture(NiNode*);
    void FORenderedMenu_SetupScreen(NiAVObject*);
    void FORenderedMenu_SetTintColor(const NiColorA&);
    void TESQuest_SetScriptProcessingDelay(float);
    void bhkCharacterControllerCinfo_SetAvoidBox(bool);
    FORenderedMenu* FUN_00704370();
    void ReInitialize();

    NiPointer<NiNode> spPipboyRoot;
    NiPointer<NiNode> sp3rdPersonPipboyRoot;
    NiPointer<NiAVObject> sp3rdPersonScreen;
    NiPointer<NiScreenElements> spPartialScreenGeometry;
    NiPointer<NiAVObject> m_cPipBoyButtonAvailability[3];
    NiPointer<NiAVObject> spButtonGlow[3];
    NiPointer<NiGeometry> m_pGaugeObjects[3];
    float fKnobPositions[3];
    float fKnobTargets[3];
    float fKnobRates[3];
    float fTabKnobPositions[5];
    bool bScaledTexCoords;
    unsigned char layoutPadding145[3];
    float fScrollWheelCurrentRotation;
    float fScrollWheelTarget;
    bool bPipboyUp;
    unsigned char layoutPadding151[3];
    BSSoundHandle pBackgroundHum;
    bool b1stPersonLightOn;
    bool b3rdPersonLightOn;
    bool bLightEffectFading;
    unsigned char layoutPadding163[1];
    float fLightEffectFadeStartTime;
    float fLightEffectFadeTarget;
    bool bResetPipboyManager;
    unsigned char layoutPadding16D[3];
};
