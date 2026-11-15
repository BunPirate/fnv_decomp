#pragma once

#include "NiObject.h"
#include "NiFixedString.h"
#include "NiAVObject.h"

class NiControllerSequence__InterpArrayItem;
class NiControllerSequence__IDTag;
class NiControllerManager;
class NiTextKeyExtraData;
class NiStringPalette;
class BSAnimNote;
class TESAnimGroup;
class SL;
class NiAVObjectPalette;
class NiInterpController;
class NiInterpolator;
class NiTimeController;
struct SeqController;

enum NiTimeController__CycleType
{
    NiTimeController__CycleType_LOOP = 0,
    NiTimeController__CycleType_REVERSE = 1,
    NiTimeController__CycleType_CLAMP = 2,
    NiTimeController__CycleType_MAX_CYCLE_TYPES = 3
};

enum NiControllerSequence__AnimState
{
    NiControllerSequence__AnimState_INACTIVE = 0,
    NiControllerSequence__AnimState_ANIMATING = 1,
    NiControllerSequence__AnimState_EASEIN = 2,
    NiControllerSequence__AnimState_EASEOUT = 3,
    NiControllerSequence__AnimState_TRANSSOURCE = 4,
    NiControllerSequence__AnimState_TRANSDEST = 5,
    NiControllerSequence__AnimState_MORPHSOURCE = 6
};

// pdb: class NiControllerSequence, size 0x74, bases: NiObject, 28 members
class NiControllerSequence : public NiObject
{
  public:
    typedef NiControllerSequence__InterpArrayItem InterpArrayItem;
    typedef NiControllerSequence__IDTag IDTag;
    typedef NiControllerSequence__AnimState AnimState;

    static const AnimState INACTIVE = NiControllerSequence__AnimState_INACTIVE;
    static const AnimState ANIMATING = NiControllerSequence__AnimState_ANIMATING;
    static const AnimState EASEIN = NiControllerSequence__AnimState_EASEIN;
    static const AnimState EASEOUT = NiControllerSequence__AnimState_EASEOUT;
    static const AnimState TRANSSOURCE = NiControllerSequence__AnimState_TRANSSOURCE;
    static const AnimState TRANSDEST = NiControllerSequence__AnimState_TRANSDEST;
    static const AnimState MORPHSOURCE = NiControllerSequence__AnimState_MORPHSOURCE;

    NiControllerSequence();
    __declspec(noalias) NiControllerSequence(const char* const& name, unsigned int arraySize,
                                            unsigned int arrayGrowBy) throw();
    __declspec(nothrow) void AddFromOld(void* object, SeqController* controller) throw();
    virtual ~NiControllerSequence() throw();

    virtual const NiRTTI* GetRTTI() const;
    virtual NiNode* IsSceneNode() const;
    virtual BSFadeNode* IsFadeNode() const;
    virtual BSMultiBoundNode* IsMultiBoundNode() const;
    virtual NiGeometry* IsGeometry() const;
    virtual NiTriBasedGeom* IsTriBasedGeometry() const;
    virtual NiTriStrips* IsTriStrips() const;
    virtual NiTriShape* IsTriShape() const;
    virtual BSSegmentedTriShape* IsSegmentedTriShape() const;
    virtual BSResizableTriShape* IsResizableTriShape() const;
    virtual NiParticles* IsParticlesGeom() const;
    virtual NiLines* IsLineGeometry() const;
    virtual bhkNiCollisionObject* IsBhkNiCollisionObject() const;
    virtual bhkBlendCollisionObject* IsBhkBlendCollisionObject() const;
    virtual bhkRigidBody* IsBhkRigidBody() const;
    virtual bhkLimitedHingeConstraint* IsBhkLimitedHingeConstraint() const;
    virtual NiObject* MakeClone(CloningProcess& arCloning);
    virtual void LoadBinary(NiStream& arStream);
    virtual void LinkObject(NiStream& kStream);
    virtual bool RegisterStreamables(NiStream& arStream);
    virtual void SaveBinary(NiStream& arStream);
    virtual bool IsEqual(NiObject* apObject) const;
    virtual void GetViewerStrings(NiViewerStringsArray* apStrings);
    virtual void AddViewerStrings(NiViewerStringsArray* apStrings);
    virtual void ProcessClone(CloningProcess& kCloning);
    virtual void PostLinkObject(NiStream& arStream);
    virtual bool StreamCanSkip();
    virtual const NiRTTI* GetStreamableRTTI();
    virtual void SetObjectBound(NiBound* apNewBound);
    virtual unsigned int GetBlockAllocationSize();
    virtual NiObjectGroup* GetGroup();
    virtual void SetGroup(NiObjectGroup* apGroup);
    virtual NiControllerManager* IsControllerManager() const;
    virtual bool Deactivate(float afEaseOutTime, bool abTransition);

    bool GetEntryByte0d(int iIndex);
    void SetEntryByte(int iIndex, bool bValue);

    bool CanSyncWithSequence(NiControllerSequence* sequence);
    void SetSequenceTime(float afPhase, bool abUpdateControllers);
    void Update(float fTime, bool bUpdateInterpolators);
    bool Activate(char cPriority, bool startOver, float weight, float easeInTime,
                  NiControllerSequence* timeSyncSequence, bool transition);
    int GetState();
    NiFixedString& GetName();
    const NiFixedString& GetName() const;
    float GetField4C();
    int GetType();
    SL* GetTESPackageList();
    TESAnimGroup* GetAnimGroup();
    void ResetStrings();
    float GetEndKeyTime_00508100();
    float NiControllerSequence_GetLastTime();
    float TESCombatStyle_GetTargetingFOV();
    NiTextKeyExtraData* GetName_00700300();
    float NiPSysSpawnModifier_GetLifeSpan();
    char* GetHavokWorldObjectCountInSceneGraph_0084e3a0();
    void PathingLOSGridMap_SetSightRadius(float afTime);
    void* FUN_00a35820(unsigned int);

    bool IsNotInChain(void* sequence);
    bool MatchesTextKeys(NiControllerSequence* pkTimeSyncSeq);
    bool SetTimeSyncSequence(NiControllerSequence* pkTimeSyncSeq);
    bool StartSequence(char cPriority, bool startOver, float weight, float easeInTime,
                       NiControllerSequence* timeSyncSequence, bool transition);
    unsigned char SetEaseOut(float easeOutTime, bool transition);
    bool CrossFadeTo(NiControllerSequence* destination, float duration, int priority,
                     float sourceWeight, float destinationWeight);
    float FindCorrespondingMorphFrame(NiControllerSequence* pkSourceSequence, float fSourceSequenceTime);
    void SetAnimationCycleType(char cPriority);
    bool SetState(int state);
    void SetPriorityStub(char cPriority);
    void GetEntryText(unsigned int index, char* output);
    void ClearTargets();
    void AssignInterpolatorRef(int index, NiRefObject** output);
    void AssignInterpolatorRef(unsigned int index, NiRefObject*& output);
    int AddInterpolator(NiRefObject* pkInterpolator, unsigned int kIDTag, unsigned char ucPriority);
    void ClearInterpolatorRefs(NiControllerSequence* source, int argument);
    bool Attach(bool pkRoot, NiAVObject* pkObjectPalette, bool aiTransformControllerCount);
    bool AssignControllers(void* pcObjectName, NiInterpController* pkController);
    void SaveToStream(NiStream& stream);
    void LinkSequenceSource(NiStream* stream);

    void NiControllerSequence_DetachInterpolators();
    void AttachInterpolators(char cPriority);
    float ComputeScaledTime_00a30970(float fTime, bool bStoreLastTime);
    bool CanSyncTo(void* pkTargetSequence);
    bool RegisterStreamables_00a30ea0(NiStream& kStream);
    unsigned char IsEqual_00a30fb0(NiControllerSequence* pkObject);
    void* FUN_00a316a0();
    bool ResolveTransformInterpolators(NiAVObject* pkRoot, NiAVObject* pkObjectPalette, int aiTransformControllerCount);
    void NiControllerSequence_SetInterpsWeightAndTime(float fWeight, float fEaseSpinner, float fTime);
    bool NiControllerSequence_ReallocateArrays();
    void SetPhase(float afPhase, bool abUpdateControllers);
    bool StoreTargets(bool pkRoot);
    void PopulatePoseSequence(NiControllerSequence* pkPoseSequence, int uiArraySize, int pkSequenceToSynchronize, bool abRemInterps);
    void NiControllerSequence_CopyMembers(NiControllerSequence* pkDest, int kCloning);
    void Update_00a34ba0(float fTime, bool bUpdateInterpolators);
    bool StartBlend(NiControllerSequence* pkDestSequence, float fDuration, float fDestFrame, int priority,
                      float fSourceWeight, float fDestWeight, NiControllerSequence* pkTimeSyncSeq);
    void ProcessState_00a35640();

    NiFixedString m_kName;
    unsigned int m_uiNumControlledBlocks;
    unsigned int m_uiNumIDTags;
    NiControllerSequence__InterpArrayItem* m_pInterpArray;
    NiControllerSequence__IDTag* m_pkIDTags;
    float m_fWeight;
    NiPointer<NiTextKeyExtraData> m_spTextKeyData;
    NiTimeController__CycleType m_eAnimationCycleType;
    float m_fFrequency;
    float m_fFirstKeyTime;
    float m_fLastKeyTime;
    float m_fLastTime;
    float m_fWeightAdjustedLastTime;
    float m_fScaledLastTime;
    NiControllerManager* m_pkOwnerManager;
    NiControllerSequence__AnimState m_eAnimationState;
    float m_fSequenceOffset;
    float m_fStartTime;
    float m_fEndTime;
    float m_fDestinationFrame;
    NiControllerSequence* m_pkTimeSyncSequence;
    NiFixedString m_kAccumulationRootName;
    NiAVObject* m_pkAccumulationRoot;
    NiPointer<NiStringPalette> m_spStringPalette;
    short m_sAnimNotesExtraDataIndex;
    unsigned char layoutPadding6A[2];
    NiPointer<BSAnimNote>* m_pkAnimNotes;
    unsigned short m_usNumAnimNotes;
    bool m_bHasAnimNotes;
    unsigned char layoutPadding73[1];
};
