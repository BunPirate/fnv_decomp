#include "../../include/hkArray.h"

// src/staging/blk_00dc0000_o2_welding.cpp - staging unit created 2026-10-31 for 0x00ddf070 (flag review): in hkpmeshweldingutility.cpp
// the SSE helper methods of NormalVector (used by 0x00ddd620) make VC9 drop the private register convention of static functions
// compiled after them; this function takes name in eax and stringTable in ebx, so it gets a file without them. The declarations
// below are copied from hkpmeshweldingutility.cpp.

struct S_00ddecf0_Heap;
struct S_00ddecf0_Router
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    S_00ddecf0_Heap* m_pStreamAllocator;
    S_00ddecf0_Heap& heap()
    {
        return *m_pStreamAllocator;
    }
};
S_00ddecf0_Router* hkMemoryRouter_getInstance();
void __cdecl ResizeAudioStream(void* mem, void* array, int sizeElem) throw();

extern const char DAT_010d8038[];

struct S00ddf070_StringPtr
{
    const char* m_pcText;
    S00ddf070_StringPtr* hkStringPtr_ctor(const char* string) throw();
    S00ddf070_StringPtr* FUN_00cb0bd0(const S00ddf070_StringPtr& strRef) throw();
    void Object_UpdateFields_00cb0c00() throw();
    const char* cString() const
    {
        return (const char*)((unsigned int)m_pcText & ~1u);
    }
};

struct S00ddf070_Node;

struct S00ddf070_Node
{
    float m_uiFilterValue[8];
    unsigned short m_uiItemCount[8];
    hkArrayBase<S00ddf070_Node*> m_children;
    int unk3c;
    double m_dValue;
    int unk48;
    const char* m_name;
    int unk50;
    int unk54;
    S00ddf070_Node* hkMonitorStreamAnalyzer_Node_ctor(S00ddf070_Node* parent, const char* name, int type) throw();
};
struct S00ddf070_Heap
{
    virtual void v00();
    virtual void* AllocateMemoryBlock(int numBytes) throw();
};

int __cdecl hkString_strCmp(const char* a, const char* b) throw();

// Finds or creates a child node by name, appends the name to the string pool if new, and accumulates value, count, and two counters on the node.
// @fnv 0x00ddf070
// src: HAVOK_LIB 0x00ddf070
// pdb: _newNode | hkStreamStatisticsCollector.obj | retail, upstream name already matches, high
// pdb params: parent, name, size, allocSize, stringTable
static __declspec(noinline) S00ddf070_Node* _newNode(S00ddf070_Node* parent, const char* name, int value, int allocSize,
                                                         hkArrayBase<S00ddf070_StringPtr>* stringTable)
{
    if (allocSize == 0)
        allocSize = value;
    if (!name)
        name = DAT_010d8038;

    S00ddf070_Node* child = 0;
    for (int i = 0; parent && i < parent->m_children.GetLogicalSize(); i++)
    {
        if (hkString_strCmp(parent->m_children[i]->m_name, name) == 0)
        {
            child = parent->m_children[i];
            break;
        }
    }
    if (!child)
    {
        if (stringTable && name)
        {
            {
                S00ddf070_StringPtr strName;
                strName.hkStringPtr_ctor(name);
                S00ddf070_Heap& heap = *(S00ddf070_Heap*)&hkMemoryRouter_getInstance()->heap();
                if (stringTable->m_iElementCount == (stringTable->m_iCapacityState & 0x3fffffff))
                    ResizeAudioStream(&heap, stringTable, 4);
                S00ddf070_StringPtr* dest = stringTable->m_data + stringTable->m_iElementCount;
                if (dest)
                    dest->FUN_00cb0bd0(strName);
                stringTable->m_iElementCount++;
                strName.Object_UpdateFields_00cb0c00();
            }
            name = stringTable->back().cString();
        }
        void* mem = ((S00ddf070_Heap*)&hkMemoryRouter_getInstance()->heap())->AllocateMemoryBlock(0x58);
        child = mem ? ((S00ddf070_Node*)mem)->hkMonitorStreamAnalyzer_Node_ctor(parent, name, 1) : 0;
    }
    child->m_uiFilterValue[0] += (float)value;
    child->m_uiFilterValue[1] += (float)allocSize;
    child->m_uiItemCount[0] += 1;
    child->m_uiItemCount[1] += 1;
    return child;
}

hkArrayBase<S00ddf070_StringPtr>* volatile g00ddf070_strings;
S00ddf070_Node* volatile g00ddf070_parent;
const char* volatile g00ddf070_name;
volatile int g00ddf070_v;
S00ddf070_Node* volatile g00ddf070_out;
void S00ddf070_Caller()
{
    g00ddf070_out = _newNode(g00ddf070_parent, g00ddf070_name, g00ddf070_v, g00ddf070_v, g00ddf070_strings);
}
