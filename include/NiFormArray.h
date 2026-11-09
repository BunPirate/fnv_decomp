#pragma once

#include "NiTLargePrimitiveArray.h"

class TESForm;

// pdb: class NiFormArray, size 0x18, bases: NiTLargePrimitiveArray<TESForm *>, 0 members
class NiFormArray : public NiTLargePrimitiveArray<TESForm *>
{
public:
    NiFormArray();
    virtual ~NiFormArray();

    unsigned int GetIndexOfForm(TESForm* apForm);
    unsigned int GetSize();
    TESForm*& FUN_00877a30(unsigned int index);
    void SetSize(unsigned int size, unsigned int* oldSize);
    void Compact();
    void SetFormAtIndex(unsigned int aiIndex, TESForm* apInfo);
    TESForm* GetFormAt(unsigned int index);
};
