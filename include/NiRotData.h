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
    TimedRotationKey* m_pkKeys; // src: XBOX_RETAIL_PDB +0xc (old: m_pKeyArray)
    NiAnimationKey::KeyType m_eType; // src: XBOX_RETAIL_PDB +0x10 (old: m_eRequestType)
    unsigned char m_ucKeySize; // src: XBOX_RETAIL_PDB +0x14 (old: m_ucKeyDataSize)
};
