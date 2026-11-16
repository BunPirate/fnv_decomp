#pragma once

#include <cstddef>
#include "NiObject.h"

class hkReferencedObject;

// pdb: class bhkRefObject, size 0xc, bases: NiObject, 1 members
class bhkRefObject : public NiObject
{
public:
    bhkRefObject();
    virtual ~bhkRefObject();

    virtual void* GetReferencedData();
    virtual void* GetReferencedDataSafe();

    int Initialize();
    bhkRefObject* InitializeFields_00ccd100();
    void Destroy();
    void UpdateReference(bool);

    hkReferencedObject* phkObject; // src: XBOX_RETAIL_PDB +0x8 (old: m_pHavokObject)
};
