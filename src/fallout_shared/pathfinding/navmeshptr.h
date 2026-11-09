
#include "navmeshptr_decls.h"

// @fnv 0x00690860
// pdb: NavMeshPtr::MakeNavMeshPtr | NavMesh.obj | retail, call graph (shared callers), low
// pdb note: debug build links it to NavMeshInfo::GetNavMeshEvenDisabled
// pdb params: arNavmeshPtr, apNavMesh
bool NavMeshInfo::AcquireNavMesh(NavMeshPtr& out)
{
    ProcessWithScopedRef(out, pNavMesh);
    return pNavMesh != 0;
}
