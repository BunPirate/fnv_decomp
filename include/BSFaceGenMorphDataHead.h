#pragma once

#include "BSFaceGenMorphData.h"
#include "BSFaceGenMorph.h"
#include "NiRTTI.h"

class FaceGenTriData;

// pdb: class BSFaceGenMorphDataHead, size 0x18, bases: BSFaceGenMorphData, 4 members
class BSFaceGenMorphDataHead : public BSFaceGenMorphData
{
public:
    BSFaceGenMorphDataHead();
    BSFaceGenMorphDataHead(FaceGenTriData*);
    virtual ~BSFaceGenMorphDataHead();

    virtual const NiRTTI* GetRTTI() const;

    void* FUN_00661db0(unsigned int flags);
    void ApplyMorph(int aeType, int aiIndex, int apGeom, int apBaseMorph, float afModifier);
    int GetExpressionMorph(int aiIndex);
    int GetModifierMorph(int aiIndex);
    int GetPhonemeMorph(int aiIndex);
    int GetCustomMorph(int aiIndex);

    static const NiRTTI ms_kRTTI;

    BSFaceGenMorph** ppExpressionMorphs;
    BSFaceGenMorph** ppModifierMorphs;
    BSFaceGenMorph** ppPhonemeMorphs;
    BSFaceGenMorph** ppCustomMorphs;
};
