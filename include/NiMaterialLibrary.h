#pragma once

#include "NiRefObject.h"
#include "NiFixedString.h"

// pdb: class NiMaterialLibrary, size 0xc, bases: NiRefObject, 1 members
class NiMaterialLibrary : public NiRefObject
{
public:
    __declspec(nothrow) NiMaterialLibrary(const NiFixedString& kName);
    virtual ~NiMaterialLibrary();

    NiFixedString m_kName;
};
