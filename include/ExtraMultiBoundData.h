#pragma once

#include "BSExtraData.h"

class Point3Offset;

// pdb: class ExtraMultiBoundData, size 0x10, bases: BSExtraData, 1 members
class ExtraMultiBoundData : public BSExtraData
{
public:
    virtual ~ExtraMultiBoundData();
    virtual bool Compare(BSExtraData* extra);

    ExtraMultiBoundData();

    Point3Offset* pBound;
};
