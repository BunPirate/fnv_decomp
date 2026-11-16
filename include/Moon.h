#pragma once

#include "SkyObject.h"
#include "NiTriShape.h"
#include "TESFullName.h"

class Sky;

// pdb: class Moon, size 0x7c, bases: SkyObject, 14 members
class Moon : public SkyObject
{
public:
    enum UpdateStatus
    {
        US_NOT_REQUIRED = 0,
        US_WHEN_CULLED = 1,
        US_INITIALIZE = 2
    };

    Moon(const char* apMoonName, float afAngleFadeStart, float afAngleFadeEnd, float afAngleShadowEarlyFade,
         float afSpeed, float afZOffset, unsigned int aiSize);
    virtual ~Moon();
    virtual void Initialize(NiNode* apSkyRoot, const char* apName);
    virtual void Update(Sky* sky, float elapsed);

    static bool IsMoonVisible(const Sky* sky);
    float GetMoonVisibility();
    float GetMoonShadowVisibility();

    NiPointer<NiNode> spMoonNode; // src: XBOX_RETAIL_PDB +0x8 (old: m_pMoonNode)
    NiPointer<NiNode> spShadowNode; // src: XBOX_RETAIL_PDB +0xc (old: m_pMoonShadowNode)
    NiPointer<NiTriShape> spMoonMesh; // src: XBOX_RETAIL_PDB +0x10 (old: m_pMoonShape)
    NiPointer<NiTriShape> spShadowMesh; // src: XBOX_RETAIL_PDB +0x14 (old: m_pMoonShadowShape)
    BSStringT<char> strTextures[8]; // src: XBOX_RETAIL_PDB +0x18 (old: m_kMoonTexturePaths)
    float fAngleFadeStart; // src: XBOX_RETAIL_PDB +0x58 (old: m_fFadeStartAngle)
    float fAngleFadeEnd; // src: XBOX_RETAIL_PDB +0x5c (old: m_fFadeEndAngle)
    float fAngleShadowEarlyFade; // src: XBOX_RETAIL_PDB +0x60 (old: m_fFadeAngleRange)
    float fSpeed;
    float fZOffset; // src: XBOX_RETAIL_PDB +0x68 (old: m_fGlyphVerticalOffset)
    unsigned int iSize;
    UpdateStatus eUpdateMoonTexture; // src: XBOX_RETAIL_PDB +0x70 (old: m_eUpdateStatus)
    float fPos;
    float fLastPosUpdate; // src: XBOX_RETAIL_PDB +0x78 (old: m_fValue)
};
