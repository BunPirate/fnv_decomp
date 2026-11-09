// bscore/memoryusagetracker.cpp: AutoMemContext (1 function)
#include "../../include/AutoMemContext.h"

// @fnv 0x00404ee0
// pdb: AutoMemContext::~AutoMemContext | EffectItem.obj | debug, upstream name already matches, high
AutoMemContext::~AutoMemContext()
{
    Leave();
}
