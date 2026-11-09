// fallout_shared/sky/clouds.cpp: Clouds (10 functions)

#include "clouds_decls.h"
#include "../../../include/Sky.h"
#include "../../../include/NiPoint3.h"

// @fnv 0x00634110
// pdb: Clouds::Update | Clouds.obj | retail, upstream name already matches, high
// pdb params: apSky, afSecondsPassed
// pdb locals: pLastWeather, pCurrentWeather, i, pshadeProperty, fdelta, fCloudSpeed, kcolor, strfilename, ptestexture, pprop, spTex, ptex, pskyprop
void Clouds::Update(Sky* apSky, float afSecondsPassed)
{
    SkyObject::Update(apSky, afSecondsPassed);
    TESWeather* m_pWeatherObject = apSky->TESMain_GetThread();
    TESWeather* m_pPreviousWeather = apSky->FUN_00825c00();
    if (!m_pWeatherObject)
        return;
    for (int i = 0; i < GetOffset58(); ++i)
        if (!spClouds[i])
            return;
    if (apSky->Sky_GetMode() == 3 || apSky->Sky_GetMode() == 2)
    {
        for (int i = 0; i < GetOffset58(); ++i)
        {
            float speed;
            float delta;
            CloudsColorController* controller =
                (!spClouds[i]->FUN_0050d100()->GetControllers()
                     ? false
                     : spClouds[i]->FUN_0050d100()->GetControllers()->FUN_00441110() == 13)
                    ? (CloudsColorController*)spClouds[i]->FUN_0050d100()->GetControllers()
                    : 0;
            if (controller)
            {
                NiColor color = GetPointAt(i);
                controller->color = NiColorA(color.r, color.g, color.b, 1.0f);
            }
            speed = m_pWeatherObject->GetCloudLayerSpeed(i, DAT_011cca6c.Float()->f, 0.0f);
            if (m_pPreviousWeather)
            {
                speed *= apSky->Sky_GetCurrentWeatherPct();
                speed += (1.0f - apSky->Sky_GetCurrentWeatherPct()) *
                         m_pPreviousWeather->GetCloudLayerSpeed(i, DAT_011cca6c.Float()->f, 0.0f);
            }
            delta = apSky->GetFieldCC() * afSecondsPassed * speed;
            AddToFloatArray((unsigned short)i, delta);
        }
    }
    if (apSky->GetWeatherUpdateFlag() || bForceUpdate)
    {
        bForceUpdate = false;
        if (m_pPreviousWeather)
        {
            for (int i = 0; i < GetOffset58(); ++i)
            {
                BSStringT<char> path;
                SkyShaderProperty* property = (SkyShaderProperty*)spClouds[i]->GetProperty(3);
                TESTexture1024* pkTexture = m_pWeatherObject->GetCloudTexture(i);
                if (pkTexture && pkTexture->GetModelLength())
                {
                    path = pkTexture->GetTextureResourcePath();
                    path += pkTexture->GetTextureResourceName();
                    apSky->GetTextureManager();
                    SkyTextureManager::LoadTextureInBackground(&spTransTexture[i], path);
                }
                else
                    spTransTexture[i] = 0;
            }
        }
        else if (apSky->Sky_GetMode() == 3 || apSky->Sky_GetMode() == 2)
        {
            for (int i = 0; i < GetOffset58(); ++i)
            {
                BSStringT<char> path;
                SkyShaderProperty* property = (SkyShaderProperty*)spClouds[i]->GetProperty(3);
                TESTexture1024* pkTexture = m_pWeatherObject->GetCloudTexture(i);
                if (pkTexture && pkTexture->GetModelLength())
                {
                    path = pkTexture->GetTextureResourcePath();
                    path += pkTexture->GetTextureResourceName();
                    NiPointer<NiTexture> loaded = 0;
                    BSShaderManager::GetTexture(path, true, loaded, true, false);
                    NiTexture* raw = loaded;
                    if (raw)
                    {
                        property->SetBaseMap(raw);
                        property->SetTextureFile(NiFixedString(path));
                        property->SkyShaderProperty_SetBlendValue(0.0f);
                    }
                }
            }
        }
    }
    for (int i = 0; i < GetOffset58(); ++i)
    {
        SkyShaderProperty* property;
        NiProperty* baseProperty = spClouds[i]->GetProperty(3);
        property = NiObject_DynamicCast(&SkyShaderProperty_ms_RTTI, baseProperty);
        if (spTransTexture[i])
        {
            if (property)
            {
                property->NiPhysXProp_SetSnapshot(spTransTexture[i]);
                property->SkyShaderProperty_SetBlendValue(apSky->Sky_GetCurrentWeatherPct());
            }
            if (!m_pPreviousWeather)
            {
                property->SetBaseMap(spTransTexture[i]);
                spTransTexture[i] = 0;
                property->NiPhysXProp_SetSnapshot(0);
                property->SkyShaderProperty_SetBlendValue(0.0f);
            }
        }
        spClouds[i]->FUN_00450f90(!property || !property->BGSCameraShot_GetImagespaceTarget());
    }
}

// Loads Clouds.nif, attaches its 3D to parent, adds each geometry child to the cloud node, and sets the layer count.
// @fnv 0x00633ed0
// pdb: Clouds::Initialize | Clouds.obj | retail, string-set bridge, high
// pdb params: apSkyRoot
// pdb locals: stream, model, inumlayers, pnode, inumchildren, i
void Clouds::Initialize(NiNode* apSkyRoot)
{
    SkyObject::Initialize(apSkyRoot);
    BSStream stream;
    if (stream.BSStream_Load("Meshes\\Sky\\Clouds.nif", false))
    {
        Model kModel("Meshes\\Sky\\Clouds.nif", &stream, false, false);
        struct LayerBuild
        {
            int layers;
            NiNode* root;
            int children;
        } build;
        build.root = kModel.GetObject3D();
        apSkyRoot->AttachChildInAvailableSlot((NiAVObject*)(NiNode*)spRoot, true);
        build.layers = 0;
        build.children = build.root->NiNode_GetChildCount();
        for (int i = 0; i < build.children; ++i)
        {
            if (build.root->FUN_0043b4a0(i)->IsGeometry())
            {
                spClouds[i] = (NiGeometry*)build.root->FUN_0043b4a0(i);
                spRoot->AttachChildInAvailableSlot((NiAVObject*)(NiGeometry*)spClouds[i], true);
                ++build.layers;
            }
        }
        SetCloudCount(build.layers);
    }
}

// @fnv 0x006340e0
// pdb: Clouds::SetNumLayers | Clouds.obj | debug, object-file gap fill, medium
// pdb params: aiNumLayers
void Clouds::SetCloudCount(int count)
{
    if (count > 4)
        count = 4;
    usNumLayers = (unsigned short)count;
}

// @fnv 0x00634870
// src: XBOX_PDB 0x00634870
bool Sky::GetWeatherUpdateFlag()
{
    return (0 < (uiFlags & 3));
}

// @fnv 0x00634890
SkyTextureManager* Sky::GetTextureManager()
{
    return &SkyController;
}

// Assigns the fixed string to the cloud texture path at offset 0x74.
// @fnv 0x00634900
// src: XBOX_PDB 0x00634900
// pdb: SkyShaderProperty::SetTextureFile | Clouds.obj | debug, upstream name already matches, high
// pdb params: aFilename
void SkyShaderProperty::SetTextureFile(const NiFixedString& aFilename)
{
    *(BSStringT<char>*)((char*)this + 0x74) = aFilename;
}

// @fnv 0x009c8680
// src: XBOX_PDB 0x009c8680
// pdb: BGSCameraShot::GetImagespaceTarget | VATS.obj | debug, upstream name already matches, high
NiTexture* SkyShaderProperty::BGSCameraShot_GetImagespaceTarget()
{
    return (NiTexture*)((BSStringT<char>*)((char*)this + 0x70))->operator const char*();
}

// @fnv 0x00633e00
void __fastcall InitializeCloudColor(NiColor* color)
{
    reinterpret_cast<NiPoint3*>(color)->Set(0.0f, 0.0f, 0.0f);
}

// The shared Clouds interface does not yet declare the geometry reset method.
void __fastcall ClearCloudGeometry(Clouds*);

// @fnv 0x00633e30
// pdb: Clouds::~Clouds | Clouds.obj | retail, upstream name already matches, high
Clouds::~Clouds()
{
    ClearCloudGeometry(this);
    ClearCloudLayers();
}
