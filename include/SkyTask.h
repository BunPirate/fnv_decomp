#pragma once

#include "QueuedFileEntry.h"
#include "NiTexture.h"

#pragma pack(push, 4)
// pdb: class SkyTask, size 0x38, bases: QueuedFileEntry, 1 members
class SkyTask : public QueuedFileEntry
{
public:
    SkyTask(NiPointer<NiTexture>* apspTexture, const char* apFilename);
    virtual ~SkyTask();
    virtual void Run();
    virtual void Finish();
    virtual bool GetDescription(char* description, unsigned int bufferSize);
    virtual unsigned char GetFileIndex();

    SkyTask& operator=(const SkyTask& other);

    NiPointer<NiTexture>* pspTexture;
    unsigned char layoutPadding34[4];
};
#pragma pack(pop)
