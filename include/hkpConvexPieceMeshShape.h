#pragma once

#include "hkpShapeCollection.h"

class hkpConvexPieceStreamData;

// pdb: class hkpConvexPieceMeshShape, size 0x24, bases: hkpShapeCollection, 3 members
class hkpConvexPieceMeshShape : public hkpShapeCollection
{
public:
    virtual void calcContentStatistics(hkStatisticsCollector* collector, const hkClass* cls) const;
    void CollectShapeStatistics(hkStatisticsCollector* pkCollector, const hkClass* pkClass) const throw();

    hkpConvexPieceStreamData* m_convexPieceStream; // src: XBOX_RETAIL_PDB +0x18 (old: m_pConvexPieceStreamData)
    hkpShapeCollection* m_displayMesh; // src: XBOX_RETAIL_PDB +0x1c (old: m_pDisplayMesh)
    hkReal m_radius; // src: XBOX_RETAIL_PDB +0x20 (old: m_fSphereRadius)
};
