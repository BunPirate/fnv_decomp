#pragma once

#include "NiTPointerMap.h"

class ChangeData;
class TESForm;

// pdb: class ChangesMap, size 0x10, bases: NiTPointerMap<unsigned int, 0 members
class ChangesMap : public NiTPointerMap<unsigned int, ChangeData*>
{
public:
    virtual ~ChangesMap();
    virtual void DeleteAllEntries();

    ChangesMap();
    bool HasFormChanges(TESForm*, bool);
    bool RemoveChanges(unsigned int, bool);
};
