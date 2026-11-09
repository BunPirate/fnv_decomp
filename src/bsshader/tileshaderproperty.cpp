
// src/bsshader/tileshaderproperty.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/bsshader/tileshaderproperty.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#define FNV64_NIPOINTER_INLINE_BODIES
#include "../../include/TileShaderProperty.h"
#include "../../include/NiTexture.h"
#include "../../include/NiStream.h"
#include "../../include/NiBinaryStream.h"

extern "C" void* TileShaderProperty_ms_RTTI;

// @fnv 0x00bb7d60
// src: XBOX_PDB 0x00bb7d60
void* __cdecl TileShaderProperty_GetRTTI()
{
    return &TileShaderProperty_ms_RTTI;
}

// pdb: class TallGrassShader, size 0x1d8 (here 0x40), bases: BSShader, 12 members
struct TallGrassShader
{
    void InitializeConstants(unsigned int);
    char _pad[0x38];
    unsigned int m_comb;
    BSShaderProperty::ShaderPassList* m_aiIndexedValues;
    BSShaderProperty::ShaderPassList* SetupGeometryGroup(NiGeometry*, unsigned int, unsigned int, unsigned int,
                                                         unsigned int, unsigned int);
};
// @fnv 0x00bb7a60
BSShaderProperty::ShaderPassList* TallGrassShader::SetupGeometryGroup(NiGeometry* apGeometry, unsigned int auiValue1,
                                                                      unsigned int auiValue2, unsigned int auiValue3,
                                                                      unsigned int auiValue4, unsigned int auiValue5)
{
    InitializeConstants(1);
    if (m_aiIndexedValues->m_uiCount == 0)
    {
        m_aiIndexedValues->Add(apGeometry, 0x42, true, 0, 0, 0, 0, 0);
        m_aiIndexedValues->m_kRenderPasses.m_pBase[m_aiIndexedValues->m_uiCount - 1]->m_ucLightIndex = 1;
        m_comb = (auiValue3 << 8) | auiValue1;
    }
    return m_aiIndexedValues;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
inline void NiTexture::IncRefCount()
{
    InterlockedIncrement(reinterpret_cast<volatile long*>(&m_uiRefCount));
}
inline void NiTexture::DecRefCount()
{
    if (InterlockedDecrement(reinterpret_cast<volatile long*>(&m_uiRefCount)) == 0)
        DeleteThis();
}
// Replaces m_spTexture.m_pObject with apTexture, releasing the old texture and incrementing the new one's reference count when they differ.
// @fnv 0x00bb7a10
// src: XBOX_PDB 0x00bb7a10
// pdb: TileShaderProperty::SetTileTexture | TileShaderProperty.obj | debug, upstream name already matches, high
// pdb params: apTexture
void TileShaderProperty::SetTileTexture(NiTexture* apTexture)
{
    if (spTileTexture.m_pObject != apTexture)
    {
        if (spTileTexture.m_pObject)
            spTileTexture.m_pObject->DecRefCount();
        spTileTexture.m_pObject = apTexture;
        if (apTexture)
            apTexture->IncRefCount();
    }
}

// @fnv 0x00bb7ac0
// src: XBOX_RETAIL_PDB 0x00bb7ac0
// pdb: TileShaderProperty::CopyMembers | TileShaderProperty.obj | retail, call graph, high
// pdb params: pDest, arCloneData
void TileShaderProperty::CopyMembers(TileShaderProperty* pDest, int arCloneData)
{
    CopyMemberData(pDest, reinterpret_cast<CloningProcess*>(arCloneData));

    NiTexture* pOldTile = pDest->spTileTexture.m_pObject;
    if (pOldTile != spTileTexture.m_pObject)
    {
        if (pOldTile)
            pOldTile->DecRefCount();
        NiTexture* pTileTexture = spTileTexture.m_pObject;
        pDest->spTileTexture.m_pObject = pTileTexture;
        if (pTileTexture)
            pTileTexture->IncRefCount();
    }

    reinterpret_cast<unsigned int&>(pDest->TintColor.r) = reinterpret_cast<unsigned int&>(TintColor.r);
    reinterpret_cast<unsigned int&>(pDest->TintColor.g) = reinterpret_cast<unsigned int&>(TintColor.g);
    reinterpret_cast<unsigned int&>(pDest->TintColor.b) = reinterpret_cast<unsigned int&>(TintColor.b);
    reinterpret_cast<unsigned int&>(pDest->TintColor.a) = reinterpret_cast<unsigned int&>(TintColor.a);
    pDest->TexClampMode = TexClampMode;
    pDest->fAlpha = fAlpha;
    pDest->bUseTexturingProperty = bUseTexturingProperty;
    pDest->bNoBlend = bNoBlend;
}

// @fnv 0x00bb7e70
// src: XBOX_RETAIL_PDB 0x00bb7e70
// pdb: TileShaderProperty::CreateClone | TileShaderProperty.obj | retail, object-file gap fill, high
// pdb params: arCloneData
// pdb locals: pprop
TileShaderProperty* TileShaderProperty::CreateClone(int arCloneData)
{
    TileShaderProperty* result = new TileShaderProperty(false);
    CopyMembers(result, arCloneData);
    return result;
}

inline NiColorA::NiColorA(float fR, float fG, float fB, float fA) : r(fR), g(fG), b(fB), a(fA)
{}

template <> inline BSStringT<char>::BSStringT() : pString(0), sLen(0), sMaxLen(0)
{}

// Initializes the object's texture pointers, color, float fields, flags and integer fields to their default values.
// @fnv 0x00bb7c30
// pdb: TileShaderProperty::TileShaderProperty | TileShaderProperty.obj | retail, upstream name already matches, high
// pdb params: abUseTexturingProperty
TileShaderProperty::TileShaderProperty(bool abUseTexturingProperty)
{
    spTileTexture = 0;
    spAlphaMap = 0;
    TintColor.r = 1.0f;
    TintColor.g = 1.0f;
    TintColor.b = 1.0f;
    TintColor.a = 1.0f;
    fAlpha = 1.0f;
    fTexScrollX[1] = 0.0f;
    fTexScrollX[0] = 0.0f;
    TexClampMode = 3;
    bUseTexturingProperty = abUseTexturingProperty;
    bNoBlend = false;
    bUseTexScroll = false;
    iShader = 0x20;
    iShaderPropertyType = 0x13;
    bUseScissor = false;
    bUseVertexColors = false;
    fTexScrollX[3] = 1.0f;
    fTexScrollX[2] = 1.0f;
}

// the stream's write/read go through its two function pointers; the position counter advances by what they report
inline unsigned int NiBinaryStream::BinaryWrite(const void* pvSrc, unsigned int uiBytes, unsigned int* puiSizes,
                                                unsigned int uiParts)
{
    unsigned int uiDone;
    uiDone = m_pfnWrite(this, pvSrc, uiBytes, puiSizes, uiParts);
    this->m_uiAbsoluteCurrentPos += uiDone;
    return uiDone;
}

inline unsigned int NiBinaryStream::BinaryRead(void* pvDst, unsigned int uiBytes, unsigned int* puiSizes,
                                               unsigned int uiParts)
{
    unsigned int uiDone;
    uiDone = m_pfnRead(this, pvDst, uiBytes, puiSizes, uiParts);
    this->m_uiAbsoluteCurrentPos += uiDone;
    return uiDone;
}

// The shared BSShaderProperty header does not yet declare these two base stream methods.
// This call interface supplies only their declarations, with no duplicate object layout.
struct BSShaderPropertyStreamIO
{
    void BSShaderProperty_LoadBinary(NiStream* stream);
    void BSShaderProperty_SaveBinary(NiStream* kStream);
};
void __cdecl _NiFree_00aa10f0(unsigned int v);
template <class T> inline void LoadBin(NiBinaryStream& kStream, T& val)
{
    unsigned int uiSize = sizeof(T);
    kStream.BinaryRead(&val, sizeof(T), &uiSize, 1);
}

// Loads the base property and tile mode, then reads and assigns the tile name.
// @fnv 0x00bb7b60
// src: XBOX_PDB 0x00bb7b60
// pdb: TileShaderProperty::LoadBinary | TileShaderProperty.obj | retail, object-file gap fill, high
// pdb params: kStream
// pdb locals: pcstring
void TileShaderProperty::LoadBinary_00bb7b60(NiStream* kStream)
{
    reinterpret_cast<BSShaderPropertyStreamIO*>(this)->BSShaderProperty_LoadBinary(kStream);
    LoadBin(*kStream->m_pkIstr, TexClampMode);
    char* v = 0;
    kStream->ReadStreamString(v);
    TextureFilename.Set(v, 0);
    _NiFree_00aa10f0(reinterpret_cast<unsigned int>(v));
}

template <class T> inline void SaveBin(NiBinaryStream& kStream, const T& val)
{
    unsigned int uiSize = sizeof(T);
    kStream.BinaryWrite(&val, sizeof(T), &uiSize, 1);
}
// Saves the base property, tile mode and tile name.
// @fnv 0x00bb7be0
// src: XBOX_PDB 0x00bb7be0
// pdb: TileShaderProperty::SaveBinary | TileShaderProperty.obj | retail, object-file gap fill, high
// pdb params: kStream
void TileShaderProperty::SaveBinary_00bb7be0(NiStream* kStream)
{
    reinterpret_cast<BSShaderPropertyStreamIO*>(this)->BSShaderProperty_SaveBinary(kStream);
    SaveBin(*kStream->m_pkOstr, TexClampMode);
    kStream->SaveCString(TextureFilename.pString);
}
class TexturePool_bb7d
{
  public:
    void MemoryManager_Deallocate(void* apMem);
};
extern TexturePool_bb7d DAT_011f6238;

template <> inline BSStringT<char>::~BSStringT()
{
    if (pString)
        DAT_011f6238.MemoryManager_Deallocate(pString);
    pString = 0;
    sMaxLen = 0;
    sLen = 0;
}

// Releases the tile texture before the member and base destructors run.
// @fnv 0x00bb7d70
// pdb: TileShaderProperty::~TileShaderProperty | TileShaderProperty.obj | retail, upstream name already matches, high
TileShaderProperty::~TileShaderProperty()
{
    spTileTexture = 0;
}
