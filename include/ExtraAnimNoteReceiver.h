#pragma once

#include "BSExtraData.h"
#include "BSAnimNoteReceiver.h"

// pdb: class ExtraAnimNoteReceiver, size 0x10, bases: BSExtraData, 1 members
class ExtraAnimNoteReceiver : public BSExtraData
{
public:
    virtual ~ExtraAnimNoteReceiver();

    ExtraAnimNoteReceiver(void* receiver);
    void FUN_0057a8d0();
    void* FUN_0057a8a0(unsigned int flags);

    BSAnimNoteReceiver* pReceiver;
};
