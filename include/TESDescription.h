#pragma once

#include "BaseFormComponent.h"

class TESForm;
class TESFile;
enum CHUNK_ID;

// pdb: class TESDescription, size 0x8, bases: BaseFormComponent, 1 members
class TESDescription : public BaseFormComponent
{
public:
    TESDescription();

    virtual void Init();
    virtual void Free();
    virtual void CopyFromBase(BaseFormComponent* component);
    virtual bool CompareWithBase(BaseFormComponent* component);
    virtual const char* GetDescription(TESForm* apForm, CHUNK_ID aeChunk);

    void InitializeComponent();
    void ClearComponent();
    void BaseFormRecord(BaseFormComponent* apCopyFC);
    bool IsEqualToBase(BaseFormComponent* apCompareFC);
    void Save();
    void Save_00482cb0();
    static void LoadDescriptionAtOffset(TESDescription* description, int offset);
    static void ReadDescriptionFromFile(TESDescription* apDesc, TESFile* apFile);
    static unsigned int GetDescriptionLength(TESForm* form);
    unsigned int GetDescriptionLength();
    static char* GetDescription(TESForm* form);
    char* GetDescription(TESForm* form, int chunkID);
    const char* GetDescription(TESForm* form, unsigned int chunkID);
    unsigned long GetDescriptionFileOffset();
    void SetDescriptionFileOffset(unsigned long offset);
    void LoadDescriptionForForm(TESForm* form, int chunkID);
    void LoadDescriptionForForm(TESForm* form, CHUNK_ID aeChunk);
    void UnLoadDescription();
    void SetDescription(char* description);

    unsigned long m_uiDescriptionFileOffset;
};
