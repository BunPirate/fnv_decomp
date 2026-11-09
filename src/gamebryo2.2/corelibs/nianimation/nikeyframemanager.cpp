// gamebryo2.2/corelibs/nianimation/nikeyframemanager.cpp: NiGeomMorpherController (1 function)

#include "../../../../include/NiGeomMorpherController.h"

// NiMorphData's shared declaration does not yet expose its target-count getter.
unsigned int __fastcall GetMorphTargetCount(NiMorphData* pkMorphData);

// @fnv 0x008d3ed0
// pdb: NiGeomMorpherController::GetNumTargets | Character.obj | debug, upstream name already matches, high
unsigned int NiGeomMorpherController::GetNumTargets() const
{
    return m_spMorphData.operator->()
               ? GetMorphTargetCount(m_spMorphData.operator->())
               : 0;
}
