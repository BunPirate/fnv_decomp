#pragma once

class BGSPerkEntry;
class TESObjectREFR;
class TESSound;

// pdb: class BGSLoadedReferenceCollection, size 0xc0 (here 0xa9), 8 members
class BGSLoadedReferenceCollection
{
public:
    class ReferenceBucket
    {
    public:
        bool RemoveSound(TESSound* apRef);
    };

    unsigned char pad0[0x18];
    ReferenceBucket member18;
    unsigned char pad1[0x47];
    ReferenceBucket member60;
    unsigned char pad2[0x17];
    ReferenceBucket member78;
    unsigned char pad3[0x17];
    ReferenceBucket member90;
    unsigned char pad4[0x17];
    ReferenceBucket memberA8;

    void RemoveReference(TESObjectREFR* apRef);
    char* GetFieldByType(unsigned int type);
    void AddReference(BGSPerkEntry* apRef);
};
