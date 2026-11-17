#pragma once

// pdb: structure fd_set, size 0x104, 2 members
class fd_set
{
public:
    unsigned int fd_count;
    unsigned int fd_array[64];
};
