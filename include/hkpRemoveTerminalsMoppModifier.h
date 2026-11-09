#pragma once

#include "hkReferencedObject.h"
#include "hkpMoppModifier.h"
#include "hkArray.h"

typedef unsigned int hkUint32;

class hkpMoppCode;
class hkpShapeContainer;
class hkAabb;

// pdb: class hkpRemoveTerminalsMoppModifier, size 0x1c, bases: hkReferencedObject, hkpMoppModifier, 2 members
class hkpRemoveTerminalsMoppModifier : public hkReferencedObject, public hkpMoppModifier
{
public:
    hkpRemoveTerminalsMoppModifier(const hkpMoppCode* moppCode, const hkpShapeContainer* shapeContainer,
                                  const hkArray<hkUint32>& shapesToRemove) throw();
    hkpRemoveTerminalsMoppModifier(const hkpMoppCode* moppCode, const hkAabb& aabb,
                                  const hkArray<hkUint32>& shapesToRemove) throw();
    virtual ~hkpRemoveTerminalsMoppModifier() throw();

protected:
    hkpRemoveTerminalsMoppModifier() throw();

    virtual hkBool shouldTerminalBeRemoved(hkUint32 id, const hkUint32* properties) throw();
    virtual void addTerminalRemoveInfo(int relativeMoppAddress) throw();

public:
    hkArray<hkUint32> m_removeInfo;           // +0x0c m_removeInfo
    const hkArray<hkUint32>* m_tempShapesToRemove;  // +0x18 m_tempShapesToRemove
};
