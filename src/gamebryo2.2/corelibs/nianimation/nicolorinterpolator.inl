// @fnv 0x0052cff0
// src: XBOX_RETAIL_PDB 0x0052cff0
// pdb: NiColorInterpolator::ReplaceKeys | TESImageSpaceModifier.obj | retail, call graph, high
// pdb params: pkKeys, uiNumKeys, eType
void NiColorInterpolator::ReplaceKeys(ColorAnimationKey* pkKeys, unsigned int uiNumKeys, NiAnimationKey::KeyType eType)
{
    if (uiNumKeys > 0)
    {
        if (!m_spColorData.operator->())
            m_spColorData = new NiColorData;
        m_spColorData->ReplaceAnim(pkKeys, uiNumKeys, eType);
        m_uiLastIdx = 0;
    }
    else if (m_spColorData.operator->())
        m_spColorData->ReplaceAnim(0, 0, NiAnimationKey::NOINTERP);
}
