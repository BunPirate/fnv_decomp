#pragma once

enum BSDiscBootSystemUtility__NOTIFICATION_TYPE;

// pdb: class BSDiscBootSystemUtility, size 0x50, 4 members
class BSDiscBootSystemUtility
{
public:
    virtual void* vf00(unsigned int flags);
    virtual void Initialize(const char* apcDefaultTitleID, unsigned int auiDefaultParentalLevel);
    virtual void Destroy();

    char cTitleID[64]; // src: XBOX_RETAIL_PDB +0x4 (old: m_acTitleID)
    unsigned int uiParentalLevel; // src: XBOX_RETAIL_PDB +0x44 (old: m_uiParentalLevel)
    bool bAllowDiscEjectChange; // src: XBOX_RETAIL_PDB +0x48 (old: m_bNotificationActive)
    unsigned char layoutPadding49[3];
    void (__cdecl* pNotificationCallback)(BSDiscBootSystemUtility__NOTIFICATION_TYPE); // src: XBOX_RETAIL_PDB +0x4c (old: m_pNotificationCallback)
};
