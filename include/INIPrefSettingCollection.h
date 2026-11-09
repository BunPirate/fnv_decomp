#pragma once

#include "INISettingCollection.h"

// pdb: class INIPrefSettingCollection, size 0x114, bases: INISettingCollection, 0 members
class INIPrefSettingCollection : public INISettingCollection
{
public:
    INIPrefSettingCollection();
    virtual ~INIPrefSettingCollection();
    virtual void Add(Setting* setting);
    virtual void Remove(Setting* setting);
};
