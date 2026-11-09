#pragma once

#include "hkaAnimation.h"
#include "hkQsTransform.h"

// pdb: class hkaInterleavedUncompressedAnimation, size 0x40, bases: hkaAnimation, 2 members
class hkaInterleavedUncompressedAnimation : public hkaAnimation
{
public:
    hkArray<hkQsTransform> m_transforms;
    hkArray<hkReal> m_floats;
};
