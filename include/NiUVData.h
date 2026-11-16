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
    unsigned char* m_pkUOffsetKeys; // src: XBOX_RETAIL_PDB +0xc (old: m_pUOffsetKeys)
    unsigned int m_eUOffsetType; // src: XBOX_RETAIL_PDB +0x10 (old: m_uiUOffsetKeyStride)
    unsigned int m_uiNumVOffsetKeys;
    unsigned char* m_pkVOffsetKeys; // src: XBOX_RETAIL_PDB +0x18 (old: m_pVOffsetKeys)
    unsigned int m_eVOffsetType; // src: XBOX_RETAIL_PDB +0x1c (old: m_uiVOffsetKeyStride)
    unsigned int m_uiNumUTilingKeys;
    unsigned char* m_pkUTilingKeys; // src: XBOX_RETAIL_PDB +0x24 (old: m_pUTilingKeys)
    unsigned int m_eUTilingType; // src: XBOX_RETAIL_PDB +0x28 (old: m_uiUTilingKeyStride)
    unsigned int m_uiNumVTilingKeys;
    unsigned char* m_pkVTilingKeys; // src: XBOX_RETAIL_PDB +0x30 (old: m_pVTilingKeys)
    unsigned int m_eVTilingType; // src: XBOX_RETAIL_PDB +0x34 (old: m_uiVTilingKeyStride)
    int m_fLastUOffset; // src: XBOX_RETAIL_PDB +0x38 (old: unk38)
    int m_fLastVOffset; // src: XBOX_RETAIL_PDB +0x3c (old: unk3C)
    int m_fLastUTiling; // src: XBOX_RETAIL_PDB +0x40 (old: unk40)
    int m_fLastVTiling; // src: XBOX_RETAIL_PDB +0x44 (old: unk44)
    unsigned char m_ucUOffsetSize; // src: XBOX_RETAIL_PDB +0x48 (old: m_ucByte48)
    unsigned char m_ucVOffsetSize; // src: XBOX_RETAIL_PDB +0x49 (old: m_ucByte49)
    unsigned char m_ucUTilingSize; // src: XBOX_RETAIL_PDB +0x4a (old: m_ucByte4A)
    unsigned char m_ucVTilingSize; // src: XBOX_RETAIL_PDB +0x4b (old: m_ucByte4B)
};
