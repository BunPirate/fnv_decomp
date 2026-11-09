#pragma once

#include "NiAVObject.h"
#include "NiColor.h"
#include "StrArr.h"

#include "NiTPointerList.h"

// pdb: class NiDynamicEffect, size 0xf0 (here 0xc4), bases: NiAVObject, 7 members
class NiDynamicEffect : public NiAVObject
{
  public:
    NiDynamicEffect();
    virtual ~NiDynamicEffect();
    virtual void LoadBinary(NiStream& kStream);
    virtual void LinkObject(NiStream& kStream);
    virtual void SaveBinary(NiStream& kStream);
    virtual bool IsEqual(NiObject* pkObject) const;

    void AppendEffectProperties(StrArr* strings);

    void IncRevisionID();
    void SetEffectColor(const NiColor& color);
    using NiAVObject::SetEffectColor;

    bool switchState;
    unsigned char effectType;
    long iIndex;
    unsigned long pushCount;
    unsigned long revID;
    NiTPointerList<NiNode*> shadowGenerator;
    NiTPointerList<NiNode*> unaffectedNodes;
};
