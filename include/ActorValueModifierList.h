#pragma once

#if !defined(FNV64_BSSIMPLELIST_DEFINED) && !defined(FNV_EXTRADATAOBJECTS_PRIVATE_LAYOUT_SUPPORT_H)
#include "BSSimpleList.h"
#endif
#include "MagicTarget.h"

class BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
class Modifier;
class ModifierPointerList;

class ActorValueModifierList : public BSSimpleList<Modifier*>
{
public:
    bool bZeroValuesAllowed; // src: XBOX_RETAIL_PDB +0x8 (old: m_bAllowZeroValueModifiers)
    unsigned char layoutPadding9;
    unsigned short layoutPaddingA;
    ModifierPointerList* pFastModifiers; // src: XBOX_RETAIL_PDB +0xc (old: m_ppModifiedActorValues)

    enum ClampStyle
    {
        ClampNone = 0
    };

    ActorValueModifierList();
    ~ActorValueModifierList();

    Modifier* GetModifierItem(char acKey);
    float GetActorValueModifierAmount(char acKey, bool& abExists);
    float GetActorValueModifierAmount(char acKey);
    void ModifyModifier(char acKey, float afValue, ClampStyle aeClampStyle);
    void ModifierList_SetModifier(char acKey, float afValue);
    static float ModifyAndClamp(float value, float delta, ClampStyle clamp);
    void EraseModifier(Modifier* modifier);
    void SetAllModifiers(ActorValueModifierList* other);
    void AppendModifier(Modifier* apModifier);
    void DeleteAllModifiers();
    void AddFastModifier(char key, Modifier* modifier);
    void ModifierList_SaveGameBGS(BGSSaveFormBuffer* buffer);
    void Revert();
    void LoadGame(BGSLoadFormBuffer* buffer);
    void InitLoadGame(BGSLoadFormBuffer* buffer);
};
