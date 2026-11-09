#pragma once

#include "BSFadeNode.h"
#include "BSTreeModel.h"

class BSTreeModel;
class CSpeedTreeRT;
class NiTexturingProperty;
class bhkSimpleShapePhantom;

// pdb: class BSTreeNode, size 0x130, bases: BSFadeNode, 5 members
class BSTreeNode : public BSFadeNode
{
  public:
    BSTreeNode();
    BSTreeNode(BSTreeModel*, NiAVObject*);
    BSTreeNode(void*, void*);
    virtual ~BSTreeNode();

    virtual const NiRTTI* GetRTTI() const;
    virtual void GetViewerStrings(NiViewerStringsArray*);
    virtual void UpdateDownwardPass(NiUpdateData& UpdateData, unsigned int uFlags);
    virtual void UpdateSelectedDownwardPass(NiUpdateData& UpdateData, unsigned int uFlags);
    virtual void OnVisible(NiCullingProcess&);

    virtual BSTreeModel* GetModelFilePath();
    virtual NiNode* GetBranchesNode();
    virtual NiNode* GetFrondNode();
    virtual NiNode* GetLeavesNode();
    virtual NiTriBasedGeom* GetBranchMesh(unsigned short);
    virtual NiTriBasedGeom* GetFrondMesh(unsigned short);
    virtual NiTriBasedGeom* GetLeafMesh();
    virtual bool SetBranchGeometry(unsigned short, NiTriBasedGeom*);
    virtual bool SetFrondGeometry(unsigned short, NiTriBasedGeom*);
    virtual void SetBillboardObject(NiTriBasedGeom*);
    virtual bool SetBranchVisible(bool);
    virtual bool SetFrondVisible(bool);
    virtual bool SetLeavesVisible(bool);
    virtual bool SetBranchTextureVariant(unsigned short, unsigned char);
    virtual bool SetFrondTextureVariant(unsigned short, unsigned char);
    virtual bool SetLeafTextureVariant(unsigned char);
    virtual bool SetTexturingProperty(NiTexturingProperty*);
    virtual void SetWindAmplitude(float);

    void UpdateSpeedTree(CSpeedTreeRT*, float);
    bhkSimpleShapePhantom* GetLeafObject();
    bool CheckForCollision(float);
    NiAVObject* __thiscall GetFirstChild();
    NiAVObject* __thiscall FUN_0066b5e0();
    NiAVObject* FUN_0066b600();
    void __thiscall FUN_0066b6c0();
    void* __thiscall FUN_0066b680(unsigned int);
    bool FUN_0066be30(unsigned char);

    union
    {
        char _pad_e4[44];
        struct ModelAlias
        {
            NiNode* m_pObject;

            NiNode* operator->() const
            {
                return reinterpret_cast<const NiPointer<NiNode>*>(&m_pObject)->operator->();
            }
        } model;
        struct
        {
            NiPointer<BSTreeModel> m_spModel;
            NiPointer<NiTriBasedGeom>* m_pBranchMeshes;
            NiPointer<NiTriBasedGeom>* m_pFrondMeshes;
            NiPointer<NiTriBasedGeom> m_spLeafMesh;
            float m_fWindTime;
            unsigned char unkF8[24];
        };
    };
    char spModel[4];
    void* pspBranches;
    void* pspLeaves;
    char spBillboard[4];
    float fNextCollisionCheck;
    char _pad_124[12];
};
