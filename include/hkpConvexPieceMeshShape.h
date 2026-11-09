#pragma once

#include "hkpShapeCollection.h"

class hkpConvexPieceStreamData;

// pdb: class hkpConvexPieceMeshShape, size 0x24, bases: hkpShapeCollection, 3 members
class hkpConvexPieceMeshShape : public hkpShapeCollection
{
public:
    virtual void calcContentStatistics(hkStatisticsCollector* collector, const hkClass* cls) const;
    void CollectShapeStatistics(hkStatisticsCollector* pkCollector, const hkClass* pkClass) const throw();

    hkpConvexPieceStreamData* m_convexPieceStream;
    hkpShapeCollection* m_displayMesh;
    hkReal m_radius;
};
