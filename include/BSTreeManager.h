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
    NiTPointerMap<TESObjectTREE*, NiPointer<BSTreeModel>*>* pModelMap; // src: XBOX_RETAIL_PDB +0x0 (old: m_pLoadedModelMap)
    NiPointer<NiTexture> spCanopyShadow; // src: XBOX_RETAIL_PDB +0x4 (old: m_pTreeTexture)
    NiPointer<NiMaterialProperty> spBillboardMatProp; // src: XBOX_RETAIL_PDB +0x8 (old: m_spMaterialProperty)
    NiPointer<NiAlphaProperty> spDistantAlphaProp; // src: XBOX_RETAIL_PDB +0xc (old: m_pAlphaProperty)
    NiPointer<BSXFlags> spHavokFlags; // src: XBOX_RETAIL_PDB +0x10 (old: m_pBSXFlags)
    float fWindSpeed; // src: XBOX_RETAIL_PDB +0x14 (old: m_fCurrentWeatherBlend)
    bool bShowTrees; // src: XBOX_RETAIL_PDB +0x18 (old: m_bFirstOfFourFlags)
    bool bShowLeaves; // src: XBOX_RETAIL_PDB +0x19 (old: m_bSecondOfFourFlags)
    bool bForceCompute; // src: XBOX_RETAIL_PDB +0x1a (old: ReferenceTreeManagerState)
    bool m_bForceFullLOD; // src: XBOX_RETAIL_PDB +0x1b (old: m_bFourthTreeManagerFlag)
    LockFreeMap_TESObjectREFR___BSTreeNode___* pBackgroundLoadedTreeMap; // src: XBOX_RETAIL_PDB +0x1c (old: m_pTreeInstanceMap)

    BSTreeManager();
    static void Create(bool);
    static void ClearCanopyShadow();
    BSTreeNode* CreateTreeInstance(int, int);
};
