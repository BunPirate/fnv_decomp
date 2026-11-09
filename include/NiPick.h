#pragma once

#include "NiAVObject.h"
#include "NiPoint2.h"
#include "NiPoint3.h"

class NiNode;
class NiPickResults;
class PickRecord;
class PickNode;
class NiPoint3;

// pdb: class NiPick, size 0x34, 13 members
class NiPick
{
public:
    enum PickType { FIND_ALL = 0, FIND_FIRST = 1 };
    enum SortType { SORT = 0, NO_SORT = 1 };
    enum IntersectType { BOUND_INTERSECT = 0, TRIANGLE_INTERSECT = 1 };
    enum CoordinateType { MODEL_COORDINATES = 0, WORLD_COORDINATES = 1 };

    class Record
    {
    public:
        NiPointer<NiAVObject> m_spObject;
        NiPointer<NiNode> m_spProxyParent;
        NiPoint3 m_intersect;
        float m_fDistance;
        unsigned short m_usTriangleIndex;
        unsigned short m_usVertexIndex[3];
        float m_texture[2];
        NiPoint3 m_normal;
        float m_color[4];

        NiAVObject* AnimatingText_GetFullText();
        const NiPoint2* FUN_00891170();
    };

    class Results
    {
    public:
        void** m_ppVirtualMethodTable;
        union { Record** m_pBase; Record** data; };
        union { unsigned short m_usMaxSize; unsigned short capacity; };
        union { unsigned short m_usSize; unsigned short size; };
        union { unsigned short m_usESize; unsigned short effective; };
        union { unsigned short m_usGrowBy; unsigned short grow; };
        union { unsigned int m_uiValidCount; unsigned int valid; };

        ~Results();
        Record* GetAt(unsigned int index) const
        {
            return m_pBase[index];
        }
        void SetAt(unsigned int index, Record* record)
        {
            if (index >= m_usSize)
            {
                m_usSize = (unsigned short)(index + 1);
                ++m_usESize;
            }
            else if (!m_pBase[index])
            {
                ++m_usESize;
            }
            m_pBase[index] = record;
        }
        Record* ProcessArray_GetItem(unsigned int);
        void NiPick_Results_SortResults();
        void NiPick_Results_FindClosest();
        void Clear() throw();
    };

    unsigned int m_ePickType;
    unsigned int m_eSortType;
    unsigned int m_eIntersectType;
    unsigned int m_eCoordinateType;
    unsigned char m_bFrontOnly;
    unsigned char m_bObserveAppCullFlag;
    unsigned char returnTextures;
    unsigned char returnColors;
    void* m_spRoot;
    unsigned int m_pickResults;
    unsigned int resultData;
    unsigned int resultCapacity;
    unsigned int resultSize;
    unsigned int resultGrow;
    unsigned int m_pLastAddedRecord;
    unsigned char m_bReturnTexture;
    unsigned char m_bReturnNormal;
    unsigned char m_bReturnSmoothNormal;
    unsigned char m_bReturnColor;

    NiPick();
    NiPick(int, int);
    ~NiPick();
    NiAVObject* GetRoot() const
    {
        return static_cast<NiAVObject*>(m_spRoot);
    }
    void SetTarget_00705fc0(NiAVObject*);
    void SetTarget_00705fc0(void*);
    void SetTarget_00705fc0(PickNode*);
    void SetByteAtOffset17(bool);
    void SetByteAtOffset17(int);
    bool FUN_00e98e20(const NiPoint3&, const NiPoint3&, bool);
    bool FUN_00e98e20(const NiPoint3&, const NiPoint3&, int);
    bool FUN_00e98e20(NiPoint3*, NiPoint3*, int);
    bool FUN_00e98e20(NiPoint3&, NiPoint3&, bool);
    Results* FUN_00500940();
    PickRecord* FUN_00500940(unsigned int);
    void FUN_006ecd40(int);
    void FUN_006ecd40(unsigned int);
    void SetByteAtOffset30(bool);
    void SetByteAtOffset30(int);
    bool PerformPick(const NiPoint3&, const NiPoint3&, bool);
    NiAVObject* AnimatingText_GetFullText();
    const NiPoint2* FUN_00891170();
    Record* ProcessArray_GetItem(unsigned int);
    NiPickResults* GetResults();
    void RadioEntry_Data_SetLastSignalStrength(bool bValue);
    void* ScalarDeletingDestructor(unsigned int flags);
    void InvokeCallbacks();
    void FindHighestPriorityCallback();
    void Clear() throw();
};
