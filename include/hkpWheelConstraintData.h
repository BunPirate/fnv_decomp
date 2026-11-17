#pragma once

#include "hkpConstraintData.h"
#include "hkpWheelConstraintDataAtoms.h"
#include "hkVector4.h"

// pdb: class hkpWheelConstraintData, size 0x160, bases: hkpConstraintData, 3 members
class hkpWheelConstraintData : public hkpConstraintData
{
public:
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();

    char padC[0x4];
    hkpWheelConstraintDataAtoms m_atoms; // src: XBOX_RETAIL_PDB +0x10 (old: m_kBridgeAtoms)
    hkVector4 m_initialAxleInB; // src: XBOX_RETAIL_PDB +0x140 (old: m_kAxleDirectionInBodyB)
    hkVector4 m_initialSteeringAxisInB; // src: XBOX_RETAIL_PDB +0x150 (old: m_kSteeringDirectionInBodyB)
};
