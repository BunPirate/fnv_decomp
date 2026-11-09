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

    NiPointer<NiNode> spMoonNode;
    NiPointer<NiNode> spShadowNode;
    NiPointer<NiTriShape> spMoonMesh;
    NiPointer<NiTriShape> spShadowMesh;
    BSStringT<char> strTextures[8];
    float fAngleFadeStart;
    float fAngleFadeEnd;
    float fAngleShadowEarlyFade;
    float fSpeed;
    float fZOffset;
    unsigned int iSize;
    UpdateStatus eUpdateMoonTexture;
    float fPos;
    float fLastPosUpdate;
};
