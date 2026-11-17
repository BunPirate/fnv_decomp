#include <xmmintrin.h>

// src/havok/physics/utilities/actions/angulardashpot/hkpangulardashpotaction.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/actions/angulardashpot/hkpangulardashpotaction.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.


#include "../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../include/hkQuaternion.h"
#include "../../../../../../include/hkReferencedObject.h"
#include "../../../../../../include/hkVector4.h"

__forceinline hkQuaternion::hkQuaternion() {}


// The TLS accessor is 0x00c85750, also bound as hkMemoryRouter::GetMonitorStream in hkbsdsocket.cpp.
inline void* hkReferencedObject::operator new(std::size_t uiSize)
{
    hkMemoryAllocator& allocator =
        reinterpret_cast<hkMemoryAllocator&>((&hkMemoryRouter::getInstance())->heap());
    hkReferencedObject* pkObj = static_cast<hkReferencedObject*>(allocator.blockAlloc(uiSize));
    pkObj->m_memSizeAndFlags = (unsigned short)uiSize;
    return pkObj;
}

extern const __m128 DAT_010c71b0;

class FUN_00cf4d80
{
  public:
    FUN_00cf4d80(void* entityA, void* entityB, unsigned long userData) throw();
    virtual ~FUN_00cf4d80() throw();

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    void* m_pOwningWorld;
    void* m_pCurrentSimulationIsland;
    unsigned long m_ulUserData;
    const char* m_name;
    void* m_pEntityA;
    void* m_pEntityB;
};

class FUN_00d4dbe0 : public FUN_00cf4d80
{
  public:
    FUN_00d4dbe0(void* entityA, void* entityB, unsigned long userData) throw();
    virtual ~FUN_00d4dbe0() throw();

    hkQuaternion m_rotation;
    float m_fSpringStrength;
    float m_fMotorDamping;
    int unk38, unk3C;
};

// @fnv 0x00d4dbe0
// pdb: hkpAngularDashpotAction::hkpAngularDashpotAction | hkpAngularDashpotAction.obj | retail, call graph (shared callers), high
// pdb params: flag
FUN_00d4dbe0::FUN_00d4dbe0(void* entityA, void* entityB, unsigned long userData) throw()
    : FUN_00cf4d80(entityA, entityB, userData), m_fSpringStrength(0.1f), m_fMotorDamping(0.01f)
{
    *reinterpret_cast<__m128*>(&m_rotation) = DAT_010c71b0;
}

namespace fnv_00d4dc30 {
struct hkpEntityPairD4DC
{
    void* m_pEntityA;
    void* m_pEntityB;
};

struct hkpConstraintInputD4DC
{
    hkpEntityPairD4DC* m_pair;
    int m_type;
};

class FUN_00d4dbe0 : public hkReferencedObject
{
  public:
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    hkVector4 m_kAxisEndPoints;
    float m_kMinimumCorner;
    float m_kMaximumCorner;
    int unk38;
    int unk3C;

    FUN_00d4dbe0(void* entityA, void* entityB, int userData) throw();
    virtual ~FUN_00d4dbe0() throw();
};

class hkpConstraintTemplateD4DC
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int m_ulUserData;
    int unk14;
    int unk18;
    int unk1C;
    hkVector4 m_kAxisEndPoints;
    float m_kMinimumCorner;
    float m_kMaximumCorner;

    FUN_00d4dbe0* hkpAngularDashpotAction_clone(const hkpConstraintInputD4DC& newEntities, const hkpConstraintInputD4DC& newPhantoms);
};

// Returns null unless kA.m_type is 2 and kB.m_type is 0; otherwise creates a FUN_00d4dbe0 from kA's entity pair and copies axis end points and min/max corners.
// @fnv 0x00d4dc30
// src: HAVOK_SRC 0x00d4dc30
// pdb: hkpAngularDashpotAction::clone | hkpAngularDashpotAction.obj | retail, upstream name already matches, high
// pdb params: newEntities, newPhantoms
// pdb locals: assertBuf, ostr
FUN_00d4dbe0* hkpConstraintTemplateD4DC::hkpAngularDashpotAction_clone(const hkpConstraintInputD4DC& newEntities,
                                                      const hkpConstraintInputD4DC& newPhantoms)
{
    if (newEntities.m_type != 2)
        return 0;
    if (newPhantoms.m_type != 0)
        return 0;
    FUN_00d4dbe0* pkResult = new FUN_00d4dbe0(newEntities.m_pair->m_pEntityA, newEntities.m_pair->m_pEntityB, m_ulUserData);
    pkResult->m_kAxisEndPoints = m_kAxisEndPoints;
    pkResult->m_kMinimumCorner = m_kMinimumCorner;
    pkResult->m_kMaximumCorner = m_kMaximumCorner;
    return pkResult;
}
}  // namespace fnv_00d4dc30
