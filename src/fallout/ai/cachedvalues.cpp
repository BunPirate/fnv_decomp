
// src/fallout/ai/cachedvalues.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/ai/cachedvalues.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../include/ActorValueModifierList.h"

struct FUN_0092ca70_shell
{
    int pad[0xb4 / 4];
    int m_0xb4;
    ActorValueModifierList m_0xb8;
    void CopyFrom(FUN_0092ca70_shell* source);
};

// @fnv 0x0092ca70
// pdb: MiddleLowProcess::MiddleLowCopy | MiddleLowProcess.obj | debug, object-file gap fill, medium
// pdb params: apProcess
void FUN_0092ca70_shell::CopyFrom(FUN_0092ca70_shell* source)
{
    m_0xb4 = source->m_0xb4;
    m_0xb8.SetAllModifiers(&source->m_0xb8);
}
