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
#include "levels/jrb/header.h"

const LevelScript level_jrb_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x07, _jrb_segment_7SegmentRomStart, _jrb_segment_7SegmentRomEnd), 
	LOAD_MIO0(0x0B, _effect_mio0SegmentRomStart, _effect_mio0SegmentRomEnd), 
	LOAD_MIO0_TEXTURE(0x09, _water_mio0SegmentRomStart, _water_mio0SegmentRomEnd), 
	LOAD_MIO0(0x0A, _bbh_skybox_mio0SegmentRomStart, _bbh_skybox_mio0SegmentRomEnd), 
	LOAD_MIO0(0x05, _group9_mio0SegmentRomStart, _group9_mio0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group9_geoSegmentRomStart, _group9_geoSegmentRomEnd), 
	LOAD_MIO0(0x06, _group13_mio0SegmentRomStart, _group13_mio0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group13_geoSegmentRomStart, _group13_geoSegmentRomEnd), 
	LOAD_MIO0(0x08, _common0_mio0SegmentRomStart, _common0_mio0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_10), 
	JUMP_LINK(script_func_global_14), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_GROUNDS_WARP_PIPE, warp_pipe_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CUBE, colored_cube_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_GATE, sc_gate1_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_SC_TRUCK, sc_truck_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BIG_TRUCK, sc_big_truck_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_SIMP_MINE, sc_mine_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_SIMP_ELEVATOR, SC_Elevator_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_SIMP_SPOTLIGHT, spotlight_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_SIMP_SPRING, box_spring_geo), 

	AREA(1, jrb_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		INSTANT_WARP(0, 0x02, 0, 0, 0),
		INSTANT_WARP(1, 0x02, 0, -5809, 0),
		INSTANT_WARP(2, 0x02, 0, -4584, 0),
		WARP_NODE(0x1A, LEVEL_JRB, 0x03, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0B, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xAB, LEVEL_JRB, 0x03, 0x0B, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0C, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		INSTANT_WARP(3, 0x04, 0, 0, 0),
		WARP_NODE(0x7A, LEVEL_JRB, 0x05, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x8E, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_STAR, -8883, -6579, 24459, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 21610, 10113, -12091, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_CUBE, -16378, -9996, 10510, 0, 0, 0, 0x00000000, bhvColoredCube),
		OBJECT(MODEL_CUBE, -12658, -9996, 4636, 0, 0, 0, 0x00010000, bhvColoredCube),
		OBJECT(MODEL_CUBE, 12662, -8987, 2572, 0, 0, 0, 0x00020000, bhvColoredCube),
		OBJECT(MODEL_CUBE, 11512, -9996, 13841, 0, 0, 0, 0x00030000, bhvColoredCube),
		OBJECT(MODEL_RED_FLAME, -11689, -9913, 23433, 0, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_SIMP_TOAD, 568, 12835, -17188, 0, 90, 0, 0x00020000, bhvGangToad),
		OBJECT(MODEL_SIMP_TOAD, 2133, -10000, 12738, 0, -90, 0, 0x00010000, bhvGangToad),
		OBJECT(MODEL_SIMP_TOAD, -7349, -10000, 23800, 0, 180, 0, 0x00000000, bhvGangToad),
		OBJECT(MODEL_SIMP_TOAD, -29818, -10000, 568, 0, 135, 0, 0x00000000, bhvGangToad),
		OBJECT(MODEL_GATE, 22517, -10000, -651, 0, 0, 0, 0x00000000, bhvTimedGate),
		OBJECT(MODEL_GATE, -31060, -10000, -651, 0, -180, 0, 0x00010000, bhvTimedGate),
		OBJECT(MODEL_NONE, 0, -9041, 26663, 0, -180, 0, 0x000A0000, bhvWarps78),
		OBJECT(MODEL_CASTLE_GROUNDS_WARP_PIPE, 23687, -3190, 26632, 0, -180, 0, 0x000B0100, bhvWarpPipe),
		OBJECT(MODEL_CASTLE_GROUNDS_WARP_PIPE, 21160, -10000, 871, 0, -90, 0, 0x000C0100, bhvWarpPipe),
		OBJECT(MODEL_CASTLE_GROUNDS_WARP_PIPE, -23001, -9998, 21217, 0, -180, 0, 0x008E0100, bhvWarpPipe),
		OBJECT(MODEL_TOAD, -26907, -10178, -10096, 0, 0, 0, 0x00000000, bhvSimpMGToad),
		OBJECT(MODEL_PURPLE_SWITCH, -11040, -10000, -9431, 0, 0, 0, 0x00000000, bhvTimedCarSwitch),
		OBJECT(MODEL_PURPLE_SWITCH, 568, 12835, -15724, 0, 0, 0, 0x00000000, bhvChaseSwitch),
		OBJECT(MODEL_RED_COIN, -16083, -1948, 6626, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 7268, 4230, 6628, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 21619, 3621, 10197, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 11160, -3190, 6553, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -4126, 1781, 974, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -6107, 995, 6628, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -5583, -67, 14012, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 14454, -1881, -3908, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_SIMP_SPRING, -7964, -10000, -3888, 0, 0, 0, 0x001E0000, bhvBounceBoxes),
		OBJECT(MODEL_SIMP_SPRING, 7286, -10000, 4020, 0, -90, 0, 0x001E0000, bhvBounceBoxes),
		OBJECT(MODEL_SIMP_SPRING, 12662, -10000, 3646, 0, -90, 0, 0x000A0000, bhvBounceBoxes),
		OBJECT(MODEL_SIMP_SPRING, -11052, -9995, 10354, 0, 0, 0, 0x001C0000, bhvBounceBoxes),
		OBJECT(MODEL_SIMP_SPRING, 9412, -9995, 10707, 0, -180, 0, 0x00180000, bhvBounceBoxes),
		OBJECT(MODEL_NONE, 7268, 1465, 2577, 0, 0, 0, 0x00000000, bhvHiddenRedCoinStar),
		OBJECT(MODEL_STAR_PIECE, -24809, -9866, -12824, 0, 0, 0, 0x00010000, bhvStarPiece),
		OBJECT(MODEL_STAR_PIECE, -25963, -9866, -10723, 0, 0, 0, 0x00010000, bhvStarPiece),
		OBJECT(MODEL_STAR_PIECE, -23876, -9866, -11251, 0, 0, 0, 0x00010000, bhvStarPiece),
		OBJECT(MODEL_STAR_PIECE, -24559, -9866, -9973, 0, 0, 0, 0x00010000, bhvStarPiece),
		OBJECT(MODEL_STAR_PIECE, -25298, -9866, -14323, 0, 0, 0, 0x00010000, bhvStarPiece),
		OBJECT(MODEL_NONE, -26383, -9878, -12657, 0, 0, 0, 0x00000000, bhvStarPieceStar),
		OBJECT(MODEL_STAR_PIECE_SWITCH, -25193, -10178, -18398, 0, -180, 0, 0x09020000, bhvStarPieceSwitch),
		OBJECT(MODEL_NONE, 25406, -3852, 26840, 0, 0, 0, 0x801A0000, bhvWarp),
		OBJECT(MODEL_NONE, -23001, -10607, 23155, 0, 0, 0, 0x807A0000, bhvWarp),
		TERRAIN(jrb_area_1_collision),
		MACRO_OBJECTS(jrb_area_1_Area1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_UNDERGROUND),
		TERRAIN_TYPE(TERRAIN_STONE),
	END_AREA(),

	AREA(2, jrb_area_2),
		INSTANT_WARP(0, 0x01, 0, 0, 0),
		INSTANT_WARP(1, 0x01, 0, 5809, 0),
		INSTANT_WARP(2, 0x01, 0, 4584, 0),
		WARP_NODE(0x86, LEVEL_JRB, 0x02, 0x87, WARP_NO_CHECKPOINT),
		WARP_NODE(0x87, LEVEL_JRB, 0x02, 0x86, WARP_NO_CHECKPOINT),
		INSTANT_WARP(3, 0x01, 0, 12804, 0),
		OBJECT(MODEL_SIMP_ELEVATOR, 0, -8297, -15422, 0, 0, 0, 0x00000000, bhvSCElevator),
		TERRAIN(jrb_area_2_collision),
		ROOMS(jrb_area_2_collision_rooms),
		MACRO_OBJECTS(jrb_area_2_Area2_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_UNDERGROUND),
		TERRAIN_TYPE(TERRAIN_STONE),
	END_AREA(),

	AREA(3, jrb_area_3),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x2A, LEVEL_JRB, 0x01, 0x0B, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0B, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x5B, LEVEL_JRB, 0x01, 0x0C, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, -12326, 16339, 22082, 0, -180, 0, 0x000A0000, bhvWarps78),
		OBJECT(MODEL_NONE, -25153, -5709, -17228, 0, 90, 0, 0x000B0000, bhvWarps78),
		OBJECT(MODEL_CASTLE_GROUNDS_WARP_PIPE, -21310, -5856, 23480, 0, 0, 0, 0x002A0000, bhvWarpPipe),
		OBJECT(MODEL_CASTLE_GROUNDS_WARP_PIPE, -12326, 15532, 24236, 0, 0, 0, 0x002A0000, bhvWarpPipe),
		OBJECT(MODEL_STAR, -19477, -5556, 23480, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_BIG_TRUCK, -24152, -5856, -18210, 0, 0, 0, 0x01000000, bhvSimpBigTruck),
		OBJECT(MODEL_BIG_TRUCK, -24152, -5856, -16265, 0, 0, 0, 0x00000000, bhvSimpBigTruck),
		OBJECT(MODEL_BIG_TRUCK, -22950, -5856, -15279, 0, 0, 0, 0x00000000, bhvSimpBigTruck),
		OBJECT(MODEL_BIG_TRUCK, -23395, -5856, -17220, 0, 0, 0, 0x00010000, bhvSimpBigTruck),
		OBJECT(MODEL_BIG_TRUCK, -23663, -5856, -20188, 0, 0, 0, 0x00000000, bhvSimpBigTruck),
		OBJECT(MODEL_BIG_TRUCK, -20916, -5856, -18210, 0, 0, 0, 0x00010000, bhvSimpBigTruck),
		OBJECT(MODEL_BIG_TRUCK, -21395, -5856, -17220, 0, 0, 0, 0x00010000, bhvSimpBigTruck),
		OBJECT(MODEL_BIG_TRUCK, -22151, -5856, -19127, 0, 0, 0, 0x00010000, bhvSimpBigTruck),
		OBJECT(MODEL_BIG_TRUCK, -19274, -5856, -15299, 0, 0, 0, 0x00010000, bhvSimpBigTruck),
		OBJECT(MODEL_BIG_TRUCK, -16768, -5856, -15279, 0, 0, 0, 0x00010000, bhvSimpBigTruck),
		OBJECT(MODEL_BIG_TRUCK, -16768, -5856, -18240, 0, 0, 0, 0x00010000, bhvSimpBigTruck),
		OBJECT(MODEL_BIG_TRUCK, -13993, -5856, -19140, 0, 0, 0, 0x00010000, bhvSimpBigTruck),
		OBJECT(MODEL_BIG_TRUCK, -15110, -5856, -16233, 0, 0, 0, 0x00000000, bhvSimpBigTruck),
		OBJECT(MODEL_BIG_TRUCK, -13304, -5856, -17213, 0, 0, 0, 0x00010000, bhvSimpBigTruck),
		OBJECT(MODEL_BIG_TRUCK, -13265, -5856, -14302, 0, 0, 0, 0x00000000, bhvSimpBigTruck),
		OBJECT(MODEL_BIG_TRUCK, -19454, -5856, -18206, 0, 0, 0, 0x00010000, bhvSimpBigTruck),
		OBJECT(MODEL_BIG_TRUCK, -11496, -5856, -18202, 0, 0, 0, 0x00010000, bhvSimpBigTruck),
		OBJECT(MODEL_BIG_TRUCK, -7959, -5856, -15237, 0, 0, 0, 0x00010000, bhvSimpBigTruck),
		OBJECT(MODEL_BIG_TRUCK, -9960, -5856, -20172, 0, 0, 0, 0x00000000, bhvSimpBigTruck),
		OBJECT(MODEL_BIG_TRUCK, -8501, -5856, -17219, 0, 0, 0, 0x00010000, bhvSimpBigTruck),
		OBJECT(MODEL_BIG_TRUCK, -6608, -5856, -18228, 0, 0, 0, 0x00010000, bhvSimpBigTruck),
		OBJECT(MODEL_BIG_TRUCK, -4587, -5856, -17219, 0, 0, 0, 0x00010000, bhvSimpBigTruck),
		OBJECT(MODEL_CASTLE_GROUNDS_WARP_PIPE, -4587, -5128, -17219, 0, 0, 0, 0x005B0000, bhvWarpPipe),
		OBJECT(MODEL_BIG_TRUCK, -20411, -5856, -16205, 0, 0, 0, 0x00010000, bhvSimpBigTruck),
		OBJECT(MODEL_BIG_TRUCK, -18639, -5856, -17220, 0, 0, 0, 0x00000000, bhvSimpBigTruck),
		OBJECT(MODEL_BIG_TRUCK, -15886, -5856, -17239, 0, 0, 0, 0x00010000, bhvSimpBigTruck),
		OBJECT(MODEL_BIG_TRUCK, -16768, -5856, -19131, 0, 0, 0, 0x00000000, bhvSimpBigTruck),
		OBJECT(MODEL_BIG_TRUCK, -10265, -5856, -14302, 0, 0, 0, 0x00010000, bhvSimpBigTruck),
		OBJECT(MODEL_BIG_TRUCK, -10976, -5856, -15237, 0, 0, 0, 0x00000000, bhvSimpBigTruck),
		OBJECT(MODEL_BIG_TRUCK, -11501, -5856, -17219, 0, 0, 0, 0x00000000, bhvSimpBigTruck),
		OBJECT(MODEL_BIG_TRUCK, -11496, -5856, -20187, 0, 0, 0, 0x00010000, bhvSimpBigTruck),
		OBJECT(MODEL_BIG_TRUCK, -7668, -5856, -19130, 0, 0, 0, 0x00010000, bhvSimpBigTruck),
		OBJECT(MODEL_BIG_TRUCK, -12243, -5856, -19140, 0, 0, 0, 0x00010000, bhvSimpBigTruck),
		OBJECT(MODEL_BIG_TRUCK, -7399, -5856, -16233, 0, 0, 0, 0x00000000, bhvSimpBigTruck),
		OBJECT(MODEL_STAR, -5212, -4828, -17219, 0, 0, 0, 0x00000000, bhvStar),
		TERRAIN(jrb_area_3_collision),
		ROOMS(jrb_area_3_collision_rooms),
		MACRO_OBJECTS(jrb_area_3_Area3_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_UNDERGROUND),
		TERRAIN_TYPE(TERRAIN_STONE),
	END_AREA(),

	AREA(4, jrb_area_4),
		INSTANT_WARP(0, 0x01, 0, 0, 0),
		WARP_NODE(0x86, LEVEL_JRB, 0x04, 0x87, WARP_NO_CHECKPOINT),
		WARP_NODE(0x87, LEVEL_JRB, 0x04, 0x86, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_STAR, 27060, -8941, -15288, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_NONE, 27060, -9241, -15288, 0, 0, 0, 0x00860000, bhvFadingWarp),
		OBJECT(MODEL_NONE, 26377, -9241, -13071, 0, 90, 0, 0x00870000, bhvFadingWarp),
		TERRAIN(jrb_area_4_collision),
		ROOMS(jrb_area_4_collision_rooms),
		MACRO_OBJECTS(jrb_area_4_Area4_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_UNDERGROUND),
		TERRAIN_TYPE(TERRAIN_STONE),
	END_AREA(),

	AREA(5, jrb_area_5),
		WARP_NODE(0xA, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x2A, LEVEL_JRB, 0x01, 0x8E, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, -21702, -1674, 19317, 0, -180, 0, 0x000A0000, bhvWarps78),
		OBJECT(MODEL_CASTLE_GROUNDS_WARP_PIPE, 12264, -2174, 2201, 0, 0, 0, 0x002A0000, bhvWarpPipe),
		OBJECT(MODEL_SIMP_SPOTLIGHT, -21642, -2174, 11775, 0, 0, 0, 0x38400000, bhvSpotlight),
		OBJECT(MODEL_STAR, 10952, -1874, 2177, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_SIMP_SPOTLIGHT, -21587, -2174, 9738, 0, -17, 0, 0x28C00000, bhvSpotlight),
		OBJECT(MODEL_SIMP_SPOTLIGHT, -19895, -2174, 8502, 0, -90, 0, 0x30C00000, bhvSpotlight),
		OBJECT(MODEL_SIMP_SPOTLIGHT, -21147, -2174, 8689, 0, -45, 0, 0x2C400000, bhvSpotlight),
		OBJECT(MODEL_SIMP_SPOTLIGHT, -16185, -1732, 8450, 180, -90, 0, 0x1C400000, bhvSpotlight),
		OBJECT(MODEL_SIMP_SPOTLIGHT, -10722, -2174, 8683, 0, -90, 0, 0x58C00000, bhvSpotlight),
		OBJECT(MODEL_SIMP_SPOTLIGHT, -9627, -2174, 7784, 0, -90, 0, 0x58400000, bhvSpotlight),
		OBJECT(MODEL_SIMP_SPOTLIGHT, -8490, -2174, 7876, 0, -90, 0, 0x90C00000, bhvSpotlight),
		OBJECT(MODEL_SIMP_SPOTLIGHT, -7302, -2174, 7927, 0, -90, 0, 0x58400000, bhvSpotlight),
		OBJECT(MODEL_SIMP_SPOTLIGHT, -2210, -1732, 4562, -180, 0, 0, 0x3E400000, bhvSpotlight),
		OBJECT(MODEL_SIMP_SPOTLIGHT, -2210, -1732, 6008, -180, 0, 0, 0x3EC00000, bhvSpotlight),
		OBJECT(MODEL_SIMP_SPOTLIGHT, 472, -1732, 2178, 180, -90, 0, 0x30C00100, bhvSpotlight),
		OBJECT(MODEL_SIMP_SPOTLIGHT, 4625, -2174, 2493, 0, -90, 0, 0x50400100, bhvSpotlight),
		OBJECT(MODEL_SIMP_SPOTLIGHT, 4625, -2174, 1861, 0, 90, 0, 0x50C00100, bhvSpotlight),
		OBJECT(MODEL_SIMP_SPOTLIGHT, 6852, -2174, 2493, 0, -90, 0, 0x50400100, bhvSpotlight),
		OBJECT(MODEL_SIMP_SPOTLIGHT, 6852, -2174, 1861, 0, 90, 0, 0x50C00100, bhvSpotlight),
		OBJECT(MODEL_SIMP_SPOTLIGHT, 8982, -2174, 2493, 0, -90, 0, 0x50400100, bhvSpotlight),
		OBJECT(MODEL_SIMP_SPOTLIGHT, 8982, -2174, 1861, 0, 90, 0, 0x50C00100, bhvSpotlight),
		OBJECT(MODEL_SIMP_SPOTLIGHT, -3733, -1732, 8064, 180, -90, 0, 0x1CC00000, bhvSpotlight),
		TERRAIN(jrb_area_5_collision),
		MACRO_OBJECTS(jrb_area_5_Area5_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_UNDERGROUND),
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
