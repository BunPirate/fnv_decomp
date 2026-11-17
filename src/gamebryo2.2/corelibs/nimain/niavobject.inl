
#include "niavobject_types.h"

// @fnv 0x004eff50
// pdb: NiAVObject::UpdateObjectControllers | BSBipNode.obj | retail, call graph, high
// pdb params: UpdateData, bProperties
// pdb locals: pkControl, kPos, pkProperty
void NiAVObject::UpdateTimeControllers(NiUpdateData& UpdateData, bool bProperties)
{
    NiTimeController* controller;
    if (bProperties && GetHasPropertyController()) {
        void* position = m_kPropertyList.GetHeadPos();
        while (position) {
            NiProperty* property = m_kPropertyList.GetNext(position);
            if (property && property->GetControllers())
                property->Update(UpdateData);
        }
    }
    for (controller = GetControllers(); controller; controller = controller->GetNext())
        controller->Update(UpdateData);
}

// @fnv 0x005467e0
// pdb: NiAVObject::CreateBoundIfNone | TESObjectCELL.obj | retail, call graph (shared callers), high
void NiAVObject::EnsureWorldBound()
{
    if (!m_kWorldBound) {
        SetObjectBound(new FourComponentFloatVector(0x100, 0));
        m_kWorldBound->SetCenterAndRadius(NiPoint3::ZERO, 0.0f);
    }
}
