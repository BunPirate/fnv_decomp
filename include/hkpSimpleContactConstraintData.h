#pragma once
#include "hkpConstraintData.h"
#include "hkArray.h"

class hkpConstraintOwner;
class hkpConstraintInstance;
class hkpSimpleContactConstraintAtom;
class hkpContactPointPropertiesCFD;
class hkContactPoint;
struct hkContactPt;
struct hkCPProperties;
struct PhysicsMaterial;

// Exe RTTI at vftable 0x010cc934: hkpSimpleContactConstraintData derives from hkpConstraintData.
// pdb: class hkpSimpleContactConstraintData, size 0x30, bases: hkpConstraintData, 5 members
class hkpSimpleContactConstraintData : public hkpConstraintData
{
public:
    hkArray<unsigned char> m_idMgrA;
    int unk18;
    int unk1C;
    int m_clientData;
    hkpConstraintInstance* m_constraint;
    hkpSimpleContactConstraintAtom* m_atom;
    int m_atomSize;

    hkpContactPointPropertiesCFD* GetContactPointProperties(unsigned short id);
    int freeContactPoint(hkpConstraintOwner& constraintOwner, unsigned short id);
    int allocateContactPoint(hkpConstraintOwner& owner, hkContactPt** cpOut, hkCPProperties** cpiOut);
    int allocateContactPoint(hkpConstraintOwner& owner, hkContactPoint** cpOut, PhysicsMaterial** cpPropsOut);
};
