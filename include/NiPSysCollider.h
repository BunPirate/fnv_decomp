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

    float m_fBounce;
    bool m_bSpawnOnCollide;
    bool m_bDieOnCollide;
    unsigned char layoutPaddingE[2];
    NiPSysSpawnModifier* m_pkSpawnModifier;
    NiPoint3 m_kCollisionPoint;
    float m_fCollisionTime;
    NiPSysColliderManager* m_pkManager;
    NiPointer<NiPSysCollider> m_spNext;
};
