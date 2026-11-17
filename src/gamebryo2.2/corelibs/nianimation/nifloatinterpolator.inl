
#include "nifloatinterpolator_decls.h"
// @fnv 0x0052ce40
// pdb: NiFloatInterpolator::ReplaceKeys | TESImageSpaceModifier.obj | retail, call graph, high
// pdb params: pkKeys, uiNumKeys, eType
void NiFloatInterpolator::SetAnimationKeys(TimedAnimationKey* pkKeys, unsigned int uiNumKeys, NiAnimationKey::KeyType eType)
{
    if (uiNumKeys > 0) {
        if (!m_spFloatData.operator->())
            m_spFloatData = new NiFloatData;
        m_spFloatData->ReplaceAnim(pkKeys, uiNumKeys, eType);
        m_uiLastIdx = 0;
    } else {
        if (m_spFloatData.operator->())
            m_spFloatData->ReplaceAnim(0, 0, NiAnimationKey::NOINTERP);
    }
}
