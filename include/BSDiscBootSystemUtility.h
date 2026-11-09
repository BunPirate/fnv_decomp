#pragma once

enum BSDiscBootSystemUtility__NOTIFICATION_TYPE;

// pdb: class BSDiscBootSystemUtility, size 0x50, 4 members
class BSDiscBootSystemUtility
{
public:
    virtual void* vf00(unsigned int flags);
    virtual void Initialize(const char* apcDefaultTitleID, unsigned int auiDefaultParentalLevel);
    virtual void Destroy();

    char cTitleID[64];
    unsigned int uiParentalLevel;
    bool bAllowDiscEjectChange;
    unsigned char layoutPadding49[3];
    void (__cdecl* pNotificationCallback)(BSDiscBootSystemUtility__NOTIFICATION_TYPE);
};
