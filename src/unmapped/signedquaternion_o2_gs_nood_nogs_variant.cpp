// src/unmapped/signedquaternion_o2_gs_nood_nogs_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/unmapped/signedquaternion.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/unmapped/signedquaternion.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/animation/internal/compression/signedquaternion/signedquaternion.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <xmmintrin.h>
// The scratch record the original builds on the stack before the call:
//   +0x00  four floats, zeroed (one 16-byte SSE store)
//   +0x10  the float the callee writes its result into
// The type is 16-byte aligned, so sizeof is 32 and the frame slot is aligned.
struct __declspec(align(16)) FnvScratch
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    float result;
};

// Stand-in for the object the original is a member of: the only member it
// touches is the float at +0x40.
class FnvNode
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    float m_40;

    void hkaSplineCompressedAnimation_sampleFloat(float u, int quantizedTime, unsigned char mask, int scalarQuantizationType, unsigned int* dataInOut, float* a6);
};

// The helper the original calls with eight stack arguments; it is cdecl (the
// caller pops them) and it also receives the object pointer in ECX.
void __cdecl hkaSplineCompressedAnimation_readNURBSCurve(unsigned int* dataInOut, int quantizedTime, float frameDuration, float u, unsigned char mask, int scalarQuantizationType, float* I,
                          float* out);

// @fnv 0x00e33f10
// src: XBOX_PDB 0x00e33f10
// pdb: hkaSplineCompressedAnimation::sampleFloat | hkaSplineCompressedAnimation.obj | retail, upstream name already matches, high
// pdb params: u, quantizedTime, mask, scalarQuantizationType, dataInOut, out
// pdb locals: I, vout
void FnvNode::hkaSplineCompressedAnimation_sampleFloat(float u, int quantizedTime, unsigned char mask, int scalarQuantizationType, unsigned int* dataInOut, float* a6)
{
    if (!mask)
    {
        *a6 = 0.0f;
    }
    else
    {
        FnvScratch s;
        _mm_store_ps((float*)&s.unk00, _mm_setzero_ps());
        hkaSplineCompressedAnimation_readNURBSCurve(dataInOut, quantizedTime, m_40, u, mask, scalarQuantizationType, (float*)&s.unk00, &s.result);
        *a6 = s.result;
    }
    *dataInOut = (*dataInOut + 3) & 0xfffffffcu;
}
