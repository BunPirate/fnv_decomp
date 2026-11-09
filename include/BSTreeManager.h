#pragma once

#include "NiPointer.h"

class BSTreeModel;
class BSTreeNode;
class BSXFlags;
class LockFreeMap_TESObjectREFR___BSTreeNode___;
class NiAlphaProperty;
class NiMaterialProperty;
class NiTexture;
class TESObjectTREE;
template <class TKEY, class TVAL> class NiTPointerMap;

// pdb: class BSTreeManager, size 0x20, 11 members
class BSTreeManager
{
public:
    NiTPointerMap<TESObjectTREE*, NiPointer<BSTreeModel>*>* pModelMap;
    NiPointer<NiTexture> spCanopyShadow;
    NiPointer<NiMaterialProperty> spBillboardMatProp;
    NiPointer<NiAlphaProperty> spDistantAlphaProp;
    NiPointer<BSXFlags> spHavokFlags;
    float fWindSpeed;
    bool bShowTrees;
    bool bShowLeaves;
    bool bForceCompute;
    bool m_bForceFullLOD;
    LockFreeMap_TESObjectREFR___BSTreeNode___* pBackgroundLoadedTreeMap;

    BSTreeManager();
    static void Create(bool);
    static void ClearCanopyShadow();
    BSTreeNode* CreateTreeInstance(int, int);
};
