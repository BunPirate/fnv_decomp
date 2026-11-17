#pragma once

#include "bhkSerializable.h"

// pdb: class bhkCharacterProxy, size 0x3e0 (here 0xc), bases: bhkSerializable, 1 members
class bhkCharacterProxy : public bhkSerializable
{
public:
    virtual ~bhkCharacterProxy();

    virtual const NiRTTI* GetRTTI() const;
};
