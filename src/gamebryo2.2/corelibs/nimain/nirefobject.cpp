// gamebryo2.2/corelibs/nimain/nirefobject.cpp: NiRefObject, ScrapHeapTaskQueue (2 functions)

#include "NiRefObject.h"
#pragma optimize("gty", on)
// @fnv 0x00cfcc20
void NiRefObject::DeleteThis()
{
    delete this;
}
#pragma optimize("", off)
#include "nirefobject_queue.h"
// Acquires the lock, enqueues command, releases the lock, and returns the enqueue result.
// @fnv 0x009054a0
// pdb: BSTCommonMessageQueue<ActorPathingMessage>::Push | HighProcess.obj | retail, vtable slot, high
// pdb params: aMessage
// pdb locals: bResult
bool ScrapHeapTaskQueue::QueueCall(void* aMessage)
{
    bool result;
    while (true)
    {
        if (BSAtomicCompareExchange(&lock, 0, 1) == 0)
        {
            reinterpret_cast<void(__cdecl*)()>(&Interface::PrintDebugMessage)();
            result = Enqueue(aMessage);
            reinterpret_cast<void(__cdecl*)()>(&Interface::PrintDebugMessage)();
            BSAtomicCompareExchange(&lock, 1, 0);
            break;
        }
    }
    return result;
}
