#pragma once

#include "BSExtraData.h"

class TESTopic;
class TESTopicInfo;

// pdb: class ExtraSayToTopicInfo, size 0x1c, bases: BSExtraData, 4 members
struct ExtraSayToTopicInfo : public BSExtraData
{
public:
    ExtraSayToTopicInfo();
    ExtraSayToTopicInfo(TESTopicInfo*);
    ExtraSayToTopicInfo(int);
    virtual ~ExtraSayToTopicInfo();

    void __vslot_0();
    void SetTopic(TESTopic*);
    void SetVoiceDone(bool);

    TESTopicInfo* pInfo;
    TESTopic* pTopic;
    unsigned int m_uiTopicInfoValue;
    bool m_bTopicInfoFlag;
    char _pad_19[3];
};
