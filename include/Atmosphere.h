#pragma once

#include "SkyObject.h"
#include "NiFogProperty.h"

// pdb: class Atmosphere, size 0x1c, bases: SkyObject, 5 members
class Atmosphere : public SkyObject
{
public:
    Atmosphere();
    virtual ~Atmosphere();
    virtual void Update(Sky* pWeatherSky, float fSeconds);
    virtual void Init2(NiNode* pRoot, int arg);

    void SetAtmosphere(NiNode* apSkyRoot, NiFogProperty* apFog);
    void CreateSortAdjustNode(NiNode* apSkyRoot);
    void UpdateAtmosphere(Sky* apSky, float afSecondsPassed);
    void FUN_008d0600(Sky* pWeatherSky, float fSeconds);

    void FUN_00633190();
    void LoadGeometry(void*);

    NiPointer<NiNode> spAtmosphere;
    NiPointer<NiFogProperty> spFog;
    NiPointer<NiNode> spSkyQuadNode;
    NiPointer<NiNode> spSkyQuad;
    unsigned char bUpdateFogDistance;
    unsigned char unk19[3];
};
