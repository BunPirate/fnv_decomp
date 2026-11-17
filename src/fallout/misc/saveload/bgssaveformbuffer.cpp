#include "../../../../include/Actor.h"
#include "../../../../include/BGSSaveFormBuffer.h"
#include "../../../../include/TESForm.h"
#include "../../../../include/TESObjectREFR.h"

// src/fallout/misc/saveload/bgssaveformbuffer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/misc/saveload/bgssaveformbuffer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FormLoadContext
{
    char bytes[12];
    FormLoadContext();
};

struct FUN_00865aa0_shell
{
    unsigned char c;
    void __thiscall SetFlags(unsigned int a);
};

// Stores the low 2 bits of a into the upper 2 bits of c, preserving c's lower 6 bits.
// @fnv 0x00865aa0
void __thiscall FUN_00865aa0_shell::SetFlags(unsigned int a)
{
    c = (c & 0x3f) | (a << 6);
}

unsigned int __cdecl GetSizeTypeForSize(unsigned int);
unsigned int __cdecl GetSizeTypeSize(unsigned int);
// Calls FUN_0084e3a0, passes the result through FUN_00845d40 and FUN_00845d70, then returns that value plus 9.
// @fnv 0x00865b10
// pdb: BGSSaveFormBuffer::GetOverhead | BGSSaveFormBuffer.obj | debug, object-file gap fill, medium
// pdb locals: isizeTypeSize
unsigned int __thiscall BGSSaveFormBuffer::GetSize()
{
    unsigned int value = GetSizeTypeSize(GetSizeTypeForSize(GetHavokWorldObjectCountInSceneGraph_0084e3a0()));
    return value + 9;
}

// Returns the buffer's form cast to TESObjectREFR if it is a reference, otherwise returns null.
// @fnv 0x00865b40
// pdb: BGSSaveFormBuffer::GetReference | BGSSaveFormBuffer.obj | retail, vtable slot, high
// pdb locals: pform
TESObjectREFR* BGSSaveFormBuffer::GetFormAsReference()
{
    TESForm* pform = GetForm();
    if (pform)
    {
        if (pform->GetIsReference())
        {
            return (TESObjectREFR*)pform;
        }
    }
    return 0;
}

// Returns the buffer's reference cast to Actor if it is an actor, otherwise returns null.
// @fnv 0x00865b80
// pdb: BGSSaveFormBuffer::GetActor | BGSSaveFormBuffer.obj | retail, vtable slot, high
// pdb locals: pref
Actor* BGSSaveFormBuffer::GetActorReference()
{
    TESObjectREFR* pref = GetReference();
    if (pref && pref->IsActor())
        return (Actor*)pref;
    return 0;
}

struct PackedFormID
{
    void __thiscall BGSNumericIDIndex_SetNumericID(unsigned int aiNumericID);
};
struct BGSFormInfo
{
    void __thiscall BGSSaveLoadFormInfo_SetFormType(unsigned int aeFormType);
};
// Stores the form ID, change flags, form type and version into this save-form buffer's fields.
// @fnv 0x00865ad0
// pdb: BGSSaveFormBuffer::SetHeader | BGSSaveFormBuffer.obj | debug, call graph (shared callers), medium
// pdb params: aiFormID, aiChangeFlags, aeFormType, acVersion
void BGSSaveFormBuffer::InitFormEntry(unsigned int aiFormID, unsigned int aiChangeFlags, unsigned int aeFormType,
                                      unsigned char acVersion)
{
    reinterpret_cast<PackedFormID*>(Header.formID)->BGSNumericIDIndex_SetNumericID(aiFormID);
    Header.changeFlags = aiChangeFlags;
    reinterpret_cast<BGSFormInfo*>(&Header.formInfo)->BGSSaveLoadFormInfo_SetFormType(aeFormType);
    Header.version = acVersion;
}

// @fnv 0x008659c0
// pdb: BGSSaveFormBuffer::BGSSaveFormBuffer | BGSSaveFormBuffer.obj | retail, upstream name already matches, high
BGSSaveFormBuffer::BGSSaveFormBuffer() : BGSSaveGameBuffer()
{
    // The shared POD header still needs the original FormLoadContext constructor.
    reinterpret_cast<FormLoadContext*>(&Header)->FormLoadContext::FormLoadContext();
    pForm = 0;
}

class SaveLoadFile
{
public:
    void __thiscall BGSSaveLoadFile_Write(void* data, int size);
};

void __cdecl WriteValueByType(void*, unsigned int, unsigned int);
// @fnv 0x00865a30
// pdb: BGSSaveFormBuffer::Save | BGSSaveFormBuffer.obj | retail, upstream name already matches, high
// pdb params: apFile
// pdb locals: esizeType, isize
void BGSSaveFormBuffer::Save(SaveLoadFile* apFile)
{
    unsigned int secondValue = GetHavokWorldObjectCountInSceneGraph_0084e3a0();
    unsigned int firstValue = GetSizeTypeForSize(secondValue);
    reinterpret_cast<FUN_00865aa0_shell*>(&Header.formInfo)->SetFlags(firstValue);
    apFile->BGSSaveLoadFile_Write(&Header, 9);
    WriteValueByType(apFile, secondValue, firstValue);
    BGSSaveGameBuffer::Save(apFile, secondValue);
}
