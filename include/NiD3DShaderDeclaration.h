#pragma once

#include "NiShaderDeclaration.h"
#include "NiSkinPartition.h"

class GraphicsRenderer;
class VertexDeclarationLayout;
class Direct3DDeviceInterface;
class NiD3DShaderDeclaration__ShaderRegisterStream;
class NiGeometryData;
class NiSkinInstance;
class NiVBChip;
struct IDirect3DVertexDeclaration9;

// pdb: class NiD3DShaderDeclaration, size 0x2c, bases: NiShaderDeclaration, 9 members
class NiD3DShaderDeclaration : public NiShaderDeclaration
{
public:
    class ShaderStreamInfo;

    NiD3DShaderDeclaration();
    virtual ~NiD3DShaderDeclaration();
    NiD3DShaderDeclaration& operator=(const NiD3DShaderDeclaration&);

    virtual bool SetEntry(unsigned int, unsigned int, ShaderParameter,
                          ShaderParameterType, unsigned int);
    virtual bool RemoveEntry(unsigned int, unsigned int);
    virtual bool SetEntryAlt(unsigned int, unsigned int, unsigned int,
                             ShaderParameter, ShaderParameterType, ShaderParameterUsage,
                             unsigned int, ShaderParameterTesselator);
    virtual void SetFloatValues(unsigned int, unsigned int, float*);
    virtual void ClearAllEntries(unsigned int);
    virtual unsigned int GetVertexStride(unsigned int);
    virtual void SetSoftwareVertexProcessing();
    virtual bool GetSoftwareVertexProcessing();
    virtual NiVBChip* CreateVertexBufferChip(NiGeometryData*, NiSkinInstance*,
                                             NiSkinPartition::Partition*, unsigned short,
                                             NiVBChip*, unsigned int, void*);
    virtual bool GenerateVertexParameters(IDirect3DVertexDeclaration9**, unsigned int*);
    virtual IDirect3DVertexDeclaration9* GetD3DDeclaration();

    bool SetEntryAlt(unsigned int, unsigned int, unsigned int, unsigned int,
                     unsigned int, unsigned int, unsigned int, unsigned int);
    void Finalize();

    GraphicsRenderer* m_pkRenderer; // src: XBOX_RETAIL_PDB +0x8 (old: m_pOwnerShader)
    VertexDeclarationLayout* m_pkVBManager; // src: XBOX_RETAIL_PDB +0xc (old: m_pShaderStreamInfo)
    Direct3DDeviceInterface* m_pkD3DDevice; // src: XBOX_RETAIL_PDB +0x10 (old: m_pD3DDevice)
    unsigned int m_uiDeclSize; // src: XBOX_RETAIL_PDB +0x14 (old: m_uiVertexElementCount)
    unsigned int m_uiCurrDeclIndex; // src: XBOX_RETAIL_PDB +0x18 (old: m_uiBufferStride)
    unsigned int m_uiMaxStreamEntryCount; // src: XBOX_RETAIL_PDB +0x1c (old: m_uiShaderRegisterCount)
    unsigned int m_uiStreamCount; // src: XBOX_RETAIL_PDB +0x20 (old: m_uiRegisterStreamCount)
    NiD3DShaderDeclaration__ShaderRegisterStream* m_pkStreamEntries; // src: XBOX_RETAIL_PDB +0x24 (old: m_pShaderRegisterStream)
    bool m_bModified; // src: XBOX_RETAIL_PDB +0x28 (old: m_bHasChanges)
    unsigned char layoutPadding29[3];
};
