#pragma once

#include "hkpBvTreeShape.h"
#include "hkVector4_X.h"

class hkpMoppCode;

// pdb: class hkMoppBvTreeShapeBase, size 0x30, bases: hkpBvTreeShape, 4 members
class hkMoppBvTreeShapeBase : public hkpBvTreeShape
{
public:
    static const ClassMemberDescriptor Members[];

    virtual ~hkMoppBvTreeShapeBase() throw();

    int queryAabbImpl(const hkAabb& aabbIn, unsigned int* hits, int maxNumKeys) const;

    const hkpMoppCode* m_code; // src: XBOX_RETAIL_PDB +0x14 (old: m_pMoppCode)
    unsigned char* m_moppData; // src: XBOX_RETAIL_PDB +0x18 (old: m_pMoppData)
    int m_moppDataSize; // src: XBOX_RETAIL_PDB +0x1c (old: m_uiMoppDataSize)
    hkVector4_X m_codeInfoCopy; // src: XBOX_RETAIL_PDB +0x20 (old: m_kMoppCodeInfo)
};
