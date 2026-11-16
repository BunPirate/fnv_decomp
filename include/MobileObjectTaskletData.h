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

    BSSimpleList<MobileObject*>* pmoblist; // src: XBOX_RETAIL_PDB +0x18 (old: pMobList)
    BSTCommonLLMessageQueue<MobileObjectTaskletContext> msgqueue; // src: XBOX_RETAIL_PDB +0x1c (old: kMessageQueue)
    unsigned int uiHighActorCount; // src: XBOX_RETAIL_PDB +0x30 (old: MobileObjectTaskletState)
    unsigned int iThread; // src: XBOX_RETAIL_PDB +0x34 (old: eType)

    void FUN_008c83a0();
    bool HandleMessage(void* apMessage, int aiThread);
    void ProcessMessages(int aiType);
};
