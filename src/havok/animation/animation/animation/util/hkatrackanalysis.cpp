#include <new>
#include "../../../../../../include/hkArray.h"
#include "../../../../../../include/hkBool.h"
#include "../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../include/hkMemoryRouter.h"

// src/havok/animation/animation/animation/util/hkatrackanalysis.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/animation/animation/animation/util/hkatrackanalysis.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct TrackAnalysis
{
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
    int g;
    int count;
    int sum;
    int max;
};

// Accumulates bit counts from each value shifted right by 6 into result->count, result->sum and result->max.
// @fnv 0x00e4e570
// src: XBOX_RETAIL_PDB 0x00e4e570
// pdb: hkaTrackAnalysis::calcDynamicStatsQsTransform | hkaTrackAnalysis.obj | retail, call graph (shared callers), high
// pdb params: mask, numTracks, out
void hkaTrackAnalysis_calcDynamicStatsQsTransform(const unsigned short* mask, unsigned int numTracks, TrackAnalysis* out)
{
    out->count = 0;
    out->sum = 0;
    out->max = 0;
    for (unsigned int i = 0; i < numTracks; ++i)
    {
        unsigned int uiBits = mask[i] >> 6;
        out->count += ((uiBits >> 2) & 1) + ((uiBits >> 1) & 1) + (uiBits & 1);
        out->sum += ((uiBits >> 6) & 1) + ((uiBits >> 5) & 1) + ((uiBits >> 4) & 1) + ((uiBits >> 3) & 1);
        out->max += ((uiBits >> 9) & 1) + ((uiBits >> 8) & 1) + ((uiBits >> 7) & 1);
    }
}

void hkaTrackAnalysis_calcDynamicStatsQsTransform(const unsigned short* mask, unsigned int numTracks, TrackAnalysis* out);

// Analyzes the first value range via AnalyzeTrackBits, then counts zero entries in values and stores the count at result+0x28.
// @fnv 0x00e4e610
// pdb: hkaTrackAnalysis::calcDynamicStats | hkaTrackAnalysis.obj | retail, call graph, high
// pdb params: staticMaskT, staticMaskF, numTracksT, numTracksF, out
void AnalyzeTrackWithZeroCount(const unsigned short* staticMaskT, const unsigned short* staticMaskF,
                               unsigned int numTracksT, unsigned int numTracksF, TrackAnalysis* out)
{
    hkaTrackAnalysis_calcDynamicStatsQsTransform(staticMaskT, numTracksT, out);
    int* piZeroCount = (int*)((char*)out + 0x28);
    *piZeroCount = 0;
    for (unsigned int i = 0; i < numTracksF; ++i)
    {
        if (staticMaskF[i] == 0)
        {
            ++*piZeroCount;
        }
    }
}

struct TraceSink
{
    virtual void ReportDiagnostic();
    virtual void unused1();
    virtual void unused2();
    virtual void write(int, int, const char*, const char*, int);
    virtual void unused4();
    virtual void unused5();
    virtual void unused6();
    virtual void begin(unsigned int, const char*);
    virtual void end();
};
extern TraceSink* DAT_01268360;
extern const char str_010ec758[];
extern const char str_010ec724[];
extern const char str_010ec74c[];
extern const char str_010ec70c[];
extern const char str_010ec6f4[];
extern const char str_010ec6e0[];
extern const char str_010ec6cc[];
extern const char str_010ec6b4[];
extern const char str_010ec69c[];
extern const char str_010ec688[];
extern const char str_010ec670[];
extern const char str_010ec658[];
extern const char str_010ec644[];
extern const char str_010ec6f40[];
extern const char str_010ec624[];
struct TextBuilder
{
    int state;
    int length;
    int bufferCapacity;
    void FUN_00cb1600(char*, unsigned int);
    TextBuilder* ProcessAndReturnValue_00cc01c0(const char*, int);
    TextBuilder* ProcessAndReturnValue_00cc01c0(const char*, float);
    void EvaluateValue_00cc02d0();
    void WriteFloat();
    void FUN_00cc00e0();
};
struct TrackStatistics
{
    int field0;
    int field1;
    int field2;
    int field3;
    int field4;
    int field5;
    int field6;
    int field7;
    int field8;
    int field9;
    int field10;
    int total0;
    int total1;
    float rate;
    void hkaTrackAnalysis_AnalysisStats_displayReport();
};
// Formats each statistic field and the rate into a text buffer and writes them to the trace sink, then ends the trace.
// @fnv 0x00e4e660
// src: XBOX_RETAIL_PDB 0x00e4e660
// pdb: hkaTrackAnalysis::AnalysisStats::displayReport | hkaTrackAnalysis.obj | retail, unique string literal, high
// pdb locals: reportBuf, ostr
void TrackStatistics::hkaTrackAnalysis_AnalysisStats_displayReport()
{
    {
        TextBuilder textBuilder;
        char* outputWords[128];
        DAT_01268360->begin(0x432434a4u, str_010ec758);
        textBuilder.FUN_00cb1600(reinterpret_cast<char*>(outputWords), 512);
        textBuilder.ProcessAndReturnValue_00cc01c0(str_010ec74c, total0 + total1)->EvaluateValue_00cc02d0();
        DAT_01268360->write(0, -1, reinterpret_cast<char*>(outputWords), str_010ec724, 47);
        textBuilder.FUN_00cc00e0();
        textBuilder.FUN_00cb1600(reinterpret_cast<char*>(outputWords), 512);
        textBuilder.ProcessAndReturnValue_00cc01c0(str_010ec70c, field0)->EvaluateValue_00cc02d0();
        DAT_01268360->write(0, -1, reinterpret_cast<char*>(outputWords), str_010ec724, 48);
        textBuilder.FUN_00cc00e0();
        textBuilder.FUN_00cb1600(reinterpret_cast<char*>(outputWords), 512);
        textBuilder.ProcessAndReturnValue_00cc01c0(str_010ec6f4, field1)->EvaluateValue_00cc02d0();
        DAT_01268360->write(0, -1, reinterpret_cast<char*>(outputWords), str_010ec724, 49);
        textBuilder.FUN_00cc00e0();
        textBuilder.FUN_00cb1600(reinterpret_cast<char*>(outputWords), 512);
        textBuilder.ProcessAndReturnValue_00cc01c0(str_010ec6e0, field2)->EvaluateValue_00cc02d0();
        DAT_01268360->write(0, -1, reinterpret_cast<char*>(outputWords), str_010ec724, 50);
        textBuilder.FUN_00cc00e0();
        textBuilder.FUN_00cb1600(reinterpret_cast<char*>(outputWords), 512);
        textBuilder.ProcessAndReturnValue_00cc01c0(str_010ec6cc, field3)->EvaluateValue_00cc02d0();
        DAT_01268360->write(0, -1, reinterpret_cast<char*>(outputWords), str_010ec724, 51);
        textBuilder.FUN_00cc00e0();
        textBuilder.FUN_00cb1600(reinterpret_cast<char*>(outputWords), 512);
        textBuilder.ProcessAndReturnValue_00cc01c0(str_010ec6b4, field4)->EvaluateValue_00cc02d0();
        DAT_01268360->write(0, -1, reinterpret_cast<char*>(outputWords), str_010ec724, 52);
        textBuilder.FUN_00cc00e0();
        textBuilder.FUN_00cb1600(reinterpret_cast<char*>(outputWords), 512);
        textBuilder.ProcessAndReturnValue_00cc01c0(str_010ec69c, field5)->EvaluateValue_00cc02d0();
        DAT_01268360->write(0, -1, reinterpret_cast<char*>(outputWords), str_010ec724, 53);
        textBuilder.FUN_00cc00e0();
        textBuilder.FUN_00cb1600(reinterpret_cast<char*>(outputWords), 512);
        textBuilder.ProcessAndReturnValue_00cc01c0(str_010ec688, field6)->EvaluateValue_00cc02d0();
        DAT_01268360->write(0, -1, reinterpret_cast<char*>(outputWords), str_010ec724, 54);
        textBuilder.FUN_00cc00e0();
        textBuilder.FUN_00cb1600(reinterpret_cast<char*>(outputWords), 512);
        textBuilder.ProcessAndReturnValue_00cc01c0(str_010ec670, field7)->EvaluateValue_00cc02d0();
        DAT_01268360->write(0, -1, reinterpret_cast<char*>(outputWords), str_010ec724, 55);
        textBuilder.FUN_00cc00e0();
        textBuilder.FUN_00cb1600(reinterpret_cast<char*>(outputWords), 512);
        textBuilder.ProcessAndReturnValue_00cc01c0(str_010ec658, field8)->EvaluateValue_00cc02d0();
        DAT_01268360->write(0, -1, reinterpret_cast<char*>(outputWords), str_010ec724, 56);
        textBuilder.FUN_00cc00e0();
        textBuilder.FUN_00cb1600(reinterpret_cast<char*>(outputWords), 512);
        textBuilder.ProcessAndReturnValue_00cc01c0(str_010ec644, field9)->EvaluateValue_00cc02d0();
        DAT_01268360->write(0, -1, reinterpret_cast<char*>(outputWords), str_010ec724, 57);
        textBuilder.FUN_00cc00e0();
        textBuilder.FUN_00cb1600(reinterpret_cast<char*>(outputWords), 512);
        textBuilder.ProcessAndReturnValue_00cc01c0(str_010ec6f40, field10)->EvaluateValue_00cc02d0();
        DAT_01268360->write(0, -1, reinterpret_cast<char*>(outputWords), str_010ec724, 58);
        textBuilder.FUN_00cc00e0();
        textBuilder.FUN_00cb1600(reinterpret_cast<char*>(outputWords), 512);
        textBuilder.ProcessAndReturnValue_00cc01c0(str_010ec624, rate)->WriteFloat();
        DAT_01268360->write(0, -1, reinterpret_cast<char*>(outputWords), str_010ec724, 59);
        textBuilder.FUN_00cc00e0();
    }
    return DAT_01268360->end();
}

// hkMemoryRouter is the shared memory router: GetMonitorStream is 0x00c85750,
// and its heap allocator is at +0x10, as in both original router views here.

__forceinline hkMemoryAllocator& hkContainerHeapAllocator::get(const void*)
{
    return hkMemoryRouter::getInstance().heap();
}

template <class T> inline void hkArrayBase<T>::GrowArrayCapacity(hkMemoryAllocator& kAllocator, int n)
{
    const int iCapacity = getCapacity();
    if (iCapacity < n)
    {
        int iCap = 2 * iCapacity;
        int iNewSize = (n < iCap) ? iCap : n;
        hkArrayUtil::_reserve(kAllocator, this, iNewSize, sizeof(T));
    }
}

template <class T> inline void hkArrayBase<T>::_setSize(hkMemoryAllocator& kAllocator, int n)
{
    GrowArrayCapacity(kAllocator, n);
    m_iElementCount = n;
}

struct TrackHeader_e50650
{
    int m_iUnk00;
    int m_iArrayLength;
    int m_iUnk08;
};

struct TrackSource_e50650
{
    TrackHeader_e50650 m_kHeader;
    float m_fCoefficientA;
    float m_fB;
    float m_fC;
    float m_fD;
    unsigned char m_ucE;
};

struct TrackBuffers_e50650
{
    TrackHeader_e50650 m_kHeader;
    hkArray<float> m_kA;
    hkArray<float> m_kB;
    hkArray<float> m_kC;
    hkArray<float> m_kCubicCoefficient;
    hkArray<unsigned char> m_kE;

    void ReleaseFiveArrays();
};

void hkaTrackAnalysis_analyzeQsTransform(TrackBuffers_e50650* input, void* staticMask, void* staticDOFs, hkBool displayStatsReport);

// @fnv 0x00e50650
// pdb: hkaTrackAnalysis::analyze | hkaTrackAnalysis.obj | retail, object-file run extension, low
// pdb params: input, staticMask, staticDOFs
// pdb locals: perBoneInput
void ExpandTrackSource(const TrackSource_e50650* pkSource, void* pkArg, void* pkArgCur)
{
    // The original explicitly destroys this buffer through FUN_00e50ca0.
    void* bufferStorage[sizeof(TrackBuffers_e50650) / sizeof(void*)];
    TrackBuffers_e50650& kBuffers = *(TrackBuffers_e50650*)bufferStorage;
    kBuffers.m_kA.m_data = 0;
    kBuffers.m_kA.m_iElementCount = 0;
    kBuffers.m_kA.m_iCapacityState = 0x80000000;
    kBuffers.m_kB.m_data = 0;
    kBuffers.m_kB.m_iElementCount = 0;
    kBuffers.m_kB.m_iCapacityState = 0x80000000;
    kBuffers.m_kC.m_data = 0;
    kBuffers.m_kC.m_iElementCount = 0;
    kBuffers.m_kC.m_iCapacityState = 0x80000000;
    kBuffers.m_kCubicCoefficient.m_data = 0;
    kBuffers.m_kCubicCoefficient.m_iElementCount = 0;
    kBuffers.m_kCubicCoefficient.m_iCapacityState = 0x80000000;
    kBuffers.m_kE.m_data = 0;
    kBuffers.m_kE.m_iElementCount = 0;
    kBuffers.m_kE.m_iCapacityState = 0x80000000;
    int iCount = pkSource->m_kHeader.m_iArrayLength;
    kBuffers.m_kHeader.m_iUnk00 = pkSource->m_kHeader.m_iUnk00;
    kBuffers.m_kHeader.m_iArrayLength = iCount;
    kBuffers.m_kHeader.m_iUnk08 = pkSource->m_kHeader.m_iUnk08;
    kBuffers.m_kA.setSize(iCount);
    kBuffers.m_kB.setSize(iCount);
    kBuffers.m_kC.setSize(iCount);
    kBuffers.m_kCubicCoefficient.setSize(iCount);
    kBuffers.m_kE.setSize(iCount);
    for (int i = 0; i < iCount; i++)
    {
        kBuffers.m_kA.m_data[i] = pkSource->m_fCoefficientA;
        kBuffers.m_kB.m_data[i] = pkSource->m_fB;
        kBuffers.m_kC.m_data[i] = pkSource->m_fC;
        kBuffers.m_kCubicCoefficient.m_data[i] = pkSource->m_fD;
        kBuffers.m_kE.m_data[i] = pkSource->m_ucE;
    }
    hkaTrackAnalysis_analyzeQsTransform(&kBuffers, pkArg, pkArgCur, true);
    kBuffers.ReleaseFiveArrays();
}

struct StatsB0
{
    unsigned int m_iWordAt00, m_iWordAt04, m_8, m_iThirdValue, m_10, m_14, m_18, m_1c, m_20, m_24, m_28, m_2c, m_30;
    float m_34;
};
__declspec(noinline) void __cdecl Analyze(const unsigned short* p, unsigned int count, StatsB0* s)
{
    for (unsigned int i = 0; i < count; i++)
        s->m_1c += p[i] & 3;
}
__declspec(noinline) void __cdecl CountTail(const unsigned short* staticMaskT, void* staticMaskF, unsigned int numTracksT, unsigned int numTracksF,
                                            StatsB0* out)
{
    Analyze(staticMaskT, numTracksT, out);
    Analyze((const unsigned short*)staticMaskF, numTracksF, out);
}
// Initializes selected StatsB0 fields, counts mask values from both inputs, and computes derived fields and a ratio in m_34.
// @fnv 0x00e4ebb0
// src: HAVOK_LIB 0x00e4ebb0
// pdb: hkaTrackAnalysis::calcStats | hkaTrackAnalysis.obj | retail, upstream name already matches, high
// pdb params: staticMaskT, staticMaskF, numTracksT, numTracksF, out
void __cdecl hkaTrackAnalysis_calcStats(const unsigned short* staticMaskT, void* staticMaskF, unsigned int numTracksT,
                          unsigned int numTracksF, StatsB0* out)
{
    out->m_34 = 0.0f;
    out->m_30 = numTracksF;
    out->m_2c = numTracksT * 10;
    unsigned int* pCounters = &out->m_iWordAt00;
    pCounters[0] = 0;
    pCounters[1] = 0;
    pCounters[2] = 0;
    pCounters[4] = 0;
    pCounters[5] = 0;
    pCounters[6] = 0;
    pCounters[10] = 0;
    for (unsigned int i = 0; i < numTracksT; i++)
    {
        if ((staticMaskT[i] & 3) == 2)
            out->m_10 += 3;
        if ((staticMaskT[i] & 0xc) == 8)
            out->m_14 += 4;
        if ((staticMaskT[i] & 0x30) == 0x20)
            out->m_18 += 3;
    }
    CountTail(staticMaskT, staticMaskF, numTracksT, numTracksF, out);
    out->m_iWordAt00 = numTracksT * 3 - out->m_10 - out->m_1c;
    out->m_iWordAt04 = numTracksT * 4 - out->m_20 - out->m_14;
    out->m_8 = numTracksT * 3 - out->m_18 - out->m_24;
    out->m_iThirdValue = numTracksF - out->m_28;
    unsigned int sum = out->m_1c + out->m_20 + out->m_24 + out->m_28;
    if (sum)
    {
        unsigned int num = out->m_30;
        num += out->m_2c;
        out->m_34 = (float)num / (float)sum;
    }
    else
        out->m_34 = 0.0f;
}

#include <xmmintrin.h>
#include <math.h>
namespace fnv_00e4f640 {
// Exe 0x00e4f640 FUN_00e4f640: retain this LocalM128 view; the CRT type changes the matched code.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;
extern "C" LocalM128 _mm_setzero_ps(void);
extern "C" void _mm_store_ps(float* p, LocalM128 a);
extern "C" LocalM128 _mm_load_ps(const float* p);
extern "C" LocalM128 _mm_set_ps1(float a);
struct TrackData
{
    unsigned int numTransforms;
    unsigned int numFloats;
    const unsigned short* transformMasks;
    const unsigned short* floatMasks;
    const float* staticData;
    const float* staticFloats;
    const float* dynamicData;
    const float* dynamicFloats;
};
extern const __declspec(align(16)) float DAT_010c71b0[4];
extern const float DAT_01012068;
extern const float DAT_010ec620;
static float readComponent(const float*& stat, const float*& dynamic, unsigned int isDynamic)
{
    return isDynamic ? *dynamic++ : *stat++;
}
// Decodes transform and float tracks from static/dynamic data into 12-float transforms and a float array, using masks to select sources and defaults.
// @fnv 0x00e4f640
// src: XBOX_PDB 0x00e4f640
// pdb: hkaTrackAnalysis::recompose | hkaTrackAnalysis.obj | retail, upstream name already matches, high
// pdb params: input, outputPose, outputFloatTracks
// pdb locals: assertBuf, ostr
void hkaTrackAnalysis_recompose(const TrackData* input, float* outputPose, float* outputFloatTracks)
{
    const float* staticData = input->staticData;
    const float* dynamicData = input->dynamicData;
    for (unsigned int i = 0; i < input->numTransforms; ++i)
    {
        float* p = outputPose + i * 12;
        unsigned int mask = input->transformMasks[i];
        unsigned int flags = mask >> 6;
        if ((mask & 3) != 2)
        {
            p[0] = readComponent(staticData, dynamicData, flags & 4);
            p[1] = readComponent(staticData, dynamicData, flags & 2);
            p[2] = readComponent(staticData, dynamicData, flags & 1);
        }
        else
        {
            _mm_store_ps(p, _mm_setzero_ps());
        }
        if ((mask & 0x0c) != 8)
        {
            float x = readComponent(staticData, dynamicData, flags & 0x40);
            p[4] = x;
            float y = readComponent(staticData, dynamicData, flags & 0x20);
            p[5] = y;
            float z = readComponent(staticData, dynamicData, flags & 0x10);
            p[6] = z;
            float w = readComponent(staticData, dynamicData, flags & 8);
            p[7] = w;
            if ((float)fabs(w) == 2.0f)
            {
                float lenSq = x * x + y * y + z * z;
                if (lenSq > 1.0f)
                    lenSq = 1.0f;
                if (w > 0.0f)
                    p[7] = (float)sqrt(1.0f - lenSq);
                else
                    p[7] = -(float)sqrt(1.0f - lenSq);
            }
        }
        else
        {
            _mm_store_ps(p + 4, _mm_load_ps(DAT_010c71b0));
        }
        if ((mask & 0x30) != 0x20)
        {
            p[8] = readComponent(staticData, dynamicData, flags & 0x200);
            p[9] = readComponent(staticData, dynamicData, flags & 0x100);
            p[10] = readComponent(staticData, dynamicData, flags & 0x80);
        }
        else
        {
            _mm_store_ps(p + 8, _mm_set_ps1(1.0f));
        }
    }
    const float* staticFloats = input->staticFloats;
    const float* dynamicFloats = input->dynamicFloats;
    for (unsigned int iFloat = 0; iFloat < input->numFloats; ++iFloat)
    {
        if (input->floatMasks[iFloat] == 0)
            outputFloatTracks[iFloat] = *dynamicFloats++;
        else
            outputFloatTracks[iFloat] = *staticFloats++;
    }
}
}  // namespace fnv_00e4f640

struct PerTransformIn
{
    const void* boneData;
    unsigned int numberOfTransformTracks;
    unsigned int numberOfPoses;
};

struct PerFloatIn
{
    const float* floatData;
    unsigned int numberOfFloatTracks;
    unsigned int numberOfPoses;
    hkArray<float> absoluteTolerance;
};

static __forceinline void ClearStatistics(TrackStatistics& s)
{
    s.field0 = 0;
    s.field1 = 0;
    s.field2 = 0;
    s.field3 = 0;
    s.field4 = 0;
    s.field5 = 0;
    s.field6 = 0;
    s.field7 = 0;
    s.field8 = 0;
    s.field9 = 0;
    s.field10 = 0;
    s.total0 = 0;
    s.total1 = 0;
    s.rate = 0.0f;
}

void __cdecl hkaTrackAnalysis_calcStatsQsTransform(const unsigned short* mask, unsigned int numTracks, TrackStatistics* out);
void __cdecl hkaTrackAnalysis_calcStats(const unsigned short* staticMaskT, const unsigned short* staticMaskF, unsigned int numTracksT,
                          unsigned int numTracksF, TrackStatistics* out);

// Own the array storage explicitly: release() restores the stack router before freeing heap spillover.
struct FloatLocalArray
{
    void* arrayStorage[sizeof(hkArray<float>) / sizeof(void*)];
    float* localMemory;

    FloatLocalArray()
    {
        new (arrayStorage) hkArray<float>;
    }

    __forceinline hkArray<float>& values()
    {
        return *reinterpret_cast<hkArray<float>*>(arrayStorage);
    }

    __forceinline void allocate(int n)
    {
        hkMemoryRouter* router = &hkMemoryRouter::getInstance();
        char* block = (char*)router->m_stack.m_next.m_storage;
        router->m_stack.m_next.m_storage = block + ((n * 4 + 127) & ~127);
        values().m_iCapacityState = n | 0x80000000;
        values().m_data = (float*)block;
        localMemory = (float*)block;
    }

    __forceinline void freeStorage(hkMemoryAllocator& alloc)
    {
        int cap = values().m_iCapacityState;
        values().m_iElementCount = 0;
        if ((cap & 0x80000000) == 0)
        {
            alloc.bufFree(values().m_data, (cap & 0x3fffffff) * 4);
        }
        values().m_data = 0;
        values().m_iCapacityState = 0x80000000;
    }

    __forceinline void release()
    {
        float* saved = localMemory;
        if (saved == values().m_data)
        {
            values().m_iElementCount = 0;
        }
        hkMemoryRouter::getInstance().m_stack.m_next.m_storage = saved;
        freeStorage(hkContainerHeapAllocator().get(&values()));
    }
};

// Computes per-track min/max over poses, marks float tracks static when range is below tolerance, and optionally logs statistics.
// @fnv 0x00e50920
// src: HAVOK_LIB 0x00e50920
// pdb: hkaTrackAnalysis::analyze | hkaTrackAnalysis.obj | retail, object-file run extension, low
// pdb params: input, staticMask, staticDOFs
// pdb locals: perBoneInput
void __cdecl hkaTrackAnalysis_analyze(const PerTransformIn& input, const PerFloatIn& apFloatIn, unsigned short* staticMask,
                          float* staticDOFs, hkBool displayStatsReport)
{
    hkaTrackAnalysis_analyzeQsTransform((TrackBuffers_e50650*)&input, staticMask, staticDOFs, false);
    TrackStatistics statistics;
    ClearStatistics(statistics);
    hkaTrackAnalysis_calcStatsQsTransform(staticMask, input.numberOfTransformTracks, &statistics);
    float* pStaticDOF = staticDOFs + statistics.field0 + statistics.field1 + statistics.field2;
    FloatLocalArray minimum;
    minimum.allocate(apFloatIn.numberOfFloatTracks);
    minimum.values().setSize(apFloatIn.numberOfFloatTracks);
    FloatLocalArray maximum;
    maximum.allocate(apFloatIn.numberOfFloatTracks);
    maximum.values().setSize(apFloatIn.numberOfFloatTracks);
    for (unsigned int track = 0; track < apFloatIn.numberOfFloatTracks; ++track)
    {
        float tolerance = apFloatIn.absoluteTolerance.m_data[track];
        minimum.values().m_data[track] = 3.40282e+38f;
        maximum.values().m_data[track] = -3.40282e+38f;
        for (unsigned int pose = 0; pose < input.numberOfPoses; ++pose)
        {
            float value = apFloatIn.floatData[pose * apFloatIn.numberOfFloatTracks + track];
            if (value < minimum.values().m_data[track])
                minimum.values().m_data[track] = value;
            if (value > maximum.values().m_data[track])
                maximum.values().m_data[track] = value;
        }
        float midpoint = (minimum.values().m_data[track] + maximum.values().m_data[track]) * 0.5;
        float range = fabsf(maximum.values().m_data[track] - minimum.values().m_data[track]);
        float threshold = (float)(tolerance * 2.0);
        if (range < threshold)
        {
            staticMask[input.numberOfTransformTracks + track] = 1;
            *pStaticDOF++ = midpoint;
        }
        else
        {
            staticMask[input.numberOfTransformTracks + track] = 0;
        }
    }
    if (displayStatsReport.m_cBooleanValue)
    {
        const PerTransformIn* __restrict src = &input;
        ClearStatistics(statistics);
        hkaTrackAnalysis_calcStats(staticMask, staticMask + src->numberOfTransformTracks, src->numberOfTransformTracks,
                     apFloatIn.numberOfFloatTracks, &statistics);
        statistics.hkaTrackAnalysis_AnalysisStats_displayReport();
    }
    maximum.release();
    minimum.release();
}

struct StatisticsResult
{
    unsigned int field0, field1, field2, field3, field4, field5, field6, field7, field8, field9, field10, total0,
        total1;
    float rate;
    void LogStatistics();
};
__declspec(noinline) void hkaTrackAnalysis_calcDynamicStatsQsTransform(const unsigned short* mask, unsigned int numTracks, StatisticsResult* out)
{
    out->field7 = 0;
    out->field8 = 0;
    out->field9 = 0;
    for (unsigned int i = 0; i < numTracks; i++)
    {
        unsigned int v = mask[i] >> 6;
        out->field7 += ((v >> 2) & 1) + ((v >> 1) & 1) + (v & 1);
        out->field8 += ((v >> 6) & 1) + ((v >> 5) & 1) + ((v >> 4) & 1) + ((v >> 3) & 1);
        out->field9 += ((v >> 9) & 1) + ((v >> 8) & 1) + ((v >> 7) & 1);
    }
}
// Accumulates bit-field counts from mask values, calls FUN_00e4e570 for remaining fields, and computes a rate from total0 and the summed counts.
// @fnv 0x00e4ead0
// src: HAVOK_LIB 0x00e4ead0
// pdb: hkaTrackAnalysis::calcStatsQsTransform | hkaTrackAnalysis.obj | retail, upstream name already matches, high
// pdb params: mask, numTracks, out
void __cdecl hkaTrackAnalysis_calcStatsQsTransform(const unsigned short* mask, unsigned int numTracks, StatisticsResult* out)
{
    out->rate = 0.0f;
    StatisticsResult* pResult = out;
    pResult->total0 = numTracks * 10;
    pResult->total1 = 0;
    pResult->field0 = 0;
    pResult->field1 = 0;
    pResult->field2 = 0;
    pResult->field3 = 0;
    pResult->field4 = 0;
    pResult->field5 = 0;
    pResult->field6 = 0;
    pResult->field10 = 0;
    for (unsigned int i = 0; numTracks > i; i++)
    {
        if (((*(mask + i)) & 3) == 2)
            out->field4 += 3;
        if ((0xc & (*(mask + i))) == 8)
            out->field5 += 4;
        if ((0x30 & mask[i]) == 0x20)
            out->field6 += 3;
    }
    hkaTrackAnalysis_calcDynamicStatsQsTransform(mask, numTracks, out);
    out->field0 = 3 * numTracks - pResult->field7 - pResult->field4;
    out->field1 = numTracks * 4 - pResult->field5 - pResult->field8;
    out->field2 = numTracks * 3 - pResult->field9 - out->field6;
    if (pResult->field9 + (pResult->field7 + pResult->field8) > 0)
        pResult->rate = (float)out->total0 / (float)(pResult->field9 + (pResult->field7 + pResult->field8));
    else
        out->rate = 0.0f;
}
