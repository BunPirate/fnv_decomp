#include "../../../../include/BSFadeNode.h"
#include "../../../../include/NiObject.h"
#include "../../../../include/NiSpecularProperty.h"
#include "../../../../include/NiCullingProperty.h"

// src/gamebryo2.2/corelibs/nimain/nispecularproperty.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/nispecularproperty.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern int DAT_010a02e4;
inline NiSpecularProperty::NiSpecularProperty() throw()
{
    *(void**)this = (void*)&DAT_010a02e4;
    m_uFlags = 0;
}
// @fnv 0x00a95110
// pdb: NiSpecularProperty::CreateClone | NiSpecularProperty.obj | retail, object-file run extension, low
// pdb note: debug build links it to NiSpecularProperty::CopyMembers
// pdb params: kCloning
// pdb locals: pkObject
NiObject* NiSpecularProperty::MakeClone(CloningProcess& kCloning)
{
    NiSpecularProperty* pkObject = new NiSpecularProperty;
    ((NiCullingProperty*)this)->NiProperty_CopyMembers(pkObject, kCloning);
    pkObject->m_uFlags = m_uFlags;
    return pkObject;
}

extern unsigned int NiSpecularProperty_ms_RTTI;

unsigned int __cdecl NiViewerStrings_NiGetViewerString_Title(unsigned int key);
unsigned int __cdecl NiGetViewerString(const char* pcPrefix, unsigned int bValue);

struct FUN_00a951f0_list
{
    int unk00;
    int unk04;
    unsigned short m_08;
    unsigned short m_0a;
    unsigned short unk0c;
    unsigned short m_0e;
    void FUN_0096ad30(unsigned int newCapacity);
    void FUN_0096ae90(unsigned int index, void* item);
};

// The shared headers do not declare the property viewer overrides. These
// entry points pass this in ECX and leave EDX unused, as the original does.
void __fastcall NiProperty_GetViewerStrings(NiProperty* property, void*, FUN_00a951f0_list* list);

// @fnv 0x00a951f0
// pdb: NiSpecularProperty::GetViewerStrings | NiSpecularProperty.obj | retail, string-set bridge, high
// pdb params: pkStrings
void __fastcall NiSpecularProperty_GetViewerStrings(NiSpecularProperty* property, void* unusedEDX,
                                                   FUN_00a951f0_list* list)
{
    NiProperty_GetViewerStrings(property, unusedEDX, list);
    unsigned int item = NiViewerStrings_NiGetViewerString_Title(NiSpecularProperty_ms_RTTI);
    unsigned int count = list->m_0a;
    if (count >= list->m_08)
        list->FUN_0096ad30(count + list->m_0e);
    list->FUN_0096ae90(count, &item);

    unsigned char ucSpecFlag = (unsigned char)property->m_uFlags;
    ucSpecFlag &= 1;
    *(volatile unsigned char*)&item = ucSpecFlag;
    unsigned int result = NiGetViewerString("m_bSpec", *(volatile unsigned int*)&item);
    *(volatile unsigned int*)&item = result;

    count = list->m_0a;
    if (count >= list->m_08)
        list->FUN_0096ad30(count + list->m_0e);
    list->FUN_0096ae90(count, &item);
}
