#pragma once

#include "NiObject.h"
#include "NiColorInterpolator.h"
#include "NiPoint3.h"

class PositionKeyInterpolator;

// pdb: class NiPosData, size 0x18, bases: NiObject, 4 members
class NiPosData : public NiObject
{
  public:
    virtual void LoadBinary(NiStream&);

    void ReplaceAnim(PositionKeyInterpolator*, unsigned int, NiAnimationKey::KeyType);
    static NiPoint3* ComputePositionAtTime(NiPoint3*, float, const NiPoint3*);
    static NiPoint3 ComputePositionAtTime(float, const NiPoint3&);

    unsigned int m_uiNumKeys;
    PositionKeyInterpolator* m_pkKeys; // src: XBOX_RETAIL_PDB +0xc (old: m_pKeyArray)
    NiAnimationKey::KeyType m_eType; // src: XBOX_RETAIL_PDB +0x10 (old: m_eRequestType)
    unsigned char m_ucKeySize; // src: XBOX_RETAIL_PDB +0x14 (old: m_ucKeyDataSize)
    unsigned char m_padding15[3];
};
