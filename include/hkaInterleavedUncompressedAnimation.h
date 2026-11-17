#pragma once

#include "hkaAnimation.h"
#include "hkQsTransform.h"

// pdb: class hkaInterleavedUncompressedAnimation, size 0x40, bases: hkaAnimation, 2 members
class hkaInterleavedUncompressedAnimation : public hkaAnimation
{
public:
    hkArray<hkQsTransform> m_transforms; // src: XBOX_RETAIL_PDB +0x28 (old: m_kTransforms)
    hkArray<hkReal> m_floats; // src: XBOX_RETAIL_PDB +0x34 (old: m_kFloats)
};
