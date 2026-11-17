#pragma once

#include "BSSaveDataSystemUtility__SaveDataEntry.h"

class BSSaveDataOperationEntry;

// pdb: class BSSaveDataSystemUtility, size 0x48, 10 members
class BSSaveDataSystemUtility
{
public:
    enum OPERATION
    {
        OPERATION_NONE = 0,
        OPERATION_SAVE = 1,
        OPERATION_LOAD = 2,
        OPERATION_DELETE = 3,
        OPERATION_AUTOSAVE = 4,
        OPERATION_AUTOLOAD = 5,
    };

    enum RESULT
    {
        RESULT_SUCCESS = 0,
        RESULT_CANCEL = 1,
        RESULT_FAILED = 2,
    };

    enum RESULT_FAILED_REASON
    {
        RESULT_FAILED_REASON_NO_DATA = 0,
        RESULT_FAILED_REASON_INSUFFICIENT_SPACE = 1,
        RESULT_FAILED_REASON_DATA_CORRUPT = 2,
        RESULT_FAILED_REASON_UNKNOWN = 3,
    };

    virtual void* vf00(unsigned int flags);
    virtual void vf04();
    virtual void Destroy();
    virtual unsigned int vf0C(const char*, int, int);  // 0x00aaa650: returns 0
    virtual bool vf10(const char*, void*);
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C(int);
    virtual void vf20();
    virtual void vf24();

    bool bIsActive;
    unsigned char layoutPadding5;
    unsigned short layoutPadding6;
    BSSaveDataOperationEntry* pSaveDataFile; // src: XBOX_RETAIL_PDB +0x8 (old: m_pOperationContext)
    BSSaveDataSystemUtility__SaveDataEntry MostRecentEntry; // src: XBOX_RETAIL_PDB +0xc (old: m_kSaveDataEntry)
    OPERATION eCurrentOperation; // src: XBOX_RETAIL_PDB +0x2c (old: m_eOperation)
    RESULT eSaveResult; // src: XBOX_RETAIL_PDB +0x30 (old: m_eResult)
    RESULT eLoadResult; // src: XBOX_RETAIL_PDB +0x34 (old: m_eSecondResult)
    RESULT eDeleteResult; // src: XBOX_RETAIL_PDB +0x38 (old: m_eThirdResult)
    RESULT_FAILED_REASON eResultFailedReason; // src: XBOX_RETAIL_PDB +0x3c (old: m_eFailedReason)
    unsigned int uiInsufficientSpaceFileSize; // src: XBOX_RETAIL_PDB +0x40 (old: m_uiResultCount)
    void (__cdecl* pDeleteCompleteCallback)(RESULT); // src: XBOX_RETAIL_PDB +0x44 (old: m_pResultCallback)

    void SetResultCallback(void (__cdecl* apCallback)(RESULT));  // 0x008d8040 (folded +0x44 setter)
};
