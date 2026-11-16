#pragma once

#include "NiProperty.h"

// pdb: class NiCullingProperty, size 0x1c, bases: NiProperty, 1 members
class NiCullingProperty : public NiProperty
{
  public:
    virtual NiCullingProperty* MakeClone(CloningProcess& kCloning);
    virtual void LoadBinary(NiStream& kStream);

    void NiProperty_CopyMembers(void* destination, CloningProcess& kCloning);
    void NiProperty_CopyMembers(NiCullingProperty* destination, CloningProcess& kCloning);
    NiCullingProperty* CreateClone_00a8f530(CloningProcess& kCloning);
    NiCullingProperty* NiDitherProperty_CreateClone(CloningProcess& kCloning);
    void LoadBinary_00a8f650(NiStream& kStream);
    void NiFogProperty_CopyMembers(void* pkDest, CloningProcess& kCloning);
    void NiShadeProperty_CopyMembers(void* pDest, CloningProcess& kCloning);

    unsigned short m_uFlags; // src: XBOX_RETAIL_PDB +0x18 (old: m_usFlags)
    unsigned short unk1A;
};
