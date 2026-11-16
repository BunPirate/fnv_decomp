
// src/havok/physics/utilities/serialize/hkphavoksnapshot.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/serialize/hkphavoksnapshot.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../include/hkMemoryRouter.h"
#include "../../../../../include/hkBool.h"

struct CallbackInterface
{
    virtual void reserved0();
    virtual void reserved1();
    virtual void notify(void*, unsigned short);
};
struct State
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    CallbackInterface* interface10;
};
State* __cdecl hkMemoryRouter_getInstance();
struct Object
{
    void* unk00;
    unsigned short unk04;
    void hkpHavokSnapshot_ConvertListener_dtor();
    Object* FUN_00cc0dd0(unsigned int flags);
};
// Calls FUN_00cc0ae0, and if flags has bit 0 set, notifies the interface from FUN_00c85750 with this and unk04; returns this.
// @fnv 0x00cc0dd0
// pdb: hkpHavokSnapshot::ConvertListener::`scalar deleting destructor' | hkpHavokSnapshot.obj | retail, vtable slot, high
Object* Object::FUN_00cc0dd0(unsigned int flags)
{
    hkpHavokSnapshot_ConvertListener_dtor();
    if (flags & 1)
    {
        State* state = hkMemoryRouter_getInstance();
        state->interface10->notify(this, unk04);
    }
    return this;
}

struct D481D0StringPtr
{
    const char* m_pcText;

    D481D0StringPtr();
    void operator=(const char* s);
};

struct D481D0Class
{
    const char* getName() const;
};

struct D481D0ReferencedObject;

struct D481D0RefVariant
{
    D481D0ReferencedObject* m_ptr;

    D481D0RefVariant() : m_ptr(0)
    {}
    void set(D481D0ReferencedObject* obj, const D481D0Class* pClassInfo);
    const D481D0Class* GetVariantValue() const;
};

struct FUN_00d481d0
{
    D481D0StringPtr m_name;
    D481D0StringPtr m_pClassName;
    D481D0RefVariant m_pReferencedResource;

    FUN_00d481d0(const char* name, D481D0ReferencedObject* object, const D481D0Class* pClassInfo);
};

// Stores the name, binds the object with its class, and caches the class name (or null) from the reference variant.
// @fnv 0x00d481d0
FUN_00d481d0::FUN_00d481d0(const char* name, D481D0ReferencedObject* object, const D481D0Class* apClass)
{
    m_name = name;
    m_pReferencedResource.set(object, apClass);
    m_pClassName = m_pReferencedResource.GetVariantValue() ? m_pReferencedResource.GetVariantValue()->getName() : 0;
}

struct CC0D30Result
{
    CC0D30Result();

    int m_iResultCode;
    int m_data;
};

struct CC0D30Registry
{
    int unk00;
};

extern CC0D30Registry g_CC0D30DefaultRegistry;

CC0D30Result __cdecl hkpHavokSnapshot_saveUnderRootLevel(const void* data, const CC0D30Registry& registry, const void* pClassInfo, void* out,
                                  int flags);

// @fnv 0x00cc0d30
// src: HAVOK_LIB 0x00cc0d30
// pdb: hkpHavokSnapshot::save | hkpHavokSnapshot.obj | retail, object-file gap fill, high
// pdb params: data, dataClass, writer, binaryFormat, targetLayout, userListener
// pdb locals: defaultConvertListener
CC0D30Result __cdecl hkpHavokSnapshot_save_00cc0d30(const void* data, const void* writer, void* binaryFormat, int targetLayout)
{
    return hkpHavokSnapshot_saveUnderRootLevel(data, g_CC0D30DefaultRegistry, writer, binaryFormat, targetLayout);
}

struct S_00cc0d60_R
{
    char v;
    S_00cc0d60_R()
    {}
};
struct S_00cc0d60_A
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    void FUN_00d4c220();
    void hkpPhysicsData_populateFromWorld(void* world, int saveContactPoints);
    void FUN_00d4c250();
};
S_00cc0d60_R* hkpHavokSnapshot_save_00cc0d30(void** pa, S_00cc0d60_A* writer, void* binaryFormat, int targetLayout, int d);
// @fnv 0x00cc0d60
// src: HAVOK_LIB 0x00cc0d60
// pdb: hkpHavokSnapshot::save | hkpHavokSnapshot.obj | retail, call graph, medium
// pdb note: debug build links it to hkArrayBase<hkRootLevelContainer::NamedVariant>::clear
// pdb params: data, dataClass, writer, binaryFormat, targetLayout, userListener
// pdb locals: defaultConvertListener
S_00cc0d60_R hkpHavokSnapshot_save_00cc0d60(void* a2, void* a3, int a4, int a5, int a6)
{
    S_00cc0d60_R res;
    void* c;
    c = a2;
    if (c && a3)
    {
        S_00cc0d60_A obj;
        obj.FUN_00d4c220();
        obj.hkpPhysicsData_populateFromWorld(c, a6);
        char r = hkpHavokSnapshot_save_00cc0d30(&a2, &obj, a3, a4, a5)->v;
        obj.FUN_00d4c250();
        res.v = r;
    }
    else
    {
        res.v = 0;
    }
    return res;
}

struct Allocator
{
    virtual void* unk0();
    virtual void* allocate(unsigned int size);
};


struct PtrList;
void __cdecl ResizeAudioStream(void* mem, PtrList* array, unsigned int sizeElem);

struct PtrList
{
    void** m_00;
    unsigned int m_04;
    unsigned int m_08;

    void** Add(void* o)
    {
        unsigned int i = m_04;
        void** slot = &m_00[i];
        *slot = o;
        if (slot == 0)
        {
            return 0;
        }
        m_04++;
        return slot;
    }
};

struct Obj70
{
    unsigned int unk00;
    unsigned short m_04;
    Obj70* FUN_00d4bab0(void* v);
};

struct Obj110
{
    unsigned int unk00;
    unsigned short m_04;
    Obj110* FUN_00d4aa70(void* v);
};

struct Obj80
{
    unsigned int unk00;
    unsigned short m_04;
    Obj80* FUN_00d49750(void* v);
};

struct TypeMatcher
{
    hkBool hkClass_isSuperClass(void* k);
};

struct GlobalObjectO2_00d472a0 : TypeMatcher
{
};
extern GlobalObjectO2_00d472a0 g_01268f2c;
extern GlobalObjectO2_00d472a0 g_01268e24;
extern GlobalObjectO2_00d472a0 g_01268c5c;
extern GlobalObjectO2_00d472a0 g_01268bcc;
extern GlobalObjectO2_00d472a0 hkpStorageMeshShapeClass; // src: XBOX_RETAIL_PDB 0x01268eb4 (old: g_01268eb4/g_unk01268eb4)
extern GlobalObjectO2_00d472a0 hkpStorageExtendedMeshShapeClass; // src: XBOX_RETAIL_PDB 0x01268d4c (old: DAT_01268d4c/g_01268d4c)
extern GlobalObjectO2_00d472a0 hkpStorageSampledHeightFieldShapeClass; // src: XBOX_RETAIL_PDB 0x01268c14 (old: DAT_01268c14/g_01268c14)

struct FUN_00cc08f0_cls
{
    unsigned int unk00;
    unsigned int unk04;
    PtrList m_08;

    void hkpHavokSnapshot_ConvertListener_addObjectCallback(void** p, void** k);
};

// Checks type matchers on *a2, allocates and links a new object into m_08, or clears the pointer when the back-reference matches.
// @fnv 0x00cc08f0
// src: XBOX_PDB 0x00cc08f0
// pdb: hkpHavokSnapshot::ConvertListener::addObjectCallback | hkpHavokSnapshot.obj | retail, upstream name already matches, high
// pdb params: p, k
void FUN_00cc08f0_cls::hkpHavokSnapshot_ConvertListener_addObjectCallback(void** p, void** k)
{
    void** cur = k;

    if (g_01268f2c.hkClass_isSuperClass(*cur))
    {
        if (*cur != (void*)&hkpStorageMeshShapeClass)
        {
            void* v = *p;
            State* h = hkMemoryRouter_getInstance();
            Obj70* o = (Obj70*)((Allocator*)h->interface10)->allocate(0x70);
            o->m_04 = 0x70;
            o = o->FUN_00d4bab0(v);
            PtrList* list = &m_08;
            State* h2 = hkMemoryRouter_getInstance();
            if (list->m_04 == (list->m_08 & 0x3fffffff))
            {
                ResizeAudioStream(h2->interface10, list, 4);
            }
            list->Add(o);
            *p = o;
            *k = (void*)&hkpStorageMeshShapeClass;
            cur = k;
        }
    }
    if (g_01268e24.hkClass_isSuperClass(*cur))
    {
        if (*cur != (void*)&hkpStorageExtendedMeshShapeClass)
        {
            void* v = *p;
            State* h = hkMemoryRouter_getInstance();
            Obj110* o = (Obj110*)((Allocator*)h->interface10)->allocate(0x110);
            o->m_04 = 0x110;
            o = o->FUN_00d4aa70(v);
            PtrList* list = &m_08;
            State* h2 = hkMemoryRouter_getInstance();
            if (list->m_04 == (list->m_08 & 0x3fffffff))
            {
                ResizeAudioStream(h2->interface10, list, 4);
            }
            list->Add(o);
            *p = o;
            *k = (void*)&hkpStorageExtendedMeshShapeClass;
            return;
        }
    }
    if (g_01268c5c.hkClass_isSuperClass(*cur))
    {
        void* v = *p;
        if (((unsigned char*)v)[0x1d] == 2)
        {
            State* h = hkMemoryRouter_getInstance();
            Obj80* o = (Obj80*)((Allocator*)h->interface10)->allocate(0x80);
            o->m_04 = 0x80;
            o = o->FUN_00d49750(v);
            PtrList* list = &m_08;
            State* h2 = hkMemoryRouter_getInstance();
            if (list->m_04 == (list->m_08 & 0x3fffffff))
            {
                ResizeAudioStream(h2->interface10, list, 4);
            }
            list->Add(o);
            *p = o;
            *k = (void*)&hkpStorageSampledHeightFieldShapeClass;
        }
        return;
    }
    if (g_01268bcc.hkClass_isSuperClass(*cur))
    {
        void* v = *p;
        unsigned int* back = (unsigned int*)((unsigned int*)v)[2];
        if (back != 0 && back[9] == (unsigned int)v)
        {
            *p = 0;
            *cur = 0;
        }
    }
}

namespace fnv_00cc0ae0 {
struct PooledItem
{
    virtual void v00(int aiFlags);
};

struct FixedAllocator
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void FreeArray(void* apMemory, unsigned int auiSize) throw();
};

hkMemoryRouter* __cdecl hkMemoryRouter_getInstance() throw();
extern int DAT_010c93e4;
extern int DAT_0102e388;

struct FUN_00cc0ae0_cls
{
    int m_vptr00;
    unsigned int unk04;
    PooledItem** m_pItems;
    int m_iArrayLength;
    unsigned int m_uCapBits;

    void hkpHavokSnapshot_ConvertListener_dtor();
};

// Sets the vtable pointer, calls v00(1) on each non-null item, frees the item array, empties it, and sets the vtable pointer to DAT_0102e388.
// @fnv 0x00cc0ae0
// src: XBOX_RETAIL_PDB 0x00cc0ae0
// pdb: hkpHavokSnapshot::ConvertListener::~ConvertListener | hkpHavokSnapshot.obj | retail, object-file gap fill, high
void FUN_00cc0ae0_cls::hkpHavokSnapshot_ConvertListener_dtor()
{
    m_vptr00 = (int)&DAT_010c93e4;
    for (int i = 0; i < m_iArrayLength; i++)
    {
        PooledItem* item = m_pItems[i];
        if (item != 0)
        {
            item->v00(1);
        }
    }
    hkMemoryRouter* holder = hkMemoryRouter_getInstance();
    FixedAllocator* alloc = (FixedAllocator*)holder->m_heap;
    unsigned int cap = m_uCapBits;
    m_iArrayLength = 0;
    if ((cap & 0x80000000u) == 0)
    {
        alloc->FreeArray(m_pItems, (cap & 0x3fffffffu) * 4);
    }
    m_pItems = 0;
    m_uCapBits = 0x80000000u;
    *(volatile int*)&m_vptr00 = (int)&DAT_0102e388;
}
}  // namespace fnv_00cc0ae0

namespace fnv_00cc0b50 {
struct SlotRec
{
    unsigned short m_u0;
    unsigned short m_flag;
    unsigned int m_kPointA;
    unsigned int m_kPointB;
    unsigned int m_iThirdValue;
};

struct SpawnedObject
{
    virtual void* v00();
    SlotRec m_slot;
    void hkpHavokSnapshot_ConvertListener_dtor();
    SpawnedObject()
    {
        m_slot.m_flag = 1;
        m_slot.m_kPointA = 0;
        m_slot.m_kPointB = 0;
        m_slot.m_iThirdValue = 0x80000000;
    }
};

int hkSerializeUtil_saveTagfile(unsigned int object, unsigned int klass, unsigned int writer, int binary, SpawnedObject* userListener);

struct InputBool223
{
    unsigned char value;
    inline operator bool() const
    {
        return value != 0;
    }
};
// Calls FUN_00d485a0 with a2, a3, a4, (bool)a5 and ctx (or a local object if null), stores whether it returned 0 into *out, and returns out.
// @fnv 0x00cc0b50
// src: HAVOK_LIB 0x00cc0b50
// pdb: hkpHavokSnapshot::save | hkpHavokSnapshot.obj | retail, object-file gap fill, medium
// pdb note: debug build links it to hkSerializeUtil::saveTagfile
// pdb params: data, dataClass, writer, binaryFormat, targetLayout, userListener
// pdb locals: defaultConvertListener
unsigned char* hkpHavokSnapshot_save(unsigned char* apResult, unsigned int a2, unsigned int a3, unsigned int a4,
                            InputBool223 abFlag, unsigned int unk2c, SpawnedObject* ctx)
{
    SpawnedObject* pCtx = ctx;
    SpawnedObject localCtx;
    if (pCtx == 0)
    {
        pCtx = &localCtx;
    }
    int r = hkSerializeUtil_saveTagfile(a2, a3, a4, (bool)abFlag, pCtx);
    *apResult = (unsigned char)(r == 0);
    localCtx.hkpHavokSnapshot_ConvertListener_dtor();
    return apResult;
}
}  // namespace fnv_00cc0b50
