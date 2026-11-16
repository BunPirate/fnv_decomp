#pragma once

#include <cstddef>
#include "hkReferencedObject.h"
#include "hkaAnimation.h"
#include "hkBool.h"
#include "hkStringPtr.h"

class hkpRigidBody;
class hkpConstraintInstance;
class hkpAction;
class hkpPhantom;
struct BoolResult;

typedef unsigned long hkUlong;

// pdb: class hkpPhysicsSystem, size 0x44, bases: hkReferencedObject, 7 members
class hkpPhysicsSystem : public hkReferencedObject
{
public:
    hkArray<hkpRigidBody*> m_rigidBodies; // src: XBOX_RETAIL_PDB +0x8 (old: m_ppRigidBodies)
    hkArray<hkpConstraintInstance*> m_constraints; // src: XBOX_RETAIL_PDB +0x14 (old: m_ppConstraints)
    hkArray<hkpAction*> m_actions; // src: XBOX_RETAIL_PDB +0x20 (old: m_ppActions)
    hkArray<hkpPhantom*> m_phantoms; // src: XBOX_RETAIL_PDB +0x2c (old: m_kPhantoms)
    hkStringPtr m_name;
    hkUlong m_userData; // src: XBOX_RETAIL_PDB +0x3c (old: m_ulUserData)
    hkBool m_active; // src: XBOX_RETAIL_PDB +0x40 (old: m_bSlotEnabled)
    char pad41[3];

    hkpPhysicsSystem();
    hkpPhysicsSystem(FinishingFlag f);
    virtual ~hkpPhysicsSystem() throw();
    virtual void vfunc3() throw();
    virtual BoolResult vfunc4() throw();

    void vfunc1() throw();
    void vfunc2() throw();
    static void* __cdecl operator new(std::size_t nbytes);
    const hkArray<hkpRigidBody*>& getRigidBodies() const;
    void __thiscall AddShape(hkpRigidBody* body);
    void __thiscall AddAction(hkpAction* action);
    void __thiscall hkpPhysicsSystem_addPhantom(void* phantom);
    void __thiscall hkpPhysicsSystem_addConstraint(hkpConstraintInstance* constraint);
    void __thiscall hkpPhysicsSystem_addAction(hkpAction* a);
    void __thiscall hkpPhysicsSystem_removeRigidBody(int index);
    void __thiscall hkpPhysicsSystem_removeConstraint(int index);
    void __thiscall hkpPhysicsSystem_removeAction(int index);
};
