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
    hkArray<hkpRigidBody*> m_rigidBodies;
    hkArray<hkpConstraintInstance*> m_constraints;
    hkArray<hkpAction*> m_actions;
    hkArray<hkpPhantom*> m_phantoms;
    hkStringPtr m_name;
    hkUlong m_userData;
    hkBool m_active;
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
