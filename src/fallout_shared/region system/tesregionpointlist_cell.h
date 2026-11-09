// Region-list accessors for the cell extra-data list at TESObjectCELL offset 0x28.
// ExtraDataList does not yet declare these two methods.

class TESRegionPointList_CellExtraList
{
  public:
    TESRegionList* ExtraDataList_GetRegionList();
    void ExtraDataList_SetRegionList(TESRegionList*);
};
