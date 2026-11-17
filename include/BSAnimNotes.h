#pragma once

#include "NiObject.h"

// pdb: class BSAnimNotes, size 0x10, bases: NiObject, 2 members
class BSAnimNotes : public NiObject
{
public:
    virtual ~BSAnimNotes();
    virtual bool RegisterStreamables(NiStream& arStream);

    void BSAnimNotes_dtor();
    void* DestroyIfFlagged(unsigned int auiFlags);

    NiObject** NoteA; // src: XBOX_RETAIL_PDB +0x8 (old: m_ppNotes)
    unsigned short usNumNotes; // src: XBOX_RETAIL_PDB +0xc (old: m_usNumAnimNotes)
};
