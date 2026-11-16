#pragma once

#include "hkaAnimation.h"
#include "hkaWaveletCompressedAnimationQuantizationFormat.h"

// pdb: class hkaWaveletCompressedAnimation, size 0x70, bases: hkaAnimation, 12 members
class hkaWaveletCompressedAnimation : public hkaAnimation
{
public:
    virtual hkUint32 getBlockKey(int block) const; // RTTI slot 16.
    virtual void vf16();

    hkInt32 m_numberOfPoses; // src: XBOX_RETAIL_PDB +0x28 (old: m_iFrameCount)
    hkInt32 m_blockSize; // src: XBOX_RETAIL_PDB +0x2c (old: m_iDofCount)
    hkaWaveletCompressedAnimationQuantizationFormat m_qFormat; // src: XBOX_RETAIL_PDB +0x30 (old: m_eQuantizationFormat)
    hkUint32 m_staticMaskIdx; // src: XBOX_RETAIL_PDB +0x44 (old: m_uiFramesPerBlock)
    hkUint32 m_staticDOFsIdx; // src: XBOX_RETAIL_PDB +0x48 (old: m_uiNumBlocks)
    hkUint32 m_numStaticTransformDOFs; // src: XBOX_RETAIL_PDB +0x4c (old: m_uiOffsetDataOffset)
    hkUint32 m_numDynamicTransformDOFs; // src: XBOX_RETAIL_PDB +0x50 (old: m_uiScaleDataOffset)
    hkUint32 m_blockIndexIdx; // src: XBOX_RETAIL_PDB +0x54 (old: m_uiIndexDataOffset)
    hkUint32 m_blockIndexSize; // src: XBOX_RETAIL_PDB +0x58 (old: m_uiNumIndices)
    hkUint32 m_quantizedDataIdx; // src: XBOX_RETAIL_PDB +0x5c (old: m_uiNumDynamicDofs)
    hkUint32 m_quantizedDataSize; // src: XBOX_RETAIL_PDB +0x60 (old: m_uiNumDynamicTracks)
    hkArray<hkUint8> m_dataBuffer; // src: XBOX_RETAIL_PDB +0x64 (old: m_kCompressedData)
};
