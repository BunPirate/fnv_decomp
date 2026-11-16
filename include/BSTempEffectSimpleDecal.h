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

    bool bFinished; // src: XBOX_RETAIL_PDB +0x18 (old: bWasPlaying)
    bool bFinalize; // src: XBOX_RETAIL_PDB +0x19 (old: m_bTextureDirty)
    bool bOcclusionQuery; // src: XBOX_RETAIL_PDB +0x1a (old: m_bNeedsManagerUpdate)
    bool bClearQueryTexture; // src: XBOX_RETAIL_PDB +0x1b (old: m_bDecalRenderingEnabled)
    RenderQuery* pOcclusionQuery; // src: XBOX_RETAIL_PDB +0x1c (old: m_pRenderQuery)
    NiPointer<BSRenderedTexture> spQueryTexture; // src: XBOX_RETAIL_PDB +0x20 (old: m_pDecalRenderTexture)
    unsigned int iCurrentOcclusionResult; // src: XBOX_RETAIL_PDB +0x24 (old: m_uiTextureReferenceCount)
    NiPointer<NiAVObject> sp3D; // src: XBOX_RETAIL_PDB +0x28 (old: m_pSceneObject)
    bool bPermanent;
    bool bValidDecal; // src: XBOX_RETAIL_PDB +0x2d (old: m_bSecondObjectFlag)
    bool bForceFade; // src: XBOX_RETAIL_PDB +0x2e (old: TexturedObjectPlacementInfo)
    unsigned char layoutPadding2F[1];
    BGSTextureSet* pTextureSet; // src: XBOX_RETAIL_PDB +0x30 (old: m_pTextureSet)
    NiPoint3 pOrigin;
    NiPoint3 pVector; // src: XBOX_RETAIL_PDB +0x40 (old: m_kSecondVertex)
    NiPoint3 pDecalCenter; // src: XBOX_RETAIL_PDB +0x4c (old: m_kThirdPoint)
    NiPoint3 pDecalNormal; // src: XBOX_RETAIL_PDB +0x58 (old: m_kFourthPoint)
    NiPlane pClippingPlanes[6]; // src: XBOX_RETAIL_PDB +0x64 (old: m_akFacePlanes)
    int iDecalVertexCount; // src: XBOX_RETAIL_PDB +0xc4 (old: m_iFirstValueAfterPlanes)
    int iDecalTriangleCount; // src: XBOX_RETAIL_PDB +0xc8 (old: m_iSecondValueAfterPlanes)
    NiPoint3* pTempVertexArray; // src: XBOX_RETAIL_PDB +0xcc (old: m_pFirstPoint3Array)
    NiPoint3* pFinalVertexArray; // src: XBOX_RETAIL_PDB +0xd0 (old: m_pVertexNormals)
    NiPoint3* pTempNormalArray; // src: XBOX_RETAIL_PDB +0xd4 (old: m_pThirdPoint3Array)
    NiPoint3* pFinalNormalArray; // src: XBOX_RETAIL_PDB +0xd8 (old: m_pVertexBitangents)
    NiPoint2* pTempTexcoordArray; // src: XBOX_RETAIL_PDB +0xdc (old: m_pPrimaryTextureCoordinates)
    NiPoint2* pFinalTexcoordArray; // src: XBOX_RETAIL_PDB +0xe0 (old: m_pSecondaryTextureCoordinates)
    NiColorA* pTempColorArray; // src: XBOX_RETAIL_PDB +0xe4 (old: m_pFirstElementArray)
    NiColorA* pFinalColorArray; // src: XBOX_RETAIL_PDB +0xe8 (old: NavMeshGeometryBuffers)
    unsigned short* pTempIndexArray; // src: XBOX_RETAIL_PDB +0xec (old: m_pFirstUnsignedShortArray)
    unsigned short* pFinalIndexArray; // src: XBOX_RETAIL_PDB +0xf0 (old: m_pSecondUnsignedShortArray)
    short* pOldToNewIndexArray; // src: XBOX_RETAIL_PDB +0xf4 (old: m_pSignedShortArray)
    // A single collection retains array decay for buffer access.
    BSSimpleArray<DecalPointRecord*> pNewIndexMap[1]; // src: XBOX_RETAIL_PDB +0xf8 (old: m_aucByteBuffer)
    BGSDecalNode* pParentNode; // src: XBOX_RETAIL_PDB +0x108 (old: m_pDecalNode)
    NiPointer<NiAVObject> spTargetNode; // src: XBOX_RETAIL_PDB +0x10c (old: m_pTargetNode)
    float fScale;
    float fRotation; // src: XBOX_RETAIL_PDB +0x114 (old: fPathHeading)
    float fWidth; // src: XBOX_RETAIL_PDB +0x118 (old: m_fGlyphWidthInPixels)
    float fHeight; // src: XBOX_RETAIL_PDB +0x11c (old: m_fGlyphExtent)
    float fDepth; // src: XBOX_RETAIL_PDB +0x120 (old: m_fProjectionDepth)
    unsigned char cSubTexture; // src: XBOX_RETAIL_PDB +0x124 (old: m_ucByteAfterFloats)
    bool bUseParallaxOcclusion; // src: XBOX_RETAIL_PDB +0x125 (old: m_bFlagBeforeFloat)
    unsigned char layoutPadding126[2];
    float fParallaxOcclusionScale; // src: XBOX_RETAIL_PDB +0x128 (old: m_fFloatBeforeScalarFlagState)
    unsigned char ucParallaxOcclusionMaxPasses; // src: XBOX_RETAIL_PDB +0x12c (old: ScalarFlagState)
    bool bUseAlphaTesting; // src: XBOX_RETAIL_PDB +0x12d (old: m_bFirstBooleanFlag)
    bool bUseAlphaBlending; // src: XBOX_RETAIL_PDB +0x12e (old: m_bSecondBooleanFlag)
    unsigned char layoutPadding12F[1];
    float fSpecular; // src: XBOX_RETAIL_PDB +0x130 (old: m_fSpecularStrength)
    NiColor fVertexColor; // src: XBOX_RETAIL_PDB +0x134 (old: m_kSurfaceColor)
    bool bModelSpace; // src: XBOX_RETAIL_PDB +0x140 (old: m_bTextureFlag)
    bool bTwoSided; // src: XBOX_RETAIL_PDB +0x141 (old: m_bDecalTextureCreated)
    unsigned char layoutPadding142[2];
};
