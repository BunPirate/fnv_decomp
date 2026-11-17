#pragma once

#include "hkReferencedObject.h"
#include "hkStringPtr.h"

class hkpWorld;
class hkpSimulationIsland;
class hkpEntity;
struct ClassMemberDescriptor;

#include "hkArray.h"

typedef unsigned long hkUlong;

// pdb: class hkpAction, size 0x18, bases: hkReferencedObject, 4 members
struct hkpAction : public hkReferencedObject
{
public:
    static const ClassMemberDescriptor Members[];

    hkpAction() throw();
    hkpAction(FinishingFlag flag);

    virtual void v0c();
    virtual void GetEntities(hkArray<hkpEntity*>& entitiesOut);
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();

    void FUN_00c90510();
    void FUN_00c905b0();

    hkpSimulationIsland* GetSimulationIsland();
    void setSimulationIsland(hkpSimulationIsland* island);

    hkpWorld* m_world; // src: XBOX_RETAIL_PDB +0x8 (old: m_pOwningWorld)
    hkpSimulationIsland* m_island; // src: XBOX_RETAIL_PDB +0xc (old: m_pCurrentSimulationIsland)
    hkUlong m_userData; // src: XBOX_RETAIL_PDB +0x10 (old: m_ulUserData)
    hkStringPtr m_name;
};
