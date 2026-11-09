#pragma once

#include "BSFaceGenMorph.h"

class NiTriBasedGeom;
class BSFaceGenBaseMorphExtraData;

// pdb: class BSFaceGenMorphStatistical, size 0x10, bases: BSFaceGenMorph, 3 members
class BSFaceGenMorphStatistical : public BSFaceGenMorph
{
public:
    BSFaceGenMorphStatistical(unsigned int aiVertsCount, unsigned int aiFirstIndex);
    virtual ~BSFaceGenMorphStatistical();
    void ApplyDifferentialMorph(NiTriBasedGeom*, BSFaceGenBaseMorphExtraData*, float);

    unsigned int iFirstIndex;
};
