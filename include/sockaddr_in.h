#pragma once

#include "in_addr.h"

// pdb: structure sockaddr_in, size 0x10, 4 members
class sockaddr_in
{
public:
    short sin_family;
    unsigned short sin_port;
    in_addr sin_addr;
    char sin_zero[8];
};
