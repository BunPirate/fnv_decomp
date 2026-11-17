#pragma once

class TESPackage;
class ActorPackageData;
class TESObjectREFR;
class TESPackageData;
class BGSSaveFormBuffer;
class BGSLoadFormBuffer;

class ActorPackageContext
{
public:
    TESPackage* pPackage;
    ActorPackageData* pData;
    TESObjectREFR* pTarget;
    int m_iPackageValue;
    float m_fPackageValue;
    unsigned int iFlags;

    void Clear();
    void ActorPackage_InitFromPackage(TESPackage*, TESObjectREFR*);
    void MoveTo(ActorPackageContext*);
    void MovePackageData(ActorPackageContext*);
    void SetReferenceTarget(TESObjectREFR*);
    TESPackage* GetTESPackage();
    TESPackageData* GetTESPackageData();
    ActorPackageData* GetInstanceData();
    float GetPackageStartTime();
    int GetPackageState();
    void SetPackageInfoState(int);
    void SetPackageExecutionState(int);
    void SetInstanceData(ActorPackageData*);
    void NullInstanceData();
    unsigned short GetSaveSize(unsigned int);
    void SaveGame(BGSSaveFormBuffer*);
    void TESSaveLoadGame_SaveGameDataOLDEndian(unsigned int);
    void LoadGame(BGSLoadFormBuffer*);
    void LoadGame(unsigned int, unsigned int);
    void InitLoadGame(BGSLoadFormBuffer*);
    void ActorPackage_InitLoadGame(unsigned int, unsigned int);
    void Revert(BGSLoadFormBuffer*);
    void ActorPackage_Revert(unsigned int);
    void ActorPackage_FinishLoadGame(BGSLoadFormBuffer*);
    void SetTarget(TESObjectREFR*);
    TESObjectREFR* GetTarget();
    void SetFlag(int, bool);
    void SetFlag(unsigned char, bool);
    bool GetFlag(int);
    bool IsFlagSet(unsigned char);
    int GetProcedureIndex();
    void AddToProcedureIndex(int);
    void* __vecDelDtor(unsigned int);
};
