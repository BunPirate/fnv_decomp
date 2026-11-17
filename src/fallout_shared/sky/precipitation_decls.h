// fallout_shared/sky/precipitation_decls.h: declares ModelLoader and shader helpers
#ifndef FNV_PRECIPITATION_DECLS_H
#define FNV_PRECIPITATION_DECLS_H

#include "../../../include/NiNode.h"

class NiProperty;
class SkyShaderProperty;

#include "../../../include/ENUM_LOD_MULT.h"
// pdb: class ModelLoader, size 0x30 (here 0x1), 12 members
class ModelLoader
{
  public:
    NiNode* LoadFile(const char* path, ENUM_LOD_MULT lodMult, bool assignShaders, bool suppressWarning, bool keepUV,
                     bool noUseCountIncrease);
};
extern ModelLoader* g_modelLoader;

extern const NiRTTI DAT_012024e0;
extern const char DAT_0104ed9c[];

SkyShaderProperty* NiObject_DynamicCast(const NiRTTI* rtti, NiProperty* property);

#endif
