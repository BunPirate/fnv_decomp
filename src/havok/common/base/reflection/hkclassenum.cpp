
// src/havok/common/base/reflection/hkclassenum.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/reflection/hkclassenum.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../include/hkCustomAttributes.h"

extern "C" int __cdecl FUN_00d86980();

// Reads a signed char, short or int from p depending on the size returned by FUN_00d86980, defaulting to 0.
// @fnv 0x00d86b80
// src: XBOX_RETAIL_PDB 0x00d86b80
// pdb: hkClassMember::getEnumValue | hkClassMember.obj | retail, call graph, high
// pdb params: memberAddress
int __stdcall hkClassMember_getEnumValue(const void* memberAddress)
{
    int r = 0;
    switch (FUN_00d86980())
    {
    case 1:
        r = *(const signed char*)memberAddress;
        break;
    case 2:
        r = *(const signed short*)memberAddress;
        break;
    case 4:
        r = *(const int*)memberAddress;
        break;
    }
    return r;
}

struct FUN_00db76a0_Class
{
    void* __thiscall GetAttribute(void* arg);
};

// @fnv 0x00db76a0
void* FUN_00db76a0_Class::GetAttribute(void* arg)
{
    hkCustomAttributes* a = *(hkCustomAttributes**)((char*)this + 0xc);
    if (a)
        return a->getAttribute(arg);
    return 0;
}

struct FUN_00db7860
{
    int m_00;
    int m_04;
    int m_08;
    ~FUN_00db7860() throw();
};

struct FUN_00db7870 : public FUN_00db7860
{
    FUN_00db7870(int n) throw();
};

struct hkObjDB76
{
    void writeSignature(FUN_00db7860* w) throw();
    void hkClassEnum_getSignature();
};

// Constructs a temporary FUN_00db7870 with 0 and passes it to FUN_00db7600.
// @fnv 0x00db76c0
// src: HAVOK_LIB 0x00db76c0
// pdb: hkClassEnum::getSignature | hkClassEnum.obj | retail, upstream name already matches, high
// pdb locals: crc
void hkObjDB76::hkClassEnum_getSignature()
{
    FUN_00db7870 tmp(0);
    writeSignature(&tmp);
}

template <int SIZE> __forceinline void memCpyOneAlignedXdb76f0(void* dst, const void* src)
{
    const unsigned int* s = (const unsigned int*)src;
    unsigned int* d = (unsigned int*)dst;
    int i = 0;
    do
    {
        d[i] = s[i];
    } while (++i < SIZE / 4);
}

struct hkMemoryRouterXdb76f0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void* m_pStreamAllocator;
};

namespace hkRouterXdb76f0 {
extern "C" hkMemoryRouterXdb76f0& __cdecl hkMemoryRouter_getInstance() throw();
}
void __cdecl ResizeAudioStream(void* mem, void* array, int sizeElem);

template <class T> class hkArrayXdb76f0LocalForm
{ // local form of hkArray: 0x00db76f0 needs the original inline/out-of-line helper split; shared replacement changes bytes.
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void AddBack(const T& e)
    {
        hkMemoryRouterXdb76f0& router = hkRouterXdb76f0::hkMemoryRouter_getInstance();
        if (m_iElementCount == getCapacity())
            ResizeAudioStream(router.m_pStreamAllocator, this, sizeof(T));
        memCpyOneAlignedXdb76f0<sizeof(T)>(m_data + m_iElementCount, &e);
        m_iElementCount++;
    }
};

struct hkEntryXdb76f0
{
    unsigned int m_flags;
    void* m_uiFilterValue;
};

class hkOwnerXdb76f0
{
  public:
    int unk00;
    hkArrayXdb76f0LocalForm<hkEntryXdb76f0> m_entries;

    bool CollectMatchingEntries(unsigned int flagValue, hkArrayXdb76f0LocalForm<void*>& bitsOut, unsigned int* bitsOver);
};

// Iterates m_entries in reverse, adds entries whose m_flags are a subset of flags to out, and stores the unmatched bits in remaining.
// @fnv 0x00db76f0
// pdb: hkClassEnum::decomposeFlags | hkClassEnum.obj | retail, call graph, high
// pdb params: flagValue, bitsOut, bitsOver
// pdb locals: assertBuf, ostr
bool hkOwnerXdb76f0::CollectMatchingEntries(unsigned int flagValue, hkArrayXdb76f0LocalForm<void*>& bitsOut, unsigned int* bitsOver)
{
    bitsOut.m_iElementCount = 0;
    for (int i = m_entries.m_iElementCount - 1; i >= 0 && flagValue; i--)
    {
        hkEntryXdb76f0& e = m_entries.m_data[i];
        unsigned int f = e.m_flags;
        if ((f & flagValue) == f)
        {
            void* value = e.m_uiFilterValue;
            bitsOut.AddBack(value);
            flagValue &= ~f;
        }
    }
    *bitsOver = flagValue;
    return flagValue != 0;
}
