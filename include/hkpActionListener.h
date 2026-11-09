#pragma once

class hkpAction;

// pdb: class hkpActionListener, size 0x4, 0 members
class hkpActionListener
{
public:
    virtual ~hkpActionListener();
    virtual void ActionAddedCallback(hkpAction*);
    virtual void ActionRemovedCallback(hkpAction*);

    void actionShapeSetCallback(hkpAction*);
    void actionDeletedCallback(hkpAction*);
    void destroy();
    void a04();
    void a08();
};
