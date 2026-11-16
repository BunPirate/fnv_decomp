#pragma once

#include "BSAnimNote.h"

// pdb: class BSLookIKNote, size 0x18, bases: BSAnimNote, 2 members
class BSLookIKNote : public BSAnimNote
{
  public:
    BSLookIKNote();
    virtual ~BSLookIKNote();

    virtual const NiRTTI* GetRTTI() const;
    virtual NiObject* MakeClone(CloningProcess& arCloning);
    virtual void LoadBinary(NiStream& arStream);
    virtual void LinkObject(NiStream& arStream);
    virtual void SaveBinary(NiStream& arStream);
    virtual bool IsEqual(NiObject* apObject) const;
    virtual void GetViewerStrings(NiViewerStringsArray* apStrings);
    virtual bool __thiscall vf35(const TimedTextEntry* apTextKey);

    void* __thiscall Destroy(unsigned int flags);

    float fGain; // src: XBOX_RETAIL_PDB +0x10 (old: m_fDistanceScale)
    int eState;
};
