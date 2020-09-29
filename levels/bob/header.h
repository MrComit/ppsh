#ifndef BOB_HEADER_H
#define BOB_HEADER_H

#include "types.h"

#include "levels/bob/sand_mound/collision_declarations.h"
#include "levels/bob/sand_mound/geo_declarations.h"

#include "levels/bob/construction/collision_declarations.h"
#include "levels/bob/construction/geo_declarations.h"

#include "levels/bob/barricade/collision_declarations.h"
#include "levels/bob/barricade/geo_declarations.h"

#include "levels/bob/FBblock/collision_header.h"
#include "levels/bob/FBblock/geo_header.h"

#include "levels/bob/palmtree/collision_header.h"
#include "levels/bob/palmtree/geo_header.h"

#include "levels/bob/bridge/collision_header.h"
#include "levels/bob/bridge/geo_header.h"

// geo
extern const GeoLayout bob_geo_000440[];
extern const GeoLayout bob_geo_000458[];
extern const GeoLayout bob_geo_000470[];
extern const GeoLayout bob_geo_000488[];

// leveldata
extern const Gfx bob_seg7_dl_07004390[];
extern const Gfx bob_seg7_dl_07009D80[];
extern const Gfx bob_seg7_dl_0700A470[];
extern const Gfx bob_seg7_dl_0700A920[];
extern const Gfx bob_seg7_dl_0700DD18[];
extern const Gfx bob_seg7_dl_0700E338[];
extern const Gfx bob_seg7_dl_0700E458[];
extern const Gfx bob_seg7_dl_0700E768[];
extern const Gfx bob_seg7_dl_0700E8A0[];
extern const Collision bob_seg7_collision_level[];
extern const MacroObject bob_seg7_macro_objs[];
extern const Collision bob_seg7_collision_chain_chomp_gate[];
extern const Collision bob_seg7_collision_bridge[];
extern const Collision bob_seg7_collision_gate[];
extern const Trajectory bob_seg7_metal_ball_path0[];
extern const Trajectory bob_seg7_metal_ball_path1[];
extern const Trajectory bob_seg7_trajectory_koopa[];

// script
extern const LevelScript level_bob_entry[];


#include "levels/bob/header.inc.h"

extern const Lights0 bob_dl_Rocks_v2_lights;
extern const Lights0 bob_dl_Rocks2_v2_lights;
extern const Gfx mat_bob_sm64_material_water[];

#endif