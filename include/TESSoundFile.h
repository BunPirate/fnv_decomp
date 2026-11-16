#pragma once

#include "BaseFormComponent.h"
#include "TESFullName.h"

class TESForm;

// pdb: class TESSoundFile, size 0xc, bases: BaseFormComponent, 1 members
class TESSoundFile : public BaseFormComponent
{
public:
    TESSoundFile();
    ~TESSoundFile();

    virtual void Init();
    virtual void Free();
    virtual void CopyFromBase(BaseFormComponent* component);
    virtual bool CompareWithBase(BaseFormComponent* component);
    virtual void SetSoundFile(const char* name);

    void InitializeComponent();
    void ClearComponent();
    void BaseFormRecord(BaseFormComponent* component);
    bool IsEqualToBase(BaseFormComponent* component);
    void Save();
    void SetSoundFile(char* name);
    void SetName(const char* name);
    static unsigned int GetSoundFileLength(TESForm* form);
    unsigned int GetSoundFileLength();
    unsigned int GetSoundFileLength() const;
    static char* GetSoundFile(TESForm* form);
    char* GetSoundFile();
    const char* GetSoundFile() const;

    BSStringT<char> cSoundFile; // src: XBOX_RETAIL_PDB +0x4 (old: m_kSoundFile)
};
