#pragma once

#include "BSFaceGenMorphData.h"

class FaceGenTriData;

// pdb: class BSFaceGenMorphDataHair, size 0xc, bases: BSFaceGenMorphData, 1 members
class BSFaceGenMorphDataHair : public BSFaceGenMorphData
{
public:
    BSFaceGenMorphDataHair(FaceGenTriData*);
    virtual ~BSFaceGenMorphDataHair();
    virtual const NiRTTI* GetRTTI() const;

    void FUN_006623d0();
    void* FUN_006623a0(unsigned int);
    void ApplyMorph_00662460(int, int, float);

    void* pHairMorph; // src: XBOX_RETAIL_PDB +0x8 (old: hairMorph)
};
