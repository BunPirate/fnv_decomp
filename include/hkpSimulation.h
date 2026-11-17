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

    hkUint32 m_determinismCheckFrameCounter; // src: XBOX_RETAIL_PDB +0x8 (old: m_eLastProcessingStep)
    hkpWorld* m_world; // src: XBOX_RETAIL_PDB +0xc (old: m_pOwningWorld)
    hkUint8 m_lastProcessingStep; // src: XBOX_RETAIL_PDB +0x10 (old: m_bHasStepped)
    char pad11[3];
    hkReal m_currentTime; // src: XBOX_RETAIL_PDB +0x14 (old: m_fElapsedSimulationTime)
    hkReal m_currentPsiTime; // src: XBOX_RETAIL_PDB +0x18 (old: m_fSimulationTime)
    hkReal m_physicsDeltaTime; // src: XBOX_RETAIL_PDB +0x1c (old: m_fStepDeltaTime)
    hkReal m_simulateUntilTime; // src: XBOX_RETAIL_PDB +0x20 (old: m_fFrameMarkerTime)
    hkReal m_frameMarkerPsiSnap; // src: XBOX_RETAIL_PDB +0x24 (old: m_fFrameMarkerPsiSnap)
    hkUint32 m_previousStepResult; // src: XBOX_RETAIL_PDB +0x28 (old: m_uiSimulationType)
};
