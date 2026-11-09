#pragma once

#include "FinishingFlag.h"

struct ClassMemberDescriptor;

// pdb: class hkpBroadPhaseHandle, size 0x4, 1 members
class hkpBroadPhaseHandle
{
public:
    static const ClassMemberDescriptor Members[];

    hkpBroadPhaseHandle() : m_id(0) {}
    hkpBroadPhaseHandle(FinishingFlag flag);

    unsigned int m_id;
};
