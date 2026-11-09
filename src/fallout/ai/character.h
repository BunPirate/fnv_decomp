// @fnv 0x008d1ed0
bool Character::GetActorGuard()
{
    return bGuard;
}

// @fnv 0x008d83c0
float MiddleHighProcess::GetVisibilityAlpha() const
{
    return fAutomaticShotDelay;
}

// @fnv 0x008d1ef0
// pdb: Character::GetRace | Character.obj | debug, object-file run extension, low
void Character::SetActorGuardState(bool guard)
{
    bGuard = guard;
}
