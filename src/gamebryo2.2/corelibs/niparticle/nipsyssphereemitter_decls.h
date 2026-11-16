// gamebryo2.2/corelibs/niparticle/nipsyssphereemitter_decls.h: declares NiPSysSphereEmitter
#ifndef NIPSYSSPHEREEMITTER_DECLS_H
#define NIPSYSSPHEREEMITTER_DECLS_H

#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/NiStream.h"
#include "../../../../include/NiPSysVolumeEmitter.h"

// pdb: class NiPSysSphereEmitter, size 0x5c, bases: NiPSysVolumeEmitter, 1 members
class NiPSysSphereEmitter : public NiPSysVolumeEmitter
{
  public:
    float m_fEmitterRadius; // src: XBOX_RETAIL_PDB +0x58 (old: m_fBoundRadius)
    virtual void LoadBinary(NiStream& kStream);
    virtual void SaveBinary(NiStream& kStream);
};
inline void __fastcall ReadBinaryValue(NiStream& stream, float& value)
{
    NiBinaryStream* input = stream.m_pkIstr;
    unsigned int reader = reinterpret_cast<unsigned int>(input->m_pfnRead);
    unsigned int size = 4;
    input->m_uiAbsoluteCurrentPos +=
        reinterpret_cast<unsigned int(__cdecl*)(NiBinaryStream*, void*, unsigned int, unsigned int*, unsigned int)>(
            reader)(input, &value, 4, &size, 1);
}
#endif
