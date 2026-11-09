#pragma once

#include "QueuedFile.h"
#include "GO.h"

class BipedAnim;

// pdb: class QueuedHelmet, size 0x128, bases: QueuedFile, 6 members
class QueuedHelmet : public QueuedFile
{
public:
    QueuedHelmet(void* bipedAnim, int priority, int flags);

    virtual ~QueuedHelmet();
    virtual void Run();
    virtual void Finish();
    virtual void Cancel(BS_TASK_STATE state, void* parent);
    virtual bool GetDescription(char* description, unsigned int bufferSize);
    virtual void ProcessLoadedAnimIdle();
    virtual void GenerateKey();
    virtual void ChangePriority(IO_TASK_PRIORITY priority);
    virtual void DispatchToManager();
    virtual void HandleChildCompletion(QueuedFile* apChild);
    virtual void OnChildCompletion();

    void UpdateFaceGenModels();
    bool FormatQueuedHelmetDescription(char* apDescription, unsigned int aiBufferSize);
    void ApplyQueuedModels();
    void FUN_0043f080();
    void* FUN_0043f030(unsigned int flags);
    void PostProcess();
    void Finish_0043f2b0();

    BipedAnim* pBipedAnim;
    unsigned char spQueuedHelmetModel[0x50];
    GO spHelmetFaceGenModel[20];
    GO spClonedHelmetNode[20];
    int pRef;
    int cFlags;
    int unk124;
};
