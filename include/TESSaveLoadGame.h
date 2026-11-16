#pragma once

// TESSaveLoadGame: the save/load singleton, no vtable. 0x1c8 bytes: TES init (0x0044ffc8) does `new` with 0x1c8 and
// stores the result in g_TESSaveLoadGame (0x011de45c); the constructor 0x00856380 / destructor 0x00856870 give the
// members below (pointer maps it allocates, the five BSSimpleLists it constructs, the 0x10-byte memset at +0x98, the
// pointer at +0x1c4 it frees). Accessors confirm: +0x14 buffer (AdvanceBuffer 0x00857bd0, DestroyBuffer 0x00858700),
// +0x20 (GetInitArrayExists 0x008727b0), +0x48 (GetRevertBefore 0x0055f5b0), +0x5c/+0x60/+0x64 (Queue*Load),
// +0x74/+0x75/+0x80 (ResetVersions 0x008620f0, ResetCurrentVersion 0x00856850), +0x8c (GetNextSaveNumber 0x00862370),
// +0x1c4 (GetMostRecentSaveGame 0x005a9460).

#ifndef FNV64_BSSIMPLELIST_DEFINED
#include "BSSimpleList.h"
#endif

struct _FILETIME;
class Actor;
class BSFile;
class ChangeData;
class ChangesMap;
class ExteriorCellNewReferencesMap;
class InteriorCellNewReferencesMap;
class NiPoint3;
class NiTexture;
class NumericIDBufferMap;
class TESForm;
class TESObjectCELL;
class TESObjectREFR;
class TESPackage;
class TESWorldSpace;
template <class T> class NiTLargePrimitiveArray;

// pdb: class TESSaveLoadGame, size 0x1c8, 44 members
class TESSaveLoadGame
{
public:
    ChangesMap* m_pChanges;                                         // 0x000 new ChangesMap (0x00854ea0) // src: XBOX_RETAIL_PDB +0x0 (old: m_pChangesMap)
    ChangesMap* m_pNewChanges;                                // 0x004 // src: XBOX_RETAIL_PDB +0x4 (old: m_pAlternateChangesMap)
    InteriorCellNewReferencesMap* m_pInteriorCellMap;     // 0x008 // src: XBOX_RETAIL_PDB +0x8 (old: m_pInteriorCellNewReferencesMap)
    ExteriorCellNewReferencesMap* m_pExteriorCellMap;    // 0x00c // src: XBOX_RETAIL_PDB +0xc (old: m_pExteriorCellNewReferencesMap1)
    ExteriorCellNewReferencesMap* m_pCreatedExteriorCells;    // 0x010 // src: XBOX_RETAIL_PDB +0x10 (old: m_pExteriorCellNewReferencesMap2)
    char* m_pBuffer;                                                   // 0x014
    unsigned int m_iSaveLoadStates;                                       // 0x018 // src: XBOX_RETAIL_PDB +0x18 (old: m_uiBufferSize)
    bool m_bAllowChanges;                                                   // 0x01c // src: XBOX_RETAIL_PDB +0x1c (old: m_bLoading)
    void* m_pInitArray;                                            // 0x020 // src: XBOX_RETAIL_PDB +0x20 (old: m_pInitFormArray)
    BSSimpleList<unsigned int> m_MovedReferencesList;              // 0x024 CreateChangedReference removes its form id // src: XBOX_RETAIL_PDB +0x24 (old: m_kChangedReferenceIDList)
    BSSimpleList<TESForm*> m_CreatedBaseObjectsList;                   // 0x02c AddCreatedBaseObject // src: XBOX_RETAIL_PDB +0x2c (old: m_kCreatedBaseObjectList)
    BSSimpleList<TESForm*> m_DeferredDeleteList;                    // 0x034 AddFormToDeferredDeletionsList // src: XBOX_RETAIL_PDB +0x34 (old: m_kDeferredDeletionList)
    BSSimpleList<void*> m_DeferredInitActorPackageList;                                     // 0x03c element type unknown (ctor/dtor only) // src: XBOX_RETAIL_PDB +0x3c (old: m_kList3C)
    void* m_pSaveLoadStats;                                            // 0x044 // src: XBOX_RETAIL_PDB +0x44 (old: m_pSaveGameEntry)
    int m_iRevertState;                                                // 0x048
    unsigned char m_iSavedPluginCount;                                     // 0x04c // src: XBOX_RETAIL_PDB +0x4c (old: m_ucSaveVersion)
    unsigned char* m_pFileIndexArray;                                 // 0x050 freed by the destructor // src: XBOX_RETAIL_PDB +0x50 (old: m_pNumericIDBuffer)
    unsigned int m_iQueuedRemoveChanges;                               // 0x054 QueueRemoveChange 0x0060e680 // src: XBOX_RETAIL_PDB +0x54 (old: m_uiQueuedRemoveChange)
    NumericIDBufferMap* m_pAnimationMap;                         // 0x058 // src: XBOX_RETAIL_PDB +0x58 (old: m_pAnimationBufferMap)
    NumericIDBufferMap* m_pAttachedAnimationMap;                 // 0x05c QueueAttachedAnimationLoad // src: XBOX_RETAIL_PDB +0x5c (old: m_pAttachedAnimationBufferMap)
    NumericIDBufferMap* m_pCharControllerMap;                    // 0x060 QueueCharControllerLoad // src: XBOX_RETAIL_PDB +0x60 (old: m_pCharControllerBufferMap)
    NumericIDBufferMap* m_pHavokDataMap;                         // 0x064 QueueHavokDataLoad // src: XBOX_RETAIL_PDB +0x64 (old: m_pHavokDataBufferMap)
    BSSimpleList<TESForm*> m_QueuedFormList;                     // 0x068 QueueFormForFinalization // src: XBOX_RETAIL_PDB +0x68 (old: m_kQueuedFinalizeForms)
    void* m_pSaveGameList;                                             // 0x070
    unsigned char m_cMajorVersion;                                  // 0x074 ResetVersions: 0 // src: XBOX_RETAIL_PDB +0x74 (old: m_ucMinimumVersion)
    unsigned char m_cMinorVersion;                                         // 0x075 ResetVersions: 0x7d // src: XBOX_RETAIL_PDB +0x75 (old: m_ucVersion)
    NiTLargePrimitiveArray<unsigned int>* m_pNumericIDArray;              // 0x078 new (100, 50) // src: XBOX_RETAIL_PDB +0x78 (old: m_pFormIDArray)
    NiTLargePrimitiveArray<unsigned int>* m_pWorldSpaceIDArray;        // 0x07c new (5, 1)
    unsigned char m_cCurrentVersion;                                  // 0x080 ResetCurrentVersion copies +0x75 // src: XBOX_RETAIL_PDB +0x80 (old: m_ucCurrentVersion)
    bool m_bUseNumericIDArray;                                         // 0x081 ctor: 1 // src: XBOX_RETAIL_PDB +0x81 (old: m_bUseSaveGameBlocks)
    unsigned int m_pCurrentlyLoadingFormHeader;                                          // 0x084 // src: XBOX_RETAIL_PDB +0x84 (old: m_uiValue84)
    unsigned int m_pCurrentlySavingFormHeader;                                          // 0x088 // src: XBOX_RETAIL_PDB +0x88 (old: m_uiValue88)
    unsigned int m_iNextSaveNumber;                                   // 0x08c GetNextSaveNumber // src: XBOX_RETAIL_PDB +0x8c (old: m_uiNextSaveNumber)
    unsigned int m_iFileStartPosition;                                          // 0x090 // src: XBOX_RETAIL_PDB +0x90 (old: m_uiValue90)
    unsigned int m_iSimulationFileSize;                                          // 0x094 // src: XBOX_RETAIL_PDB +0x94 (old: m_uiValue94)
    char m_OriginalSaveTime[16];                                    // 0x098 ctor memset 0x10 // src: XBOX_RETAIL_PDB +0x98 (old: m_acSaveGameSignature)
    unsigned int m_iOriginalSaveVersion;                           // 0x0a8 // src: XBOX_RETAIL_PDB +0xa8 (old: m_uiCurrentFormRecordCount)
    bool m_bReconstructedAllObjects;                                            // 0x0ac // src: XBOX_RETAIL_PDB +0xac (old: m_bSaveGameLoaded)
    bool m_bLoadingFromMainMenu;                                           // 0x0ad // src: XBOX_RETAIL_PDB +0xad (old: m_bSaveGameCorrupt)
    bool m_bAutosaveDisabledDueToLackOfSpace;                                         // 0x0ae // src: XBOX_RETAIL_PDB +0xae (old: m_bHasPendingChanges)
    bool m_bQuickloading;                              // 0x0af // src: XBOX_RETAIL_PDB +0xaf (old: m_bNeedsReferenceReconstruction)
    void* m_pInitItemArray;                                         // 0x0b0 // src: XBOX_RETAIL_PDB +0xb0 (old: m_pSaveGameListData)
    char m_SavedPlayerData[272];                                        // 0x0b4 // src: XBOX_RETAIL_PDB +0xb4 (old: m_acSaveGamePath)
    _FILETIME* m_pMostRecentSaveGame;                                  // 0x1c4 GetMostRecentSaveGame; freed by the dtor // src: XBOX_RETAIL_PDB +0x1c4 (old: m_pMostRecentSaveTime)

    TESSaveLoadGame();
    ~TESSaveLoadGame();

    // Declarations the units bind (union of their copies). FUN_ names are placeholders; the comment gives the
    // original's name for that address where it is known (several are folded with other classes' getters).
    unsigned short AddFormIDToArray(TESForm*, unsigned int);
    void AddFormToChangesMap(TESForm*, unsigned int);
    void AddFormToInitFormArray(TESForm*);
    void AddInitItem(TESForm*);
    unsigned short AddWorldSpaceIDToArray(unsigned int);
    void AdvanceBuffer(unsigned int);
    void AllowChanges(bool);
    void ApplyFormChanges(bool);
    void Autoload();
    void Autosave();
    void BuildSaveGameList();
    unsigned int CalculateNextSaveNumber();
    void CleanUpExpiredData();
    void CleanupCurrentGameState();
    void CleanupLoadSave(BSFile*, int);
    void CleanupMaps();
    void ClearFormChangeFlags(TESForm*, unsigned int);
    void ClearFormID(unsigned int);
    void ClearNextSaveNumber();
    unsigned int ComputeArmorHash(Actor*);
    int ComputeFormTableChecksum(void*);
    unsigned int ContainsAnyFlags(TESForm*, unsigned int);
    void ConvertArrayByteOrder(NiPoint3*, unsigned int);
    void ConvertArrayByteOrder(double*, unsigned int);
    void ConvertArrayByteOrder(float*, unsigned int);
    void ConvertArrayByteOrder(int*, unsigned int);
    void ConvertArrayByteOrder(long*, unsigned int);
    void ConvertArrayByteOrder(short*, unsigned int);
    void ConvertArrayByteOrder(unsigned int*, unsigned int);
    void ConvertArrayByteOrder(unsigned long*, unsigned int);
    void ConvertArrayByteOrder(unsigned short*, unsigned int);
    void ConvertArrayByteOrder(void*, unsigned int);
    unsigned int ConvertNumericID(unsigned int);
    bool ConvertPCSaveGames();
    void ConvertTypedArrayByteOrder(NiPoint3*, unsigned int);
    void ConvertTypedArrayByteOrder(double*, unsigned int);
    void ConvertTypedArrayByteOrder(float*, unsigned int);
    void ConvertTypedArrayByteOrder(int*, unsigned int);
    void ConvertTypedArrayByteOrder(long*, unsigned int);
    void ConvertTypedArrayByteOrder(short*, unsigned int);
    void ConvertTypedArrayByteOrder(unsigned int*, unsigned int);
    void ConvertTypedArrayByteOrder(unsigned long*, unsigned int);
    void ConvertTypedArrayByteOrder(unsigned short*, unsigned int);
    void ConvertTypedArrayByteOrder(void*, unsigned int);
    void* CreateBuffer(unsigned int);
    void CreateChangedReference(unsigned int);
    TESPackage* CreatePackageForType(unsigned int, unsigned char);
    void* CreateQueuedBuffer(unsigned short);
    void DeleteCreatedBaseObjects();
    void DeleteForm(TESForm*);
    void DeleteSaveGameList();
    void DisplayCorruptSaveGameMessage(BSFile*);
    void DisposeBuffer(void*);
    static void DrawDebugText(TESObjectREFR*, int, int*, int*);
    void EndLoadingSequence();
    char EndianConvert(char);
    int EndianConvert(int);
    short EndianConvert(short);
    unsigned char EndianConvert(unsigned char);
    unsigned int EndianConvert(unsigned int);
    unsigned short EndianConvert(unsigned short);
    bool FUN_0047c850();  // folded getter (TESActorBase::GetHasPLSpecTex)
    void* BGSProjectile_GetExplosion();  // folded with BGSProjectile::GetExplosion
    void* FUN_004fd3e0();  // folded with TES::GetWorldSpace
    bool TESSaveLoadGame_GetRevertBefore();  // 0x55f5b0 = TESSaveLoadGame::GetRevertBefore
    const char* TESSaveLoadGame_GetMostRecentSaveGame();  // 0x5a9460 = TESSaveLoadGame::GetMostRecentSaveGame
    bool bhkPickData_GetPickFailed();  // folded getter (bhkPickData::GetPickFailed)
    unsigned int FUN_00825c00();  // folded with BSTimer::GetTime
    void TESSaveLoadGame_SaveGameDataOLD(int*, int);  // 0x8579b0 = TESSaveLoadGame::SaveGameDataOLD
    void TESSaveLoadGame_SaveGameDataOLD(void*, int);  // 0x8579b0 = TESSaveLoadGame::SaveGameDataOLD
    void TESSaveLoadGame_SaveGameDataOLD(void*, unsigned int);  // 0x8579b0 = TESSaveLoadGame::SaveGameDataOLD
    void TESSaveLoadGame_LoadGameDataOLD(void*, unsigned int);  // 0x8579e0 = TESSaveLoadGame::LoadGameDataOLD
    void TESSaveLoadGame_SaveNumericID(int, int);  // 0x857a10 = TESSaveLoadGame::SaveNumericID
    void TESSaveLoadGame_SaveNumericID(int*, int);  // 0x857a10 = TESSaveLoadGame::SaveNumericID
    void TESSaveLoadGame_SaveNumericID(unsigned int*, unsigned int);  // 0x857a10 = TESSaveLoadGame::SaveNumericID
    void TESSaveLoadGame_SaveNumericID(void*, int);  // 0x857a10 = TESSaveLoadGame::SaveNumericID
    void TESSaveLoadGame_SaveNumericID(void*, unsigned int);  // 0x857a10 = TESSaveLoadGame::SaveNumericID
    void FUN_00857aa0(unsigned int*, int);  // 0x857aa0 = TESSaveLoadGame::LoadNumericID
    void FUN_00857aa0(unsigned int*, unsigned int);  // 0x857aa0 = TESSaveLoadGame::LoadNumericID
    void FUN_00857aa0(void*, unsigned int);  // 0x857aa0 = TESSaveLoadGame::LoadNumericID
    void FUN_00857bd0(unsigned int);  // 0x857bd0 = TESSaveLoadGame::AdvanceBuffer
    void SaveGlobals(BSFile*);  // 0x858480 = TESSaveLoadGame::SaveGlobals
    void* TESSaveLoadGame_CreateBuffer(unsigned int);  // 0x858600 = TESSaveLoadGame::CreateBuffer
    void FUN_00858700(void*);  // 0x858700 = TESSaveLoadGame::DestroyBuffer
    void TESSaveLoadGame_QueueAnimationLoad(void*, unsigned int);  // 0x85f010 = TESSaveLoadGame::QueueAnimationLoad
    void FUN_0085f420(void*, unsigned int);  // 0x85f420 = TESSaveLoadGame::QueueCharControllerLoad
    void TESSaveLoadGame_StartLoadingSequence();  // 0x861ea0 = TESSaveLoadGame::StartLoadingSequence
    bool TESSaveLoadGame_UseSaveGameBlocks();  // 0x862110 = TESSaveLoadGame::UseSaveGameBlocks
    unsigned char FUN_008df040();  // 0x8df040 = TESSaveLoadGame::GetCurrentVersion
    void FinalizeForm(TESForm*);
    void FinalizeQueuedForms();
    void FinishLoad();
    bool FormReconstructionMap(TESObjectCELL*);
    void FreeChangeData(void*);
    void GenerateSaveGameDataOLD(char*, char*, char*);
    void GenerateSaveGameFileName(char*);
    bool GetAllowChanges();
    bool GetAutosaveWhenFadedIn();
    void* GetBufferPointer();
    bool GetBusy();
    unsigned int GetChangeFlags(TESForm*, bool);
    ChangeData* GetChanges(TESForm*);
    bool GetConstructingObject();
    char* GetCurrentPosition();
    unsigned char GetCurrentVersion();
    bool GetDeferInitForms();
    bool GetFadingInFromSaveGame();
    unsigned short GetFileNameSaveSize(char*);
    unsigned int GetFileSize();
    unsigned int GetFormIDFromArray(unsigned int);
    void* GetHitSound();
    bool GetInitArrayExists();
    bool GetInitObject();
    bool GetIniting();
    bool GetLoading();
    bool GetLoadingCreatedBaseObjects();
    bool GetLoadingGlobalData();
    bool GetLoadingTempRefs();
    unsigned int GetMappedFormID(unsigned int, int, int);
    _FILETIME* GetMostRecentSaveGame();
    unsigned int GetNeedToConvertPCSaveGames();
    unsigned int GetNextSaveNumber();
    unsigned int GetNumericIDFromArray(unsigned int);
    unsigned int GetOrCreateFormID(TESForm*, unsigned int);
    bool GetPositioning();
    bool GetPositioningPlayerCharacter();
    unsigned short GetQueuedBufferSaveSize(void*);
    bool GetReconstructedAllObjects();
    bool GetReconstructingObjects();
    bool GetRevertAfter();
    bool GetRevertBefore();
    bool GetRevertingCurrentChanges();
    unsigned short* GetSaveCountPtr();
    NiTexture* GetSaveGameDataOLD(BSFile*, unsigned int*, char*, char*, char*, char*, char*, char*, int*, bool);
    void GetSaveGameDisplayData(BSFile*, unsigned int*, char*, char*, char*);
    void* GetSaveGameList();
    bool GetSaveGameLoading();
    bool GetSimulatedMode();
    bool GetSkyLoading();
    bool GetTemporarilyMovingRef();
    unsigned int GetTimeStamp();
    bool GetUseNumericIDArray();
    unsigned int GetWorldSpaceIDFromArray(unsigned short);
    void HasFormChanges(TESForm*, bool);
    bool HasQueuedChanges();
    bool HasReferenceMoved(TESObjectCELL*, TESObjectREFR*, unsigned int);
    bool InitObject(TESForm*, unsigned int, bool);
    bool IsFormIDInChangesMap(unsigned int);
    bool IsInvalidPoint(NiPoint3*);
    bool IsValidSaveGame(BSFile*);
    void LoadAnimationForReference(TESObjectREFR*, unsigned int, void*);
    void LoadAnimations();
    void LoadAttachedAnimationForReference(TESObjectREFR*, void*);
    void LoadAttachedAnimations();
    void LoadBuffer(BSFile*, void*, unsigned int);
    void LoadChangeData(BSFile*);
    void LoadChangeFormData(BSFile*);
    void LoadCharControllers();
    void LoadCreatedBaseObjects(BSFile*);
    void LoadDataBlock(void*, unsigned int, unsigned int);
    void LoadFinalData(BSFile*);
    bool LoadForm(TESForm*);
    void LoadFormRecords(BSFile*);
    bool LoadGame(BSFile*, char*, bool);
    void LoadGlobalData(BSFile*);
    void LoadHavokData();
    void LoadHavokDataForReference(TESObjectREFR*, void*);
    unsigned int LoadHeader(BSFile*, bool);
    void LoadInitialDataForForm(TESForm*, unsigned int);
    void LoadMostRecentSaveGame();
    void LoadNumericIDArrays(BSFile*);
    void LoadQueuedData(bool);
    void NotifyFormIDChanged(TESForm*, unsigned int);
    void PerformDeferredDeletions();
    void PerformDeferredInitActorPackages();
    unsigned int Position();
    BSFile* PrepForLoadSave(BSFile*, char*, int);
    void PrepareLoadGame(BSFile*);
    unsigned int PurgeSavedDataForCell(TESObjectCELL*);
    unsigned int PurgeSavedDataForLocation(unsigned int, bool);
    unsigned int PurgeSavedDataForWorld(TESWorldSpace*);
    void QueueAttachedAnimationLoad(TESObjectREFR*, unsigned short);
    void QueueBufferLoad(NumericIDBufferMap*, unsigned int, unsigned short);
    void QueueCharControllerLoad(TESObjectREFR*, unsigned short);
    void QueueFormForFinalization(TESForm*);
    void QueueHavokDataLoad(TESObjectREFR*, unsigned short);
    void QueueRemoveChange(unsigned int);
    void QueueRemoveReferenceChange(TESObjectREFR*, unsigned short);
    TESObjectREFR* QueueRemoveReferenceChange(unsigned int);
    bool Quickload();
    void Quicksave();
    void ReInitForcedChanges(TESForm*, unsigned int);
    void ReadFile(BSFile*, NiPoint3*, unsigned int);
    void ReadFile(BSFile*, float*, unsigned int);
    void ReadFile(BSFile*, int*, unsigned int);
    void ReadFile(BSFile*, long*, unsigned int);
    void ReadFile(BSFile*, short*, unsigned int);
    void ReadFile(BSFile*, unsigned int*, unsigned int);
    void ReadFile(BSFile*, unsigned long*, unsigned int);
    void ReadFile(BSFile*, unsigned short*, unsigned int);
    unsigned int TESSaveLoadGame_ReadFile(BSFile*, void*, unsigned int);
    void ReadFileEndian(BSFile*, void*, unsigned int, unsigned int);
    char* ReadFileName(char*);
    void ReadSaveGameMetadata(BSFile*, unsigned int*, char*, char*, _FILETIME*, char*);
    void ReadTypedData(void*, unsigned int);
    void ReconstructAllObjects();
    void RegisterCreatedBaseObject(TESForm*);
    void RemoveCreatedBaseObject(TESForm*);
    void RemoveCreatedBaseObject(unsigned int);
    void RemoveFormFromInitFormArray(TESForm*);
    unsigned short* ReserveCount();
    void ResetCurrentVersion();
    int ResetObject(TESForm*, unsigned int, unsigned int);
    bool ResetReferencePosition(TESObjectREFR*, bool);
    void ResetVersions();
    unsigned int ReverseConvertNumericID(unsigned int);
    void RevertForm(TESForm*, ChangeData*);
    void RevertGlobalData();
    void SafetyCheckReferencePositionAndAngle(TESObjectREFR*);
    void SaveBuffer(BSFile*, void*, unsigned int);
    void SaveData(void*, int);
    void SaveDataBlock(void*, unsigned int, unsigned int);
    void SaveFileName(char*);
    bool SaveGame(BSFile*, char*, bool);
    void SaveGameHeader(BSFile*);
    void SaveGameHeader(BSFile*, char*);
    void SaveGlobalData(BSFile*);
    void SaveHeader(BSFile*, char*);
    void SaveMostRecentSaveGame(BSFile*);
    void SaveQueuedAttachedAnimation(TESObjectREFR*);
    void SaveQueuedHavokData(TESObjectREFR*);
    void SerializeChangeData(BSFile*);
    void SerializeFormToBuffer(char*, TESForm*, unsigned int, unsigned char, bool);
    void SetAutosaveWhenFadedIn(bool);
    void SetBufferPointer(void*);
    void SetBusy(bool);
    void SetConstructingObject(bool);
    void SetCurrentVersion(unsigned char);
    void SetDeferInitForms(bool);
    void SetFadingInFromSaveGame(bool);
    void SetFormFlags(TESForm*, unsigned int);
    bool SetFormLoaded(TESForm*);
    void SetInitObject(bool);
    void SetIniting(bool);
    void SetLoading(bool);
    void SetLoadingCreatedBaseObjects(bool);
    void SetLoadingGlobalData(bool);
    void SetLoadingTempRefs(bool);
    void SetPositioning(bool);
    void SetPositioningPlayerCharacter(bool);
    void SetReconstructedAllObjects(bool);
    void SetReconstructingObjects(bool);
    void SetRevertState(int);
    void SetRevertingCurrentChanges(bool);
    void SetSaveGameLoading(bool);
    void SetSimulatedMode(bool);
    void SetSkyLoading(bool);
    void SetTemporarilyMovingRef(bool);
    void SetUseNumericIDArray(bool);
    void StartLoadingSequence();
    void StripIllegalCharacters(char*);
    void SwapUnsignedIntByteOrder(unsigned int*, unsigned int);
    void TestAllCells(unsigned int);
    void TestSaveCreatedBaseObjects();
    void UpdateLoadingSequence();
    bool ValidateFormIDArray(unsigned int*, unsigned int);
    void WriteCreatedBaseObjects(BSFile*);
    void WriteFile(BSFile*, NiPoint3*, unsigned int);
    void WriteFile(BSFile*, float*, unsigned int);
    void WriteFile(BSFile*, int*, unsigned int);
    void WriteFile(BSFile*, long*, unsigned int);
    void WriteFile(BSFile*, short*, unsigned int);
    void WriteFile(BSFile*, unsigned int*, unsigned int);
    void WriteFile(BSFile*, unsigned long*, unsigned int);
    void WriteFile(BSFile*, unsigned short*, unsigned int);
    unsigned int WriteFile(BSFile*, void*, unsigned int);
    void WriteFileEndian(BSFile*, void*, unsigned int, unsigned int);
};
