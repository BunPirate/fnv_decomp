#pragma once

#include "hkpPhantom.h"
#include "hkAabb.h"
#include "hkBool.h"
#include "hkaAnimation.h"

union hkAabbQ;
struct LinCastInputS;
struct WorldRayCastInput;
struct WorldRayCastOutput;
class hkpRayHitCollector;

// pdb: class hkpAabbPhantom, size 0xe0, bases: hkpPhantom, 3 members
class hkpAabbPhantom : public hkpPhantom
{
public:
    virtual ~hkpAabbPhantom() throw();

    hkpAabbPhantom(const hkAabb& aabb, unsigned int collisionFilterInfo);
    hkpAabbPhantom* initialize(const hkAabb& aabb, unsigned int collisionFilterInfo);
    void setAabb(const hkAabbQ& aabb);
    void __thiscall castRay(void* input, void* output);
    void hkpAabbPhantom_setAabb(const hkAabbQ& newAabb);
    void __thiscall hkpAabbPhantom_setAabb(const hkAabb& newAabb);
    hkpAabbPhantom* FUN_00cf2cb0(const hkAabb& aabb, unsigned int collisionFilterInfo);
    void __thiscall hkpAabbPhantom_castRay_00cf26b0(void* input, void* output);
    void hkpAabbPhantom_castRay_00cf26b0(const WorldRayCastInput& input, WorldRayCastOutput& output) const;
    void hkpAabbPhantom_linearCast(const hkpCollidable* toBeCast, const LinCastInputS& input, void* castCollector, void* startCollector);
    void hkpAabbPhantom_castRay(const WorldRayCastInput& input, hkpRayHitCollector& collector) const;

    char padA4[0xC];
    hkAabb m_aabb; // src: XBOX_RETAIL_PDB +0xb0 (old: m_kBounds)
    hkArray<void*> m_overlappingCollidables; // src: XBOX_RETAIL_PDB +0xd0 (old: m_ppOverlappingCollidables)
    hkBool m_orderDirty; // src: XBOX_RETAIL_PDB +0xdc (old: m_bOrderDirty)
    char padDD[0x3];
};
