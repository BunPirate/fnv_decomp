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
    NiFloatInterpolator BlurInterpolator;
    NiFloatInterpolator DoubleInterpolator;
    NiColorInterpolator TintColorInterpolator;
    NiColorInterpolator FadeColorInterpolator;
    NiFloatInterpolator RadialBlurStrengthInterpolator;
    NiFloatInterpolator RadialBlurRampupInterpolator;
    NiFloatInterpolator RadialBlurStartInterpolator;
    NiFloatInterpolator RadialBlurRampDownInterpolator;
    NiFloatInterpolator RadialBlurDownStartInterpolator;
    NiFloatInterpolator DepthOfFieldStrengthInterpolator;
    NiFloatInterpolator DepthOfFieldDistanceInterpolator;
    NiFloatInterpolator DepthOfFieldRangeInterpolator;
    NiFloatInterpolator MotionBlurStrengthInterpolator;
    TimedFloatKey* pEffectEntryTable[21][2];
    TimedFloatKey* pBlurFloatKey;
    TimedFloatKey* pDoubleFloatKey;
    AlphaColor* pTintColorKey;
    AlphaColor* pFadeColorKey;
    TimedFloatKey* pRadialBlurStrengthFloatKey;
    TimedFloatKey* pRadialBlurRampupFloatKey;
    TimedFloatKey* pRadialBlurStartFloatKey;
    TimedFloatKey* pRadialBlurRampDownFloatKey;
    TimedFloatKey* pRadialBlurDownStartFloatKey;
    TimedFloatKey* pDepthOfFieldStrengthFloatKey;
    TimedFloatKey* pDepthOfFieldDistanceFloatKey;
    TimedFloatKey* pDepthOfFieldRangeFloatKey;
    TimedFloatKey* pMotionBlurStrengthFloatKey;
};
