#pragma once

#include "TESForm.h"
#include "EncounterZoneData.h"
#include "CellDetachData.h"

class TESObjectCELL;
class BGSSaveFormBuffer;
class BGSLoadFormBuffer;

// pdb: class BGSEncounterZone, size 0x30, bases: TESForm, 2 members
struct BGSEncounterZone : public TESForm
{
public:
    BGSEncounterZone();
    virtual ~BGSEncounterZone();

    void ResetFormData();
    bool Load(TESFile* apFile);
    virtual void InitItem();
    unsigned short GetCalculatedLevel();
    bool QMatchPCBelowMin();
    unsigned char GetByteAt1D();

    void Save();
    void SetDetachTime_00526070(unsigned int aiVal);
    void SetAttachTime(unsigned int aiVal);
    bool ShouldCellRecalc(TESObjectCELL* apCell);
    void SetZoneLevel(unsigned short aiVal);
    void DetermineLevel();
    bool QNeverReset();
    virtual void SaveGame(BGSSaveFormBuffer* buffer);
    void LoadGame_005264a0(BGSLoadFormBuffer* buffer);
    void RevertAndClearIfChanged(BGSLoadFormBuffer* apLoadGameBuffer);
    bool Compare_00526000(TESForm* apCompare);
    void Copy_00525fa0(TESForm* apCopy);

    static void CreateNoZone();
    static BGSEncounterZone* ms_pDefaultEncounterZone;

    EncounterZoneData Data;
    CellDetachData GameData;
};
