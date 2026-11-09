#pragma once

#include "BSTempEffect.h"
#include "BSSimpleArray.h"
#include "NiAVObject.h"
#include "NiPoint3.h"
#include "NiPlane.h"
#include "NiColor.h"

class RenderQuery;
class BSRenderedTexture;
class BGSTextureSet;
class NiPoint2;
class NiColorA;
class BGSDecalNode;
class QueuedFile;
class TESTopicInfoData;
class DecalData;
class NiPoint3;
class NiPoint3;
class DecalPoint;
struct DecalPointRecord;
class Geometry;
class Param;

// pdb: class BSTempEffectSimpleDecal, size 0x144, bases: BSTempEffect, 48 members
class BSTempEffectSimpleDecal : public BSTempEffect
{
  public:
    BSTempEffectSimpleDecal(int p1, float afLifetime, DecalData* pData);
    virtual ~BSTempEffectSimpleDecal();
    virtual const NiRTTI* GetRTTI() const;
    virtual void Initialize();
    virtual bool Update(float afTime);
    virtual NiAVObject* Get3D();

    bool ReleaseTextureObject();
    bool FinalizeGeometry();
    void CreateDebugBox(NiColorA& arColor, bool abWireframe);
    bool GetByteAt2D();
    TESTopicInfoData* BSTempEffectSimpleDecal_GetDecalParent();
    void CleanUpMemory();
    bool AddDecalGeometry(int count, int* indices, NiPoint3* positions,
                          const NiPoint3* attributes);
    bool AddDecalGeometry(int count, int* indices, DecalPoint* positions,
                          DecalPoint* attributes);
    bool AddDecalGeometry(int count, unsigned int* indices, NiPoint3* positions,
                          NiPoint3* attributes);
    void ProcessDecalTriangles(NiAVObject* object);
    void ClipMesh(Geometry* apAVObj);
    void ClipMesh(Param* apAVObj);
    bool ProcessGeometry(NiAVObject* object);
    bool ProcessGeometry(unsigned int object);
    bool ProcessGeometry(Param* apAVObj);
    int CreateTriData_0068ca90();
    void ResizeMeshBuffers();
    int ClipPolygonByPlanes(int count, const int* indices, const NiPoint3* positions,
                            const NiPoint3* attributes, int* outIndices,
                            NiPoint3* outPositions, NiPoint3* outAttributes);
    int ClipPolygonByPlanes(int count, float* apInVerts, NiPoint3* apInB, NiPoint3* apInC,
                            float* apOutB, NiPoint3* apOutPos, NiPoint3* apOutC);
    int ClipPolygonByPlanes(int count, unsigned int* indices, NiPoint3* positions,
                            NiPoint3* attributes, unsigned int* outIndices,
                            NiPoint3* outPositions, NiPoint3* outAttributes);

    static void PreloadDecalData();
    static void UnloadDecalData();
    static int ClipPolygonToPlane(NiPlane* plane, int count, const int* indices,
                                  const NiPoint3* positions, const NiPoint3* attributes,
                                  int* outIndices, NiPoint3* outPositions,
                                  NiPoint3* outAttributes);
    static int BSTempEffectSimpleDecal_ClipPolygonAgainstPlane(void* apPlane, int aiVertexCount, NiPoint3* apInIndex,
                                  float* apInVertex, NiPoint3* apInNormal,
                                  float* apOutIndex, NiPoint3* apOutVertex,
                                  NiPoint3* apOutNormal);
    static NiPointer<QueuedFile> ms_pPreloadDecalDataFile;

    bool bFinished;
    bool bFinalize;
    bool bOcclusionQuery;
    bool bClearQueryTexture;
    RenderQuery* pOcclusionQuery;
    NiPointer<BSRenderedTexture> spQueryTexture;
    unsigned int iCurrentOcclusionResult;
    NiPointer<NiAVObject> sp3D;
    bool bPermanent;
    bool bValidDecal;
    bool bForceFade;
    unsigned char layoutPadding2F[1];
    BGSTextureSet* pTextureSet;
    NiPoint3 pOrigin;
    NiPoint3 pVector;
    NiPoint3 pDecalCenter;
    NiPoint3 pDecalNormal;
    NiPlane pClippingPlanes[6];
    int iDecalVertexCount;
    int iDecalTriangleCount;
    NiPoint3* pTempVertexArray;
    NiPoint3* pFinalVertexArray;
    NiPoint3* pTempNormalArray;
    NiPoint3* pFinalNormalArray;
    NiPoint2* pTempTexcoordArray;
    NiPoint2* pFinalTexcoordArray;
    NiColorA* pTempColorArray;
    NiColorA* pFinalColorArray;
    unsigned short* pTempIndexArray;
    unsigned short* pFinalIndexArray;
    short* pOldToNewIndexArray;
    // A single collection retains array decay for buffer access.
    BSSimpleArray<DecalPointRecord*> pNewIndexMap[1];
    BGSDecalNode* pParentNode;
    NiPointer<NiAVObject> spTargetNode;
    float fScale;
    float fRotation;
    float fWidth;
    float fHeight;
    float fDepth;
    unsigned char cSubTexture;
    bool bUseParallaxOcclusion;
    unsigned char layoutPadding126[2];
    float fParallaxOcclusionScale;
    unsigned char ucParallaxOcclusionMaxPasses;
    bool bUseAlphaTesting;
    bool bUseAlphaBlending;
    unsigned char layoutPadding12F[1];
    float fSpecular;
    NiColor fVertexColor;
    bool bModelSpace;
    bool bTwoSided;
    unsigned char layoutPadding142[2];
};
