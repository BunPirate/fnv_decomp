#pragma once

class AutoMemHelper
{
public:
    AutoMemHelper(int memContext, bool overridable, const char* pcFile, int aiLine);
    AutoMemHelper(int memContext, int overridable, const char* pcFile, int aiLine);
    AutoMemHelper(int memContext, bool overridable, char* pcFile, int aiLine);
    ~AutoMemHelper();

    int pad;
};
