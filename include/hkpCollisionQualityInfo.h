#pragma once
#include "hkBool.h"
#include "hkPadSpu.h"

typedef float hkReal;
typedef int hkBool32;

// src: XBOX_PDB; hkpCollisionQualityInfo is 0x40 bytes. Exe continuous GSK reads TOI fields through +0x3e.
// pdb: structure hkpCollisionQualityInfo, size 0x40, 17 members
struct hkpCollisionQualityInfo
{
    __declspec(align(16)) hkReal m_keepContact; // src: XBOX_RETAIL_PDB +0x0 (old: m_fMinimumCollisionSeparation)
    hkReal m_create4dContact; // src: XBOX_RETAIL_PDB +0x4 (old: m_fMinimumExtraSeparation)
    hkReal m_createContact; // src: XBOX_RETAIL_PDB +0x8 (old: m_fMaximumExtraSeparation)
    hkReal m_manifoldTimDistance; // src: XBOX_RETAIL_PDB +0xc (old: m_fTimeOfImpactSeparation)
    hkPadSpu<hkBool32> m_useContinuousPhysics; // src: XBOX_RETAIL_PDB +0x10 (old: m_iQualityInfoValue10)
    hkBool m_useSimpleToiHandling; // src: XBOX_RETAIL_PDB +0x14 (old: m_bUseContinuousPhysics)
    hkReal m_minSeparation; // src: XBOX_RETAIL_PDB +0x18 (old: m_fCreateContactThreshold)
    hkReal m_minExtraSeparation; // src: XBOX_RETAIL_PDB +0x1c (old: m_fManifoldTimeDistance)
    hkReal m_minSafeDeltaTime; // src: XBOX_RETAIL_PDB +0x20 (old: m_fMinimumSafeDeltaTime)
    hkReal m_minAbsoluteSafeDeltaTime; // src: XBOX_RETAIL_PDB +0x24 (old: m_fMinimumAbsoluteTimeOfImpact)
    hkReal m_toiSeparation; // src: XBOX_RETAIL_PDB +0x28 (old: m_fMinimumTimeOfImpactDelta)
    hkReal m_toiExtraSeparation; // src: XBOX_RETAIL_PDB +0x2c (old: m_fMaximumTimeOfImpactDelta)
    hkReal m_toiAccuracy; // src: XBOX_RETAIL_PDB +0x30 (old: m_fMaximumConstraintViolation)
    hkReal m_maxContraintViolation; // src: XBOX_RETAIL_PDB +0x34 (old: m_fMaximumLinearVelocity)
    hkReal m_minToiDeltaTime; // src: XBOX_RETAIL_PDB +0x38 (old: m_fMaximumAngularVelocity)
    unsigned short m_constraintPriority; // src: XBOX_RETAIL_PDB +0x3c (old: m_usValueAtOffset3C)
    hkBool m_enableToiWeldRejection; // src: XBOX_RETAIL_PDB +0x3e (old: m_bEnableToiWeldRejection)
};
