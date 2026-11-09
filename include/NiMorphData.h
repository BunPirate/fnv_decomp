#pragma once

#include "NiObject.h"
#include "NiMemObject.h"
#include "NiFixedString.h"
#include "NiAVObject.h"

class NiPoint3;
class NiInterpolator;

// pdb: class NiMorphData, size 0x18, bases: NiObject, 4 members
class NiMorphData : public NiObject
{
  public:
    class MorphTarget : public NiMemObject
    {
      public:
        NiPoint3* m_aTargetVerts;
        NiFixedString m_kName;
        float m_fLegacyWeight;
        NiPointer<NiInterpolator> m_spLegacyInterpolator;

        const NiFixedString& GetName();
        void SetTargetInterpolator(NiInterpolator*);
    };

    virtual ~NiMorphData();

    MorphTarget* GetTarget(unsigned int uiIndex) const;

    unsigned int m_uiNumTargets;
    unsigned int m_uiNumVertsPerTarget;
    MorphTarget* m_aMorphTargets;
    bool m_bRelativeTargets;
    unsigned char m_aucPad[3];
};
