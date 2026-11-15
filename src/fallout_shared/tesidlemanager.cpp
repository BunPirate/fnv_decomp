// fallout_shared/tesidlemanager.cpp: IdleAnimationManager, IdleAnimationDirectoryEntry, IdleCleanup (22 functions)

#include "../../include/NiFormArray.h"
#include "../../include/NiTMap.h"
#include "../../include/NiTPointerMap.h"
#include "../../include/TESAnimGroup.h"
#include "../../include/TESForm.h"
#include "../../include/TESIdleForm.h"
#include "../../include/TESModel.h"
#include "../../include/TESObjectREFR.h"

#include "tesidlemanager_decls.h"

// @fnv 0x006008f0
TESObject* TESIdleManager::GetCurrentUsedItem()
{
    return fnv_tesidlemanager_used_item;
}

// @fnv 0x00600930
bool TESIdleManager::GetUsedItemActivate()
{
    return fnv_tesidlemanager_used_item_activate;
}

// @fnv 0x00600690
// pdb: TESIdleManager::GetLooseIdleArray | TESIdleManager.obj | retail, object-file run extension, high
// pdb params: apIdleDir
// pdb locals: pretarray, proot
NiFormArray* TESIdleManager::GetIdleArray(TESForm* apForm)
{
    NiFormArray* result = 0;
    char buffer[264];

    if (apForm)
    {
        GetIdleDirName(TESModel::GetModelFilePath((TESObject*)apForm), buffer);
        result = TESIdleManager_GetLooseIdleArray(buffer);
    }
    return result;
}

// @fnv 0x006007f0
// src: XBOX_RETAIL_PDB 0x006007f0
// pdb: TESIdleManager::GetIdleDirName | TESIdleManager.obj | retail, call graph, high
// pdb params: apInDir, apOutDir
// pdb locals: ptempstring, pfind
void TESIdleManager::GetIdleDirName(const char* apInDir, char* apOutDir)
{
    char buffer[260];
    char* match;

    apOutDir[0] = 0;
    if (apInDir && apInDir[0])
    {
        TaskQueueInterface::CopyStringToBuffer(buffer, sizeof(buffer), apInDir);
        match = FUN_004812f0(buffer, fnv_tesidlemanager_idle_anims);
        if (match)
        {
            match += BSStringLength<char>(fnv_tesidlemanager_idle_anims);
            *match = 0;
            TaskQueueInterface::CopyStringToBuffer(apOutDir, sizeof(buffer), buffer);
        }
        else
        {
            match = strrchr_0040ab30(buffer, '\\');
            if (match)
            {
                ++match;
                *match = 0;
                TaskQueueInterface::CopyStringToBuffer(apOutDir, sizeof(buffer), buffer);
                strcat_s(apOutDir, sizeof(buffer), fnv_tesidlemanager_idle_anims);
            }
        }
    }
}

// Builds a path from directory and the idle anims folder, looks it up in the map, and returns the weapon's list from the found entry.
// @fnv 0x00600700
// pdb: TESIdleManager::GetRootFilenameList | TESIdleManager.obj | retail, call graph (shared callers), high
// pdb params: apIdleDir, aeWeaponGroup
// pdb locals: pret, plastSlash, searchPath, proot
BSSimpleList<const char*>* TESIdleManager::FindIdleArrayEntry(const char* apIdleDir,
                                                                    ANIM_GROUP_WEAPON_ENUM aeWeaponGroup)
{
    BSSimpleList<const char*>* result = 0;
    if (apIdleDir && apIdleDir[0])
    {
        IdleAnimationDirectoryEntry* pIdleEntry = 0;
        {
            char buffer[128];
            {
                TaskQueueInterface::CopyStringToBuffer(buffer, 128, apIdleDir);
                char* match = strrchr_0040ab30(buffer, '\\');
                TaskQueueInterface::CopyStringToBuffer(match + 1, 128 - (match - buffer) - 1,
                                                       fnv_tesidlemanager_idle_anims);
                if (GetAt(buffer, pIdleEntry) && pIdleEntry)
                    result = pIdleEntry->m_ppFileListsByWeapon[aeWeaponGroup];
            }
        }
    }
    return result;
}

// @fnv 0x005ffc20
// pdb: TESIdleManager::InitLoadedIdles | TESIdleManager.obj | debug, object-file gap fill, medium
// pdb locals: isize, iter, i, pidle, proot, pignore, icount, tempstring
void TESIdleManager::InitializeIdleAnimations()
{
    unsigned int count = LoadedIdleArray.GetSize();
    for (unsigned int i = 0; i < count; ++i)
    {
        TESIdleForm* idle = (TESIdleForm*)LoadedIdleArray.GetAt(i);
        if (idle && !idle->GetInitialized())
            idle->InitItem();
        else
            LoadedIdleArray.SetAt(i, const_cast<BGSCameraPath*&>(static_cast<BGSCameraPath* const&>((BGSCameraPath*)0)));
    }
    for (unsigned int uiIndex2 = 0; uiIndex2 < count; ++uiIndex2)
    {
        TESIdleForm* idle = (TESIdleForm*)LoadedIdleArray.GetAt(uiIndex2);
        if (idle && idle->InitParents())
            LoadedIdleArray.SetAt(uiIndex2,
                            const_cast<BGSCameraPath*&>(static_cast<BGSCameraPath* const&>((BGSCameraPath*)0)));
    }
    LoadedIdleArray.Compact();
    bInitialized = true;
}

// @fnv 0x00600950
// pdb: TESIdleManager::GetIdleToPlay | TESIdleManager.obj | retail, call graph (shared callers), medium
// pdb params: apActionRef, apTargetRef
// pdb locals: pretidle, pactionAnim, idledir, parray, icount, i, pidle
TESIdleForm* TESIdleManager::FindIdleFormForObject(TESObjectREFR* action, TESObjectREFR* target)
{
    TESIdleForm* result = 0;
    NiFormArray* idles;
    if (action)
    {
        char buffer[264];
        {
            GetIdleDirName(action->GetModelFilePath(), buffer);
            AnimData* anim = action->GetAnimData();
            idles = TESIdleManager_GetRootIdleArray(buffer);
            if (idles)
            {
                unsigned int count = idles->GetSize();
                for (unsigned int i = 0; i < count; ++i)
                {
                    TESIdleForm* idle = (TESIdleForm*)idles->GetFormAt(i);
                    if (idle)
                        result = idle->FindIdleFormForObject(action, target, anim ? &anim->replayDelays : 0);
                    if (result)
                        break;
                }
            }
        }
    }
    if (result && result->TESIdleForm_GetAllowNoFile() && !result->CheckIdleFile())
        result = 0;
    return result;
}

// @fnv 0x005ff950
// src: XBOX_RETAIL_PDB 0x005ff950
// pdb: IDLE_ANIM_ROOT::AddRootFilenameList | TESIdleManager.obj | retail, string-set bridge, high
// pdb params: apList
// pdb locals: eanimWeapon, bpowerArmor, eanimMove, pfilename, plastSlash
void IdleAnimationDirectoryEntry::IDLE_ANIM_ROOT_AddRootFilenameList(BSSimpleList<const char*>* apList)
{
    if (!apList)
        return;
    while (!apList->IsEmpty())
    {
        const char* filename = apList->GetItem();
        {
            ANIM_GROUP_MOVE_ENUM move;
            bool flag;
            {
                ANIM_GROUP_WEAPON_ENUM weapon;
                TESAnimGroup::ParseAnimationGroupFilename(filename, move, weapon, flag);
                if (weapon == ANIM_GROUP_WEAPON_ENUM_AGW_ONE_HAND_PISTOL)
                {
                    const char* basename = CRT::strrchr(filename, '\\');
                    if (basename)
                    {
                        ++basename;
                        if (!CRT::_stricmp(basename, fnv_idle_1hp_left) ||
                            !CRT::_stricmp(basename, fnv_idle_1hp_fast_left) ||
                            !CRT::_stricmp(basename, fnv_idle_1hm_left) ||
                            !CRT::_stricmp(basename, fnv_idle_1hm_fast_left))
                            weapon = ANIM_GROUP_WEAPON_ENUM_AGW_NONE;
                    }
                }
                if (!m_ppFileListsByWeapon[weapon])
                    m_ppFileListsByWeapon[weapon] = new BSSimpleList<const char*>;
                m_ppFileListsByWeapon[weapon]->AddHead(filename);
                apList->RemoveHead();
            }
        }
    }
    delete apList;
}

// @fnv 0x00600170
// src: XBOX_RETAIL_PDB 0x00600170
// pdb: TESIdleManager::AddRootIdleArray | TESIdleManager.obj | retail, call graph (shared callers), high
// pdb params: apIdleDir, apList, abForceList
// pdb locals: pretarray, proot, plastSlash, searchPath
IdleAnimationDirectoryEntry* TESIdleManager::AddRootIdleArray(const char* apIdleDir,
                                                                 BSSimpleList<const char*>* apList, bool abForceList)
{
    IdleAnimationDirectoryEntry* result = 0;
    {
        IdleAnimationDirectoryEntry* fallback;
        {
            IdleAnimationDirectoryEntry* supplied;
            if ((!DAT_011cb71c || abForceList) && apIdleDir && apIdleDir[0])
            {
                result = (IdleAnimationDirectoryEntry*)TESIdleManager_GetRootIdleArray(apIdleDir);
                if (!result)
                {
                    if (apList)
                    {
                        char buffer[128];
                        {
                            TaskQueueInterface::CopyStringToBuffer(buffer, 128, apIdleDir);
                            char* slash = strrchr_0040ab30(buffer, '\\');
                            TaskQueueInterface::CopyStringToBuffer(slash + 1, 128 - (slash - buffer) - 1,
                                                                   fnv_tesidlemanager_idle_anims);
                            supplied = new IdleAnimationDirectoryEntry(apIdleDir);
                            supplied->IDLE_ANIM_ROOT_AddRootFilenameList(g_modelLoader->FindNIFFileListEntry(apList, 0));
                            InsertOrUpdate(buffer, supplied);
                            result = supplied;
                            return result;
                        }
                    }
                    fallback = new IdleAnimationDirectoryEntry(apIdleDir);
                    DAT_011cb71c = true;
                    fallback->IDLE_ANIM_ROOT_AddRootFilenameList(
                        g_modelLoader->GetModelFileList(apIdleDir, true, false, ANIM_GROUP_WEAPON_ENUM_AGW_NONE));
                    DAT_011cb71c = false;
                    InsertOrUpdate(apIdleDir, fallback);
                    result = fallback;
                }
            }
        }
    }
    return result;
}

bool __fastcall _ref_008256d0(BSSimpleList<const char*>*);
const char** __fastcall _ref_006815c0(BSSimpleList<const char*>*);
void __fastcall _ref_0063f7b0(BSSimpleList<const char*>*);

// @fnv 0x006003c0
// src: XBOX_RETAIL_PDB 0x006003c0 (was COMMUNITY)
// pdb: TESIdleManager::RebuildRootFilenameLists | TESIdleManager.obj | retail, call graph, high
// pdb locals: iter, pidledir, proot, n, pfilename
void __fastcall TESIdleManager_RebuildRootFilenameLists(void* thisPtr)
{
    void* pIter = ((NiTPointerMap<unsigned int, void*>*)thisPtr)->GetFirstPos();
    while (pIter)
    {
        IdleAnimationDirectoryEntry* root = 0;
        const char* path = 0;
        ((NiTPointerMap<unsigned int, void*>*)thisPtr)->GetNext(pIter, *(unsigned int*)&path, *(void**)&root);
        if (root)
        {
            for (unsigned int i = 0; i < 12; i++)
            {
                if (root->m_ppFileListsByWeapon[i])
                {
                    while (!_ref_008256d0(root->m_ppFileListsByWeapon[i]))
                    {
                        const char* pString = *_ref_006815c0(root->m_ppFileListsByWeapon[i]);
                        delete pString;
                        _ref_0063f7b0(root->m_ppFileListsByWeapon[i]);
                    }
                    delete root->m_ppFileListsByWeapon[i];
                    root->m_ppFileListsByWeapon[i] = 0;
                }
            }
            root->IDLE_ANIM_ROOT_AddRootFilenameList(g_modelLoader->GetModelFileList(path, true, false, 0));
        }
    }
}

struct FUN_006004f0_shell : public TESIdleManager
{
    NiFormArray* TESIdleManager_AddRootIdleArray(TESForm*);
};

// @fnv 0x006004f0
// src: XBOX_RETAIL_PDB 0x006004f0
// pdb: TESIdleManager::AddRootIdleArray | TESIdleManager.obj | retail, call graph, high
// pdb params: apIdleDir, apList, abForceList
// pdb locals: pretarray, proot, plastSlash, searchPath
NiFormArray* FUN_006004f0_shell::TESIdleManager_AddRootIdleArray(TESForm* apForm)
{
    IdleAnimationDirectoryEntry* pretarray = 0;
    if (apForm)
    {
        char idledir[260];
        GetIdleDirName(TESModel::GetModelFilePath((TESObject*)apForm), idledir);
        pretarray = AddRootIdleArray(idledir, 0, false);
    }
    return (NiFormArray*)pretarray;
}

namespace fnv_00600560 {
struct FUN_00600560_shell : public TESIdleManager
{
    NiFormArray* TESIdleManager_GetRootIdleArray(TESForm*);
};

// Looks up apIdleDir in the map and returns the stored NiFormArray pointer, or null if the key is missing or empty.
// @fnv 0x00600560
// src: XBOX_RETAIL_PDB 0x00600560
// pdb: TESIdleManager::GetRootIdleArray | TESIdleManager.obj | retail, object-file run extension, high
// pdb params: apIdleDir
// pdb locals: pretarray, proot
NiFormArray* FUN_00600560_shell::TESIdleManager_GetRootIdleArray(TESForm* apIdleDir)
{
    NiFormArray* pretarray = 0;
    if (apIdleDir && *(const char*)apIdleDir)
    {
        unsigned int proot = 0;
        if (((NiTPointerMap<unsigned int, unsigned int>*)this)->GetAt((unsigned int)apIdleDir, proot) && proot)
        {
            pretarray = (NiFormArray*)proot;
        }
    }
    return pretarray;
}
}  // namespace fnv_00600560

namespace fnv_00600630 {
struct FUN_00600630_shell : public TESIdleManager
{
    NiFormArray* TESIdleManager_GetLooseIdleArray(TESForm*);
};

// Looks up apIdleDir in the map and returns the NiFormArray at offset 0x18 of the found entry, or null if the key is empty or missing.
// @fnv 0x00600630
// src: XBOX_RETAIL_PDB 0x00600630
// pdb: TESIdleManager::GetLooseIdleArray | TESIdleManager.obj | retail, object-file run extension, high
// pdb params: apIdleDir
// pdb locals: pretarray, proot
NiFormArray* FUN_00600630_shell::TESIdleManager_GetLooseIdleArray(TESForm* apIdleDir)
{
    NiFormArray* pretarray = 0;
    if (apIdleDir && *(const char*)apIdleDir != '\0')
    {
        unsigned int proot = 0;
        if (((NiTPointerMap<unsigned int, unsigned int>*)this)->GetAt((unsigned int)apIdleDir, proot) && proot)
        {
            pretarray = (NiFormArray*)(proot + 0x18);
        }
    }
    return pretarray;
}
}  // namespace fnv_00600630

extern int _fnv_tesidlemanager_used_item;

// @fnv 0x00600900
// src: XBOX_PDB 0x00600900
void TESIdleManager_SetUsedItem(int param)
{
    _fnv_tesidlemanager_used_item = param;
}

extern int DAT_01199c8c;

// @fnv 0x00600910
// src: XBOX_PDB 0x00600910
int __cdecl TESIdleManager_GetUsedItemLevel()
{
    return DAT_01199c8c;
}

extern int DAT_01199c8c;

// @fnv 0x00600920
// src: XBOX_PDB 0x00600920
void TESIdleManager_SetUsedItemLevel(int value)
{
    DAT_01199c8c = value;
}

extern unsigned char _fnv_tesidlemanager_used_item_activate;

// @fnv 0x00600940
// src: XBOX_PDB 0x00600940
void TESIdleManager_SetUsedItemActivate(unsigned char value)
{
    _fnv_tesidlemanager_used_item_activate = value;
}

void _Deallocate(void*);
struct S005fff90
{
    void FUN_005fffc0();
    void* FUN_005fff90(unsigned int);
};
// @fnv 0x005fff90
// pdb: IDLE_ANIM_ROOT::`scalar deleting destructor' | TESIdleManager.obj | debug, object-file gap fill, medium
void* S005fff90::FUN_005fff90(unsigned int flags)
{
    FUN_005fffc0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FUN_006005c0_shell : public TESIdleManager
{
    NiFormArray* _TESIdleManager_GetIdleAnimRoot(const char* apForm);
};

// @fnv 0x006005c0
// src: COMMUNITY 0x006005c0
// pdb: TESIdleManager::GetRootIdleArray | TESIdleManager.obj | retail, object-file run extension, high
// pdb params: apIdleDir
// pdb locals: pretarray, proot
NiFormArray* FUN_006005c0_shell::_TESIdleManager_GetIdleAnimRoot(const char* apForm)
{
    NiFormArray* result = 0;
    if (apForm)
    {
        char directory[260];
        TESIdleManager::GetIdleDirName(TESModel::GetModelFilePath((TESObject*)apForm), directory);
        result = TESIdleManager_GetRootIdleArray(directory);
    }
    return result;
}

struct S_005fffc0_C
{
    int unk00;
    int unk04;
    ~S_005fffc0_C();
};

struct FUN_005fffc0
{
    NiFormArray unk00;
    NiFormArray unk18;
    S_005fffc0_C unk30;
    ~FUN_005fffc0();
};

// Destroys the directory entry's form arrays and list data.
// @fnv 0x005fffc0
// pdb: IDLE_ANIM_ROOT::~IDLE_ANIM_ROOT | TESIdleManager.obj | debug, object-file gap fill, medium
FUN_005fffc0::~FUN_005fffc0()
{}

struct FilenameList
{
    bool Empty();
    const char*& Front();
    void Pop();
    ~FilenameList();
};
struct RootData
{
    NiFormArray first;
    NiFormArray second;
    int unk30;
    int unk34;
    FilenameList* files[12];
    ~RootData();
};
struct IdleBaseArray
{
    unsigned int Count();
    TESForm*& At(unsigned int);
    void Clear();
};
struct IdleCleanup
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    IdleBaseArray forms;
    void DeleteAllOwnedForms();
};
// Iterates the container, deleting each root's forms, file lists and filenames, then deletes all forms in forms and clears both containers.
// @fnv 0x005ffd20
// pdb: TESIdleManager::DestroyRootIdleArrays | TESIdleManager.obj | debug, object-file gap fill, medium
// pdb locals: isize, iter, proot, pignore, icount, i, pidle, n, pfilename
void IdleCleanup::DeleteAllOwnedForms()
{
    void* position = ((NiTPointerMap<unsigned int, RootData*>*)this)->GetFirstPos();
    while (position)
    {
        RootData* root = 0;
        unsigned int key = 0;
        ((NiTPointerMap<unsigned int, RootData*>*)this)->GetNext(position, key, root);
        if (root)
        {
            unsigned int count = root->first.GetSize();
            for (unsigned int firstIndex = 0; firstIndex < count; firstIndex++)
            {
                TESForm* form = root->first.GetFormAt(firstIndex);
                delete form;
            }
            count = root->second.GetSize();
            for (unsigned int secondIndex = 0; secondIndex < count; secondIndex++)
            {
                TESForm* pSecondForm = root->second.GetFormAt(secondIndex);
                delete pSecondForm;
            }
            for (unsigned int listIndex = 0; listIndex < 12; listIndex++)
            {
                if (root->files[listIndex])
                {
                    while (!root->files[listIndex]->Empty())
                    {
                        const char* filename = root->files[listIndex]->Front();
                        delete filename;
                        root->files[listIndex]->Pop();
                    }
                    delete root->files[listIndex];
                }
            }
            delete root;
        }
    }
    unsigned int formCount = forms.Count();
    for (unsigned int formIndex = 0; formIndex < formCount; formIndex++)
    {
        TESForm* pThirdForm = forms.At(formIndex);
        delete pThirdForm;
    }
    forms.Clear();
    ((NiTPointerMap<unsigned int, RootData*>*)this)->RemoveAll();
}

void __fastcall ClearIdleFormArray(NiFormArray* array);

// @fnv 0x00600030
// src: GUESS 0x00600030 (confidence: low)
// pdb: TESIdleManager::DestroyRootIdleArrayForms | TESIdleManager.obj | debug, object-file gap fill, medium
// pdb locals: iter, proot, pignore, icount, i, pidle
void TESIdleManager::ReleaseStorage_00600030()
{
    void* a = ((NiTPointerMap<void*, NiFormArray*>*)this)->GetFirstPos();
    while (a != 0)
    {
        NiFormArray* c = 0;
        void* b = 0;
        ((NiTPointerMap<void*, NiFormArray*>*)this)->GetNext(a, b, c);
        if (c != 0)
        {
            unsigned int nG = c->GetSize();
            unsigned int i;
            TESForm* TD;
            TESForm* DQ;
            unsigned int jF;
            for (i = 0; i < nG; i++)
            {
                TD = c->GetFormAt(i);
                delete TD;
            }
            ClearIdleFormArray(c);
            nG = reinterpret_cast<NiFormArray*>(reinterpret_cast<unsigned char*>(c) + 0x18)->GetSize();
            for (jF = 0; jF < nG; jF++)
            {
                DQ = reinterpret_cast<NiFormArray*>(reinterpret_cast<unsigned char*>(c) + 0x18)->GetFormAt(jF);
                delete DQ;
            }
            ClearIdleFormArray(reinterpret_cast<NiFormArray*>(reinterpret_cast<unsigned char*>(c) + 0x18));
        }
    }
}
