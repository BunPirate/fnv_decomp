#pragma once

#include "hkReferencedObject.h"
#include "hkaAnimation.h"

class hkpWorldCinfo;
class hkpPhysicsSystem;

// pdb: class hkpPhysicsData, size 0x18, bases: hkReferencedObject, 2 members
class hkpPhysicsData : public hkReferencedObject
{
public:
    hkpWorldCinfo* m_worldCinfo;
    hkArray<hkpPhysicsSystem*> m_systems;
};
