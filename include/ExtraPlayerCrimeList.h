#pragma once

#include "BSExtraData.h"

template <class T> class BSSimpleList;
class MenuTopic;

// pdb: class ExtraPlayerCrimeList, size 0x10 (here 0xc), bases: BSExtraData, 1 members
class ExtraPlayerCrimeList : public BSExtraData
{
public:
    ExtraPlayerCrimeList();
    ExtraPlayerCrimeList(BSSimpleList<MenuTopic*>* apTopicList);
    virtual ~ExtraPlayerCrimeList();
};
