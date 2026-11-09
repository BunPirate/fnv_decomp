// The diagnostic allocation overload: it forwards the size to the plain
// MemoryManager allocator while carrying the caller's file, line and
// function text for the allocation trackers.

#include "../../include/MemoryManager.h"

// Allocates size bytes by calling the plain Allocate overload, ignoring the file, line and function arguments.
// @fnv 0x00aa4030
// pdb: MemoryManager::Allocate | MemoryManager.obj | retail, upstream name already matches, high
// pdb params: aSize
// pdb locals: imemoryPass, pheap, pdefaultHeap, econtext, bfromSystem, pcontextHeap, ballowSystemAlloc, original_size, pmem, ppool
void* MemoryManager::Allocate(unsigned int aSize, const char* apFile, const int aiLine, const char* apFunction)
{
    void* result = Allocate(aSize);
    return result;
}
