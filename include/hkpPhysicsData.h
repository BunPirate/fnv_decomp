#pragma once

#include "hkReferencedObject.h"
#include "hkaAnimation.h"

class hkpWorldCinfo;
class hkpPhysicsSystem;

// pdb: class hkpPhysicsData, size 0x18, bases: hkReferencedObject, 2 members
class hkpPhysicsData : public hkReferencedObject
{
public:
    hkpWorldCinfo* m_worldCinfo; // src: XBOX_RETAIL_PDB +0x8 (old: m_pWorldCinfo)
    hkArray<hkpPhysicsSystem*> m_systems; // src: XBOX_RETAIL_PDB +0xc (old: m_kPhysicsSystems)
};
