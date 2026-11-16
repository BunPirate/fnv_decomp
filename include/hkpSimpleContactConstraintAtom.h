#pragma once

#include "hkContactPoint.h"

class PhysicsMaterial;
class UInt32Value;

// pdb: structure hkpSimpleContactConstraintAtom, size 0x30, bases: hkpConstraintAtom, 8 members
class hkpSimpleContactConstraintAtom
{
public:
    unsigned short m_type;
    unsigned short m_sizeOfAllAtoms; // src: XBOX_RETAIL_PDB +0x2 (old: m_usSizeOfAllAtoms)
    unsigned short m_numContactPoints; // src: XBOX_RETAIL_PDB +0x4 (old: m_usNumContactPoints)
    unsigned short m_numReservedContactPoints; // src: XBOX_RETAIL_PDB +0x6 (old: m_usMaxNumContactPoints)
    unsigned char m_numUserDatasForBodyA; // src: XBOX_RETAIL_PDB +0x8 (old: m_ucNumReservedContactPoints)
    unsigned char m_numUserDatasForBodyB; // src: XBOX_RETAIL_PDB +0x9 (old: m_ucNumContactPointProperties)
    unsigned char m_contactPointPropertiesStriding; // src: XBOX_RETAIL_PDB +0xa (old: m_ucContactPointPropertiesStriding)
    unsigned char unk0B;
    unsigned short m_maxNumContactPoints; // src: XBOX_RETAIL_PDB +0xc (old: m_usMaxNumContactPointProperties)
    unsigned short unk0E;
    unsigned short m_info; // src: XBOX_RETAIL_PDB +0x10 (old: m_infoFlags)
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
