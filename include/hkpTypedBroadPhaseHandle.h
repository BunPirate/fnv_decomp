#pragma once

struct hkFinishLoadedObjectFlagCD2C;
struct ClassMemberDescriptor;

// pdb: class hkpTypedBroadPhaseHandle, size 0xc, bases: hkpBroadPhaseHandle, 4 members
class hkpTypedBroadPhaseHandle
{
public:
    __forceinline hkpTypedBroadPhaseHandle(int type)
    {
        *(unsigned int*)pad0 = 0;
        m_type = (signed char)type;
        m_collisionFilterInfo = 0;
        m_objectQualityType = -1;
        m_ownerOffset = 0x7f;
    }

    hkpTypedBroadPhaseHandle(hkFinishLoadedObjectFlagCD2C);

    void SetOwnerPointer(void* pvOwner);
    void* getOwner() const;
    void setType(int type);

    static const ClassMemberDescriptor Members[];
    enum { OFFSET_INVALID = 127 };

    char pad0[0x4];
    signed char m_type;
    signed char m_ownerOffset;
    signed char m_objectQualityType;
    char pad7[0x1];
    unsigned int m_collisionFilterInfo;
};
