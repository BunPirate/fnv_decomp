#include "bhkcharactercontroller_decls.h"

// @fnv 0x00560d30
float& bhkCharacterController::GetVectorElement(int index)
{
    return reinterpret_cast<float*>(this)[index];
}

// @fnv 0x00931ed0
// pdb: MobileObject::DeleteCurrentProcess | MobileObject.obj | retail, object-file gap fill, high
CharacterControllerValue MobileObject::GetVectorElement()
{
    bhkCharacterController* controller = GetPhysicsCharacterController();
    return controller ? reinterpret_cast<const CharacterControllerValue&>(controller->bhkCharacterController_GetCollisionFilter()) : CharacterControllerValue(0);
}
