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

    NiPointer<NiNode> spAtmosphere; // src: XBOX_RETAIL_PDB +0x8 (old: m_spAtmosphere)
    NiPointer<NiFogProperty> spFog; // src: XBOX_RETAIL_PDB +0xc (old: m_spFog)
    NiPointer<NiNode> spSkyQuadNode; // src: XBOX_RETAIL_PDB +0x10 (old: m_spSkyNode)
    NiPointer<NiNode> spSkyQuad; // src: XBOX_RETAIL_PDB +0x14 (old: m_spSkyShape)
    unsigned char bUpdateFogDistance; // src: XBOX_RETAIL_PDB +0x18 (old: unk18)
    unsigned char unk19[3];
};
