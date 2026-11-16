#pragma once

#include "Projectile.h"
#include "AnimIdle.h"
#include "NiPoint3.h"

class EffectItem;
class EffectSetting;
class ProjectileEvent;
class ProjectileNodeStandin;

// pdb: class ContinuousBeamProjectile, size 0x180 (here 0x154), bases: Projectile, 2 members
class ContinuousBeamProjectile : public Projectile
{
public:
    ContinuousBeamProjectile(bool bTempRef);
    virtual ~ContinuousBeamProjectile();
    virtual unsigned int GetProjectileType();
    virtual void Do3DLoaded();
    virtual void HandleTracer();
    virtual void UpdateProjectile(float afDelta);
    virtual bool OnCollision(Actor* actor, const NiPoint3& contactPoint,
                             const NiPoint3& contactNormal, hkpCollidable* collidable,
                             unsigned int collisionShapeKey, unsigned int hitMaterial);

    NiAVObject* Root();
    NiPoint3* Position();
    void v310();

    int Initialize();
    void InitContinuousBeam();
    void UpdateAlignment();
    bool AddImpact_009ab9c0(void* apCollidee, NiPoint3* aContactPoint, void* aContactNormal,
                      void* apTargetCollidable, void* aiKey, void* aeForceMaterial);
    bool ProcessHit(void* apCollidee, NiPoint3* aContactPoint, void* aContactNormal,
                    void* apTargetCollidable, void* aiKey, void* aeForceMaterial);
    void MarkGeometryDataMutable(NiAVObject* object);
    void ScaleObject(NiAVObject* object, float scale);
    void fn_9ABD00_Recurse(NiAVObject* object, float scale, float previousScale);
    float FindBeamGeometryLength(NiAVObject* apGeometry);
    void* GetActorBase();
    bool Projectile_IsFlagSet(int flags);
    void Projectile_SetRange(float distance);
    void Projectile_SetFlag(int flag, int value);
    void Projectile_Initialize();
    Actor* Projectile_GetShooter();
    void Projectile_Kill();
    int GetArchetype();
    EffectItem* CombatController_GetCombatState();
    void TESObjectREFR_SetLocationOnReference(const NiPoint3*);
    void MagicProjectile_ApplyCollisionForce(NiPoint3, NiPoint3, unsigned int);
    ProjectileNodeStandin* FUN_009306d0();
    void* FUN_008d6f30();
    ProjectileEvent* FUN_009185e0();
    EffectSetting* GetAVEffect();
    void ApplyAreaEffect(NiPoint3 point, unsigned int variant,
                         TESObjectREFR* apCollidee, bool abFizzle);

    NiPointer<AnimIdle> m_spUnk150;
};
