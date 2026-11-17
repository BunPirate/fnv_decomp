#pragma once

#include "hkError.h"

// pdb: class HavokError, size 0x124 (here 0x8), bases: hkError, 3 members
class HavokError : public hkError
{
public:
    HavokError();
    virtual ~HavokError() throw();
    virtual int message(int m, int id, const char* description, const char* file, int line);
    virtual void vf06();
    virtual void beginSection(int id, const char* name);
    virtual void endSection();
    virtual void disableReport(const char* file, int line);
    virtual void RemoveEntryByPathAndValue(const char* apFile, int aiLine);
    virtual void HavokError_assertMessage(const char* prefix, int soundId, const char* message, const char* file, int line);
    virtual void ReportWarning(const char* what, int id, const char* description, const char* file, int line);
    virtual void WarnWithLocation(const char* message, int unused, const char* type, const char* file, int line);
    virtual void ReportError(const char* what, int id, const char* description, const char* file, int line);
    virtual void showString(const char* apStr);
    virtual const char* hkGetFileBaseName(const char* path);

    bool HavokError_isReportEnabled(const char* path, int value);

    int Warning(int type, int id, const char* desc, const char* file, int line);
    void __thiscall enableAll_00625650();
};
