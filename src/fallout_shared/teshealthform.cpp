// fallout_shared/teshealthform.cpp: TESHealthForm (7 functions)

#include "../../include/TESHealthForm.h"
#include "../../include/TESObjectWEAP.h"
#include "../../include/TESObjectARMO.h"
#include "../../include/TESActorBase.h"

static const int kInitializeDataComponentValue1 = 100;

// @fnv 0x00487220
void TESHealthForm::InitializeComponent()
{
    iHealth = kInitializeDataComponentValue1;
}

// Returns the health of form if it is a TESHealthForm, otherwise returns 0.
// @fnv 0x004873d0
// pdb: TESHealthForm::GetFormHealth | TESHealthForm.obj | debug, call graph, high
// pdb params: apForm
// pdb locals: pComponent
unsigned int TESHealthForm::GetBaseHealth(TESForm* form)
{
    TESHealthForm* health = GetFormAsHealthForm(form);
    if (health)
        return health->GetHealth();
    else
        return 0;
}

// @fnv 0x004871d0
// pdb: TESHealthForm::TESHealthForm | TESHealthForm.obj | debug, upstream name already matches, high
TESHealthForm::TESHealthForm()
{
    InitializeComponent();
}

struct TESFile_Access
{
    void InitializeComponent();
};

// @fnv 0x00487200
// pdb: TESHealthForm::~TESHealthForm | TESHealthForm.obj | debug, upstream name already matches, high
TESHealthForm::~TESHealthForm()
{
    reinterpret_cast<TESFile_Access*>(this)->InitializeComponent();
}

unsigned int __fastcall _FNV_GetFormType(void* pForm);

// Returns apForm cast to TESHealthForm if its form type is weapon, armor, or actor base, otherwise null.
// @fnv 0x004872e0
// pdb: TESHealthForm::GetFormAsHealthForm | TESHealthForm.obj | debug, upstream name already matches, high
// pdb params: apForm
// pdb locals: pretval, pform
TESHealthForm* TESHealthForm::GetFormAsHealthForm(TESForm* apForm)
{
    TESHealthForm* pHealthForm = 0;
    if (apForm)
    {
        switch (_FNV_GetFormType(apForm))
        {
        case 0x28: {
            TESObjectWEAP* pform = reinterpret_cast<TESObjectWEAP*>(apForm);
            pHealthForm = pform;
            break;
        }
        case 0x18: {
            TESObjectARMO* pform = reinterpret_cast<TESObjectARMO*>(apForm);
            pHealthForm = pform;
            break;
        }
        case 0x2a:
        case 0x2b: {
            TESActorBase* pform = reinterpret_cast<TESActorBase*>(apForm);
            pHealthForm = pform;
            break;
        }
        }
    }
    return pHealthForm;
}

// @fnv 0x00487240
// pdb: TESHealthForm::CopyComponent | TESHealthForm.obj | retail, vtable slot, high
// pdb params: apCopyFC
// pdb locals: pCopy
void TESHealthForm::BaseFormRecord(BaseFormComponent* apCopyFC)
{
    TESHealthForm* pCopy = dynamic_cast<TESHealthForm*>(apCopyFC);
    if (!pCopy)
        return;
    SetFormHealth(pCopy->iHealth);
}

// Returns true if the given component is not a TESHealthForm or its health value differs from this form's health value.
// @fnv 0x00487290
// pdb: TESHealthForm::CompareComponent | TESHealthForm.obj | retail, vtable slot, high
// pdb params: apCompareFC
// pdb locals: pCompare
bool TESHealthForm::IsEqualToBase(BaseFormComponent* apCompareFC)
{
    TESHealthForm* casted = dynamic_cast<TESHealthForm*>(apCompareFC);
    if (!casted)
        return true;
    if (iHealth != casted->iHealth)
        return true;
    return false;
}
