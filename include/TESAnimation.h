#pragma once

#include "BaseFormComponent.h"
#include "MagicTarget.h"

class TESFile;
class TESForm;
enum CHUNK_ID;

// pdb: class TESAnimation, size 0xc, bases: BaseFormComponent, 1 members
class TESAnimation : public BaseFormComponent
{
public:
    TESAnimation();
    ~TESAnimation();
    TESAnimation& operator=(const TESAnimation&);

    virtual void Init();
    virtual void Free();
    virtual void CopyFromBase(BaseFormComponent* component);
    virtual bool CompareWithBase(BaseFormComponent* apCompareFC);

    void InitializeComponent();
    void ClearComponent();
    void BaseFormRecord(BaseFormComponent* component);
    bool IsEqualToBase(BaseFormComponent* component);
    bool IsKFFileInList(char* path);
    bool IsKFFileInList(const char* apFilename);
    void AddKFFile(char* path);
    void AddKFFile(const char* path);
    bool HasKFFiles();
    void* GetKFFileList();
    void Save(int chunkID);
    void Save(CHUNK_ID chunkID);
    void LoadAnimationChunk(TESAnimation* animation, TESFile* file);
    void BaseFormRecord(TESAnimation* animation, TESFile* file);
    void LoadComponent(TESForm* form, TESFile* file);
    void AddPathToList(const char* path);

    BSSimpleList<const char*> kfFilenames;
};
