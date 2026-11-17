
#include "nicontrollermanager_decls.h"
// @fnv 0x0047a510
NiFixedString* NiControllerManager::FindSequenceByName() { return DAT_011c61e0; }

// @fnv 0x0047b220
bool NiControllerManager::StopSequence(NiControllerSequence* sequence,float easeOut) { return sequence->Deactivate(easeOut,false); }
// @fnv 0x0047aab0
// pdb: NiControllerManager::ActivateSequence | BGSOpenCloseForm.obj | debug, call graph, medium
// pdb params: pkSequence, iPriority, bStartOver, fWeight, fEaseInTime, pkTimeSyncSeq
bool NiControllerManager::ActivateControllerSequence(NiControllerSequence* sequence,int priority,bool startOver,float weight,float easeIn,NiControllerSequence* sync) { return sequence->Activate((char)priority,startOver,weight,easeIn,sync,false); }
// @fnv 0x0048fef0
// pdb: NiControllerManager::DeactivateAll | Animation.obj | debug, call graph, high
// pdb params: fEaseOutTime
// pdb locals: ui, pkSequence
void NiControllerManager::DeactivateAllSequences(float fEaseOutTime) {
 for(unsigned int i=0;i<reinterpret_cast<NiControllerManagerPlayingSequences&>(m_kPlayingSequences).GetSize();++i) {
  NiControllerSequence* sequence=reinterpret_cast<NiControllerManagerPlayingSequences&>(m_kPlayingSequences).GetAt(i);
  StopSequence(sequence,fEaseOutTime);
 }
}
