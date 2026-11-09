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

    void* ObjectName;
    CA0E60Array ConstraintsA;
    CA0E60Array ConstraintTypeA;
    int fRBMass;
    int fRBRestitution;
    int fRBFriction;
    int fRBRadius;
    int uiRBMaterial;
};
