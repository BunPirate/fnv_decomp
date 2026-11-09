#pragma once

#include "NiInterpController.h"
#include "NiMorphData.h"
#include "NiPointer.h"

// pdb: class NiGeomMorpherController, size 0x44, bases: NiInterpController, 7 members
class NiGeomMorpherController : public NiInterpController
{
public:
    struct InterpItem
    {
        NiPointer<NiInterpolator> m_spInterpolator;
        float m_fWeight;

        __declspec(nothrow) InterpItem();
        __declspec(nothrow) ~InterpItem();
        static void* operator new[](unsigned int size) throw();
        static void operator delete[](void* p) throw();
    };

    NiGeomMorpherController(NiMorphData* pkData = 0) throw()
        : m_spMorphData(pkData), m_pkInterpItems(0)
    {
        m_uFlags = 0;
        m_bNeedPreDisplay = false;
        m_bIgnoreBaseTarget = false;
        m_bAlwaysUpdate = false;
        m_bBoundCalculated = false;
    }
    virtual ~NiGeomMorpherController() throw();
    virtual NiObject* MakeClone(CloningProcess& kCloning);

    virtual unsigned short GetTargetCount() const;
    virtual unsigned short GetTargetIndex(const char* pcID) const;
    virtual unsigned short GetTargetIndex(const NiFixedString& kID) const;

    virtual void vf58();
    virtual void vf59();

    unsigned int GetNumTargets() const;
    void CopyMemberData(NiGeomMorpherController* pkClone, CloningProcess& kCloning);
    void SetMorphData(NiMorphData* pkData, bool bCalculateMorphBound);
    void AllocateInterpArray();

    unsigned short m_uFlags;
    unsigned char m_aucPad[2];
    NiPointer<NiMorphData> m_spMorphData;
    InterpItem* m_pkInterpItems;
    bool m_bNeedPreDisplay;
    bool m_bIgnoreBaseTarget;
    bool m_bAlwaysUpdate;
    bool m_bBoundCalculated;
};

