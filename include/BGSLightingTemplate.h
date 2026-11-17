#pragma once

#include "TESForm.h"
#include "InteriorData.h"

// pdb: class BGSLightingTemplate, size 0x44, bases: TESForm, 1 members
class BGSLightingTemplate : public TESForm
{
public:
    InteriorData Data;

    BGSLightingTemplate();
    virtual ~BGSLightingTemplate();

    void ResetFormData();
    bool Load(TESFile* apFile);
    void ReadTypedData(TESFile* apFile, void* apData, unsigned short asSize);
};
