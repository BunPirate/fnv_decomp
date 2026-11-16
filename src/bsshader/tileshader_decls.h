// bsshader/tileshader_decls.h: shared property/renderer types and the local TileShader declaration
#ifndef FNV_TILESHADER_DECLS_H
#define FNV_TILESHADER_DECLS_H

#include "../../include/NiPropertyState.h"

#include "../../include/TileShaderProperty.h"
#include "../../include/NiStencilProperty.h"
#include "../../include/BSShader.h"
#include "../../include/NiDX9Renderer.h"
#include "../../include/NiDX9RenderState.h"

// TileShader has no shared header yet; +0x28 is its shader declaration, +0x70/+0x7C its program arrays.
// pdb: class TileShader, size 0x90, bases: BSShader, 5 members
class TileShader : public BSShader
{
  public:
    void UpdateMaterial(const NiPropertyState* state);
    void SetupMaterial(const NiPropertyState* state);
    void RebuildPrograms();
    void NiDX9FragmentShader_RecreateRendererData();

    NiD3DPass* spTileShaderPass; // src: XBOX_RETAIL_PDB +0x6c (old: m_pTilePass)
    NiD3DVertexShader* spTileVertexShader[3]; // src: XBOX_RETAIL_PDB +0x70 (old: m_apVertexShaders)
    NiD3DPixelShader* spTilePixelShader[3]; // src: XBOX_RETAIL_PDB +0x7c (old: m_apPixelShaders)
    void* spShaderDecl[2]; // src: XBOX_RETAIL_PDB +0x88 (old: m_apDeclarations)
};

void AddToCounterIfIdle(unsigned int, unsigned int);
void UpdateRendererStateCount(unsigned int, unsigned int);

#endif
