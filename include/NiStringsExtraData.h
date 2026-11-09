#pragma once

#include "NiExtraData.h"

class ViewerStringArray;

// pdb: class NiStringsExtraData, size 0x14, bases: NiExtraData, 2 members
class NiStringsExtraData : public NiExtraData
{
  public:
    virtual ~NiStringsExtraData();
    virtual const NiRTTI* GetRTTI() const;
    virtual NiObject* MakeClone(CloningProcess& arCloning);
    virtual void LoadBinary(NiStream& stream);
    virtual void SaveBinary(NiStream& stream);
    virtual bool IsEqual(NiObject* pObject) const;
    virtual void GetViewerStrings(NiViewerStringsArray* apStrings);

    void __thiscall FreeStrings();
    void __thiscall DestroyFields_00a7b300();
    void* __thiscall FUN_00a94970(unsigned int flags);
    void __thiscall CopyMembers(NiStringsExtraData* pDest, void* kCloning);
    void LoadStringArray(NiStream* kStream);
    NiStringsExtraData* CreateClone_00a94990(void* kCloning);
    void SaveBinary_00a949f0(NiStream& kStream);
    void GetViewerStrings_00a94ae0(ViewerStringArray* pStrings);

    union
    {
        unsigned int m_uiItemCount;
        unsigned int m_uiSize;
    };
    union
    {
        void** m_ppData;
        char** m_ppcValue;
    };
};
