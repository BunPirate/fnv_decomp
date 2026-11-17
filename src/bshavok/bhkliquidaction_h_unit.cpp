#include "../../include/bhkLiquidAction.h"

extern unsigned int DAT_012681bc;

// @fnv 0x0056d380
// pdb: bhkRigidBody::bhkRigidBody | TESObjectREFR.obj | debug, call graph, high
// pdb params: arInfo
bhkLiquidAction::bhkLiquidAction(const LiquidActionInfo& arInfo)
{
    ConfigureBody(arInfo);
    ++DAT_012681bc;
}
