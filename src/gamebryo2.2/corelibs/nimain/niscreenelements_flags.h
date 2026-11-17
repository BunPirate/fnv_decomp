// gamebryo2.2/corelibs/nimain/niscreenelements_flags.h: declares TaskQueueInterface
#ifndef NISCREENELEMENTS_FLAGS_H
#define NISCREENELEMENTS_FLAGS_H
// pdb: class TaskQueueInterface, size 0x10 (here 0x1), 4 members
class TaskQueueInterface
{
  public:
    void SetTaskFlagDWord(bool enabled, unsigned int mask);
    void NiAVObject_SetFixedBound(bool abTF);
};
#endif
