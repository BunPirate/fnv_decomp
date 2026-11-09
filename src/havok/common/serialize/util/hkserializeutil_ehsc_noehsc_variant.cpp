// src/havok/common/serialize/util/hkserializeutil_ehsc_noehsc_variant.cpp - flag-variant unit created 2026-10-31 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHs-c- /Gy (unit src/havok/common/serialize/util/hkserializeutil.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.


// src/havok/common/serialize/util/hkserializeutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/serialize/util/hkserializeutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../../../include/hkReferencedObject.h"
#include "../../../../../include/hkStringPtr.h"
#include "../../../../../include/Pair.h"

void __cdecl Object_ForwardCall_00d48620(int a, int b, int c);
void __cdecl Object_ForwardCall_00d48640(int a, int b);
extern "C" void __cdecl hkSerializeUtil_saveTagfile(int, int, int, int, int);
void __cdecl Object_ForwardCall_00d48660(int a, int b, int c);
extern int DAT_0102e388;
extern int DAT_010d7540;
struct FUN_00dcc160_cls
{
    void* vtbl;
    int a;
    hkReferencedObject* b;
    void SetVirtualTable_00dcc160();
};
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
int __cdecl hkSerializeUtil_savePackfile(int object, int klass, int writer, int options, int binary, int userListener);
extern void* hkSerializeUtil_load(void* streamIn, int errorOut, int classReg);
struct CtorBox
{
    CtorBox* hkIstream_ctor(void* fname);
    void SetVirtualTable_00dcc160();

    void* f0;
    int f4;
    void* b;
};
void* __cdecl hkSerializeUtil_load_00d48ec0(void* filename, int resultOut, int classReg);
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
S_00d49310_Result hkSerializeUtil_detectFormat_00d49310(void* reader);
int hkString_strCmp(const char* a, const char* b);
static inline int S_00d49350_Compare(const char* a, const char* b)
{
    if (a)
    {
        if (b)
            return hkString_strCmp(a, b);
        return 1;
    }
    return b ? -1 : 0;
}
struct FUN_00d493a0_cls
{
    char m_00;
    char m_01;
    char m_02;
    char m_03;
    bool* MatchesTag(bool* out, const char* tag);
};
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
static int anonymous_namespace_loadBinaryTagfileIntoWorld(int streamIn, int world, int errorOut, int classReg);
int __cdecl S00d48a90_Entry(int a1);
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
int __cdecl hkSerializeUtil_load(S00d48d30_Stream* streamIn, S00d48d30_Result* errorOut, int classReg) throw();
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
static void anonymous_namespace_loadStreamIntoBuffer(S00d48680_Obj* stream, S00d48680_Arr* buf);
void __cdecl S00d48680_Entry(S00d48680_Obj* obj, S00d48680_Arr* arr);

extern int DAT_011b7b88;
extern "C" int __cdecl hkString_memCmp(const void*, const void*, int);
extern "C" const char* __cdecl hkVersionUtil_getCurrentVersion();
extern "C" void* __cdecl hkNativePackfileUtils_load(const void*, int, const void*);

struct ByteBool
{
    char value;
    operator bool() const
    {
        return value != 0;
    }
};
struct VersionedDataBlock
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual ByteBool IsStreamValid() const;
    virtual int read(void*, int);
    virtual int skip(int);
    virtual ByteBool marks() const;
    virtual int mark(int);
    virtual int rewind();
    virtual ByteBool canSeek() const;
    virtual int seek(int, int);
    virtual int tell() const;
};
struct VersionString
{
    unsigned word;
    int Equals(const char*) const;
};
struct LoadFormat
{
    int kind;
    VersionString version;
    unsigned char pointerSize;
    unsigned char littleEndian;
    unsigned char paddingReuse;
    unsigned char emptyBase;
};
struct LoadError
{
    int code;
    hkStringPtr message;
    void set(int c, const char* text)
    {
        code = c;
        message = text;
    }
};
struct BufferAllocator
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void freeBuffer(void*, int);
};
struct TemporaryAllocator
{
    __forceinline BufferAllocator& get(void*)
    {
        return *(BufferAllocator*)hkMemoryRouter_getInstance()->heap;
    }
};
struct BufferBase : S00d48680_Arr
{
    __forceinline BufferBase()
    {
        m_data = 0;
        m_iElementCount = 0;
        m_capFlags = 0x80000000;
    }
    __forceinline ~BufferBase()
    {}
    __forceinline int size() const
    {
        return m_iElementCount;
    }
    __forceinline char* begin()
    {
        return m_data;
    }
    __forceinline int capacity() const
    {
        return m_capFlags & 0x3fffffff;
    }
    __forceinline void clear()
    {
        m_iElementCount = 0;
    }
    __forceinline void release(BufferAllocator& allocator)
    {
        clear();
        if ((m_capFlags & 0x80000000u) == 0)
            allocator.freeBuffer(m_data, capacity());
        m_data = 0;
        m_capFlags = 0x80000000;
    }
    __forceinline void reserve(BufferAllocator& allocator, int required)
    {
        if (required > capacity())
        {
            int grown = 2 * capacity();
            hkArrayUtil__reserve((S00d48680_Alloc*)&allocator, this, required > grown ? required : grown, 1);
        }
    }
    __forceinline void resize(BufferAllocator& allocator, int count)
    {
        reserve(allocator, count);
        m_iElementCount = count;
    }
    __forceinline char* expand(int count)
    {
        int old = m_iElementCount;
        m_iElementCount = old + count;
        return m_data + old;
    }
};
struct Buffer : BufferBase
{
    __forceinline Buffer()
    {}
    __forceinline ~Buffer()
    {
        release(TemporaryAllocator().get(this));
    }
    __forceinline void reserve(int count)
    {
        BufferBase::reserve(TemporaryAllocator().get(this), count);
    }
    __forceinline void resize(int count)
    {
        BufferBase::resize(TemporaryAllocator().get(this), count);
    }
};
struct OldLoader
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void* load(VersionedDataBlock&, const LoadFormat&, LoadError*);
    static OldLoader& instance()
    {
        return *(OldLoader*)DAT_01269b74;
    }
};

// src: GUESS 0x00d48680 (confidence: medium)
static __declspec(noinline) void anonymous_namespace_loadStreamIntoBuffer(S00d48680_Obj* stream, S00d48680_Arr* buf)
{
    VersionedDataBlock& input = *(VersionedDataBlock*)stream;
    Buffer& bytes = *(Buffer*)buf;
    if (input.canSeek())
    {
        input.seek(0, 2);
        bytes.resize(input.tell());
        input.seek(0, 0);
        input.read(bytes.begin(), bytes.size());
    }
    else
    {
        int readCount;
        do
        {
            const int chunk = 0x20000;
            bytes.reserve(bytes.size() + chunk);
            readCount = input.read(bytes.begin() + bytes.size(), chunk);
            bytes.expand(readCount);
        } while (readCount > 0);
    }
}

void __cdecl S00d48680_Entry(S00d48680_Obj* obj, S00d48680_Arr* arr)
{
    anonymous_namespace_loadStreamIntoBuffer(obj, arr);
}

// @fnv 0x00d48760
// src: XBOX_RETAIL_PDB 0x00d48760
// pdb: `anonymous namespace'::loadPackfile | hkSerializeUtil.obj | retail, unique string literal, high
// pdb params: streamIn, details, errorOut, typeReg
// pdb locals: buf
static __declspec(noinline) void* anonymous_namespace_loadPackfile(VersionedDataBlock& streamIn, const LoadFormat& details, LoadError* errorOut,
                                               const void* typeReg)
{
    if (details.kind == 2)
    {
        if (hkString_memCmp(&details.pointerSize, &DAT_011b7b88, 4) == 0)
        {
            if (details.version.Equals(hkVersionUtil_getCurrentVersion()))
            {
                Buffer bytes;
                anonymous_namespace_loadStreamIntoBuffer((S00d48680_Obj*)&streamIn, &bytes);
                return hkNativePackfileUtils_load(bytes.begin(), bytes.size(), typeReg);
            }
        }
        else
        {
            if (errorOut)
                errorOut->set(3, "Wrong platform for packfile");
            return 0;
        }
    }
    return OldLoader::instance().load(streamIn, details, errorOut);
}

void* FiveIntegerLoadRecord(VersionedDataBlock& input, const LoadFormat& format, LoadError* error, const void* registry)
{
    return anonymous_namespace_loadPackfile(input, format, error, registry);
}
