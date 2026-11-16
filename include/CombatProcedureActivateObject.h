#pragma once

#include "CombatProcedure.h"

class TESObjectREFR;
class TESBoundObject;

// pdb: class CombatProcedureActivateObject, size 0x1c, bases: CombatProcedure, 3 members
class CombatProcedureActivateObject : public CombatProcedure
{
public:
    CombatProcedureActivateObject(TESObjectREFR* apTargetRef, TESBoundObject* apBoundObject);
    virtual ~CombatProcedureActivateObject();

    virtual void Unk04();
    virtual void Unk10(int);
    virtual int GetType();
    virtual void SaveGame(BGSSaveFormBuffer* apSaveGameBuffer);
    virtual void LoadGame(BGSLoadFormBuffer* apLoadGameBuffer);

    int Return8();
    void FUN_009ca740();
    void Update_009ca760();
    void CombatProcedure_SetFailed(const char* msg);
    void CombatProcedure_SetFailed(int arg1);
    void SetState();
    void ClearReferencePointers_009cab00(TESObjectREFR* apRef);
    void vf04(TESObjectREFR* apRef);
    void SaveGame_009cacb0(BGSSaveFormBuffer* apSaveGameBuffer);
    void LoadGame_009cad00(BGSLoadFormBuffer* apLoadGameBuffer);
    void InitLoadGame_009cad70(unsigned int apLoadGameBuffer);

    TESObjectREFR* pTargetRef; // src: XBOX_RETAIL_PDB +0x10 (old: m_pReference)
    TESBoundObject* pBoundObject; // src: XBOX_RETAIL_PDB +0x14 (old: m_pBaseObject)
    union
    {
        char m_cValue24;
        char cAnimState;
        char bFlag;
        signed char status;
    };
};
