#pragma once

template <class T> class BSSimpleList;
class Actor;
class BGSLoadFormBuffer;
class BGSSaveFormBuffer;
class TESObjectREFR;
class ExtraDataList;
class ScriptLocals;
class TESBoundObject;
class TESObjectWEAP;
class WeaponObjStub;

class InventoryStackRecord
{
public:
    BSSimpleList<ExtraDataList*>* pExtraObjectList;
    int iNumber;
    TESBoundObject* pContainerObj;

    InventoryStackRecord();
    InventoryStackRecord(TESBoundObject* apObject, int aiNumber);
    ~InventoryStackRecord();

    float GetArmorDamageThreshold(Actor* actor);
    float GetConditionPercent(bool percentage);
    static float GetConditionPercent(float health);
    bool SetEquipmentState(int effect, float& value);
    bool SetEquipmentState(int effect);
    bool SetEquipmentState(unsigned char effect);
    bool SetEquipmentState(unsigned char effect, float& value);
    static float __cdecl RoundToNearestStep(float value, float maximum);
    TESBoundObject* GetObject();
    void* Destroy(unsigned int flags);
    void* FUN_004459e0(unsigned int flags);
    unsigned char GetWeaponCategory();
    int GetIndex();
    WeaponObjStub* GetWeaponObj();
    float GetWeaponConditionHealth(bool abBase);
    unsigned char const* __thiscall GetFullName();
    TESObjectWEAP* GetFlags();
    TESBoundObject* FUN_0044ddc0();
    bool ItemChange_GetWorn(bool abUnk);
    BSSimpleList<ExtraDataList*>* Modelloader_GetReferencedThis();
    int FUN_00726070();
    void ClearExtraDataList();
    int CountAndPruneEntries();
    int ItemChange_GetExtraTotalCount(bool abWornIgnore);
    int ItemChange_GetExtraTotalDefaultCount();
    void InitLoadGame(BGSLoadFormBuffer* buffer);
    bool HasPerkEntry();
    bool HasStolenData();
    ScriptLocals* GetScriptLocals();

    void SetPoison(void* apPoison);
    void SavePerkList(BGSSaveFormBuffer* buffer);
    InventoryStackRecord* ItemChange_ctor(InventoryStackRecord* apCopy);
    void SetExtraListFlag(bool abNew, bool abFlag, bool abDelete);
    void CopyFirstExtraList(void* extra);
    const char* GetIconFilename(TESObjectREFR* reference);
};
