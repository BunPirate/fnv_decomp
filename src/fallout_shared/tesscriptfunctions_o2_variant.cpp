
// src/fallout_shared/tesscriptfunctions_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/tesscriptfunctions.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "../../include/BGSListForm.h"
#include "../../include/NiTexturingProperty.h"
#include "../../include/Script.h"
#include "../../include/TESFaction.h"
#include "../../include/TESForm.h"
#include "../../include/TESObjectREFR.h"
#include "../../include/TESQuest.h"
#include "../../include/OBJECT_ACTION.h"
class BGSMusicType;
// pdb: class FalloutAudioMedia, size 0x1, 0 members
class FalloutAudioMedia
{
  public:
    static void PlayMedia(BGSMusicType*);
    static void EndMediaUpdate();
    static void Update();
};
extern bool ExtractArgs(const ScriptParameter*, const char*, unsigned int*, TESObjectREFR*, TESObjectREFR*, Script*,
                        ScriptLocals*, ...);

__declspec(nothrow) void* _NiMalloc(unsigned int);
// Keep the array construction and nonthrowing map transfer inline in this unit.
template <class T, class A>
inline __declspec(nothrow) NiTArray<T, A>::NiTArray(unsigned int uiMaxSize, unsigned int uiGrowBy)
{
    m_usMaxSize = (unsigned short)uiMaxSize;
    m_usGrowBy = (unsigned short)uiGrowBy;
    m_usSize = 0;
    m_usESize = 0;
    if (m_usMaxSize > 0)
        m_pBase = (T*)_NiMalloc(sizeof(T) * m_usMaxSize);
    else
        m_pBase = 0;
}

template <class T>
inline NiTPrimitiveArray<T>::NiTPrimitiveArray(unsigned int uiMaxSize, unsigned int uiGrowBy) throw()
    : NiTArray<T, NiTMallocInterface<T> >(uiMaxSize, uiGrowBy)
{}

// the out-of-line NiTArray::SetAt does not unwind (NiMain has no C++ exceptions)
template <> __declspec(nothrow) void NiTArray<NiTexturingProperty::Map*, NiTMallocInterface<NiTexturingProperty::Map*> >::SetAt(
    unsigned int uiIndex, NiTexturingProperty::Map* const& element);
// @fnv 0x00a6aa40
// pdb: NiTexturingProperty::NiTexturingProperty | NiTexturingProperty.obj | retail, call graph, low
NiTexturingProperty::NiTexturingProperty() : m_uFlags(0), m_kMaps(9, 1), m_pkShaderMaps(0)
{
    Map* pkMap;
    pkMap = 0;
    m_kMaps.SetAt(0, pkMap);
    pkMap = 0;
    m_kMaps.SetAt(1, pkMap);
    pkMap = 0;
    m_kMaps.SetAt(2, pkMap);
    pkMap = 0;
    m_kMaps.SetAt(3, pkMap);
    pkMap = 0;
    m_kMaps.SetAt(4, pkMap);
    pkMap = 0;
    m_kMaps.SetAt(5, pkMap);
    pkMap = 0;
    m_kMaps.SetAt(6, pkMap);
    pkMap = 0;
    m_kMaps.SetAt(7, pkMap);
    pkMap = 0;
    m_kMaps.SetAt(8, pkMap);
    m_uFlags &= 0xf00f;
    bool bMulti = false;
    unsigned int uiSize = m_kMaps.m_usSize;
    for (unsigned int i = 1; i < uiSize; i++)
    {
        if (m_kMaps.m_pBase[i])
        {
            bMulti = true;
            break;
        }
    }
    if (bMulti)
        m_uFlags |= 1;
    else
        m_uFlags &= ~1;
    m_uFlags = (m_uFlags & ~0xA) | 4;
}
