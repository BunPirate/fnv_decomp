#pragma once

#include "NiMaterialLibrary.h"

class NiMaterial;

// pdb: class NiSingleShaderMaterialLibrary, size 0x14, bases: NiMaterialLibrary, 2 members
class NiSingleShaderMaterialLibrary : public NiMaterialLibrary
{
public:
    NiSingleShaderMaterialLibrary();
    virtual ~NiSingleShaderMaterialLibrary();
    void* Destroy(unsigned int auiFlags);

    virtual NiMaterial* vf02(const NiFixedString* kName);
    virtual const char* GetShaderNameByIndex(unsigned int uiShaderIndex);
    virtual unsigned int vf04();
    virtual void* vf05();
    virtual void* vf06();

    int m_pkLastLibrary;
    int m_uiLastDesc;
};
