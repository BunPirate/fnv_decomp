#include "../../include/TESNPC.h"

// @fnv 0x005dd560
// pdb: TESNPC::ClearHead | TESScriptFunctions.obj | retail, call graph (shared callers), medium
void TESNPC::ResetFaceGen()
{
    m_pkSecondaryFaceGenNode = m_pkPrimaryFaceGenNode = 0;
}
