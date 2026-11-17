#pragma once

// FOHUDEffectManager: the HUD screen effects (shudder, blur, scanlines), no vtable. InterfaceManager holds it by value
// at +0x178 with the next member at +0x1dc, so 0x64 bytes. The constructor 0x007f7610 constructs the NiPointer at
// +0x00, the BGSMenuPacker at +0x04 (0x007002d0) and the NiPoint2s at +0x30/+0x38/+0x40/+0x48, news the 0x88-byte
// ImageSpaceShaderParam into +0x50 (0x00b8a9e0), clears +0x28/+0x54/+0x55/+0x56 and reads three settings into
// +0x5c/+0x60/+0x58. TriggerShudder 0x007f7880/0x007f78f0 and UpdateShudder 0x007f7970 use +0x28..+0x4c;
// SetBlurRadiusHUD 0x005bfbb0 writes +0x58, SetBlurIntensityHUD 0x005bfbd0 writes +0x60.

#include "BGSMenuPacker.h"
#include "NiPoint2.h"
#include "NiPointer.h"

class ImageSpaceShaderParam;
class NiRefObject;

// pdb: class FOHUDEffectManager, size 0x64, 13 members
class FOHUDEffectManager
{
public:
    NiPointer<NiRefObject> spPartialScreenGeometry;              // 0x00 pointee type not established // src: XBOX_RETAIL_PDB +0x0 (old: spEffect)
    BGSMenuPacker Packer;                    // 0x04 // src: XBOX_RETAIL_PDB +0x4 (old: kMenuPacker)
    bool bShudderActive;                          // 0x28
    float fShudderStartTime;                      // 0x2c
    NiPoint2 ShudderDuration;                    // 0x30 // src: XBOX_RETAIL_PDB +0x30 (old: kShudderDuration)
    NiPoint2 ShudderIntensity;                    // 0x38 // src: XBOX_RETAIL_PDB +0x38 (old: kShudderStrength)
    NiPoint2 ShudderFrequency;                   // 0x40 // src: XBOX_RETAIL_PDB +0x40 (old: kShudderFrequency)
    NiPoint2 ShudderCurrentPosition;                      // 0x48 // src: XBOX_RETAIL_PDB +0x48 (old: kShudderOffset)
    ImageSpaceShaderParam* pUnpackShaderParams;          // 0x50 // src: XBOX_RETAIL_PDB +0x50 (old: pShaderParam)
    bool bHideHUD;                                 // 0x54 // src: XBOX_RETAIL_PDB +0x54 (old: bFlag54)
    bool bFlag55;                                 // 0x55
    bool bFlag56;                                 // 0x56
    float fCurrentBlurRadiusHUD;                            // 0x58 // src: XBOX_RETAIL_PDB +0x58 (old: fBlurRadius)
    float fCurrentScanlineFrequencyHUD;                     // 0x5c // src: XBOX_RETAIL_PDB +0x5c (old: fScanlineFrequency)
    float fCurrentBlurIntensityHUD;                         // 0x60 // src: XBOX_RETAIL_PDB +0x60 (old: fBlurIntensity)

    FOHUDEffectManager();                         // 0x007f7610
    void OnIdle();                                // 0x007f7830
    void UpdateShudder();                         // 0x007f7970
    void SetBlurRadiusHUD(float);                 // 0x005bfbb0
    void SetBlurIntensityHUD(float);              // 0x005bfbd0
};
