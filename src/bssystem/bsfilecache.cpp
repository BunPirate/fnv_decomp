// bssystem/bsfilecache.cpp: BSFileCache, StandIn (15 functions)

#include "bsfilecache.h"
#include "../../include/MemoryManager.h"

// @fnv 0x00b00f20
// pdb: BSFileCache::BSFileCache | BSFileCache.obj | debug, upstream name already matches, high
BSFileCache::BSFileCache()
{
    iNumCachedFiles = 0;
    pCachedFiles = 0;
    hFileCachingThreadHandle = 0;
    eFileCacheState = FILE_CACHING_IN_PROGRESS;
    pCurrentlyCachingFile = 0;
    iCurrentWritten = 0;
    iCurrentFileSize = 0;
    iTotalDiskSpaceAvailable = 0;
    iFreeDiskSpaceAvailable = 0;
    iCurrentThreadPriority = -1;
    iTotalWritten = 0;
    iTotalAlreadyCached = 0;
    iThreadTime = 1;
    iTotalSizeToCache = 0;
    iCurrentPriority = 0;
    eCurrentLayer = DVD_LAYER_FRONT;
    bArraySorted = false;
    bCacheDriveAvailable = false;
    bInPauseLoop = false;
    iPrecachePriority = 0;
    iFileCacheLoadScreenTime = 0;
    iFileCacheLoadScreenEssentialTime = 2;
    pForceFileCacheCallback = 0;
    pFileCacheCompletionCallback = 0;
}

struct FUN_00b011b0_shell : public BSFileCache
{
    bool BSWin32FileCache_IsFileCached(int);
};

struct VT_00b011b0
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual int v5(int);
};
struct ST_00b011b0
{
    bool BSWin32FileCache_IsFileCached_0(int);
};
// Calls v5 on the argument, then forwards the result to FUN_00b011e0 and returns its bool result.
// @fnv 0x00b011b0
// src: COMMUNITY 0x00b011b0
// pdb: BSFileCache::IsFileCached | BSFileCache.obj | debug, object-file gap fill, medium
// pdb params: apFileName
bool FUN_00b011b0_shell::BSWin32FileCache_IsFileCached(int a)
{
    return ((ST_00b011b0*)this)->BSWin32FileCache_IsFileCached_0(((VT_00b011b0*)this)->v5(a));
}

struct FUN_00b01020
{
    virtual ~FUN_00b01020();
};
// @fnv 0x00b01020
// pdb: BSFileCache::~BSFileCache | BSFileCache.obj | debug, object-file gap fill, medium
FUN_00b01020::~FUN_00b01020()
{}

struct Unk00b01040
{
    void CallVirtualWithField38();
};
struct VBase
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11(int, int, int, int);
};
// Calls the virtual f11 on this with arguments 0, the int at offset 0x38, 1 and 0.
// @fnv 0x00b01040
// pdb: BSFileCache::WaitForEssentialFileCachingToFinish | BSFileCache.obj | debug, object-file gap fill, medium
void Unk00b01040::CallVirtualWithField38()
{
    ((VBase*)this)->f11(0, *(int*)((char*)this + 0x38), 1, 0);
}

struct FUN_00b01070_Class
{
    void nullsub_316();
};
// @fnv 0x00b01070
// src: COMMUNITY 0x00b01070
// pdb: BSFileCache::CalculateCurrentLayer | BSFileCache.obj | debug, object-file gap fill, medium
void FUN_00b01070_Class::nullsub_316()
{}

struct E00b011e0
{
    int pad0;
    int pad1;
    int pad2;
    int v;
};
struct M00b011e0
{
    int pad;
    E00b011e0** arr;
};
struct C00b011e0
{
    char _0[0x24];
    int cnt;
    char _1[0x28];
    M00b011e0* mid;
    bool BSWin32FileCache_IsFileCached_0(int idx);
};
// Returns true when idx is within cnt and the entry at mid->arr[idx] has v equal to 2; otherwise false.
// @fnv 0x00b011e0
// src: COMMUNITY 0x00b011e0
// pdb: BSFileCache::IsFileCached | BSFileCache.obj | debug, object-file gap fill, medium
// pdb params: aiIndex
bool C00b011e0::BSWin32FileCache_IsFileCached_0(int aiIndex)
{
    if (aiIndex < 0 || aiIndex >= cnt)
        return false;
    return mid->arr[aiIndex]->v == 2;
}

extern int DAT_011ad028;
extern int DAT_011ad02c;

struct FUN_00b012f0_shell
{
    void BSFileCache_SetFileCacheList(int aEssentialFileCacheList, int aUnessentialFileCacheList);
};

// @fnv 0x00b012f0
// src: COMMUNITY 0x00b012f0
// pdb: BSFileCache::SetFileCacheList | BSFileCache.obj | debug, upstream name already matches, high
// pdb params: aEssentialFileCacheList, aUnessentialFileCacheList
void __thiscall FUN_00b012f0_shell::BSFileCache_SetFileCacheList(int aEssentialFileCacheList, int aUnessentialFileCacheList)
{
    DAT_011ad028 = aEssentialFileCacheList;
    DAT_011ad02c = aUnessentialFileCacheList;
}

struct FUN_00b01020_Holder
{
    void FUN_00b01020();
};
extern MemoryManager g_memoryManager;
struct FUN_00b01310_shell
{
    void* FUN_00b01310(unsigned int flags);
};
// Calls FUN_00b01020 on this, deallocates this via g_memoryManager when flags has bit 1 set, and returns this.
// @fnv 0x00b01310
void* FUN_00b01310_shell::FUN_00b01310(unsigned int flags)
{
    ((FUN_00b01020_Holder*)this)->FUN_00b01020();
    if (flags & 1)
        g_memoryManager._DeallocateAlias(this);
    return this;
}

struct FUN_00b01340_Shell
{
    int BSFileCache_ParseCachedFileList(const char* apFileList, unsigned int aiCurrentPriority);
};
// @fnv 0x00b01340
// src: COMMUNITY 0x00b01340
// pdb: BSFileCache::ParseCachedFileList | BSFileCache.obj | debug, upstream name already matches, high
// pdb params: apFileList, aiCurrentPriority
int FUN_00b01340_Shell::BSFileCache_ParseCachedFileList(const char* apFileList, unsigned int aiCurrentPriority)
{
    return 0;
}

struct FUN_00b01350_shell
{
    bool __thiscall _retn_0_(void* apCachedFile);
};

// @fnv 0x00b01350
// src: COMMUNITY 0x00b01350
bool __thiscall FUN_00b01350_shell::_retn_0_(void* apCachedFile)
{
    return false;
}

struct FUN_00b01360_Cls
{
    void BSFileCache_WaitForFileCachingToFinish(int aiMaxWait, int aiPriority, int abUpdateLoadingBar, int cLoadingBarSection);
};
// @fnv 0x00b01360
// src: COMMUNITY 0x00b01360
// pdb: BSFileCache::WaitForFileCachingToFinish | BSFileCache.obj | debug, upstream name already matches, high
// pdb params: aiMaxWait, aiPriority, abUpdateLoadingBar, cLoadingBarSection
void FUN_00b01360_Cls::BSFileCache_WaitForFileCachingToFinish(int aiMaxWait, int aiPriority, int abUpdateLoadingBar, int cLoadingBarSection)
{}

struct StandIn
{
    void ClearPointerAt60();
};
// @fnv 0x00b01370
// pdb: BSFileCache::WaitDuringLoadingScreen | BSFileCache.obj | debug, object-file run extension, low
void StandIn::ClearPointerAt60()
{
    *reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x60) = 0;
}

extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long ulMilliseconds);

class B01130Task
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    unsigned char unk44;
    unsigned char unk45;
    unsigned char unk46;
    bool m_bTaskActive;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int m_iFadeIndex;
    void* m_pvThread;

    void BSFileCache_ForcePauseAndWaitForIdle();
};

// @fnv 0x00b01130
// src: COMMUNITY 0x00b01130
// pdb: BSFileCache::ForcePauseAndWaitForIdle | BSFileCache.obj | retail, upstream name already matches, high
void B01130Task::BSFileCache_ForcePauseAndWaitForIdle()
{
    if (!m_pvThread)
        return;
    if (m_iFadeIndex == 1 || m_iFadeIndex == 2)
        m_iFadeIndex = 3;
    if ((bool)((m_iFadeIndex == 2 || m_iFadeIndex == 3) ? 1 : 0))
    {
        while (!m_bTaskActive)
            Sleep(10);
    }
}

struct S : public BSFileCache
{
    void BSFileCache_WaitIfPaused();
};
// @fnv 0x00b01080
// src: XBOX_RETAIL_PDB 0x00b01080
// pdb: BSFileCache::WaitIfPaused | BSFileCache.obj | retail, object-file run extension, high
void S::BSFileCache_WaitIfPaused()
{
    while ((bool)((eFileCacheState == FILE_CACHING_PAUSED || eFileCacheState == FILE_CACHING_FORCE_PAUSED) ? 1 : 0))
    {
        bInPauseLoop = true;
        Sleep(50);
    }
    bInPauseLoop = false;
}

struct FUN_00b010d0_cls : public BSFileCache
{
    void BSFileCache_PauseAndWaitForIdle();
};

// @fnv 0x00b010d0
// src: XBOX_RETAIL_PDB 0x00b010d0
// pdb: BSFileCache::PauseAndWaitForIdle | BSFileCache.obj | retail, object-file run extension, high
void FUN_00b010d0_cls::BSFileCache_PauseAndWaitForIdle()
{
    if (eFileCacheState == FILE_CACHING_IN_PROGRESS)
    {
        eFileCacheState = FILE_CACHING_PAUSED;
    }
    if ((bool)((eFileCacheState == FILE_CACHING_PAUSED || eFileCacheState == FILE_CACHING_FORCE_PAUSED) ? 1 : 0))
    {
        while (bInPauseLoop == 0)
        {
            Sleep(10);
        }
    }
}
