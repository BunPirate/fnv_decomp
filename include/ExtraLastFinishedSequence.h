#pragma once

#include "BSExtraData.h"

// pdb: class ExtraLastFinishedSequence, size 0x10, bases: BSExtraData, 1 members
class ExtraLastFinishedSequence : public BSExtraData
{
public:
    virtual ~ExtraLastFinishedSequence();
    virtual bool Compare(BSExtraData* extra);

    ExtraLastFinishedSequence(const char* apName);
    bool Compare_00435310(BSExtraData* arg);

    char* name;
};
