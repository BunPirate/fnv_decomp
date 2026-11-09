#pragma once

#include <stdexcept>
#include <string>

// pdb: class IdvFileError, size 0x8 (here 0x28), bases: std::runtime_error, 0 members
class IdvFileError : public std::runtime_error
{
public:
    inline IdvFileError(const std::string& strMessage, bool bUseErrno = true);
};
