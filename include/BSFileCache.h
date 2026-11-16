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

    FileCache* pCurrentlyCachingFile; // src: XBOX_RETAIL_PDB +0x4 (old: m_pActiveFileCache)
    unsigned int iCurrentWritten; // src: XBOX_RETAIL_PDB +0x8 (old: m_uiCacheEntryCount)
    unsigned int iCurrentFileSize; // src: XBOX_RETAIL_PDB +0xc (old: m_uiCachedBytes)
    unsigned int iTotalWritten; // src: XBOX_RETAIL_PDB +0x10 (old: m_uiCacheLimit)
    unsigned int iTotalDiskSpaceAvailable; // src: XBOX_RETAIL_PDB +0x14 (old: m_uiCacheByteCount)
    unsigned int iFreeDiskSpaceAvailable; // src: XBOX_RETAIL_PDB +0x18 (old: m_uiCacheCapacity)
    unsigned int iTotalAlreadyCached; // src: XBOX_RETAIL_PDB +0x1c (old: m_uiCacheRequestCount)
    unsigned int iTotalSizeToCache; // src: XBOX_RETAIL_PDB +0x20 (old: m_uiCacheFlags)
    unsigned int iNumCachedFiles; // src: XBOX_RETAIL_PDB +0x24 (old: m_uiCacheIndex)
    int iCurrentThreadPriority; // src: XBOX_RETAIL_PDB +0x28 (old: m_iCacheEntryIndex)
    unsigned int iThreadTime; // src: XBOX_RETAIL_PDB +0x2c (old: m_uiReferenceCount)
    int iCurrentPriority; // src: XBOX_RETAIL_PDB +0x30 (old: m_iCacheCount)
    int iPrecachePriority; // src: XBOX_RETAIL_PDB +0x34 (old: m_iFileSize)
    int iEssentialPriority; // src: XBOX_RETAIL_PDB +0x38 (old: m_iFilePosition)
    int iUnessentialPriority; // src: XBOX_RETAIL_PDB +0x3c (old: m_iCachePosition)
    DVD_LAYER eCurrentLayer; // src: XBOX_RETAIL_PDB +0x40 (old: m_eDVDLayer)
    bool bArraySorted; // src: XBOX_RETAIL_PDB +0x44 (old: m_bCacheEnabled)
    bool bCacheDriveAvailable; // src: XBOX_RETAIL_PDB +0x45 (old: m_bCacheReadPending)
    bool bRunningFromDVD; // src: XBOX_RETAIL_PDB +0x46 (old: m_bCacheWritePending)
    bool bInPauseLoop; // src: XBOX_RETAIL_PDB +0x47 (old: m_bCacheInitialized)
    unsigned int iFileCacheLoadScreenTime; // src: XBOX_RETAIL_PDB +0x48 (old: m_uiCacheOffset)
    unsigned int iFileCacheLoadScreenEssentialTime; // src: XBOX_RETAIL_PDB +0x4c (old: m_uiCacheBufferCount)
    BSSimpleArray<FileCache*, 1024>* pCachedFiles; // src: XBOX_RETAIL_PDB +0x50 (old: m_pFileCacheArray)
    void (__cdecl* pFileCacheCompletionCallback)(const char*); // src: XBOX_RETAIL_PDB +0x54 (old: m_pfnCacheProgress)
    void (__cdecl* pForceFileCacheCallback)(bool); // src: XBOX_RETAIL_PDB +0x58 (old: m_pfnCacheStatus)
    volatile FILE_CACHE_STATE eFileCacheState; // src: XBOX_RETAIL_PDB +0x5c (old: m_eCacheState)
    void* hFileCachingThreadHandle; // src: XBOX_RETAIL_PDB +0x60 (old: m_pCacheSyncObject)
};
