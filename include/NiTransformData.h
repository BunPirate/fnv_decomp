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
    NiAnimationKey::KeyType m_ePosType; // src: XBOX_RETAIL_PDB +0x14 (old: m_ePositionKeyType)
    NiAnimationKey::KeyType m_eScaleType; // src: XBOX_RETAIL_PDB +0x18 (old: m_eScaleKeyType)
    unsigned char m_ucRotSize; // src: XBOX_RETAIL_PDB +0x1c (old: m_ucRotationKeySize)
    unsigned char m_ucPosSize; // src: XBOX_RETAIL_PDB +0x1d (old: m_ucPositionKeySize)
    unsigned char m_ucScaleSize; // src: XBOX_RETAIL_PDB +0x1e (old: m_ucScaleKeySize)
    unsigned char layoutPadding1F[1];
    TimedRotationKey* m_pkRotationKeys;
    PositionKeyInterpolator* m_pkPositionKeys;
    TimedAnimationKey* m_pkScaleKeyArray;

    void ReplaceRotAnim(TimedRotationKey*, unsigned int, NiAnimationKey::KeyType);
    void ReplacePosAnim(PositionKeyInterpolator*, unsigned int, NiAnimationKey::KeyType);
    void ReplaceScaleAnim(TimedAnimationKey*, unsigned int, NiAnimationKey::KeyType);
};
