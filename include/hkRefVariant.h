#pragma once

class hkClass;
class hkReferencedObject;

// pdb: class hkRefVariant, size 0x4, bases: hkRefPtr<hkReferencedObject>, 0 members
class hkRefVariant
{
public:
    hkReferencedObject* m_pRetainedObject;

    hkRefVariant() : m_pRetainedObject(0) {}
    hkRefVariant(const hkRefVariant& kOther) throw();
    ~hkRefVariant() throw();

    void FUN_00d47770(const void* object, const hkClass* pClassInfo);
    const hkClass* hkRefVariant_getClass() const;
};
