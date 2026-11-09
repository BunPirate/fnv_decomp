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
    ColorAnimationKey* m_pkKeys;
    NiAnimationKey::KeyType m_eType;
    unsigned char m_ucKeySize;
    unsigned char m_aucPad[3];
};
