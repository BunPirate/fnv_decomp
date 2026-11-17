#pragma once

#include "hkReferencedObject.h"

class hkpTyremark;

// pdb: class hkpTyremarksWheel, size 0x1c (here 0x14), bases: hkReferencedObject, 3 members
class hkpTyremarksWheel : public hkReferencedObject
{
public:
    int m_iMaxNumTyremarks;
    int m_numTyremarks;
    hkpTyremark* m_data;

    hkpTyremark* __thiscall ComputeIndex(int index);
    void __thiscall addTyremarkPoint(hkpTyremark* tyremark);
};
