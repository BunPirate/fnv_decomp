
#include "nicontrollersequence_decls.h"
// @fnv 0x00a5d3f0
// pdb: NiObject::CreateSharedClone | NiObject.obj | retail, call graph (shared callers), high
// pdb params: kCloning
// pdb locals: pkClone
NiControllerSequence__IDTag& NiControllerSequence__IDTag::operator=(const NiControllerSequence__IDTag& kCloning)
{
    ShaderBufferRecord* result;
    NiTStringPointerMap<ShaderBufferRecord*>* map = *(NiTStringPointerMap<ShaderBufferRecord*>**)&kCloning;
    if (map->GetAt((const char*)this, result))
        return *(NiControllerSequence__IDTag*)result;
    return Clone(kCloning);
}
