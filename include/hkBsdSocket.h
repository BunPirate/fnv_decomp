#pragma once

#include "hkSocket.h"

// pdb: class hkBsdSocket, size 0x24, bases: hkSocket, 1 members
class hkBsdSocket : public hkSocket
{
public:
    virtual bool* __thiscall isOk_00da2db0(bool* pOut);
    virtual void __thiscall CloseSocket();
    virtual int Read(void* buf, int nbytes);
    virtual int write_00da2e60(int buf, int nbytes);
    virtual int connect(const char* servername, int portNumber);
    virtual int listen_00da30d0(int port) throw();
    virtual bool asyncSelect(int a, int b, int c);
    virtual void* pollForNewClient();

    void __thiscall Destroy();
    void* __thiscall InitWithParam(int param);
    int createSocket();
    bool __thiscall SetNonBlocking(bool blocking);

    unsigned char unk08[0x18];
    int m_socket;
};
