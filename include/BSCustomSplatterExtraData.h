#pragma once

#include "NiExtraData.h"

// Exe 0x004dea80: four DWORDs copied into the splatter extra data; no SIMD alignment or vector arithmetic.
struct SplatterWordsView
{
    int a, b, c, d;
};

struct OpacityFadeState;

// pdb: class BSCustomSplatterExtraData, size 0x1c, bases: NiExtraData, 1 members
class BSCustomSplatterExtraData : public NiExtraData
{
public:
    SplatterWordsView SplatterData;

    BSCustomSplatterExtraData(SplatterWordsView* aSplatterData);
    virtual const NiRTTI* GetRTTI() const override;

    void ForwardCall_004deb10();
    void* DestroyIfFlagged(unsigned int flags);
    OpacityFadeState* GetOffsetC();
    void* GetList();

};
