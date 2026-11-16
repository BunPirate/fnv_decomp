#pragma once

#include "NiObject.h"
#include "NiPosData.h"

class TimedAnimationKey;

// pdb: class NiFloatData, size 0x18, bases: NiObject, 4 members
class NiFloatData : public NiObject
{
  public:
    NiFloatData();
    virtual void LoadBinary(NiStream&);

    void ReplaceAnim(TimedAnimationKey*, unsigned int, NiAnimationKey::KeyType);

    unsigned int m_uiNumKeys;
    TimedAnimationKey* m_pkKeys; // src: XBOX_RETAIL_PDB +0xc (old: m_pKeyArray)
    NiAnimationKey::KeyType m_eType; // src: XBOX_RETAIL_PDB +0x10 (old: m_eRequestType)
    unsigned char m_ucKeySize; // src: XBOX_RETAIL_PDB +0x14 (old: m_ucKeyDataSize)
    unsigned char m_auPadKeySize[3];
};
