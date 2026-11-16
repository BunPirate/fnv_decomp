#pragma once

#include <cstddef>
#include "hkReferencedObject.h"
#include "hkBool.h"
#include "hkStringPtr.h"
#include "hkpConstraintInstanceSmallArraySerializeOverrideType.h"

class hkpConstraintData;
class hkpConstraintOwner;
class hkpEntity;
class hkpModifierConstraintAtom;
struct ConstraintRuntimeInfo;

typedef unsigned char hkUint8;
typedef unsigned int hkUint32;
typedef unsigned long hkUlong;

// pdb: class hkpConstraintInstance, size 0x38, bases: hkReferencedObject, 12 members
class hkpConstraintInstance : public hkReferencedObject
{
public:
    enum ConstraintPriority
    {
        PRIORITY_INVALID = 0,
        PRIORITY_PSI = 1,
        PRIORITY_SIMPLIFIED_TOI_UNUSED = 2,
        PRIORITY_TOI = 3,
        PRIORITY_TOI_HIGHER = 4,
        PRIORITY_TOI_FORCED = 5
    };

    enum InstanceType
    {
        TYPE_NORMAL = 0,
        TYPE_CHAIN = 1
    };

    enum AddReferences
    {
        DO_NOT_ADD_REFERENCES = 0,
        DO_ADD_REFERENCES = 1
    };

    enum CloningMode
    {
        CLONE_INSTANCES_ONLY = 0,
        CLONE_DATAS_WITH_MOTORS = 1,
        CLONE_FORCE_SHALLOW = 2
    };

    enum OnDestructionRemapInfo
    {
        ON_DESTRUCTION_REMAP = 0,
        ON_DESTRUCTION_REMOVE = 1,
        ON_DESTRUCTION_RESET_REMOVE = 2
    };

    class SmallArraySerializeOverrideType
    {
    public:
        class CommandArgument;
        struct DefaultStruct;

        static const ClassMemberDescriptor Members[];
        static const hkClass& __cdecl staticClass();

        static void* __cdecl operator new(std::size_t nbytes);
        static void __cdecl operator delete(void* p);
        static void* __cdecl operator new(std::size_t n, void* p);
        static void* __cdecl operator new[](std::size_t n, void* p);
        static void __cdecl operator delete(void* p, void* placement);
        static void __cdecl operator delete[](void* p, void* placement);

        void* m_data;
        hkUint16 m_size; // src: XBOX_RETAIL_PDB +0x4 (old: m_iElementCount)
        hkUint16 m_capacityAndFlags; // src: XBOX_RETAIL_PDB +0x6 (old: m_iCapacityState)
    };

    static const ClassMemberDescriptor Members[];

    hkpConstraintInstance(ConstraintPriority priority);
    hkpConstraintInstance(int iPriority) throw();
    virtual ~hkpConstraintInstance() throw();
    virtual void vf03(int);
    virtual void vf04(void* arg);
    virtual void vf05(int);
    virtual int vf06();

    hkpEntity* getEntityA() const;
    const hkpConstraintData* getData() const;
    hkpConstraintOwner* getOwner() const;
    hkBool isConstrainedToWorld() const throw();
    ConstraintPriority getPriority() const { return (ConstraintPriority)m_priority; }
    hkpConstraintInstance* clone_00cf3fa0(hkpEntity* newEntityA, hkpEntity* newEntityB, int mode) const throw();

    hkpConstraintOwner* m_owner; // src: XBOX_RETAIL_PDB +0x8 (old: m_pOwnerObject)
    hkpConstraintData* m_data;
    hkpModifierConstraintAtom* m_constraintModifiers; // src: XBOX_RETAIL_PDB +0x10 (old: m_pConstraintModifier)
    hkpEntity* m_entities[2]; // src: XBOX_RETAIL_PDB +0x14 (old: m_kActorEntries)
    hkUint8 m_priority;
    hkBool m_wantRuntime; // src: XBOX_RETAIL_PDB +0x1d (old: m_bWantRuntime)
    hkUint8 m_destructionRemapInfo; // src: XBOX_RETAIL_PDB +0x1e (old: m_eDestructionRemapInfo)
    char pad1F[1];
    hkpConstraintInstanceSmallArraySerializeOverrideType m_listeners; // src: XBOX_RETAIL_PDB +0x20 (old: m_kListeners)
    hkStringPtr m_name;
    hkUlong m_userData; // src: XBOX_RETAIL_PDB +0x2c (old: m_ulUserData)
    ConstraintRuntimeInfo* m_internal; // src: XBOX_RETAIL_PDB +0x30 (old: m_pConstraintInternal)
    hkUint32 m_uid; // src: XBOX_RETAIL_PDB +0x34 (old: m_uiUniqueId)
};
