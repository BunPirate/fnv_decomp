
#include "../../include/TESCombatStyle.h"

// @fnv 0x004a7290
// pdb: BSMultiBound::QShape | TES.obj | debug, call graph, medium
float TESCombatStyle::UpdateCombatStyle()
{
    return ((float*)this)[0] * ((float*)this)[0] + ((float*)this)[1] * ((float*)this)[1] +
           ((float*)this)[2] * ((float*)this)[2];
}
