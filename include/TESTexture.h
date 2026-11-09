#pragma once

#include "BaseFormComponent.h"
#include "TESFullName.h"

class TESForm;
class TESObjectREFR;
class TESFile;
class BSS;
class String;

// pdb: class TESTexture, size 0xc, bases: BaseFormComponent, 1 members
class TESTexture : public BaseFormComponent
{
public:
    TESTexture();
    ~TESTexture();

    virtual void Init();
    virtual void Free();
    virtual void CopyFromBase(BaseFormComponent* component);
    virtual bool CompareWithBase(BaseFormComponent* component);
    virtual unsigned int GetTexturePathLength();
    virtual char* NormalizeTextureFilePath(void* result);
    virtual char* GetTextureResourcePath();

    void InitializeComponent();
    void ClearComponent();
    void BaseFormRecord(BaseFormComponent* component);
    bool IsEqualToBase(BaseFormComponent* component);
    bool TESTexture_CompareComponent(TESTexture* component);
    void Save(int chunk);

    static unsigned int GetTextureNameLength(TESForm* form);
    unsigned int GetTextureNameLength();
    static char* GetTextureResourceName(TESForm* apObj, TESObjectREFR* apRef);
    char* GetTextureResourceName();
    void AssignTextureName(char* apFullName);
    void AssignTextureName(const char* apFullName);
    void SetTexture(const char* apFullName);

    static void NormalizeTextureFilePath(char* path, char* output);
    static char* NormalizeTextureFilePath(void* result, char* path);
    static const char* GetAsNormalFile(BSStringT<char>& aOutFilename, const char* apTextureName);
    static const char* NormalizeTextureFilePath(BSS& result, const char* path);
    template <class StringType>
    static const char* NormalizeTextureFilePath(StringType& result, const char* path);
    static char* NormalFileToRegularFile(void* result, char* path);
    char* GetRegularTextureFilePath(void* result);
    static void GetRegularTextureFilePath(char* path, char* output);
    static char* GetRegularTextureFilePath(void* result, char* path);
    static void GetAsSkinFile(char* apTextureName, char* apSkinTextureName);
    static void GetAsSkinFile(const char* apTextureName, char* apSkinTextureName);
    static bool IsTextureChunk(int chunk);
    static void ReadTextureData(TESTexture* apTexture, TESFile* apFile);
    static char* GetMessageIconName(TESForm* form, TESObjectREFR* reference);

    unsigned long Unk_04();
    void GetNormalMap(String* result);
    char* GetPathRoot();

    BSStringT<char> FullNameComponent;
};
