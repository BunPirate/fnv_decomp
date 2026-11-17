
// src/fallout_shared/bipedanim_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/bipedanim.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "../../include/NiFixedString.h"
#include "../../include/NiAVObject.h"
#include "../../include/NiExtraData.h"
#include "../../include/NiShader.h"
#include "../../include/NiNode.h"
#include "../../include/NiMaterialProperty.h"
#include "../../include/BSShaderProperty.h"
#include "../../include/NiCollisionObject.h"
#include "../../include/bhkBlendCollisionObject.h"
#include "../../include/NiGeometry.h"

extern int EmptyFS;
// @fnv 0x00a5bc40
// src: XBOX_RETAIL_PDB 0x00a5bc40
// pdb: NiObjectNET::AddExtraData | NiObjectNET.obj | retail, call graph (shared callers), high
// pdb params: kKey, pkExtra
bool NiAVObject::NiObjectNET_AddExtraData(const NiFixedString& kKey, NiExtraData* pkExtra)
{
    if ((int)kKey.m_kHandle == EmptyFS)
        return false;
    if (!pkExtra)
        return false;
    if (((NiShader*)pkExtra)->GetFilename().m_kHandle == (const char*)EmptyFS)
    {
        ((NiAVObject*)pkExtra)->SetName(kKey);
    }
    else
    {
        if (kKey.m_kHandle != ((NiShader*)pkExtra)->GetFilename().m_kHandle)
            return false;
    }
    return NiObjectNET_InsertExtraData((void*)pkExtra);
}

// @fnv 0x00b553d0
// src: COMMUNITY 0x00b553d0
// pdb: BSShaderManager::SetEmittanceRecurse | BSShaderManager.obj | retail, upstream name already matches, high
// pdb params: apObject, aColor
// pdb locals: pmatproperty, pgeometry, pshaderproperty, pnode, ucount, uindex, pchild
void __cdecl BSShaderManager_SetEmittanceRecurse(NiGeometry* apObject, NiPoint3* aColor)
{
    if (apObject == 0)
        return;

    if (static_cast<const NiObject*>(apObject)->IsGeometry() != 0)
    {
        NiProperty* pFirst = apObject->GetProperty(2);
        NiProperty* pSecond = apObject->GetProperty(3);

        if (pFirst != 0 && pSecond != 0)
        {
            NiMaterialProperty* pMaterial = (NiMaterialProperty*)pFirst;
            BSShaderProperty* pShader = (BSShaderProperty*)pSecond;

            if ((pShader->ulFlags[0] & 0x20000000u) <= 0)
                return;

            *(NiPoint3*)&pMaterial->m_emit = *aColor;
            ++pMaterial->m_uiRevID;
        }
        return;
    }

    NiNode* pNode = apObject->IsSceneNode();
    if (pNode == 0)
        return;

    unsigned int count = pNode->m_kChildren.m_usSize;
    for (unsigned int i = 0; i < count; ++i)
    {
        NiAVObject* pChild = pNode->m_kChildren.m_pBase[i].m_pObject;
        if (pChild != 0)
            BSShaderManager_SetEmittanceRecurse((NiGeometry*)pChild, aColor);
    }
}

NiAVObject* BSUtilities_GetObjectByName_00c4b310(NiAVObject* apScene, const char* apName, int bTestScenegraph);
NiAVObject* BSUtilities_GetObjectByName_00c4b470(NiAVObject* apScene, NiFixedString* apName, int bTestScenegraph);
struct AttachInfo
{
    void* m_data;
};

void WeaponObject_Constrain(void* abEnable, AttachInfo aOwnerFilter, NiAVObject* apFrom, NiAVObject* apTo, bool abDefaultKeyframed);

inline NiNode* NiAVObject::GetParent() const
{
    return m_pkParent;
}

static __forceinline NiAVObject* FindAttachParent(NiAVObject* obj, NiAVObject* root)
{
    NiAVObject* p = obj ? static_cast<const NiAVObject*>(obj)->GetParent() : 0;
    while (p)
    {
        NiCollisionObject* c = p->m_spCollisionObject.m_pObject;
        if (c && (!c->IsBhkBlendCollisionObject() || *(unsigned int*)&p->m_spCollisionObject.m_pObject->IsBhkBlendCollisionObject()->unk0C[4] != 0))
            break;
        if (p == root)
            break;
        p = static_cast<const NiAVObject*>(p)->GetParent();
    }
    if (p == root)
        return 0;
    return p;
}

// @fnv 0x00c89050
// src: XBOX_PDB 0x00c89050
// pdb: WeaponObject::UpdateConstraints | WeaponObject.obj | retail, string-set bridge, high
// pdb params: abEnable, aOwnerFilter, apRoot3d, abDefaultKeyframed
// pdb locals: pweaponBone, pbackpack, pweaponAttach, pbackpackAttach
void __stdcall WeaponObject_UpdateConstraints(void* abEnable, AttachInfo aOwnerFilter, NiAVObject* apRoot3d, bool abDefaultKeyframed)
{
    NiAVObject* obj = BSUtilities_GetObjectByName_00c4b310(apRoot3d, "Weapon", 0);
    NiAVObject* parent = FindAttachParent(obj, apRoot3d);
    if (obj && parent)
        WeaponObject_Constrain(abEnable, aOwnerFilter, obj, parent, abDefaultKeyframed);

    static NiFixedString kBackpack("Backpack");
    obj = BSUtilities_GetObjectByName_00c4b470(apRoot3d, &kBackpack, 0);
    parent = FindAttachParent(obj, apRoot3d);
    if (obj && parent)
        WeaponObject_Constrain(abEnable, aOwnerFilter, obj, parent, abDefaultKeyframed);
}

