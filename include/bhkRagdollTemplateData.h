#pragma once

#include "NiObject.h"
#include "CA0E60Array.h"

// pdb: class bhkRagdollTemplateData, size 0x40, bases: NiObject, 8 members
class bhkRagdollTemplateData : public NiObject
{
public:
    virtual ~bhkRagdollTemplateData();
    virtual const NiRTTI* GetRTTI() const;
    virtual void LoadBinary(NiStream& arStream);
    virtual void LinkObject(NiStream& kStream);
    virtual bool RegisterStreamables(NiStream& kStream);
    virtual void SaveBinary(NiStream& kStream);
    virtual bool IsEqual(NiObject* apObject) const;

    static NiObject* __cdecl CreateObject();

    void* ObjectName; // src: XBOX_RETAIL_PDB +0x8 (old: m_kName)
    CA0E60Array ConstraintsA; // src: XBOX_RETAIL_PDB +0xc (old: m_kArray1)
    CA0E60Array ConstraintTypeA; // src: XBOX_RETAIL_PDB +0x1c (old: m_kArray2)
    int fRBMass; // src: XBOX_RETAIL_PDB +0x2c (old: m_2c)
    int fRBRestitution; // src: XBOX_RETAIL_PDB +0x30 (old: m_30)
    int fRBFriction; // src: XBOX_RETAIL_PDB +0x34 (old: m_34)
    int fRBRadius; // src: XBOX_RETAIL_PDB +0x38 (old: m_38)
    int uiRBMaterial; // src: XBOX_RETAIL_PDB +0x3c (old: m_3c)
};
