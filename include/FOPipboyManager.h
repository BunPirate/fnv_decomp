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

    NiPointer<NiNode> spPipboyRoot; // src: XBOX_RETAIL_PDB +0xd8 (old: m_pPipBoyObject0)
    NiPointer<NiNode> sp3rdPersonPipboyRoot; // src: XBOX_RETAIL_PDB +0xdc (old: m_pPipBoyObject1)
    NiPointer<NiAVObject> sp3rdPersonScreen; // src: XBOX_RETAIL_PDB +0xe0 (old: m_pPipBoyObject2)
    NiPointer<NiScreenElements> spPartialScreenGeometry; // src: XBOX_RETAIL_PDB +0xe4 (old: m_pScreenGeometry)
    NiPointer<NiAVObject> m_cPipBoyButtonAvailability[3];
    NiPointer<NiAVObject> spButtonGlow[3]; // src: XBOX_RETAIL_PDB +0xf4 (old: m_pButtonGlowObjects)
    NiPointer<NiGeometry> m_pGaugeObjects[3];
    float fKnobPositions[3]; // src: XBOX_RETAIL_PDB +0x10c (old: m_fChartFirstPoint)
    float fKnobTargets[3]; // src: XBOX_RETAIL_PDB +0x118 (old: m_fChartSecondPoint)
    float fKnobRates[3]; // src: XBOX_RETAIL_PDB +0x124 (old: m_fGaugeValues2)
    float fTabKnobPositions[5]; // src: XBOX_RETAIL_PDB +0x130 (old: m_fTabKnobPositions)
    bool bScaledTexCoords; // src: XBOX_RETAIL_PDB +0x144 (old: m_bUseMenuImageSpaceEffects)
    unsigned char layoutPadding145[3];
    float fScrollWheelCurrentRotation; // src: XBOX_RETAIL_PDB +0x148 (old: m_fPipBoyAlpha)
    float fScrollWheelTarget; // src: XBOX_RETAIL_PDB +0x14c (old: m_fPipBoyTargetAlpha)
    bool bPipboyUp; // src: XBOX_RETAIL_PDB +0x150 (old: m_bPipBoyFadeActive)
    unsigned char layoutPadding151[3];
    BSSoundHandle pBackgroundHum; // src: XBOX_RETAIL_PDB +0x154 (old: m_kPipBoyLightData)
    bool b1stPersonLightOn;
    bool b3rdPersonLightOn;
    bool bLightEffectFading; // src: XBOX_RETAIL_PDB +0x162 (old: m_bPipBoyLightOn)
    unsigned char layoutPadding163[1];
    float fLightEffectFadeStartTime; // src: XBOX_RETAIL_PDB +0x164 (old: m_fFirstPersonLightIntensity)
    float fLightEffectFadeTarget; // src: XBOX_RETAIL_PDB +0x168 (old: m_fThirdPersonLightIntensity)
    bool bResetPipboyManager; // src: XBOX_RETAIL_PDB +0x16c (old: m_bPipBoyLightEnabled)
    unsigned char layoutPadding16D[3];
};
