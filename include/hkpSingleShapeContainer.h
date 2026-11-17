#pragma once

#include "hkpShapeContainer.h"

// pdb: class hkpSingleShapeContainer, size 0x8, bases: hkpShapeContainer, 1 members
class hkpSingleShapeContainer : public hkpShapeContainer
{
public:
    static const ClassMemberDescriptor Members[];

    hkpSingleShapeContainer(hkpShape* child, int ref);

    virtual ~hkpSingleShapeContainer();
    virtual hkpShapeKey GetFirstKey() const;
    virtual hkpShapeKey GetNextShapeKey(hkpShapeKey oldKey) const;
    virtual const hkpShape* GetShapeForKey(hkpShapeKey key, hkpShapeBuffer& buffer) const;

    inline const hkpShape* getChild() const
    {
        return m_childShape;
    }

    const hkpShape* m_childShape; // src: XBOX_RETAIL_PDB +0x4 (old: m_pContainedShape)
};
