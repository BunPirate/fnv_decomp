#pragma once

#include "BSWin32TaskletData.h"
#include "BSTCommonLLMessageQueue.h"
#include "LockPrimitive.h"

class MobileObject;
class MobileObjectTaskletContext;
template <class T> class BSSimpleList;
template <class T> class BSTFreeListElem;



// pdb: class MobileObjectTaskletData, size 0x38, bases: BSXenonTaskletData, 4 members
class MobileObjectTaskletData : public BSWin32TaskletData
{
public:
    MobileObjectTaskletData(BSTFreeList<MobileObjectTaskletContext>* apPool);
    virtual ~MobileObjectTaskletData();
    virtual void Process();
    virtual void SetMobileObjectCount(unsigned int auiObjectCount);
    virtual void ProcessMobileObject(MobileObject* apObject);
    virtual void SetThreadNumber(unsigned int auiThreadNumber);

    BSSimpleList<MobileObject*>* pmoblist;
    BSTCommonLLMessageQueue<MobileObjectTaskletContext> msgqueue;
    unsigned int uiHighActorCount;
    unsigned int iThread;

    void FUN_008c83a0();
    bool HandleMessage(void* apMessage, int aiThread);
    void ProcessMessages(int aiType);
};
