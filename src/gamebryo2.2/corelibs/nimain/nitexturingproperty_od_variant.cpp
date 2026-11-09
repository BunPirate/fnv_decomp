// NiTexturingProperty map replacement, compiled with the original /Od flags.

#include "../../../../include/NiTexturingProperty.h"

// @fnv 0x00533f40
// src: COMMUNITY 0x00533f40
// pdb: NiTexturingProperty::SetBaseMap | TESLand.obj | debug, upstream name already matches, high
// pdb params: pkMap
// pdb locals: pkOld
void NiTexturingProperty::SetBaseMap(Map* pkMap)
{
    Map* old = m_kMaps.GetAt(0);
    if (pkMap != old)
    {
        delete old;
        static_cast<NiTArray<Map*, NiTMallocInterface<Map*> >&>(m_kMaps).SetAt(0, pkMap);
    }
}
