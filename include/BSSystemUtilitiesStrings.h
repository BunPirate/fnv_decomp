#pragma once

// pdb: class BSSystemUtilitiesStrings, size 0x24, 1 members
class BSSystemUtilitiesStrings
{
public:
    char* pcStrings[8]; // src: XBOX_RETAIL_PDB +0x4 (old: m_pStringFunctions)

    virtual ~BSSystemUtilitiesStrings();
    virtual void Initialize();
    virtual void Destroy();

    void SetStringAt(unsigned int index, const char* str);
    void CallVTableMethod();
    void* DestroyIfFlagged(unsigned int flags);
    void SetVirtualTable_00af35c0();
};
