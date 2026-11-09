// gamebryo2.2/corelibs/nimain/console/niavobject_console.cpp: NiAVObject (1 function)
#include "../../../../../include/NiAVObject.h"
#include "../../../../../include/NiCollisionObject.h"
// @fnv 0x00a68c60
// pdb: NiAVObject::UpdateWorldData | NiAVObject_Xenon.obj | retail, upstream name already matches, high
// pdb params: UpdateData
void NiAVObject::UpdateWorldData(NiUpdateData& UpdateData)
{
    NiCollisionObject* pCollisionObject = m_spCollisionObject.m_pObject;
    if (pCollisionObject)
        pCollisionObject->Unk_24(UpdateData);
    else
        UpdateWorldLoc();
}
