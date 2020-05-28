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
#include "levels/wf/header.h"

const LevelScript level_wf_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x07, _wf_segment_7SegmentRomStart, _wf_segment_7SegmentRomEnd), 
	LOAD_MIO0(0x0A, _cloud_floor_skybox_mio0SegmentRomStart, _cloud_floor_skybox_mio0SegmentRomEnd), 
	LOAD_MIO0_TEXTURE(0x09, _grass_mio0SegmentRomStart, _grass_mio0SegmentRomEnd), 
	LOAD_MIO0(0x05, _group6_mio0SegmentRomStart, _group6_mio0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group6_geoSegmentRomStart, _group6_geoSegmentRomEnd), 
	LOAD_MIO0(0x06, _group14_mio0SegmentRomStart, _group14_mio0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group14_geoSegmentRomStart, _group14_geoSegmentRomEnd), 
	LOAD_MIO0(0x08, _common0_mio0SegmentRomStart, _common0_mio0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_7), 
	JUMP_LINK(script_func_global_15), //JUMP_LINK(script_func_local_2), //        JUMP_LINK(script_func_local_2),
	LOAD_MODEL_FROM_GEO(MODEL_WF_BUBBLY_TREE, bubbly_tree_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_GROUNDS_WARP_PIPE, warp_pipe_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CANYON_ELEVATOR, canyon_elevator_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CANYON_BUTTON, canyon_button_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_WRENCH, mole_wrench_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_SPLAT, quicksand_platforming_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_FLOATING_ROCK, floating_rock_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_ROCK_DOOR, rock_door_geo), //AREA(/*index*/ 1, wf_geo_000BF8),
	LOAD_MODEL_FROM_GEO(MODEL_HORIZONTAL_ROCK, horizontal_rock_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BOMB_SWITCH, BombSwitch_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BOMB_BOULDER, bomb_boulder_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_TRUCK, cc_truck_geo), 

	AREA(1, wf_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x1A, LEVEL_WF, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_WF, 0x01, 0x1A, WARP_NO_CHECKPOINT),
		INSTANT_WARP(0x00, 0x02, 0, 0, 0),
		WARP_NODE(0x1F, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		INSTANT_WARP(0x01, 0x03, 0, -200, 0),
		WARP_NODE(0x33, LEVEL_WF, 0x04, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x36, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_MONTY_MOLE, -19647, -539, 2770, 0, -151, 0, 0x02310000, bhvMoleNpc),
		OBJECT(MODEL_CANYON_BUTTON, -6047, 0, -24598, 0, 0, 0, 0x0C000000, bhvCanyonButton),
		OBJECT(MODEL_CANYON_BUTTON, 18689, 0, -13499, 0, 0, 0, 0x00020000, bhvBlueCanyonButton),
		OBJECT(MODEL_CANYON_ELEVATOR, -13995, 0, 3616, 0, 0, 0, 0x00000000, bhvCanyonElevator),
		OBJECT(MODEL_CANYON_ELEVATOR, -276, 1965, -3789, 0, -41, 0, 0x00010000, bhvCanyonElevator),
		OBJECT(MODEL_CANYON_ELEVATOR, 2608, 1965, 8124, 0, 97, 0, 0x00010000, bhvCanyonElevator),
		OBJECT(MODEL_NONE, -13930, 192, -13471, 90, -174, 0, 0x00120000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -12881, 192, -21698, 90, 117, 0, 0x00120000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 5554, 2265, 5141, 0, 106, 0, 0x00020000, bhvCoinFormation),
		OBJECT(MODEL_YELLOW_COIN, -5908, 2007, 5807, 90, -122, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_NONE, -1182, 7031, -14621, 0, -178, 0, 0x00110000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -12488, 680, 12345, 0, 169, 0, 0x001A0000, bhvWarps84),
		OBJECT(MODEL_FLOATING_ROCK, 17908, -508, -2335, 0, 0, 0, 0x00800000, bhvFloatRock),
		OBJECT(MODEL_FLOATING_ROCK, 19172, -508, -3174, 0, -49, 0, 0x00400000, bhvFloatRock),
		OBJECT(MODEL_FLOATING_ROCK, 17771, -508, -4189, 0, -96, 0, 0x00100000, bhvFloatRock),
		OBJECT(MODEL_FLOATING_ROCK, 18709, -508, -5249, 0, 93, 0, 0x00C00000, bhvFloatRock),
		OBJECT(MODEL_FLOATING_ROCK, 11203, -508, -2393, 0, -71, 0, 0x00800000, bhvFloatRock),
		OBJECT(MODEL_FLOATING_ROCK, 12801, -508, -930, 0, -121, 0, 0x00400000, bhvFloatRock),
		OBJECT(MODEL_FLOATING_ROCK, 12669, -508, -2577, 0, -167, 0, 0x00100000, bhvFloatRock),
		OBJECT(MODEL_FLOATING_ROCK, 10391, 1460, 13626, 0, -155, 0, 0x00400000, bhvFloatRock),
		OBJECT(MODEL_FLOATING_ROCK, 9275, 1691, 15259, 0, -118, 0, 0x00900000, bhvFloatRock),
		OBJECT(MODEL_FLOATING_ROCK, 8088, 1843, 15500, 0, -161, 0, 0x00E00000, bhvFloatRock),
		OBJECT(MODEL_FLOATING_ROCK, 6076, 1483, 12959, 0, -36, 0, 0x00400000, bhvFloatRock),
		OBJECT(MODEL_FLOATING_ROCK, 6159, 1765, 15243, 0, 0, 0, 0x00900000, bhvFloatRock),
		OBJECT(MODEL_FLOATING_ROCK, -5450, 3756, 9254, 0, -47, 0, 0x03000000, bhvFloatRockQueen),
		OBJECT(MODEL_FLOATING_ROCK, 9589, 1460, 9890, 0, 159, 0, 0x00400000, bhvFloatRock),
		OBJECT(MODEL_FLOATING_ROCK, 10749, 1460, 10597, 0, 109, 0, 0x00400000, bhvFloatRock),
		OBJECT(MODEL_FLOATING_ROCK, 15729, 1460, 13905, 0, -128, 0, 0x00400000, bhvFloatRock),
		OBJECT(MODEL_FLOATING_ROCK, 15904, 1672, 15195, 0, -163, 0, 0x00900000, bhvFloatRock),
		OBJECT(MODEL_FLOATING_ROCK, 16008, 1599, 16373, 0, 140, 0, 0x00000000, bhvFloatRock),
		OBJECT(MODEL_FLOATING_ROCK, 11787, 1599, 17808, 0, 171, 0, 0x00200000, bhvFloatRock),
		OBJECT(MODEL_FLOATING_ROCK, 14874, 1599, 17669, 0, 65, 0, 0x00A00000, bhvFloatRock),
		OBJECT(MODEL_FLOATING_ROCK, 6614, 1624, 14042, 0, -47, 0, 0x00000000, bhvFloatRock),
		OBJECT(MODEL_FLOATING_ROCK, 9257, 1536, 13967, 0, -140, 0, 0x00000000, bhvFloatRock),
		OBJECT(MODEL_FLOATING_ROCK, -6449, 3964, 9877, 0, -24, 0, 0x03400000, bhvFloatRockQueen),
		OBJECT(MODEL_FLOATING_ROCK, -7517, 4241, 10296, 0, -81, 0, 0x03800000, bhvFloatRockQueen),
		OBJECT(MODEL_FLOATING_ROCK, -8678, 4568, 10789, 0, -119, 0, 0x03C00000, bhvFloatRockQueen),
		OBJECT(MODEL_FLOATING_ROCK, -9971, 4838, 11028, 0, -178, 0, 0x03000000, bhvFloatRockQueen),
		OBJECT(MODEL_FLOATING_ROCK, -11003, 5091, 10408, 0, 164, 0, 0x03400000, bhvFloatRockQueen),
		OBJECT(MODEL_FLOATING_ROCK, -10111, 5265, 9673, 0, 126, 0, 0x03800000, bhvFloatRockQueen),
		OBJECT(MODEL_NONE, -15589, 0, -5536, 0, 0, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, -12653, 0, -8847, 0, 0, 0, 0x00040000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, 7752, 0, -6426, 0, 0, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, 4291, 1965, 1828, 0, 0, 0, 0x00040000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, 5860, 1965, 9371, 0, 0, 0, 0x00040000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, -3135, 1965, 780, 0, 0, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, -16326, 1965, -342, 0, 0, 0, 0x00040000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_HORIZONTAL_ROCK, -19889, -101, -4721, 0, -80, 0, 0x00000000, bhvHorizontalRock),
		OBJECT(MODEL_HORIZONTAL_ROCK, -20155, -308, -3798, 0, -80, 0, 0x00800000, bhvHorizontalRock),
		OBJECT(MODEL_HORIZONTAL_ROCK, -19660, -476, -2886, 0, -80, 0, 0x00000000, bhvHorizontalRock),
		OBJECT(MODEL_HORIZONTAL_ROCK, -19756, -611, -207, 0, -80, 0, 0x00800000, bhvHorizontalRock),
		OBJECT(MODEL_HORIZONTAL_ROCK, -19531, -611, 1480, 0, -80, 0, 0x00800000, bhvHorizontalRock),
		OBJECT(MODEL_HORIZONTAL_ROCK, -19232, -611, 644, 0, -80, 0, 0x00000000, bhvHorizontalRock),
		OBJECT(MODEL_HORIZONTAL_ROCK, -8711, 4751, 3934, 0, -102, 0, 0x02000000, bhvHorizontalRockQueen),
		OBJECT(MODEL_HORIZONTAL_ROCK, -7315, 4751, 4537, 0, 63, 0, 0x02000000, bhvHorizontalRockQueen),
		OBJECT(MODEL_HORIZONTAL_ROCK, -7448, 4945, 5380, 0, -117, 0, 0x02000000, bhvHorizontalRockQueen),
		OBJECT(MODEL_HORIZONTAL_ROCK, -9139, 4945, 4733, 0, 78, 0, 0x02000000, bhvHorizontalRockQueen),
		OBJECT(MODEL_HORIZONTAL_ROCK, -9792, 5228, 5467, 0, -102, 0, 0x02000000, bhvHorizontalRockQueen),
		OBJECT(MODEL_HORIZONTAL_ROCK, -7449, 5228, 6458, 0, 63, 0, 0x02000000, bhvHorizontalRockQueen),
		OBJECT(MODEL_HORIZONTAL_ROCK, -8632, 5228, 5916, 0, 158, 0, 0x02000000, bhvHorizontalRockQueen),
		OBJECT(MODEL_HORIZONTAL_ROCK, -8079, 5485, 7049, 0, -112, 0, 0x02000000, bhvHorizontalRockQueen),
		OBJECT(MODEL_HORIZONTAL_ROCK, -9836, 5485, 6330, 0, 68, 0, 0x02000000, bhvHorizontalRockQueen),
		OBJECT(MODEL_HORIZONTAL_ROCK, -14260, 5894, 8934, 0, -74, 0, 0x01000000, bhvHorizontalRockQueen),
		OBJECT(MODEL_HORIZONTAL_ROCK, -12385, 5894, 8383, 0, -74, 0, 0x01000000, bhvHorizontalRockQueen),
		OBJECT(MODEL_HORIZONTAL_ROCK, -13160, 5894, 9191, 0, 16, 0, 0x01000000, bhvHorizontalRockQueen),
		OBJECT(MODEL_HORIZONTAL_ROCK, -11647, 5894, 7620, 0, 16, 0, 0x01000000, bhvHorizontalRockQueen),
		OBJECT(MODEL_NONE, -12488, 680, 12345, 0, 169, 0, 0x000A0000, bhvWarps78),
		OBJECT(MODEL_MONTY_MOLE, -12717, 0, 9110, 0, 0, 0, 0x002E0000, bhvMoleNpc),
		OBJECT(MODEL_MONTY_MOLE, -8075, 0, 8956, 0, 86, 0, 0x00300000, bhvMoleNpc),
		OBJECT(MODEL_MONTY_MOLE, 15623, 0, -1099, 0, -55, 0, 0x00330000, bhvMoleNpc),
		OBJECT(MODEL_MONTY_MOLE, -4069, 5894, -4841, 0, 22, 0, 0x00340000, bhvMoleNpc),
		OBJECT(MODEL_MONTY_MOLE, -5535, 1841, 6060, 0, -56, 0, 0x00350000, bhvMoleNpc),
		OBJECT(MODEL_SPLAT, 9416, -180, -9309, 0, 0, 0, 0x073A0000, bhvSPlat),
		OBJECT(MODEL_SPLAT, 9416, -290, -9309, 0, 0, 0, 0x04300000, bhvSPlat),
		OBJECT(MODEL_SPLAT, 9416, -400, -9309, 0, 0, 0, 0x09260000, bhvSPlat),
		OBJECT(MODEL_SPLAT, 9416, -510, -9309, 0, 0, 0, 0x051C0000, bhvSPlat),
		OBJECT(MODEL_SPLAT, 9416, -620, -9309, 0, 0, 0, 0x0A120000, bhvSPlat),
		OBJECT(MODEL_MONTY_MOLE, -9842, 3929, 8015, 0, 0, 0, 0x14000000, bhvQueenMole),
		OBJECT(MODEL_CANYON_BUTTON, 10713, 1965, 17679, 0, 0, 0, 0x11000000, bhvRedCanyonButton),
		OBJECT(MODEL_CANYON_BUTTON, 15933, 1965, 17595, 0, 0, 0, 0x11000000, bhvRedCanyonButton),
		OBJECT(MODEL_CANYON_BUTTON, 15440, 1965, 12899, 0, 22, 0, 0x11000000, bhvRedCanyonButton),
		OBJECT(MODEL_CANYON_BUTTON, 11282, 1993, 14615, 0, -40, 0, 0x11000000, bhvRedCanyonButton),
		OBJECT(MODEL_CANYON_BUTTON, 6982, 2185, 15972, 0, 45, 0, 0x11000000, bhvRedCanyonButton),
		OBJECT(MODEL_NONE, 14738, 2043, 8725, 0, -70, 0, 0x00000000, bhvCloud),
		OBJECT(MODEL_NONE, 15629, 2043, 11117, 0, -70, 0, 0x00000000, bhvCloud),
		OBJECT(MODEL_NONE, 11601, 2141, 13010, 0, -70, 0, 0x01000000, bhvCloud),
		OBJECT(MODEL_NONE, 11542, 2141, 16985, 0, -70, 0, 0x01000000, bhvCloud),
		OBJECT(MODEL_NONE, 12004, 2141, 14294, 0, -70, 0, 0x01000000, bhvCloud),
		OBJECT(MODEL_NONE, 15047, 2142, 15634, 0, 94, 0, 0x00000000, bhvCloud),
		OBJECT(MODEL_RED_COIN, 5992, 639, -12321, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -17795, 1965, 1760, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -15278, 681, 9252, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -5135, 1966, 6440, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 6136, 2325, 1489, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 209, 1972, 5214, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 5549, 1965, 4067, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -11486, 5894, -2363, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_ROCK_DOOR, 15405, 1214, 4035, 0, 0, 0, 0x00000000, bhvRockDoor),
		OBJECT(MODEL_STAR, -2817, 8158, -10182, 0, 0, 0, 0x13000000, bhvStar),
		OBJECT(MODEL_NONE, 9416, -273, -9309, 0, 0, 0, 0x0E000000, bhvStarPieceStar),
		OBJECT(MODEL_NONE, 5554, 2265, 5141, 0, 0, 0, 0x17000000, bhvHiddenRedCoinStar),
		OBJECT(MODEL_NONE, -9186, 640, 9850, 0, 0, 0, 0x0D000000, bhvWrenchStar),
		OBJECT(MODEL_STAR_PIECE_SWITCH, 9416, -573, -9309, 0, 0, 0, 0x0B020000, bhvStarPieceSwitch),
		OBJECT(MODEL_TRUCK, -3541, 2258, -2603, 0, 106, 0, 0x00000000, bhvStaticObject),
		OBJECT(MODEL_TRUCK, 2032, 2258, 5066, 0, -122, 0, 0x00000000, bhvStaticObject),
		OBJECT(MODEL_TRUCK, -1980, 4228, -6711, 0, -167, 0, 0x00000000, bhvStaticObject),
		OBJECT(MODEL_TRUCK, 6112, 2255, 1470, -53, -155, 0, 0x00000000, bhvStaticObject),
		OBJECT(MODEL_CASTLE_GROUNDS_WARP_PIPE, -1370, 1965, 13019, 0, 173, 0, 0x001F0100, bhvWarpPipe),
		OBJECT(MODEL_CASTLE_GROUNDS_WARP_PIPE, -8660, 1965, -10468, 0, -88, 0, 0x00360100, bhvWarpPipe),
		OBJECT(MODEL_NONE, -7379, 1473, -12508, 0, 0, 0, 0x80330000, bhvWarp),
		OBJECT(MODEL_NONE, -11730, 861, 1191, 0, 0, 0, 0x00000000, bhvWrenchThrower),
		OBJECT(MODEL_WRENCH, -10698, 0, 6271, 0, 0, 0, 0x00000000, bhvWrenchCollect),
		OBJECT(MODEL_WRENCH, -15504, 0, 7262, 0, 0, 0, 0x00000000, bhvWrenchCollect),
		OBJECT(MODEL_WRENCH, -13722, 0, 11173, 0, 17, 0, 0x00000000, bhvWrenchCollect),
		OBJECT(MODEL_WRENCH, -8008, 261, 3653, 0, 0, 0, 0x00000000, bhvWrenchCollect),
		OBJECT(MODEL_WRENCH, -8271, 1021, 13022, 0, 0, 0, 0x00000000, bhvWrenchCollect),
		TERRAIN(wf_area_1_collision),
		ROOMS(wf_area_1_collision_rooms),
		MACRO_OBJECTS(wf_area_1_Area1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_FEAR),
		TERRAIN_TYPE(TERRAIN_SAND),
	END_AREA(),

	AREA(2, wf_area_2),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		INSTANT_WARP(0, 0x01, 0, 0, 0),
		WARP_NODE(0x1A, LEVEL_WF, 0x01, 0x1F, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_WF, 0x01, 0x1A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_MONTY_MOLE, 12557, 0, 8152, 0, 0, 0, 0x0F000000, bhvBigBully),
		OBJECT(MODEL_FLOATING_ROCK, -2027, -530, 3472, 0, -71, 0, 0x00800000, bhvFloatRock),
		OBJECT(MODEL_FLOATING_ROCK, -833, -530, 3808, 0, -103, 0, 0x00C00000, bhvFloatRock),
		OBJECT(MODEL_FLOATING_ROCK, -90, -530, 2665, 0, -70, 0, 0x00200000, bhvFloatRock),
		OBJECT(MODEL_FLOATING_ROCK, 1483, -860, -14225, 0, -3, 0, 0x00800000, bhvFloatRock),
		OBJECT(MODEL_FLOATING_ROCK, 2236, -860, -15210, 0, -35, 0, 0x00000000, bhvFloatRock),
		OBJECT(MODEL_FLOATING_ROCK, 2917, -860, -16185, 0, -26, 0, 0x00800000, bhvFloatRock),
		OBJECT(MODEL_MONTY_MOLE, -8616, 0, 1933, 0, 161, 0, 0x00360000, bhvMoleNpc),
		OBJECT(MODEL_NONE, -6124, 0, 2739, 0, -19, 0, 0x003C0000, bhvSignOnWall),
		OBJECT(MODEL_RED_COIN, 3651, -18, -250, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 2916, -142, -16158, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_NONE, -16607, 0, 5979, 0, 75, 0, 0x003D0000, bhvSignOnWall),
		TERRAIN(wf_area_2_collision),
		ROOMS(wf_area_2_collision_rooms),
		MACRO_OBJECTS(wf_area_2_Area2_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_FEAR),
		TERRAIN_TYPE(TERRAIN_SAND),
	END_AREA(),

	AREA(3, wf_area_3),
		WARP_NODE(0x1A, LEVEL_WF, 0x01, 0x1F, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_WF, 0x01, 0x1A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_MONTY_MOLE, 2990, -74, 14603, 0, 42, 0, 0x01320000, bhvMoleNpc),
		OBJECT(MODEL_CASTLE_GROUNDS_WARP_PIPE, 3357, -74, 14032, 0, -180, 0, 0x001A0000, bhvWarpPipe),
		TERRAIN(wf_area_3_collision),
		ROOMS(wf_area_3_collision_rooms),
		MACRO_OBJECTS(wf_area_3_Area3_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_FEAR),
		TERRAIN_TYPE(TERRAIN_STONE),
	END_AREA(),

	AREA(4, wf_area_4),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_WF, 0x01, 0x1A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x35, LEVEL_WF, 0x01, 0x36, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_BOMB_BOULDER, -3118, 4103, 17418, 0, 0, 0, 0x00000000, bhvBombBoulder),
		OBJECT(MODEL_BOMB_BOULDER, -3145, 4103, 12256, 0, 0, 0, 0x01000000, bhvBombBoulder),
		OBJECT(MODEL_BOMB_BOULDER, -6776, 4103, 9651, 0, 0, 0, 0x02000000, bhvBombBoulder),
		OBJECT(MODEL_BOMB_BOULDER, -4781, 4548, 6116, 0, 0, 0, 0x03000000, bhvBombBoulder),
		OBJECT(MODEL_BOMB_BOULDER, -5281, 5624, -11147, 0, 0, 0, 0x1A000000, bhvBombBoulder),
		OBJECT(MODEL_BOMB_BOULDER, -5281, 5624, -12068, 0, 0, 0, 0x1B000000, bhvBombBoulder),
		OBJECT(MODEL_BOMB_BOULDER, -4593, 4509, -6394, 0, 90, 0, 0x1D000000, bhvBombBoulder),
		OBJECT(MODEL_BOMB_BOULDER, -5938, 4509, -6394, 0, 90, 0, 0x1C000000, bhvBombBoulder),
		OBJECT(MODEL_BOMB_BOULDER, -3165, 4548, 4658, 0, 0, 0, 0xFF000000, bhvBombBoulder),
		OBJECT(MODEL_BOMB_BOULDER, -8656, 4499, 4385, 0, 90, 0, 0x1F000000, bhvBombBoulder),
		OBJECT(MODEL_BOMB_BOULDER, -5303, 4548, -90, 0, 90, 0, 0x20000000, bhvBombBoulder),
		OBJECT(MODEL_BOMB_SWITCH, -3125, 4103, 19299, 0, 0, 0, 0x00000000, bhvBombSwitch),
		OBJECT(MODEL_BOMB_SWITCH, -5307, 3896, 14638, 0, 0, 0, 0x01000000, bhvBombSwitch),
		OBJECT(MODEL_BOMB_SWITCH, -1697, 3782, 7585, 0, 0, 0, 0x02000000, bhvBombSwitch),
		OBJECT(MODEL_BOMB_SWITCH, -6364, 4103, 9638, 0, 0, 0, 0x03000000, bhvBombSwitch),
		OBJECT(MODEL_BOMB_SWITCH, -5938, 4509, -6394, 0, 0, 0, 0x1A000000, bhvBombSwitch),
		OBJECT(MODEL_BOMB_SWITCH, -4593, 4509, -6394, 0, 0, 0, 0x1B000000, bhvBombSwitch),
		OBJECT(MODEL_BOMB_SWITCH, -9294, 3875, -6375, 0, 0, 0, 0x1C000000, bhvBombSwitch),
		OBJECT(MODEL_BOMB_SWITCH, -1461, 4198, -6348, 0, 0, 0, 0x1D000000, bhvBombSwitch),
		OBJECT(MODEL_BOMB_SWITCH, -8656, 4499, 4385, 0, 0, 0, 0x20000000, bhvBombSwitch),
		OBJECT(MODEL_BOMB_SWITCH, -3051, 4380, 1684, 0, 0, 0, 0x1F000000, bhvBombSwitch),
		OBJECT(MODEL_WOODEN_SIGNPOST, -2446, 3761, 21603, 0, -33, 0, 0x003E0000, bhvMessagePanel),
		OBJECT(MODEL_GOOMBA, -2395, 4281, -3751, 0, 0, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_GOOMBA, -1665, 4225, -4903, 0, 0, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_NONE, -3305, 4403, 22445, 0, -180, 0, 0x000A0000, bhvWarps78),
		OBJECT(MODEL_CASTLE_GROUNDS_WARP_PIPE, -4049, 3761, 22282, 0, 0, 0, 0x00350000, bhvWarpPipe),
		OBJECT(MODEL_CASTLE_GROUNDS_WARP_PIPE, -5296, 5624, -14645, 0, -180, 0, 0x00350000, bhvWarpPipe),
		OBJECT(MODEL_STAR, -5296, 5924, -13901, 0, 0, 0, 0x15000000, bhvStar),
		OBJECT(MODEL_STAR, -3181, 4848, 5151, 0, 0, 0, 0x16000000, bhvStar),
		TERRAIN(wf_area_4_collision),
		ROOMS(wf_area_4_collision_rooms),
		MACRO_OBJECTS(wf_area_4_Area4_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_FEAR),
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
