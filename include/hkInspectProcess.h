#pragma once

#include "hkReferencedObject.h"
#include "hkProcess.h"

class hkClass;
class ProcessContext;
struct hkSourceListDDB6;
struct hkWrittenObjectQ;
template <typename T> struct hkArrQLocalForm;

// pdb: class hkInspectProcess, size 0x30, bases: hkReferencedObject, hkProcess, 2 members
class hkInspectProcess : public hkReferencedObject, public hkProcess
{
public:
    hkInspectProcess(const hkSourceListDDB6& contexts) throw();
    virtual ~hkInspectProcess() throw();

    virtual void init();

    int m_autoUpdateList;
    int unk24;
    int unk28;
    ProcessContext* m_vdb;

    int addTopLevelObject(void* ptr, const hkClass* klass, unsigned int tag);
    void addTopLevelObject(void* ptr, int klass, int tag);
    int RemovePair(void* object);
    int RemovePair(int key);
    void WriteTrackedObjects();
    int sendRecursiveQ(const void* object, const hkClass* pClassInfo,
                       hkArrQLocalForm<hkWrittenObjectQ>* written) throw();
    int writeObject(const void* ptr, const hkClass* klass, hkBool recurse,
                     hkArrQLocalForm<hkWrittenObjectQ>* recursionStack) throw();
};
