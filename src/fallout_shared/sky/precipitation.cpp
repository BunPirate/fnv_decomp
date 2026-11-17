// fallout_shared/sky/precipitation.cpp: Precipitation (6 functions)

#include "../../../include/NiNode.h"
#include "../../../include/NiSortAdjustNode.h"
#include "../../../include/NiUpdateData.h"
#include "../../../include/Precipitation.h"
#include "precipitation_decls.h"
int BSstricmp(const char*, const char*);
// @fnv 0x00636c40
// pdb: Precipitation::Load | Precipitation.obj | retail, string-set bridge, high
// pdb params: apPrecipNIF
void Precipitation::Load(const char* apFilename)
{
    if (spCurrentPrecipRoot)
    {
        pParent->RemoveObject(spCurrentPrecipRoot);
        spLastPrecipRoot = spCurrentPrecipRoot;
        pParent->AttachChildInAvailableSlot(static_cast<NiAVObject*>(static_cast<NiNode*>(spLastPrecipRoot)), true);
        spCurrentPrecipRoot = 0;
    }
    if (apFilename && *apFilename)
    {
        NiNode* model = g_modelLoader->LoadFile(apFilename, ENUM_LOD_MULT_LOD_MULT_NONE, true, false, false, false);
        if (model)
        {
            bool bIsSnow = BSstricmp(apFilename, DAT_0104ed9c) == 0;
            NiUpdateData kUpdateData(0.0f, false, false);
            model->UpdateDownwardPass(kUpdateData, 0);
            spCurrentPrecipRoot = new NiSortAdjustNode(0);
            fBirthRate = 0.0f;
            for (unsigned int index = 0; index < model->NiNode_GetChildCount(); ++index)
            {
                NiAVObject* m_pShaderGeometry = model->FUN_0043b4a0(index)->IsSceneNode();
                SkyShaderProperty* pShaderProperty =
                    m_pShaderGeometry ? NiObject_DynamicCast(&DAT_012024e0, m_pShaderGeometry->NiNode_GetAtChecked(false)) : 0;
                if (!pShaderProperty)
                    continue;
                NiAVObject* precipParticle = CreateShaderGeometry(pShaderProperty, pParent->NiAVObject_GetWorldRotate(bIsSnow));
                if (precipParticle)
                    static_cast<NiNode*>(spCurrentPrecipRoot)->AttachChildInAvailableSlot(precipParticle, true);
            }
            pParent->AttachChildInAvailableSlot(static_cast<NiAVObject*>(static_cast<NiNode*>(spCurrentPrecipRoot)), true);
            static_cast<NiNode*>(spCurrentPrecipRoot)->UpdateSceneObject();
        }
    }
}

NiAVObject* __cdecl TESMain_GetWeatherRoot(void);

// @fnv 0x00636bb0
void Precipitation::InitParent()
{
    pParent = static_cast<NiNode*>(TESMain_GetWeatherRoot());
}

// @fnv 0x00637800
// pdb: Precipitation::FlushAll | Precipitation.obj | retail, upstream name already matches, high
void Precipitation::FlushAll()
{
    if (spLastPrecipRoot.operator NiNode*())
    {
        pParent->RemoveObject(static_cast<NiAVObject*>(spLastPrecipRoot.operator NiNode*()));
        spLastPrecipRoot = static_cast<NiNode*>(0);
    }
    if (spCurrentPrecipRoot.operator NiNode*())
    {
        pParent->RemoveObject(static_cast<NiAVObject*>(spCurrentPrecipRoot.operator NiNode*()));
        spCurrentPrecipRoot = static_cast<NiNode*>(0);
    }
}

void _Deallocate(void*);
// Destroys the object, frees it when requested, and returns its address.
// @fnv 0x00636af0
// pdb: Precipitation::`scalar deleting destructor' | Precipitation.obj | retail, vtable slot, high
void* Precipitation::DestroyIfFlagged(unsigned int flags)
{
    this->Precipitation::~Precipitation();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct PrecipQueuedObject
{
    virtual void vfn_0000();
    virtual void vfn_0004();
    virtual void vfn_0008();
    virtual void vfn_000c();
    virtual void vfn_0010();
    virtual void* vfn_0014(int a0, int a1, int a2, int a3, int a4, int a5);

    int FUN_0048cee0();
};

struct PrecipManager
{
    void ModelLoader_QueueModel_00444040(void* apModelFileName);
};

extern PrecipManager* DAT_011c3b3c;

// @fnv 0x00636bd0
// pdb: Precipitation::Load | Precipitation.obj | debug, object-file run extension, low
// pdb params: apPrecipNIF
void Precipitation::QueuePrecipitationObject(PrecipQueuedObject* object)
{
    if (spLastPrecipRoot.operator NiNode*())
        return;

    if (object != 0 && object->FUN_0048cee0() != 0)
    {
        DAT_011c3b3c->ModelLoader_QueueModel_00444040(object->vfn_0014(0, 0, 0, 0, 0, 0));
        pQueuedModel = object;
    }
    else
        Load(0);
}

// Release both handles and clear the cached object before destroying the members.
// @fnv 0x00636b20
// pdb: Precipitation::~Precipitation | Precipitation.obj | retail, upstream name already matches, high
Precipitation::~Precipitation()
{
    spCurrentPrecipRoot = static_cast<NiNode*>(0);
    spLastPrecipRoot = static_cast<NiNode*>(0);
    pQueuedModel = 0;
}
