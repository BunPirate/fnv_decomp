#pragma once

#include "BSExtraData.h"

namespace extra_save
{
class SForm;
}

// pdb: class ExtraInfoGeneralTopic, size 0x10, bases: BSExtraData, 1 members
class ExtraInfoGeneralTopic : public BSExtraData
{
public:
    ExtraInfoGeneralTopic(void* topic);
    virtual ~ExtraInfoGeneralTopic();

    void* FUN_00432440(unsigned int flags);

    extra_save::SForm* topic;
};
