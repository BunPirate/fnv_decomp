#pragma once

#include "NiTLargePrimitiveArray.h"

class Actor;
class TESTopicInfo;

// pdb: class TopicInfoArray, size 0x18, bases: NiTLargePrimitiveArray<TESTopicInfo *>, 0 members
class TopicInfoArray : public NiTLargePrimitiveArray<TESTopicInfo *>
{
public:
    TopicInfoArray();
    virtual ~TopicInfoArray();

    void InsertInfoAt(unsigned int aiIndex, TESTopicInfo *apInfo);
    unsigned int ProcessArray_GetProcessLevelTail(int a);
    unsigned int ProcessArray_GetProcessLevelHead(unsigned int index);
    Actor *ProcessArray_GetItem(unsigned int index);
};
