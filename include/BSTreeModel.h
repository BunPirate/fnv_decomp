#pragma once

#include "NiRefObject.h"
#include "NiAVObject.h"

class CSpeedTreeRT;
class NiNode;
class NiTexture;
class NiTriStrips;
class NiTriStripsData;
class TESObjectTREE;
class TreeCallback;
class TreeInput;
class TreeLeafRef;
class TreeModelInput;
class LoaderX;

// pdb: class BSTreeModel, size 0x50, bases: NiRefObject, 18 members
class BSTreeModel : public NiRefObject
{
  public:
    union
    {
        int initialized;
        unsigned int unk08;
    };
    union
    {
        CSpeedTreeRT* m_pTreeRuntime;
        CSpeedTreeRT* runtime;
    };
    NiPointer<BSTreeModel> spTreeParent; // src: XBOX_RETAIL_PDB +0x10 (old: source)
    union
    {
        NiPointer<NiTriStripsData>* pLeafGeometry;
        NiPointer<NiTriStripsData>* branchGeometry;
    };
    union
    {
        NiPointer<NiTriStripsData>* leafGeometry;
        NiPointer<NiTriStripsData>* m_pspLeafGeometry;
    };
    NiPointer<NiNode> spBillboard; // src: XBOX_RETAIL_PDB +0x1c (old: billboard)
    NiPointer<NiAVObject> spLeafShaderData; // src: XBOX_RETAIL_PDB +0x20 (old: unk20)
    union
    {
        NiPointer<NiTriStrips>* pLeafShapes;
        NiPointer<NiTriStrips>* branchNodes;
    };
    union
    {
        NiPointer<NiTriStrips>* leafNodes;
        NiPointer<NiTriStrips>* m_pspLeafShaders;
    };
    NiPointer<NiTexture> spBranchTextureSet; // src: XBOX_RETAIL_PDB +0x2c (old: unk2c)
    NiPointer<NiTexture> spLeafFrondTexture; // src: XBOX_RETAIL_PDB +0x30 (old: unk30)
    NiPointer<NiTexture> spBillboardTextureSet; // src: XBOX_RETAIL_PDB +0x34 (old: unk34)
    NiPointer<NiNode> spRigidBody; // src: XBOX_RETAIL_PDB +0x38 (old: collision)
    union
    {
        float unk3c;
        float m_fLeafScale;
        float scale;
    };
    unsigned int iSeed; // src: XBOX_RETAIL_PDB +0x40 (old: unk40)
    bool bInitialized; // src: XBOX_RETAIL_PDB +0x44 (old: unk44)
    unsigned char unk45[3];
    union
    {
        float unk48;
        float radius;
    };
    union
    {
        float unk4c;
        float height;
    };

    BSTreeModel();
    virtual ~BSTreeModel();
    virtual void DeleteThis();
    virtual void f2();
    virtual NiAVObject* CreateInstance(float);
    virtual void ApplyInput(TreeInput*);
    virtual void ClearArrays();
    virtual void LoadTreeCollision(TESObjectTREE*);

    void f1();
    void vf04();
    void vf05();
    void vf06();
    unsigned int FUN_00726070();
    bool BSTreeModel_InitFromBase(TESObjectTREE*, unsigned int);
    bool BSTreeModel_InitFromBase(TreeModelInput*, int);
    bool CombatProcedure_GetFinished();
    unsigned short __thiscall GetNumBranchLODLevels();
    unsigned short FUN_006699d0();
    unsigned short GetUnsignedShort();
    bool CloneFromModel(BSTreeModel*);
    void SetByteAtOffset44(unsigned char);
    void BSTreeModel_CreateBranchGeometry();
    void BSTreeModel_CreateLeafGeometry(TESObjectTREE*);
    void BSTreeModel_CreateLeafGeometry(TreeLeafRef*);
    void BSTreeModel_CreateBillboardGeometry(TESObjectTREE*);
    void BSTreeModel_CreateBillboardGeometry(LoaderX*);
    void UpdateTreeLod(TreeCallback*);
    void Setup(TreeModelInput*);
    void Finish(TreeModelInput*);
    NiAVObject* CreateTree(float);
    NiAVObject* ConvertFloatToUInt();
    void ReleaseData();
    void* DestroyAndFree(unsigned int flags);
};
