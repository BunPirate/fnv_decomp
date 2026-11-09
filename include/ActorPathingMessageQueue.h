#pragma once
#include "BSTCommonLLMessageQueue.h"
#include "LockPrimitive.h"
#include "NiRefObject.h"

class ActorPathingMessage;
typedef ActorPathingMessage QueuedMessage;
template <class T> class BSTFreeListElem;

// pdb: class ActorPathingMessageQueue, size 0x1c, bases: BSTCommonLLMessageQueue<ActorPathingMessage>, NiRefObject, 0 members
class ActorPathingMessageQueue : public BSTCommonLLMessageQueue<ActorPathingMessage>, public NiRefObject
{
  public:
    ActorPathingMessageQueue();
    virtual ~ActorPathingMessageQueue();
    virtual bool Push(const QueuedMessage& msg);

};
