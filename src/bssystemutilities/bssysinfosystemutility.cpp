// bssystemutilities/bssysinfosystemutility.cpp: BSSysInfoSystemUtility (3 functions)

#include "layout_support.h"
#include "../../include/BSSysInfoSystemUtility.h"
#include "../../include/MemoryManagerGlobals.h"

// @fnv 0x00af3b70
// pdb: BSSysInfoSystemUtility::Initialize | BSSysInfoSystemUtility.obj | debug, upstream name already matches, high
void BSSysInfoSystemUtility::Initialize()
{}

// @fnv 0x00af3b80
// pdb: BSSysInfoSystemUtility::Destroy | BSSysInfoSystemUtility.obj | debug, upstream name already matches, high
void BSSysInfoSystemUtility::Destroy()
{
    eLanguage = BSSysInfoSystemUtility::LANGUAGE_UNKNOWN;
}



// The shared header does not declare the non-virtual destructor.
void DestroyBSSysInfoSystemUtility();

// @fnv 0x00af3ba0
// pdb: BSSysInfoSystemUtility::`scalar deleting destructor' | BSSysInfoSystemUtility.obj | debug, object-file run extension, low
void* BSSysInfoSystemUtility::vf00(unsigned int flags)
{
    reinterpret_cast<void (__thiscall*)(BSSysInfoSystemUtility*)>(&DestroyBSSysInfoSystemUtility)(this);
    if (flags & 1)
        g_memoryManager.Deallocate(this);
    return this;
}
