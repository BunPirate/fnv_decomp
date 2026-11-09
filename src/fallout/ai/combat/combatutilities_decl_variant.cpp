#include "../../../../include/NiPoint3.h"
#include "../../../../include/hkpClosestRayHitCollector.h"
// Avoid collision with the compiler-generated constructor closure in TESBoundObject.
#define __local_vftable_ctor_closure FNVLocalVftableCtorClosure
#include "../../../../include/Actor.h"
#include "../../../../include/AlchemyItem.h"
#include "../../../../include/BGSProjectile.h"
#include "../../../../include/NiAVObject.h"
#include "../../../../include/PathingRequest.h"
#include "../../../../include/TESObjectREFR.h"
#undef __local_vftable_ctor_closure

// Declaration variant for the line-of-sight query at 0x009a7940.
#pragma strict_gs_check(on)
class HandleRef
{
public:
    unsigned int bits;
    HandleRef(int bits);
    void CFilter_SetLayer(int layer);
};
struct __declspec(align(16)) SightRayInput
{
    SightVector4 from, to;
    bool enableShapeCollectionFilter;
    HandleRef filter;
};
struct __declspec(align(16)) BhkPickData
{
    SightRayInput input;
    SightRayOutput output;
    SightVector4 startBounds;
    void* unkA0;
    hkpClosestRayHitCollector* collector;
    unsigned int collectorMode;
    bool enabled;
    BhkPickData();
    void bhkPickData_SetClosestCollector(hkpClosestRayHitCollector* collector);
    void bhkPickData_SetFilter(HandleRef filter);
    void bhkPickData_SetFrom(const NiPoint3& start);
    void bhkPickData_SetTo(const NiPoint3& end);
};
class LookTarget
{
public:
    void* TESObjectCELL_Pick(BhkPickData* arResult);
};
class GlobalObject_0045d260
{
  public:
    bool IsInCombat();
};
extern GlobalObject_0045d260 g_011f1c7c;
float __cdecl CombatUtilities_GetAttackerFiringZOffset(TESObjectREFR* apAttacker, int abIgnoreCrouch);
float __cdecl CombatUtilities_GetTargetFiringZOffset(TESObjectREFR* apTarget, int aeTargetSegmentInView, bool abIgnoreCrouch);
TESObjectREFR* __cdecl TESObjectREFR_FindReferenceFor3D(void* hit);
// @fnv 0x009a7940
// src: XBOX_PDB 0x009a7940
// pdb: CombatUtilities::CalculateLOS | CombatUtilities.obj | retail, upstream name already matches, high
// pdb params: apAttacker, apTarget, arAttackerLocation, arTargetLocation, abIgnoreCrouch, aiCollisionLayer
// pdb locals: collector, ecollilsionLayer, attackerLocation, icolFilter, phitRef, targetLocation, pobjHit, pickData, pmob
bool __cdecl CombatUtilities_CalculateLOS(Actor* apAttacker, TESObjectREFR* apTarget, const NiPoint3& arAttackerLocation, const NiPoint3& arTargetLocation,
                          int abIgnoreCrouch, int aiCollisionLayer)
{
    g_011f1c7c.IsInCombat();
    int layer = 37;
    if (aiCollisionLayer != -1)
        layer = aiCollisionLayer;
    NiPoint3 start = arAttackerLocation;
    start.z += CombatUtilities_GetAttackerFiringZOffset(apAttacker, 1);
    NiPoint3 end = arTargetLocation;
    if (apTarget)
        end.z += CombatUtilities_GetTargetFiringZOffset(apTarget, 2, true);
    BhkPickData ray;
    HandleRef filter = apAttacker->FUN_00931ed0();
    if (apTarget && apTarget->IsMobileObject())
    {
        Actor* mobile = static_cast<Actor*>(apTarget);
        filter = mobile->FUN_00931ed0();
    }
    hkpClosestRayHitCollector collector(layer, reinterpret_cast<const SightFilter*>(&filter));
    ray.bhkPickData_SetClosestCollector(&collector);
    filter = apAttacker->FUN_00931ed0();
    filter.CFilter_SetLayer(layer);
    ray.bhkPickData_SetFilter(filter);
    ray.bhkPickData_SetFrom(start);
    ray.bhkPickData_SetTo(end);
    void* hit = apAttacker->FUN_008d6f30()->TESObjectCELL_Pick(&ray);
    if (!hit)
    {
        g_011f1c7c.IsInCombat();
        return true;
    }
    TESObjectREFR* hitRef = TESObjectREFR_FindReferenceFor3D(hit);
    if (apTarget && hitRef == apTarget)
    {
        g_011f1c7c.IsInCombat();
        return true;
    }
    g_011f1c7c.IsInCombat();
    return false;
}
