#pragma once

#include "NiRefObject.h"
#include "NiFixedString.h"

struct ScriptAttributeTypes
{
    enum AttributeType
    {
        ATTRIB_TYPE_BOOL = 1,
        ATTRIB_TYPE_INT = 3
    };
};

// pdb: class NiShaderConstantMapEntry, size 0x38, bases: NiRefObject, 14 members
class NiShaderConstantMapEntry : public NiRefObject
{
public:
    NiShaderConstantMapEntry() throw();
    virtual ~NiShaderConstantMapEntry();
    __declspec(noalias) __declspec(nothrow) virtual void DeleteThis() throw();

    void IncRefCount();
    void DecRefCount();
    ScriptAttributeTypes::AttributeType GetAttributeType() const;

    unsigned int m_bEnabled;
    NiFixedString m_kKey;
    unsigned int m_uiInternal;
    unsigned int m_uiFlags;
    unsigned int m_uiExtra;
    unsigned int m_uiShaderRegister;
    unsigned int m_uiRegisterCount;
    NiFixedString m_kVariableName;
    unsigned int m_uiDataSize;
    unsigned int m_uiDataStride;
    void* m_pvDataSource;
    bool m_bOwnData;
};
