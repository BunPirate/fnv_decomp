#pragma once

#include "ImageSpaceModifierInstanceTemp.h"
#include "NiPoint2.h"

// pdb: class ImageSpaceModifierInstanceRB, size 0x38, bases: ImageSpaceModifierInstanceTemp, 5 members
class ImageSpaceModifierInstanceRB : public ImageSpaceModifierInstanceTemp
{
  public:
    ImageSpaceModifierInstanceRB(float, float, NiAVObject*, float, float, float, float, float, const NiPoint2&);

    void vf36();
    virtual void vf38(char* apBuffer);

    float m_fRampUp;
    float fStart;
    float m_fRampDown;
    float m_fRampDownStart;
    NiPoint2 Center;
};
