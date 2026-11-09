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

    hkpMaterial m_material;
    void* m_limitContactImpulseUtil;
    hkReal m_damageMultiplier;
    hkpBreakableBody* m_breakableBody;
    hkUint32 m_solverData;
    hkUint16 m_storageIndex;
    hkUint16 m_contactPointCallbackDelay;
    hkpEntitySmallArraySerializeOverrideType m_constraintsMaster;
    hkArray<hkpConstraintInstance*> m_constraintsSlave;
    hkArray<hkUint8> m_constraintRuntime;
    hkpSimulationIsland* m_simulationIsland;
    hkInt8 m_autoRemoveLevel;
    hkUint8 m_numShapeKeysInContactPointProperties;
    hkUint8 m_responseModifierFlags;
    char padD3[1];
    hkUint32 m_uid;
    hkpEntitySpuCollisionCallback m_spuCollisionCallback;
    hkpMaxSizeMotion m_motion;
    hkpEntitySmallArraySerializeOverrideType m_contactListeners;
    ActionArray m_actions;
    hkLocalFrame* m_localFrame;
    mutable hkpEntityExtendedListeners* m_extendedListeners;
    char pad218[8];
};
