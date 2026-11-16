#pragma once

#include "NiStream.h"
#include "NiObject.h"
#include "NiTexturingProperty.h"

class RendererDataRecord;

// pdb: class NiScreenTexture, size 0x20, bases: NiObject, 4 members
class NiScreenTexture : public NiObject
{
public:
    virtual ~NiScreenTexture();
    virtual const NiRTTI* GetRTTI() const;
    virtual NiObject* MakeClone(CloningProcess& arCloning);
    virtual void LoadBinary(NiStream& kStream);
    virtual void LinkObject(NiStream& arStream);
    virtual bool RegisterStreamables(NiStream& arStream);
    virtual void SaveBinary(NiStream& arStream);
    virtual bool IsEqual(NiObject* pkObject) const;

    bool FUN_00a954f0(NiStream&);
    void LinkTexturingProperty(NiStream&);
    void __thiscall ReleaseReference_00a95590();
    void* __thiscall FUN_00a95740(unsigned int);

    RendererDataRecord* m_kScreenRects; // src: XBOX_RETAIL_PDB +0x8 (old: m_pBase)
    unsigned int m_uiElementCount;
    unsigned int m_uiAllocatedCapacity;
    NiTexturingProperty* m_spTexProp; // src: XBOX_RETAIL_PDB +0x14 (old: m_pTexturingProperty)
    unsigned short m_usDirtyFlags; // src: XBOX_RETAIL_PDB +0x18 (old: flags)
    unsigned short unk1A;
    void* m_pkBuffData; // src: XBOX_RETAIL_PDB +0x1c (old: m_pkGeometryRendererData)
};
