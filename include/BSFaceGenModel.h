#pragma once

#include "NiRefObject.h"

class BSFaceGenTexture;
class FaceGenCoordinate;
struct FaceGenData;
class FaceGenGeometryModel;
struct FaceGenCoordinates;
class GO;
class NiAVObject;
class NiTexture;
class NiTriBasedGeom;
template <class T> class NiPointer;
template <class T> class FaceGenMatrix;
typedef FaceGenMatrix<float> FaceGenCoord;
enum HAIR_PART;

class __declspec(align(16)) BSFaceGenModel : public NiRefObject
{
public:
    FaceGenGeometryModel* pMeshData;
    BSFaceGenTexture* pTextureData;

    bool LoadModelMesh(const char*, const char*, const char*, HAIR_PART, bool);
    bool LoadFaceGenTexture();
    bool LoadModelTexture(const char*);
    static NiAVObject* GetFaceGenModelNode(NiAVObject*);
    bool ApplyFaceGenMorphs(FaceGenCoordinate*, NiTriBasedGeom*, bool);
    bool ApplyFaceGenMorphs(FaceGenData*, NiPointer<NiTriBasedGeom>&);
    bool ApplyFaceGenMorphs(FaceGenCoord (*)[4], NiTriBasedGeom*, bool);
    bool ApplyCoordinateTexturingToMesh(FaceGenCoordinates*, NiPointer<NiTexture>&, unsigned int);
    bool ApplyCoordinateTexturingToMesh(FaceGenCoordinates*, GO&, unsigned int);
    void ClearTextureData();
    bool CloneTriBasedGeom(NiPointer<NiTriBasedGeom>& out);
    bool HasMorphs();
    bool NiAdditionalGeometryData_GetDataStream(int, void*, void*, void*, void*, void*, void*);
};
