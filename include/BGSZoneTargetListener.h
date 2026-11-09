#pragma once

// pdb: class BGSZoneTargetListener, size 0x8, 1 members
class BGSZoneTargetListener
{
public:
    virtual void* __thiscall Destroy(unsigned int flags);
    virtual void* Create(unsigned int apZone, unsigned int apCol);
    virtual void* CreateZoneTargetNode(unsigned int apZone, unsigned int apCol);

    ~BGSZoneTargetListener();
    void SetFlags(int flags, bool set);

    int pZones;
};
