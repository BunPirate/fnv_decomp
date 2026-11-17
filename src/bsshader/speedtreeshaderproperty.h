
// @fnv 0x00407840
unsigned int TESPackage::GetRefCount()
{
    return uiRefCount;
}
// @fnv 0x008d83e0
// pdb: BSTreeNode::GetModel | BSTreeNode.obj | debug, vtable slot, medium
BSTreeModel* BSTreeNode::GetModelFilePath()
{
    return reinterpret_cast<BSTreeModel*>(model.operator->());
}
