#pragma once

#include "NiObject.h"
#include "NiPosData.h"

class TimedRotationKey;
class PositionKeyInterpolator;
class TimedAnimationKey;

// pdb: class NiTransformData, size 0x2c, bases: NiObject, 12 members
class NiTransformData : public NiObject
{
  public:
    unsigned short m_usNumRotKeys;
    unsigned short m_usNumPosKeys;
    unsigned short m_usNumScaleKeys;
    unsigned char layoutPaddingE[2];
    NiAnimationKey::KeyType m_eRotationKeyType;
    NiAnimationKey::KeyType m_ePosType;
    NiAnimationKey::KeyType m_eScaleType;
    unsigned char m_ucRotSize;
    unsigned char m_ucPosSize;
    unsigned char m_ucScaleSize;
    unsigned char layoutPadding1F[1];
    TimedRotationKey* m_pkRotationKeys;
    PositionKeyInterpolator* m_pkPositionKeys;
    TimedAnimationKey* m_pkScaleKeyArray;

    void ReplaceRotAnim(TimedRotationKey*, unsigned int, NiAnimationKey::KeyType);
    void ReplacePosAnim(PositionKeyInterpolator*, unsigned int, NiAnimationKey::KeyType);
    void ReplaceScaleAnim(TimedAnimationKey*, unsigned int, NiAnimationKey::KeyType);
};
