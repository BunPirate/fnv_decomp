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
    TimedAnimationKey* m_pkKeys;
    NiAnimationKey::KeyType m_eType;
    unsigned char m_ucKeySize;
    unsigned char m_auPadKeySize[3];
};
