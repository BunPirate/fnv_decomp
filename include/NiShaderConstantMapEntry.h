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

    unsigned int m_bEnabled; // src: XBOX_RETAIL_PDB +0x8 (old: unk08)
    NiFixedString m_kKey; // src: XBOX_RETAIL_PDB +0xc (old: m_kControlPoint)
    unsigned int m_uiInternal; // src: XBOX_RETAIL_PDB +0x10 (old: unk10)
    unsigned int m_uiFlags; // src: XBOX_RETAIL_PDB +0x14 (old: m_uiValue1)
    unsigned int m_uiExtra; // src: XBOX_RETAIL_PDB +0x18 (old: m_uiValue2)
    unsigned int m_uiShaderRegister; // src: XBOX_RETAIL_PDB +0x1c (old: m_uiValue3)
    unsigned int m_uiRegisterCount; // src: XBOX_RETAIL_PDB +0x20 (old: m_uiValue4)
    NiFixedString m_kVariableName; // src: XBOX_RETAIL_PDB +0x24 (old: m_kSecondaryString)
    unsigned int m_uiDataSize; // src: XBOX_RETAIL_PDB +0x28 (old: m_uiValue5)
    unsigned int m_uiDataStride; // src: XBOX_RETAIL_PDB +0x2c (old: m_uiValue6)
    void* m_pvDataSource; // src: XBOX_RETAIL_PDB +0x30 (old: m_pConstantData)
    bool m_bOwnData; // src: XBOX_RETAIL_PDB +0x34 (old: m_bFlag0)
};
