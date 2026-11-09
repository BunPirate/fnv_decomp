# Names from the Xbox 360 development build PDBs

This branch carries the original names of functions, fields, parameters, globals and classes into fnv_decomp. The
names come from the program databases (PDBs) of two Fallout: New Vegas Xbox 360 development builds made on Aug 22,
2010. One is the retail build, the same build as the retail disc. The other is the debug build from the same day.
Every function still compiles to the game's bytes.

## Verification

`python3 tools/build_and_match.py --image <FalloutNV.exe>` on this branch gives the same result as `main`:

- 2,989 of 2,989 units match.
- 68,667 of 68,667 functions (11,458,254 bytes) match.
- 1,954 of 1,954 EH tails match.

The compilers are Microsoft's, from the downloads the CI uses, checked against the digests it pins. Nothing outside
`src/`, `include/`, `build/units.json` and Markdown files changes.

## What changes

### Renames (29,714)

| Kind | Renamed | Example |
|---|---|---|
| Parameters | 20,733 | `Script::ScriptEffectUpdateFunction`: `result` → `afReturnValue` |
| Fields | 4,852 | `CombatProcedureBeInCover` +0x44: `m_waitingOutTimer` → `WaitingOutOfCoverTimer` |
| Functions | 3,531 | `BGSSaveLoadManager::IsSaveFileNameGenerated`, `CombatController::AddTarget` |
| Globals | 517 | `DAT_0126b1b0` → `hkpVehicleInstanceClass` |
| Classes | 81 | `FUN_00eb3750` → `NiCapsuleTriIntersector`, `AIThreadManager` → `AILinearTaskThreadManager` |

The renames were made with a C++ parser (libclang in MSVC-compatibility mode). Each reference is tied to its exact
entity:

- a field by its class and offset;
- a parameter by its function and position;
- a function or global by its address in `build/units.json`.

So `Save` on one class is renamed without touching `Save` on another. `build/units.json` carries the new decorated
names, including the `__ehhandler$` names derived from them. Every rename was built and compared with the game, and
any that made a unit fail or compile differently was left out.

Naming rules:
- A method keeps its current class. When the PDB puts it on a different class, it becomes `Class_Method`, the
  convention the project already uses for a real name on a stand-in scope.
- Static members and function-local statics become `Class_member` or `Class_Function_name`.
- A class is renamed only where the real class is not already defined elsewhere in the tree.
- A renamed function's provenance tag becomes `XBOX_RETAIL_PDB` or `XBOX_DEBUG_PDB`.

### Comments on every linked function (37,465) and class (2,509)

```cpp
// @fnv 0x009e9e50
// pdb: PlayerMover::Update | PlayerMover.obj | retail, upstream name already matches, high
// pdb params: fdeltaT
// pdb locals: movedelta, panim, panim1st, pController, pListener, fMotionMagnitude, fAnimMagnitude, ...
void PlayerMover::Update(float fdeltaT)
```

- **Function comments** give the original qualified name, the original object file (and so the original source
  file), the build and method that linked it, the confidence, and the original parameter and local variable names.
  The locals come from the unoptimised debug build, which keeps all of them.
- **Class comments** give the PDB class, its size (and the size here, when it differs), its bases and its member
  count.
- **Unrenamed functions.** Where a rename was not possible, the comment still carries the real name.

## How PC functions were linked to the Xbox 360 builds

| Source | Linked PC functions |
|---|---|
| Retail build PDB (51,207 named functions) | 20,732 |
| Debug build PDB (105,100 named functions; inline helpers stay functions) | 16,728 more |
| **Total** | **37,460 of 68,657** (high 26,724, medium 4,348, low 6,388) |

Evidence, repeated until nothing new is found:

- **Shared strings.** The same set of string literals, or a literal only one function on each side uses.
- **Vtable slots.** The same RTTI class and subobject has a vtable with the same slot count on both builds.
- **Call graph.** A linked pair's callees link position by position, or the one callee every linked caller has in
  common.
- **Object-file order.** Gaps between linked functions in one object file, with the same count on both sides.

Confidence was measured by holding out half of the functions this project already names from the public Xbox 360
symbols, linking without them, and checking what came back:
- **High-tier retail links:** 1,929 of 1,931 right (99.9%).
- **Debug-build links** count as high only for the methods that held 99% or more there (string set 99.8%, unique
  string 100%, call-graph segments 99.6%, shared callers 99.0%). The others are medium.
- **Agreement between builds.** When the two builds disagree (1,266 functions), the link is demoted. When they agree,
  it is promoted.

Only high-tier links were renamed. Medium and low links appear as comments, labelled with their tier.

Globals were linked through the data references of linked function pairs. The RTTI and Havok class objects were
linked by their name-string argument, which has to match a public symbol in the retail PDB.

## What was not renamed, and why

| Not renamed | Count | Why |
|---|---|---|
| Virtual functions | 6,973 | An override family has to be renamed together. Renaming one moves vtable slots, which was measured to change code. |
| Functions the parser found no definition for | 5,552 | Mostly units clang cannot fully parse (648 of 2,989), or names it decorates differently. |
| Rejected by the build | 2,045 | They made a unit fail to compile or compile differently, usually through a use the parser missed. |
| Declared twice under two names in one file | 860 | One address declared twice (for example `GetExtraData` and `FUN_00a5bdd0`); renaming both would collide. |
| Collisions and shadowing | 372 | The name already exists on the class, a base or derived class, in the function body, or as another global. |
| Classes whose real name is already defined | 2,249 | Stand-ins for real classes; the comment names the real class. |
| Local variables | all | No safe way to pair the current locals with the originals by position. They are listed in `// pdb locals:`. |
| zlib | all | Left as it is. |

All of these still get the real name in a comment.

## Known risks

- **Linking errors.** About 1 in 1,000 high-tier retail links is expected to be wrong, and somewhat more for
  debug-only links. A wrong link gives a wrong name, never wrong code.
- **Folded code.** A function the linker folded with identical code stands for several originals, so its name is one
  of several.
- **Field types.** Field renames follow the PDB layout at an offset. Where a class here models a smaller or
  differently typed field at that offset, the name can be the right member with the wrong type.
- **`Class_Method` spellings.** On a stand-in class the name is a convention, not the original spelling. The original
  is in the comment.

A machine-readable mapping of every link and every rename (old name, new name, source, confidence, reason when
skipped) exists and can be shared separately.
