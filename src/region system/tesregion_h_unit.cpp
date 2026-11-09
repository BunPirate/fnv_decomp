
#include "../../include/NiColor.h"
#include "../../include/TESRegion.h"

// @fnv 0x005d8a70
// pdb: Script::ClearScreenSplatter | TESScriptFunctions.obj | retail, object-file run extension, low
// pdb params: apParameters, apCompiledParams, apRefObject, apContainer, apScript, apScriptLocals, afReturnValue, auiOffset
inline NiColor* TESRegion::GetDiffuseColor()
{
    return reinterpret_cast<NiColor*>(&m_kDiffuseColor);
}

void TESRegion_UnitReference()
{
    TESRegion* pRegion = 0;
    NiColor* pColor = pRegion->GetDiffuseColor();
    (void)pColor;
}
