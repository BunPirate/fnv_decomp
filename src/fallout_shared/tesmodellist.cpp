// fallout_shared/tesmodellist.cpp: TESModelList, ActorValue, FileEntryListCollection

#include "layout_support.h"
#include "../../include/TESModelList.h"
#include <new>
#include "../../include/ActorValueOwner.h"
#include "../../include/PathingRequest.h"
#include "../../include/SettingT_GameSettingCollection_.h"
#include "../../include/TESActorBaseData.h"

#include "../../include/ActorValue.h"
namespace ActorValue {
bool __cdecl GetFlag(Index index, unsigned int flag);
}


class TESModelListCopyTarget
{
  public:
    virtual void vfn_00() = 0;
    virtual void vfn_04() = 0;
    virtual void vfn_08() = 0;
    virtual void vfn_0c() = 0;
    virtual unsigned short vfn_10() = 0;
};


// Deletes every filename string in the list at offset 4, then calls ClearAndDeleteArray on the object at offset 12.
// @fnv 0x00489b40
// pdb: TESModelList::ClearDataComponent | TESModelList.obj | retail, vtable slot, high
// pdb locals: pnifFilename
void TESModelList::ClearComponent()
{
    while (!nifFilenames.IsEmpty())
    {
        const char* filenameToDelete;
        const char* filename;
        filenameToDelete = nifFilenames.GetItem();
        nifFilenames.RemoveHead();
        filename = filenameToDelete;
        ::operator delete((void*)filename);
    }
    reinterpret_cast<FileEntryListCollection*>(TextureListArray)->ClearAndDeleteArray();
}

// @fnv 0x00489ae0
// pdb: TESModelList::~TESModelList | TESModelList.obj | retail, upstream name already matches, high
TESModelList::~TESModelList()
{
    ClearComponent();
}

// @fnv 0x005fa180
// pdb: TESCreature::GetActorValue | TESCreature.obj | retail, vtable slot, high
// pdb params: aiWhich
// pdb locals: iresult
unsigned int TESModelList::BaseFormRecord(unsigned int type)
{
    unsigned int result = 0;
    if (ActorValue::GetFlag((ActorValue::Index)type, 0x400))
    {
        result = ((TESModelList*)((char*)this - 0x100))->HasModels();
    }
    else
    {
        switch (type)
        {
        case 0x38:
            result = ((TESModelListCopyTarget*)((char*)this + 0x0c))->vfn_10();
            break;
        default:
            result = ((ActorValueOwner*)this)->ActorValueOwner::GetActorValue((ActorValue::Index)type);
            break;
        }
    }
    return result;
}

struct FUN_00478690_shell
{
    void BGSDestructibleObjectForm_RemoveData();
};


// Releases the object stored at offset 4 by calling its virtual method with 1, then sets that pointer to null.
// @fnv 0x00478690
// src: XBOX_PDB 0x00478690
// pdb: BGSDestructibleObjectForm::ClearDataComponent | BGSDestructibleObjectForm.obj | retail, vtable slot, high
void FUN_00478690_shell::BGSDestructibleObjectForm_RemoveData()
{
    delete *(FileEntryListCollection**)((char*)this + 4);
    *(void**)((char*)this + 4) = 0;
}

class GameSettingCollection;
template <class T> class SettingT;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting43;

// Returns the byte at pThis+0x12d, adding the scaled level from the actor base data when it matches the PC level.
// @fnv 0x005f8f70
// src: COMMUNITY 0x005f8f70
// pdb: TESCreature::GetCombatSkill | TESCreature.obj | retail, upstream name already matches, high
// pdb locals: cretval, slevel
unsigned char __fastcall TESCreature_GetCombatSkill(char* pThis)
{
    unsigned char ucLevel = static_cast<unsigned char>(pThis[0x12d]);
    if (reinterpret_cast<TESActorBaseData*>(pThis + 0x30)->GetMatchesPCLevel())
    {
        short slevel = reinterpret_cast<TESActorBaseData*>(pThis + 0x30)->TESActorBaseData_GetLevel();
        if (slevel < 1)
            slevel = 1;
        ucLevel =
            ucLevel +
            static_cast<unsigned char>(
                slevel * reinterpret_cast<SettingT_GameSettingCollection_&>(originalRuntimeFloatSetting43).Float()->f);
    }
    return ucLevel;
}

struct FUN_005fa180_cls : public ActorValueOwner
{
    char pad[0xc - 4];
    int TESCreature_GetActorValueI(ActorValue::Index aiWhich);
};
// @fnv 0x005fa180
// src: COMMUNITY 0x005fa180
// pdb: TESCreature::GetActorValue | TESCreature.obj | retail, vtable slot, high
// pdb params: aiWhich
// pdb locals: iresult
int FUN_005fa180_cls::TESCreature_GetActorValueI(ActorValue::Index aiWhich)
{
    int result = 0;
    if (ActorValue::GetFlag(aiWhich, 0x400))
    {
        result = ((TESModelList*)((char*)this - 0x100))->HasModels();
    }
    else
    {
        switch (aiWhich)
        {
        case 0x38:
            result = ((TESModelListCopyTarget*)((char*)this + 0xc))->vfn_10();
            break;
        default:
            result = ActorValueOwner::GetActorValue(aiWhich);
            break;
        }
    }
    return result;
}

// Initializes the model list and its collection storage, then clears the component.
// @fnv 0x00489a60
// pdb: TESModelList::AddNIFFile | TESModelList.obj | retail, object-file run extension, low
// pdb note: debug build links it to TESModelList::TESModelList
// pdb params: apFilename
// pdb locals: iFilenameLen, pnifFilename
TESModelList::TESModelList()
{
    // The raw storage is initialized as a list without adding a member destructor.
    reinterpret_cast<BSSimpleList<const char*>*>(TextureListArray)->BSSimpleList<const char*>::BSSimpleList();
    Free();
}

unsigned int __cdecl BSStringLength(const char*);
// @fnv 0x00489ce0
// pdb: TESModelList::LoadModelListChunk | TESModelList.obj | retail, object-file run extension, high
// pdb params: apModelList, apFile
// pdb locals: chunk, pcurrentFile, pmessage
void TESModelList::LoadStringChunk(TESModelList* apModelList, TESFile* apFile)
{
    if (!apFile || !apModelList)
        return;
    unsigned int id = apFile->GetChunkID();
    switch (id)
    {
    case 0x5a46494e: {
        char* pChunkBuffer = new char[apFile->GetChunkSize()];
        {
            char* pString = pChunkBuffer;
            apFile->GetChunkData(pChunkBuffer, 0);
            while (*pString)
            {
                AddModel_00489fa0(pString);
                pString += BSStringLength(pString) + 1;
            }
        }
        delete pChunkBuffer;
        break;
    }
    case 0x5446494e:
        reinterpret_cast<FileEntryListCollection*>(TextureListArray)->LoadFromTESFile(apModelList, apFile);
        break;
    }
}

// Deletes each element of the array at this+4, frees the array, nulls the pointer, and resets the count at this+0 to zero.
// @fnv 0x0048a010
// pdb: TESTextureListArray::ClearData | TESModelList.obj | retail, call graph (shared callers), high
// pdb locals: i
void FileEntryListCollection::ClearAndDeleteArray()
{
    unsigned int i;
    if (pTextureLists)
    {
        for (i = 0; i < iTextureListCount; i++)
            delete pTextureLists[i];
        delete pTextureLists;
        pTextureLists = 0;
    }
    iTextureListCount = 0;
}

struct FUN_0048a2c0_shell
{
    void TESTextureListArray_Copy(PathingLocation*);
};
// Casts component to TESModelList, copies each filename via FUN_00489fa0, then copies the origin pathing location.
// @fnv 0x00489db0
// pdb: TESModelList::CopyComponent | TESModelList.obj | retail, vtable slot, high
// pdb params: apCopyFC
// pdb locals: pcopy, pnifFileList, pnifFilename
void TESModelList::BaseFormRecord(BaseFormComponent* apCopyFC)
{
    TESModelList* source = dynamic_cast<TESModelList*>(apCopyFC);
    if (!source)
        return;
    Free();
    BSSimpleList<char const*>* list = &source->nifFilenames;
    while (list)
    {
        const char* filename = list->GetItem();
        if (filename)
            AddModel_00489fa0(filename);
        list = list->GetNext();
    }
    ((FUN_0048a2c0_shell*)((char*)this + 0xc))->TESTextureListArray_Copy(((PathingRequest*)source)->GetOrigin());
}

// pdb: class TaskQueueInterface, size 0x10 (here 0x1), 4 members
struct TaskQueueInterface
{
    static void CopyStringToBuffer(char* dest, unsigned int size, const char* src);
};
struct SoundListView
{
    void AddTail(char* const&);
};
// If the string is not already present, allocates a copy of it, copies the text into it, and appends it to the list at this+4.
// @fnv 0x00489fa0
// src: COMMUNITY 0x00489fa0
// pdb: TESModelList::AddNIFFile | TESModelList.obj | debug, call graph, high
// pdb params: apFilename
// pdb locals: iFilenameLen, pnifFilename
void TESModelList::AddModel_00489fa0(const char* apFilename)
{
    if (!ContainsFile(apFilename))
    {
        int size = BSStringLength(apFilename) + 1;
        char* copy = static_cast<char*>(operator new(size));
        char* dest = copy;
        TaskQueueInterface::CopyStringToBuffer(dest, size, apFilename);
        ((SoundListView*)((char*)this + 4))->AddTail(dest);
    }
}

struct FNV_NodeIter
{
    int* GetItem();
    FNV_NodeIter* GetNext();
};

extern char DAT_01183040;
extern char DAT_01186b14;

void* __cdecl FUN_00ec43fb(unsigned int a, unsigned int b, void* c, void* d, unsigned int e);
int __cdecl BSstricmp(int a, int b);

// Looks up a record via FUN_00ec43fb and walks both node lists, returning true if any pair of entries differs or the lists have different lengths.
// @fnv 0x00489e40
// pdb: TESModelList::CompareComponent | TESModelList.obj | retail, vtable slot, high
// pdb params: apCompareFC
// pdb locals: pnifFileListCompare, pnifFileList, pcompare, pnifFilename, pnifFilenameCompare
bool TESModelList::CompareWithBase(BaseFormComponent* apCompareFC)
{
    char* p = (char*)FUN_00ec43fb(reinterpret_cast<unsigned int>(apCompareFC), 0, &DAT_01183040, &DAT_01186b14, 0);
    if (p == 0)
    {
        return true;
    }
    FNV_NodeIter* a = (FNV_NodeIter*)((char*)this + 4);
    FNV_NodeIter* b = (FNV_NodeIter*)(p + 4);
    int y4;
    int x3;
    while (a != 0 && b != 0)
    {
        x3 = *a->GetItem();
        y4 = *b->GetItem();
        if ((x3 == 0 && y4 != 0) || (x3 != 0 && y4 == 0))
        {
            return true;
        }
        else
        {
            if (x3 != 0 && y4 != 0 && BSstricmp(x3, y4) != 0)
            {
                return true;
            }
        }
        a = a->GetNext();
        b = b->GetNext();
    }
    if (a != 0 || b != 0)
    {
        return true;
    }
    return false;
}

int __cdecl BSstricmp(const char* lhs, const char* rhs);

// Returns true if filename is non-null and matches an entry in the model list, otherwise false.
// @fnv 0x00489f20
// pdb: TESModelList::IsNIFFileInList | TESModelList.obj | debug, object-file gap fill, medium
// pdb params: apFilename
// pdb locals: pnifFileList, pnifFilename
bool TESModelList::ContainsFile(const char* filename)
{
    if (nifFilenames.IsEmpty() || filename == 0)
        return false;

    BSSimpleList<const char*>* entry = &nifFilenames;
    while (entry != 0)
    {
        const char* value = entry->GetItem();
        if (value && BSstricmp(value, filename) == 0)
            return true;
        entry = entry->GetNext();
    }

    return false;
}

unsigned int __cdecl BSstrlen(const char* text);
void __cdecl FUN_00406d30(char* destination, unsigned int capacity, const char* source);
void __cdecl TESForm_AddChunkArray(void* aeChunkID, char* apData, unsigned int aiSize);

// If the model list is non-empty, concatenates its strings into a new buffer, copies it to destination, frees it, then clears the list data.
// @fnv 0x00489ba0
// pdb: TESModelList::Save | TESModelList.obj | retail, call graph, high
// pdb params: aeModelListID, aeTextureListID
// pdb locals: pcurrentFile, pnifFileList, pnifFilenames, ilocalsize, idataSize, pnifFilename, isize
void TESModelList::CopyModelListToBuffer(void* aeModelListID, unsigned int aeTextureListID)
{
    if (!nifFilenames.IsEmpty())
    {
        unsigned int iStack_8 = 1;
        BSSimpleList<const char*>* iStack7 = &nifFilenames;
        const char* piVar4;
        char* allocResult;
        char* puVar4;
        char* puStack_18;
        unsigned int iStack_c;
        const char* iVarTmp;
        unsigned int count9;
        char* freeBuffer_;

        while (iStack7 != 0)
        {
            piVar4 = iStack7->GetItem();
            if (piVar4 != 0)
                iStack_8 = iStack_8 + BSstrlen(piVar4) + 1;
            iStack7 = iStack7->GetNext();
        }

        allocResult = (char*)::operator new(iStack_8);
        puVar4 = allocResult;
        puStack_18 = puVar4;
        iStack7 = &nifFilenames;
        iStack_c = iStack_8;
        while (iStack7 != 0)
        {
            iVarTmp = iStack7->GetItem();
            if (iVarTmp != 0)
            {
                FUN_00406d30(puStack_18, iStack_c, iVarTmp);
                count9 = BSstrlen(iVarTmp) + 1;
                puStack_18 = puStack_18 + count9;
                iStack_c = iStack_c - count9;
            }
            iStack7 = iStack7->GetNext();
        }
        *puStack_18 = 0;
        TESForm_AddChunkArray(aeModelListID, puVar4, iStack_8);
        freeBuffer_ = puVar4;
        ::operator delete(freeBuffer_);
    }
    reinterpret_cast<FileEntryListCollection*>(TextureListArray)->ClearData(aeTextureListID);
}
