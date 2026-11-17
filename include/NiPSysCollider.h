#pragma once

#include "NiObject.h"
#include "NiPoint3.h"
#include "NiAVObject.h"

class NiPSysSpawnModifier;
class NiPSysColliderManager;
class NiPSysData;
struct StrArr;

// pdb: class NiPSysCollider, size 0x2c, bases: NiObject, 8 members
class NiPSysCollider : public NiObject
{
public:
    NiPSysCollider(float bounce, bool spawn, bool die, NiPSysSpawnModifier* spawnMod);

    virtual void LoadBinary(NiStream& kStream);
    virtual void LinkObject(NiStream& kStream);
    virtual void GetViewerStrings(NiViewerStringsArray* pkStrings);
    virtual void ProcessClone(CloningProcess& kCloning);

    virtual NiPSysCollider* vf35(float time, float& collisionTime,
                               NiPSysData* data, unsigned short index);
    virtual void vf36(float time, NiPSysData* data, unsigned int index);
    virtual void vf37();

    void CreateVertexBufferSet(NiPSysCollider* collider, CloningProcess& cloning);
    NiPSysCollider* Clone(CloningProcess& cloning);

    float m_fBounce; // src: XBOX_RETAIL_PDB +0x8 (old: m_fBounceFactor)
    bool m_bSpawnOnCollide; // src: XBOX_RETAIL_PDB +0xc (old: m_bSpawnOnCollision)
    bool m_bDieOnCollide; // src: XBOX_RETAIL_PDB +0xd (old: m_bDieOnCollision)
    unsigned char layoutPaddingE[2];
    NiPSysSpawnModifier* m_pkSpawnModifier; // src: XBOX_RETAIL_PDB +0x10 (old: m_pSpawnModifier)
    NiPoint3 m_kCollisionPoint; // src: XBOX_RETAIL_PDB +0x14 (old: m_kCollisionPosition)
    float m_fCollisionTime; // src: XBOX_RETAIL_PDB +0x20 (old: m_fSpawnRate)
    NiPSysColliderManager* m_pkManager; // src: XBOX_RETAIL_PDB +0x24 (old: m_pColliderManager)
    NiPointer<NiPSysCollider> m_spNext; // src: XBOX_RETAIL_PDB +0x28 (old: m_spNextController)
};
