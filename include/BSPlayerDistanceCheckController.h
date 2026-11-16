#pragma once

#include "NiTimeController.h"

// pdb: class BSPlayerDistanceCheckController, size 0x3c, bases: NiTimeController, 2 members
class BSPlayerDistanceCheckController : public NiTimeController
{
public:
    virtual ~BSPlayerDistanceCheckController();
    virtual const NiRTTI* GetRTTI() const;
    virtual NiObject* MakeClone(CloningProcess& arCloning);
    virtual void Update(NiUpdateData& update);
    virtual void Unk_2C();

    void* __thiscall ScalarDeletingDestructor(unsigned int flags);
    const NiRTTI* const* GetNiRTTI();
    double NiControllerSequence_GetLastTime();
    int GetField38();
    void UpdateDoorSpawn(unsigned int UpdateData);
    void TargetIsRequiredType();

    unsigned int fCheckDistance; // src: XBOX_RETAIL_PDB +0x34 (old: unk34)
    void (__cdecl* pfnCallback)(void*); // src: XBOX_RETAIL_PDB +0x38 (old: m_callback)
};
