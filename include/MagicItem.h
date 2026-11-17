#pragma once

#include "TESFullName.h"
#include "EffectItemList.h"
#include "ActiveEffect.h"

class EffectSetting;
class EffectSettingQ;
class TESFile;
class TESForm;

namespace MagicSystem
{
    enum Range
    {
        SELF = 0,
        TOUCH = 1,
        TARGET = 2,
        RANGE_COUNT = 3
    };
}

// pdb: class MagicItem, size 0x1c, bases: TESFullName, EffectItemList, 0 members
class MagicItem : public TESFullName, public EffectItemList
{
public:
    typedef int CannotCastReason;

    virtual ~MagicItem();

    virtual bool IsAutoCalculated();
    virtual void SetPlayable(bool bAutoCalc);
    virtual MagicSystem__SpellType GetSpellType();
    virtual bool IgnoreResistance();
    virtual bool GetNoAbsorbOrReflect();
    virtual unsigned int GetChunkID();
    virtual void* GetData();
    virtual unsigned int GetDataSize();
    virtual bool IsMagicItemEqual(MagicItem* pOther);
    virtual void CopyMagicItemData(MagicItem* pOther);
    virtual void ClearMagicItemData();
    virtual void SaveMagicItemData();
    virtual void LoadMagicItemChunk(TESFile* pFile, unsigned int uiChunk);

    void Endian();

    static MagicItem* GetMagicItemByNumericID(unsigned int aiFormID);
    EffectSetting* GetEffectSettingForRange(MagicSystem::Range aeRange);
    void ClearEffectList();
    void Preload(bool abNow);
    void Unload(bool abUnload);
    bool IsLoaded();
    bool IsLoading();
    void MagicItemInitItem(TESForm* apForm);

    void FUN_00403600(MagicItem* source);
    EffectSettingQ* FUN_0040a300(int iUnk);
    bool SpellItem_CompareMagicItemData(MagicItem* apCompare);
    const char* TESModel_GetModel();
    void FUN_0040b800(int);
    void FUN_0040b800(bool);
};
