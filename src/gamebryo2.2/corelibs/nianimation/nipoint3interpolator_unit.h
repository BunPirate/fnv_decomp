#ifndef FNV_NIPOINT3INTERPOLATOR_UNIT_H
#define FNV_NIPOINT3INTERPOLATOR_UNIT_H


#include "../../../../include/NiPointer.h"
#include "NiObject.h"
#include "NiMemObject.h"

class PositionKeyInterpolator
{
  public:
    static NiPoint3 InterpolatePosition(float fTime, PositionKeyInterpolator* pkKeys, NiAnimationKey::KeyType eType,
                                        unsigned int uiNumKeys, unsigned int& uiLastIdx, unsigned char ucSize);
};


extern "C" float DAT_011a9424;
extern "C" float DAT_011a9428;
extern "C" float DAT_011a942c;

#endif
