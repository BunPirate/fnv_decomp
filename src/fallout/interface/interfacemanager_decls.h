#include "../../../include/InterfaceManager.h"
// fallout/interface/interfacemanager_decls.h: declares SettingT_GameSettingCollection_, SystemColorManager, SoftSystemColor, InterfaceManager
#ifndef FNV_INTERFACEMANAGER_DECLS_H
#define FNV_INTERFACEMANAGER_DECLS_H

#include "../../../include/SETTING_VALUE.h"
#include "../../../include/SettingT_GameSettingCollection_.h"
// pdb: class SystemColorManager, size 0x10 (here 0x1), 2 members
class SystemColorManager
{
  public:
    class SoftSystemColor
    {
      public:
        unsigned char padding[12];
        SettingT_GameSettingCollection_* pSetting;
        unsigned int GetColor();
    };
};
class FORenderedMenu;

#endif
