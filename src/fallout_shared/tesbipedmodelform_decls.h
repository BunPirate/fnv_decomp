// fallout_shared/tesbipedmodelform_decls.h: declares BGSListForm, BSFaceGenModelExtraData, NiNode, BipedAnim, ModelLoader
#ifndef FNV_TESBIPEDMODELFORM_DECLS_H
#define FNV_TESBIPEDMODELFORM_DECLS_H

class BSExtraData;
class InventoryChanges;
class TESBoundObject;
class TESObjectCELL;
class CellDataNode;
class ValidBip01Names;
class TESForm;
class TESModel;
class BSFaceGenModel;
class BGSListForm;
template <class T> class BSSimpleList;
#include "tesbipedmodelform_types_BIPED_OBJECT.h"
#include "../../include/BGSListForm.h"
#include "../../include/BSFaceGenModelExtraData.h"
#include "../../include/NiNode.h"
// pdb: class BipedAnim, size 0x2b4 (here 0x1), 6 members
class BipedAnim
{
  public:
    void SetBipedPart(TESForm*, TESModel*, BIPED_OBJECT);
    NiNode* FUN_0043f010(BSFaceGenModel*);
};
// pdb: class ModelLoader, size 0x30 (here 0x1), 12 members
class ModelLoader
{
  public:
    void ModelLoader_FindModel(BSFaceGenModel*, NiPointer<BSFaceGenModelExtraData>*);
};
extern ModelLoader* g_modelLoader;
#endif
