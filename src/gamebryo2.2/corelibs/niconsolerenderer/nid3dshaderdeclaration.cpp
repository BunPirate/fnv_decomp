
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../include/NiD3DShaderDeclaration.h"
#include "../../../../include/NiVBBlock.h"

extern "C" void __cdecl _delete(void* p, unsigned int flags);

// Calls FUN_00e78be0, then deletes this with size 0x2c when flags has bit 0 set, and returns this.
// @fnv 0x00e7a1e0
void* __fastcall DestroyIfFlagged(NiD3DShaderDeclaration* self, void*, unsigned int flags)
{
    self->NiD3DShaderDeclaration::~NiD3DShaderDeclaration();
    if (flags & 1)
        _delete(self, 0x2c);
    return self;
}

// @fnv 0x00e942d0
// src: COMMUNITY 0x00e942d0
// pdb: NiVBBlock::ClearAllData | NiVBSet.obj | debug, upstream name already matches, high
void NiVBBlock::ClearAllData()
{
    unsigned int zero = 0;
    m_00 = zero;
    m_pkVB = zero;
    m_0c = zero;
    m_uiFVF = zero;
    m_uiFlags = zero;
    m_uiIndex = zero;
    m_uiUsage = zero;
    m_1c = zero;
    m_20 = zero;
    m_24 = zero;
    m_28 = zero;

    m_apkChips.RemoveAll(zero);

    m_pkNextBlock = zero;
    m_pkPrevBlock = zero;
}
