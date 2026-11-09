#include "../../../../include/NiStream.h"

void __cdecl NiStreamSaveBinary_unsigned_int(NiStream& kStream, const unsigned int& value);

// @fnv 0x0043d050
// pdb: NiStream::SaveLinkID | ModelLoader.obj | retail, upstream name already matches, high
// pdb params: pkObject
// pdb locals: uiLinkID
void NiStream::SaveLinkID(const NiObject* pkObject)
{
    unsigned int linkID = GetLinkIDFromObject(pkObject);
    NiStreamSaveBinary_unsigned_int(*this, linkID);
}

