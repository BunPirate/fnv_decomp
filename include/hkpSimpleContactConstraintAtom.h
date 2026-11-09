#pragma once

#include "hkContactPoint.h"

class PhysicsMaterial;
class UInt32Value;

// pdb: structure hkpSimpleContactConstraintAtom, size 0x30, bases: hkpConstraintAtom, 8 members
class hkpSimpleContactConstraintAtom
{
public:
    unsigned short m_type;
    unsigned short m_sizeOfAllAtoms;
    unsigned short m_numContactPoints;
    unsigned short m_numReservedContactPoints;
    unsigned char m_numUserDatasForBodyA;
    unsigned char m_numUserDatasForBodyB;
    unsigned char m_contactPointPropertiesStriding;
    unsigned char unk0B;
    unsigned short m_maxNumContactPoints;
    unsigned short unk0E;
    unsigned short m_info;
    unsigned short unk12;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;

    hkContactPoint* getContactPoints();
    hkContactPoint* getContactPoints() const;
    PhysicsMaterial* getContactPointPropertiesStream(int i);
    UInt32Value* getContactPointPropertiesStream() const;
    int getContactPointPropertiesStriding() const;
};
