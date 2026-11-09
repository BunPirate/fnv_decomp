#pragma once

#include "TESForm.h"
#include "TESFullName.h"
#include "NiPoint3.h"
#include "NiPoint3.h"
#include "ExtraDataList.h"

class Actor;
class CellPoint3;
struct Ref54;
struct Destination54;
struct MaskTexture;
struct RotationPoint;
class NiPick;
struct CellFileStub;
struct G2;
struct FileH;
struct CellFormGroupRecord;
class AObj;
class P2Obj;
class SeenData_Stub;
class GO;
class Helper62d0;
class BSExtraData;
class TESActorBase;
class BGSAcousticSpace;
class BGSLightingTemplate;
class BGSEncounterZone;
class BGSPerkEntry;
class BSPortalGraph;
class BoundNodeV;
class CellLightingTemplate;
class ExteriorCellData;
class ExtraDataList;
class FormRecordHeader;
class InteriorCellData;
class ImpactSwap;
class NiColor;
class NavMeshCollection;
class NiAVObject;
class NiNode;
class RefX;
class RefV;
class ReferenceCollectorDC;
class TESGlobal;
class TESFileGroup;
class TESObjectLAND;
class TESObjectREFR;
class TESRegionList;
class TESWaterForm;
class TESWorldSpace;
class bhkWorld;
struct FormGroupQuery;
template <class T, unsigned int N> class BSSimpleArray;

class ActorReferenceArray
{
public:
    struct ActorReferenceSetupData;
};

// pdb: class TESObjectCELL, size 0xb0 (here 0xe0), bases: TESForm, TESFullName, 35 members
class TESObjectCELL : public TESForm, public TESFullName
{
public:
    unsigned char formData[0xBC];

    TESObjectCELL();
    virtual ~TESObjectCELL();
    virtual void ClearData();

    bool IsCellInterior() const;
    bool IsInterior();
    bool HasWater() const;  // 0x004518e0 (Xbox debug PDB TESObjectCELL::HasWater)
    bool IsPointInCell(const NiPoint3& point);
    bool IsActorTrespassing(Actor* actor);
    bool IsOutdoorCell();
    bool IsCellPersistent();
    int GetCellGridX();
    int GetCellGridY();
    void SetDataCoord(int x, int y);
    TESWorldSpace* GetParentWorldSpace();
    TESObjectLAND* GetLandscape();
    void SetLand(TESObjectLAND* apLand);
    NavMeshCollection* GetNavMeshArray();
    void SetNavMeshArray(NavMeshCollection* apNavMeshArray);
    void AddReference(TESObjectREFR* apRef, bool abOnTop);
    void AddReference(RefX* apRef, bool abOnTop);
    void RemoveReference(TESObjectREFR* reference);
    void RemoveNonPersistentRefs();
    void AddAudioMarkersToList(BSSimpleList<const char*>* apAudioList);
    void AppendCellReferences(BSSimpleArray<TESObjectREFR*, 1024>& references);
    bool GetReferencesInArea(const NiPoint3& aPoint1, float afRadius1,
                             const NiPoint3& aPoint2, float afRadius2,
                             bool (__cdecl* apfnEnumFunc)(TESObjectREFR*, long), long aiEnumData);
    void CellRefLockEnter();
    void CellRefLockLeave();
    void ClearCellReferenceList();
    void BuildLocalMapDoorList(ReferenceCollectorDC* apOutList);
    unsigned int CountReferencesWithFormType30();
    void Detach(bool abDetachHavok);
    void SetDetachTime(unsigned int aiTime, bool abForce);
    TESRegionList* GetRegionList(bool abCreateIfNotFound);
    BGSAcousticSpace* GetAcousticSpace();
    BGSEncounterZone* FindEncounterZone() const;
    TESWaterForm* GetAssociatedWaterForm();
    TESForm* GetOwner();
    unsigned char GetField24();
    unsigned char GetFakeExterior();
    NiNode* __thiscall GetSelectedValue(unsigned int index);
    void ClearAudioMarkers();
    ExteriorCellData* GetExteriorData();
    InteriorCellData* GetInteriorData();
    bool GetLowestProcessMiddleLow();
    ExtraDataList* GetExtraDataList();
    void SetTempPublic(bool value);
    void CreateCellData();
    void SetLightingTemplate(void* value);
    CellLightingTemplate* GetLightingTemplate();
    int GetCellStandValue();
    float GetInteriorLightValue();
    NiAVObject* GetCellChildAt(int index);
    NiAVObject* GetDynamicNode();
    bool IsFormTypeBelowThreshold(FormGroupQuery* apGroupFORM);
    bool MatchForm(void* form);
    void BuildParentGroupForm(FormRecordHeader* outGroupForm, TESFileGroup* parentGroup);

    char* TESObjectCELL_GetCellName();
    unsigned char TESDataHandler_GetSaveLoadGame();
    bool SavesBefore(FormGroupQuery* apGroupFORM);
    unsigned int GetGroupBlockKey();
    unsigned int GetGroupSubBlockKey();
    void TESObjectCELL_SetInterior(bool value);
    bool TESObjectCELL_GetTempPublic();
    void* PlayerCharacter_GetCurrentRegion();
    void AddActivatingRef(TESObjectREFR* apRef);
    BoundNodeV* TESObjectCELL_GetMultiBoundNode(RefV* apRef);
    BSPortalGraph* GetPortalGraph();
    NiNode* Get3D_00545cb0();
    void* FUN_00546c20();
    void __thiscall SetDetachTime_0();
    void GetInteriorLocalMapTexture(void* aiSectionX, unsigned int aiSectionY, Helper62d0* aspTexture);
    void TESObjectCELL_TakeInteriorLocalMapPicture(void* aiSectionX, unsigned int aiSectionY, GO* aspRenderedTexture);
    void __thiscall SetImageSpace_00547750(int value);
    TESWaterForm* Actor_GetRadiationLevel();
    void FillBarterContainer(Ref54* apActor, Destination54* apBarterContainer);
    void SaveGameTest();
    void PlaceCanopyShadowInAdjacentCell(int aiX, int aiY, MaskTexture** apRect, int aiIndex, unsigned char aiValue);
    void CalcRefCenterPoint(RotationPoint& aOutCenter);
    void ComputeCellRotationCenter(NiPoint3& center);
    void ComputeCellRotationCenter(NiPoint3* center);
    void AddFurnitureToList(G2* apFurnList);
    bool TESDataHandler_FormGroupLoadsInGame(FileH* file, CellFormGroupRecord* apFormGroup);
    void TESObjectCELL_GetCOCPlacementInfo(RotationPoint& aOutPos, RotationPoint& aOutRot);
    void TESObjectCELL_GetCOCPlacementInfo(CellPoint3* position, CellPoint3* rotation);
    void TESObjectCELL_GetCOCPlacementInfo(NiPoint3* position, NiPoint3* rotation);
    void TESObjectCELL_DetermineCOCPlacement(NiPoint3* aOutPos, NiPoint3* aOutRot);
    bool FUN_00550200(NiPoint3* position);
    bool LoadAllTempData();
    RefX* CreateLootBagAtRef(RefX* apRef);
    void TESObjectCELL_FillLootBag(RefX* apBagRef);
    void TESObjectCELL_SetHasTempData(bool active);
    bool FUN_005516c0();
    unsigned char NavMeshRender_GetDraw();
    void AdjustCoordForNorthRotation(NiPoint3& aStartCoord, NiPoint3& aOutCoord, bool abClockwise);
    void QueueReferences(bool abHighPriorityOnly);
    void RemoveObstaclesAndDoors();
    bool GetLightingTemplateInheritanceFlag(int mask);
    void RemoveAutoWaterReferenceFromReferencesCurrentWater(TESObjectREFR* apThis);
    BSSimpleList<BGSPerkEntry*>* GetRefList_009604f0();

    void* GetExteriorData_005445d0();
    void* GetInteriorData_00544600();
    bool GetHideLand(unsigned int aiQuad);
    void GetDataDirectionalColor(NiColor* color);
    unsigned int GetDataDirectionalXY();
    unsigned int GetDirectionalZ();
    void GetDataFogColor(NiColor* color);
    void RegisterReferenceInCell(TESObjectREFR* reference);
    TESGlobal* GetOwnershipGlobal();
    unsigned int GetDetachTime();
    BGSAcousticSpace* GetAcousticSpace_00547590();
    ImpactSwap* GetImpactSwap();
    NiNode* GetLightMarkerNode();
    NiNode* GetActorNode();
    void AttachSounds(bool attach);
    void SetWorldSpace(TESWorldSpace* world);
    void SetTempDataOffset_0054de80(int value);
    unsigned int GetInteriorOffset();
    bool GetHasTempData();
    void SetAltered_00552900(bool altered);
    void SetupMopp();
    void RevertBGS_00555a50(BGSLoadFormBuffer* buffer);
    void SetLightingTemplate_00558b60(BGSLightingTemplate* lightingTemplate);
    bool GetLightingTemplateInheritanceFlag(unsigned int mask);
    void RemoveAutoWaterReferenceFromReferencesCurrentWater(int apThis);
    void ActivateAllSubmergedReferencesIslands();
    BSPortalGraph* GetPortalGraph_009d9f20();
    void IOManager_Pause();
    void PerformCellNodeAttach(TESObjectREFR* reference, NiNode* parent);
    bool FindInFileFast(TESFile* file);
    void AddObstaclesAndDoors();
    void AttachMultiBoundNodes();
    bool RunScripts(bool, bool);
    void CalcLeveledCreatures(bool);
    void LoadGame_00555740(BGSLoadFormBuffer* buffer);
    bool GetWaterHeight(void* arPos, float* height);
    void UpdateCellExtraData(BSExtraData* aiTime, bool abForce);
    int GetCanopyShadowMask(int, int);
    void AddReference_0(TESObjectREFR* reference);
    void LockAndProcessPerks();
    void FUN_00541ac0();
    void TESObjectCELL_CellRefLockLeave();
    void* GetRefList_009604f0(unsigned char flag);
    void ChangeProcessLevel(unsigned char abChangeLevel);
    void ForceLODFadeIn();
    bool IsActorCellOwner(Actor* actor);
    bool TESObjectCELL_GetAttached();                     // 0x00450ff0 (HighProcess::Update 0x008eeec0)
    int TESObjectCELL_GetOwnershipRank();
    bool IsOwnedBy_00546ee0(TESActorBase* actorBase);
    void InitLoadGameBGS_005559d0(BGSLoadFormBuffer* buffer);
    void Save_00541ce0();
    bool Compare_00543c50(TESForm* form);

    bool PickWorldDistance(NiPick* apPick, int aOrigin, int aDir, float afDistance, char acNodeFlags);
    NiAVObject* ChildNodeAt(int index);
    bool SaveCellToFile(CellFileStub* apFile);
    bool SaveCellToFile(TESFile* file);
    void SaveReferences(CellFileStub* apFile);
    bool FUN_00460340();
    bool TestObjectAgainstRoom(AObj* apRef, P2Obj* apRef3D, int apBoundRef,
                      unsigned char* abFoundRoom, unsigned char abMultipleRoomTest);
    void Prepare();
    bool IsAttached();
    void AddSpaceRef(RefX* apThis);
    bool IsInteriorCell();
    void ProcessCellRefs();
    void DetachHavok();
    SeenData_Stub* FUN_00555bc0();
    unsigned short GetSaveSize_00554b90(unsigned int aiFlags);

    static void InitializeCell();
    static unsigned int InitializeTESResources(
        ActorReferenceArray::ActorReferenceSetupData& setup, bool, bool, bool);
    static bhkWorld* GetExteriorbhkWorld();
};

