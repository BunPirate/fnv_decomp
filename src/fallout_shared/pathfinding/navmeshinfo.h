
#include "navmeshinfo_decls.h"
// @fnv 0x0069ad00
// pdb: NavMeshInfo::GetNavMesh | NavMesh_Util.obj | debug, call graph, high
// pdb params: aReturnNavMeshPtr
bool NavMeshInfo::ResolveNavMesh(NavMeshPtr& aReturnNavMeshPtr)
{
    if (NavMeshInfo_GetDisabled())
        return false;
    ProcessWithScopedRef(aReturnNavMeshPtr, pNavMesh);
    return aReturnNavMeshPtr.Modelloader_GetReferencedThis() ? true : false;
}
// @fnv 0x006dd6a0
// pdb: PathingLocation::HasNavMeshData | PathingLocation.obj | debug, call graph, high
bool PathingLocation::HasValidTriangle()
{
    if (pNavMesh == 0)
        return false;
    if (!pNavMesh->HasNonZeroAtOffset54())
        return false;
    if (usTriangle == 0xffff)
        return false;
    return true;
}
