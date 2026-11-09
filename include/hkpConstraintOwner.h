#pragma once

#include "hkReferencedObject.h"

class hkpConstraintInstance;
struct GenericConstraintAtomScheme;
struct hkpConstraintInfo;

// pdb: class hkpConstraintOwner, size 0x18 (here 0xc), bases: hkReferencedObject, 1 members
class hkpConstraintOwner : public hkReferencedObject
{
public:
    virtual void addConstraintToCriticalLockedIsland(hkpConstraintInstance* constraint);
    virtual void removeConstraintFromCriticalLockedIsland(hkpConstraintInstance* constraint);
    virtual void addCallbackRequest(hkpConstraintInstance* constraint, int request);
    virtual void checkAccessRw();

    int m_iMaxSchemaSize;

    void subConstraintInfo(hkpConstraintInstance* constraint, hkpConstraintInfo& delta);
    void AccumulateStats(hkpConstraintInstance* constraint, GenericConstraintAtomScheme& delta);
    void AccumulateStats(void* constraint, GenericConstraintAtomScheme& info);
};
