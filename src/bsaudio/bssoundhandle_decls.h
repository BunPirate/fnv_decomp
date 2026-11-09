// Local system-color declarations used by bssoundhandle.cpp.
#ifndef FNV_BSSOUNDHANDLE_WORKER_DECLS_H
#define FNV_BSSOUNDHANDLE_WORKER_DECLS_H

class NiColor;

// pdb: class SystemColorManager, size 0x10 (here 0x1), 2 members
class SystemColorManager
{
  public:
    class SystemColor
    {
      public:
        void GetColor(NiColor&);
    };

    SystemColor* Find(int);
    bool GetColor(int, NiColor&);
};

#endif
