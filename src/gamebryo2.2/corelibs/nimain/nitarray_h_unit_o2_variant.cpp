
// src/gamebryo2.2/corelibs/nimain/nitarray_h_unit_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/gamebryo2.2/corelibs/nimain/nitarray_h_unit.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

// Header unit for gamebryo2.2/corelibs/nimain/nitarray.inl.
// No @fnv markers here; the covered template members are defined and
// marked in the header. This translation unit only forces the covered
// COMDATs to be emitted so their bytes can be compared.
#include "nitarray.inl"
#include "../../../../include/StrArr.h"

inline unsigned int AddViewerString(StrArr* array, char* const& element)
{
    unsigned int index = array->m_usSize;
    if (index >= array->m_usMaxSize)
        array->SetSize(index + array->m_usGrowBy);
    array->SetAt(index, element);
    return index;
}

inline unsigned int SetViewerStringAtGrow(StrArr* array, unsigned int index, char* const& element)
{
    if (index >= array->m_usMaxSize)
        array->SetSize(index + array->m_usGrowBy);
    array->SetAt(index, const_cast<char*&>(element));
    return index;
}

struct FUN_00cc6540_Class
{
    unsigned char m_auiShapeKeys[4];
    void* m_pUserData;

    void hkConstraintCinfo_GetViewerStrings(StrArr* apStrings);
    void hkRagdollLimitsConstraintCinfo_GetViewerStrings(StrArr* apStrings);
};

char* __cdecl NiGetViewerString_00a7d550(char const* name, float value);

// @fnv 0x00cc6540
// src: XBOX_PDB 0x00cc6540
// pdb: hkRagdollLimitsConstraintCinfo::GetViewerStrings | bhkRagdollLimitsConstraint.obj | retail, string-set bridge, high
// pdb params: apStrings
// pdb locals: pd
void FUN_00cc6540_Class::hkRagdollLimitsConstraintCinfo_GetViewerStrings(StrArr* apStrings)
{
    hkConstraintCinfo_GetViewerStrings(apStrings);

    unsigned char* data = static_cast<unsigned char*>(m_pUserData);
    if (data)
    {
        char* value = NiGetViewerString_00a7d550("ConeMinAngle", *reinterpret_cast<float*>(data + 0xa0));
        unsigned int index = apStrings->m_usSize;
        unsigned int size = apStrings->m_usMaxSize;
        if (index >= size)
            apStrings->SetSize(index + apStrings->m_usGrowBy);
        apStrings->SetAt(index, value);

        value = NiGetViewerString_00a7d550("PlaneMinAngle", *reinterpret_cast<float*>(data + 0xb0));
        index = apStrings->m_usSize;
        size = apStrings->m_usMaxSize;
        if (index >= size)
            apStrings->SetSize(index + apStrings->m_usGrowBy);
        apStrings->SetAt(index, value);

        value = NiGetViewerString_00a7d550("PlaneMaxAngle", *reinterpret_cast<float*>(data + 0xb4));
        index = apStrings->m_usSize;
        size = apStrings->m_usMaxSize;
        if (index >= size)
            apStrings->SetSize(index + apStrings->m_usGrowBy);
        apStrings->SetAt(index, value);

        value = NiGetViewerString_00a7d550("TwistMinAngle", *reinterpret_cast<float*>(data + 0x88));
        index = apStrings->m_usSize;
        size = apStrings->m_usMaxSize;
        if (index >= size)
            apStrings->SetSize(index + apStrings->m_usGrowBy);
        apStrings->SetAt(index, value);

        value = NiGetViewerString_00a7d550("TwistMaxAngle", *reinterpret_cast<float*>(data + 0x8c));
        index = apStrings->m_usSize;
        size = apStrings->m_usMaxSize;
        if (index >= size)
            apStrings->SetSize(index + apStrings->m_usGrowBy);
        apStrings->SetAt(index, value);
    }
}

namespace fnv_00cf46e0 {

struct GlobalObjectO2_00a7b610
{
    unsigned char _pad[0x2b4];
    unsigned int m_02b4;
};

extern __declspec(thread) GlobalObjectO2_00a7b610 g_tls_object;
extern GlobalObjectO2_00a7b610* bhkSpringDamperConstraintMotor_ms_RTTI; // src: XBOX_RETAIL_PDB 0x01268740 (old: DAT_01268740/g_01268740)

char* __cdecl _FUN_00a7d330(GlobalObjectO2_00a7b610* object);

struct TLSGuard
{
    unsigned int saved;

    TLSGuard() : saved(g_tls_object.m_02b4)
    {
        g_tls_object.m_02b4 = 0x10;
    }

    ~TLSGuard()
    {
        g_tls_object.m_02b4 = saved;
    }
};

// @fnv 0x00cf46e0
// src: XBOX_PDB 0x00cf46e0
// pdb: bhkSpringDamperConstraintMotor::GetViewerStrings | bhkSpringDamperConstraintMotor.obj | retail, upstream name already matches, high
// pdb params: pkStrings
// pdb locals: tempMemContext
void __stdcall bhkSpringDamperConstraintMotor_GetViewerStrings(StrArr* pkStrings)
{
    TLSGuard guard;
    char* value = _FUN_00a7d330(bhkSpringDamperConstraintMotor_ms_RTTI);
    unsigned int index = pkStrings->m_usSize;

    if (index >= pkStrings->m_usMaxSize)
        pkStrings->SetSize(static_cast<unsigned int>(index + pkStrings->m_usGrowBy));

    pkStrings->SetAt(index, value);
}
}  // namespace fnv_00cf46e0

// Keep the index-returning variant local; shared AddFirstEmpty returns void.
// The explicit ECX receiver and unused EDX argument preserve the original member ABI.
// @fnv 0x00a5b4b0
// src: COMMUNITY 0x00a5b4b0
// pdb: NiGlobalStringTable::InstanceRemoveUnusedStrings | NiGlobalStringTable.obj | retail, object-file run extension, low
// pdb locals: khandle, ui, arraySize, arrayPos, pkMem
int __fastcall NiTPrimitiveArray_DWORD_AddFirstEmpty(StrArr* array, void*, char*& value)
{
    if (value == 0)
        return -1;
    unsigned short i = 0;
    for (; i < array->m_usSize; i++)
    {
        if (array->m_pBase[i] == 0)
        {
            array->m_pBase[i] = value;
            array->m_usESize++;
            return i;
        }
    }
    unsigned int count = array->m_usSize;
    if (count >= array->m_usMaxSize)
        array->SetSize(array->m_usGrowBy + count);
    array->SetAt(count, value);
    return count;
}

extern __declspec(thread) int g_iC8AD40AllocTag;

struct BC8AD40AllocTagScope
{
    int m_iSaved;

    BC8AD40AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_iC8AD40AllocTag;
        g_iC8AD40AllocTag = aiAllocationTag;
    }
    ~BC8AD40AllocTagScope()
    {
        g_iC8AD40AllocTag = m_iSaved;
    }
};

extern const char* g_pcC8AD40Name;

char* __cdecl NiViewerStrings_NiGetViewerString_Title(const char* pcString);

class FUN_00c8ad40_cls
{
  public:
    void C8AD40BaseGetViewerStrings(StrArr* apStrings);
    void bhkBinaryAction_GetViewerStrings(StrArr* apStrings);
};

// @fnv 0x00c8ad40
// src: XBOX_PDB 0x00c8ad40
// pdb: bhkBinaryAction::GetViewerStrings | bhkBinaryAction.obj | retail, upstream name already matches, high
// pdb params: apStrings
// pdb locals: tempMemContext
void FUN_00c8ad40_cls::bhkBinaryAction_GetViewerStrings(StrArr* apStrings)
{
    BC8AD40AllocTagScope kScope(0x10);
    C8AD40BaseGetViewerStrings(apStrings);
    char* pcName = NiViewerStrings_NiGetViewerString_Title(g_pcC8AD40Name);
    AddViewerString(apStrings, pcName);
}

namespace fnv_00cc31c0 {
extern __declspec(thread) int g_iCC31C0MemContext;

class CC31C0MemContext
{
  public:
    CC31C0MemContext(int aiMemoryContext)
    {
        m_iPrevious = g_iCC31C0MemContext;
        g_iCC31C0MemContext = aiMemoryContext;
    }
    ~CC31C0MemContext()
    {
        g_iCC31C0MemContext = m_iPrevious;
    }

    int m_iPrevious;
};

extern const char* bhkSpringAction_ms_RTTI; // src: XBOX_RETAIL_PDB 0x012685b0 (old: DAT_012685b0/g_012685b0/g_pcCC31C0ClassName)
extern "C" char* __cdecl NiViewerStrings_NiGetViewerString_Title(const char* pcName);

class CC31C0Object
{
  public:
    void GetViewerStringsBase(StrArr* apStrings);
    void bhkSpringAction_GetViewerStrings(StrArr* apStrings);
};

// @fnv 0x00cc31c0
// src: XBOX_PDB 0x00cc31c0
// pdb: bhkSpringAction::GetViewerStrings | bhkSpringAction.obj | retail, upstream name already matches, high
// pdb params: apStrings
// pdb locals: tempMemContext
void CC31C0Object::bhkSpringAction_GetViewerStrings(StrArr* apStrings)
{
    CC31C0MemContext kContext(0x10);
    GetViewerStringsBase(apStrings);
    AddViewerString(apStrings, NiViewerStrings_NiGetViewerString_Title(bhkSpringAction_ms_RTTI));
}
}  // namespace fnv_00cc31c0

struct ViewerObject
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void* GetType();
};
const char* __cdecl TypeName(void*);
char* __cdecl MakeViewerString(const char*, const char*);
char* __cdecl NiGetViewerString_00a7d4d0(const char*, int);
int __cdecl FormatViewer(char*, unsigned int, const char*, ...);
struct ViewerConstraint
{
    int unk00;
    ViewerObject* object;
    int priority;
    void* entityA;
    void* entityB;
    void hkConstraintCinfo_GetViewerStrings(StrArr* apStrings);
};
// @fnv 0x00c8a560
// src: XBOX_PDB 0x00c8a560
// pdb: hkConstraintCinfo::GetViewerStrings | bhkConstraint.obj | retail, string-set bridge, high
// pdb params: apStrings
// pdb locals: tempMemContext, pstr
void ViewerConstraint::hkConstraintCinfo_GetViewerStrings(StrArr* apStrings)
{
    BC8AD40AllocTagScope scope(16);
    char* text;
    char buffer[32];
    if (object)
    {
        text = MakeViewerString("Type", TypeName(object->GetType()));
        AddViewerString(apStrings, text);
    }
    FormatViewer(buffer, 32, "0x%8X", entityA);
    text = MakeViewerString("hkpEntityA", buffer);
    AddViewerString(apStrings, text);
    FormatViewer(buffer, 32, "0x%8X", entityB);
    text = MakeViewerString("hkpEntityB", buffer);
    AddViewerString(apStrings, text);
    text = NiGetViewerString_00a7d4d0("ePriority", priority);
    AddViewerString(apStrings, text);
}

// Appends this class name to the viewer strings after the base entries, under the Havok allocation tag.

extern __declspec(thread) int g_iCC4740AllocTag;

struct BCC4740AllocTagScope
{
    int m_iSaved;

    BCC4740AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_iCC4740AllocTag;
        g_iCC4740AllocTag = aiAllocationTag;
    }
    ~BCC4740AllocTagScope()
    {
        g_iCC4740AllocTag = m_iSaved;
    }
};

extern const char* g_pcCC4740Name;

char* __cdecl NiViewerStrings_NiGetViewerString_Title(const char* pcString);

class CC4740Base
{
  public:
    void GetViewerStrings(StrArr* apStrings);
};

class CC4740Derived : public CC4740Base
{
  public:
    void bhkAngularDashpotAction_GetViewerStrings(StrArr* apStrings);
};

// @fnv 0x00cc4740
// src: XBOX_PDB 0x00cc4740
// pdb: bhkAngularDashpotAction::GetViewerStrings | bhkAngularDashpotAction.obj | retail, upstream name already matches, high
// pdb params: apStrings
// pdb locals: tempMemContext
void CC4740Derived::bhkAngularDashpotAction_GetViewerStrings(StrArr* apStrings)
{
    BCC4740AllocTagScope kScope(0x10);
    CC4740Base::GetViewerStrings(apStrings);
    char* pcName = NiViewerStrings_NiGetViewerString_Title(g_pcCC4740Name);
    AddViewerString(apStrings, pcName);
}

extern __declspec(thread) int g_iCC4740AllocTag;
struct CF4520AllocTagScope
{
    int saved;
    CF4520AllocTagScope(int tag)
    {
        saved = g_iCC4740AllocTag;
        g_iCC4740AllocTag = tag;
    }
    ~CF4520AllocTagScope()
    {
        g_iCC4740AllocTag = saved;
    }
};
extern const char* bhkVelocityConstraintMotor_ms_RTTI; // src: XBOX_RETAIL_PDB 0x01268738 (old: DAT_01268738/g_01268738)
char* __cdecl NiViewerStrings_NiGetViewerString_Title(const char* name);
// @fnv 0x00cf4520
// src: XBOX_PDB 0x00cf4520
// pdb: bhkVelocityConstraintMotor::GetViewerStrings | bhkVelocityConstraintMotor.obj | retail, upstream name already matches, high
// pdb params: pkStrings
// pdb locals: tempMemContext
void __stdcall bhkVelocityConstraintMotor_GetViewerStrings(StrArr* pkStrings)
{
    CF4520AllocTagScope tag(16);
    char* element = NiViewerStrings_NiGetViewerString_Title(bhkVelocityConstraintMotor_ms_RTTI);
    AddViewerString(pkStrings, element);
}

extern __declspec(thread) int g_iCCCFD0AllocTag;
struct BCCCFD0AllocTagScope
{
    int m_iSaved;

    BCCCFD0AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_iCCCFD0AllocTag;
        g_iCCCFD0AllocTag = aiAllocationTag;
    }
    ~BCCCFD0AllocTagScope()
    {
        g_iCCCFD0AllocTag = m_iSaved;
    }
};

extern const char* bhkExtendedMeshShape_ms_RTTI; // src: XBOX_RETAIL_PDB 0x0126867c (old: DAT_0126867c/g_0126867c/g_pcCCCFD0Name)

class CCCFD0Base
{
  public:
    void GetViewerStrings(StrArr* apStrings);
};

class CCCFD0Derived : public CCCFD0Base
{
  public:
    void bhkExtendedMeshShape_GetViewerStrings(StrArr* apStrings);
};

// @fnv 0x00cccfd0
// src: XBOX_PDB 0x00cccfd0
// pdb: bhkExtendedMeshShape::GetViewerStrings | bhkExtendedMeshShape.obj | retail, upstream name already matches, high
// pdb params: apStrings
// pdb locals: tempMemContext
void CCCFD0Derived::bhkExtendedMeshShape_GetViewerStrings(StrArr* apStrings)
{
    BCCCFD0AllocTagScope kScope(0x10);
    CCCFD0Base::GetViewerStrings(apStrings);
    AddViewerString(apStrings, NiViewerStrings_NiGetViewerString_Title(bhkExtendedMeshShape_ms_RTTI));
}

extern "C" void _ReadWriteBarrier();
struct CAA010Inner
{
    virtual void OpA();
    virtual void OpB();
    virtual void OpC();
    virtual void OpD();
    virtual void OpE();
    virtual void OpF();
    virtual void OpG();
    virtual void OpH();
    virtual void* GetHandle();
};

struct CAA010Shell
{
    virtual void Activate(int flag);
    virtual void OpB();
    virtual void OpC();
    virtual void OpD();
    virtual void OpE();
    virtual void PassArray(StrArr* array);
    void SetChildObject(CAA010Inner* apData);
};

struct CAA010Data
{
    int unk00;
    int unk04;
    int unk08;
    CAA010Inner* m_obj;
    int unk10;
    int unk14;
    int unk18;
    float m_f;
};

extern __declspec(thread) int g_caa010TlsTag;

struct CAA010TagScope
{
    int m_iSaved;
    CAA010TagScope(int aiAllocationTag)
    {
        m_iSaved = g_caa010TlsTag;
        g_caa010TlsTag = aiAllocationTag;
    }
    ~CAA010TagScope()
    {
        g_caa010TlsTag = m_iSaved;
    }
};

CAA010Shell* __cdecl CreateSaver(void* aiType);

struct CAA010This
{
    int unk00;
    void* m_pUserData;
    void hkConstraintCinfo_GetViewerStrings(StrArr* apStrings);
    CAA010Inner* GetObj()
    {
        return m_pUserData ? ((CAA010Data*)m_pUserData)->m_obj : 0;
    }
    void hkMalleableConstraintCinfo_GetViewerStrings(StrArr* apStrings);
};

// @fnv 0x00caa010
// src: XBOX_PDB 0x00caa010
// pdb: hkMalleableConstraintCinfo::GetViewerStrings | bhkMalleableConstraint.obj | retail, string-set bridge, high
// pdb params: apStrings
// pdb locals: tempMemContext, pd, pi
void CAA010This::hkMalleableConstraintCinfo_GetViewerStrings(StrArr* apStrings)
{
    CAA010TagScope scope(16);
    hkConstraintCinfo_GetViewerStrings(apStrings);
    SetViewerStringAtGrow(apStrings, apStrings->m_usSize, NiGetViewerString_00a7d550("Strength", m_pUserData ? ((CAA010Data*)m_pUserData)->m_f : 0.0f));
    CAA010Inner* inner = GetObj();
    _ReadWriteBarrier();
    if (inner)
    {
        CAA010Shell* shell = CreateSaver(inner->GetHandle());
        if (shell)
        {
            shell->SetChildObject(inner);
            shell->PassArray(apStrings);
            shell->Activate(1);
            return;
        }
        return;
    }
}

extern const char* bhkPositionConstraintMotor_ms_RTTI; // src: XBOX_RETAIL_PDB 0x01268730 (old: DAT_01268730/g_01268730)
// @fnv 0x00cf4300
// src: XBOX_PDB 0x00cf4300
// pdb: bhkPositionConstraintMotor::GetViewerStrings | bhkPositionConstraintMotor.obj | retail, upstream name already matches, high
// pdb params: pkStrings
// pdb locals: tempMemContext
void __stdcall bhkPositionConstraintMotor_GetViewerStrings(StrArr* pkStrings)

{

    CF4520AllocTagScope scope(16);

    char* pcElement = NiViewerStrings_NiGetViewerString_Title(bhkPositionConstraintMotor_ms_RTTI);

    AddViewerString(pkStrings, pcElement);
}
