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

    const hkpMoppCode* m_code;
    unsigned char* m_moppData;
    int m_moppDataSize;
    hkVector4_X m_codeInfoCopy;
};
