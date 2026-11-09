#pragma once

#include "BaseFormComponent.h"
#include "MagicTarget.h"
#include "FileEntryListCollection.h"

class TESFile;
enum CHUNK_ID;

// pdb: class TESModelList, size 0x14, bases: BaseFormComponent, 2 members
class TESModelList : public BaseFormComponent
{
public:
    TESModelList();
    ~TESModelList();
    TESModelList& operator=(const TESModelList&);

    virtual void Init();
    virtual void Free();
    virtual void CopyFromBase(BaseFormComponent* component);
    virtual bool CompareWithBase(BaseFormComponent* apCompareFC);

    void ClearComponent();
    bool HasModels();
    unsigned int BaseFormRecord(unsigned int type);
    void BaseFormRecord(BaseFormComponent* apCopyFC);
    void CopyModelListToBuffer(void* aeModelListID, unsigned int aeTextureListID);
    void CopyModelListToBuffer(unsigned int aeModelListID, unsigned int aeTextureListID);
    void CopyModelListToBuffer(CHUNK_ID modelChunkID, CHUNK_ID dataChunkID);
    void LoadStringChunk(TESModelList* apModelList, TESFile* file);
    bool ContainsFile(const char* filename);
    void AddModel_00489fa0(const char* apFilename);
    void FUN_00489a60();
    BSSimpleList<const char*>* FUN_00717e50();

    BSSimpleList<const char*> nifFilenames;
    unsigned char TextureListArray[8];
};
