#pragma once

#include "hkReferencedObject.h"

// pdb: class hkpShapeInfo, size 0x70 (here 0x14), bases: hkReferencedObject, 6 members
class hkpShapeInfo : public hkReferencedObject
{
public:
    int unk08;
    int unk0c;
    unsigned int m_flags;
};
