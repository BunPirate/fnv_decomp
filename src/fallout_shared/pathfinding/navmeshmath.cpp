
// src/fallout_shared/pathfinding/navmeshmath.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/pathfinding/navmeshmath.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../include/NiPoint2.h"
#include "../../../include/NiPoint3.h"
bool __cdecl ComputeBarycentricCoordinates(const NiPoint2&, const NiPoint2&, const NiPoint2&, const NiPoint2&,
                                           NiPoint3*);
// @fnv 0x006b9790
// src: XBOX_PDB 0x006b9790
// pdb: NavMeshMath::Get2DBaryCentricCoord | NavMeshMath.obj | retail, upstream name already matches, high
// pdb params: aV0, aV1, aV2, aLoc, aCoord
bool __cdecl NavMeshMath_Get2DBaryCentricCoord(const NiPoint3& aV0, const NiPoint3& aV1, const NiPoint3& aV2,
                          const NiPoint3& aLoc, NiPoint3* aCoord)
{
    return ComputeBarycentricCoordinates(NiPoint2(aV0.x, aV0.y), NiPoint2(aV1.x, aV1.y),
                                         NiPoint2(aV2.x, aV2.y), NiPoint2(aLoc.x, aLoc.y), aCoord);
}
