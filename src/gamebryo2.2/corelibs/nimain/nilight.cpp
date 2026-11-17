// gamebryo2.2/corelibs/nimain/nilight.cpp: NiLight (11 functions)

#include "../../../../include/NiRenderer.h"
#include "../../../../include/StrArr.h"
#include "../../../../include/BSStreamHeader.h"
#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/NiColor.h"
#include "../../../../include/NiDynamicEffect.h"
#include "../../../../include/NiLight.h"
#include "../../../../include/NiStream.h"

template <class T> inline void ReadBinaryValue(NiStream& stream, T& value)
{
    stream.m_pkIstr->Read(&value, sizeof(T));
}

inline unsigned int NiBinaryStream::Read(void* data, unsigned int size)
{
    unsigned int componentSizes[1] = {size};
    return BinaryRead(data, size, componentSizes, 1);
}

inline unsigned int NiBinaryStream::BinaryRead(void* data, unsigned int size,
    unsigned int* componentSizes, unsigned int components)
{
    unsigned int read = m_pfnRead(this, data, size, componentSizes, components);
    m_uiAbsoluteCurrentPos += read;
    return read;
}

inline NiColor::NiColor()
{
    static_cast<volatile float&>(r) = 0.0f;
    static_cast<volatile float&>(g) = 0.0f;
    static_cast<volatile float&>(b) = 0.0f;
}

// Loads the dimmer value and ambient, diffuse and specular colors from the stream after the base NiDynamicEffect data.
// @fnv 0x00a72080
// pdb: NiLight::LoadBinary | NiLight.obj | retail, upstream name already matches, high
// pdb params: stream
void NiLight::LoadBinary(NiStream& stream)
{
    NiDynamicEffect::LoadBinary(stream);
    ReadBinaryValue(stream, m_fDimmer);
    m_kAmb.LoadBinary(stream);
    m_kDiff.LoadBinary(stream);
    m_kSpec.LoadBinary(stream);
}

// @fnv 0x00a68d40
// pdb: NiDynamicEffect::CopyMembers | NiDynamicEffect.obj | retail, object-file run extension, low
// pdb params: pkDest, kCloning
void NiLight::CopyMemberData(NiLight* clone, CloningProcess& process)
{
    NiAVObject::CopyMembers_00a5ac90(clone, process);
    clone->pushCount = pushCount;
    clone->revID = revID;
    clone->switchState = switchState;
}

extern const char* const g_011f4a68_arg1;

// @fnv 0x00a72000
const NiRTTI* NiLight::GetRTTI() const
{
    return reinterpret_cast<const NiRTTI*>(&g_011f4a68_arg1);
}

extern int DAT_0109ce4c;
void __fastcall DestroyDynamicEffect(NiDynamicEffect*);

// @fnv 0x00a72010
void NiLight::DestroyMembers()
{
    typedef void(__thiscall * Fn_t)(NiRenderer*, void*);
    *(void**)this = (void*)&DAT_0109ce4c;
    NiRenderer* pkRenderer = NiRenderer::ms_pRenderer;
    if (pkRenderer)
        ((Fn_t*)*(void**)pkRenderer)[62](pkRenderer, this);
    DestroyDynamicEffect((NiDynamicEffect*)(void*)this);
}

// @fnv 0x00a72160
// pdb: NiLight::IsEqual | NiLight.obj | retail, upstream name already matches, high
// pdb params: pObject
// pdb locals: pLight
bool NiLight::IsEqual(NiObject* pObject) const
{
    const NiLight* light = static_cast<const NiLight*>(pObject);
    if (NiDynamicEffect::IsEqual(pObject) &&
        m_fDimmer == light->m_fDimmer &&
        !reinterpret_cast<NiPoint3&>(const_cast<NiColor&>(m_kAmb)).operator!=(reinterpret_cast<const NiPoint3&>(light->m_kAmb)) &&
        !reinterpret_cast<NiPoint3&>(const_cast<NiColor&>(m_kDiff)).operator!=(reinterpret_cast<const NiPoint3&>(light->m_kDiff)) &&
        !reinterpret_cast<NiPoint3&>(const_cast<NiColor&>(m_kSpec)).operator!=(reinterpret_cast<const NiPoint3&>(light->m_kSpec)))
        return true;
    return false;
}

char* __cdecl _FUN_00a7d330(const char*);
char* __cdecl NiGetViewerString_00a7d550(const char*, float);

// Appends formatted strings for the dimmer, ambient, diffuse and specular properties to pArray, growing it when full.
// @fnv 0x00a721e0
// pdb: NiLight::GetViewerStrings | NiLight.obj | retail, string-set bridge, high
// pdb params: pStrings
void NiLight::AppendEffectProperties(StrArr* pStrings)
{
    char* pString;

    NiDynamicEffect::AppendEffectProperties(pStrings);

    pString = _FUN_00a7d330(g_011f4a68_arg1);
    {
        unsigned int nIndex = pStrings->m_usSize;
        unsigned int nCapacity = pStrings->m_usMaxSize;
        if (nIndex >= nCapacity)
        {
            unsigned int nGrow = pStrings->m_usGrowBy;
            pStrings->SetSize(nGrow + nIndex);
        }
        pStrings->SetAt(nIndex, pString);
    }

    pString = NiGetViewerString_00a7d550("m_fDimmer", m_fDimmer);
    {
        unsigned int nIndex = pStrings->m_usSize;
        unsigned int nCapacity = pStrings->m_usMaxSize;
        if (nIndex >= nCapacity)
        {
            unsigned int nGrow = pStrings->m_usGrowBy;
            pStrings->SetSize(nGrow + nIndex);
        }
        pStrings->SetAt(nIndex, pString);
    }

    pString = m_kAmb.GetViewerString("m_kAmb");
    {
        unsigned int nIndex = pStrings->m_usSize;
        unsigned int nCapacity = pStrings->m_usMaxSize;
        if (nIndex >= nCapacity)
        {
            unsigned int nGrow = pStrings->m_usGrowBy;
            pStrings->SetSize(nGrow + nIndex);
        }
        pStrings->SetAt(nIndex, pString);
    }

    pString = m_kDiff.GetViewerString("m_kDiff");
    {
        unsigned int nIndex = pStrings->m_usSize;
        unsigned int nCapacity = pStrings->m_usMaxSize;
        if (nIndex >= nCapacity)
        {
            unsigned int nGrow = pStrings->m_usGrowBy;
            pStrings->SetSize(nGrow + nIndex);
        }
        pStrings->SetAt(nIndex, pString);
    }

    pString = m_kSpec.GetViewerString("m_kSpec");
    {
        unsigned int nIndex = pStrings->m_usSize;
        unsigned int nCapacity = pStrings->m_usMaxSize;
        if (nIndex >= nCapacity)
        {
            unsigned int nGrow = pStrings->m_usGrowBy;
            pStrings->SetSize(nGrow + nIndex);
        }
        pStrings->SetAt(nIndex, pString);
    }
}

extern int DAT_0109ce4c;

// Initializes the base and colors, clears the material pointer, and sets the dimmer and colors to 1.0f.
// @fnv 0x00a71f60
// pdb: NiLight::NiLight | NiLight.obj | retail, upstream name already matches, high
NiLight::NiLight()
{
    m_pMaterialData = 0;
    static_cast<volatile float&>(m_fDimmer) = 1.0f;
    static_cast<volatile float&>(m_kAmb.r) = 1.0f;
    static_cast<volatile float&>(m_kAmb.g) = 1.0f;
    static_cast<volatile float&>(m_kAmb.b) = 1.0f;
    static_cast<volatile float&>(m_kDiff.r) = 1.0f;
    static_cast<volatile float&>(m_kDiff.g) = 1.0f;
    static_cast<volatile float&>(m_kDiff.b) = 1.0f;
    static_cast<volatile float&>(m_kSpec.r) = 1.0f;
    static_cast<volatile float&>(m_kSpec.g) = 1.0f;
    static_cast<volatile float&>(m_kSpec.b) = 1.0f;
}

inline unsigned int NiBinaryStream::Write(const void* data, unsigned int size)
{
    unsigned int componentSizes[1] = {size};
    unsigned int written = m_pfnWrite(this, data, size, componentSizes, 1);
    m_uiAbsoluteCurrentPos += written;
    return written;
}
// @fnv 0x00a720f0
// pdb: NiLight::SaveBinary | NiLight.obj | retail, upstream name already matches, high
// pdb params: stream
void NiLight::SaveBinary(NiStream& stream)
{
    NiDynamicEffect::SaveBinary(stream);
    stream.m_pkOstr->Write(static_cast<const void*>(&m_fDimmer), 4);
    m_kAmb.SaveBinary(stream);
    m_kDiff.SaveBinary(stream);
    m_kSpec.SaveBinary(stream);
}

// @fnv 0x00a71f50
// pdb: NiLight::LinkObject | NiLight.obj | debug, upstream name already matches, high
// pdb params: stream
void NiLight::LinkObject(NiStream& stream)
{
    NiDynamicEffect::LinkObject(stream);
}

void __cdecl NiDynamicEffect_RegisterStreamables();

// @fnv 0x00a90010
// src: XBOX_PDB 0x00a90010
// pdb: NiLight::RegisterStreamables | NiLight.obj | debug, upstream name already matches, high
// pdb params: stream
void __cdecl NiLight_RegisterStreamables()
{
    NiDynamicEffect_RegisterStreamables();
}

void __fastcall DestroyDynamicEffect(NiDynamicEffect*);
void __cdecl _delete(void*, unsigned int);
extern int DAT_0109ce4c;

// Sets the vtable, calls UnkF8 on the renderer when present, destroys the dynamic effect, and optionally frees memory when flag bit 0 is set.
// @fnv 0x00a72040
// pdb: NiLight::`scalar deleting destructor' | NiLight.obj | retail, object-file run extension, low
void* NiLight::Destroy(unsigned int auiFlags)
{
    *(void**)this = &DAT_0109ce4c;
    typedef void(__thiscall * Fn_t)(NiRenderer*, void*);
    if (NiRenderer::ms_pRenderer)
        ((Fn_t*)*(void**)NiRenderer::ms_pRenderer)[62](NiRenderer::ms_pRenderer, this);
    DestroyDynamicEffect((NiDynamicEffect*)this);
    if (auiFlags & 1)
        _delete(this, 0xF0);
    return this;
}
