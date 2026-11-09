#pragma once

#include "NiObject.h"
#include "NiPosData.h"

class TimedRotationKey;

// pdb: class NiRotData, size 0x18, bases: NiObject, 4 members
class NiRotData : public NiObject
{
  public:
    void SetKeys(TimedRotationKey* pkKeys, unsigned int uiNumKeys, NiAnimationKey::KeyType eType);
    void GuaranteeKeysAtStartAndEnd(float fStartTime, float fEndTime);
    TimedRotationKey* ComputePositionAtTime(unsigned int& uiNumKeys, int& eType, unsigned char& ucSize) const;

    unsigned int m_uiNumKeys;
    TimedRotationKey* m_pkKeys;
    NiAnimationKey::KeyType m_eType;
    unsigned char m_ucKeySize;
};
