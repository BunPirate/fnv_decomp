#pragma once

#include "hkpAction.h"

class hkpEntity;

// pdb: class hkpUnaryAction, size 0x1c, bases: hkpAction, 1 members
class hkpUnaryAction : public hkpAction
{
public:
    static const ClassMemberDescriptor Members[];

    hkpUnaryAction(hkpEntity* entity, unsigned int userData);
    hkpUnaryAction(FinishingFlag flag);

    hkpEntity* m_entity;
};
