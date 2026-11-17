// gamebryo2.2/corelibs/nisystem/nifile.cpp: NiFile (2 functions)

#include "nifile_packet.h"
// @fnv 0x00aa1a20
// pdb: NiFile::GetFile | NiFile.obj | debug, upstream name already matches, high
// pdb params: pcName, eMode, uiSize
NiFile* NiFile::GetFile(const char* pcName, OpenMode eMode, unsigned int uiSize)
{
    return DAT_011ac224(pcName, eMode, uiSize);
}
// The dispatch helper retains the original unoptimized request construction.
#pragma optimize("", off)
// Builds a NiFileAccessRequest with operation 1, the given name, buffer size and mode, submits it to CompleteJob and returns the result.
// @fnv 0x00aa85c0
// pdb: BSPointerListBase<OEI::IO::IO_Request *>::AddTail | oei_io_thread.obj | retail, object-file run extension, low
// pdb note: debug build links it to OEI::IO::fseek
// pdb params: element
// pdb locals: pkNode
unsigned int NiFile::RequestFileAccess(const char* name, unsigned int mode, unsigned int bufferSize)
{
    NiFileAccessRequest request;
    request.name = 0;
    request.operation = 0;
    request.reserved0 = 0;
    request.reserved1 = 0;
    request.operation = 1;
    request.name = name;
    request.bufferSize = bufferSize;
    request.mode = mode;
    CompleteJob(&request);
    return request.result;
}
