#pragma once

#include "hkpCharacterProxyListener.h"

// pdb: class bhkCharacterListener, size 0x70, bases: hkpCharacterProxyListener, 13 members
class bhkCharacterListener : public hkpCharacterProxyListener
{
public:
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();

    unsigned char iFlags[0x6C];

    unsigned int GetFlags(unsigned int aiFlags);
};
