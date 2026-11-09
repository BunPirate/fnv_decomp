#pragma once

#include "NiDynamicEffect.h"
#include "NiColor.h"
#include "StrArr.h"

// pdb: class NiLight, size 0x120 (here 0xf0), bases: NiDynamicEffect, 5 members
class NiLight : public NiDynamicEffect
{
  public:
    NiLight();
    virtual ~NiLight();
    virtual void DeleteThis();
    virtual const NiRTTI* GetRTTI() const;
    virtual void LoadBinary(NiStream& stream);
    virtual void LinkObject(NiStream& stream);
    virtual void SaveBinary(NiStream& stream);
    virtual bool IsEqual(NiObject* object) const;

    void DestroyMembers();
    void* Destroy(unsigned int flags);
    void AppendEffectProperties(StrArr* pStrings);

    void IncRefCount();
    void DecRefCount();
    bool IsKindOfType(const NiRTTI* type) const;
    void CopyMemberData(NiLight* light, CloningProcess& process);

    float m_fDimmer;
    NiColor m_kAmb;
    NiColor m_kDiff;
    NiColor m_kSpec;
    void* m_pMaterialData;
};
