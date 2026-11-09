#pragma once

#include "hkpConstraintInstance.h"
#include "hkaAnimation.h"

class hkpConstraintChainData;
class hkpConstraintChainInstanceAction;
class hkpEntity;

// pdb: class hkpConstraintChainInstance, size 0x48, bases: hkpConstraintInstance, 2 members
class hkpConstraintChainInstance : public hkpConstraintInstance
{
public:
    hkpConstraintChainInstance(hkpConstraintChainData* data);
    virtual ~hkpConstraintChainInstance() throw();

    void EntityRemovedCallback(void* entity);
    void addEntity(hkpEntity* entity);

    hkArray<hkpEntity*> m_chainedEntities;
    hkpConstraintChainInstanceAction* m_action;
};
