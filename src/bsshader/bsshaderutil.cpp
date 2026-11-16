// bsshader/bsshaderutil.cpp: BSShaderRenderUtility_bsshaderutil (7 functions)

#include <d3d9.h>

// BSShaderRenderUtility_bsshaderutil: local type (was include/BSShaderRenderUtility.h, which had no evidence of one real class); its methods are 0x00469860 TESDataHandler::IsFormIDCreated, 0x00b6ba70 BSShaderUtil::InitSDM, 0x00b6bb30 BSShaderUtil::RecursiveSetPropertyFadeAlpha, 0x00b6c0d0 BSShaderUtil::RenderScene
class AnimIdle;
class BSShaderAccumulator;
class NiCamera;
class NiNode;

// pdb: class BSShaderUtil, size 0x1, 0 members
class BSShaderUtil // src: XBOX_RETAIL_PDB 0x00b6b940 (first of 10 linked methods; old: BSShaderRenderUtility_bsshaderutil)
{
public:
    bool IsRenderTargetId(unsigned int value);
    static void InitSDM();
    static void SetRenderCamera(NiCamera* apCamera, BSShaderAccumulator* apAccumulator, bool abUseSPU);
    static void SetRenderCamera(AnimIdle* camera, AnimIdle* accumulator, bool unused);
    static void SetRenderCamera(void* camera, unsigned int accumulator, bool unused);
    static void RecursiveSetPropertyFadeAlpha(NiNode* apNode, float afAlpha);
};
#include "../../include/BSSimpleArray.h"
#include "../../include/NiTPointerMap.h"
#include "../../include/NiTListItem.h"
#include "../../include/MemoryManager.h"
#include "../../include/NiRefObject.h"
#include "../../include/NiFixedString.h"
#include "../../include/NiAVObject.h"
#include "../../include/NiTexture.h"
#include "../../include/NiNode.h"
#include "../../include/NiGeometry.h"
#include "../../include/BSShaderProperty.h"
#include "../../include/NiBound.h"
#include "../../include/NiRenderer.h"
#include "../../include/NiDX9Renderer.h"
#include "../../include/NiSourceTexture.h"
#include "../../include/NiPixelFormat.h"
#include "../../include/NiPixelData.h"
#include "../../include/NiMemObject.h"
#include "../../include/BSShaderAccumulator.h"
#include "../../include/BSCullingProcess.h"
#include "../../include/NiDX9TextureData.h"

extern NiCamera* DAT_011f917c;
extern void* DAT_011fa050;
extern void* DAT_011fa054;
extern MemoryManager g_memoryManager;
void BSShaderManager_SetCurrentAccumulator(BSShaderAccumulator* apAccum);

inline void* NiFixedString::operator new(size_t size)
{
    return g_memoryManager.Allocate(size);
}
inline void NiFixedString::operator delete(void* pointer)
{
    g_memoryManager.Deallocate(pointer);
}

#pragma optimize("", off)
// @fnv 0x00469860
bool BSShaderUtil::IsRenderTargetId(unsigned int value)
{
    return value >= 0xff000000u;
}

#pragma optimize("", on)

// Allocates two NiFixedString objects and stores them in DAT_011fa050 and DAT_011fa054.
// @fnv 0x00b6ba70
// src: XBOX_RETAIL_PDB 0x00b6ba70
// pdb: BSShaderUtil::InitSDM | BSShaderUtil.obj | retail, string-set bridge, high
void BSShaderUtil::InitSDM()
{
    DAT_011fa050 = new NiFixedString("ConvertedTexture");
    DAT_011fa054 = new NiFixedString("BackgroundConvertedTexture");
}

// @fnv 0x00b6c0d0
// pdb: BSShaderUtil::RenderScene | BSShaderUtil.obj | retail, call graph, high
// pdb params: apCamera, apAccumulator, abUseSPU
void BSShaderUtil::SetRenderCamera(NiCamera* apCamera, BSShaderAccumulator* apAccumulator, bool)
{
    typedef void (__thiscall* AccumulatorCallback)(BSShaderAccumulator*);
    if (NiRenderer::ms_pRenderer && apCamera)
    {
        NiRenderer::ms_pRenderer->SetCurrentCamera(apCamera);
        DAT_011f917c = apCamera;
        BSShaderManager_SetCurrentAccumulator(apAccumulator);
        apAccumulator->StartAccumulating(apCamera);
        // The shared accumulator does not yet declare the callbacks at 0xa8 and 0xac.
        ((AccumulatorCallback)(*(void***)apAccumulator)[0xa8 / 4])(apAccumulator);
    }
    ((AccumulatorCallback)(*(void***)apAccumulator)[0xac / 4])(apAccumulator);
}

// @fnv 0x00b6bb30
// src: XBOX_RETAIL_PDB 0x00b6bb30
// pdb: BSShaderUtil::RecursiveSetPropertyFadeAlpha | BSShaderUtil.obj | retail, call graph (shared callers), high
// pdb params: apNode, afAlpha
// pdb locals: n, pObj, pgeom, pProperty, pShaderProp
void BSShaderUtil::RecursiveSetPropertyFadeAlpha(NiNode* apNode, float afAlpha)
{
    if (apNode && apNode->m_kWorldBound && reinterpret_cast<NiBound*>(apNode->m_kWorldBound)->m_fRadius != 0.0f)
    {
        for (unsigned int i = 0; i < apNode->m_kChildren.m_usSize; ++i)
        {
            NiAVObject* child = apNode->m_kChildren.m_pBase[i].m_pObject;
            if (child)
            {
                NiGeometry* properties = child->IsGeometry();
                if (properties)
                {
                    if (&properties->m_PropertyState)
                    {
                        BSShaderProperty* state = static_cast<BSShaderProperty*>(properties->m_PropertyState.m_aspProps[3]);
                        if (state)
                        {
                            state = state->iShaderPropertyType != -1 ? state : 0;
                            if (state)
                                state->fFadeAlpha = afAlpha;
                        }
                    }
                }

                BSShaderUtil::RecursiveSetPropertyFadeAlpha(child->IsSceneNode(), afAlpha);
            }
        }
    }
}

inline void NiRefObject::IncRefCount()
{
    InterlockedIncrement((volatile long*)&m_uiRefCount);
}

inline void NiRefObject::DecRefCount()
{
    if (InterlockedDecrement((volatile long*)&m_uiRefCount) == 0)
        DeleteThis();
}

template <class T> inline NiPointer<T>::NiPointer() : m_pObject(0) {}
template <class T> inline NiPointer<T>::NiPointer(T* pkNew) : m_pObject(pkNew)
{
    if (m_pObject != 0)
        m_pObject->IncRefCount();
}
template <class T> inline NiPointer<T>::NiPointer(const NiPointer& kSrc) : m_pObject(kSrc.m_pObject)
{
    if (m_pObject != 0)
        m_pObject->IncRefCount();
}
template <class T> inline NiPointer<T>::~NiPointer()
{
    if (m_pObject != 0)
        m_pObject->DecRefCount();
}
template <class T> inline NiPointer<T>::operator T*() const { return m_pObject; }
template <class T> inline NiPointer<T>& NiPointer<T>::operator=(T* pkNew)
{
    if (m_pObject != pkNew)
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
        m_pObject = pkNew;
        if (m_pObject != 0)
            m_pObject->IncRefCount();
    }
    return *this;
}

extern NiPointer<NiRefObject> g_spCurrentAccumulator;

// Stores the given BSShaderAccumulator into the global g_spCurrentAccumulator smart pointer.
// @fnv 0x00b54b10
// src: COMMUNITY 0x00b54b10
// pdb: BSShaderManager::SetCurrentAccumulator | BSShaderManager.obj | debug, upstream name already matches, high
// pdb params: apAccum
void BSShaderManager_SetCurrentAccumulator(BSShaderAccumulator* apAccum)
{
    g_spCurrentAccumulator = reinterpret_cast<NiRefObject*>(apAccum);
}

// The shared renderer lacks this setter; retain only its member-call ABI.
struct RendererAccumulatorCall
{
    void NiTexturingProperty_Map_SetTexture(NiRefObject* pkTexture);
};
extern NiRenderer* DAT_011f4748;
void __cdecl BSShaderManager_SetAccumulator(NiRefObject* apAccum);

// Slot18 has not yet acquired its camera/object signature in the shared header.
inline void SetSortingCamera(BSCullingProcess* process, void* camera, void* object, int flags)
{
    typedef void (__thiscall* SetCamera)(BSCullingProcess*, void*, void*, int);
    ((SetCamera)(*(void***)process)[0x48 / 4])(process, camera, object, flags);
}

template <class Allocator, class T> inline void* NiTListBase<Allocator, T>::GetHeadPos() const
{
    return m_pkHead;
}

inline void* NextObject(void*& position)
{
    if (position)
    {
        void*& object = static_cast<NiTListItem<void*>*>(position)->m_element;
        position = static_cast<NiTListItem<void*>*>(position)->m_pkNext;
        return object;
    }
    return 0;
}

// Sets the sorting camera from the first list item, then registers later items when the manager and camera are non-null.
// @fnv 0x00b6bfc0
// src: COMMUNITY 0x00b6bfc0
// pdb: BSShaderUtil::AccumulateSceneList | BSShaderUtil.obj | retail, upstream name already matches, high
// pdb params: apCamera, aSceneList, aCuller
// pdb locals: spaccum, prenderer, iter, pscene, pnextscene
void __cdecl BSShaderUtil_AccumulateSceneList(void* apCamera, NiTPointerList<void*>& aSceneList, BSCullingProcess* aCuller)
{
    if (!DAT_011f4748 || !apCamera)
        return;

    NiPointer<NiRefObject> spRetainedObject = *reinterpret_cast<NiPointer<NiRefObject>*>(&DAT_011f4748->m_spAccum);
    reinterpret_cast<RendererAccumulatorCall*>(DAT_011f4748)->NiTexturingProperty_Map_SetTexture(
        reinterpret_cast<NiPointer<NiRefObject>&>(aCuller->m_acRendererDataA));
    BSShaderManager_SetAccumulator(reinterpret_cast<NiPointer<NiRefObject>&>(aCuller->m_acRendererDataA));

    void* kPos = aSceneList.GetHeadPos();
    if (kPos)
    {
        SetSortingCamera(aCuller, apCamera, NextObject(kPos), 0);
        if (kPos)
        {
            void* pvObject = NextObject(kPos);
            do
            {
                void* pvCurrent = pvObject;
                pvObject = NextObject(kPos);
                aCuller->Process(static_cast<NiAVObject*>(pvCurrent));
            } while (pvObject);
        }
    }
}

// Preserve the original NiMemObject allocation and exception cleanup calls.


namespace fnv_00b6bbd0 {

void _memmove(void* destination, const void* source, unsigned int size);

extern NiDX9Renderer* DAT_011f4748;
extern unsigned char DAT_011f4448;
extern bool DAT_011a9595;
extern NiTexture::TextureFormatPreferences DAT_011a9598;
int FUN_00e7bd20(const NiPixelFormat*);
HRESULT __stdcall D3DXLoadSurfaceFromSurface_00ee6de6(IDirect3DSurface9*, const PALETTEENTRY*, const RECT*, IDirect3DSurface9*,
                               const PALETTEENTRY*, const RECT*, DWORD, D3DCOLOR);
NiTexture* NiSourceTexture_Create(NiPixelData*, void*, NiTexture::TextureFormatPreferences*);

// Converts a NiTexture to a supported D3D format by copying each mip level and swapping RGB bytes when needed, then builds a new NiTexture from the result.
// @fnv 0x00b6bbd0
// src: COMMUNITY 0x00b6bbd0
// pdb: BSShaderUtil::ConvertTexture | BSShaderUtil.obj | retail, upstream name already matches, high
// pdb params: apTex, arFormat
// pdb locals: pd3ddestSurface, iwidth, uimipSize, pd3dsourceSurface, dwalloc, ptexdataSource, fmt, ptexMem, apRenderer, efmt, pd3dtexSource, prd, pd3dtexDest, ptexReturn, iheight, inumMipMaps, allocAttribs, pdx9device, uibaseSize, imipmap
NiTexture* BSShaderUtil_ConvertTexture(NiTexture* apTex, const NiPixelFormat* arFormat)
{
    NiDX9Renderer* renderer = DAT_011f4748;
    NiPixelFormat format = *arFormat;
    if (!apTex || !renderer)
        return 0;
    int d3dFormat = FUN_00e7bd20(&format);
    switch (d3dFormat)
    {
    case 32:
        d3dFormat = 21;
        break;
    case 21:
    case 0x31545844:
    case 0x33545844:
    case 0x35545844:
        break;
    default:
        return 0;
    }
    IDirect3DDevice9* device = renderer->pD3DDevice;
    unsigned int width = apTex->GetWidth();
    unsigned int height = apTex->GetHeight();
    // The converted texture is a source texture; its pixel-data pointer is at 0x3c.
    NiPixelData* mipData = static_cast<NiSourceTexture*>(apTex)->m_spSrcPixelData.m_pObject;
    unsigned int levels = mipData ? mipData->m_uiMipmapLevels : 1;
    // GetTexture is not yet declared by the shared DX9 texture-data header.
    typedef IDirect3DTexture9* (__thiscall* GetD3DTexture)(NiDX9TextureData*);
    IDirect3DTexture9* source = ((GetD3DTexture)(*(void***)apTex->m_pkRendererData)[0x9c / 4])(
        static_cast<NiDX9TextureData*>(apTex->m_pkRendererData));
    IDirect3DTexture9* destination;
    HRESULT hStatus =
        device->CreateTexture(width, height, levels, 0, (D3DFORMAT)d3dFormat, D3DPOOL_SYSTEMMEM, &destination, 0);
    NiPixelData* pixels = 0;
    if (hStatus != 0 || !destination)
        return 0;
    IDirect3DSurface9* sourceSurface;
    IDirect3DSurface9* destinationSurface;
    D3DLOCKED_RECT lockedRect;
    // The pointer overload retains the original throwing-constructor cleanup.
    pixels = new NiPixelData(width, height, &format, levels, 1);
    for (unsigned int level = 0; level < levels; ++level)
    {
        source->GetSurfaceLevel(level, &sourceSurface);
        destination->GetSurfaceLevel(level, &destinationSurface);
        D3DXLoadSurfaceFromSurface_00ee6de6(destinationSurface, 0, 0, sourceSurface, 0, 0, 0xffffffff, 0);
        destinationSurface->LockRect(&lockedRect, 0, 0);
        if (d3dFormat == 21)
        {
            _memmove(pixels->m_pucPixels + pixels->m_puiOffsetInBytes[level], lockedRect.pBits,
                     pixels->m_puiHeight[level] * lockedRect.Pitch);
            unsigned char* pPixelData = pixels->m_pucPixels + pixels->m_puiOffsetInBytes[level];
            unsigned int bytes = pixels->m_puiWidth[level] * pixels->m_puiHeight[level] * 4;
            for (unsigned int offset = 0; offset < bytes; offset += 4)
            {
                unsigned char red = pPixelData[offset];
                pPixelData[offset] = pPixelData[offset + 2];
                pPixelData[offset + 2] = red;
            }
        }
        else if (d3dFormat == 0x31545844 || d3dFormat == 0x33545844 || d3dFormat == 0x35545844)
        {
            unsigned char* pPixelData = pixels->m_pucPixels + pixels->m_puiOffsetInBytes[level];
            unsigned int rows = pixels->m_puiHeight[level];
            if (rows < 4)
                rows = 4;
            _memmove(pPixelData, lockedRect.pBits, (rows * lockedRect.Pitch) / 4);
        }
        destinationSurface->UnlockRect();
        destinationSurface->Release();
        sourceSurface->Release();
    }
    destination->Release();
    unsigned char oldFlag = DAT_011f4448;
    DAT_011f4448 = 0;
    void* pvGlobalData = *(void**)DAT_011fa050;
    NiTexture* pResultTexture = NiSourceTexture_Create(pixels, pvGlobalData, &DAT_011a9598);
    DAT_011a9595 = levels > 1;
    DAT_011f4448 = oldFlag;
    return pResultTexture;
}
}  // namespace fnv_00b6bbd0
