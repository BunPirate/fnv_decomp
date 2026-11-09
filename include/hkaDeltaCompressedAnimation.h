#pragma once

#include "hkaAnimation.h"
#include "hkaDeltaCompressedAnimationQuantizationFormat.h"

// pdb: class hkaDeltaCompressedAnimation, size 0x78, bases: hkaAnimation, 14 members
class hkaDeltaCompressedAnimation : public hkaAnimation
{
public:
    virtual hkUint32 getBlockKey(int block) const; // RTTI slot 16.
    virtual void vf16();

    hkInt32 m_numberOfPoses;
    hkInt32 m_iDofCount;
    hkaDeltaCompressedAnimationQuantizationFormat m_qFormat;
    hkUint32 m_quantizedDataIdx;
    hkUint32 m_quantizedDataSize;
    hkUint32 m_staticMaskIdx;
    hkUint32 m_staticMaskSize;
    hkUint32 m_staticDOFsIdx;
    hkUint32 m_staticDOFsSize;
    hkUint32 m_numStaticTransformDOFs;
    hkUint32 m_numDynamicTransformDOFs;
    hkUint32 m_totalBlockSize;
    hkUint32 m_lastBlockSize;
    hkArray<hkUint8> m_dataBuffer;
};
