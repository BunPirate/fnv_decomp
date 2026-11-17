#include "../../../../include/NiFloatData.h"
#include "../../../../include/NiLODData.h"

// @fnv 0x0052cf30
// pdb: NiFloatData::NiFloatData | TESImageSpaceModifier.obj | retail, upstream name already matches, high
NiFloatData::NiFloatData()
    : NiObject()
    , m_uiNumKeys(0)
    , m_pkKeys(0)
    , m_eType(NiAnimationKey::NOINTERP)
    , m_ucKeySize(0)
{
}
