#pragma once
#include "hkBool.h"
#include "hkPadSpu.h"

typedef float hkReal;
typedef int hkBool32;

// src: XBOX_PDB; hkpCollisionQualityInfo is 0x40 bytes. Exe continuous GSK reads TOI fields through +0x3e.
// pdb: structure hkpCollisionQualityInfo, size 0x40, 17 members
struct hkpCollisionQualityInfo
{
    __declspec(align(16)) hkReal m_keepContact;
    hkReal m_create4dContact;
    hkReal m_createContact;
    hkReal m_manifoldTimDistance;
    hkPadSpu<hkBool32> m_useContinuousPhysics;
    hkBool m_useSimpleToiHandling;
    hkReal m_minSeparation;
    hkReal m_minExtraSeparation;
    hkReal m_minSafeDeltaTime;
    hkReal m_minAbsoluteSafeDeltaTime;
    hkReal m_toiSeparation;
    hkReal m_toiExtraSeparation;
    hkReal m_toiAccuracy;
    hkReal m_maxContraintViolation;
    hkReal m_minToiDeltaTime;
    unsigned short m_constraintPriority;
    hkBool m_enableToiWeldRejection;
};
