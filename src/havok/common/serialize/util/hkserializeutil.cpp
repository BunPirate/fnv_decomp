#include "../../../../../include/hkArray.h"

// src/havok/common/serialize/util/hkserializeutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/serialize/util/hkserializeutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../include/hkReferencedObject.h"
#include "../../../../../include/Pair.h"
#include "../../../../../include/hkStringPtr.h"

void __cdecl Object_ForwardCall_00d48620(int a, int b, int c);

// @fnv 0x00d48640
// src: GUESS 0x00d48640 (confidence: low)
void __cdecl Object_ForwardCall_00d48640(int a, int b)
{
    Object_ForwardCall_00d48620(a, b, 1);
}

extern "C" void __cdecl hkSerializeUtil_saveTagfile(int, int, int, int, int);

// @fnv 0x00d48660
// src: GUESS 0x00d48660 (confidence: low)
void __cdecl Object_ForwardCall_00d48660(int a, int b, int c)
{
    hkSerializeUtil_saveTagfile(a, b, c, 1, 0);
}

extern int DAT_0102e388;
extern int DAT_010d7540;

struct FUN_00dcc160_cls
{
    void* vtbl;
    int a;
    hkReferencedObject* b;
    void SetVirtualTable_00dcc160();
};

// @fnv 0x00dcc160
// src: GUESS 0x00dcc160 (confidence: low)
// pdb: hkIstream::~hkIstream | hkIStream.obj | retail, call graph, medium
void FUN_00dcc160_cls::SetVirtualTable_00dcc160()
{
    hkReferencedObject* old = b;
    vtbl = &DAT_010d7540;
    if (old)
        old->removeReference();
    vtbl = &DAT_0102e388;
}

struct FUN_00dbc670_storage
{
    void* vtbl;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
};
struct FUN_00dbc670_shell
{
    void FUN_00dbc670();
    void hkPackfileWriter_setContents(int, int, int);
    int ProcessPoly(int, int);
    void SetVirtualTableAndProcessState_00dbc6e0();
};
struct GlobalDispatch
{
    virtual int V0();
    virtual int V1();
    virtual int V2();
    virtual int Dispatch(int, int, int, int, int);
};
extern GlobalDispatch* DAT_01269b74;
// @fnv 0x00d484a0
// src: XBOX_PDB 0x00d484a0
// pdb: hkSerializeUtil::savePackfile | hkSerializeUtil.obj | retail, upstream name already matches, high
// pdb params: object, klass, writer, options, binary, userListener
// pdb locals: pw
int __cdecl hkSerializeUtil_savePackfile(int object, int klass, int writer, int options, int binary, int userListener)
{
    if (writer)
    {
        if (binary)
        {
            FUN_00dbc670_storage msgStorage;
            FUN_00dbc670_shell* shell = (FUN_00dbc670_shell*)&msgStorage;
            shell->FUN_00dbc670();
            shell->hkPackfileWriter_setContents(object, klass, userListener);
            int result = shell->ProcessPoly(writer, options);
            shell->SetVirtualTableAndProcessState_00dbc6e0();
            return result;
        }
        return DAT_01269b74->Dispatch(object, klass, writer, options, userListener);
    }
    return 1;
}

extern void* hkSerializeUtil_load(void* streamIn, int errorOut, int classReg);

struct CtorBox
{
    CtorBox* hkIstream_ctor(void* fname);
    void SetVirtualTable_00dcc160();

    void* f0;
    int f4;
    void* b;
};

// Constructs a CtorBox from a1, calls FUN_00d48d30 on its b field with a2 and a3, destroys the box, and returns the result.
// @fnv 0x00d48ec0
// src: XBOX_PDB 0x00d48ec0
// pdb: hkSerializeUtil::load | hkSerializeUtil.obj | retail, object-file gap fill, high
// pdb params: streamIn, errorOut, classReg
// pdb locals: details, world, assertBuf, ostr
void* __cdecl hkSerializeUtil_load_00d48ec0(void* filename, int resultOut, int classReg)
{
    CtorBox obj;
    CtorBox* p = obj.hkIstream_ctor(filename);
    void* res = hkSerializeUtil_load(p->b, resultOut, classReg);
    obj.SetVirtualTable_00dcc160();
    return res;
}

namespace fnv_00d48f00 {
void* __cdecl hkString_memSet(void* destination, int value, int size);
int __cdecl hkString_memCmp(const void* left, const void* right, int size);
int __cdecl hkString_strCmp(const char* left, const char* right);
const char* __cdecl hkVersionUtil_getCurrentVersion();
int __cdecl hkNativePackfileUtils_load(void* packfileData, int dataSize, int userRegistry);
int __cdecl hkSerializeUtil_load(void* streamIn, int errorOut, int classReg);
extern int DAT_011b7b88;
struct Header180
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    char unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    Header180()
    {
        hkString_memSet(this, -1, 64);
        unk00 = 0x57e0e057;
        unk04 = 0x10c0c010;
        unk28 = 0;
    }
};
struct Object180
{
    void* unk00;
    int unk04;
    void* unk08;
    Object180* __thiscall hkIstream_hkIstream_00dcc6a0(void* mem, int memSize);
    void __thiscall SetVirtualTable_00dcc160();
};
// @fnv 0x00d48f00
// src: XBOX_PDB 0x00d48f00
// pdb: hkSerializeUtil::load | hkSerializeUtil.obj | retail, object-file gap fill, high
// pdb params: streamIn, errorOut, classReg
// pdb locals: details, world, assertBuf, ostr
int __cdecl hkSerializeUtil_load_00d48f00(Header180* buf, int buflen, int resultOut, int classReg)
{
    Header180 defaultHeader;
    if (buf->unk00 == defaultHeader.unk00 && buf->unk04 == defaultHeader.unk04 &&
        hkString_memCmp(&buf->unk10, &DAT_011b7b88, 4) == 0 && hkString_strCmp(&buf->unk28, hkVersionUtil_getCurrentVersion()) == 0)
        return hkNativePackfileUtils_load(buf, buflen, 0);
    Object180 wrapper;
    Object180* result = wrapper.hkIstream_hkIstream_00dcc6a0(buf, buflen);
    void* payload = result->unk08;
    int value = hkSerializeUtil_load(payload, resultOut, classReg);
    wrapper.SetVirtualTable_00dcc160();
    return value;
}
}  // namespace fnv_00d48f00

struct S_00d49310_Lock
{
    int unk0;
    int unk4;
    S_00d49310_Lock() throw();
    ~S_00d49310_Lock() throw();
};
struct S_00d49310_Result
{
    int m_uiFilterValue;
    S_00d49310_Result(int v) : m_uiFilterValue(v)
    {}
};
void hkSerializeUtil_detectFormat(void* reader, int* details) throw();
// @fnv 0x00d49310
// src: XBOX_PDB 0x00d49310
// pdb: hkSerializeUtil::detectFormat | hkSerializeUtil.obj | retail, object-file gap fill, high
// pdb params: reader, details
// pdb locals: buf, packfileActual, assertBuf, ostr, header, classVersionString
S_00d49310_Result hkSerializeUtil_detectFormat_00d49310(void* reader)
{
    S_00d49310_Lock lock;
    int res;
    hkSerializeUtil_detectFormat(reader, &res);
    return S_00d49310_Result(res);
}

int hkString_strCmp(const char* a, const char* b);

static inline int StringCompare(const char* a, const char* b)
{
    if (a)
    {
        if (b)
            return hkString_strCmp(a, b);
        return 1;
    }
    return b ? -1 : 0;
}

// The unused EDX argument keeps the original ECX string / stack text calling convention.
// @fnv 0x00d49350
// pdb: hkStringPtr::operator== | hkSerializeUtil.obj | retail, call graph (shared callers), high
// pdb params: cptr
int __fastcall StringEquals(const hkStringPtr* text, void*, const char* aString)
{
    return StringCompare(reinterpret_cast<const char*>(reinterpret_cast<std::size_t>(text->m_stringAndFlag) & ~std::size_t(1)), aString) == 0;
}

struct FUN_00d493a0_cls
{
    char m_00;
    char m_01;
    char m_02;
    char m_03;
    bool* MatchesTag(bool* out, const char* tag);
};

// Compares the four bytes m_00..m_03 against the first four bytes of tag, stores the result in out and returns out.
// @fnv 0x00d493a0
// pdb: hkVersionPatchManager::getPatchIndex | hkSerializeUtil.obj | debug, object-file gap fill, medium
// pdb params: uid
bool* FUN_00d493a0_cls::MatchesTag(bool* pbResult, const char* tag)
{
    bool r;
    if (m_00 == tag[0] && m_01 == tag[1] && m_02 == tag[2] && m_03 == tag[3])
    {
        r = true;
    }
    else
    {
        r = false;
    }
    *pbResult = r;
    return pbResult;
}

struct D493E0Object;

struct D493E0Ref
{
    D493E0Ref(D493E0Object* p);

    D493E0Object* m_pRetainedObject;
};

struct D493E0Registry
{
    D493E0Object* find(const void* object, int klass) const;
};

struct D493E0Loader
{
    int unk00;
    int unk04;
    int unk08;
    D493E0Registry* m_registry;

    D493E0Ref FindObject(const void* key, int flags) const;
};

// Looks up key in m_registry when key is non-null and returns a D493E0Ref wrapping the found object, otherwise a null D493E0Ref.
// @fnv 0x00d493e0
// pdb: `anonymous namespace'::ForwardingPackfileListerer::wrapObject | hkSerializeUtil.obj | debug, object-file gap fill, medium
// pdb params: object, klass
D493E0Ref D493E0Loader::FindObject(const void* key, int flags) const
{
    if (key)
        return D493E0Ref(m_registry->find(key, flags));
    return D493E0Ref(0);
}

struct Vt4Obj
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0c();
    virtual void* unk10(void* apArg);
};

struct GlobalObj
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0c();
    virtual Vt4Obj* unk10();
};

struct Obj5
{
    void* hkDataClass_getName();
    void Object_DoNothing_00dba660();
};

struct Obj2
{
    void GetObjectValue(Obj5* apOut);
    int hkDataObject_isNull();
    void Object_DoNothing_00dba660();
    void GetSourcePair(Pair* apOut);
};

struct Obj1
{
    void hkDataObject_ctor(Obj2* o);
};

struct PairVt
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0c(void** apFirst, void** apSecond);
};

extern int DAT_01268b08;

struct FUN_00d49420_cls
{
    int unk00;
    int unk04;
    PairVt* m_08;

    Obj1* ProcessPair(Obj1* apArg1, Obj2* apArg2);
    void unk20(Obj1* apA, void* apB, void* apC);
};

// @fnv 0x00d49420
// pdb: `anonymous namespace'::ForwardingPackfileListerer::addDataObjectCallback | hkSerializeUtil.obj | retail, vtable slot, high
// pdb params: object
// pdb locals: dataClass, classPtr, h, objPtr
Obj1* FUN_00d49420_cls::ProcessPair(Obj1* apArg1, Obj2* apArg2)
{
    if (m_08 != 0)
    {
        if (apArg2->hkDataObject_isNull() == 0)
        {
            Obj5 local28;
            int pairStorage[sizeof(Pair) / sizeof(int)];
            Pair& pair = *reinterpret_cast<Pair*>(pairStorage);
            apArg2->GetObjectValue(&local28);
            Vt4Obj* v = reinterpret_cast<GlobalObj*>(DAT_01268b08)->unk10();
            void** pVtableSlot = *(void***)v + 4;
            void* arg = local28.hkDataClass_getName();
            void* pSecond = reinterpret_cast<void*(__thiscall*)(void*, void*)>(*pVtableSlot)(v, arg);
            apArg2->GetSourcePair(&pair);
            void* first = reinterpret_cast<void*>(pair.a);
            if (pair.b != 0)
            {
                pSecond = reinterpret_cast<void*>(pair.b);
            }
            void* second = pSecond;
            m_08->unk0c(&first, &second);
            if (first == reinterpret_cast<void*>(pair.a) && second == pSecond)
            {
                local28.Object_DoNothing_00dba660();
            }
            else
            {
                unk20(apArg1, first, second);
                local28.Object_DoNothing_00dba660();
                return apArg1;
            }
        }
    }
    apArg1->hkDataObject_ctor(apArg2);
    return apArg1;
}

extern volatile int DAT_01269b70;

// src: GUESS 0x00d48950 (confidence: low)
static __declspec(noinline) int anonymous_namespace_checkTagfileWorld(int world, int errorOut, int versionManager, int classReg)
{
    int* pb = &versionManager;
    if (world)
    {
        return errorOut;
    }
    return *pb + classReg;
}

struct Holder_cls
{
    int unk00;
    void ReleaseStorage_00dba7f0();
};

struct Pending_cls
{
    int unk00;
    int unk04;
    void FUN_00dc5d30();
    void hkBinaryTagfileReader_load(Holder_cls* h, int a, int b);
};

struct Owner_cls
{
    int hkVersionPatchManager_applyPatches(int worldToUpdate, int finalClassesReg);
};

// Initialises a Pending_cls and Holder_cls, then returns 1 if a condition on edi_in fails, otherwise calls Owner_cls::FUN_00dba0d0.
// @fnv 0x00d48a90
// src: XBOX_RETAIL_PDB 0x00d48a90
// pdb: `anonymous namespace'::loadBinaryTagfileIntoWorld | hkSerializeUtil.obj | retail, call graph, high
// pdb params: streamIn, world, errorOut, classReg
// pdb locals: reader
static __declspec(noinline) int anonymous_namespace_loadBinaryTagfileIntoWorld(int streamIn, int world, int errorOut, int classReg)
{
    Pending_cls p;
    Holder_cls h;

    p.FUN_00dc5d30();
    p.hkBinaryTagfileReader_load(&h, streamIn, world);
    h.ReleaseStorage_00dba7f0();

    if (errorOut != 0)
    {
        if (anonymous_namespace_checkTagfileWorld(errorOut, world, DAT_01269b70, classReg) == 0)
        {
            return 1;
        }
    }
    return ((Owner_cls*)DAT_01269b70)->hkVersionPatchManager_applyPatches(world, classReg);
}

int __cdecl S00d48a90_Entry(int a1)
{
    return anonymous_namespace_loadBinaryTagfileIntoWorld(a1, 0, 0, 0);
}

struct S00d48d30_Bool
{
    char m_cBooleanValue;
    S00d48d30_Bool()
    {}
};

struct S00d48d30_Stream
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual S00d48d30_Bool IsStreamValid() const;
};

struct S00d48d30_Result
{
    int m_iResultCode;
    hkStringPtr m_message;
};

struct S00d48d30_Lock
{
    int unk00;
    int unk04;
    S00d48d30_Lock() throw();
    ~S00d48d30_Lock() throw();
};

struct S00d48d30_Ref
{
    int unk00;
    S00d48d30_Ref(const S00d48d30_Ref&) throw();
    ~S00d48d30_Ref() throw();
};

struct S00d48d30_Format
{
    int m_type;
    int attach(struct S00d48d30_Stream* s, struct S00d48d30_Result* out);
};

struct S00d48d30_Reader
{
    int unk00;
    int unk04;
    int unk08;
    S00d48d30_Reader() throw();
    ~S00d48d30_Reader() throw();
    S00d48d30_Ref ForwardToReceiver();
    void prepare();
    int open(S00d48d30_Stream* s);
    void close();
};

struct S00d48d30_Service
{
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual int getLoadOptions();
    virtual int getDefaultOptions();
};

extern const char str_010cfacc[];
extern const char str_010cfab8[];
extern const char str_010cfa94[];

int S00d48d30_Finish(int opts);
void hkSerializeUtil_detectFormat(void* reader, int* details) throw();
int __cdecl hkDataObjectUtil_toResourceWithRegistry(const S00d48d30_Ref& r, int classReg);

// src: GUESS 0x00d48a90 (confidence: low)
static __declspec(noinline) int anonymous_namespace_loadBinaryTagfileIntoWorld(S00d48d30_Stream* streamIn, S00d48d30_Reader* world, S00d48d30_Result* errorOut)
{
    world->prepare();
    if (world->open(streamIn) == 0)
    {
        if (errorOut != 0)
        {
            errorOut->m_iResultCode = 3;
            errorOut->m_message = str_010cfa94;
        }
        world->close();
        return 1;
    }
    return 0;
}

// src: GUESS 0x00d48760 (confidence: low)
static __declspec(noinline) int anonymous_namespace_loadPackfile(S00d48d30_Stream* streamIn, S00d48d30_Format* details, S00d48d30_Result* errorOut,
                                             int typeReg)
{
    if (details->m_type < 2)
    {
        return 0;
    }
    if (errorOut != 0)
    {
        errorOut->m_iResultCode = 0;
    }
    if (streamIn == 0)
    {
        return 0;
    }
    if (details->attach(streamIn, errorOut) == 0)
    {
        return 0;
    }
    return S00d48d30_Finish(typeReg);
}

// Validates the stream, resolves load options, and dispatches to a format-specific loader based on the detected stream type.
// @fnv 0x00d48d30
// src: XBOX_PDB 0x00d48d30
// pdb: hkSerializeUtil::load | hkSerializeUtil.obj | retail, string-set bridge, high
// pdb params: streamIn, errorOut, classReg
// pdb locals: details, world, assertBuf, ostr
int __cdecl hkSerializeUtil_load(S00d48d30_Stream* streamIn, S00d48d30_Result* errorOut, int classReg) throw()
{
    if (streamIn == 0)
    {
        if (errorOut != 0)
        {
            errorOut->m_iResultCode = 1;
            errorOut->m_message = str_010cfacc;
        }
        return 0;
    }
    if (!streamIn->IsStreamValid().m_cBooleanValue)
    {
        if (errorOut != 0)
        {
            errorOut->m_iResultCode = 1;
            errorOut->m_message = str_010cfab8;
        }
        return 0;
    }
    if (classReg == 0)
    {
        classReg = reinterpret_cast<S00d48d30_Service*>(DAT_01268b08)->getDefaultOptions();
    }
    S00d48d30_Lock lock;
    S00d48d30_Format format;
    hkSerializeUtil_detectFormat(streamIn, &format.m_type);
    switch (format.m_type)
    {
    case 2:
    case 3:
        return anonymous_namespace_loadPackfile(streamIn, &format, errorOut,
                            reinterpret_cast<S00d48d30_Service*>(DAT_01268b08)->getLoadOptions());
    case 4: {
        S00d48d30_Reader reader;
        if (anonymous_namespace_loadBinaryTagfileIntoWorld(streamIn, &reader, errorOut) == 0)
        {
            return hkDataObjectUtil_toResourceWithRegistry(reader.ForwardToReceiver(), classReg);
        }
        return 0;
    }
    }
    if (errorOut != 0)
    {
        errorOut->m_iResultCode = 2;
        errorOut->m_message = str_010cfa94;
    }
    return 0;
}

struct S00d48680_Arr
{
    char* m_data;
    int m_iElementCount;
    unsigned int m_capFlags;
};

struct S00d48680_Alloc
{
    int unk00;
};

struct S00d48680_Sys
{
    int unk00;
    int unk04;
    int unk08;
    S00d48680_Alloc* heap;
    S00d48680_Alloc& getHeap()
    {
        return *heap;
    }
};

extern "C" S00d48680_Sys* __cdecl hkMemoryRouter_getInstance();
extern "C" void __cdecl hkArrayUtil__reserve(S00d48680_Alloc* mem, S00d48680_Arr* array, int numElem, int sizeElem);

struct S00d48680_Obj
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int v4(int a, int b);
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual unsigned char& v9(unsigned char& f);
    virtual void v10(int a, int b);
    virtual int v11();
};

// Reads data into arr from obj, growing the buffer via FUN_00c908c0 when the requested size exceeds the current capacity.
// @fnv 0x00d48680
// src: XBOX_RETAIL_PDB 0x00d48680
// pdb: `anonymous namespace'::loadStreamIntoBuffer | hkSerializeUtil.obj | retail, call graph, high
// pdb params: stream, buf
static __declspec(noinline) void anonymous_namespace_loadStreamIntoBuffer(S00d48680_Obj* stream, S00d48680_Arr* buf)
{
    unsigned char flag;
    if (stream->v9(flag))
    {
        stream->v10(0, 2);
        int iNeeded = stream->v11();
        S00d48680_Alloc& heap = hkMemoryRouter_getInstance()->getHeap();
        unsigned int cap = buf->m_capFlags & 0x3fffffff;
        if ((int)cap < iNeeded)
        {
            int grow = (int)(cap * 2);
            if (iNeeded >= grow)
            {
                grow = iNeeded;
            }
            hkArrayUtil__reserve(&heap, buf, grow, 1);
        }
        buf->m_iElementCount = iNeeded;
        stream->v10(0, 0);
        stream->v4((int)buf->m_data, buf->m_iElementCount);
        return;
    }

    int r;
    do
    {
        int iNeeded = buf->m_iElementCount + 0x20000;
        S00d48680_Alloc& heap = hkMemoryRouter_getInstance()->getHeap();
        unsigned int cap = buf->m_capFlags & 0x3fffffff;
        if ((int)cap < iNeeded)
        {
            int grow = (int)(cap * 2);
            if (iNeeded < grow)
            {
                iNeeded = grow;
            }
            hkArrayUtil__reserve(&heap, buf, iNeeded, 1);
        }
        char* d = buf->m_data;
        int iSize = buf->m_iElementCount;
        r = stream->v4((int)(d + iSize), 0x20000);
        buf->m_iElementCount += r;
    } while (r > 0);
}

void __cdecl S00d48680_Entry(S00d48680_Obj* obj, S00d48680_Arr* arr)
{
    anonymous_namespace_loadStreamIntoBuffer(obj, arr);
}

struct HashPolicy
{
};
struct StringMapState
{
    void* entries;
    int count;
    int mask;
    HashPolicy policy;
    void FUN_00d87790(HashPolicy) throw();
    void FreeBuffer() throw();
    StringMapState() throw()
    {
        FUN_00d87790(HashPolicy());
    }
    void clear() throw()
    {
        FreeBuffer();
    }
};
extern void* DAT_010cf7b0[];
struct RegistryBase
{
    void** dispatch;
    unsigned short allocationSize;
    unsigned short references;
    RegistryBase() throw() : references(1)
    {
        dispatch = DAT_010cf7b0;
    }
};
struct TypeRegistry : RegistryBase
{
    StringMapState types;
    int finish;
    TypeRegistry(int flag) throw() : finish(flag)
    {}
    void clear() throw()
    {
        types.clear();
    }
    void hkTypeInfoRegistry_merge(const TypeRegistry&) throw();
};
struct RuntimeClass;
struct ClassRegistry
{
    virtual void v0() throw();
    virtual void v1() throw();
    virtual void v2() throw();
    virtual void v3() throw();
    virtual const RuntimeClass* find(const char*) const throw();
};
struct Resource : hkReferencedObject
{
    virtual void v3() throw();
    virtual void v4() throw();
    virtual void v5() throw();
    virtual void* contents(const char*, const TypeRegistry*) const throw();
    virtual const char* name() const throw();
};
struct ResourceRef
{
    Resource* ptr;
    ResourceRef() throw() : ptr(0)
    {}
    void clear() throw()
    {
        if (ptr)
            ptr->removeReference();
        ptr = 0;
    }
    Resource* operator->() const
    {
        return ptr;
    }
    void take(Resource* p) throw()
    {
        if (ptr && ptr != p)
            ptr->removeReference();
        ptr = p;
    }
};
struct ObjectImpl
{
    virtual ~ObjectImpl() throw();
    unsigned short allocationSize;
    unsigned short references;
    int externalRefs;
};
struct RootObject
{
    ObjectImpl* impl;
    void hkDataObject_hkDataObject(ObjectImpl*) throw();
    __declspec(noinline) void ReleaseStorage_00dba7f0() throw();
    RootObject(ObjectImpl* p) throw()
    {
        hkDataObject_hkDataObject(p);
    }
    void clear() throw()
    {
        ReleaseStorage_00dba7f0();
    }
};
// src: GUESS 0x00dba7f0 (confidence: low)
__declspec(noinline) void RootObject::ReleaseStorage_00dba7f0() throw()
{
    if (impl)
    {
        --impl->references;
        if (--impl->externalRefs == 0)
            delete impl;
    }
}
struct NativeWorld
{
    void* dispatch;
    unsigned short allocationSize;
    unsigned short references;
    const ClassRegistry* classes;
    void* vtableRegistry;
    void* mapEntries;
    int mapCount;
    int mapMask;
    HashPolicy mapPolicy;
    void* rootPointer;
    const RuntimeClass* rootClass;
    void hkDataWorldNative_ctor() throw();
    void FUN_00dbb3f0() throw();
    void hkDataWorldNative_setClassRegistry(const ClassRegistry*) throw();
    ObjectImpl* SetNativeDataObjectFromPair(void*, const RuntimeClass&) const throw();
    NativeWorld() throw()
    {
        hkDataWorldNative_ctor();
    }
    void clear() throw()
    {
        FUN_00dbb3f0();
    }
};
struct ObjectResource;
extern "C" ObjectResource* __cdecl hkDataObjectUtil_toObjectWithRegistry(const RootObject&, const ClassRegistry*, const TypeRegistry*) throw();
struct LoadFormat
{
    int type;
    hkStringPtr version;
    unsigned int layout;
};
struct LoadError
{
    int status;
    hkStringPtr message;
};
struct LoadStream;
struct LoadBuffer
{
    char* data;
    int size;
    unsigned int capacity;
};
struct LoadAllocator
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void freeBlock(void*, int) throw();
};
struct LoadMemory
{
    int unk00;
    int unk04;
    int unk08;
    LoadAllocator* heap;
};
extern "C" int __cdecl hkString_memCmp(const void*, const void*, int) throw();
extern "C" const char* __cdecl hkVersionUtil_getCurrentVersion() throw();
extern "C" Resource* __cdecl hkNativePackfileUtils_load(const void*, int, const TypeRegistry*) throw();
extern unsigned int DAT_011b7b88;
extern const char str_010cf9d8[];
void __cdecl Object_ReadIntoGrowingBuffer(LoadStream&, LoadBuffer&) throw();
struct DeprecatedLoader
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual Resource* load(LoadStream&, const LoadFormat&, LoadError*) throw();
};
// src: GUESS 0x00d48760 (confidence: low)
static __declspec(noinline) __declspec(nothrow) Resource* Object_ProcessAndReturnValue_00d48760(LoadStream& input, const LoadFormat& format,
                                                                       LoadError* error,
                                                                       const TypeRegistry& types) throw()
{
    if (format.type == 2)
    {
        if (hkString_memCmp(&format.layout, &DAT_011b7b88, 4) == 0)
        {
            if (StringEquals(&format.version, 0, hkVersionUtil_getCurrentVersion()))
            {
                LoadBuffer buffer;
                buffer.data = 0;
                buffer.size = 0;
                buffer.capacity = 0x80000000;
                Object_ReadIntoGrowingBuffer(input, buffer);
                Resource* result = hkNativePackfileUtils_load(buffer.data, buffer.size, &types);
                LoadMemory* memory = (LoadMemory*)hkMemoryRouter_getInstance();
                buffer.size = 0;
                if ((int)buffer.capacity >= 0)
                    memory->heap->freeBlock(buffer.data, buffer.capacity & 0x3fffffff);
                return result;
            }
        }
        else
        {
            if (error)
            {
                error->status = 3;
                error->message = str_010cf9d8;
            }
            return 0;
        }
    }
    return ((DeprecatedLoader*)DAT_01269b74)->load(input, format, error);
}

// Loads a resource via FUN_00d48760, resolves its class in classes, and constructs an ObjectResource from the parsed data.
// @fnv 0x00d48840
// src: XBOX_RETAIL_PDB 0x00d48840
// pdb: `anonymous namespace'::loadNewPackfileOnHeap | hkSerializeUtil.obj | retail, object-file gap fill, high
// pdb params: streamIn, details, errorOut, classReg, typeReg
// pdb locals: world, noFinish, contents
static __declspec(noinline) ObjectResource* anonymous_namespace_loadNewPackfileOnHeap(LoadStream* streamIn, LoadFormat& details, LoadError* errorOut,
                                                         const ClassRegistry* classReg, const TypeRegistry* typeReg)
{
    TypeRegistry unfinished(0);
    unfinished.hkTypeInfoRegistry_merge(*typeReg);
    ResourceRef resource;
    resource.take((Resource*)anonymous_namespace_loadPackfile((S00d48d30_Stream*)streamIn, (S00d48d30_Format*)&details,
                                          (S00d48d30_Result*)errorOut, (int)&unfinished));
    NativeWorld data;
    data.hkDataWorldNative_setClassRegistry(classReg);
    const RuntimeClass* rootClass = classReg->find(resource->name());
    if (rootClass)
    {
        RootObject root(data.SetNativeDataObjectFromPair(resource->contents(0, typeReg), *rootClass));
        ObjectResource* result = hkDataObjectUtil_toObjectWithRegistry(root, classReg, typeReg);
        root.clear();
        data.clear();
        resource.clear();
        unfinished.clear();
        return result;
    }
    data.clear();
    resource.clear();
    unfinished.clear();
    return 0;
}
LoadStream* volatile inputSource;
LoadFormat* volatile formatSource;
LoadError* volatile errorSource;
const ClassRegistry* volatile classSource;
const TypeRegistry* volatile typeSource;
ObjectResource* volatile outputSink;
void CallHeapLoader()
{
    outputSink = anonymous_namespace_loadNewPackfileOnHeap(inputSource, *formatSource, errorSource, classSource, typeSource);
}

extern const char str_010cf9f4[];

struct S00d48950_Item
{
    virtual void v00();
    virtual void v04();
    virtual void* GetIteratorKey();
    virtual int GetNumOwnMembers();
};
typedef hkArrayBase<S00d48950_Item*> S00d48950_ItemArray;
struct S00d48950_Root
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void getItems(S00d48950_ItemArray& items);
};
struct S00d48950_Entry
{
    int FUN_00d47120();
};
struct S00d48950_Lookup
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual S00d48950_Entry* find(void* key);
};
struct S00d48950_Set
{
    int hkMapBase_unsigned_int64_unsigned_int64_struct_hkMapOperations_unsigned_int64_getWithDefault(__int64 id, int a, int b);
};
struct S00d48950_Target
{
    char pad00[0x18];
    S00d48950_Set m_set;
    void hkVersionPatchManager_recomputePatchDependencies();
    __int64 hkVersionPatchManager_getUid(void* key, int version);
};
struct S00d48950_Result
{
    int m_pMoppCode;
    hkStringPtr m_message;
};
struct S00d48950_Heap
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void ReturnMemory(void* p, int numBytes);
};
struct S00d48950_Sys
{
    int unk00, unk04, unk08, unk0c;
    S00d48950_Heap* m_pStreamAllocator;
    S00d48950_Heap& heap()
    {
        return *m_pStreamAllocator;
    }
};

// For each root item, checks lookup and adds it to target's set when versions differ; returns 0 with result code 4 on failure, otherwise 1.
// @fnv 0x00d48950
// src: XBOX_RETAIL_PDB 0x00d48950
// pdb: `anonymous namespace'::checkTagfileWorld | hkSerializeUtil.obj | retail, unique string literal, high
// pdb params: world, errorOut, versionManager, classReg
// pdb locals: classes, assertBuf, ostr
static __declspec(noinline) int anonymous_namespace_checkTagfileWorld(S00d48950_Result* world, S00d48950_Target* errorOut,
                                             S00d48950_Lookup* versionManager, S00d48950_Root* classReg)
{
    errorOut->hkVersionPatchManager_recomputePatchDependencies();
    S00d48950_ItemArray items;
    items.m_data = 0;
    items.m_iElementCount = 0;
    items.m_iCapacityState = 0x80000000;
    classReg->getItems(items);
    for (int iIndex = 0; iIndex < items.m_iElementCount; iIndex++)
    {
        void* key = items.m_data[iIndex]->GetIteratorKey();
        int version = items.m_data[iIndex]->GetNumOwnMembers();
        S00d48950_Entry* entry = versionManager->find(key);
        int iCurrentVersion = entry ? entry->FUN_00d47120() : -1;
        if (entry && iCurrentVersion == version)
            continue;
        __int64 id = errorOut->hkVersionPatchManager_getUid(key, version);
        if (errorOut->m_set.hkMapBase_unsigned_int64_unsigned_int64_struct_hkMapOperations_unsigned_int64_getWithDefault(id, -1, -1) == -1)
        {
            world->m_pMoppCode = 4;
            world->m_message.printf_00cb0c70(str_010cf9f4, key, version);
            S00d48950_Heap& heap = *((S00d48950_Sys*)hkMemoryRouter_getInstance())->m_pStreamAllocator;
            items.m_iElementCount = 0;
            if ((items.m_iCapacityState & 0x80000000) == 0)
                heap.ReturnMemory(items.m_data, (items.m_iCapacityState & 0x3fffffff) * 4);
            return 0;
        }
    }
    S00d48950_Heap& heap = ((S00d48950_Sys*)hkMemoryRouter_getInstance())->heap();
    items.m_iElementCount = 0;
    if ((items.m_iCapacityState & 0x80000000) == 0)
        heap.ReturnMemory(items.m_data, (items.m_iCapacityState & 0x3fffffff) * 4);
    return 1;
}

S00d48950_Result* volatile g00d48950_result;
S00d48950_Target* volatile g00d48950_target;
S00d48950_Lookup* volatile g00d48950_lookup;
S00d48950_Root* volatile g00d48950_root;
volatile int g00d48950_out;
void S00d48950_Caller()
{
    g00d48950_out = anonymous_namespace_checkTagfileWorld(g00d48950_result, g00d48950_target, g00d48950_lookup, g00d48950_root);
}
