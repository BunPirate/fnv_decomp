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
    hkArray<unsigned char> m_idMgrA; // src: XBOX_RETAIL_PDB +0xc (old: m_kAtoms)
    int unk18;
    int unk1C;
    int m_clientData; // src: XBOX_RETAIL_PDB +0x20 (old: unk20)
    hkpConstraintInstance* m_constraint; // src: XBOX_RETAIL_PDB +0x24 (old: m_pHavokConstraint)
    hkpSimpleContactConstraintAtom* m_atom; // src: XBOX_RETAIL_PDB +0x28 (old: m_pAtom)
    int m_atomSize; // src: XBOX_RETAIL_PDB +0x2c (old: m_iAtomSize)

    hkpContactPointPropertiesCFD* GetContactPointProperties(unsigned short id);
    int freeContactPoint(hkpConstraintOwner& constraintOwner, unsigned short id);
    int allocateContactPoint(hkpConstraintOwner& owner, hkContactPt** cpOut, hkCPProperties** cpiOut);
    int allocateContactPoint(hkpConstraintOwner& owner, hkContactPoint** cpOut, PhysicsMaterial** cpPropsOut);
};
