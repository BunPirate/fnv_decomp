// fallout_shared/niformarray.cpp: NiFormArray (3 functions)

#include "../../include/NiFormArray.h"

// The canonical _memmove binding names a different runtime entry point.
void* __cdecl FUN_00ec7230(void* destination, const void* source, unsigned int size);

// @fnv 0x0061bc10
// pdb: TopicInfoArray::InsertInfoAt | TESTopic.obj | retail, call graph (shared callers), high
// pdb params: aiIndex, apInfo
// pdb locals: newsize
void NiFormArray::SetFormAtIndex(unsigned int aiIndex, TESForm* apInfo)
{
    Compact();
    if (aiIndex > m_uiSize)
        SetAt(aiIndex, apInfo);
    else
    {
        unsigned int newSize = m_uiSize + 1;
        if (m_uiMaxSize < newSize)
            NiTLargePrimitiveArray<TESForm*>::SetSize(newSize + m_uiGrowBy);
        FUN_00ec7230(m_pBase + aiIndex + 1, m_pBase + aiIndex, (m_uiSize - aiIndex) * sizeof(TESForm*));
        ++m_uiSize;
        m_uiESize = m_uiSize;
        m_pBase[aiIndex] = apInfo;
    }
}

// @fnv 0x004d6100
// pdb: NiFormArray::GetIndexForForm | NiFormArray.obj | debug, call graph (shared callers), high
// pdb params: apForm
// pdb locals: iretval, icount, i
unsigned int NiFormArray::GetIndexOfForm(TESForm* apForm)
{
    unsigned int foundIndex = 0xffffffff;
    if (apForm)
    {
        unsigned int size = GetSize();
        if (size)
        {
            for (unsigned int index = 0; index < size; ++index)
            {
                if (FUN_00877a30(index) == apForm)
                {
                    foundIndex = index;
                    break;
                }
            }
        }
    }
    return foundIndex;
}

// Returns the form at aiIndex if it is within GetSize(), otherwise returns null.
// @fnv 0x004d6170
// pdb: NiFormArray::GetFormAt | NiFormArray.obj | debug, upstream name already matches, high
// pdb params: aiIndex
// pdb locals: pretform
TESForm* NiFormArray::GetFormAt(unsigned int aiIndex)
{
    TESForm* pretform = 0;
    if (aiIndex < GetSize())
    {
        pretform = FUN_00877a30(aiIndex);
    }
    return pretform;
}
