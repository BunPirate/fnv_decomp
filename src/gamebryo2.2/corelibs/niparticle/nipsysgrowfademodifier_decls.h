// gamebryo2.2/corelibs/niparticle/nipsysgrowfademodifier_decls.h: declares NiPSysGrowFadeModifier
#pragma once

#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/NiPSysModifier.h"
#include "../../../../include/NiStream.h"

// pdb: class NiPSysGrowFadeModifier, size 0x2c, bases: NiPSysModifier, 5 members
class NiPSysGrowFadeModifier : public NiPSysModifier
{
  public:
    float m_fGrowTime; // src: XBOX_RETAIL_PDB +0x18 (old: m_fGrowthTime)
    unsigned short m_usGrowGeneration; // src: XBOX_RETAIL_PDB +0x1c (old: m_usGrowGenerationLimit)
    float m_fFadeTime; // src: XBOX_RETAIL_PDB +0x20 (old: m_fFadeDuration)
    unsigned short m_usFadeGeneration; // src: XBOX_RETAIL_PDB +0x24 (old: m_usFadeGenerationLimit)
    float m_fBaseScale; // src: XBOX_RETAIL_PDB +0x28 (old: m_fInitialScale)
    virtual void LoadBinary(NiStream&);
};
template <class T> inline void NiBinaryStreamLoad(NiBinaryStream& stream, T* value)
{
    unsigned int size = sizeof(T);
    stream.m_uiAbsoluteCurrentPos += stream.m_pfnRead(&stream, value, sizeof(T), &size, 1);
}
