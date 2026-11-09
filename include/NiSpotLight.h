#pragma once

#include "NiPointLight.h"
#include "NiPoint3.h"

// pdb: class NiSpotLight, size 0x150 (here 0x114), bases: NiPointLight, 4 members
class NiSpotLight : public NiPointLight
{
  public:
    virtual bool IsEqual(NiObject* object) const;
    using NiPointLight::IsEqual;

    NiPoint3 m_kWorldDir;
    float m_f0108;
    float m_f010c;
    float m_f0110;
};
