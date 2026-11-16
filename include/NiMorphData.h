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
        NiPoint3* m_aTargetVerts; // src: XBOX_RETAIL_PDB +0x0 (old: m_pkVertexPositions)
        NiFixedString m_kName;
        float m_fLegacyWeight; // src: XBOX_RETAIL_PDB +0x8 (old: m_fMorphWeight)
        NiPointer<NiInterpolator> m_spLegacyInterpolator; // src: XBOX_RETAIL_PDB +0xc (old: m_spTargetInterpolator)

        const NiFixedString& GetName();
        void SetTargetInterpolator(NiInterpolator*);
    };

    virtual ~NiMorphData();

    MorphTarget* GetTarget(unsigned int uiIndex) const;

    unsigned int m_uiNumTargets;
    unsigned int m_uiNumVertsPerTarget;
    MorphTarget* m_aMorphTargets; // src: XBOX_RETAIL_PDB +0x10 (old: m_pMorphTargets)
    bool m_bRelativeTargets; // src: XBOX_RETAIL_PDB +0x14 (old: m_bTargetsAreRelative)
    unsigned char m_aucPad[3];
};
