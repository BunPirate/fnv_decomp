#pragma once

#include "BSFaceGenMorph.h"

class NiTriBasedGeom;
class BSFaceGenBaseMorphExtraData;

// pdb: class BSFaceGenMorphDifferential, size 0xc, bases: BSFaceGenMorph, 2 members
class BSFaceGenMorphDifferential : public BSFaceGenMorph
{
public:
    BSFaceGenMorphDifferential(unsigned int aiVertsCount);
    virtual ~BSFaceGenMorphDifferential();
    void ApplyDifferentialMorph(NiTriBasedGeom*, BSFaceGenBaseMorphExtraData*, float);
};
