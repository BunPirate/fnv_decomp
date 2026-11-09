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

    GraphicsRenderer* m_pkRenderer;
    VertexDeclarationLayout* m_pkVBManager;
    Direct3DDeviceInterface* m_pkD3DDevice;
    unsigned int m_uiDeclSize;
    unsigned int m_uiCurrDeclIndex;
    unsigned int m_uiMaxStreamEntryCount;
    unsigned int m_uiStreamCount;
    NiD3DShaderDeclaration__ShaderRegisterStream* m_pkStreamEntries;
    bool m_bModified;
    unsigned char layoutPadding29[3];
};
