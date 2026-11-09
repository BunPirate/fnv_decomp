// bsshader/imagespacetexture.cpp: free functions (1 function)

#include "imagespacetexture_decls.h"
#include "../../include/BaseFormComponent.h"
#include "../../include/TESEnchantableForm.h"

// @fnv 0x0041fd00
// pdb: ShadowSceneNode::QFrozenCamera | TES.obj | debug, call graph, medium
void TESEnchantableForm::SetCastingType(int aeCastingType)
{
    eCastingType = static_cast<MagicSystem__CastingType>(aeCastingType);
}
