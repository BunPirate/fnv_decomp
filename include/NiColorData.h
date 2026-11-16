#pragma once

#include "NiObject.h"
#include "NiPosData.h"
#include "NiRTTI.h"

class ColorAnimationKey;

// pdb: class NiColorData, size 0x18, bases: NiObject, 4 members
class NiColorData : public NiObject
{
  public:
    NiColorData();
    virtual ~NiColorData();
    virtual const NiRTTI* GetRTTI() const;

    void ReplaceAnim(ColorAnimationKey*, unsigned int, NiAnimationKey::KeyType);

    unsigned int m_uiNumKeys;
    ColorAnimationKey* m_pkKeys; // src: XBOX_RETAIL_PDB +0xc (old: m_pKeyArray)
    NiAnimationKey::KeyType m_eType; // src: XBOX_RETAIL_PDB +0x10 (old: m_eRequestType)
    unsigned char m_ucKeySize; // src: XBOX_RETAIL_PDB +0x14 (old: m_ucKeyDataSize)
    unsigned char m_aucPad[3];
};
