class BGSReconstructCellSubBlocksMap;
class GlobalObject_004ee810
{
  public:
    void BSSimpleList_NiPointer_bhkAction_RemoveAll();
};
extern GlobalObject_004ee810 g_011d6a30;
extern unsigned int DAT_011d6a20;
// 0x0048eff0 forwards a loader request to 0x00445370 with its flag set.
// That callee uses fields through +0x2c; this is not a NiTMap operation.
// pdb: class ModelLoader, size 0x30 (here 0x1), 12 members
class ModelLoader
{
  public:
    void ReleaseKFFile_0048eff0(unsigned int key);
    void ModelLoader_ReleaseKF(unsigned int apKFFileName, bool abDeleteIfUnreferenced);
};
