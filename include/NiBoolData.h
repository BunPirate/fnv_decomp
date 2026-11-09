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
    BooleanKey* m_pkKeys;
    NiAnimationKey::KeyType m_eType;
    unsigned char m_ucKeySize;
    unsigned char unk15[3];
};
