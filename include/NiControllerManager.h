#pragma once

#include "NiTimeController.h"
#include "NiNode.h"
#include "NiControllerSequence.h"
#include "NiAVObjectPalette.h"
#include "NiTPrimitiveSet.h"
#include "NiTStringPointerMap.h"

class BSAnimNoteListener;
class NiControllerSequenceX;

template <class T> class NiTMallocInterface;



// pdb: class NiControllerManager, size 0x7c, bases: NiTimeController, 7 members
class NiControllerManager : public NiTimeController
{
public:
    NiControllerManager() throw();
    NiControllerManager(NiNode* target, bool useCumulativeAnimation);
    virtual ~NiControllerManager();
    using NiTimeController::Update;
    virtual void Update(NiUpdateData& UpdateData);
    virtual void vf45();

    void CopyMembers(NiControllerManager* destination, CloningProcess* cloning);
    NiControllerSequence* CreateTempBlendSequence(NiControllerSequence* pkSequence, unsigned int pkSequenceToSynchronize);
    void SetBit(bool value, unsigned short mask);
    NiControllerSequence* FindSequenceByName(const NiFixedString& name);
    static NiFixedString* FindSequenceByName();
    bool StopSequence(NiControllerSequence* sequence, float easeOutTime = 0.0f);
    bool StopSequence(NiControllerSequenceX* sequence, float easeOutTime);
    bool ActivateControllerSequence(NiControllerSequence* sequence, int priority = 0,
        bool startOver = false, float weight = 1.0f, float easeInTime = 0.0f,
        NiControllerSequence* timeSyncSequence = 0);
    void ActivateControllerSequence(NiControllerSequence* sequence, int priority,
        bool startOver, float weight, float easeInTime, int timeSyncSequence);
    void DeactivateAllSequences(float fEaseOutTime);
    unsigned int GetSequenceCount();
    NiControllerSequence* GetSequenceAt(unsigned int index);
    NiAVObjectPalette* GetStringAtOffset();
    int GetStringAtOffset(int offset);

    NiControllerSequence* NiControllerManager_GetSequenceByName(const NiFixedString& name);
    NiControllerSequence* NiControllerManager_GetSequenceByName(const char* name);
    void FUN_0047aa40(bool value);
    bool FUN_0047aab0(NiControllerSequence* sequence, int priority, int startOver,
        float weight, float easeInTime, NiControllerSequence* timeSyncSequence);
    void FUN_0047aab0(NiControllerSequence* sequence, int priority, int startOver,
        float weight, float easeInTime, int timeSyncSequence);
    void FUN_0047b220(NiControllerSequence* sequence, float easeOutTime);
    void FUN_0048fef0(float fEaseOutTime);
    unsigned int GetSequenceCount_00495d00();
    NiControllerSequence* GetSequenceAt_00495d20(unsigned int index);
    bool NiTimeController_GetActive();

    NiTObjectArray<NiPointer<NiControllerSequence> > m_kSequenceArray; // src: XBOX_RETAIL_PDB +0x34 (old: m_kSequences)
    NiTPrimitiveSet<NiControllerSequence*> m_kPlayingSequences;
    NiTStringPointerMap<NiControllerSequence*> m_kStringMap; // src: XBOX_RETAIL_PDB +0x50 (old: m_kObjectMap)
    BSAnimNoteListener* pListener; // src: XBOX_RETAIL_PDB +0x64 (old: m_pAudioListener)
    bool m_bCumulative; // src: XBOX_RETAIL_PDB +0x68 (old: m_bUseCumulativeAnimation)
    NiTObjectSet<NiPointer<NiControllerSequence> > m_kSequenceSet;
    NiPointer<NiAVObjectPalette> m_spControllerManager;
};
