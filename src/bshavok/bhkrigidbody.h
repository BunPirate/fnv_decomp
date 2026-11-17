#ifndef FNV_BHKRIGIDBODY_WORKER_H
#define FNV_BHKRIGIDBODY_WORKER_H

#include "../../include/NiRTTI.h"
#include "../../include/bhkRigidBody.h"

#include "bhkrigidbody_worker_decls.h"
extern NiRTTI DAT_012681c0;

#pragma optimize("", off)
// @fnv 0x0056d530
const NiRTTI* bhkRigidBody::GetRTTI() const
{
    return &DAT_012681c0;
}

// @fnv 0x0056d540
unsigned int bhkRigidBody::GetInstanceSize()
{
    return 0xe0;
}

#pragma optimize("", on)
// @fnv 0x00c8d170
// pdb: bhkRigidBody::SetPosition | bhkRigidBody.obj | retail, vtable slot, high
// pdb params: arPos
// pdb locals: hkv
void bhkRigidBody::SetPosition(const NiPoint3& arPos)
{
    if (this)
    {
        hkpRigidBody* body = (hkpRigidBody*)phkObject;
        if (body)
        {
            ((void(__thiscall*)(bhkRigidBody*))NiD3DDefaultShader::SetShaderName)(this);
            body->SetWorldPosition(arPos);
            ((void(__thiscall*)(bhkRigidBody*))NiD3DDefaultShader::SetShaderName)(this);
        }
    }
}
// @fnv 0x00c8d1a0
// pdb: bhkRigidBody::SetRotation | bhkRigidBody.obj | retail, vtable slot, high
// pdb params: arRot
// pdb locals: hkrot
void bhkRigidBody::SetRotation(const NiQuaternion& arRot)
{
    if (this)
    {
        hkpRigidBody* body = (hkpRigidBody*)phkObject;
        if (body)
        {
            ((void(__thiscall*)(bhkRigidBody*))NiD3DDefaultShader::SetShaderName)(this);
            body->SetBodyOrientation(arRot);
            ((void(__thiscall*)(bhkRigidBody*))NiD3DDefaultShader::SetShaderName)(this);
        }
    }
}

#pragma optimize("", off)
// @fnv 0x0062ab20
// pdb: bhkRigidBody::GetDynamicMass | TESArrowTargetListener.obj | retail, call graph, high
// pdb locals: pm
float bhkRigidBody::GetBodyMass()
{
    hkpMotion* motion = hkpRigidBody_getStoredDynamicMotion();
    return motion ? motion->GetMassValue() : bhkRigidBody_GetMass();
}
#pragma optimize("", on)
__forceinline const __m128& bhkRigidBody::PositionVector()
{
    if (this && phkObject)
        return ((hkpRigidBodyMotionView*)phkObject)->m_vContactPosition;
    return *(__m128*)&DAT_01267e30;
}
#pragma optimize("t", on)
// @fnv 0x00c8d0f0
// pdb: bhkRigidBody::GetPosition | TESObjectREFR.obj | retail, upstream name already matches, high
// pdb params: arPos
// pdb locals: hkv
NiPoint3& bhkRigidBody::GetPosition(NiPoint3& arPos)
{
    *(bhkrigidbody_vector*)&arPos = (const bhkrigidbody_vector&)PositionVector();
    return arPos;
}
__forceinline const __m128& bhkRigidBody::RotationVector()
{
    if (this && phkObject)
        return ((hkpRigidBodyMotionView*)phkObject)->m_rotation;
    return *(__m128*)&DAT_012683b0;
}
#pragma optimize("t", on)
// @fnv 0x00c8d130
// pdb: bhkRigidBody::GetRotation | TESObjectREFR.obj | retail, upstream name already matches, high
// pdb params: arRot
// pdb locals: hkq
NiQuaternion& bhkRigidBody::GetRotation(NiQuaternion& arRot)
{
    *(bhkrigidbody_vector*)&arRot = (const bhkrigidbody_vector&)RotationVector();
    return arRot;
}

// @fnv 0x00c8f510
// pdb: bhkRigidBodyCinfo::bhkRigidBodyCinfo | bhkRigidBody.obj | retail, object-file gap fill, high
bhkRigidBodyCinfo::bhkRigidBodyCinfo()
{
    hk.m_fSurfaceFriction = DAT_01022958;
    hk.m_iAutoRemoveLevel = 0xff;
    hk.m_fRestitution = DAT_010c60d8;
}
// @fnv 0x00c8d1d0
// src: XBOX_PDB 0x00c8d1d0
// pdb: bhkRigidBody::SetPosRot | bhkRigidBody.obj | retail, upstream name already matches, high
// pdb params: arPos, arRot
// pdb locals: pb, pw
void bhkRigidBody::SetPosRot(const NiPoint3& arPos, const NiQuaternion& arRot)
{
    if (this)
    {
        hkpRigidBody* body = (hkpRigidBody*)phkObject;
        if (body)
        {
            bhkWorldObject_GethkWorldRw();
            body->SetPositionAndRotation(arPos, arRot);
        }
    }
}
__forceinline const __m128& bhkRigidBody::FUN_00c8d240()
{
    if (this && phkObject)
        return ((hkpRigidBodyMotionView*)phkObject)->m_vCenterOfMass1;
    return *(__m128*)&DAT_01267e30;
}
#pragma optimize("t", on)
// @fnv 0x00c8d240
// pdb: bhkRigidBody::GetCenterOfMassInWorld | bhkRigidBody.obj | debug, vtable slot, medium
// pdb params: arCOM
// pdb locals: pb
NiPoint3& bhkRigidBody::GetVec(NiPoint3& p)
{
    *(bhkrigidbody_vector*)&p = (const bhkrigidbody_vector&)FUN_00c8d240();
    return p;
}
// src: XBOX_PDB 0x00c8d200
__forceinline const __m128& bhkRigidBody::GetCenterOfMassLocal_00c8d200()
{
    if (this && phkObject)
        return ((hkpRigidBodyMotionView*)phkObject)->m_vCenterOfMassLocal;
    return *(__m128*)&DAT_01267e30;
}
#pragma optimize("t", on)
// @fnv 0x00c8d200
// src: XBOX_PDB 0x00c8d200
// pdb: bhkRigidBody::GetCenterOfMassLocal | bhkRigidBody.obj | debug, vtable slot, medium
// pdb params: arCOM
// pdb locals: pb
NiPoint3& bhkRigidBody::GetCenterOfMassLocal_00c8d200(NiPoint3& p)
{
    *(bhkrigidbody_vector*)&p = (const bhkrigidbody_vector&)GetCenterOfMassLocal_00c8d200();
    return p;
}
#endif
