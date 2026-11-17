// fallout/misc/saveload/bgsloadgamebuffer.h: defines BGSLoadGameBuffer::ResetReadPosition
#ifndef FNV_BGSLOADGAMEBUFFER_H
#define FNV_BGSLOADGAMEBUFFER_H

#include "bgsloadgamebuffer_decls.h"


// @fnv 0x00848d50
// src: XBOX_RETAIL_PDB 0x00848d50
// pdb: BGSLoadGameBuffer::DeleteBuffer | BGSSaveLoadGame.obj | retail, call graph, high
void BGSLoadGameBuffer::DeleteBuffer()
{
    void* buffer = pBuffer;
    Deallocate(buffer);
    pBuffer = 0;
    iBufferSize = 0;
    m_uiReadOffset = 0;
}
#endif
