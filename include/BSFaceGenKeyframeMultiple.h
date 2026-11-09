#pragma once

#include "BSFaceGenKeyframe.h"

template <class T> class NiTPointerList;

// pdb: class BSFaceGenKeyframeMultiple, size 0x14, bases: BSFaceGenKeyframe, 2 members
class BSFaceGenKeyframeMultiple : public BSFaceGenKeyframe
{
public:
    BSFaceGenKeyframeMultiple(BS_FACEGEN_MORPH_TYPE type, unsigned int count);
    BSFaceGenKeyframeMultiple(const BSFaceGenKeyframeMultiple& other);
    virtual ~BSFaceGenKeyframeMultiple();

    virtual void UnknownSlot1();
    virtual void UnknownSlot5();
    virtual void UnknownSlot6();
    virtual void UnknownSlot7();
    virtual bool ClearData(bool abForceZero);
    virtual void UnknownSlot9();
    virtual void UnknownSlot10();
    void UnknownSlot11();
    bool vfn_2c(BSFaceGenKeyframe* keyframe);
    virtual float GetAttributeStrength();
    virtual void UnknownSlot13();
    virtual void NormalizeFaceGenValues();
    virtual void UnknownSlot15();
    virtual bool HasNonzeroQuantity();
    virtual void UnknownSlot17();
    virtual void UnknownSlot18();
    virtual bool IsQuantityInRange(unsigned int quantity);
    virtual void ApplyFaceGenValues(unsigned int aiNumQuantities, bool abForceZero);

    void CopyFromKeyframe(BSFaceGenKeyframe* keyframe);
    bool DiffersFrom(BSFaceGenKeyframe* keyframe);
    BSFaceGenKeyframeMultiple* CreateCopy_0064f530();
    bool BlendWith(BSFaceGenKeyframe* apSource1, BSFaceGenKeyframe* apSource2, float afBlend);
    bool BlendFrom(BSFaceGenKeyframe* apSource, float afBlend, bool abMergeZeroes, bool abClearValueIfNoUpdate);
    bool Interpolate(float afTime, BSFaceGenKeyframe* apTarget);
    bool IsEmpty_0064f7e0();
    float BSFaceGenKeyframeMultiple_GetQuantity(unsigned int quantity);
    unsigned int GetCount();
    float GetQuantity(unsigned int quantity);
    bool SetQuantity(unsigned int quantity, float value);
    bool SetQuantity_0064a4d0(unsigned int quantity, float value);
    bool InsertIntoKeyframeList(NiTPointerList<BSFaceGenKeyframe*>* list);
    bool AddToCompatibleList(NiTPointerList<BSFaceGenKeyframe*>* list);

    float* pQuantities;
    unsigned int iNumQuantities;
};
