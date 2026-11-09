#pragma once

#include "BSTempEffect.h"
#include "NiAVObject.h"

// pdb: class BSTempEffectDebris, size 0x24, bases: BSTempEffect, 4 members
class BSTempEffectDebris : public BSTempEffect
{
  public:
    BSTempEffectDebris();
    virtual ~BSTempEffectDebris();

    virtual bool ShouldDelete();
    void SetIsForegroundEffect(bool foregroundElement);
    bool IsNew();

    NiPointer<NiAVObject> sp3D;
    const char* pFilename;
    bool bUseDebrisCounter;
    bool bForceDelete;
    bool m_bShouldDelete;
    unsigned char pad23;
};
