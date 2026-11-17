
#include "memorypool_console_decls.h"
// @fnv 0x00aa6610
// pdb: MemoryPool::PlatformCommitPage | MemoryPool.obj | debug, object-file gap fill, medium
// pdb params: auiPageIndex, apPageAddress
bool MemoryPool::CommitPage(unsigned int pageIndex, char*& page)
{
    page = m_pPoolBase + (pageIndex << 12);
    return VirtualAlloc(page, 4096, 4096, 4) != 0;
}
