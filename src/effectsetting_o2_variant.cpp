
// src/effectsetting_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/effectsetting.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "../include/BaseFormComponent.h"
#include "../include/EffectSetting.h"
#include "../include/FileEntryList.h"
#include "../include/TESDescription.h"
#include "../include/TESEffectShader.h"
#include "../include/TESFile.h"
#include "../include/TESForm.h"
#include "../include/TESFullName.h"
#include "../include/TESIcon.h"
#include "../include/TESModel.h"
#include "../include/TESObjectLIGH.h"
#include "../include/TESSound.h"
#include "../include/TESTexture.h"

#include "effectsetting_decls.h"

struct BEB3890Body
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
    float m_fBoundRadius;
};

static const float NI_INFINITY = 3.402823466e+38f;

class BEB3890Base
{
  public:
    BEB3890Base(float fA, float fB, float fC, int iD);
    virtual ~BEB3890Base();

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
};

// pdb: class NiBoxCapsuleIntersector, size 0x50, bases: NiIntersector, 4 members
class NiBoxCapsuleIntersector : public BEB3890Base
{
  public:
    NiBoxCapsuleIntersector(BEB3890Body* kBox, BEB3890Body* kCapsule, float fMaxTime, float fDerivativeTimeStep, float fPseudodistanceThreshold, int iMaxIterations);
    virtual ~NiBoxCapsuleIntersector();

    BEB3890Body* m_kBox;
    BEB3890Body* m_kCapsule;
    float m_fInvRadiusSqr;
    float m_afParameter;
    float m_fVectorZ;
    float m_fScalarPart;
};

// @fnv 0x00eb3890
// pdb: NiBoxCapsuleIntersector::NiBoxCapsuleIntersector | NiBoxCapsuleIntersector.obj | retail, call graph (shared callers), high
// pdb params: kBox, kCapsule, fMaxTime, fDerivativeTimeStep, fPseudodistanceThreshold, iMaxIterations
// pdb locals: i
NiBoxCapsuleIntersector::NiBoxCapsuleIntersector(BEB3890Body* kBox, BEB3890Body* kCapsule, float fMaxTime, float fDerivativeTimeStep, float fPseudodistanceThreshold, int iMaxIterations)
    : BEB3890Base(fMaxTime, fDerivativeTimeStep, fPseudodistanceThreshold, iMaxIterations), m_kBox(kBox), m_kCapsule(kCapsule)
{
    m_fInvRadiusSqr = 1.0f / (kCapsule->m_fBoundRadius * kCapsule->m_fBoundRadius);
    m_afParameter = NI_INFINITY;
    m_fVectorZ = NI_INFINITY;
    m_fScalarPart = NI_INFINITY;
}
