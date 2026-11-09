#pragma once

#include "hkReferencedObject.h"

class hkpWorld;

typedef unsigned int hkUint32;
typedef unsigned char hkUint8;
typedef float hkReal;
typedef hkReal hkTime;

// pdb: class hkpSimulation, size 0x2c, bases: hkReferencedObject, 9 members
class hkpSimulation : public hkReferencedObject
{
public:
    enum FindContacts
    {
        FIND_CONTACTS_DEFAULT = 0,
        FIND_CONTACTS_EXTRA = 1
    };

    enum ResetCollisionInformation
    {
        RESET_TOI = 1,
        RESET_TIM = 2,
        RESET_AABB = 4,
        RESET_ALL = 7
    };

    enum LastProcessingStep
    {
        INTEGRATE = 0,
        COLLIDE = 1
    };

    virtual void WarpTime(hkReal deltaTime);
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void shiftTime(float shift);

    static const ClassMemberDescriptor Members[];

    void checkDeltaTimeIsOk(hkReal deltaTime);
    void setCurrentTime(hkTime time) { m_currentTime = time; }

    hkUint32 m_determinismCheckFrameCounter;
    hkpWorld* m_world;
    hkUint8 m_lastProcessingStep;
    char pad11[3];
    hkReal m_currentTime;
    hkReal m_currentPsiTime;
    hkReal m_physicsDeltaTime;
    hkReal m_simulateUntilTime;
    hkReal m_frameMarkerPsiSnap;
    hkUint32 m_previousStepResult;
};
