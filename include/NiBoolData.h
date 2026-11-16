#pragma once

#include "NiObject.h"
#include "NiColorInterpolator.h"

class BooleanKey;

// pdb: class NiBoolData, size 0x18, bases: NiObject, 4 members
class NiBoolData : public NiObject
{
  public:
    virtual void LoadBinary(NiStream& kStream);

    void SetColorKeys(BooleanKey*, unsigned int, NiAnimationKey::KeyType);
    void DecrementRefCount();
    void* Destroy(unsigned int);

    unsigned int m_uiNumKeys;
    BooleanKey* m_pkKeys; // src: XBOX_RETAIL_PDB +0xc (old: m_pKeyArray)
    NiAnimationKey::KeyType m_eType; // src: XBOX_RETAIL_PDB +0x10 (old: m_eRequestType)
    unsigned char m_ucKeySize; // src: XBOX_RETAIL_PDB +0x14 (old: m_ucKeyDataSize)
    unsigned char unk15[3];
};
