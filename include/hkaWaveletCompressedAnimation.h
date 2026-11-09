#pragma once

#include "hkaAnimation.h"
#include "hkaWaveletCompressedAnimationQuantizationFormat.h"

// pdb: class hkaWaveletCompressedAnimation, size 0x70, bases: hkaAnimation, 12 members
class hkaWaveletCompressedAnimation : public hkaAnimation
{
public:
    virtual hkUint32 getBlockKey(int block) const; // RTTI slot 16.
    virtual void vf16();

    hkInt32 m_numberOfPoses;
    hkInt32 m_blockSize;
    hkaWaveletCompressedAnimationQuantizationFormat m_qFormat;
    hkUint32 m_staticMaskIdx;
    hkUint32 m_staticDOFsIdx;
    hkUint32 m_numStaticTransformDOFs;
    hkUint32 m_numDynamicTransformDOFs;
    hkUint32 m_blockIndexIdx;
    hkUint32 m_blockIndexSize;
    hkUint32 m_quantizedDataIdx;
    hkUint32 m_quantizedDataSize;
    hkArray<hkUint8> m_dataBuffer;
};
