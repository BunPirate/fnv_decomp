#pragma once

#include "BSTempEffect.h"
#include "NiAVObject.h"
#include "NiPoint3.h"

class Aux30;
class Obj4;
class SubDef;
class NiPoint3;
class Pt3Obj;
class Obj4c;
class DGeometry;
class DPoint;
class DBone;
class DNewPartition;

template <class T> class NiPointer;

// pdb: class BSTempEffectGeometryDecal, size 0x64, bases: BSTempEffect, 15 members
class BSTempEffectGeometryDecal : public BSTempEffect
{
public:
    BSTempEffectGeometryDecal(int apCell, float afLifetime, const Aux30* apDecalData, Obj4* apGeometry,
                             SubDef apOrigin, SubDef apVector, float afScale, float afRotation,
                             unsigned int aiBodyParts);
    virtual ~BSTempEffectGeometryDecal();

    virtual const NiRTTI* GetRTTI() const override;
    virtual void Initialize() override;
    virtual bool Update(float afTime) override;
    virtual NiAVObject* Get3D() override;
    virtual int GetType() override;
    virtual bool IsSaveable() override;
    virtual unsigned short GetSaveSize() override;
    virtual void SaveGame() override;
    virtual bool LoadGame() override;

    NiPointer<BSTempEffect> operator*();

    void BuildSkinPartitions();
    void BuildDecalGeometry();
    void CreateDecalGeometry(DGeometry* geom, unsigned short ausVertexCount,
                             unsigned short ausIndexCount, DPoint* apVertices,
                             DPoint* d, unsigned short* apIndices, DBone* bone,
                             DNewPartition* apNewPartition, unsigned short* apPartMap);
    void CreateDecalGeometry(const char* s, int a, int b, Pt3Obj* c, Pt3Obj* d,
                             unsigned short* e, Obj4c* f, void* g, unsigned short* h);
    bool ShouldAddTriangle(int aiIndex, int aiBaseVertex, bool abStrip,
                      const unsigned short* apIB, const NiPoint3* apTexCoords,
                      const unsigned short* apusVertexMap);
    bool ShouldAddTriangle(int aiIndex, int aiBaseVertex, bool abStrip,
                      const unsigned short* apIB, const DPoint* apTexCoords,
                      const unsigned short* apusVertexMap);
    unsigned char ShouldAddTriangle(int aiIndex, int aiBaseVertex, bool abStrip, unsigned short* apIB,
                               Pt3Obj* apTexCoords, int apusVertexMap);

    void Smooth();
    void Straighten();
    void Finalize();
    void FinalizePath();
    unsigned short GetRuntimeFlags();

    const NiRTTI* GetRTTI_006838a0() const;
    void* FUN_006838d0(unsigned int flags);
    bool FUN_006828a0(float f);
    void FUN_00688770();
    bool Update_006888a0(float f);
    void SaveGameTES_00688b00();
    bool LoadGameTES_00688c90();

    unsigned int pDecalData;
    NiPointer<NiAVObject> spDecalGeometry;
    int pGeometry;
    char* pOldIndex;
    unsigned char bFinished;
    unsigned char unk29[3];
    NiPointer<NiAVObject> spTargetGeom;
    NiPointer<NiAVObject> spParent;
    NiPointer<NiAVObject> spDecalParent;
    NiPoint3 pOrigin;
    NiPoint3 pVector;
    float fScale;
    float fRotation;
    unsigned int pTextureSet;
    unsigned int iNumVerts;
    unsigned int iBodyParts;
};
