#ifndef FNV_INTERFACEMANAGER_H
#define FNV_INTERFACEMANAGER_H

#include "interfacemanager_decls.h"
// @fnv 0x00719320
// pdb: SystemColorManager::SoftSystemColor::GetColor | InterfaceManager.obj | debug, upstream name already matches, high
unsigned int SystemColorManager::SoftSystemColor::GetColor()
{
    return pSetting->Int()->u;
}
// @fnv 0x00707af0
// pdb: InterfaceManager::GetCurrentRenderedMenu | Interface.obj | debug, call graph (shared callers), high
FORenderedMenu* InterfaceManager::GetActiveRenderedMenu()
{
    return IsPipboyMenuActive() ? reinterpret_cast<FORenderedMenu*>(pPipboyManager) : pRenderedMenu;
}
#endif
