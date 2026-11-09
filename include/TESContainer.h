#pragma once

#include "BaseFormComponent.h"

#if !defined(FNV64_BSSIMPLELIST_DEFINED) && !defined(FNV_LAYOUT_SUPPORT_H) && !defined(FNV_EXTRADATAOBJECTS_PRIVATE_LAYOUT_SUPPORT_H)
#include "BSSimpleList.h"
#endif
class ContainerChanges;
class ContainerItem;
class ContainerItemExtra;
class InventoryChanges;
class InventoryItemEntry;
class InventoryStackRecord;
class ListShell;
class TESActorBase;
class TESAmmo;
class TESBoundObject;
class TESForm;
class TESObject;
class TESObjectARMO;
class TESObjectCLOT;
class TESObjectREFR;
class TESObjectWEAP;
class TickPlayer;

// pdb: class TESContainer, size 0xc, bases: BaseFormComponent, 1 members
class TESContainer : public BaseFormComponent
{
public:
    TESContainer();
    ~TESContainer();

    virtual void Init();
    virtual void Free();
    virtual void CopyFromBase(BaseFormComponent* apCopyFC);
    virtual bool CompareWithBase(BaseFormComponent* apCompareFC);

    void InitializeComponent();
    void ClearComponent();
    void Save();
    void BaseFormRecord(BaseFormComponent* apCopyFC);
    bool IsEqualToBase(BaseFormComponent* component);
    void InitItem(TESForm* apOwner);
    void FreeObjectList();
    InventoryItemEntry* AddObject(ContainerChanges* apCOFile);
    InventoryItemEntry* AddObject(TESObject* object, int count, ContainerItemExtra* extra);
    void AddObject(TESForm* form, int count, ContainerItemExtra* extra);
    void AddObject(InventoryItemEntry* object);
    void FUN_004818e0(void* object, int count, int extra);
    void FUN_004818e0(void* object, int count, void* extra);
    void* AddContainerObject(void* apCOFile);
    InventoryItemEntry* AddContainerObject(ContainerItem* apCOFile);
    void AddDuplicateObject(InventoryItemEntry* object);
    InventoryItemEntry* GetFirstContainerObject();
    void RemoveContainerObject(InventoryItemEntry* apCObj);
    void ReplaceObject(TESObject* object, TESObject* replacement);
    bool HasObjectOfType(TESObject* object);
    float GetContainerWeight(bool abIsHardcore);
    int GetObjectCount(TESObject* object);
    char Compare(InventoryItemEntry* first, InventoryItemEntry* second);
    float GetClothingModifier();
    static bool IsValidContainerType(unsigned char type);
    static bool IsValidContainerObject(TESObject* object);
    void AddContainerContents(TESContainer* container);
    void MultiplyContainerCounts(int multiplier);
    void ScaleEntryCounts(int multiplier);
    void SetClothingModifier(float modifier);
    void ApplyHealthPercentToContainer(float modifier);
    void AddContentsFromReference(TESObjectREFR* reference, bool value);
    void AddContainerToReference(TESObjectREFR* apRef, bool abSilent);
    void AddContainerToReference(TickPlayer* apRef, int abSilent);
    void AddContainerToReference(void* apRef, bool abSilent);
    void AddLevItemContainerToChanges(int value, InventoryChanges* changes);
    TESAmmo* GetBestAmmoForActor(TESActorBase* actor);
    TESObjectWEAP* GetBestWeapon(TESActorBase* apActorBase);
    TESObjectARMO* FindBestArmor(TESActorBase* actor, int slot);
    TESObjectCLOT* GetBestClothing(TESActorBase* actor, int slot);
    TESBoundObject* GetInventoryEntryData(int slot);
    BSSimpleList<InventoryStackRecord*>* GetObjectList();
    void* GetObjectListEnd();
    ListShell* FUN_00717e50();

    union
    {
        struct
        {
            unsigned int count;
            InventoryItemEntry** objects;
        };
        struct
        {
            BSSimpleList<InventoryStackRecord*> objectList;
        };
    };
};
