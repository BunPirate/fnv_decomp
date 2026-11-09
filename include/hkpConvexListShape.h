#pragma once

#include "hkpConvexShape.h"
#include "hkpShapeContainer.h"
#include "hkVector4.h"
#include "hkBool.h"
#include "hkArray.h"
#include "hkaAnimation.h"

// pdb: class hkpConvexListShape, size 0x50, bases: hkpConvexShape, hkpShapeContainer, 5 members
class hkpConvexListShape : public hkpConvexShape, public hkpShapeContainer
{
public:
    hkpConvexListShape(hkpConvexShape** shapeArray, int numShapes) throw();
    virtual ~hkpConvexListShape() throw();

    virtual void vf17();

    void setShapesAndRadius(hkpConvexShape** shapeArray, int numShapes) throw();
    void setUseCachedAabb(bool useCachedAabb) throw();
    void hkReferencedObject_calcContentStatistics(hkStatisticsCollector* collector, int* cls);
    void calcContentStatistics_00d5e480(hkStatisticsCollector* collector, int cls);

    union
    {
        hkReal m_fMaximumRadius;
        float m_minDistanceToUseConvexHull;
    };
    char pad1C[0x4];
    hkVector4 m_aabbHalfExtents;
    hkVector4 m_aabbCenter;
    hkBool m_useCachedAabb;
    char pad41[0x3];
    hkArray<hkpConvexShape*> m_childShapes;
};
