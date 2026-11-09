#pragma once

#include "ImageSpaceModifierInstance.h"

// pdb: class ImageSpaceModifierInstanceTemp, size 0x20, bases: ImageSpaceModifierInstance, 1 members
class ImageSpaceModifierInstanceTemp : public ImageSpaceModifierInstance
{
  public:
    ImageSpaceModifierInstanceTemp(float, float, NiAVObject*, float);
    virtual ~ImageSpaceModifierInstanceTemp();

    void DestroyMembers();
    bool IsExpired();

    float fDuration;
};
