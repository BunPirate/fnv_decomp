#pragma once

#include "hkReferencedObject.h"
#include "hkpLinkedCollidable.h"
#include "hkMultiThreadCheck.h"
#include "hkStringPtr.h"

class hkpProperty;
class hkpWorld;
struct hkFinishLoadedObjectFlagCD2C;

typedef unsigned long hkUlong;

// pdb: class hkpWorldObject, size 0x8c, bases: hkReferencedObject, 8 members
class hkpWorldObject : public hkReferencedObject
{
public:
    enum MtChecks
    {
        MULTI_THREADING_CHECKS_ENABLE = 0,
        MULTI_THREADING_CHECKS_IGNORE = 1
    };

    enum BroadPhaseType
    {
        BROAD_PHASE_INVALID = 0,
        BROAD_PHASE_ENTITY = 1,
        BROAD_PHASE_PHANTOM = 2,
        BROAD_PHASE_BORDER = 3,
        BROAD_PHASE_MAX_ID = 4
    };

    hkpWorldObject(const void* shape, int type);
    hkpWorldObject(hkFinishLoadedObjectFlagCD2C flag);
    virtual ~hkpWorldObject() throw();
    virtual void vf03();
    virtual void vf04();

    hkpWorld* getWorld() const;

    void* m_world;
    hkUlong m_userData;
    hkpLinkedCollidable m_kCollidable;
    hkMultiThreadCheck m_multiThreadCheck;
    hkStringPtr m_name;
    hkArray<hkpProperty> m_properties;
    void* m_aiData;
    void* m_treeData;
};
