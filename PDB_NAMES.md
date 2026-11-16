# Names from the Xbox 360 development build PDBs

This branch carries the original names of functions, fields, parameters, globals and classes into fnv_decomp. The
names come from the program databases (PDBs) of two Fallout: New Vegas Xbox 360 development builds that shipped
together. One is the retail build of Aug 22, 2010, the same build as the retail disc. The other is a debug build of
Aug 15, 2010 (its executable's and PDB's timestamps).
Every function still compiles to the game's bytes.

## Verification

`python3 tools/build_and_match.py --image <FalloutNV.exe>` on this branch gives the same result as `main`:

- 2,989 of 2,989 units match.
- 68,667 of 68,667 functions (11,458,254 bytes) match. (That counts each unit's functions; 10 of the 68,657
  addresses are built by two units.)
- 1,954 of 1,954 EH tails match.

The compilers are Microsoft's, from the downloads the CI uses, checked against the digests it pins. Nothing outside
`src/`, `include/`, `build/units.json` and Markdown files changes.

## What changes

### Renames (29,257)

| Kind | Renamed | Example |
|---|---|---|
| Parameters | 20,672 | `Script::ScriptEffectUpdateFunction`: `result` → `afReturnValue` |
| Fields | 4,852 | `CombatProcedureBeInCover` +0x44: `m_waitingOutTimer` → `WaitingOutOfCoverTimer` |
| Functions | 3,141 | `BGSSaveLoadManager::IsSaveFileNameGenerated`, `CombatController::AddTarget` |
| Globals | 517 | `DAT_0126b1b0` → `hkpVehicleInstanceClass` |
| Classes | 75 | `FUN_00eb3750` → `NiCapsuleTriIntersector`, `AIThreadManager` → `AILinearTaskThreadManager` |

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
  convention the project already uses for a real name on a stand-in scope. A function declared in several places
  (stand-in views) is named per declaration: the PDB method name where the declaration is on the PDB class itself,
  `Class_Method` elsewhere. Where that class already has a member of that name, or `main` spelled it with an address
  suffix, that declaration keeps `main`'s name. 192 renamed functions keep `main`'s name in some other declaration;
  the mapping lists them as `unchanged_symbols`.
- A nested class takes `Outer_Inner`, as `main` does (`StatsMenu_NamedEffectsList` for `StatsMenu::NamedEffectsList`).
- Static members and function-local statics become `Class_member` or `Class_Function_name`.
- A class is renamed only where the real class is not already defined elsewhere in the tree.
- A renamed function's provenance tag becomes `XBOX_RETAIL_PDB` or `XBOX_DEBUG_PDB`. When it replaces another tag, the
  marker keeps it as a second source: `// src: XBOX_RETAIL_PDB 0x0078a230 (was COMMUNITY)`. A `GUESS` tag is dropped.
- Where the existing name already was the PDB name, spelled differently (an address suffix, a `Class_` prefix, or
  `Class_Class` for a constructor), the name and its tag stay as they were. The PDB name is in the `// pdb:` comment.
- Every renamed field, global and class carries a marker at the end of its definition line, with the source, the
  member offset or address, and the old name, so each one can be found and reversed on its own:
  `Timer WaitingOutOfCoverTimer; // src: XBOX_RETAIL_PDB +0x44 (old: m_waitingOutTimer)`. Field names come from the
  retail build's type records. A global is marked on each of its declarations. When several renamed fields share one
  declaration, the marker names each. 53 of the 75 class names come from the PC executable's own RTTI (the vtable
  `main` already named), so they are tagged `EXE` with the vtable's address. The other 22 come from high-tier links to
  their own methods here (not counting name-only links). They carry the build most of those links come from, retail on
  a tie (16 `XBOX_RETAIL_PDB`, 6 `XBOX_DEBUG_PDB`), and the address of the first such link from that build.
  Renamed parameters have no marker; they are in the mapping (see the end of this file).
- A renamed parameter is renamed at the definition and at every declaration of the same function: those bound to its
  address in `build/units.json`, and those on the PDB class under the PDB name with the same parameter types.
  A declaration in neither group (an unbound view of the function with other parameter types) keeps `main`'s names.
- A link made only because `main` already used the PDB name (link method "upstream name already matches") renames no
  function or class: the name is the evidence, so its spelling stays. Its parameter names are applied when `main`
  already ties the function to the PDB class: it is a method of that class here, `main` names it `Class_Method` (or
  `Outer_Inner_Method`), or both are free functions of that name. Where only the bare method name matches, on another
  class, the parameter names stay in the comment, labelled unverified.

### Comments on linked functions and classes (2,509)

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
- **Where comments go.** At each definition that carries the function's `// @fnv` address, so a function defined in
  several variant units has several. 256 linked functions have no `@fnv` anchor in the source (mostly
  compiler-generated destructors and helpers), so their PDB names are only in the mapping.

## How PC functions were linked to the Xbox 360 builds

| Source | Linked PC functions |
|---|---|
| Retail build PDB (51,207 named functions) | 20,732 |
| Debug build PDB (105,100 named functions; inline helpers stay functions) | 16,728 more |
| **Total** | **37,460 of the 68,657 function addresses** (high 26,721, disputed 2 and rejected 1 in review, medium 4,348, low 6,388) |

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
| Virtual functions | 6,978 | An override family has to be renamed together. Renaming one moves vtable slots, which was measured to change code. |
| Functions the parser found no definition for | 5,552 | Mostly units clang cannot fully parse (648 of 2,989), or names it decorates differently. |
| Rejected by the build | 2,045 | They made a unit fail to compile or compile differently, usually through a use the parser missed. |
| Declared twice under two names in one file | 860 | One address declared twice (for example `GetExtraData` and `FUN_00a5bdd0`); renaming both would collide. |
| Already named, only spelled differently | 292 | The existing name and its tag already carry the same evidence (see the naming rules). |
| Linked only by the existing name | 90 functions, 4 classes | The link method is "upstream name already matches", so the rename would only respell the name it came from (see the naming rules). |
| Parameters of a bare method-name match | 34 (in 25 functions) | A name-only link where only the method name matches, on a class other than the PDB class (see the naming rules). |
| Conflicts found in review | 3 | 2 names from the public Xbox 360 symbols (probably folded code), shown as `disputed (was high)` with their parameter and local names labelled unverified; and 0x004d5a90, a float getter with no arguments linked to `LipSynchAnim::LoadFromFile`, shown as `rejected (was high)`. Four other pairs that review first took for conflicts are overloads of one name, so both links of each pair hold; their comments name the overload. |
| Collisions and shadowing | 372 | The name already exists on the class, a base or derived class, in the function body, or as another global. |
| Classes whose real name is already defined | 2,249 | Stand-ins for real classes; the comment names the real class. |
| Local variables | all | No safe way to pair the current locals with the originals by position. They are listed in `// pdb locals:`. |
| zlib | all | Left as it is. |

All of these still get the real name in a comment.

## Known risks

- **Linking errors.** About 1 in 1,000 high-tier retail links is expected to be wrong, and somewhat more for
  debug-only links. A wrong link gives a wrong name, never wrong code.
- **Object-file position.** Run extension and gap fill link by position inside one object file, so a function missing
  or reordered on one side shifts its neighbours. A function's own message strings are a check on that, but a message
  can keep an older name. 0x0078b9b0 prints `CalcLoadScreenTypeTextWindowVerts()`, yet in the debug build it is
  `LoadingMenu::CalcLoadScreenTypeTextWindowFaces` that loads this message, and neither PDB has a `Verts` function, so
  the name is `Faces`. Where a message seems to contradict a link, the test is which function of the Xbox 360 build
  loads it. 0x00865020 is the other such case: it is linked to `BGSLoadGameSubBuffer::SaveHavokData`, and its
  warning names `SaveAnimation()`, but in both Xbox 360 builds `SaveHavokData` loads that same warning (as does
  `SaveAnimation`), so the name holds. No other renamed function's message names a different function. One message
  differs from the name (`computeMemberSize`, whose message says `structureLayout::getMemberSize()`), but that link
  comes from the same string, so the message is Havok's own older wording.
- **Overloads.** Run extension and gap fill can land on a sibling overload of the same name. The name is then right,
  but the Xbox 360 address in the mapping, and names taken from that function, can belong to the sibling. Review found
  this at 0x009a52f0 (`AddThreat`) and 0x0043a9a0 (`LoadGame`); their comments name the matching overload, and the
  mapping gives its address as `x360_address_matching_overload`. 39 parameter names in 29 functions are not symbols of
  the linked Xbox 360 function itself: 35 come from a sibling overload of the same name and 4 from the other
  build's copy of the function. The mapping marks each with `name_found_in`.
- **Folded code.** A function the linker folded with identical code stands for several originals, so its name is one
  of several.
- **Field types.** Field renames follow the PDB layout at an offset. Where a class here models a smaller or
  differently typed field at that offset, the name can be the right member with the wrong type.
- **`Class_Method` spellings.** On a stand-in class the name is a convention, not the original spelling. The original
  is in the comment.

## Mapping

Every link and every rename is listed, as JSON Lines, on the branch
[`pdb-names-mapping`](https://github.com/mathisto/fnv_decomp/tree/pdb-names-mapping) of the fork this pull request
comes from. It is kept out of this pull request because the check accepts only source, `build/units.json` and Markdown.
It holds extracted names and metadata (addresses, offsets, link methods); no PDB files or executable bytes.

- `functions_renamed.jsonl`: address, old and new decorated names, the decorated names of declarations that keep
  `main`'s name, the PDB name, build, link method, tier, marker.
- `functions_linked.jsonl`: every one of the 37,460 links, renamed or not, with the reason when not.
- `fields.jsonl`: class, offset, old name, new name, PDB type, file and line of the marker.
- `globals.jsonl`: address, old names, new name, PDB symbol, and each declaration's file, line and marker.
- `classes.jsonl`: old and new name, source, tag, the vtable or first linked method's address, file, line, marker.
- `parameters.jsonl`: function address, parameter index, old name, new name, the link it came from, and
  `name_found_in` where the name is not a symbol of the linked function itself.
- `symbols_changed_by_class_or_type_renames.jsonl`: decorated names that changed only because a class or type in them
  was renamed.
