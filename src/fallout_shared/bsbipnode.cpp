// fallout_shared/bsbipnode.cpp: AnimationInterpolatorNode (5 functions)

#include "bsbipnode_decls.h"
#include "../../include/NiUpdateData.h"

// @fnv 0x004f0380
// src: XBOX_RETAIL_PDB 0x004f0380
// pdb: BSTransCon::UpdateAllButTarget | BSBipNode.obj | retail, call graph, high
// pdb params: afTime, abSkipSelectiveUpdateTest
// pdb locals: isize, kTransform, pt, i
void AnimationInterpolatorNode::BSTransCon_UpdateAllButTarget(float afTime, bool abSkipSelectiveUpdateTest)
{
    if (!NiTimeController_GetActive() || !m_usNumInterps)
        return;

    int iIndex;
    NiAVObject* target;
    NiQuatTransform transform;
    // Cache the pass limit while the shared transform remains available.
    {
        const int lastIndex = m_usNumInterps - 1;
        for (iIndex = 0; iIndex < lastIndex; ++iIndex)
        {
            target = m_ppTargetObjects[iIndex];
            if (!target)
                continue;
            if (!abSkipSelectiveUpdateTest && !target->GetSelectiveUpdate())
                continue;
            else if (abSkipSelectiveUpdateTest && target->GetSelectiveUpdate())
                continue;

            if (m_pkBlendInterpolators[iIndex].UpdateTransform(afTime, target, transform))
            {
                if (transform.IsTranslateXNotNegatedConstant())
                    target->NiAVObject_SetTranslate(transform.GetTranslate());
                if (transform.IsRotateValid())
                    target->NiNode_SetRotate(transform.GetOffsetC());
                if (transform.IsScaleValid())
                    target->NiAVObject_SetScale(transform.GetFloatAtOffset1C());
            }
        }

        target = m_ppTargetObjects[iIndex];
        if (!target || (!abSkipSelectiveUpdateTest && !target->GetSelectiveUpdate()))
            return;
        if (m_pkBlendInterpolators[iIndex].UpdateTransform(afTime, target, transform))
        {
            if (transform.IsTranslateXNotNegatedConstant())
                target->NiAVObject_SetTranslate(transform.GetTranslate());
            if (transform.IsRotateValid())
                target->NiNode_SetRotate(transform.GetOffsetC());
            if (transform.IsScaleValid())
                target->NiAVObject_SetScale(transform.GetFloatAtOffset1C());
        }
    }
}

struct FUN_004f0000_shell : public NiAVObject
{
    bool NiAVObject_GetHasPropertyController();
};

struct FUN_00456630_helper
{
    bool NiAVObject_GetBit(unsigned int);
};

// @fnv 0x004f0000
// src: COMMUNITY 0x004f0000
// pdb: NiAVObject::QHasPropController | BSBipNode.obj | debug, object-file run extension, low
bool FUN_004f0000_shell::NiAVObject_GetHasPropertyController()
{
    return ((FUN_00456630_helper*)this)->NiAVObject_GetBit(0x40000);
}

struct FUN_004f00e0_shell : public NiAVObject
{
    void NiAVObject_SetWorldTranslate(void*);
};

// @fnv 0x004f00e0
// src: XBOX_PDB 0x004f00e0
// pdb: NiAVObject::SetWorldTranslate | BSBipNode.obj | debug, upstream name already matches, high
// pdb params: kTrn
void FUN_004f00e0_shell::NiAVObject_SetWorldTranslate(void* kTrn)
{
    *reinterpret_cast<NiPoint3*>(reinterpret_cast<char*>(this) + 0x8C) = *reinterpret_cast<const NiPoint3*>(kTrn);
}

extern int DAT_011f36bc;
extern int g_011f36e4;
struct FUN_004f0040_shell
{
    void UpdateControls(float afTime);
};

// @fnv 0x004f0040
// pdb: BSBipNode::AdjustPos | BSBipNode.obj | debug, object-file run extension, low
// pdb params: apObject, arDelta
// pdb locals: pnode, I
void FUN_004f0040_shell::UpdateControls(float afTime)
{
    NiTimeController* pkControl;
    for (pkControl = ((NiObjectNET*)this)->GetControllers(); pkControl; pkControl = pkControl->GetNext())
    {
        if (pkControl->GetRTTI() == reinterpret_cast<const NiRTTI*>(&DAT_011f36bc))
        {
            ((AnimationInterpolatorNode*)pkControl)->BSTransCon_UpdateAllButTarget(afTime, false);
        }
        else if (pkControl->GetRTTI() == reinterpret_cast<const NiRTTI*>(&g_011f36e4))
        {
            NiUpdateData updateData(afTime, false, false);
            pkControl->Update(updateData);
        }
    }
}

__declspec(thread) int DAT_tls_0x2c0;

// @fnv 0x004f0020
// src: XBOX_PDB 0x004f0020
void bhkNiCollisionObject_SetSyncMode(int value)
{
    DAT_tls_0x2c0 = value;
}
