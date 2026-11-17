
// Provisional build file (plan B2): exact copies of the bsfile recipe for other original addresses.
// Twin_<addr>/FUN_<addr> are placeholder names; the original identities of these functions are unknown.
#include "bsfile_decls.h"

struct Twin_009c0070 : public BSFile
{
    unsigned int GetFilePosition();
};
// @fnv 0x009c0070
// pdb: BGSSaveLoadFile::GetFilePosition | BGSSaveLoadFile.obj | debug, upstream name already matches, high, not renamed: the link is the existing name itself, so its spelling stays
unsigned int Twin_009c0070::GetFilePosition()
{
    return m_uiValueId;
}
