#define FNV64_HKENUM_INLINE_BODIES

// src/havok/common/geometryutilities/mesh/memory/hkmemorymeshshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/geometryutilities/mesh/memory/hkmemorymeshshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../include/hkArray.h"
#include "../../../../../../include/hkReferencedObject.h"
#include "../../../../../../include/hkStatisticsCollector.h"

// include/ has no hkMeshShape header yet.
// pdb: class hkMeshShape, size 0x8, bases: hkReferencedObject, 0 members
class hkMeshShape : public hkReferencedObject
{
};


#include "../../../../../../include/hkEnum.h"
using ::hkEnum;

enum PrimitiveType
{
    PRIMITIVE_TYPE_UNKNOWN
};

// include/ has no hkMeshSectionCinfo header; the section stride at 0x00e4a040 is 0x20.
// pdb: structure hkMeshSectionCinfo, size 0x20, 8 members
struct hkMeshSectionCinfo
{
    hkReferencedObject* m_vertexBuffer;
    hkReferencedObject* m_material;
    hkEnum<PrimitiveType, unsigned char> m_primitiveType;
    int m_numPrimitives;
    bool m_indexType;
    void* m_indices;
    int m_vertexStartIndex;
    int m_transformIndex;
};

// include/ has no hkMeshSection header; 0x00e4a040 writes this 0x28-byte section result.
// pdb: structure hkMeshSection, size 0x28, 10 members
struct hkMeshSection
{
    hkEnum<PrimitiveType, unsigned char> m_primitiveType;
    int m_numPrimitives;
    int m_numIndices;
    int m_vertexStartIndex;
    int m_transformIndex;
    bool m_indexType;
    void* m_indices;
    hkReferencedObject* m_vertexBuffer;
    hkReferencedObject* m_material;
    int m_sectionIndex;
};

// The shared collector lacks beginObject(name, object, class), used at slot 3 by 0x00e4a0c0.

// include/ has no hkMemoryMeshShape header; both former stand-ins access this same sections array at +8.
// pdb: class hkMemoryMeshShape, size 0x30, bases: hkMeshShape, 4 members
class hkMemoryMeshShape : public hkMeshShape
{
  public:
    int GetNumSections() const;
    void GetSection(int sectionIndex, unsigned char accessFlags, hkMeshSection& sectionOut);
    virtual void calcContentStatistics(hkStatisticsCollector* collector, const hkClass* cls) const throw();

    hkArray<hkMeshSectionCinfo> m_sections;
    hkArray<unsigned short> m_indices16;
    hkArray<unsigned int> m_indices32;
    char* m_name;
};

// @fnv 0x00e4a020
// src: COMMUNITY 0x00e4a020
void __stdcall nullsub_89(void* unused)
{}

// @fnv 0x00e4a030
int hkMemoryMeshShape::GetNumSections() const
{
    return m_sections.m_iElementCount;
}

int hkStatisticsCollector_getAllocatedSize(const void* p, int size) throw();

template <typename T> inline void CollectArray(hkStatisticsCollector* pkCollector, const char* pcFieldName,
                                               const hkArray<T>& kArray)
{
    if (!(kArray.m_iCapacityState & 0x80000000) || pkCollector->m_includeUnmanagedArrayMemory)
    {
        const T* pData = kArray.m_data;
        int iAllocatedSize = hkStatisticsCollector_getAllocatedSize(pData, kArray.getCapacity() * sizeof(T));
        pkCollector->AddMemoryChunk(3, pcFieldName, kArray.m_data, kArray.m_iElementCount * sizeof(T), iAllocatedSize);
    }
}

// Reports the indices16, indices32 and sections arrays plus each section's vertexBuffer and material to the statistics collector.
// @fnv 0x00e4a0c0
// pdb: hkMemoryMeshShape::calcContentStatistics | hkMemoryMeshShape.obj | retail, string-set bridge, high
// pdb params: collector, cls
void hkMemoryMeshShape::calcContentStatistics(hkStatisticsCollector* collector, const hkClass* cls) const throw()
{
    CollectArray(collector, "indices16", m_indices16);
    CollectArray(collector, "indices32", m_indices32);
    CollectArray(collector, "sections", m_sections);
    const int iNumSections = m_sections.m_iElementCount;
    for (int iIndex = 0; iIndex < iNumSections; iIndex++)
    {
        const hkMeshSectionCinfo& kSection = m_sections.m_data[iIndex];
        collector->beginObject("vertexBuffer", kSection.m_vertexBuffer, 0);
        collector->beginObject("material", kSection.m_material, 0);
    }
}

int __cdecl hkMeshPrimitiveUtil_calculateNumIndices(PrimitiveType type, int numPrims);

// Copies the cinfo fields of the mesh section at sectionIndex into sectionOut, computing the index count and gating vertex/indices pointers by accessFlags.
// @fnv 0x00e4a040
// pdb: hkMemoryMeshShape::lockSection | hkMemoryMeshShape.obj | retail, vtable slot, high
// pdb params: sectionIndex, accessFlags, sectionOut
void hkMemoryMeshShape::GetSection(int sectionIndex, unsigned char accessFlags, hkMeshSection& sectionOut)
{
    const hkMeshSectionCinfo& cinfo = m_sections.m_data[sectionIndex];
    sectionOut.m_primitiveType = cinfo.m_primitiveType;
    sectionOut.m_numPrimitives = cinfo.m_numPrimitives;
    sectionOut.m_numIndices = hkMeshPrimitiveUtil_calculateNumIndices(cinfo.m_primitiveType, cinfo.m_numPrimitives);
    sectionOut.m_vertexStartIndex = cinfo.m_vertexStartIndex;
    sectionOut.m_indexType = cinfo.m_indexType;
    sectionOut.m_transformIndex = cinfo.m_transformIndex;
    sectionOut.m_vertexBuffer = (accessFlags & 2) ? cinfo.m_vertexBuffer : 0;
    sectionOut.m_indices = 0;
    if ((accessFlags & 1) && cinfo.m_indexType)
        sectionOut.m_indices = cinfo.m_indices;
    sectionOut.m_material = cinfo.m_material;
    sectionOut.m_sectionIndex = sectionIndex;
}

void __cdecl hkReferencedObject_lockAll() throw();
void __cdecl hkReferencedObject_unlockAll() throw();

class hkBoolC
{
  public:
    hkBoolC() throw()
    {}
    hkBoolC(bool b) throw()
    {
        m_cBooleanValue = static_cast<char>(b);
    }
    char m_cBooleanValue;
};
template <class ENUM, class STORAGE> class hkEnumC
{
  public:
    hkEnumC() throw()
    {}
    hkEnumC(ENUM e) throw()
    {
        m_kStorage = static_cast<STORAGE>(e);
    }
    STORAGE m_kStorage;
};
enum ConstraintPriority
{
    PRIORITY_INVALID,
    PRIORITY_PSI,
    PRIORITY_SIMPLIFIED_TOI_UNUSED,
    PRIORITY_TOI
};
enum OnDestructionRemapInfo
{
    ON_DESTRUCTION_REMAP = 0,
    ON_DESTRUCTION_REMOVE = 1,
    ON_DESTRUCTION_RESET_REMOVE = 2
};
class BaseObj
{
  public:
    BaseObj() throw()
    {}
    virtual ~BaseObj() throw();
};
class RefObject : public BaseObj
{
  public:
    RefObject() throw()
    {
        m_sReferenceCount = 1;
    }
    ~RefObject() throw();
    void FUN_00c90510() throw();

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class ConstraintEntity : public RefObject
{
};
class ConstraintData : public RefObject
{
};
class ConstraintOwner;
struct ConstraintModifier;
struct ConstraintInternal;
struct ConstraintListener;

struct ListenerArray
{
    ListenerArray() throw() : m_data(0), m_iElementCount(0), m_iCapacityState(0x8000)
    {}
    ConstraintListener** m_data;
    unsigned short m_iElementCount;
    unsigned short m_iCapacityState;
};

struct ConstraintName
{
    ConstraintName() throw();
    ~ConstraintName() throw();
    const char* m_pcText;
};

class FUN_00cf3ea0 : public RefObject
{
  public:
    FUN_00cf3ea0(ConstraintEntity* entityA, ConstraintEntity* entityB, ConstraintData* data,
                 ConstraintPriority priority) throw();
    virtual ~FUN_00cf3ea0() throw();

    ConstraintOwner* m_pOwnerObject;
    ConstraintData* m_data;
    ConstraintModifier* m_pConstraintModifier;
    ConstraintEntity* m_kActorEntries[2];
    hkEnumC<ConstraintPriority, unsigned char> m_priority;
    hkBoolC m_bWantRuntime;
    hkEnumC<OnDestructionRemapInfo, unsigned char> m_eDestructionRemapInfo;
    ListenerArray m_kListeners;
    ConstraintName m_name;
    unsigned int m_ulUserData;
    ConstraintInternal* m_pConstraintInternal;
    unsigned int m_uiUniqueId;
};

// Stores the entities, data, and priority, then increments references for entityA, nonnull entityB, and data.
// @fnv 0x00cf3ea0
// pdb: hkpConstraintInstance::hkpConstraintInstance | hkpConstraintInstance.obj | retail, call graph (shared callers), high
// pdb params: f
FUN_00cf3ea0::FUN_00cf3ea0(ConstraintEntity* entityA, ConstraintEntity* entityB, ConstraintData* data,
                           ConstraintPriority priority) throw()
    : m_pOwnerObject(0), m_data(data), m_priority(priority), m_bWantRuntime(true),
      m_eDestructionRemapInfo(ON_DESTRUCTION_REMAP), m_ulUserData(0), m_pConstraintInternal(0), m_uiUniqueId(0xfffffff0)
{
    m_kActorEntries[0] = entityA;
    m_kActorEntries[1] = entityB;
    m_pConstraintModifier = 0;

    hkReferencedObject_lockAll();
    m_kActorEntries[0]->FUN_00c90510();
    if (m_kActorEntries[1])
    {
        m_kActorEntries[1]->FUN_00c90510();
    }
    m_data->FUN_00c90510();
    hkReferencedObject_unlockAll();
}
