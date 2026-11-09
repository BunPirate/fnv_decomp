
// src/havok/physics/collide/shape/heightfield/trisampledheightfield/hkptrisampledheightfieldcollection_gs_nogs_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/havok/physics/collide/shape/heightfield/trisampledheightfield/hkptrisampledheightfieldcollection.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/collide/shape/heightfield/trisampledheightfield/hkptrisampledheightfieldcollection.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/heightfield/trisampledheightfield/hkptrisampledheightfieldcollection.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../../../../../include/hkpSampledHeightFieldShape.h"
#include "../../../../../../../include/hkAabb.h"
#include "../../../../../../../include/hkTransform.h"

__forceinline hkAabb::hkAabb() {}

struct FUN_00d26460_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    float m_fBoundRadius;
    int unk24;
    int unk28;
    int unk2C;
    __m128 m_kTranslation;
    hkpSampledHeightFieldShape* hkpTriSampledHeightFieldCollection_getHeightFieldShape();
    void hkpTriSampledHeightFieldCollection_getAabb(const hkTransform& localToWorld, float tolerance, hkAabb& out);
};
// @fnv 0x00d26460
// src: XBOX_PDB 0x00d26460
// pdb: hkpTriSampledHeightFieldCollection::getAabbImpl | hkpTriSampledHeightFieldCollection.obj | retail, vtable slot, high
// pdb params: localToWorld, tolerance, out
// pdb locals: tempAabb
void FUN_00d26460_cls::hkpTriSampledHeightFieldCollection_getAabb(const hkTransform& localToWorld, float tolerance, hkAabb& out)
{
    hkAabb kAabb;
    hkpTriSampledHeightFieldCollection_getHeightFieldShape()->CalculateAabb(localToWorld,
                               m_fBoundRadius + tolerance, kAabb);
    __m128 kMaxPoint = _mm_add_ps(m_kTranslation, kAabb.m_kMaximumCorner.m_vComponents);
    __m128 kMinBoundsCur = _mm_add_ps(m_kTranslation, kAabb.m_kMinimumCorner.m_vComponents);
    out.m_kMinimumCorner.m_vComponents = _mm_min_ps(kAabb.m_kMinimumCorner.m_vComponents, kMinBoundsCur);
    out.m_kMaximumCorner.m_vComponents = _mm_max_ps(kAabb.m_kMaximumCorner.m_vComponents, kMaxPoint);
}
