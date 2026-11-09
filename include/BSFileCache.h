#pragma once

class FileCache;
template <class T, unsigned int Growth> class BSSimpleArray;

enum DVD_LAYER
{
    DVD_LAYER_FRONT = 0,
    DVD_LAYER_BACK = 1
};

enum FILE_CACHE_STATE
{
    FILE_CACHING_DISABLED = 0,
    FILE_CACHING_IN_PROGRESS = 1,
    FILE_CACHING_PAUSED = 2,
    FILE_CACHING_FORCE_PAUSED = 3,
    FILE_CACHING_FINISHED = 4
};

// pdb: class BSFileCache, size 0x64, 27 members
class BSFileCache
{
public:
    BSFileCache();
    virtual ~BSFileCache();
    virtual void vf01(int);
    virtual void vf02();
    virtual int vf03(const char* apFileList, unsigned int aiCurrentPriority);
    virtual void vf04(int);
    virtual int vf05(int);
    virtual void vf06(void*, int);
    virtual bool vf07(void* apCachedFile);
    virtual void vf08(int);
    virtual void vf09();
    virtual void vf10(int);
    virtual void vf11(int, int, int, int);
    virtual void vf12();
    virtual bool vf13(void* apCachedFile);
    virtual void vf14();
    virtual void ClearPointerAt60();

    static BSFileCache& GetRandomGenerator();
    static char* ms_pcCachePath;
    static const char* sEssentialFileCacheList;
    static const char* sUnessentialFileCacheList;

    FileCache* pCurrentlyCachingFile;
    unsigned int iCurrentWritten;
    unsigned int iCurrentFileSize;
    unsigned int iTotalWritten;
    unsigned int iTotalDiskSpaceAvailable;
    unsigned int iFreeDiskSpaceAvailable;
    unsigned int iTotalAlreadyCached;
    unsigned int iTotalSizeToCache;
    unsigned int iNumCachedFiles;
    int iCurrentThreadPriority;
    unsigned int iThreadTime;
    int iCurrentPriority;
    int iPrecachePriority;
    int iEssentialPriority;
    int iUnessentialPriority;
    DVD_LAYER eCurrentLayer;
    bool bArraySorted;
    bool bCacheDriveAvailable;
    bool bRunningFromDVD;
    bool bInPauseLoop;
    unsigned int iFileCacheLoadScreenTime;
    unsigned int iFileCacheLoadScreenEssentialTime;
    BSSimpleArray<FileCache*, 1024>* pCachedFiles;
    void (__cdecl* pFileCacheCompletionCallback)(const char*);
    void (__cdecl* pForceFileCacheCallback)(bool);
    volatile FILE_CACHE_STATE eFileCacheState;
    void* hFileCachingThreadHandle;
};
