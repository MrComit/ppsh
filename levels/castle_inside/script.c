#include <ultra64.h>
#include "sm64.h"
#include "behavior_data.h"
#include "model_ids.h"
#include "seq_ids.h"
#include "dialog_ids.h"
#include "segment_symbols.h"
#include "level_commands.h"

#include "game/level_update.h"

#include "levels/scripts.h"

#include "actors/common1.h"

#include "make_const_nonconst.h"
#include "levels/castle_inside/header.h"

const LevelScript level_castle_inside_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x07, _castle_inside_segment_7SegmentRomStart, _castle_inside_segment_7SegmentRomEnd), 
	LOAD_MIO0_TEXTURE(0x09, _inside_mio0SegmentRomStart, _inside_mio0SegmentRomEnd), 
    LOAD_MIO0(        /*seg*/ 0x05, _group9_mio0SegmentRomStart, _group9_mio0SegmentRomEnd),
    LOAD_RAW(         /*seg*/ 0x0C, _group9_geoSegmentRomStart,  _group9_geoSegmentRomEnd),
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_10), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_BOWSER_TRAP, castle_geo_000F18), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_WATER_LEVEL_PILLAR, castle_geo_001940), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_CLOCK_MINUTE_HAND, castle_geo_001530), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_CLOCK_HOUR_HAND, castle_geo_001548), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_CLOCK_PENDULUM, castle_geo_001518), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_CASTLE_DOOR, castle_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_WOODEN_DOOR, wooden_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_METAL_DOOR, metal_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_CASTLE_DOOR_UNUSED, castle_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_WOODEN_DOOR_UNUSED, wooden_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_DOOR_0_STARS, castle_door_0_star_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_DOOR_1_STAR, castle_door_1_star_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_DOOR_3_STARS, castle_door_3_stars_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_KEY_DOOR, key_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_STAR_DOOR_30_STARS, castle_geo_000F00), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_STAR_DOOR_8_STARS, castle_geo_000F00), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_STAR_DOOR_50_STARS, castle_geo_000F00), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_STAR_DOOR_70_STARS, castle_geo_000F00), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_BUTTON, castle_button_geo), 

	AREA(1, castle_inside_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x00, LEVEL_CASTLE_GROUNDS, 0x01, 0x00, WARP_NO_CHECKPOINT),
		WARP_NODE(0x01, LEVEL_CASTLE_GROUNDS, 0x01, 0x01, WARP_NO_CHECKPOINT),
		PAINTING_WARP_NODE(0x2A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x1F, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(0x26, -946, 0, 2202, 0, -180, 0, 0x00010000, bhvDoorWarp),
		OBJECT(0x26, -1100, 0, 2202, 0, 0, 0, 0x00000000, bhvDoorWarp),
		OBJECT(MODEL_TOAD, -158, 0, 1, 0, 0, 0, 0x00000000, bhvHubToad),
		OBJECT(MODEL_LEVEL_BUTTON, -2573, 0, 40, 0, 0, 0, 0x00000000, bhvLevelButtons),
		OBJECT(MODEL_LEVEL_BUTTON, -2573, 0, -360, 0, 0, 0, 0x00010000, bhvLevelButtons),
		OBJECT(MODEL_LEVEL_BUTTON, -2573, 0, -760, 0, 0, 0, 0x00020000, bhvLevelButtons),
		OBJECT(MODEL_LEVEL_BUTTON, -2573, 0, -1240, 0, 0, 0, 0x00030000, bhvLevelButtons),
		OBJECT(MODEL_NONE, -1023, 0, 1119, 0, -180, 0, 0x001F0000, bhvWarps60),
		TERRAIN(castle_inside_area_1_collision),
		MACRO_OBJECTS(castle_inside_area_1_Area_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_INSIDE_CASTLE),
		TERRAIN_TYPE(TERRAIN_STONE),
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(1, 0, 0, 0, 0),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
