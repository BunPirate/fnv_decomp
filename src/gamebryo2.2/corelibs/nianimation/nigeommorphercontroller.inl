
#include "nigeommorphercontroller_decls.h"
// @fnv 0x00a3b460
// src: XBOX_RETAIL_PDB 0x00a3b460
// pdb: NiGeomMorpherController::AllocateInterpArray | NiGeomMorpherController.obj | retail, object-file gap fill, high
void NiGeomMorpherController::AllocateInterpArray()
{
    delete[] m_pkInterpItems;
    m_pkInterpItems = 0;
    if (m_spMorphData && m_spMorphData->m_uiNumTargets > 0)
        m_pkInterpItems = new InterpItem[m_spMorphData->m_uiNumTargets];
}
