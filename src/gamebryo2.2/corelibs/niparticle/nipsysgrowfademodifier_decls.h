// gamebryo2.2/corelibs/niparticle/nipsysgrowfademodifier_decls.h: declares NiPSysGrowFadeModifier
#pragma once

#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/NiPSysModifier.h"
#include "../../../../include/NiStream.h"

// pdb: class NiPSysGrowFadeModifier, size 0x2c, bases: NiPSysModifier, 5 members
class NiPSysGrowFadeModifier : public NiPSysModifier
{
  public:
    float m_fGrowTime;
    unsigned short m_usGrowGeneration;
    float m_fFadeTime;
    unsigned short m_usFadeGeneration;
    float m_fBaseScale;
    virtual void LoadBinary(NiStream&);
};
template <class T> inline void NiBinaryStreamLoad(NiBinaryStream& stream, T* value)
{
    unsigned int size = sizeof(T);
    stream.m_uiAbsoluteCurrentPos += stream.m_pfnRead(&stream, value, sizeof(T), &size, 1);
}
