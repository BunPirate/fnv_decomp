#pragma once

#include <stddef.h>
#include "NiPoint3.h"

class V3;
class Depth;
class OBBShape;
class OBBCollisionRecord;

// pdb: class NiOBBNode, size 0x8c, 4 members
class NiOBBNode
{
public:
    virtual ~NiOBBNode();
    virtual bool IsTerminalNode();
    virtual bool CompareTreeRecursive(NiOBBNode* pTestNode, char* pkObj0, char* pkObj1,
                                      int iMaxDepth, int iTestMaxDepth, int uiChangeStamp0, int uiChangeStamp1);
    virtual int Intersect(NiOBBNode* other, void* a2, void* a3, void* a4, void* a5,
                          int depthA, Depth depthB, int idA, int idB, void* a10);
    virtual int TestChildren(void* origin, void* dir, int pick, int bIntersects, void* pObj, int uiChangeStamp);

    struct BoundsMatrix
    {
        NiPoint3 row0;
        NiPoint3 row1;
        NiPoint3 row2;
    };

    NiPoint3 m_box; // src: XBOX_RETAIL_PDB +0x4 (old: center)
    BoundsMatrix matrix;
    NiPoint3 extent;
    NiPoint3 m_kCenter;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    union
    {
        int unk7c;
        OBBShape* m_pkShape;
    };
    int m_pLeft; // src: XBOX_RETAIL_PDB +0x80 (old: m_0x80)
    int m_pRight; // src: XBOX_RETAIL_PDB +0x84 (old: m_0x84)
    int m_uiChangeStamp; // src: XBOX_RETAIL_PDB +0x88 (old: m_0x88)

    char* GetBoundsData()
    {
        return reinterpret_cast<char*>(&m_box);
    }
    const char* GetBoundsData() const
    {
        return reinterpret_cast<const char*>(&m_box);
    }
    __declspec(property(get=GetBoundsData)) char* pad1;

    NiOBBNode();
    static void* operator new(size_t size);

    bool HasChildren();
    int NiOBBNode_BoxBoxCollision(NiOBBNode* other, int a, int b, int c, int d, bool* hit);
    int NiOBBNode_BoxBoxCollision(NiOBBNode* other, void* a2, void* a3, void* a4, void* a5, void* a10);
    int RunSwapTests(OBBCollisionRecord* record);
    void BuildNode(void* a0, const unsigned short* indices, const V3* vertices,
                   const V3* a3, float* weights, V3* centroids, int first, int last,
                   int* triangleMap, int* order, int minimum);
    void ComputeTriangleBounds(void* a0, const unsigned short* indices, const V3* vertices,
                               float* weights, V3* centroids, int first, int last,
                               int* triangleMap);
    void ComputeTriangleBounds(int a0, unsigned short* indices, V3* vertices,
                               int weights, int centroids, int first, int last,
                               int* triangleMap);
    void ComputeWeightedCovariance(void* covariance, unsigned short* indices, V3* vertices,
                                   int weights, int centroids, int first, int last,
                                   int* triangleMap);
    __declspec(noalias) void NiOBBNode_DivideTriangles(V3* vertices, int first, int last,
                                         int* sourceIndices, int* left, int* right,
                                         int* destinationIndices);
    void NiOBBNode_DivideTriangles(const V3* vertices, int first, int last, const int* sourceIndices,
                      int* left, int* right, int* destinationIndices);
};
