#pragma once

#include "TESForm.h"
#include "ImageSpaceModifierEffectData.h"
#include "NiFloatInterpolator.h"
#include "NiColorInterpolator.h"

class TESSound;
class TimedFloatKey;
class AlphaColor;

// pdb: class TESImageSpaceModifier, size 0x730, bases: TESForm, 31 members
class TESImageSpaceModifier : public TESForm
{
public:
    typedef ::ImageSpaceModifierEffectData ImageSpaceModifierEffectData;

    TESImageSpaceModifier();
    TESImageSpaceModifier& operator=(const TESImageSpaceModifier&);
    virtual ~TESImageSpaceModifier();
    virtual void ClearData();
    virtual void InitItem();
    virtual bool Compare(TESForm* form);

    void __vslot_10();
    bool Load(TESFile* apFile);
    void Save();
    void Copy(TESForm* form);
    void ResetFormData();
    bool GetAnimatable();
    float GetDuration();
    void SetAnimatable(bool animatable);
    void SetDuration(float duration);
    static void SetEnable(bool enable);
    static bool GetEnable();
    void Apply(float afStartTime, float afStrength, NiAVObject* apTarget);
    void EvaluateInterpolators(float startTime, float strength);
    bool IsExpired(float startTime);
    static void BlendModifiers(float blendWeight, TESImageSpaceModifier* lastModifier,
                               TESImageSpaceModifier* modifier, float modifierBlendWeight,
                               float time, NiAVObject* coordinate, NiAVObject* target);
    bool RemoveFloatKey(NiFloatInterpolator* interpolator);
    bool RemoveColorKey(NiColorInterpolator* interpolator);
    void MakeFloatKeyDefault(NiFloatInterpolator* interpolator, float value);
    void MakeColorKeyDefault(NiColorInterpolator* interpolator);
    void ResetInterpolators();
    bool HasValidKeys();
    bool AreKeysValid(NiAnimationKey* keys, unsigned int count, unsigned char type);
    TESSound* GetIntroSound();
    TESSound* GetOutroSound();
    static void SetCurrentTime(float time);
    static float GetTickCount();
    static void AdvanceCurrentTime(float time);
    void InitializeModifierData();
    static void AllowGetHit(bool allow);
    static TESImageSpaceModifier* GetGetHit();
    static TESImageSpaceModifier* GetConcussionModifier();
    static TESImageSpaceModifier* GetExplosionInFace();
    static TESImageSpaceModifier* QDefault();

    TESSound* pOutroSound;
    TESSound* pIntroSound;
    ImageSpaceModifierEffectData Data;
    NiFloatInterpolator m_akFloatInterpolators[21][2];
    NiFloatInterpolator BlurInterpolator; // src: XBOX_RETAIL_PDB +0x504 (old: m_kFloatInterpolatorOne)
    NiFloatInterpolator DoubleInterpolator; // src: XBOX_RETAIL_PDB +0x51c (old: m_kFloatInterpolatorTwo)
    NiColorInterpolator TintColorInterpolator; // src: XBOX_RETAIL_PDB +0x534 (old: m_kColorInterpolatorOne)
    NiColorInterpolator FadeColorInterpolator; // src: XBOX_RETAIL_PDB +0x558 (old: m_kColorInterpolatorTwo)
    NiFloatInterpolator RadialBlurStrengthInterpolator; // src: XBOX_RETAIL_PDB +0x57c (old: m_kFloatInterpolatorNine)
    NiFloatInterpolator RadialBlurRampupInterpolator; // src: XBOX_RETAIL_PDB +0x594 (old: m_kFloatInterpolatorTen)
    NiFloatInterpolator RadialBlurStartInterpolator; // src: XBOX_RETAIL_PDB +0x5ac (old: m_kFloatInterpolatorEleven)
    NiFloatInterpolator RadialBlurRampDownInterpolator; // src: XBOX_RETAIL_PDB +0x5c4 (old: m_kFloatInterpolatorThree)
    NiFloatInterpolator RadialBlurDownStartInterpolator; // src: XBOX_RETAIL_PDB +0x5dc (old: m_kFloatInterpolatorFour)
    NiFloatInterpolator DepthOfFieldStrengthInterpolator; // src: XBOX_RETAIL_PDB +0x5f4 (old: m_kFloatInterpolatorFive)
    NiFloatInterpolator DepthOfFieldDistanceInterpolator; // src: XBOX_RETAIL_PDB +0x60c (old: m_kFloatInterpolatorSix)
    NiFloatInterpolator DepthOfFieldRangeInterpolator; // src: XBOX_RETAIL_PDB +0x624 (old: m_kFloatInterpolatorSeven)
    NiFloatInterpolator MotionBlurStrengthInterpolator; // src: XBOX_RETAIL_PDB +0x63c (old: m_kFloatInterpolatorEight)
    TimedFloatKey* pEffectEntryTable[21][2];
    TimedFloatKey* pBlurFloatKey; // src: XBOX_RETAIL_PDB +0x6fc (old: pSecondEffectEntries)
    TimedFloatKey* pDoubleFloatKey; // src: XBOX_RETAIL_PDB +0x700 (old: pThirdEffectEntries)
    AlphaColor* pTintColorKey; // src: XBOX_RETAIL_PDB +0x704 (old: pFirstEffectRecordArray)
    AlphaColor* pFadeColorKey; // src: XBOX_RETAIL_PDB +0x708 (old: pSecondEffectRecordArray)
    TimedFloatKey* pRadialBlurStrengthFloatKey; // src: XBOX_RETAIL_PDB +0x70c (old: pTenthEffectEntries)
    TimedFloatKey* pRadialBlurRampupFloatKey; // src: XBOX_RETAIL_PDB +0x710 (old: pEleventhEffectEntries)
    TimedFloatKey* pRadialBlurStartFloatKey; // src: XBOX_RETAIL_PDB +0x714 (old: pTwelfthEffectEntries)
    TimedFloatKey* pRadialBlurRampDownFloatKey; // src: XBOX_RETAIL_PDB +0x718 (old: pFourthEffectEntries)
    TimedFloatKey* pRadialBlurDownStartFloatKey; // src: XBOX_RETAIL_PDB +0x71c (old: pFifthEffectEntries)
    TimedFloatKey* pDepthOfFieldStrengthFloatKey; // src: XBOX_RETAIL_PDB +0x720 (old: pSeventhEffectEntries)
    TimedFloatKey* pDepthOfFieldDistanceFloatKey; // src: XBOX_RETAIL_PDB +0x724 (old: pEighthEffectEntries)
    TimedFloatKey* pDepthOfFieldRangeFloatKey; // src: XBOX_RETAIL_PDB +0x728 (old: pNinthEffectEntries)
    TimedFloatKey* pMotionBlurStrengthFloatKey; // src: XBOX_RETAIL_PDB +0x72c (old: pSixthEffectEntries)
};
