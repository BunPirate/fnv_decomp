// bssystemutilities/console/bsawardssystemutility_console.cpp: IdleSystem, DownloadableContentManager (12 functions)

#include "bsawardssystemutility_console_decls.h"

// @fnv 0x00af26c0
// src: XBOX_RETAIL_PDB 0x00af26c0
// pdb: BSDLCSystemUtility::QInstance | BSDLCSystemUtility_Xenon.obj | retail, call graph, high
DownloadableContentManager& DownloadableContentManager::BSDLCSystemUtility_QInstance()
{
    if (!DAT_011f7244)
        DAT_011f7244 = new DownloadableContentManager;
    return *DAT_011f7244;
}

// Returns the singleton instance, allocating a new one if DAT_011f7178 is null.
// @fnv 0x00af22d0
// pdb: BSCacheDriveSystemUtility::QInstance | BSCacheDriveSystemUtility_Xenon.obj | retail, call graph, low
// pdb note: debug build links it to BSAwardsSystemUtility::QInstance
IdleSystem& IdleSystem::GetRandomGenerator()
{
    if (!DAT_011f7178)
        DAT_011f7178 = new IdleSystem;
    return *DAT_011f7178;
}

// @fnv 0x00af2d20
bool IdleSystem::Initialize()
{
    return true;
}

// @fnv 0x00af2480
void IdleSystem::Idle()
{
    if (!m_kNode.IsEmpty())
    {
        BSSimpleList<unsigned char*>* pListIter;
        pListIter = &m_kNode;
        {
            int iAwardId;
            while (pListIter && !pListIter->IsEmpty())
            {
                AwardData* pAwardData = (AwardData*)pListIter->m_item;
                iAwardId = pAwardData->id;
                delete pAwardData;
                if (iAwardId > 100)
                {
                    Warning("Achievement %d is out of range and will not be awarded!", iAwardId);
                    continue;
                }
                if (SteamUserStatsAccessor())
                {
                    char name[4];
                    sprintf_s(name, 4, "A%02d", iAwardId);
                    name[3] = 0;
                    SteamUserStatsAccessor()->SetAchievement(name);
                }
                pListIter = pListIter->m_pkNext;
            }
        }
        if (SteamUserStatsAccessor())
            SteamUserStatsAccessor()->StoreStats();
        m_kNode.RemoveAll();
    }
}

namespace std {
// Returns a reference to a function-local static object, creating it on first call.
// @fnv 0x00af2640
// pdb: BSSystemUtility::QInstance | BSSystemUtility_Xenon.obj | retail, call graph, high
template <class T> T& _Immortalize()
{
    static T object;
    return object;
}
template StandardLibrarySingletonObject& _Immortalize<StandardLibrarySingletonObject>();
}

// Deletes the global object pointed to by DAT_011f7178 and resets the pointer to null if it is set.
// @fnv 0x00af2370
// src: XBOX_DEBUG_PDB 0x00af2370
// pdb: BSAwardsSystemUtility::Destroy | BSAwardsSystemUtility_Xenon.obj | debug, call graph, high
void IdleSystem::BSAwardsSystemUtility_Destroy()
{
    if (DAT_011f7178)
    {
        delete DAT_011f7178;
        DAT_011f7178 = 0;
    }
}

// Default constructor for the class; does nothing.
// @fnv 0x00af23d0
// pdb: BSAwardsSystemUtility::BSAwardsSystemUtility | BSAwardsSystemUtility_Xenon.obj | debug, object-file gap fill, medium
IdleSystem::IdleSystem()
{}

// @fnv 0x00af2400
// pdb: BSAwardsSystemUtility::~BSAwardsSystemUtility | BSAwardsSystemUtility_Xenon.obj | debug, object-file gap fill, medium
IdleSystem::~IdleSystem()
{}

// @fnv 0x00af2360
// pdb: BSAwardsSystemUtility::Initialize | BSAwardsSystemUtility_Xenon.obj | debug, call graph, medium
void IdleSystem::Startup()
{
    GetRandomGenerator();
}

struct FUN_00af2470_class
{
    bool return_0_1();
};
// @fnv 0x00af2470
// src: COMMUNITY 0x00af2470
bool FUN_00af2470_class::return_0_1()
{
    return false;
}

struct FUN_00af2420_class
{
    void FUN_00af25b0(void** p);
    bool BSAwardsSystemUtility_Unlock(int aiID);
};

// @fnv 0x00af2420
// src: COMMUNITY 0x00af2420
// pdb: BSAwardsSystemUtility::Unlock | BSAwardsSystemUtility_Xenon.obj | retail, upstream name already matches, high
// pdb params: aiID
// pdb locals: data, rv, overlap, userID, ach
bool FUN_00af2420_class::BSAwardsSystemUtility_Unlock(int aiID)
{
    void* q = g_memoryManager.Allocate(4);
    void *p = q ? *(void**)q = (void*)aiID, q : 0;
    char buf[8];
    FUN_00af25b0(&p);
    return true;
}

unsigned int __cdecl _strlen(const char*);
int __cdecl _strcpy_s(char*, unsigned int, const char*);
struct FUN_00af2f80_class
{
    char _pad[12];
    char _buf[32];
    bool CopyBufferIfNotEmpty(char*);
};
// @fnv 0x00af2f80
// pdb: BSSaveDataSystemUtility::GetMostRecentlyAccessedSaveDataEntry | BSSaveDataSystemUtility.obj | debug, object-file run extension, low
// pdb params: aEntry
bool FUN_00af2f80_class::CopyBufferIfNotEmpty(char* pDest)
{
    if (_strlen(_buf) > 0)
    {
        _strcpy_s(pDest, 32, _buf);
        return true;
    }
    return false;
}
