#pragma once

#include "bhkNiCollisionObject.h"
#include "NiRTTI.h"

class NiAVObject;
struct hkpRigidBody;
class bhkWorldObject;
class bhkWorldObjectV;

// pdb: class bhkCollisionObject, size 0x14 (here 0xc), bases: bhkNiCollisionObject, 0 members
class bhkCollisionObject : public bhkNiCollisionObject
{
  public:
    virtual ~bhkCollisionObject();
    virtual const NiRTTI* GetRTTI() const;

    static const NiRTTI ms_kRTTI;

    static bhkCollisionObject* GetFromNiAVObject(NiAVObject* object);
    static bhkCollisionObject* GetFromRigidBody(const hkpRigidBody* apBody);
    static NiObject* CreateObject();

    bhkWorldObjectV* GetWorldObject();
    bhkWorldObject* bhkNiCollisionObject_GetWorldObject();
    void bhkNiCollisionObject_SetReset(bool);
};
