#pragma once

#include "BaseFormComponent.h"
#include "TESForm.h"

class TESSound;

// pdb: class BGSPickupPutdownSounds, size 0xc, bases: BaseFormComponent, 2 members
class BGSPickupPutdownSounds : public BaseFormComponent
{
public:
    TESSound* m_pPickupSound;
    TESSound* m_pPutdownSound;

    BGSPickupPutdownSounds();
    ~BGSPickupPutdownSounds();

    void InitItem(TESForm* apOwner);
    void SetPickupSound(TESSound* sound);
    void SetPutdownSound(TESSound* sound);
    void Save();
};
