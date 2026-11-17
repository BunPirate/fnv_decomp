#pragma once

#include "BSExtraData.h"

class LockExtraData;
class TESObjectREFR;

// pdb: class ExtraLock, size 0x10, bases: BSExtraData, 1 members
class ExtraLock : public BSExtraData
{
public:
    virtual ~ExtraLock();
    virtual bool Compare(BSExtraData* extra);

    ExtraLock(LockExtraData* lock);

    void Unlock();
    void Lock();
    void* __thiscall ReleaseIfFlagged(unsigned int flags);
    void FUN_00517360();
    int FUN_0043a320();
    void SetConnectedCellsPublic(TESObjectREFR* apDoorRef, bool abIsPublic);
    void FUN_00430ca0();
    bool MenuTopic_GetResponseListEmpty();
    void MenuTopic_FillResponseList(int);

    LockExtraData* pLock;
};
