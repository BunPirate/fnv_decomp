
// Provisional build file (plan B2): exact copies of the bsfile recipe for other original addresses.
// Twin_<addr>/FUN_<addr> are placeholder names; the original identities of these functions are unknown.
#include "bsfile_decls.h"

struct Twin_009c0070 : public BSFile
{
    unsigned int BGSSaveLoadFile_GetFilePosition();
};
// @fnv 0x009c0070
// src: XBOX_DEBUG_PDB 0x009c0070
// pdb: BGSSaveLoadFile::GetFilePosition | BGSSaveLoadFile.obj | debug, upstream name already matches, high
unsigned int Twin_009c0070::BGSSaveLoadFile_GetFilePosition()
{
    return m_uiValueId;
}
