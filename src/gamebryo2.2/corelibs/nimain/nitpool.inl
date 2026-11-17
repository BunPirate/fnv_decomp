
#include "nitpool_decls.h"
template<>
// @fnv 0x00e7f160
// pdb: NiTPool<NiD3DRenderStateGroup::NiD3DRSEntry,NiTNewInterface<NiD3DRenderStateGroup::NiD3DRSEntry> >::CreateNewObjects | NiD3DRenderStateGroup.obj | retail, object-file run extension, low
// pdb note: debug build links it to NiD3DPass::NiD3DPass
// pdb params: uiSize
// pdb locals: pkNewContainer, i
void ObjectPool<D3DRenderStateGroup,NiTNewInterface<D3DRenderStateGroup> >::AddPoolBlock(unsigned int n) {
 ObjectPoolBlock<D3DRenderStateGroup,NiTNewInterface<D3DRenderStateGroup> >* p = new ObjectPoolBlock<D3DRenderStateGroup,NiTNewInterface<D3DRenderStateGroup> >(n);
 for (unsigned int i=0; i<n; ++i) freeObjects.Add(p->GetAt(i));
 p->next = containers;
 containers = p;
}
