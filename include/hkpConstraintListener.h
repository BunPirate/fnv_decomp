#pragma once

class hkpConstraintInstance;

// pdb: class hkpConstraintListener, size 0x4, 0 members
class hkpConstraintListener
{
public:
    virtual ~hkpConstraintListener();
    virtual void ConstraintAddedCallback(hkpConstraintInstance* constraint);
    virtual void ConstraintRemovedCallback(hkpConstraintInstance* constraint);
    virtual void c0c();
    virtual void c10();
    virtual void c14();
    virtual void c18();
};
