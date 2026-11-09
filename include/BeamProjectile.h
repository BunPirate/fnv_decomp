#pragma once

#include "Projectile.h"

class BGSLoadFormBuffer;
class BGSSaveFormBuffer;
class NiGeometry;

// pdb: class BeamProjectile, size 0x180 (here 0x150), bases: Projectile, 1 members
class BeamProjectile : public Projectile
{
public:
    virtual ~BeamProjectile();
    virtual void SaveGame(BGSSaveFormBuffer* arg);
    virtual void LoadGame(BGSLoadFormBuffer* arg);
    virtual void Unk_19(void* arg);
    virtual void Revert(BGSLoadFormBuffer* buffer);
    virtual void Unk_21(BGSLoadFormBuffer* arg);
    virtual unsigned int GetProjectileType();
    virtual void Do3DLoaded();
    virtual void HandleTracer();
    virtual void UpdateProjectile(float afDelta);
    virtual bool OnCollision(Actor* actor, const NiPoint3& contactPoint,
                             const NiPoint3& contactNormal, hkpCollidable* collidable,
                             unsigned int collisionShapeKey, unsigned int hitMaterial);

    void LoadProjectile(BGSLoadFormBuffer* apLoadGameBuffer);
    void SaveProjectile(BGSSaveFormBuffer* apSaveGameBuffer);
    void LoadGame_009b4cf0(BGSLoadFormBuffer* apLoadGameBuffer);
    void RevertBGS_009abf10(BGSLoadFormBuffer* apLoadGameBuffer);
    void InitLoadGame_009bab00(BGSLoadFormBuffer* apLoadGameBuffer);
    void SaveGame_00979bb0(BGSSaveFormBuffer* apSaveGameBuffer);
    void FinishLoadGame_009abef0(BGSLoadFormBuffer* apLoadGameBuffer);

    void Process3D();
    void __thiscall Initialize_00979280();
    unsigned char AddImpact(void* apCollidee, void* aContactPoint, void* aContactNormal,
                              void* apTargetCollidable, void* aiKey, void* aeForceMaterial);
    void Projectile_SetRange(float value);
    void ScaleBeamGeometryLength(NiAVObject* apGeometry, float afScaleFactor);
    float FindBeamGeometryLength(NiGeometry* apGeometry);
    float FindBeamGeometryLength(NiAVObject* apGeometry);
    void ScaleNode(NiAVObject* node, float fScale, float fDivisor);
};
