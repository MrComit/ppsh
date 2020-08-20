#include "src/game/envfx_snow.h"

const GeoLayout jrb_area_4_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_SWITCH_CASE(4, geo_switch_area),
		GEO_OPEN_NODE(),
			GEO_BRANCH(1, jrb_dl_Room1D_geo),
			GEO_BRANCH(1, jrb_dl_Room2D_geo),
			GEO_BRANCH(1, jrb_dl_Room3D_geo),
			GEO_BRANCH(1, jrb_dl_Room4D_geo),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout jrb_dl_Room1D_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 12453, -9271, -17747, jrb_dl_Building_164_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT, 12453, -9271, -17640, jrb_dl_Building_165_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 12968, -4145, -17279, jrb_dl_Building_169_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 15268, -6682, -17221, jrb_dl_Building_173_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 10486, -9223, -16671, jrb_dl_CircleTabe_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 14401, -9223, -16924, jrb_dl_CircleTabe_001_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 11612, -9155, -17766, jrb_dl_Cookie_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 11854, -9155, -17756, jrb_dl_Cookie_001_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 12465, -9155, -17759, jrb_dl_Cookie_002_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 13401, -9155, -17749, jrb_dl_Cookie_003_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 13771, -9155, -17833, jrb_dl_Cookie_004_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 10487, -9307, -16370, jrb_dl_Cube_036_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 10221, -9307, -16817, jrb_dl_Cube_038_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 10751, -9307, -16806, jrb_dl_Cube_040_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 14662, -9307, -16773, jrb_dl_Cube_042_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 14143, -9307, -16767, jrb_dl_Cube_044_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 14417, -9307, -17220, jrb_dl_Cube_046_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 13017, -6963, -17774, jrb_dl_Cube_072_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 14102, -6727, -16327, jrb_dl_Cube_073_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT_DECAL, 11370, -9160, -17779, jrb_dl_Plane_002_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT_DECAL, 11738, -9160, -17748, jrb_dl_Plane_003_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT_DECAL, 12272, -9160, -17761, jrb_dl_Plane_004_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT_DECAL, 13676, -9160, -17731, jrb_dl_Plane_005_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT_DECAL, 13044, -9160, -17731, jrb_dl_Plane_006_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT_DECAL, 12529, -8757, -18314, jrb_dl_YoshiCookies_001_mesh),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout jrb_dl_Room2D_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 15724, -9313, -17395, jrb_dl_Ball_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 18500, -9142, -17045, jrb_dl_Building_166_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 17612, -4350, -17194, jrb_dl_Building_172_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 12968, -4145, -17279, jrb_dl_Building_174_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 24229, -4343, -15748, jrb_dl_Building_175_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 19718, -9343, -17271, jrb_dl_Car_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 16907, -9343, -16493, jrb_dl_Car_001_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 16077, -6714, -17658, jrb_dl_Cube_074_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 16886, -6613, -18187, jrb_dl_Cube_075_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 19204, -6167, -16480, jrb_dl_Cube_078_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 17772, -6440, -18187, jrb_dl_Cube_086_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 18692, -6266, -18122, jrb_dl_Cube_087_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 18533, -9300, -17100, jrb_dl_Hammer_001_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 18435, -8894, -17016, jrb_dl_Hammer_002_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 18556, -8904, -17014, jrb_dl_Potted_Plant_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 18486, -9093, -17002, jrb_dl_Potted_Plant_001_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 18432, -9238, -16978, jrb_dl_Potted_Plant_002_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT_DECAL, 17762, -8870, -18314, jrb_dl_ToadsToyStore_001_mesh),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout jrb_dl_Room3D_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 24229, -4343, -15748, jrb_dl_Building_153_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 26380, -9284, -11633, jrb_dl_Building_159_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT, 26380, -9089, -11633, jrb_dl_Building_160_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT, 27060, -6130, -15304, jrb_dl_Building_161_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 26380, -9284, -14462, jrb_dl_Building_162_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT, 26380, -9089, -14462, jrb_dl_Building_163_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 17612, -4350, -17194, jrb_dl_Building_176_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 21009, -9223, -17143, jrb_dl_CircleTabe_002_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 23742, -9223, -16578, jrb_dl_CircleTabe_003_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 21270, -9307, -16993, jrb_dl_Cube_048_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 20751, -9307, -16986, jrb_dl_Cube_050_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 21024, -9307, -17439, jrb_dl_Cube_052_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 24003, -9307, -16729, jrb_dl_Cube_054_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 23749, -9307, -16276, jrb_dl_Cube_056_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 23493, -9307, -16740, jrb_dl_Cube_058_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 21084, -6094, -16934, jrb_dl_Cube_079_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 22152, -6094, -17165, jrb_dl_Cube_080_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 25055, -5792, -17066, jrb_dl_Cube_084_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 27060, -5792, -15781, jrb_dl_Cube_085_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 22719, -6020, -17448, jrb_dl_Cube_088_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 23258, -5910, -17361, jrb_dl_Cube_089_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 24150, -5910, -17071, jrb_dl_Cube_090_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 26382, -9096, -11631, jrb_dl_Glitter_Gem_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 26382, -9097, -14460, jrb_dl_Glitter_Gem_001_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_ALPHA, 22157, -819, -17178, jrb_dl_Rope_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_ALPHA, 22713, -745, -17461, jrb_dl_Rope_001_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_ALPHA, 23276, -684, -17371, jrb_dl_Rope_002_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_ALPHA, 24153, -635, -17063, jrb_dl_Rope_003_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT_DECAL, 27686, -8537, -13703, jrb_dl_ShyGuyMetals_001_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT_DECAL, 23025, -8321, -18314, jrb_dl_subway_001_mesh),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout jrb_dl_Room4D_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT_DECAL, 27686, -8596, -8507, jrb_dl_BBK_001_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 26105, -5161, -9260, jrb_dl_Building_171_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 26338, -9223, -6774, jrb_dl_CircleTabe_004_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 27169, -9223, -10332, jrb_dl_CircleTabe_005_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 26599, -9307, -6924, jrb_dl_Cube_060_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 26344, -9307, -6471, jrb_dl_Cube_062_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 26089, -9307, -6935, jrb_dl_Cube_064_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 27168, -9307, -10633, jrb_dl_Cube_066_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 27434, -9307, -10187, jrb_dl_Cube_068_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 26904, -9307, -10197, jrb_dl_Cube_070_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 26337, -9171, -6762, jrb_dl_Plate_000_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 27169, -9171, -10332, jrb_dl_Plate_001_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 27183, -9234, -7613, jrb_dl_Plate_003_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 27177, -9234, -7451, jrb_dl_Plate_004_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 27180, -9234, -7147, jrb_dl_Plate_005_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 27173, -9208, -6989, jrb_dl_Pot_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 27203, -9208, -7267, jrb_dl_Pot_001_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 27157, -9208, -7756, jrb_dl_Pot_002_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 27172, -9309, -7398, jrb_dl_TableCloth_mesh),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout jrb_area_4[] = {
	GEO_NODE_SCREEN_AREA(10, SCREEN_WIDTH/2, SCREEN_HEIGHT/2, SCREEN_WIDTH/2, SCREEN_HEIGHT/2),
	GEO_OPEN_NODE(),
		GEO_ZBUFFER(0),
		GEO_OPEN_NODE(),
			GEO_NODE_ORTHO(100.0000),
			GEO_OPEN_NODE(),
				GEO_BACKGROUND_COLOR(0x0001),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_ZBUFFER(1),
		GEO_OPEN_NODE(),
			GEO_CAMERA_FRUSTUM_WITH_FUNC(45.0000, 100, 30000, geo_camera_fov),
			GEO_OPEN_NODE(),
				GEO_CAMERA(1, 0, 0, 0, 0, -500, 0, geo_camera_main),
				GEO_OPEN_NODE(),
					GEO_BRANCH(1, jrb_area_4_geo),
					GEO_RENDER_OBJ(),
					GEO_ASM(ENVFX_MODE_NONE, geo_enfvx_main),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, jrb_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_ALPHA, jrb_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, jrb_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, jrb_dl_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
