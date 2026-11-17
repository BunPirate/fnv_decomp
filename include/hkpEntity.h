#pragma once

#include "hkpWorldObject.h"
#include "hkpMaterial.h"
#include "hkpEntitySmallArraySerializeOverrideType.h"
#include "hkpEntitySpuCollisionCallback.h"
#include "hkpMaxSizeMotion.h"

class hkBoolH;
class hkLocalFrame;
class hkpAction;
class hkpBreakableBody;
class hkpConstraintInstance;
class hkpEntityExtendedListeners;
class hkpEntityListener;
class hkpSimulationIsland;
class SpringVector;
struct ConstraintRuntimeInfo;
template <typename T> class ResizableArray;
template <typename T> class hkSmallArray;

// pdb: class hkpEntity, size 0x220, bases: hkpWorldObject, 21 members
class hkpEntity : public hkpWorldObject
{
public:
    enum SpuCollisionCallbackEventFilter
    {
        SPU_SEND_NONE = 0x00,
        SPU_SEND_CONTACT_POINT_ADDED = 0x01,
        SPU_SEND_CONTACT_POINT_PROCESS = 0x02,
        SPU_SEND_CONTACT_POINT_REMOVED = 0x04,
        SPU_SEND_CONTACT_POINT_ADDED_OR_PROCESS =
            SPU_SEND_CONTACT_POINT_ADDED | SPU_SEND_CONTACT_POINT_PROCESS
    };

    typedef hkpEntitySmallArraySerializeOverrideType SmallArraySerializeOverrideType;
    typedef hkpEntitySpuCollisionCallback SpuCollisionCallback;
    typedef hkpEntityExtendedListeners ExtendedListeners;

    class ActionArray
    {
    public:
        hkpAction** m_data;
        hkUint16 m_iElementCount;
        hkUint16 m_iCapacityState;

        int indexOf(hkpAction* action) const
        {
            for (int i = 0; i < (int)m_iElementCount; ++i)
            {
                if (m_data[i] == action)
                    return i;
            }
            return -1;
        }

        void removeAt(int index)
        {
            m_iElementCount--;
            m_data[index] = m_data[m_iElementCount];
        }
    };

    static const ClassMemberDescriptor Members[];

    hkpEntity(FinishingFlag flag);
    virtual ~hkpEntity() throw();
    virtual void vf05();

    int getNumConstraints() throw();
    int GetEntryAt(int i) throw();
    hkBoolH isFixed() const;
    hkUint32 GetUid() const;
    const ResizableArray<ConstraintRuntimeInfo>& getConstraintMastersImpl() const;
    hkpSimulationIsland* GetSimulationIsland() const;
    void __thiscall hkpRigidBody_getPointVelocity(const SpringVector* p, SpringVector* vecOut);
    unsigned char* __thiscall isActive_00c9bff0(unsigned char* out);
    void __thiscall activate_00c9c1d0();
    void removeEntityListener_00c9c670(void* arg1);
    void ApplyForceAtPoint(float dt, const hkVector4& force, const SpringVector& point);
    void __thiscall addContactListener(void* cl);
    void __thiscall RemoveContactListener(void* listener);
    void __thiscall AddEntityListener(void* listener);
    void __thiscall RemoveEntityListener(void* listener);
    // Havok 7.1 hkpEntity::addEntityListener (0x00c9c5b0) / removeEntityListener (0x00c9c670). The void*
    // declarations above predate them: AddEntityListener is bound to 0x00c9c670 (removeEntityListener),
    // RemoveEntityListener to 0x00c9c0f0 (removeEntityActivationListener), FUN_00c9c670 = removeEntityListener.
    void addEntityListener(hkpEntityListener* el);
    void removeEntityListener(hkpEntityListener* el);
    // Creates m_pExtendedListeners on first use; the body is in hkpEntityExtendedListeners.h (hkpEntity.inl).
    inline const hkSmallArray<hkpEntityListener*>& getEntityListeners() const;
    void RetainReference();
    void removeReference();
    void activate();
    void deactivate();

    hkpMaterial m_material; // src: XBOX_RETAIL_PDB +0x8c (old: m_iMaterialIndex)
    void* m_limitContactImpulseUtil; // src: XBOX_RETAIL_PDB +0x98 (old: m_pEntityUserData)
    hkReal m_damageMultiplier; // src: XBOX_RETAIL_PDB +0x9c (old: m_fBulletSpread)
    hkpBreakableBody* m_breakableBody; // src: XBOX_RETAIL_PDB +0xa0 (old: m_pShape)
    hkUint32 m_solverData; // src: XBOX_RETAIL_PDB +0xa4 (old: m_uiFilterInfo)
    hkUint16 m_storageIndex; // src: XBOX_RETAIL_PDB +0xa8 (old: m_usStorageIndex)
    hkUint16 m_contactPointCallbackDelay; // src: XBOX_RETAIL_PDB +0xaa (old: m_usNextProcessCallbackDelay)
    hkpEntitySmallArraySerializeOverrideType m_constraintsMaster; // src: XBOX_RETAIL_PDB +0xac (old: m_eSmallArraySerializeOverrideType)
    hkArray<hkpConstraintInstance*> m_constraintsSlave; // src: XBOX_RETAIL_PDB +0xb4 (old: m_kSlaveConstraints)
    hkArray<hkUint8> m_constraintRuntime; // src: XBOX_RETAIL_PDB +0xc0 (old: m_pByteBuffer)
    hkpSimulationIsland* m_simulationIsland; // src: XBOX_RETAIL_PDB +0xcc (old: m_pSimulationIsland)
    hkInt8 m_autoRemoveLevel; // src: XBOX_RETAIL_PDB +0xd0 (old: m_iAutoRemoveLevel)
    hkUint8 m_numShapeKeysInContactPointProperties; // src: XBOX_RETAIL_PDB +0xd1 (old: m_ucNumShapeKeysInContactPointProperties)
    hkUint8 m_responseModifierFlags; // src: XBOX_RETAIL_PDB +0xd2 (old: m_ucResponseModifierFlags)
    char padD3[1];
    hkUint32 m_uid; // src: XBOX_RETAIL_PDB +0xd4 (old: m_uiUniqueId)
    hkpEntitySpuCollisionCallback m_spuCollisionCallback; // src: XBOX_RETAIL_PDB +0xd8 (old: m_kSpuCollisionCallback)
    hkpMaxSizeMotion m_motion; // src: XBOX_RETAIL_PDB +0xe0 (old: m_pMotionState)
    hkpEntitySmallArraySerializeOverrideType m_contactListeners; // src: XBOX_RETAIL_PDB +0x200 (old: m_kContactListeners)
    ActionArray m_actions; // src: XBOX_RETAIL_PDB +0x208 (old: m_ppActions)
    hkLocalFrame* m_localFrame; // src: XBOX_RETAIL_PDB +0x210 (old: m_pLocalFrame)
    mutable hkpEntityExtendedListeners* m_extendedListeners; // src: XBOX_RETAIL_PDB +0x214 (old: m_pExtendedListeners)
    char pad218[8];
};
