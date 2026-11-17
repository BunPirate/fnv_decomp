
#include "bssimplelist_decls.h"

// Reusable definitions from bscore/bssimplelist.inl. Explicit pointer-list
// instantiations below select the original linker-folded bodies.

// @fnv 0x0096a2d0
template<class T> BSSimpleList<T>::BSSimpleList()
    : m_item(0), m_pkNext(0)
{
}

// @fnv 0x00470440
// pdb: NiTMapBase<NiTPointerAllocator<unsigned int>,TESForm *,bool>::`scalar deleting destructor' | TESDataHandler.obj | debug, object-file run extension, low
template<class T> BSSimpleList<T>::BSSimpleList(T& item)
    : m_item(item), m_pkNext(0)
{
}

// @fnv 0x00905820
// pdb: BSSimpleList<VATS_COMMAND *>::AddTail | VATS.obj | retail, call graph, low
// pdb note: debug build links it to BSSimpleList<ExtraFollowerSwimBreadcrumb *>::AddTail
// pdb params: item
// pdb locals: pkCur
template<class T> void BSSimpleList<T>::AddTail(T& item)
{
    if (!item)
        return;
    BSSimpleList<T>* tail = this;
    while (tail->m_pkNext)
        tail = tail->m_pkNext;
    if (tail->m_item)
        tail->m_pkNext = new BSSimpleList<T>(item);
    else
        tail->m_item = item;
}

// @fnv 0x006815c0
template<class T> T& BSSimpleList<T>::GetItem()
{
    return m_item;
}

// @fnv 0x00726070
// pdb: BSstrcat | EffectItemList.obj | debug, call graph, medium
// pdb params: apString1, aiSize, apString2
template<class T> BSSimpleList<T>* BSSimpleList<T>::GetNext()
{
    return m_pkNext;
}

// @fnv 0x008256d0
// pdb: BSSimpleList<SpellDispelData *>::~BSSimpleList<SpellDispelData *> | MagicTarget.obj | debug, object-file run extension, low
template<class T> bool BSSimpleList<T>::IsEmpty()
{
    return !m_pkNext && !m_item;
}

// @fnv 0x00470470
// pdb: BSSimpleList<VATS_COMMAND *>::RemoveAll | VATS.obj | retail, call graph, medium
// pdb locals: pkSave
template<class T> void BSSimpleList<T>::RemoveAll()
{
    while (m_pkNext)
    {
        BSSimpleList<T>* next = m_pkNext->m_pkNext;
        m_pkNext->m_pkNext = 0;
        delete m_pkNext;
        m_pkNext = next;
    }
    m_item = 0;
}

// @fnv 0x0046ffb0
template<class T> BSSimpleList<T>::~BSSimpleList()
{
    RemoveAll();
}

// @fnv 0x005ae3d0
template<class T> void BSSimpleList<T>::AddHead(T& item)
{
    if (!item)
        return;
    if (m_item)
    {
        BSSimpleList<T>* node = new BSSimpleList<T>(m_item);
        node->m_pkNext = m_pkNext;
        m_pkNext = node;
        m_item = item;
    }
    else
        m_item = item;
}

// @fnv 0x0063f7b0
template<class T> void BSSimpleList<T>::RemoveHead()
{
    if (m_pkNext)
    {
        BSSimpleList<T>* node = m_pkNext;
        m_pkNext = node->m_pkNext;
        m_item = node->m_item;
        node->m_pkNext = 0;
        delete node;
    }
    else
        m_item = 0;
}

template class BSSimpleList<InventoryStackRecord*>;

#include "bssimplelist_packet.h"
// @fnv 0x00413f40
// pdb: NiFixedString::operator char const * | ModelLoader.obj | debug, call graph, medium
BSSimpleList<TESTopic*>* TESTopicInfoData::GetLinkToList() { return &m_kLinkToList; }
// @fnv 0x00500940
PerkEntryConditionSet* BGSCameraPath::GetConditions() { return &Conditions; }
// @fnv 0x00891170
BSSimpleList<BGSCameraShot*>* BGSCameraPath::GetShotList() { return &ShotList; }
// @fnv 0x005a7be0
// pdb: TESRecipeComponent::TESRecipeComponent | TESRecipe.obj | debug, call graph, high
QuantityData::QuantityData() { SetQuantity(0); }
// @fnv 0x00519550
// pdb: TESObjectDOOR::ClearRandomTeleportList | TESObjectDOOR.obj | debug, upstream name already matches, high
void TESObjectDOOR::ClearRandomTeleportList() { reinterpret_cast<BSSimpleList<ActorCause*>*>(&m_kRandomTeleportTargets)->RemoveAll(); }
// @fnv 0x00944460
// pdb: RandomInt | TESRegionDataSound.obj | debug, call graph, medium
// pdb params: aiMin, aiMax
unsigned int GetRandomNumberInRange(int min, int max) { return MersenneTwister::GetRandomGenerator()->IntInRange(min,max); }
// @fnv 0x005e7790
// pdb: BGSHeadPart::AddExtraPart | BGSHeadPart.obj | debug, upstream name already matches, high
// pdb params: apPart
void BGSHeadPart::AddExtraPart(BGSHeadPart* apPart) { reinterpret_cast<BSSimpleList<SpellItem*>*>(&ExtraParts)->AddHead(reinterpret_cast<SpellItem*&>(apPart)); }
// @fnv 0x004b0680
template <> BSSimpleList<TESWeather::WeatherSound*>::BSSimpleList(TESWeather::WeatherSound* item, BSSimpleList* next) : m_item(item),m_pkNext(next) {}
// @fnv 0x00501170
// pdb: BGSTerminal::AddMenuItem | BGSTerminal.obj | debug, upstream name already matches, high
// pdb params: apItem
void BGSTerminal::AddMenuItem(TerminalMenuItem* apItem) { if(apItem) reinterpret_cast<BSSimpleList<ScriptVariableInfo*>*>(&m_kMenuItems)->AddTail(reinterpret_cast<ScriptVariableInfo* const&>(apItem)); }

// @fnv 0x006130e0
BSSimpleList<TESClass*>* TESDataHandler::GetTESClassList() { return reinterpret_cast<BSSimpleList<TESClass*>*>(listClasses); }

// @fnv 0x00500a20
// src: COMMUNITY 0x00500a20
void InterfaceManager::BGSTerminal_SetPassword(Tile* tile) { *reinterpret_cast<Tile**>(reinterpret_cast<char*>(this)+160) = tile; }
