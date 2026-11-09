
#include "nibinaryloadsave_decls.h"
// @fnv 0x00a29580
// pdb: NiBinaryStreamLoad<int> | BSValueNode.obj | debug, object-file run extension, low
// pdb params: is, pValue, uiNumEls
// pdb locals: uiSize
void BooleanKey::LoadBinary(NiStream& stream)
{
    NiBinaryStreamLoad(*stream.m_pkIstr, &m_fTime);
    unsigned char value;
    NiBinaryStreamLoad(*stream.m_pkIstr, &value);
    m_bValue = value != 0;
}
