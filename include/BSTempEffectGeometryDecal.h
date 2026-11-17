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

    unsigned int pDecalData; // src: XBOX_RETAIL_PDB +0x18 (old: unk18)
    NiPointer<NiAVObject> spDecalGeometry; // src: XBOX_RETAIL_PDB +0x1c (old: m_spGeometry)
    int pGeometry; // src: XBOX_RETAIL_PDB +0x20 (old: unk20)
    char* pOldIndex; // src: XBOX_RETAIL_PDB +0x24 (old: m_pData)
    unsigned char bFinished; // src: XBOX_RETAIL_PDB +0x28 (old: unk28)
    unsigned char unk29[3];
    NiPointer<NiAVObject> spTargetGeom; // src: XBOX_RETAIL_PDB +0x2c (old: m_sp2C)
    NiPointer<NiAVObject> spParent; // src: XBOX_RETAIL_PDB +0x30 (old: m_sp30)
    NiPointer<NiAVObject> spDecalParent; // src: XBOX_RETAIL_PDB +0x34 (old: m_sp34)
    NiPoint3 pOrigin; // src: XBOX_RETAIL_PDB +0x38 (old: m_38)
    NiPoint3 pVector; // src: XBOX_RETAIL_PDB +0x44 (old: m_44)
    float fScale; // src: XBOX_RETAIL_PDB +0x50 (old: m_50)
    float fRotation; // src: XBOX_RETAIL_PDB +0x54 (old: m_54)
    unsigned int pTextureSet; // src: XBOX_RETAIL_PDB +0x58 (old: m_58)
    unsigned int iNumVerts; // src: XBOX_RETAIL_PDB +0x5c (old: m_5c)
    unsigned int iBodyParts; // src: XBOX_RETAIL_PDB +0x60 (old: m_60)
};
