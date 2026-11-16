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

    hkArray<hkpEntity*> m_chainedEntities; // src: XBOX_RETAIL_PDB +0x38 (old: m_ppRigidBodies)
    hkpConstraintChainInstanceAction* m_action; // src: XBOX_RETAIL_PDB +0x44 (old: m_pAction)
};
