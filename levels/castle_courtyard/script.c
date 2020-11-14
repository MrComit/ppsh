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
#include "levels/castle_courtyard/header.h"

const LevelScript level_castle_courtyard_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x07, _castle_courtyard_segment_7SegmentRomStart, _castle_courtyard_segment_7SegmentRomEnd), 
	LOAD_MIO0(0x0A, _water_skybox_mio0SegmentRomStart, _water_skybox_mio0SegmentRomEnd), 
	LOAD_MIO0_TEXTURE(0x09, _outside_mio0SegmentRomStart, _outside_mio0SegmentRomEnd), 
	LOAD_MIO0(0x05, _group9_mio0SegmentRomStart, _group9_mio0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group9_geoSegmentRomStart, _group9_geoSegmentRomEnd), 
	LOAD_MIO0(0x08, _common0_mio0SegmentRomStart, _common0_mio0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_10), 
	LOAD_MODEL_FROM_GEO(MODEL_COURTYARD_SPIKY_TREE, spiky_tree_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_COURTYARD_WOODEN_DOOR, wooden_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_03, castle_courtyard_geo_000200), 
	LOAD_MODEL_FROM_GEO(MODEL_MAGIC_DOOR, magic_door_geo), 

	AREA(1, castle_courtyard_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0B, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x30, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x31, LEVEL_WF, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_MAGIC_DOOR, -5827, 196, -2948, 0, 0, 0, 0x00000000, bhvMagicDoor),
		OBJECT(MODEL_WOODEN_SIGNPOST, -5827, 184, 238, 0, 0, 0, 0x005E0000, bhvMessagePanel),
		OBJECT(MODEL_NONE, -5827, 484, -61, 0, 0, 0, 0x24000000, bhvBonusStar),
		OBJECT(MODEL_NONE, -5827, 50, 2698, 0, -180, 0, 0x000A0000, bhvWarps78),
		OBJECT(MODEL_NONE, -5827, 50, -2698, 0, 0, 0, 0x000B0000, bhvWarps78),
		TERRAIN(castle_courtyard_area_1_collision),
		MACRO_OBJECTS(castle_courtyard_area_1_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_STONE),
	END_AREA(),

	AREA(2, castle_courtyard_area_2),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0B, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x30, LEVEL_WF, 0x01, 0xCA, WARP_NO_CHECKPOINT),
		WARP_NODE(0x31, LEVEL_JRB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_MAGIC_DOOR, -155, 196, -2948, 0, 0, 0, 0x00010000, bhvMagicDoor),
		OBJECT(MODEL_WOODEN_SIGNPOST, -155, 184, 238, 0, 0, 0, 0x005E0000, bhvMessagePanel),
		OBJECT(MODEL_NONE, -155, 484, -61, 0, 0, 0, 0x25010000, bhvBonusStar),
		OBJECT(MODEL_NONE, -155, 50, 2698, 0, -180, 0, 0x000A0000, bhvWarps78),
		OBJECT(MODEL_NONE, -155, 50, -2698, 0, 0, 0, 0x000B0000, bhvWarps78),
		TERRAIN(castle_courtyard_area_2_collision),
		MACRO_OBJECTS(castle_courtyard_area_2_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_STONE),
	END_AREA(),

	AREA(3, castle_courtyard_area_3),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0B, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x30, LEVEL_JRB, 0x01, 0x58, WARP_NO_CHECKPOINT),
		WARP_NODE(0x31, LEVEL_CCM, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_MAGIC_DOOR, 4944, 196, -2948, 0, 0, 0, 0x00020000, bhvMagicDoor),
		OBJECT(MODEL_WOODEN_SIGNPOST, 4344, 184, 238, 0, 0, 0, 0x005E0000, bhvMessagePanel),
		OBJECT(MODEL_NONE, 4344, 484, -61, 0, 0, 0, 0x26020000, bhvBonusStar),
		OBJECT(MODEL_SIMP_TOAD, 5251, 0, -2599, 0, -47, 0, 0x53000000, bhvStarSimpToad),
		OBJECT(MODEL_NONE, 4944, 50, 2698, 0, -180, 0, 0x000A0000, bhvWarps78),
		OBJECT(MODEL_NONE, 4944, 50, -2698, 0, 0, 0, 0x000B0000, bhvWarps78),
		TERRAIN(castle_courtyard_area_3_collision),
		MACRO_OBJECTS(castle_courtyard_area_3_macro_objs),
		STOP_MUSIC(0),
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
