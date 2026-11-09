#pragma once

#include "bhkWaterListener.h"
#include "BGSZoneTargetListener.h"
#include "NiPoint3.h"

// pdb: class TESWaterListener, size 0x40 (here 0xc), bases: bhkWaterListener, BGSZoneTargetListener, 7 members
class TESWaterListener : public bhkWaterListener, public BGSZoneTargetListener
{
public:
    virtual ~TESWaterListener();

    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();

    static void UpdateWaterHeightAtPosition(float, NiPoint3);
};
