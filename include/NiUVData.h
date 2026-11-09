#pragma once

#include "NiObject.h"
#include "StrArr.h"

class TimedAnimationKey;
class NiUVKey;
class NiUVStream;
struct NiStreamX;

enum NiUVKeyType
{
    NOINTERP,
    LINKEY,
    BEZKEY,
    TCBKEY,
    EULERKEY,
    STEPKEY,
    NUMKEYTYPES
};

// pdb: class NiUVData, size 0x4c, bases: NiObject, 20 members
class NiUVData : public NiObject
{
public:
    virtual ~NiUVData();
    virtual const NiRTTI* GetRTTI() const;
    virtual void LoadBinary(NiStream& arStream);
    virtual void SaveBinary(NiStream& arStream);
    virtual bool IsEqual(NiObject* apObject) const;
    virtual void GetViewerStrings(NiViewerStringsArray* apStrings);

    void Destructor();
    void* FUN_00a45200(unsigned int flags);
    void ReplaceUOffsetAnim(TimedAnimationKey* pkKeys, unsigned int uiNumKeys, unsigned int eType);
    void ReplaceVOffsetAnim(void* pkKeys, unsigned int uiNumKeys, int eType);
    void ReplaceUTilingAnim(void* pkKeys, unsigned int uiNumKeys, unsigned int eType);
    void ReplaceVTilingAnim(void* pkKeys, unsigned int uiNumKeys, unsigned int eType);
    bool IsEqual_00a45090(NiUVData* pkOther);
    void FUN_00a453a0(NiUVStream& kStream);
    void FUN_00a45610(NiStreamX& kStream);
    void AppendKeyNames(StrArr* pStrings);
    void ReplaceUOffsetKeys(NiUVKey* pkKeys, unsigned int uiNumKeys, NiUVKeyType eType);
    void ReplaceVOffsetKeys(NiUVKey* pkKeys, unsigned int uiNumKeys, NiUVKeyType eType);
    void ReplaceUTilingKeys(NiUVKey* pkKeys, unsigned int uiNumKeys, NiUVKeyType eType);
    void ReplaceVTilingKeys(NiUVKey* pkKeys, unsigned int uiNumKeys, NiUVKeyType eType);
    static unsigned char* GetKeyPointerByIndex(unsigned char* pk, unsigned int i, unsigned char uc);

    unsigned int m_uiNumUOffsetKeys;
    unsigned char* m_pkUOffsetKeys;
    unsigned int m_eUOffsetType;
    unsigned int m_uiNumVOffsetKeys;
    unsigned char* m_pkVOffsetKeys;
    unsigned int m_eVOffsetType;
    unsigned int m_uiNumUTilingKeys;
    unsigned char* m_pkUTilingKeys;
    unsigned int m_eUTilingType;
    unsigned int m_uiNumVTilingKeys;
    unsigned char* m_pkVTilingKeys;
    unsigned int m_eVTilingType;
    int m_fLastUOffset;
    int m_fLastVOffset;
    int m_fLastUTiling;
    int m_fLastVTiling;
    unsigned char m_ucUOffsetSize;
    unsigned char m_ucVOffsetSize;
    unsigned char m_ucUTilingSize;
    unsigned char m_ucVTilingSize;
};
