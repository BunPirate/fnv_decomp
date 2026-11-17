#pragma once

#include "hkpAction.h"

class hkpConstraintInstance;
class hkpConstraintChainInstance;

// pdb: class hkpConstraintChainInstanceAction, size 0x1c, bases: hkpAction, 1 members
class hkpConstraintChainInstanceAction : public hkpAction
{
public:
    hkpConstraintChainInstanceAction(hkpConstraintInstance* pkInstance) throw();
    virtual ~hkpConstraintChainInstanceAction() throw();

    hkpConstraintChainInstance* m_constraintInstance; // src: XBOX_RETAIL_PDB +0x18 (old: m_pConstraintChainInstance)
};
