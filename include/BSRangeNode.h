#pragma once

#include "BSNiNode.h"

// pdb: class BSRangeNode, size 0xe0 (here 0xb0), bases: BSNiNode, 4 members
class BSRangeNode : public BSNiNode
{
public:
    BSRangeNode();
    virtual ~BSRangeNode();
    virtual const NiRTTI* GetRTTI() const;
    virtual NiObject* MakeClone(CloningProcess& process);
    virtual void LoadBinary(NiStream& stream);
    virtual void LinkObject(NiStream& stream);
    virtual bool RegisterStreamables(NiStream& stream);
    virtual void SaveBinary(NiStream& stream);
    virtual bool IsEqual(NiObject* object) const;
    virtual void GetViewerStrings(NiViewerStringsArray* strings);
    virtual void ParseNameForRanges();

    void CopyMemberData(BSRangeNode* target, CloningProcess* process);
    static NiObject* CreateObject();
    unsigned char QMin();
    unsigned char QMax();
    unsigned char QCurrent();
    bool QEnabled();
    void SetMin(unsigned char minimum);
    void SetMax(unsigned char maximum);
    bool SetCurrent(unsigned char current);
    static int* QVisibilityChangedCB();
    static void SetVisibilityChangedCB(int* callback);

    unsigned char unkAC;
    unsigned char unkAD;
    unsigned char unkAE;
    unsigned char unkAF;
};
