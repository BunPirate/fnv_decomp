#pragma once

#include "NiMaterial.h"
#include "NiFixedString.h"

class NiShader;
class NiGeometry;
class NiSkinInstance;
class NiPropertyState;
class NiDynamicEffectState;

// pdb: class NiSingleShaderMaterial, size 0x18, bases: NiMaterial, 3 members
class NiSingleShaderMaterial : public NiMaterial
{
public:
    virtual ~NiSingleShaderMaterial();
    virtual void* GetGlobalObjectAddress_00aa06e0();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual bool __thiscall MatchesShaderFilename(NiShader* pkShader, const NiGeometry* pkGeometry,
                                                 const NiSkinInstance* pkSkinInstance,
                                                 const NiPropertyState* pkPropertyState,
                                                 const NiDynamicEffectState* pkDynamicEffectState,
                                                 unsigned int uiMaterialExtraData);
    virtual NiShader* GetCurrentShader(int pkGeom, int pkSkin, int pkPropState, int pkEffectState, int uiMaterialExtraData);
    virtual void ReleaseShader();
    virtual void vf21();

    NiSingleShaderMaterial* NiSingleShaderMaterial_00aa06f0(void* name, const char* filename, bool createShader);
    NiSingleShaderMaterial* Destroy(unsigned char flags);
    void BaseCleanup();

    unsigned int unk08;
    NiFixedString m_kShaderName;
    NiShader* m_spCachedShader;
    bool m_bManualShaderManagement;
    unsigned char unk15[3];
};
