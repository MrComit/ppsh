#include <ultra64.h>
#include "sm64.h"
#include "surface_terrains.h"
#include "moving_texture_macros.h"
#include "level_misc_macros.h"
#include "macro_preset_names.h"
#include "special_preset_names.h"
#include "textures.h"
#include "dialog_ids.h"

#include "make_const_nonconst.h"
#include "levels/jrb/texture.inc.c"
#include "levels/jrb/areas/1/1/model.inc.c"
#include "levels/jrb/areas/1/2/model.inc.c"
#include "levels/jrb/areas/1/3/model.inc.c"
#include "levels/jrb/areas/1/4/model.inc.c"
#include "levels/jrb/areas/1/5/model.inc.c"
#include "levels/jrb/areas/1/6/model.inc.c"
#include "levels/jrb/areas/1/7/model.inc.c"
#include "levels/jrb/rock/model.inc.c"
#include "levels/jrb/floating_platform/model.inc.c"
#include "levels/jrb/sliding_box/model.inc.c"
#include "levels/jrb/wooden_ship/model.inc.c"
#include "levels/jrb/falling_pillar/model.inc.c"
#include "levels/jrb/falling_pillar_base/model.inc.c"
#include "levels/jrb/areas/1/collision.inc.c"
#include "levels/jrb/areas/1/macro.inc.c"
#include "levels/jrb/rock/collision.inc.c"
#include "levels/jrb/floating_platform/collision.inc.c"
#include "levels/jrb/sliding_box/collision.inc.c"
#include "levels/jrb/wooden_ship/collision.inc.c"
#include "levels/jrb/falling_pillar_base/collision.inc.c"
#include "levels/jrb/unused_lid/collision.inc.c"
#include "levels/jrb/areas/1/trajectory.inc.c"
#include "levels/jrb/areas/1/movtext.inc.c"
#include "levels/jrb/areas/2/1/model.inc.c"
#include "levels/jrb/areas/2/2/model.inc.c"
#include "levels/jrb/areas/2/3/model.inc.c"
#include "levels/jrb/areas/2/collision.inc.c"
#include "levels/jrb/areas/2/macro.inc.c"
#include "levels/jrb/areas/2/movtext.inc.c"
#include "levels/jrb/leveldata.inc.c"

#include "levels/jrb/colored_cube/model.inc.c"
#include "levels/jrb/sc_gate1/collision.inc.c"
#include "levels/jrb/sc_gate1/model.inc.c"
#include "levels/jrb/sc_truck/collision.inc.c"
#include "levels/jrb/sc_truck/model.inc.c"
#include "levels/jrb/sc_big_truck/collision.inc.c"
#include "levels/jrb/sc_big_truck/model.inc.c"
#include "levels/jrb/sc_mine/model.inc.c"
#include "levels/jrb/SC_Elevator/model.inc.c"
#include "levels/jrb/SC_Elevator/collision.inc.c"
#include "levels/jrb/spotlight/model.inc.c"
#include "levels/jrb/box_spring/model.inc.c"
#include "levels/jrb/box_spring/collision.inc.c"
#include "levels/jrb/appearing_block/model.inc.c"
#include "levels/jrb/appearing_block/collision.inc.c"
#include "levels/jrb/small_switch/model.inc.c"
#include "levels/jrb/small_switch/collision.inc.c"
#include "levels/jrb/big_switch/model.inc.c"
#include "levels/jrb/big_switch/collision.inc.c"