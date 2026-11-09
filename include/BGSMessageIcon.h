#pragma once

#include "BaseFormComponent.h"
#include "TESIcon.h"

class TESFile;

// pdb: class BGSMessageIcon, size 0x10, bases: BaseFormComponent, 1 members
class BGSMessageIcon : public BaseFormComponent
{
public:
    BGSMessageIcon();
    ~BGSMessageIcon();

    void InitializeComponent();
    void ClearComponent();
    void BaseFormRecord(BaseFormComponent* apCopyFC);
    bool IsEqualToBase(BaseFormComponent* apCompareFC);

    void Save(int aeTextureID);
    static void LoadMessageIcon(BGSMessageIcon* apIcon, TESFile* apFile);
    static void LoadMessageIconChunk(BGSMessageIcon* apIcon, TESFile* apFile);
    TESIcon* GetIcon();
    char* GetMessageIconTextureName();
    unsigned int GetMessageIconTextureNameLength();
    void SetMessageIconTextureName(char* apTexture);
    void SetMessageIconTextureName(const char* name);

    TESIcon Icon;
};
