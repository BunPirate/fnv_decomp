#pragma once

#include "hkaAnimation.h"
#include "hkaDeltaCompressedAnimationQuantizationFormat.h"

// pdb: class hkaDeltaCompressedAnimation, size 0x78, bases: hkaAnimation, 14 members
class hkaDeltaCompressedAnimation : public hkaAnimation
{
public:
    virtual hkUint32 getBlockKey(int block) const; // RTTI slot 16.
    virtual void vf16();

    hkInt32 m_numberOfPoses; // src: XBOX_RETAIL_PDB +0x28 (old: m_iFrameCount)
    hkInt32 m_iDofCount;
    hkaDeltaCompressedAnimationQuantizationFormat m_qFormat; // src: XBOX_RETAIL_PDB +0x30 (old: m_eQuantizationFormat)
    hkUint32 m_quantizedDataIdx; // src: XBOX_RETAIL_PDB +0x44 (old: m_uiNumDynamicDofs)
    hkUint32 m_quantizedDataSize; // src: XBOX_RETAIL_PDB +0x48 (old: m_uiNumDynamicTracks)
    hkUint32 m_staticMaskIdx; // src: XBOX_RETAIL_PDB +0x4c (old: m_uiFramesPerBlock)
    hkUint32 m_staticMaskSize; // src: XBOX_RETAIL_PDB +0x50 (old: m_uiBlockByteSize)
    hkUint32 m_staticDOFsIdx; // src: XBOX_RETAIL_PDB +0x54 (old: m_uiNumBlocks)
    hkUint32 m_staticDOFsSize; // src: XBOX_RETAIL_PDB +0x58 (old: m_uiBlockOffsetsOffset)
    hkUint32 m_numStaticTransformDOFs; // src: XBOX_RETAIL_PDB +0x5c (old: m_uiOffsetDataOffset)
    hkUint32 m_numDynamicTransformDOFs; // src: XBOX_RETAIL_PDB +0x60 (old: m_uiScaleDataOffset)
    hkUint32 m_totalBlockSize; // src: XBOX_RETAIL_PDB +0x64 (old: m_uiCompressedBlockSize)
    hkUint32 m_lastBlockSize; // src: XBOX_RETAIL_PDB +0x68 (old: m_iLastBlockSize)
    hkArray<hkUint8> m_dataBuffer; // src: XBOX_RETAIL_PDB +0x6c (old: m_kCompressedData)
};
