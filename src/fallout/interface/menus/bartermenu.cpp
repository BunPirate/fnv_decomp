#include "../../../../include/BSSimpleList.h"
#include "../../../../include/ListBox_ItemChange___.h"
#include "../../../../include/ListBoxBase.h"
#include "../../../../include/Menu.h"
#include "../../../../include/InventoryChanges.h"
#include "../../../../include/BSAudio.h"
#include "../../../../include/TESObjectREFR.h"
#include "../../../../include/Setting.h"
#include "../../../../include/BarterMenu.h"
#include "../../../../include/BSSoundHandle.h"
#include "../../../../include/TESFullName.h"
#include "../../../../include/Tile.h"
#include "../../../../include/BaseProcess.h"
#include "../../../../include/InventoryStackRecord.h"
#include "../../../../include/PlayerCharacter.h"
#include "../../../../include/TESBipedModelForm.h"
#include "../../../../include/TESBoundObject.h"
#include "../../../../include/TESObjectARMO.h"
#include "../../../../include/TESObjectWEAP.h"

// src/fallout/interface/menus/bartermenu.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/interface/menus/bartermenu.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// @fnv 0x0072d030
int __thiscall BarterMenu::GetClass()
{
    return 0x41d;
}

// @fnv 0x0072d6c0
// src: COMMUNITY 0x0072d6c0
int __cdecl BarterMenu_GetClassStatic()
{
    return 0x41d;
}

char __cdecl ConsumeByteAtE4();
void __cdecl BarterMenu_Close();

// @fnv 0x0072db40
// src: XBOX_PDB 0x0072db40
// pdb: BarterMenu::CancelConfirmFunc | BarterMenu.obj | retail, upstream name already matches, high
void __cdecl BarterMenu_CancelConfirmFunc()
{
    if (!ConsumeByteAtE4())
        BarterMenu_Close();
}

extern int DAT_011d8fa4;
extern unsigned char DAT_011d8fc0;

// If abNow is set, calls RebuildInventoryLists(0) on DAT_011d8fa4 when non-null and clears DAT_011d8fc0; otherwise sets DAT_011d8fc0 to 1.
// @fnv 0x00730690
// src: XBOX_PDB 0x00730690
// pdb: BarterMenu::ForceBarterUpdate | BarterMenu.obj | retail, upstream name already matches, high
// pdb params: abNow
void __cdecl BarterMenu_ForceBarterUpdate(bool abNow)
{
    if (abNow)
    {
        if (DAT_011d8fa4 != 0)
        {
            reinterpret_cast<BarterMenu*>(DAT_011d8fa4)->UpdateLists(0);
        }
        DAT_011d8fc0 = 0;
    }
    else
    {
        DAT_011d8fc0 = 1;
    }
}

void __cdecl _Deallocate(void*);

// Calls FUN_0072d0a0, then frees this when flags has bit 0 set, and returns this.
// @fnv 0x0072d070
// pdb: BarterMenu::`scalar deleting destructor' | BarterMenu.obj | retail, vtable slot, high
void* BarterMenu::FUN_0072d070(unsigned int flags)
{
    this->BarterMenu::~BarterMenu();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

// Calls Set(0xfa3, 0) on the Tile objects at offsets 0x7c and 0x78 of this BarterMenu.
// @fnv 0x0072e530
// src: XBOX_PDB 0x0072e530
// pdb: BarterMenu::DoLeave | BarterMenu.obj | retail, upstream name already matches, high
// pdb params: aiID, apTarget
void BarterMenu::DoLeave(int aiID, void* apTarget)
{
    m_apTiles[21]->Set(0xfa3, 0);
    m_apTiles[20]->Set(0xfa3, 0);
}

// pdb: structure WeatherEntry, size 0xc (here 0x1), 3 members
struct WeatherEntry
{
};

struct FUN_0071a670_shell
{
    void ListBox_ItemChange_Synchronize();
};

struct FUN_00730b80_shell
{
    char pad[4];
    BSSimpleList<WeatherEntry*> list;
    void SortWeatherEntries(int(__cdecl* apCompareFn)(WeatherEntry*, WeatherEntry*));
};

// Sorts the weather entry list with the given comparison function, then calls UpdateItems on this object.
// @fnv 0x00730b80
// pdb: ListBox<ItemChange *>::Sort | BarterMenu.obj | retail, vtable slot, high
// pdb params: apCompareFn
void FUN_00730b80_shell::SortWeatherEntries(int(__cdecl* apCompareFn)(WeatherEntry*, WeatherEntry*))
{
    list.Sort(apCompareFn);
    reinterpret_cast<FUN_0071a670_shell*>(this)->ListBox_ItemChange_Synchronize();
}

extern PlayerCharacter* g_thePlayer;
struct TopicMenu
{
    char pad0[4];
    Tile* pTile;
    char pad8[0x11c - 8];
    unsigned char bFlag;
    void FUN_00a1d910();
};
int __cdecl GetTopicSubTypeName(int a, int b);
void __cdecl DialogMenu_ServiceEnd(int apTopic);

// @fnv 0x0072d6d0
// src: XBOX_RETAIL_PDB 0x0072d6d0
// pdb: BarterMenu::Close | BarterMenu.obj | retail, call graph (shared callers), high
// pdb locals: ptopic
void __cdecl BarterMenu_Close()
{
    if (DAT_011d8fa4 != 0)
    {
        BaseProcess* pAIProcess = static_cast<const PlayerCharacter*>(g_thePlayer)->GetCurrentAIProcess();
        if (pAIProcess->IsProcessFlagSet(1))
            g_thePlayer->PlayerCharacter_UpdatePlayer3d();
        int iTopic = 0;
        if (((TopicMenu*)DAT_011d8fa4)->bFlag)
            iTopic = GetTopicSubTypeName(5, 4);
        DialogMenu_ServiceEnd(iTopic);
        ((TopicMenu*)DAT_011d8fa4)->pTile->SetInt(0x1772, 1);
        ((TopicMenu*)DAT_011d8fa4)->FUN_00a1d910();
    }
}

bool TESContainer_IsGold(TESBoundObject*);
// @fnv 0x0072e570
// src: XBOX_PDB 0x0072e570
// pdb: BarterMenu::PlayerFirstPassFilterFunc | BarterMenu.obj | retail, upstream name already matches, high
// pdb params: apItem
// pdb locals: pweap, pbipedForm, pammo, pfull, pobj, bisFiltered
bool BarterMenu_PlayerFirstPassFilterFunc(InventoryStackRecord* apItem)
{
    bool unavailable = false;
    {
        TESBoundObject* form;
        {
            TESFullName* name;
            {
                TESObjectWEAP* weapon;
                {
                    TESBipedModelForm* biped;
                    {
                        TESObjectARMO* armor;

                        form = apItem ? apItem->FUN_0044ddc0() : 0;
                        biped = TESBipedModelForm::GetFormAsBipedModel(form);
                        name = dynamic_cast<TESFullName*>(form);
                        armor = apItem->FUN_0044ddc0()->FUN_00401170() == 0x28
                                    ? static_cast<TESObjectARMO*>(apItem->FUN_0044ddc0())
                                    : 0;
                        weapon = apItem->FUN_0044ddc0()->FUN_00401170() == 0x29
                                     ? static_cast<TESObjectWEAP*>(apItem->FUN_0044ddc0())
                                     : 0;
                        if (!form || (biped && !biped->TESBipedModelForm_GetPlayable()) || form->IsQuestItem() || TESContainer_IsGold(form) ||
                            !name || !name->GetModelLength() || (armor && !armor->IsFlag80Clear()) ||
                            (weapon && !weapon->FUN_004c94d0()) || form->FUN_00401170() == 0x2e)
                            unavailable = true;
                    }
                }
            }
        }
    }
    return unavailable;
}

void* __cdecl InterfaceManager_GetSingleton();

struct FUN_0070ec70_This
{
    int InterfaceManager_GetMouseWheel();
};

// For type 3 or 8, checks FUN_0070ec70() and calls Notify with 2/7 when negative, otherwise 4/9.
// @fnv 0x0072f680
// src: XBOX_PDB 0x0072f680
// pdb: BarterMenu::DoWheelMove | BarterMenu.obj | retail, upstream name already matches, high
// pdb params: aiID, apTarget
void BarterMenu::DoWheelMove(int aiID, int apTarget)
{
    if (aiID == 3 || aiID == 8)
    {
        if (((FUN_0070ec70_This*)InterfaceManager_GetSingleton())->InterfaceManager_GetMouseWheel() < 0)
            HandleSelection(aiID == 3 ? 2 : 7, 0);
        else
            HandleSelection(aiID == 3 ? 4 : 9, 0);
    }
}

struct S_Mgr
{
    void FUN_0046faf0();
};

extern S_Mgr* DAT_011c3f2c;

// @fnv 0x0072d0a0
// pdb: BarterMenu::~BarterMenu | BarterMenu.obj | retail, upstream name already matches, high
// pdb locals: pcurrBuyItemRef, pcurrSellItemRef
BarterMenu::~BarterMenu()
{
    BSSimpleList<InventoryStackRecord*>* cur;
    BSSimpleList<InventoryStackRecord*>* cur2;
    if (DAT_011d8fa4 != 0)
    {
        for (cur = &((BarterMenu*)DAT_011d8fa4)->m_kMerchantItems; cur != 0 && cur->GetItem() != 0; cur = cur->GetNext())
        {
            InventoryStackRecord* item = cur->GetItem();
            InventoryStackRecord* obj = item;
            obj != 0 ? obj->FUN_004459e0(1) : 0;
        }
        for (cur2 = &((BarterMenu*)DAT_011d8fa4)->m_kPlayerItems; cur2 != 0 && cur2->GetItem() != 0;
             cur2 = cur2->GetNext())
        {
            InventoryStackRecord* item2 = cur2->GetItem();
            InventoryStackRecord* obj2 = item2;
            obj2 != 0 ? obj2->FUN_004459e0(1) : 0;
        }
        ((BarterMenu*)DAT_011d8fa4)->m_kMerchantItems.RemoveAll();
        ((BarterMenu*)DAT_011d8fa4)->m_kPlayerItems.RemoveAll();
    }
    DAT_011c3f2c->FUN_0046faf0();
    DAT_011d8fa4 = 0;
}

extern const char str_010707d0[];
extern const char str_010707b4[];
extern const char str_01070760[];
extern const char str_010704d4[];
extern const char str_0107074c[];
extern const char str_01070740[];
extern const char str_01070734[];
extern const char str_0106ed20[];
extern double DAT_010704f0;
extern double DAT_010704e8;

extern int DAT_011d8fa4;

struct ObjA
{
    virtual int v0(int a);
};

struct ObjB
{
    BarterMenu* Tile_GetMenu();
    Tile* Tile_GetChildByName(const char* a);
    double FUN_00a011b0(int a);
    void Tile_Set(int a, float b);
};

struct ObjX
{
    ObjB* Tile_ReadFile();
};

struct SelfObj
{
    ObjX* CombatController_GetCombatState(const char* a);
    void InterfaceManager_TutorialManager_ShowMessage(int a, int b, int c);
};

extern Setting DAT_011d4378;
extern Setting DAT_011d25b0;
extern Setting DAT_011d26f4;
extern Setting DAT_011d33fc;
extern Setting DAT_011d2aa8;
extern Setting DAT_011d26a0;
extern Setting DAT_011d2c7c;
extern Setting DAT_011d412c;
extern Setting DAT_011d330c;
extern Setting DAT_011d20c4;
extern Setting DAT_011d396c;
extern char* DAT_011dea3c;

struct SubEA
{
    int FUN_0066ef20(int aiWhich);
};

struct ErrLog
{
    static void __cdecl Warning_005b5e40(const char* a);
};

void* __cdecl InterfaceManager_GetSingleton();
int __cdecl Warning_005b5e40(int a, const char* b);
int __cdecl BarterMenu_GetClassStatic();
ObjA* __cdecl Tile_GetMenuByClass(int a);
int __cdecl Tile_TextToTrait(const char* a);
float __stdcall FUN_00a01530(int a);
void __cdecl DialogMenu_ServiceStart();
int __cdecl BSMAX_00647b70(int a, int b);
int __cdecl MinInt(int a, int b);
int __cdecl Gameplayformulas_GetSkillPriceMultipliers(int a, int* b, int* c);
void __cdecl InterfaceManager_PlayMenuSound(int aeMenuSound);

// Validates arg0, resolves the inventory menu object, initializes its labels and settings from the config, and stores it in DAT_011d8fa4.
// @fnv 0x0072d250
// src: XBOX_DEBUG_PDB 0x0072d250
// pdb: BarterMenu::Create | BarterMenu.obj | debug, unique string literal, high
// pdb params: apVendor, aiDiscount
// pdb locals: pim, ptile, pold_menu_tile
int __cdecl BarterMenu_Create(int apVendor, int aiDiscount)
{
    int aT30;
    BarterMenu* t2c15;
    int t28a;
    BarterMenu* cb8;
    BarterMenu* kCb2;
    ObjA* aChain1;
    ObjA* chain2j;
    int xTmp14;
    Tile* tmp10o;
    void* selfa = InterfaceManager_GetSingleton();
    ObjB* bb;
    ObjA* ah;

    if (apVendor == 0)
    {
        Warning_005b5e40(0x12, str_010707d0);
        return 0;
    }
    ah = Tile_GetMenuByClass(BarterMenu_GetClassStatic());
    if (ah != 0)
    {
        aChain1 = ah;
        chain2j = aChain1;
        if (chain2j != 0)
            t28a = chain2j->v0(1);
        else
            t28a = 0;
    }
    bb = ((SelfObj*)selfa)->CombatController_GetCombatState(str_010707b4)->Tile_ReadFile();
    if (bb != 0)
        t2c15 = bb->Tile_GetMenu();
    else
        t2c15 = 0;
    DAT_011d8fa4 = (int)t2c15;
    if (DAT_011d8fa4 != 0 && ((BarterMenu*)DAT_011d8fa4)->GetClass() == BarterMenu_GetClassStatic())
    {
        ((BarterMenu*)DAT_011d8fa4)->FUN_00a1dc70(reinterpret_cast<TileMenu*>(bb), 0);
        if (((BarterMenu*)DAT_011d8fa4)->HasNoZeroEntries() == 0)
        {
            ErrLog::Warning_005b5e40(str_01070760);
            return 0;
        }
        if (bb->FUN_00a011b0(0xfa7) == DAT_010704f0 || bb->FUN_00a011b0(0xfa7) == DAT_010704e8)
        {
            bb->Tile_Set(0xfad, FUN_00a01530(1));
        }
        DialogMenu_ServiceStart();
        ((SelfObj*)((char*)selfa + 0x4d4))->InterfaceManager_TutorialManager_ShowMessage(0x17, BarterMenu_GetClassStatic(), 0x200);
        ((BarterMenu*)DAT_011d8fa4)->m_kMerchantList.Initialize(((BarterMenu*)DAT_011d8fa4)->m_apTiles[6], str_010704d4);
        ((BarterMenu*)DAT_011d8fa4)->m_kPlayerList.Initialize(((BarterMenu*)DAT_011d8fa4)->m_apTiles[11], str_010704d4);
        ((BarterMenu*)DAT_011d8fa4)->m_apTiles[3]->Tile_Set_00a01350(0xfc4, DAT_011d4378.FUN_00403df0(), true);
        bb->Tile_GetChildByName(str_0107074c)->Tile_Set_00a01350(0xfc4, DAT_011d25b0.FUN_00403df0(), true);
        ((BarterMenu*)DAT_011d8fa4)->m_apTiles[13]->Tile_Set_00a01350(0xfc4, DAT_011d26f4.FUN_00403df0(), true);
        ((BarterMenu*)DAT_011d8fa4)->m_apTiles[19]->Tile_Set_00a01350(0xfc4, DAT_011d33fc.FUN_00403df0(), true);
        xTmp14 = Tile_TextToTrait(str_0106ed20);
        tmp10o = bb->Tile_GetChildByName(str_01070740);
        if (tmp10o != 0)
            tmp10o->Tile_Set_00a01350(xTmp14, DAT_011d2aa8.FUN_00403df0(), true);
        tmp10o = bb->Tile_GetChildByName(str_01070734);
        if (tmp10o != 0)
            tmp10o->Tile_Set_00a01350(xTmp14, DAT_011d26a0.FUN_00403df0(), true);
        if (((BarterMenu*)DAT_011d8fa4)->m_apTiles[14] != 0)
            ((BarterMenu*)DAT_011d8fa4)->m_apTiles[14]->Tile_Set_00a01350(xTmp14, DAT_011d2c7c.FUN_00403df0(), true);
        if (((BarterMenu*)DAT_011d8fa4)->m_apTiles[15] != 0)
            ((BarterMenu*)DAT_011d8fa4)->m_apTiles[15]->Tile_Set_00a01350(xTmp14, DAT_011d412c.FUN_00403df0(), true);
        if (((BarterMenu*)DAT_011d8fa4)->m_apTiles[16] != 0)
            ((BarterMenu*)DAT_011d8fa4)->m_apTiles[16]->Tile_Set_00a01350(xTmp14, DAT_011d330c.FUN_00403df0(), true);
        if (((BarterMenu*)DAT_011d8fa4)->m_apTiles[17] != 0)
            ((BarterMenu*)DAT_011d8fa4)->m_apTiles[17]->Tile_Set_00a01350(xTmp14, DAT_011d20c4.FUN_00403df0(), true);
        if (((BarterMenu*)DAT_011d8fa4)->m_apTiles[18] != 0)
            ((BarterMenu*)DAT_011d8fa4)->m_apTiles[18]->Tile_Set_00a01350(xTmp14, DAT_011d396c.FUN_00403df0(), true);
        ((BarterMenu*)DAT_011d8fa4)->m_pkMerchant = reinterpret_cast<TESObjectREFR*>(apVendor);
        ((BarterMenu*)DAT_011d8fa4)->unk88 = MinInt(BSMAX_00647b70(aiDiscount, -100), 100);
        ((BarterMenu*)DAT_011d8fa4)->m_fBarterTotal = 0.0f;
        Gameplayformulas_GetSkillPriceMultipliers(((SubEA*)((char*)DAT_011dea3c + 0xa4))->FUN_0066ef20(0x20), reinterpret_cast<int*>(&((BarterMenu*)DAT_011d8fa4)->m_f94),
                     reinterpret_cast<int*>(&((BarterMenu*)DAT_011d8fa4)->m_f98));
        InterfaceManager_PlayMenuSound(0x24);
        ((BarterMenu*)DAT_011d8fa4)->FUN_00a1dc20(0);
        ((BarterMenu*)DAT_011d8fa4)->UpdateLists(0);
        return (int)bb;
    }
    else if (DAT_011d8fa4 != 0 && ((BarterMenu*)DAT_011d8fa4)->FUN_00726070() != 0)
    {
        cb8 = (BarterMenu*)DAT_011d8fa4;
        kCb2 = cb8;
        if (kCb2 != 0)
            aT30 = reinterpret_cast<ObjA*>(kCb2)->v0(1);
        else
            aT30 = 0;
    }
    return 0;
}

struct BmExtraList
{
    TESObjectREFR* ExtraDataList_GetOriginalReference();
};

extern InventoryStackRecord* g_pkSelectedItem_011d8fa8;
extern unsigned char g_bBarterFlag_0119fdb0;

extern Setting g_s_011d2418;

extern Setting g_s_011d1fa4;
extern Setting g_s_011d34f8;
extern Setting g_s_011d3684;

struct BmPopup
{
    virtual void Destroy(bool bFree);
    void FUN_007312e0();
};

struct BmItemList
{
    int FUN_005ae380();
};
struct BmFilteredList
{
    void ApplyFilter(int(__cdecl* apFilterFn)(void*));
    int ListBox_ItemChange_NumUnfiltered();
};

int __cdecl Tile_TextToTrait(const char* pName);
int __cdecl TruncateFloatToInt(float f);
bool __cdecl Interface_IsConsoleVisible();
void __cdecl Interface_PrintLine(const char* pFormat, ...);
void __cdecl BarterMenu_ItemSelectCallback(int aiAmountSelected);
void __cdecl QuantityMenu_Create(int aiMaxAmount, void(__cdecl* afpCallback)(int), int aiStartAmount);
void __cdecl BarterMenu_CancelConfirmFunc();
void __cdecl Interface_CreateMessageMenu(int a1, int a2, const char* pMessage, void(__cdecl* pfnCallback)(), int a5, int a6, float f7,
                          float f8, const char* pButton1, const char* pButton2, int a11);
void __cdecl BarterMenu_Close();
void __cdecl Interface_PlayMenuSound(void* pkTile);
int __cdecl BarterMenu_FilterModeFunc(void* apItem);

static const char s_szNumBartered[] = "_NumBartered";
static const char s_szOrigRef[] = "Original Container Ref: '%s' (%08x)";
static const char s_szOrigRefNone[] = "Original Container Ref: NONE";
extern const char g_szBarterClickEnd[] = "";

// @fnv 0x0072d770
// pdb: BarterMenu::DoClick | BarterMenu.obj | retail, string-set bridge, high
// pdb params: aiID, apTarget
// pdb locals: iitemCount, poriginalRef
void BarterMenu::HandleTileClick(int aiID, Tile* apTarget)
{
    if (!apTarget && aiID >= 0 && aiID < 0x16)
        apTarget = m_apTiles[aiID];
    switch (aiID)
    {
    case 23:
        if (g_pkSelectedItem_011d8fa8 && apTarget)
        {
            g_bBarterFlag_0119fdb0 = 0;
            int iCount = g_pkSelectedItem_011d8fa8->FUN_00726070() -
                         TruncateFloatToInt(apTarget->FUN_00a011b0(Tile_TextToTrait(s_szNumBartered)));
            if (Interface_IsConsoleVisible())
            {
                TESObjectREFR* pkOrig = g_pkSelectedItem_011d8fa8->Modelloader_GetReferencedThis() &&
                                        g_pkSelectedItem_011d8fa8->Modelloader_GetReferencedThis()->GetItem()
                                    ? ((BmExtraList*)g_pkSelectedItem_011d8fa8->Modelloader_GetReferencedThis()->GetItem())->ExtraDataList_GetOriginalReference()
                                    : 0;
                if (pkOrig)
                    Interface_PrintLine(s_szOrigRef, static_cast<const TESObjectREFR*>(pkOrig)->GetName(), pkOrig->GetHavokWorldObjectCountInSceneGraph_0084e3a0());
                else
                    Interface_PrintLine(s_szOrigRefNone);
            }
            else if (iCount > *g_s_011d2418.Setting_Int())
            {
                reinterpret_cast<BmPopup*>(m_pkActiveList)->FUN_007312e0();
                reinterpret_cast<BmPopup*>(m_pkActiveList)->Destroy(false);
                QuantityMenu_Create(iCount, BarterMenu_ItemSelectCallback, 0x7fffffff);
            }
            else
            {
                BarterMenu_ItemSelectCallback(1);
            }
        }
        break;
    case 13:
        g_bBarterFlag_0119fdb0 = 0;
        CompleteTransaction();
        UpdateLists(0);
        break;
    case 19:
        if (reinterpret_cast<BmItemList&>(m_kMerchantItems).FUN_005ae380() || reinterpret_cast<BmItemList&>(m_kPlayerItems).FUN_005ae380())
            Interface_CreateMessageMenu(0, 0, g_s_011d1fa4.FUN_00403df0(), BarterMenu_CancelConfirmFunc, 0, 0x17, 0.0f, 0.0f,
                         g_s_011d34f8.FUN_00403df0(), g_s_011d3684.FUN_00403df0(), 0);
        else
            BarterMenu_Close();
        break;
    case 2:
    case 3:
    case 4:
        Interface_PlayMenuSound(unkA4);
        do
        {
            m_iMerchantFilter += (aiID != 2 ? 1 : -1);
            if (m_iMerchantFilter < 0)
                m_iMerchantFilter = 5;
            else if (m_iMerchantFilter > 5)
                m_iMerchantFilter = 0;
            BarterMenu_SetFilterModeTitle((int)m_apTiles[3]);
            reinterpret_cast<BmFilteredList&>(m_kMerchantList).ApplyFilter(BarterMenu_FilterModeFunc);
        } while (!reinterpret_cast<BmFilteredList&>(m_kMerchantList).ListBox_ItemChange_NumUnfiltered() && m_iMerchantFilter != 0);
        break;
    case 7:
    case 8:
    case 9:
        Interface_PlayMenuSound(unkA4);
        do
        {
            m_iPlayerFilter += (aiID != 7 ? 1 : -1);
            if (m_iPlayerFilter < 0)
                m_iPlayerFilter = 5;
            else if (m_iPlayerFilter > 5)
                m_iPlayerFilter = 0;
            BarterMenu_SetFilterModeTitle((int)m_apTiles[8]);
            reinterpret_cast<BmFilteredList&>(m_kPlayerList).ApplyFilter(BarterMenu_FilterModeFunc);
        } while (!reinterpret_cast<BmFilteredList&>(m_kPlayerList).ListBox_ItemChange_NumUnfiltered() && m_iPlayerFilter != 0);
        break;
    }
}

namespace fnv_0072db60 {
// FUN_0072db60: thiscall, /GS, two identical formatted-label blocks.
struct SysVA
{
    void* Actor_GetGoldAmount();
};
struct SysVC
{
    void* GetCountableItemCount();
};
struct SysVB
{
    SysVC* TESDataHandler_GetBarterContainer();
};

extern SysVA* DAT_011dea3c;
extern SysVB* DAT_011c3f2c;
extern Setting DAT_011d25b0;
extern "C" int __cdecl BSsprintf(char* buf, unsigned int size, const char* fmt, ...);
extern "C" void __cdecl FUN_00ec408c();

// Stores two values from global subsystems into m_8c and m_90, then formats each with a string and passes it to m_3c and m_50 via FUN_00a01350.
// @fnv 0x0072db60
// pdb: BarterMenu::UpdateCapsLabels | BarterMenu.obj | retail, string-set bridge, high
// pdb locals: strtemp
}  // namespace fnv_0072db60

// src: XBOX_PDB 0x0072db60
void BarterMenu::UpdateCapsLabels()
{
    char buf[0x40];
    m_i8C = (int)fnv_0072db60::DAT_011dea3c->Actor_GetGoldAmount();
    m_i90 = (int)fnv_0072db60::DAT_011c3f2c->TESDataHandler_GetBarterContainer()->GetCountableItemCount();
    fnv_0072db60::BSsprintf(buf, 0x40, "%s   %d", fnv_0072db60::DAT_011d25b0.FUN_00403df0(), m_i8C);
    m_apTiles[5]->Tile_Set_00a01350(0xfc4, buf, 1);
    fnv_0072db60::BSsprintf(buf, 0x40, "%s   %d", fnv_0072db60::DAT_011d25b0.FUN_00403df0(), m_i90);
    m_apTiles[10]->Tile_Set_00a01350(0xfc4, buf, 1);
}

struct S_0072e370_Tile : Tile
{
    void Tile_Set_00a01350(int aiID, const char* apString);
};

struct S_0072e370_Item
{
    const char* GetIconFilename(int a, int b);
};

struct S_0072e370_Sub
{
    virtual void vfn0(int);
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;

    bool ContainsKey(void* a, int b);
    S_0072e370_Item* FUN_007a1910();
};

extern "C" int DAT_011d8fb8;
extern "C" unsigned char DAT_0119fdb0;
extern "C" S_0072e370_Item* DAT_011d8fa8;

void __cdecl Interface_PopulateItemStatsDisplay(S_0072e370_Item*, void*);

struct S_0072e370
{
    virtual void vfn00();
    virtual void vfn04();
    virtual void vfn08();
    virtual void vfn0C();
    virtual void vfn10(int);
    virtual void vfn14(int, int);

    Tile* tile04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    S_0072e370_Tile* tiles[22];
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    S_0072e370_Sub subA8;
    S_0072e370_Sub subD8;
    S_0072e370_Sub* unk108;

    void* FUN_00726070();
    void UpdateTileState(int aiID, void* apTarget);
};

// @fnv 0x0072e370
// pdb: BarterMenu::DoEnter | BarterMenu.obj | retail, vtable slot, high
// pdb params: aiID, apTarget
void S_0072e370::UpdateTileState(int aiID, void* apTarget)
{
    if (apTarget == 0)
    {
        if (aiID >= 0 && aiID < 22)
        {
            apTarget = this->tiles[aiID];
        }
    }

    switch (aiID)
    {
    case 0:
        this->vfn14(0x17, 0);
        this->subD8.vfn0(0);
        static_cast<Tile*>(this->FUN_00726070())->SetInt(DAT_011d8fb8, 0);
        this->unk108 = &this->subA8;
        break;

    case 1:
        this->vfn14(0x17, 0);
        this->subA8.vfn0(0);
        static_cast<Tile*>(this->FUN_00726070())->SetInt(DAT_011d8fb8, 1);
        this->unk108 = &this->subD8;
        break;

    case 23:
        DAT_0119fdb0 = 1;
        if (this->unk108 == 0)
        {
            this->vfn10(this->subD8.ContainsKey(apTarget, 0) ? 1 : 0);
        }
        DAT_011d8fa8 = this->unk108->FUN_007a1910();
        if (DAT_011d8fa8 != 0)
        {
            Interface_PopulateItemStatsDisplay(DAT_011d8fa8, this->tiles[21]);
            this->tiles[21]->SetInt(0xfa3, 1);
            this->tiles[20]->Tile_Set_00a01350(0xfcc, DAT_011d8fa8->GetIconFilename(0, 1));
            this->tiles[20]->SetInt(0xfa3, 1);
        }
        break;
    }
}

struct OwnExtraList
{
    void* ExtraDataList_GetOwner();
    void* ExtraDataList_GetGlobal();
    void* ExtraDataList_GetRank();
    short ExtraDataList_GetCount();
};

struct OwnItem
{
    BSSimpleList<OwnExtraList*>* Modelloader_GetReferencedThis();
    void* FUN_0044ddc0();
    int FUN_00726070();
    void FUN_006ecd40(int iCount);
};

struct OwnCheck
{
    char acData[0x68];
    OwnCheck();
    ~OwnCheck();
    void FUN_00567ad0(void* pkOwner);
    void TESObjectREFR_SetGlobal(void* apGlobal);
    void TESObjectREFR_SetRank(void* aiRank);
    void TESObjectREFR_SetObjectReference(void* pkForm);
    bool TESObjectREFR_IsAnOwner(TESObjectREFR* pOwner, int i);
};

extern BarterMenu* g_pkBarterMenu_011d8fa4;

// @fnv 0x0072eac0
// src: XBOX_PDB 0x0072eac0
// pdb: BarterMenu::RemoveStolenItems | BarterMenu.obj | retail, upstream name already matches, high
// pdb params: apTile, apItem
// pdb locals: pactor, removeList, pextraObj, pextra, ownedItem, premove
void __cdecl BarterMenu_RemoveStolenItems(int apTile, OwnItem* apItem)
{
    TESObjectREFR* pkMerchant_ = g_pkBarterMenu_011d8fa4->m_pkMerchant && g_pkBarterMenu_011d8fa4->m_pkMerchant->IsActor()
                                ? g_pkBarterMenu_011d8fa4->m_pkMerchant
                                : 0;
    BSSimpleList<OwnExtraList*> kRemoveY;
    for (BSSimpleList<OwnExtraList*>* pkNode = apItem->Modelloader_GetReferencedThis(); pkNode && pkNode->GetItem(); pkNode = pkNode->GetNext())
    {
        OwnExtraList* pkExtra = pkNode->GetItem();
        if (pkMerchant_ && pkExtra->ExtraDataList_GetOwner())
        {
            OwnCheck kCheck;
            kCheck.FUN_00567ad0(pkExtra->ExtraDataList_GetOwner());
            kCheck.TESObjectREFR_SetGlobal(pkExtra->ExtraDataList_GetGlobal());
            kCheck.TESObjectREFR_SetRank(pkExtra->ExtraDataList_GetRank());
            kCheck.TESObjectREFR_SetObjectReference(apItem->FUN_0044ddc0());
            if (kCheck.TESObjectREFR_IsAnOwner(pkMerchant_, 1))
                kRemoveY.AddTail(pkExtra);
        }
    }
    for (BSSimpleList<OwnExtraList*>* pkIter = &kRemoveY; pkIter && pkIter->GetItem(); pkIter = pkIter->GetNext())
    {
        apItem->FUN_006ecd40(apItem->FUN_00726070() - (pkIter->GetItem())->ExtraDataList_GetCount());
        apItem->Modelloader_GetReferencedThis()->Remove(pkIter->GetItem());
    }
    kRemoveY.RemoveAll();
}

struct S_0072ed00_List
{
    int unk00;
    bool ContainsKey(Tile* a);
};

struct S_0072ed00_Item : InventoryStackRecord
{
    float FUN_004bd400();
};
extern int DAT_011d8fb4;
void __cdecl FUN_005e58f0(int type, PlayerCharacter* actor, ...);
int __cdecl FUN_00ec7d40(int);
float __cdecl BSMAX_00404010(float, float);
float __cdecl BSMIN(float, float);
float __cdecl fabsf_00408860(float);
float __cdecl FUN_004bd510(float, float);

// @fnv 0x0072ed00
// src: XBOX_PDB 0x0072ed00
// pdb: BarterMenu::GetSortValue | BarterMenu.obj | retail, upstream name already matches, high
// pdb params: apTile, apItem
// pdb locals: freturnVal, fsortValue, forigValue, bisBarterSelected, binVendorList, bNoBarter
float __cdecl BarterMenu_GetSortValue(Tile* apTile, S_0072ed00_Item* apItem)
{
    float amount = apItem->FUN_004bd400();
    float base = amount;
    bool b5 = reinterpret_cast<S_0072ed00_List&>(((BarterMenu*)DAT_011d8fa4)->m_kPlayerList).ContainsKey(apTile);
    bool b8 = apTile->IsTraitNonZero(DAT_011d8fb4);
    float result = 0.0f;
    if (amount < 0.0)
    {
        result = -1.0f;
    }
    else if ((b5 && !b8) || (!b5 && b8))
    {
        bool isEquip = apItem->FUN_0044ddc0()->FUN_00401170() == 0x6c || apItem->FUN_0044ddc0()->FUN_00401170() == 0x74;
        amount *= isEquip ? 1.0f : ((BarterMenu*)DAT_011d8fa4)->unk94;
        if (((BarterMenu*)DAT_011d8fa4)->unk88 > 0)
        {
            amount = (1.0 - FUN_00ec7d40(((BarterMenu*)DAT_011d8fa4)->unk88) / 100.0) * amount;
        }
        else if (((BarterMenu*)DAT_011d8fa4)->unk88 < 0)
        {
            amount = (FUN_00ec7d40(((BarterMenu*)DAT_011d8fa4)->unk88) / 100.0 + 1.0) * amount;
        }
        FUN_005e58f0(0x11, g_thePlayer, apItem->FUN_0044ddc0(), &amount);
        if (fabsf_00408860(amount) > 1.0)
            amount = FUN_004bd510(amount, 1.0f);
        else
            amount = FUN_004bd510(amount, 0.1f);
        result = BSMAX_00404010(amount, base);
    }
    else if ((b5 && b8) || (!b5 && !b8))
    {
        bool isEquip = apItem->FUN_0044ddc0()->FUN_00401170() == 0x6c || apItem->FUN_0044ddc0()->FUN_00401170() == 0x74;
        amount *= isEquip ? 1.0f : ((BarterMenu*)DAT_011d8fa4)->unk98;
        if (((BarterMenu*)DAT_011d8fa4)->unk88 > 0)
        {
            amount = (FUN_00ec7d40(((BarterMenu*)DAT_011d8fa4)->unk88) / 100.0 + 1.0) * amount;
        }
        else if (((BarterMenu*)DAT_011d8fa4)->unk88 < 0)
        {
            amount = (1.0 - FUN_00ec7d40(((BarterMenu*)DAT_011d8fa4)->unk88) / 100.0) * amount;
        }
        if (fabsf_00408860(amount) > 1.0)
            amount = FUN_004bd510(amount, 1.0f);
        else
            amount = FUN_004bd510(amount, 0.1f);
        result = BSMIN(amount, base);
    }
    return result;
}

// Walks the linked list and returns the first entry whose FUN_0044ddc0 value and FUN_00559450 sub-node value both match the target's.
// @fnv 0x0072f120
// pdb: BarterMenu::GetTransactItem | BarterMenu.obj | debug, object-file gap fill, medium
// pdb params: apItemList, apCompareItem
// pdb locals: pfoundItem, pcurrItemRef, pcurrItem, pcurrItemExtra, paddItemExtra
InventoryStackRecord* BarterMenu::FindMatchingEntry(BSSimpleList<InventoryStackRecord*>* head, InventoryStackRecord* target)
{
    InventoryStackRecord* result2 = 0;
    for (BSSimpleList<InventoryStackRecord*>* node2 = head; !result2 && node2 && node2->GetItem(); node2 = node2->GetNext())
    {
        InventoryStackRecord* item5 = node2->GetItem();
        if (target->FUN_0044ddc0() == item5->FUN_0044ddc0())
        {
            void* local7 = target->Modelloader_GetReferencedThis() ? target->Modelloader_GetReferencedThis()->GetItem() : 0;
            void* local_14 = item5->Modelloader_GetReferencedThis() ? item5->Modelloader_GetReferencedThis()->GetItem() : 0;
            if (local7 == local_14)
            {
                result2 = item5;
            }
        }
    }
    return result2;
}

namespace fnv_0072f210 {

struct BarterTile
{
    bool IsTraitNonZero(int m_uiSoundID);
    void FUN_00700320(int m_uiSoundID, int iValue);
    void Tile_Set_00a01350(int m_uiSoundID, const char* apString, bool bPropagate);
    void FUN_00707e10(const char* pName);
    void Tile_Set(int m_uiSoundID, float fValue, bool bPropagate);
};

extern BarterMenu* g_pkBarterMenu_011d8fa4;
extern int g_iTileIDEquipped_011d8fb4;
extern int g_iTileIDValue_011d8fb0;

float __cdecl BarterMenu_GetSortValue(BarterTile* apTile, InventoryStackRecord* apItem);
int __cdecl Tile_TextToTrait(const char* pName);
int __cdecl Tile_AddUserTrait(const char* pName, int iDefault);
int __cdecl BSsprintf(char* pBuffer, unsigned int uiSize, const char* pFormat, ...);
int __cdecl FUN_00406d30(char* pBuffer, unsigned int uiSize, const char* pSrc);

static const char s_szNumBartered[] = "_NumBartered";
static const char s_szCountFormat[] = "%s (%d)";
static const char s_szIsEquipped[] = "_IsEquipped";
static const char s_szNoValue[] = "--";
static const char s_szValueFormat1[] = "%.1f";
static const char s_szValueFormat0[] = "%.0f";
extern const char g_szBarterTileEnd[] = "";

// @fnv 0x0072f210
// src: XBOX_RETAIL_PDB 0x0072f210
// pdb: BarterMenu::InitFunc | BarterMenu.obj | retail, string-set bridge, high
// pdb params: apTile, apItem
// pdb locals: iitemCount, fsortValue, strtemp, ptransactItem
void __cdecl BarterMenu_InitFunc(BarterTile* apTile, InventoryStackRecord* apItem)
{
    char acBuffer[0x80];
    float fValue = BarterMenu_GetSortValue(apTile, apItem);
    int iCount = 0;
    if (!apTile->IsTraitNonZero(g_iTileIDEquipped_011d8fb4))
    {
        InventoryStackRecord* pkOther =
            g_pkBarterMenu_011d8fa4->FindMatchingEntry(&g_pkBarterMenu_011d8fa4->m_kMerchantItems, apItem);
        if (!pkOther)
            pkOther = g_pkBarterMenu_011d8fa4->FindMatchingEntry(&g_pkBarterMenu_011d8fa4->m_kPlayerItems, apItem);
        iCount = apItem->FUN_00726070() - (pkOther ? pkOther->FUN_00726070() : 0);
        apTile->FUN_00700320(Tile_TextToTrait(s_szNumBartered), pkOther ? pkOther->FUN_00726070() : 0);
    }
    else
    {
        iCount = apItem->FUN_00726070();
    }
    if (iCount > 1)
    {
        BSsprintf(acBuffer, 0x80, s_szCountFormat, apItem->GetFullName(), iCount);
        apTile->Tile_Set_00a01350(0xfc4, acBuffer, true);
    }
    if (apItem->ItemChange_GetWorn(0) && !apTile->IsTraitNonZero(g_iTileIDEquipped_011d8fb4))
        apTile->FUN_00700320(Tile_AddUserTrait(s_szIsEquipped, -1), 1);
    if (fValue <= 0.0)
        FUN_00406d30(acBuffer, 0x80, s_szNoValue);
    else if (fValue > 0.0 && fValue < 1.0)
        BSsprintf(acBuffer, 0x80, s_szValueFormat1, fValue);
    else
        BSsprintf(acBuffer, 0x80, s_szValueFormat0, fValue);
    apTile->Tile_Set_00a01350(g_iTileIDValue_011d8fb0, acBuffer, true);
    apTile->FUN_00707e10((const char*)apItem->GetFullName());
    apTile->Tile_Set(0xfb0, 0.0f, true);
}
}  // namespace fnv_0072f210

// HandleAction candidate
bool __cdecl Interface_IsTopMenuID(int aiId);

struct FUN_007312e0_shell
{
    void FUN_007312e0();
};
struct FUN_00731360_shell
{
    void UpdateCurrentValueTile(int abPlayFocusSound);
};
struct FUN_00730e20_shell
{
    bool ListBox_ItemChange_IsEnabled();
};
struct FUN_00726c40_shell
{
    unsigned int GetRaceCount();
};

// @fnv 0x0072f4b0
// pdb: BarterMenu::DoGamepad | BarterMenu.obj | retail, vtable slot, high
// pdb params: aiButton, afValue
// pdb locals: bresult
bool BarterMenu::HandleAction(int aiButton, int afValue)
{
    bool bHandled = false;
    if (Interface_IsTopMenuID(0x41d))
    {
        switch (aiButton)
        {
        case 13:
            if (!reinterpret_cast<FUN_00730e20_shell*>(&m_kMerchantList)->ListBox_ItemChange_IsEnabled())
            {
                if (reinterpret_cast<FUN_00726c40_shell*>(&m_kMerchantList)->GetRaceCount() > 0)
                {
                    reinterpret_cast<FUN_007312e0_shell*>(&m_kPlayerList)->FUN_007312e0();
                    HandleMouseover(0, 0);
                    reinterpret_cast<FUN_00731360_shell*>(&m_kMerchantList)->UpdateCurrentValueTile(1);
                    bHandled = true;
                }
            }
            break;
        case 14:
            if (!reinterpret_cast<FUN_00730e20_shell*>(&m_kPlayerList)->ListBox_ItemChange_IsEnabled())
            {
                if (reinterpret_cast<FUN_00726c40_shell*>(&m_kPlayerList)->GetRaceCount() > 0)
                {
                    reinterpret_cast<FUN_007312e0_shell*>(&m_kMerchantList)->FUN_007312e0();
                    HandleMouseover(1, 0);
                    reinterpret_cast<FUN_00731360_shell*>(&m_kPlayerList)->UpdateCurrentValueTile(1);
                    bHandled = true;
                }
            }
            break;
        case 3:
        case 4:
            if (m_pkActiveList == &m_kMerchantList)
            {
                reinterpret_cast<FUN_007312e0_shell*>(&m_kMerchantList)->FUN_007312e0();
                HandleSelection((aiButton != 4) ? 4 : 2, 0);
                reinterpret_cast<FUN_00731360_shell*>(&m_kMerchantList)->UpdateCurrentValueTile(0);
            }
            else
            {
                reinterpret_cast<FUN_007312e0_shell*>(&m_kPlayerList)->FUN_007312e0();
                HandleSelection((aiButton != 4) ? 9 : 7, 0);
                reinterpret_cast<FUN_00731360_shell*>(&m_kPlayerList)->UpdateCurrentValueTile(0);
            }
            bHandled = true;
            break;
        }
    }
    return bHandled;
}

namespace fnv_0072f6f0 {

extern InventoryStackRecord* g_pkSelectedItem_011d8fa8;

struct QtyItemList
{
    Tile* FindItemData(InventoryStackRecord** ppkItem);
};

struct QtyPlayer
{
    void PlayActorSound(TESBoundObject* apobjREFR, bool abPickUp, int abUse);
};
extern QtyPlayer* g_thePlayer_011dea3c;

extern BarterMenu* g_pkBarterMenu_011d8fa4;
extern int g_iTileIDEquipped_011d8fb4;
extern int g_iTileIDValue_011d8fb0;
extern int g_iTileIDState_011d8fbc;

float __cdecl BarterMenu_GetSortValue(Tile* apTile, InventoryStackRecord* apItem);
float __cdecl floorf(float _X);
int __cdecl TruncateFloatToInt(float f);
int __cdecl MinInt(int a, int b);
int __cdecl BSAbs(int alValue);
int __cdecl BSsprintf(char* pBuffer, unsigned int uiSize, const char* pFormat, ...);

static const char s_szIntFormat[] = "%d";
extern const char g_szBarterQtyEnd[] = "";

// @fnv 0x0072f6f0
// src: XBOX_RETAIL_PDB 0x0072f6f0
// pdb: BarterMenu::ItemSelectCallback | BarterMenu.obj | retail, call graph, high
// pdb params: aiAmountSelected
// pdb locals: pcurrTile, iwholeAmount, strtemp
void __cdecl BarterMenu_ItemSelectCallback(int aiAmountSelected)
{
    Tile* pkTile = reinterpret_cast<QtyItemList*>(g_pkBarterMenu_011d8fa4->m_pkActiveList)->FindItemData(&g_pkSelectedItem_011d8fa8);
    if (!aiAmountSelected || !g_pkSelectedItem_011d8fa8 || !pkTile)
        return;
    g_pkBarterMenu_011d8fa4->m_fBarterTotal +=
        BarterMenu_GetSortValue(pkTile, g_pkSelectedItem_011d8fa8) *
        (g_pkBarterMenu_011d8fa4->m_pkActiveList == &g_pkBarterMenu_011d8fa4->m_kMerchantList ? 1 : -1) * aiAmountSelected;
    g_thePlayer_011dea3c->PlayActorSound(
        g_pkSelectedItem_011d8fa8->FUN_0044ddc0(),
        g_pkBarterMenu_011d8fa4->m_pkActiveList == &g_pkBarterMenu_011d8fa4->m_kPlayerList, 0);
    if (pkTile->IsTraitNonZero(g_iTileIDEquipped_011d8fb4))
        g_pkBarterMenu_011d8fa4->DecrementEntryCount(aiAmountSelected);
    else
        g_pkBarterMenu_011d8fa4->AddOrUpdateEntryCount(aiAmountSelected);
    g_pkBarterMenu_011d8fa4->UpdateLists(g_pkSelectedItem_011d8fa8->FUN_0044ddc0());
    if (!g_pkBarterMenu_011d8fa4->m_kMerchantItems.IsEmpty() ||
        !g_pkBarterMenu_011d8fa4->m_kPlayerItems.IsEmpty())
    {
        char acBufferTmp[0x10];
        int iCaps_2 = TruncateFloatToInt(floorf(g_pkBarterMenu_011d8fa4->m_fBarterTotal));
        g_pkBarterMenu_011d8fa4->FUN_00726070()->FUN_00700320(g_iTileIDState_011d8fbc,
                                                              g_pkBarterMenu_011d8fa4->m_fBarterTotal > 0.0 ? 2 : 1);
        BSsprintf(acBufferTmp, 0x10, s_szIntFormat, BSAbs(MinInt(iCaps_2, g_pkBarterMenu_011d8fa4->unk90)));
        g_pkBarterMenu_011d8fa4->m_apTiles[12]->Tile_Set_00a01350(g_iTileIDValue_011d8fb0, acBufferTmp, true);
        g_pkBarterMenu_011d8fa4->m_apTiles[12]->FUN_00700320(0xfa3, 1);
        if (g_pkBarterMenu_011d8fa4->m_fBarterTotal > 0.0 ||
            (g_pkBarterMenu_011d8fa4->m_fBarterTotal <= 0.0 &&
             g_pkBarterMenu_011d8fa4->m_iMerchantCaps >= -g_pkBarterMenu_011d8fa4->m_fBarterTotal))
        {
            g_pkBarterMenu_011d8fa4->m_apTiles[13]->FUN_00700320(0xfaf, 1);
            if (g_pkBarterMenu_011d8fa4->m_fBarterTotal > 0.0 &&
                g_pkBarterMenu_011d8fa4->m_fBarterTotal > g_pkBarterMenu_011d8fa4->unk90)
                g_pkBarterMenu_011d8fa4->m_apTiles[12]->Tile_Set(0xfa9, 64.0f, true);
            else
                g_pkBarterMenu_011d8fa4->m_apTiles[12]->Tile_Set(0xfa9, 255.0f, true);
        }
        else
        {
            g_pkBarterMenu_011d8fa4->m_apTiles[13]->FUN_00700320(0xfaf, 0);
            g_pkBarterMenu_011d8fa4->m_apTiles[12]->Tile_Set(0xfa9, 64.0f, true);
        }
    }
    else
    {
        g_pkBarterMenu_011d8fa4->m_apTiles[13]->FUN_00700320(0xfaf, 0);
        g_pkBarterMenu_011d8fa4->m_apTiles[12]->FUN_00700320(0xfa3, 0);
    }
}
}  // namespace fnv_0072f6f0

struct FC30Data
{
    int* GetValuePtr();
};

struct FC30Entry
{
    ~FC30Entry();

    FC30Data* GetData();
    int GetCount();
    void SetCount(int iCount);
};

extern void* g_FC30Key;

// @fnv 0x0072fc30
// pdb: BarterMenu::RemoveTransactItem | BarterMenu.obj | debug, object-file gap fill, medium
// pdb params: aiAmountSelected
// pdb locals: ptransactItem, ptransactList, ptransactExtra
void BarterMenu::DecrementEntryCount(int iCount)
{
    int iValue;
    BSSimpleList<InventoryStackRecord*>* pkListA = (m_pkActiveList == &m_kMerchantList) ? &m_kMerchantItems : &m_kPlayerItems;
    FC30Entry* pkEntry = reinterpret_cast<FC30Entry*>(FindEntry(pkListA, g_FC30Key));
    iValue = pkEntry->GetData() ? *pkEntry->GetData()->GetValuePtr() : 0;
    if (pkEntry->GetCount() - iCount <= 0)
    {
        pkListA->Remove(reinterpret_cast<InventoryStackRecord* const&>(pkEntry));
        delete pkEntry;
    }
    else
    {
        pkEntry->SetCount(pkEntry->GetCount() - iCount);
    }
}

struct LbTile
{
    float FUN_00a011b0(int m_uiSoundID);
    void FUN_00700320(int m_uiSoundID, int iValue);
    void FUN_00715c60(int aiTrait, int aiValue);
};
int __cdecl Tile_AddUserTrait(const char* pcName, int iDefault);

struct LbItem
{
    LbTile* m_pkTile;
    void* m_pPointer;
    bool m_bFiltered;
};

static const char s_szNumFiltered[] = "_num_filtered";
extern const char g_szListBoxEnd[] = "";

struct ListBoxImpl : ListBoxBase, BSSimpleList<LbItem*>
{
    LbTile* m_pkParentTile;
    LbTile* m_pkSelected;
    int unk14;
    int unk18;
    unsigned short m_usElementCount;
    float m_fScroll;

    void AccumulateTileHeight(LbTile* apNewTile);
    void UpdateScrollPages();
    LbTile* ListBox_ItemChange_GetLastItem();
    void ListBox_ItemChange_UpdateHighlightBoxPos();
    void ApplyFilter(bool(__cdecl* apFilterFn)(void* pkObject));
};

// Marks each item as filtered by pfnFilter, renumbers the visible tiles, updates the filtered count, and restores the selection.
// @fnv 0x00730bb0
// pdb: ListBox<ItemChange *>::Filter | BarterMenu.obj | retail, call graph, high
// pdb params: apFilterFn
// pdb locals: isaveHLIndex, uifilterCount, pnode
void ListBoxImpl::ApplyFilter(bool(__cdecl* apFilterFn)(void* pkObject))
{
    int iFilteredCount = 0;
    int iSelectedIndex = -1;
    static int s_iNumFilteredID = Tile_AddUserTrait(s_szNumFiltered, -1);
    m_usElementCount = 0;
    m_fScroll = 0.0f;
    for (BSSimpleList<LbItem*>* pkNode = this; pkNode && pkNode->GetItem(); pkNode = pkNode->GetNext())
    {
        (pkNode->GetItem())->m_bFiltered = apFilterFn && apFilterFn((pkNode->GetItem())->m_pPointer) ? 1 : 0;
        if ((pkNode->GetItem())->m_bFiltered)
        {
            if ((pkNode->GetItem())->m_pkTile == m_pkSelected)
            {
                iSelectedIndex = (int)(pkNode->GetItem())->m_pkTile->FUN_00a011b0(0xfac);
                m_pkSelected = 0;
            }
            (pkNode->GetItem())->m_pkTile->FUN_00700320(0xfac, -1);
            iFilteredCount++;
        }
        else
        {
            if (iSelectedIndex >= 0 && m_usElementCount == iSelectedIndex)
                m_pkSelected = (pkNode->GetItem())->m_pkTile;
            (pkNode->GetItem())->m_pkTile->FUN_00700320(0xfac, m_usElementCount++);
            AccumulateTileHeight((pkNode->GetItem())->m_pkTile);
        }
    }
    m_pkParentTile->FUN_00715c60(s_iNumFilteredID, iFilteredCount);
    UpdateScrollPages();
    if (!m_pkSelected && iSelectedIndex >= 0)
        m_pkSelected = reinterpret_cast<LbTile*>(GetTileAt(iSelectedIndex, 0));
    if (!m_pkSelected && iSelectedIndex >= 0)
        m_pkSelected = ListBox_ItemChange_GetLastItem();
    ListBox_ItemChange_UpdateHighlightBoxPos();
}

int __cdecl C72CEB0GetTraitID(const char* pcName);

extern const char g_ac72CEB0Trait0[];
extern const char g_ac72CEB0Trait1[];
extern const char g_ac72CEB0Trait2[];
extern const char g_ac72CEB0Trait3[];
extern const char g_ac72CEB0Trait4[];

extern int g_i72CEB0Trait0;
extern int g_i72CEB0Trait1;
extern int g_i72CEB0Trait2;
extern int g_i72CEB0Trait3;
extern int g_i72CEB0Trait4;
extern int g_i72CEB0Selected;

// @fnv 0x0072ceb0
// pdb: BarterMenu::BarterMenu | BarterMenu.obj | retail, string-set bridge, high
BarterMenu::BarterMenu()
{
    g_i72CEB0Trait0 = C72CEB0GetTraitID(g_ac72CEB0Trait0);
    g_i72CEB0Trait1 = C72CEB0GetTraitID(g_ac72CEB0Trait1);
    g_i72CEB0Trait2 = C72CEB0GetTraitID(g_ac72CEB0Trait2);
    g_i72CEB0Trait3 = C72CEB0GetTraitID(g_ac72CEB0Trait3);
    g_i72CEB0Trait4 = C72CEB0GetTraitID(g_ac72CEB0Trait4);
    g_i72CEB0Selected = 0;
    m_pkActiveList = 0;
    m_i8C = 0;
    m_i90 = 0;
    m_f94 = 1.0f;
    m_f98 = 1.0f;
    m_b11C = false;
    m_i9C = 0;
    m_iA0 = 0;
    m_iA4 = 3;
}

struct ListObj
{
    virtual void vtbl000();
    virtual int PredHead();
    virtual void vtbl002();
    virtual void vtbl003();
    virtual void vtbl004();
    virtual void vtbl005();
    virtual void vtbl006();
    virtual void vtbl007();
    virtual void Virt20(void* fn);
    void* m_04;
    void* m_08;
    void* m_0c;
    void* m_10;
    void* m_14;
    void* m_18;
    void* m_1c;
    void* m_20;
    void* m_24;
    void* m_28;
    void* m_2c;
    void ListBox_ItemChange_RemoveItemGroup(int a);
    int ListBox_ItemChange_AddItem(void* aAssociatedData, const char* apcItemString, int apCompareFn, int apcTemplateName);
    void PopulateInventoryList(void* a, void* fn, int b, int c, int d, int e);
    void ListBox_ItemChange_Traverse(void* fn, int a, int b);
    void ApplyFilter(void* apFilterFn);
    unsigned int ListBox_ItemChange_NumUnfiltered();
    void UpdateCurrentValueTile(int abPlayFocusSound);
    void FUN_007312e0();
    void* CallVirtualZero(int a, int b);
};

struct DataSource
{
    void InventoryChanges_GetItemGroup(int apObj, BSSimpleList<InventoryStackRecord*>* apReturnList);
};
struct DataHandler
{
    void* TESDataHandler_GetBarterContainer();
    void UpdateInventoryForReference(void* apVendor);
};

extern DataHandler* g_dataHandler;
extern PlayerCharacter* g_thePlayer;
extern int DAT_011d8fb4;
void* __cdecl FUN_004bf220(void* a);
bool __cdecl BarterMenu_VendorFirstPassFilterFunc(InventoryStackRecord* apItem);
unsigned char __cdecl InterfaceManager_Has360Controller();
void* __cdecl InterfaceManager_GetSingleton();
void __cdecl AddHeadImpl(void* list, void** pp);
void __cdecl BarterMenu_InitFunc();
void __cdecl CompareF070Entries();
struct IMObj
{
    void InterfaceManager_SetCurrentFocusTarget(void* apTarget);
};

// Rebuilds the m_a8/m_d8 lists from the player and data handler for the given form, then selects and activates m_108 and calls FUN_0072db60.
// @fnv 0x0072dc30
// src: XBOX_RETAIL_PDB 0x0072dc30
// pdb: BarterMenu::UpdateLists | BarterMenu.obj | retail, call graph (shared callers), high
// pdb params: apUpdateObj
// pdb locals: pnewHighlight, pnewItemGroup, pplayerInventory, pvendorInventory, pcurrItemObj, pcurrBuyItemRef, pnewExtra, pnewItem, pnewTile, pcurrSellItemRef
void __thiscall BarterMenu::UpdateLists(int apUpdateObj)
{
    long i = 0;
    if (reinterpret_cast<ListObj*>(m_pkActiveList) != 0)
    {
        if (reinterpret_cast<ListObj*>(m_pkActiveList)->PredHead())
        {
            reinterpret_cast<ListObj*>(m_pkActiveList)->FUN_007312e0();
        }
    }
    if (apUpdateObj != 0)
    {
        BSSimpleList<InventoryStackRecord*> b;
        void* n;
        n = FUN_004bf220((void*)g_thePlayer);
        void* res = g_dataHandler->TESDataHandler_GetBarterContainer();
        if (n != 0)
        {
            ((DataSource*)n)->InventoryChanges_GetItemGroup(apUpdateObj, &b);
            reinterpret_cast<ListObj&>(m_kMerchantList).ListBox_ItemChange_RemoveItemGroup(apUpdateObj);
            BSSimpleList<InventoryStackRecord*>* kZero = (BSSimpleList<InventoryStackRecord*>*)&b;
            for (; kZero != 0 && kZero->GetItem() != 0; kZero = kZero->GetNext())
            {
                if (!(bool)BarterMenu_PlayerFirstPassFilterFunc((InventoryStackRecord*)kZero->GetItem()))
                {
                    reinterpret_cast<ListObj&>(m_kMerchantList).ListBox_ItemChange_AddItem(kZero->GetItem(), (const char*)(kZero->GetItem())->GetFullName(), 0, 0);
                }
                else
                {
                    delete kZero->GetItem();
                }
            }
            b.RemoveAll();
        }
        if (res != 0)
        {
            ((DataSource*)res)->InventoryChanges_GetItemGroup(apUpdateObj, &b);
            reinterpret_cast<ListObj&>(m_kPlayerList).ListBox_ItemChange_RemoveItemGroup(apUpdateObj);
            BSSimpleList<InventoryStackRecord*>* kZero;
            kZero = (BSSimpleList<InventoryStackRecord*>*)&b;
            for (; kZero != 0 && kZero->GetItem() != 0; kZero = kZero->GetNext())
            {
                if (!(bool)BarterMenu_VendorFirstPassFilterFunc(kZero->GetItem()))
                {
                    reinterpret_cast<ListObj&>(m_kPlayerList).ListBox_ItemChange_AddItem(kZero->GetItem(), (const char*)(kZero->GetItem())->GetFullName(), 0, 0);
                }
                else
                {
                    delete kZero->GetItem();
                }
            }
            b.RemoveAll();
        }
    }
    else
    {
        g_dataHandler->UpdateInventoryForReference(m_pkMerchant);
        reinterpret_cast<ListObj&>(m_kMerchantList).PopulateInventoryList((void*)g_thePlayer, (void*)::BarterMenu_PlayerFirstPassFilterFunc, 0, 0, 0, 0);
        reinterpret_cast<ListObj&>(m_kPlayerList).PopulateInventoryList(m_pkMerchant, (void*)BarterMenu_VendorFirstPassFilterFunc, 0, 0, 0, 1);
    }
    {
        BSSimpleList<InventoryStackRecord*>* kZero;
        kZero = reinterpret_cast<BSSimpleList<InventoryStackRecord*>*>(&m_kMerchantItems);
        for (; kZero != 0 && kZero->GetItem() != 0; kZero = kZero->GetNext())
        {
            if (apUpdateObj == 0 || (kZero->GetItem())->FUN_0044ddc0() == (void*)apUpdateObj)
            {
                int tmp;
                InventoryStackRecord* r =
                    new InventoryStackRecord((kZero->GetItem())->FUN_0044ddc0(), (int)(kZero->GetItem())->FUN_00726070());
                void* _tempExtra;
                _tempExtra = (kZero->GetItem())->Modelloader_GetReferencedThis()
                                 ? (kZero->GetItem())->Modelloader_GetReferencedThis()->GetItem()
                                 : 0;
                tmp = 0;
                if (0 != _tempExtra)
                {
                    r->Modelloader_GetReferencedThis()->AddTail(reinterpret_cast<ExtraDataList* const&>(_tempExtra));
                }
                tmp = reinterpret_cast<ListObj&>(m_kMerchantList).ListBox_ItemChange_AddItem(r, (const char*)r->GetFullName(), 0, 0);
                ((Tile*)tmp)->FUN_00700320(DAT_011d8fb4, 1);
            }
        }
    }
    {
        BSSimpleList<InventoryStackRecord*>* kZero;
        kZero = reinterpret_cast<BSSimpleList<InventoryStackRecord*>*>(&m_kPlayerItems);
        for (; kZero != 0 && kZero->GetItem() != 0; kZero = kZero->GetNext())
        {
            if (apUpdateObj == 0 || (kZero->GetItem())->FUN_0044ddc0() == (void*)apUpdateObj)
            {
                long tmp;
                InventoryStackRecord* r;
                void* _tempExtra;
                r = new InventoryStackRecord((kZero->GetItem())->FUN_0044ddc0(), (int)(kZero->GetItem())->FUN_00726070());
                _tempExtra = (kZero->GetItem())->Modelloader_GetReferencedThis()
                                 ? (kZero->GetItem())->Modelloader_GetReferencedThis()->GetItem()
                                 : 0;
                tmp = 0;
                if (_tempExtra != 0)
                {
                    r->Modelloader_GetReferencedThis()->AddTail(reinterpret_cast<ExtraDataList* const&>(_tempExtra));
                }
                tmp = reinterpret_cast<ListObj&>(m_kPlayerList).ListBox_ItemChange_AddItem(r, (const char*)r->GetFullName(), 0, 0);
                ((Tile*)tmp)->FUN_00700320(DAT_011d8fb4, 1);
            }
        }
    }
    reinterpret_cast<ListObj&>(m_kMerchantList).ListBox_ItemChange_Traverse((void*)BarterMenu_RemoveStolenItems, 0, 0x7fffffff);
    reinterpret_cast<ListObj&>(m_kMerchantList).ListBox_ItemChange_Traverse((void*)BarterMenu_InitFunc, 0, 0x7fffffff);
    reinterpret_cast<ListObj&>(m_kMerchantList).ApplyFilter((void*)BarterMenu_FilterModeFunc);
    reinterpret_cast<ListObj&>(m_kMerchantList).Virt20((void*)CompareF070Entries);
    reinterpret_cast<ListObj&>(m_kPlayerList).ListBox_ItemChange_Traverse((void*)BarterMenu_InitFunc, 0, 0x7fffffff);
    reinterpret_cast<ListObj&>(m_kPlayerList).ApplyFilter((void*)BarterMenu_FilterModeFunc);
    reinterpret_cast<ListObj&>(m_kPlayerList).Virt20((void*)CompareF070Entries);
    if (0 == reinterpret_cast<ListObj*>(m_pkActiveList))
    {
        if (InterfaceManager_Has360Controller())
        {
            m_pkActiveList = &m_kPlayerList;
        }
    }
    if (0 != reinterpret_cast<ListObj*>(m_pkActiveList))
    {
        if (reinterpret_cast<ListObj*>(m_pkActiveList)->ListBox_ItemChange_NumUnfiltered() > 0)
        {
            reinterpret_cast<ListObj*>(m_pkActiveList)->UpdateCurrentValueTile(1);
        }
        else
        {
            m_iA4 = -1;
            HandleSelection((m_pkActiveList == &m_kMerchantList) ? 4 : 9, 0);
            m_iA4 = 3;
            if (reinterpret_cast<ListObj*>(m_pkActiveList)->ListBox_ItemChange_NumUnfiltered() > 0)
            {
                reinterpret_cast<ListObj*>(m_pkActiveList)->UpdateCurrentValueTile(1);
            }
            else
            {
                HandleMouseover((m_pkActiveList == &m_kMerchantList) ? 1 : 0, 0);
                if (InterfaceManager_Has360Controller())
                {
                    ((IMObj*)InterfaceManager_GetSingleton())->InterfaceManager_SetCurrentFocusTarget(reinterpret_cast<ListObj*>(m_pkActiveList)->CallVirtualZero(0xfc3, 1));
                }
            }
        }
    }
    UpdateCapsLabels();
}

// List sort comparator: entries whose tile has the highlight trait come first, then order by tile text.

int __cdecl _mbscmp(const unsigned char* _s1, const unsigned char* _s2);

extern int g_iF070HighlightTrait;

struct F070Entry
{
    Tile* m_pkTile;
    void* m_pvItem;
};

// Compares two entries by the highlight trait first, then by the string from trait 0xfc4, returning -1, 1 or the string comparison result.
// @fnv 0x0072f070
// pdb: BarterMenu::AddTransactItem | BarterMenu.obj | retail, object-file run extension, low
// pdb note: debug build links it to BarterMenu::SortFunc
// pdb params: aiAmountSelected
// pdb locals: ptransactItem, ptransactList, ptransactExtra, pextra
int CompareF070Entries(F070Entry* pkA, F070Entry* pkB)
{
    void* pvItemA = pkA->m_pvItem;
    void* pvDataB = pkB->m_pvItem;
    int iResult = 0;
    bool bHighlightA = pkA->m_pkTile->IsTraitNonZero(g_iF070HighlightTrait);
    bool bB = pkB->m_pkTile->IsTraitNonZero(g_iF070HighlightTrait);
    if (bHighlightA && !bB)
        iResult = -1;
    else if (!bHighlightA && bB)
        iResult = 1;
    else
        iResult = _mbscmp((const unsigned char*)pkA->m_pkTile->GetString(0xfc4),
                          (const unsigned char*)pkB->m_pkTile->GetString(0xfc4));
    return iResult;
}

namespace fnv_0072fd10 {

extern PlayerCharacter* g_player_011dea3c;

struct TESQuestStageList
{
    TESObjectREFR* ExtraDataList_GetMerchantContainer();
};

struct ItemTransferManager
{
    void TESDataHandler_RemoveItemBarterContainer(InventoryStackRecord* apitem, int aiNumber, TESObjectREFR* apVendor);
};
extern ItemTransferManager* g_transferMgr_011c3f2c;

bool __cdecl Script_SetActionFlag(TESObjectREFR* apRef, ExtraDataList* apExtraList, unsigned int auiFlags);
float __cdecl floorf(float _X);
int __cdecl TruncateFloatToInt(float afValue);
extern "C" const char* __cdecl FUN_00ec7d40(int aiValue);
void __cdecl FUN_004d5e10(int aiID, const char* apText);
extern "C" TESBoundObject* __cdecl TESForm_GetFormByNumericID(unsigned int auiFormID);
int __cdecl MinInt(int aiValue, int aiValue2);

// Transfers merchant and player barter items, adjusts caps based on m_barterTotal, plays a sound, resets totals and clears the equipped weapon if it was sold.
// @fnv 0x0072fd10
// src: XBOX_RETAIL_PDB 0x0072fd10
// pdb: BarterMenu::CompleteTransaction | BarterMenu.obj | retail, string-set bridge, high
// pdb locals: pinventory, iwholeAmount, pammo, pvendorContainer, pcurrBuyItemRef, pbuyItem, pbuyExtra, pcurrSellItemRef, psellItem, psellExtra, tempGold
}  // namespace fnv_0072fd10

// The shared audio factory still returns a legacy handle type. Use its entry point
// with the real handle return type and retain this unit's original no-argument Play call.
typedef BSSoundHandle (BSAudio::*BarterSoundFactory)(const char*, unsigned int, bool);
typedef bool (BSSoundHandle::*BarterSoundPlay)();

void BarterMenu::CompleteTransaction()
{
    TESObjectREFR* pTarget3 =
        reinterpret_cast<fnv_0072fd10::TESQuestStageList*>(m_merchant->BSFile_GetDevice())->ExtraDataList_GetMerchantContainer() ? reinterpret_cast<fnv_0072fd10::TESQuestStageList*>(m_merchant->BSFile_GetDevice())->ExtraDataList_GetMerchantContainer() : m_merchant;
    InventoryStackRecord* pWeapon3 = fnv_0072fd10::g_player_011dea3c->GetProcess()->GetCurrentAmmo();

    for (BSSimpleList<InventoryStackRecord*>* pNode6 = &m_kMerchantItems; pNode6 && pNode6->GetItem(); pNode6 = pNode6->GetNext())
    {
        InventoryStackRecord* pItem = pNode6->GetItem();
        ExtraDataList* pExtraList = pItem->Modelloader_GetReferencedThis() ? pItem->Modelloader_GetReferencedThis()->GetItem() : 0;
        if (pExtraList)
            fnv_0072fd10::Script_SetActionFlag(m_merchant, pExtraList, 0x4000);
        fnv_0072fd10::g_transferMgr_011c3f2c->TESDataHandler_RemoveItemBarterContainer(pItem, pItem->FUN_00726070(), m_merchant);
        delete pItem;
    }

    for (BSSimpleList<InventoryStackRecord*>* pNode3 = &m_kPlayerItems; pNode3 && pNode3->GetItem(); pNode3 = pNode3->GetNext())
    {
        InventoryStackRecord* pItem3 = pNode3->GetItem();
        ExtraDataList* pExtraList5 = pItem3->Modelloader_GetReferencedThis() ? pItem3->Modelloader_GetReferencedThis()->GetItem() : 0;
        if (pExtraList5)
            fnv_0072fd10::Script_SetActionFlag((TESObjectREFR*)fnv_0072fd10::g_player_011dea3c, pExtraList5, 0x4000);
        fnv_0072fd10::g_player_011dea3c->RemoveItem(pItem3->FUN_0044ddc0(), pExtraList5, pItem3->FUN_00726070(), 0, 0, pTarget3, 0, 0, 1,
                                   0);
        delete pItem3;
    }

    ((BarterMenu*)DAT_011d8fa4)->m_apTiles[13]->SetInt(0xfaf, 0);
    ((BarterMenu*)DAT_011d8fa4)->m_apTiles[12]->SetInt(0xfa3, 0);

    InventoryChanges* pChanges = 0;
    int iAmount5 = fnv_0072fd10::TruncateFloatToInt(fnv_0072fd10::floorf(((BarterMenu*)DAT_011d8fa4)->m_fBarterTotal));
    fnv_0072fd10::FUN_004d5e10(0x27, fnv_0072fd10::FUN_00ec7d40(iAmount5));

    if (m_barterTotal > 0.0)
    {
        InventoryStackRecord kCaps9(fnv_0072fd10::TESForm_GetFormByNumericID(0xf), 0);
        pChanges = InventoryChanges::GetOrAddInventoryChanges(pTarget3);
        if (pChanges)
            fnv_0072fd10::g_transferMgr_011c3f2c->TESDataHandler_RemoveItemBarterContainer(&kCaps9, fnv_0072fd10::MinInt(iAmount5, unk90), m_merchant);
        ((BSAudio::GetSingleton()->*reinterpret_cast<BarterSoundFactory>(&BSAudio::BSAudio_GetSoundHandleByEditorName))(
            "ITMBottlecapsUp", 0x101, false).*reinterpret_cast<BarterSoundPlay>(&BSSoundHandle::Play))();
    }
    else if (m_barterTotal < 0.0)
    {
        pChanges = InventoryChanges::GetOrAddInventoryChanges((TESObjectREFR*)fnv_0072fd10::g_player_011dea3c);
        if (pChanges)
            pChanges->InventoryChanges_RemoveGold((TESObjectREFR*)fnv_0072fd10::g_player_011dea3c, -iAmount5, pTarget3);
        ((BSAudio::GetSingleton()->*reinterpret_cast<BarterSoundFactory>(&BSAudio::BSAudio_GetSoundHandleByEditorName))(
            "ITMBottlecapsDown", 0x101, false).*reinterpret_cast<BarterSoundPlay>(&BSSoundHandle::Play))();
    }

    m_barterTotal = 0.0f;
    m_kMerchantItems.RemoveAll();
    m_kPlayerItems.RemoveAll();
    unk11C = 1;

    if (pWeapon3 && !InventoryChanges::GetOrAddInventoryChanges((TESObjectREFR*)fnv_0072fd10::g_player_011dea3c)
                         ->GetObjectCount(pWeapon3->FUN_0044ddc0()))
        fnv_0072fd10::g_player_011dea3c->GetProcess()->SetCurrentAmmunition(0);
}

extern double DAT_01012060;
void __cdecl InterfaceManager_UpdatePipBoyInventoryEffects(int pTileFade1, int pTileFade2, int pTilePulseSTR, S_0072e370_Item* pItemPulseSTRREQ, int abSkill);

struct TESBoundObjectExt
{
    double TESObjectARMO_GetDamageThreshold();
    double TESObjectARMO_GetArmorRating();
};

// @fnv 0x007306d0
// src: XBOX_PDB 0x007306d0
// pdb: BarterMenu::DoIdle | BarterMenu.obj | retail, upstream name already matches, high
void BarterMenu::DoIdle()
{
    if (DAT_011d8fc0 == 1)
    {
        BarterMenu_ForceBarterUpdate(true);
    }
    if (DAT_0119fdb0 != 0)
    {
        if (DAT_011d8fa8 != 0)
        {
            if (((InventoryStackRecord*)DAT_011d8fa8)->FUN_0044ddc0()->FUN_00401170() == 0x28)
            {
                InterfaceManager_UpdatePipBoyInventoryEffects(((int)m_apTiles[14]), ((int)m_apTiles[15]), ((int)m_apTiles[16]), DAT_011d8fa8, 0);
                return;
            }
        }
        if (DAT_011d8fa8 != 0)
        {
            if (((InventoryStackRecord*)DAT_011d8fa8)->FUN_0044ddc0()->FUN_00401170() == 0x18)
            {

                InterfaceManager_UpdatePipBoyInventoryEffects(
                    (DAT_011d8fa8 != 0 &&
                     DAT_01012060 !=
                         ((TESBoundObjectExt*)((InventoryStackRecord*)DAT_011d8fa8)->FUN_0044ddc0())->TESObjectARMO_GetArmorRating())
                        ? ((int)m_apTiles[17])
                        : 0,
                    (DAT_011d8fa8 != 0 &&
                     DAT_01012060 !=
                         ((TESBoundObjectExt*)((InventoryStackRecord*)DAT_011d8fa8)->FUN_0044ddc0())->TESObjectARMO_GetDamageThreshold())
                        ? ((int)m_apTiles[18])
                        : 0,
                    0, DAT_011d8fa8, 0);
            }
        }
    }
}

struct Holder7313
{
    Holder7313* Tile_GetMenuTile();
    Menu* Tile_GetMenu();
};

struct IM7313
{
    void InterfaceManager_SetCurrentFocusTarget(Tile* apTarget, int aiType, bool abPlaySounds);
};
struct List7313
{
    virtual void SetSelected7313(Tile* pTile);
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual Tile* GetTile7313(unsigned int uiIndex);
    void* pad[2];
    Holder7313* m_0c;
    void* padCur;
    Tile* m_14;
    void* kad[3];
    float m_24;
    float m_28;
    unsigned int ListBox_ItemChange_NumUnfiltered(int a);
    void UpdateCurrentValueTile(bool abPlayFocusSound);
};

// @fnv 0x00731360
// pdb: ListBox<ItemChange *>::RestoreListState | BarterMenu.obj | retail, call graph, high
// pdb params: abPlayFocusSound
// pdb locals: pnewHighlight
void List7313::UpdateCurrentValueTile(bool abPlayFocusSound)
{
    Tile* pTile = 0;
    if (m_0c && m_14)
    {
        m_14->Tile_Set(Tile_TextToTrait("_current_value"), m_28, false);
        m_14->SetTraitFloat(Tile_TextToTrait("_SetInCode"), 1.0f);
        pTile = GetTile7313((unsigned int)BSMIN(m_24, (float)(ListBox_ItemChange_NumUnfiltered(0) - 1.0)));
        ((IM7313*)InterfaceManager_GetSingleton())->InterfaceManager_SetCurrentFocusTarget(pTile, 0xfc3, abPlayFocusSound);
        SetSelected7313(pTile);
        if (!InterfaceManager_Has360Controller())
        {
            if (pTile)
                m_0c->Tile_GetMenuTile()->Tile_GetMenu()->HandleMouseoverTileAlt((int)pTile->FUN_00a011b0(0xfaa), pTile);
            SetSelected7313(0);
        }
    }
}

struct MerchantServices
{
    bool HasFlags(int mask);
};
struct MerchantBase
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    MerchantServices services;
};
struct MerchantActor : TESObjectREFR
{
    MerchantBase* FUN_004181e0();
};
int __cdecl TESValueForm_GetFormValue(TESBoundObject*);
int __cdecl FUN_00479430(TESBoundObject*);

// Checks if an inventory entry should be hidden from the barter menu based on merchant service flags and form validity.
// @fnv 0x0072e6c0
// src: XBOX_RETAIL_PDB 0x0072e6c0
// pdb: BarterMenu::VendorFirstPassFilterFunc | BarterMenu.obj | retail, object-file run extension, high
// pdb params: apItem
// pdb locals: pweap, pbipedForm, pammo, pfull, pobj, bisFiltered, pactor
bool __cdecl BarterMenu_VendorFirstPassFilterFunc(InventoryStackRecord* apItem)
{
    MerchantActor* merchant4;
    bool filteredVal = false;
    TESBoundObject* formTmp;
    TESFullName* name;
    TESObjectWEAP* weapon_;
    TESBipedModelForm* bipedVal;
    TESObjectARMO* armor;
    merchant4 =
        (((BarterMenu*)DAT_011d8fa4)->m_pkMerchant && ((BarterMenu*)DAT_011d8fa4)->m_pkMerchant->IsActor())
            ? (MerchantActor*)((BarterMenu*)DAT_011d8fa4)->m_pkMerchant
            : 0;
    formTmp = apItem ? ((InventoryStackRecord*)apItem)->FUN_0044ddc0() : 0;
    if (merchant4)
    {
        switch (((InventoryStackRecord*)apItem)->FUN_0044ddc0()->FUN_00401170())
        {
        case 40:
        case 41:
            filteredVal = merchant4->FUN_004181e0()->services.HasFlags(1) == false;
            break;
        case 24:
            filteredVal = merchant4->FUN_004181e0()->services.HasFlags(2) == false;
            break;
        case 31:
        case 50:
        case 103:
            filteredVal = merchant4->FUN_004181e0()->services.HasFlags(0x400) == false;
            break;
        case 46:
            filteredVal = true;
            break;
        case 49:
            filteredVal = (formTmp && TESValueForm_GetFormValue(formTmp) > 0)
                              ? (merchant4->FUN_004181e0()->services.HasFlags(0x400) == false)
                              : true;
            break;
        case 25:
            filteredVal = merchant4->FUN_004181e0()->services.HasFlags(8) == false;
            break;
        case 47:
            switch (FUN_00479430(((InventoryStackRecord*)apItem)->FUN_0044ddc0()))
            {
            case 10:
                filteredVal = merchant4->FUN_004181e0()->services.HasFlags(0x20) == false;
                break;
            case 11:
                filteredVal = merchant4->FUN_004181e0()->services.HasFlags(0x40) == false;
                break;
            case 12:
                filteredVal = merchant4->FUN_004181e0()->services.HasFlags(0x10) == false;
                break;
            case 13:
                filteredVal = merchant4->FUN_004181e0()->services.HasFlags(4) == false;
                break;
            }
            break;
        }
    }
    bipedVal = TESBipedModelForm::GetFormAsBipedModel(formTmp);
    name = dynamic_cast<TESFullName*>(formTmp);
    armor = ((InventoryStackRecord*)apItem)->FUN_0044ddc0()->FUN_00401170() == 40
                ? (TESObjectARMO*)((InventoryStackRecord*)apItem)->FUN_0044ddc0()
                : 0;
    weapon_ = ((InventoryStackRecord*)apItem)->FUN_0044ddc0()->FUN_00401170() == 41
                  ? (TESObjectWEAP*)((InventoryStackRecord*)apItem)->FUN_0044ddc0()
                  : 0;
    if (!formTmp || (bipedVal && !bipedVal->TESBipedModelForm_GetPlayable()) || TESContainer_IsGold(formTmp) || !name ||
        !name->GetModelLength() || (armor && !armor->IsFlag80Clear()) || (weapon_ && !weapon_->FUN_004c94d0()))
    {
        filteredVal = true;
    }
    return filteredVal;
}

struct Fr7304List
{
    Tile* FindItemData(InventoryStackRecord** ppkEntry);
};

// Evaluates the item type against a filter and, when a tile exists, combines the result with a comparison to _num_bartered.
// @fnv 0x007304b0
// src: XBOX_PDB 0x007304b0
// pdb: BarterMenu::FilterModeFunc | BarterMenu.obj | retail, string-set bridge, high
// pdb params: apItem
// pdb locals: emode, eid, pcurrTile, bisFiltered
bool __cdecl BarterMenu_FilterModeFunc(InventoryStackRecord* apItem)
{
    bool bResult = false;
    int iType = apItem->FUN_0044ddc0()->FUN_00401170();
    Tile* pkTile = reinterpret_cast<Fr7304List&>(((BarterMenu*)DAT_011d8fa4)->m_kMerchantList).FindItemData(&apItem);
    int iFilter_2 = 0;
    if (pkTile)
    {
        iFilter_2 = ((BarterMenu*)DAT_011d8fa4)->m_iMerchantFilter;
    }
    else
    {
        pkTile = reinterpret_cast<Fr7304List&>(((BarterMenu*)DAT_011d8fa4)->m_kPlayerList).FindItemData(&apItem);
        iFilter_2 = ((BarterMenu*)DAT_011d8fa4)->m_iPlayerFilter;
    }
    switch (iFilter_2)
    {
        break;
    case 1:
        bResult = iType != 0x28;
        break;
    case 2:
        bResult = iType != 0x18 && iType != 0x1a;
        break;
    case 3:
        bResult = iType != 0x1d && iType != 0x2f && iType != 0x19;
        break;
    case 4:
        bResult = iType == 0x28 || iType == 0x18 || iType == 0x1a || iType == 0x1d || iType == 0x2f || iType == 0x29 ||
                  iType == 0x19 || iType == 0x6c || iType == 0x73 || iType == 0x74;
        break;
    case 5:
        bResult = iType != 0x29;
        break;
    }
    if (pkTile)
    {
        bResult =
            bResult || (double)apItem->FUN_00726070() - pkTile->FUN_00a011b0(Tile_TextToTrait(s_szNumBartered)) <= 0.0;
    }
    return bResult;
}
