
// src/fallout_shared/region system/tesregiongrassobjectlist.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/region system/tesregiongrassobjectlist.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../include/Actor.h"

extern "C" void __cdecl Deallocate(void*);
struct FUN_004f5df0_shell
{
    void __thiscall FUN_004f5e20();
    void* __thiscall Destroy(unsigned int flags);
};
// @fnv 0x004f5df0
// pdb: TESRegionGrassObjectList::`scalar deleting destructor' | TESRegionGrassObjectList.obj | retail, vtable slot, high
void* __thiscall FUN_004f5df0_shell::Destroy(unsigned int flags)
{
    FUN_004f5e20();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct ListX
{
    ~ListX();
};
struct FUN_004f5e20
{
    virtual ~FUN_004f5e20();
    ListX f4;
    void TESRegionGrassObjectList_Clear();
};
// @fnv 0x004f5e20
// pdb: TESRegionGrassObjectList::~TESRegionGrassObjectList | TESRegionGrassObjectList.obj | debug, object-file gap fill, medium
FUN_004f5e20::~FUN_004f5e20()
{
    TESRegionGrassObjectList_Clear();
}

struct LH
{
    bool IsInList(Actor*&);
    void EraseActor(Actor*);
    bool TESRegionGrassObjectList_Add(Actor* apObject);
};

// @fnv 0x004f5e80
// src: XBOX_RETAIL_PDB 0x004f5e80
// pdb: TESRegionGrassObjectList::Add | TESRegionGrassObjectList.obj | retail, call graph (shared callers), high
// pdb params: apObject
bool LH::TESRegionGrassObjectList_Add(Actor* apObject)
{
    if (!apObject || ((LH*)((char*)this + 4))->IsInList(apObject))
        return false;
    EraseActor(apObject);
    return true;
}

struct TESRegionGrassObject;
struct SoundListView
{
    void AddTail(char* const&);
};
struct FUN_004f5ec0_shell
{
    unsigned int iCount;
    void AddGrassObject(TESRegionGrassObject* apObject);
};
// Appends apObject to the list at offset 4 and increments the count at offset 0x10.
// @fnv 0x004f5ec0
// pdb: TESRegionGrassObjectList::AddTailSimple | TESRegionGrassObjectList.obj | retail, call graph, high
// pdb params: apObject
void FUN_004f5ec0_shell::AddGrassObject(TESRegionGrassObject* apObject)
{
    reinterpret_cast<SoundListView*>(reinterpret_cast<char*>(this) + 4)
        ->AddTail(reinterpret_cast<char* const&>(apObject));
    reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x10)[0]++;
}

struct FUN_004f16c0_src;

struct FUN_004f16c0_node
{
    void* Make(int apCopyInto);
};

struct FUN_004f16c0_src
{
    int unk00;
    int unk04;
    FUN_004f16c0_node* m_08;
};

struct FUN_004f16c0_base
{
    int unk04;
    FUN_004f16c0_base(FUN_004f16c0_src* p);
    virtual ~FUN_004f16c0_base();
};

struct FUN_004f16c0 : FUN_004f16c0_base
{
    void* m_08;
    FUN_004f16c0(FUN_004f16c0_src* p);
    virtual ~FUN_004f16c0();
};

// Initializes the base from p and stores the object returned by p->m_08->Make(0) in m_08.
// @fnv 0x004f16c0
FUN_004f16c0::FUN_004f16c0(FUN_004f16c0_src* apSource) : FUN_004f16c0_base(apSource)
{
    m_08 = apSource->m_08->Make(0);
}

struct ListItemBase
{
    virtual void v0();
    virtual void v1();
    virtual int v2(int arg);
};

struct ListHeadStub
{
    ListItemBase** FUN_006815c0();
    void FUN_0063f7b0();
};

// @fnv 0x004f5ef0
// src: XBOX_RETAIL_PDB 0x004f5ef0
// pdb: TESRegionGrassObjectList::Clear | TESRegionGrassObjectList.obj | retail, object-file run extension, high
// pdb locals: premove
void FUN_004f5e20::TESRegionGrassObjectList_Clear()
{
    ListItemBase* cur;
    ListItemBase* item;
    cur = *((ListHeadStub*)((char*)this + 4))->FUN_006815c0();
    while (cur != 0)
    {
        ((ListHeadStub*)((char*)this + 4))->FUN_0063f7b0();
        if (*((unsigned char*)this + 0xc) != 0)
        {
            ListItemBase* tmp;
            tmp = cur;
            item = tmp;
            (item != 0) ? item->v2(1) : 0;
        }
        cur = *((ListHeadStub*)((char*)this + 4))->FUN_006815c0();
    }
    *((unsigned int*)((char*)this + 0x10)) = 0;
}

extern "C" void __cdecl Deallocate(void*);

struct FUN_004f5f80_obj
{
    virtual void unk00();
    virtual int unk04();
    virtual void unk08();
    virtual int unk0c();
};

struct ListNodeX
{
    void** FUN_006815c0();
    ListNodeX* FUN_00726070();
};

struct IntOpsX
{
    int GetHavokWorldObjectCountInSceneGraph_0084e3a0();
};

struct FUN_004f5f80_cls
{
    FUN_004f5f80_obj* __thiscall TESRegionGrassObjectList_Find(int aiFind, int aiParentFind);
};

// Walks the list from this+4 and returns the first object whose unk04 equals a1 and whose unk0c matches a2 (or is null when a2 < 0).
// @fnv 0x004f5f80
// src: COMMUNITY 0x004f5f80
// pdb: TESRegionGrassObjectList::Find | TESRegionGrassObjectList.obj | retail, upstream name already matches, high
// pdb params: aiFind, aiParentFind
// pdb locals: pcurrent, pobj, ptest
FUN_004f5f80_obj* FUN_004f5f80_cls::TESRegionGrassObjectList_Find(int aiFind, int aiParentFind)
{
    ListNodeX* it9 = (char*)this != 0 ? (ListNodeX*)((char*)this + 4) : 0;
    FUN_004f5f80_obj* result = 0;
    FUN_004f5f80_obj* obj;
    while (it9 != 0 && *it9->FUN_006815c0() != 0)
    {
        obj = (FUN_004f5f80_obj*)*it9->FUN_006815c0();
        if (((IntOpsX*)(int)obj->unk04())->GetHavokWorldObjectCountInSceneGraph_0084e3a0() == aiFind &&
            ((aiParentFind >= 0 && obj->unk0c() != 0 && ((IntOpsX*)(int)obj->unk0c())->GetHavokWorldObjectCountInSceneGraph_0084e3a0() == aiParentFind) ||
             (aiParentFind < 0 && obj->unk0c() == 0)))
        {
            result = obj;
            break;
        }
        it9 = it9->FUN_00726070();
    }
    return result;
}

struct VItem
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual Actor* v5(int arg);
};

struct VDel
{
    virtual void v0();
    virtual void v1();
    virtual ~VDel();
};

struct TargetList
{
    virtual ~TargetList();
    int unk04;
    int unk08;
    unsigned char unk0c;
    int unk10;
    TargetList(unsigned char flag);
};

struct Controller
{
    int unk00;
    ListNodeX list;
    int unk08;
    unsigned char unk0c;

    TargetList* CopyTargetList(TargetList* apCopyInto);
};

// @fnv 0x004f6060
// pdb: TESRegionGrassObjectList::Copy | TESRegionGrassObjectList.obj | retail, object-file run extension, high
// pdb params: apCopyInto
// pdb locals: pcopy, pcurrent, pobjCopy
TargetList* Controller::CopyTargetList(TargetList* apCopyInto)
{
    ListNodeX* iter = this ? &list : 0;
    TargetList* result = apCopyInto ? apCopyInto : new TargetList(unk0c);
    Actor* actor2 = 0;

    while (iter != 0 && *iter->FUN_006815c0() != 0)
    {
        if (result->unk0c != 0)
        {
            actor2 = ((VItem*)*iter->FUN_006815c0())->v5(0);
            if (!((LH*)result)->TESRegionGrassObjectList_Add(actor2))
            {
                delete (VDel*)actor2;
            }
        }
        else
        {
            ((LH*)result)->TESRegionGrassObjectList_Add((Actor*)*iter->FUN_006815c0());
        }
        iter = iter->FUN_00726070();
    }
    return result;
}
