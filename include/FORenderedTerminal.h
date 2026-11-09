#pragma once

#include "FORenderedMenu.h"
#include "NiPoint3.h"

class TilePX;

// pdb: class FORenderedTerminal, size 0xf0, bases: FORenderedMenu, 4 members
class FORenderedTerminal : public FORenderedMenu
{
public:
    struct NodeHandle
    {
        NiAVObject* m_pObject;

        NodeHandle(int);
        ~NodeHandle();
        operator NiAVObject*() const;
    };

    FORenderedTerminal();
    virtual ~FORenderedTerminal();

    NiAVObject* GetTerminalScreenObject();
    NiAVObject* GetParentNodeToRender();
    void FUN_007060d0();
    void* DestroyIfFlagged(unsigned int);
    void FORenderedTerminal_FadeOut();
    void FUN_00984f60(TilePX* item);
    void SetTarget_00705fc0(NiNode* node);
    void Refresh();

    NiPoint3 OriginalPos;
    NodeHandle spExitButton;
    float fLastFadePercent;
    unsigned char bFadingOut;
    unsigned char unkED[3];
};
