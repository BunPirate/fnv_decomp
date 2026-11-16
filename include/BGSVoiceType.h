#pragma once

#include "TESForm.h"

class TESFile;

// pdb: class BGSVoiceType, size 0x24, bases: TESForm, 2 members
class BGSVoiceType : public TESForm
{
public:
    struct VoiceTypeString
    {
        char* unk00;
        unsigned short unk04;
        unsigned short unk06;

        ~VoiceTypeString();
    };

    BGSVoiceType();
    virtual ~BGSVoiceType();

    virtual void ClearData();
    virtual bool LoadForm2(TESFile* modInfo);
    virtual void SaveForm();
    virtual void CopyFrom(const TESForm* form);
    virtual bool Compare(TESForm* apCompare);

    bool Load(TESFile* apFile);
    void Save_005f0140();
    void Copy_005f02a0(TESForm* apCopy);
    bool Compare_005f02f0(TESForm* apCompare);
    void TESForm_CopyAllComponents(TESForm* form);
    bool TESForm_CompareAllComponents(TESForm* apCompare);

    union
    {
        unsigned char formData[0xc];
        struct
        {
            char Data;
            unsigned char unk19[3];
            VoiceTypeString unk1c;
        };
    };
};
