#pragma once

#include "NiColorA.h"
#include "NiPoint3.h"
#include "NiAVObject.h"

class NiGeometry;
class NiLines;
class BSFadeNode;
class TESCombatStyle;

// pdb: class BGSPrimitive, size 0x34, 7 members
class BGSPrimitive
{
public:
    BGSPrimitive();
    virtual ~BGSPrimitive();
    virtual void vfn_04();
    virtual void ApplyColor(NiColorA& color);
    virtual void vf03(NiPoint3& radii);
    virtual bool vf04(TESCombatStyle& point);
    virtual void* vf05(int unused);

    static BGSPrimitive* __cdecl Copy(BGSPrimitive* apCopy);

    int eType;
    NiColorA Color;
    NiPoint3 m_kRadii;
    NiPointer<NiGeometry> m_kGeometry;
    NiPointer<NiLines> spFrame;
    NiPointer<BSFadeNode> m_pController;
    unsigned int iScaleHandlesEnabled;
};
