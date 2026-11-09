#pragma once

#include "IBSAnimNoteReceiver.h"

// pdb: class BSAnimNoteReceiver, size 0x18 (here 0xc), bases: IBSAnimNoteReceiver, 2 members
class BSAnimNoteReceiver : public IBSAnimNoteReceiver
{
public:
    virtual ~BSAnimNoteReceiver();
    virtual void vf01();

    void __thiscall FUN_004b0480();
    void* __thiscall FUN_004b0580(unsigned int flags);
    void __thiscall DispatchNoteToReceivers(void* apNote);

    void* unk04;
    int unk08;
};
