#pragma once

#include "hkpShape.h"
#include "hkpShapeContainer.h"
#include "hkBool.h"

// pdb: class hkpShapeCollection, size 0x18, bases: hkpShape, hkpShapeContainer, 2 members
class hkpShapeCollection : public hkpShape, public hkpShapeContainer
{
public:
    enum CollectionType
    {
        COLLECTION_LIST = 0,
        COLLECTION_EXTENDED_MESH = 1,
        COLLECTION_TRISAMPLED_HEIGHTFIELD = 2,
        COLLECTION_USER = 3,
        COLLECTION_SIMPLE_MESH = 4,
        COLLECTION_MESH_SHAPE = 5,
        COLLECTION_COMPRESSED_MESH = 6,
        COLLECTION_MAX = 7
    };

    hkpShapeCollection();
    hkpShapeCollection(hkpShapeType type, CollectionType collectionType);
    hkpShapeCollection(unsigned int type, unsigned char collectionType) throw();
    hkpShapeCollection(FinishingFlag flag);

    static const ClassMemberDescriptor Members[];

    virtual void vf11(int);
    virtual void vf12(int, int);

    hkBool m_disableWelding; // src: XBOX_RETAIL_PDB +0x14 (old: m_bDisableWelding)
    unsigned char m_collectionType; // src: XBOX_RETAIL_PDB +0x15 (old: m_eCollectionType)
    unsigned char unk16[2];
};
