// @fnv 0x00a11db0
// pdb: LEAPCORE::CGraphManager::Initialize | graphmgr.obj | retail, object-file run extension, low
// pdb note: debug build links it to NiTPointerListBase<NiTPointerAllocator<unsigned int>,BSSoundMessage *>::GetNext
// pdb locals: _ScopeTrace, hr
template <class K, class V>
void LocalPointerList<K, V>::NewItem(LocalPointerListItem<K, V>* pkItem)
{
    pkItem->m_pkNext = 0;
    pkItem->m_pkPrev = m_pkLastItem;
    if (m_pkLastItem)
        m_pkLastItem->m_pkNext = pkItem;
    else
        m_pkFirstItem = pkItem;
    m_pkLastItem = pkItem;
    m_uiCount++;
}
