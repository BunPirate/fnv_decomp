#ifndef XGAMESETTING_H
#define XGAMESETTING_H

class GameSettingCollection;

void EnsureGameSettingCollection();
GameSettingCollection* GetGameSettingCollection();
extern GameSettingCollection* g_pGameSettingCollection;

// @fnv 0x00404a70
// pdb: SettingT<GameSettingCollection>::QCollection | EffectItem.obj | debug, call graph, medium
GameSettingCollection* GetGameSettingCollection()
{
    EnsureGameSettingCollection();
    return g_pGameSettingCollection;
}

#endif
