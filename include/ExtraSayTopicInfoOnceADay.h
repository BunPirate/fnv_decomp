#pragma once

#include "BSExtraData.h"

template <class T> class BSSimpleList;
class TopicInfoVisitRecord;

// pdb: class ExtraSayTopicInfoOnceADay, size 0x10, bases: BSExtraData, 1 members
class ExtraSayTopicInfoOnceADay : public BSExtraData
{
public:
    ExtraSayTopicInfoOnceADay();
    virtual ~ExtraSayTopicInfoOnceADay();

    void* __thiscall FUN_004374e0(unsigned int);
    void __thiscall FUN_004375c0();

    BSSimpleList<TopicInfoVisitRecord*>* pList;
};
