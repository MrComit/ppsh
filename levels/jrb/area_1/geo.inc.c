#include "src/game/envfx_snow.h"

const GeoLayout jrb_area_1_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_ROTATE(1, 0, 0, 0, 0, 0, 0),
		GEO_OPEN_NODE(),
			GEO_TRANSLATE_ROTATE_WITH_DL(6, 25498, -7929, -11102, 0, 0, 0, jrb_dl_BBK_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -1162, -7405, -4689, 0, 0, 0, jrb_dl_Bounds_000_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, 0, -9130, -9495, 0, 0, 0, jrb_dl_Bounds_001_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, 18030, -9718, -8339, 0, 0, 0, jrb_dl_Bounds_003_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, 0, -10170, 10362, 0, 0, 0, jrb_dl_Bounds_005_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, 18821, -1937, 23552, 0, 0, 0, jrb_dl_Bounds_007_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -1970, -9999, 26279, 0, 0, 0, jrb_dl_Bounds_008_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -3228, -1537, 2577, 0, 0, 0, jrb_dl_Building_007_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, 0, 5323, -19798, 0, 0, 0, jrb_dl_Building_009_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, 13601, 215, 17893, 0, 0, 0, jrb_dl_Building_014_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, 21264, 215, 17893, 0, 0, 0, jrb_dl_Building_015_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -647, -3190, 22326, 0, 0, 0, jrb_dl_Building_017_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, 5248, -4390, -3879, 0, 0, 0, jrb_dl_Building_031_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, 18030, 215, 2577, 0, 0, 0, jrb_dl_Building_033_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, 21802, -5976, -17521, 0, 0, 0, jrb_dl_Building_045_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, 21618, 215, -10096, 0, 0, 0, jrb_dl_Building_050_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, 0, -8550, 30149, 0, 0, 0, jrb_dl_Building_053_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -31455, -8550, -651, 0, 0, 0, jrb_dl_Building_055_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, 3228, -7822, 6628, 0, 0, 0, jrb_dl_Building_057_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -3228, -7515, 6628, 0, 0, 0, jrb_dl_Building_059_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, 3228, -7822, 3059, 0, 0, 0, jrb_dl_Building_028_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, 3662, -7694, 2712, 0, 0, 0, jrb_dl_Building_060_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -9031, -1773, 14047, 0, 0, 0, jrb_dl_Building_063_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, 24205, -6595, -651, 0, 0, 0, jrb_dl_Building_064_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -12635, -5800, -12976, 0, 0, 0, jrb_dl_Building_032_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, 14443, -6595, 2577, 0, 0, 0, jrb_dl_Building_026_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, 14443, -5940, -3879, 0, 0, 0, jrb_dl_Building_027_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, 10856, -6595, 2577, 0, 0, 0, jrb_dl_Building_029_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -3228, -4107, -3879, 0, 0, 0, jrb_dl_Building_023_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -18803, -6187, 19015, 0, 0, 0, jrb_dl_Building_069_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -7359, -7919, 23689, 0, 0, 0, jrb_dl_Building_002_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, 18030, -2870, 6628, 0, 0, 0, jrb_dl_Building_001_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, 13473, 215, 6628, 0, 0, 0, jrb_dl_Building_003_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, 8238, -2885, 6628, 0, 0, 0, jrb_dl_Building_070_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -16083, -5974, 6628, 0, 0, 0, jrb_dl_Building_062_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, 14443, -5341, 10215, 0, 0, 0, jrb_dl_Building_075_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, 10856, -6595, 10697, 0, 0, 0, jrb_dl_Building_077_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, 21618, -3190, 10215, 0, 0, 0, jrb_dl_Building_078_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, 7268, -4390, 2577, 0, 0, 0, jrb_dl_Building_079_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, 25352, 215, 20114, 0, 0, 0, jrb_dl_Building_008_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, 13601, -798, 26662, 0, 0, 0, jrb_dl_Building_061_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, 18030, 215, -3879, 0, 0, 0, jrb_dl_Building_019_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, 10856, 215, -3879, 0, 0, 0, jrb_dl_Building_021_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -9407, -4392, -3879, 0, 0, 0, jrb_dl_Building_030_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, 14443, -3795, -10096, 0, 0, 0, jrb_dl_Building_013_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, 7562, -3341, -11842, 0, 0, 0, jrb_dl_Building_016_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -5438, 1619, -3879, 0, 0, 0, jrb_dl_Building_036_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -7074, 1333, -3879, 0, 0, 0, jrb_dl_Building_040_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -14179, 198, -3879, 0, 0, 0, jrb_dl_Building_041_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -16730, -5010, -3879, 0, 0, 0, jrb_dl_Building_042_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -20964, 4845, -3879, 0, 0, 0, jrb_dl_Building_044_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -11449, -5013, 2577, 0, 0, 0, jrb_dl_Building_046_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -6545, -3070, 6684, 0, 0, 0, jrb_dl_Building_048_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, 7562, -3341, -15929, 0, 0, 0, jrb_dl_Building_052_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, 7562, -3341, -20016, 0, 0, 0, jrb_dl_Building_054_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -11634, 921, -3879, 0, 0, 0, jrb_dl_Building_056_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -12913, 595, -3879, 0, 0, 0, jrb_dl_Building_058_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -12496, 215, 6628, 0, 0, 0, jrb_dl_Building_047_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -6815, 215, 2577, 0, 0, 0, jrb_dl_Building_051_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -3881, 1918, -12761, 0, 0, 0, jrb_dl_Building_039_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -12525, -5007, 10361, 0, 0, 0, jrb_dl_Building_083_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -20823, -4297, 7917, 0, 0, 0, jrb_dl_Building_084_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -16083, -4770, 2577, 0, 0, 0, jrb_dl_Building_043_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(4, 10851, -6639, 14034, 0, 0, 0, jrb_dl_Building_124_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(5, -15369, -8601, 23258, 0, 0, 0, jrb_dl_Building_125_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, 21264, 215, 22334, 0, 0, 0, jrb_dl_Building_000_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, 17950, 133, 26737, 0, 0, 0, jrb_dl_Building_006_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, 10868, -798, 23633, 0, 0, 0, jrb_dl_Building_018_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, 17166, -798, 18007, 0, 0, 0, jrb_dl_Building_010_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, 21618, 216, -14683, 0, 0, 0, jrb_dl_Building_022_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, 14443, -3795, -14683, 0, 0, 0, jrb_dl_Building_140_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, 21347, 216, -13458, 0, 0, 0, jrb_dl_Building_012_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, 22824, -5800, -651, 0, 0, 0, jrb_dl_Building_141_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -13833, -883, 14877, 0, 0, 0, jrb_dl_Crate_002_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -5800, 12884, 21686, 0, 0, 0, jrb_dl_Crate_003_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -6862, 144, 5504, 0, 0, 0, jrb_dl_Crate_000_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -6862, 485, 5504, 0, 0, 0, jrb_dl_Crate_001_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -6862, 144, 5845, 0, 0, 0, jrb_dl_Crate_004_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -10347, -7955, 24722, 0, 0, 0, jrb_dl_Crate_005_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -10347, -7955, 25062, 0, 0, 0, jrb_dl_Crate_006_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -10347, -7615, 25062, 0, 0, 0, jrb_dl_Crate_007_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -10347, -7955, 25776, 0, 0, 0, jrb_dl_Crate_008_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -10347, -7615, 25776, 0, 0, 0, jrb_dl_Crate_009_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -10347, -7275, 25776, 0, 0, 0, jrb_dl_Crate_010_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, 510, -6015, 6615, 0, 0, 0, jrb_dl_OnlyFans_002_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(6, 214, -6015, 6678, 0, 0, 0, jrb_dl_OnlyFans_000_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(6, 586, -6678, 6678, 0, 0, 0, jrb_dl_OnlyFans_001_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -14443, -9825, 23253, 0, 0, 0, jrb_dl_OnlyFans_003_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -201, -10022, 5976, 0, 0, 0, jrb_dl_Plane_001_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(4, 0, -9956, 19720, 0, 0, 0, jrb_dl_Rail_Fence_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(4, 10851, -3234, 14034, 0, 0, 0, jrb_dl_Rail_Fence_002_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(4, -3233, 1737, -1383, 0, 0, 0, jrb_dl_Rail_Fence_003_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(4, -67, 1459, -3897, 0, 0, 0, jrb_dl_Rail_Fence_004_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(4, 10551, -3201, 6553, 0, 0, 0, jrb_dl_Rail_Fence_006_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(4, 11160, -3201, 6553, 0, 0, 0, jrb_dl_Rail_Fence_005_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(4, 13966, -6800, 7758, 0, 0, 0, jrb_dl_Rail_Fence_008_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(4, 14337, 4871, 7976, 0, 0, 0, jrb_dl_Rail_Fence_001_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(4, 16681, 5460, 1031, 0, 0, 0, jrb_dl_Rail_Fence_007_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(4, 7264, 1176, -651, 0, 0, 0, jrb_dl_Rail_Fence_009_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(4, 11240, 1418, -3627, 0, 0, 0, jrb_dl_Rail_Fence_010_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(4, -3222, -4151, 10361, 0, 0, 0, jrb_dl_Rail_Fence_011_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(4, -16086, -65, -651, 0, 0, 0, jrb_dl_Rail_Fence_012_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(4, -11949, -731, 7937, 0, 0, 0, jrb_dl_Rail_Fence_013_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(4, 17976, -105, 9318, 0, 0, 0, jrb_dl_Rail_Fence_014_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(4, 20450, 1771, 18616, 0, 0, 0, jrb_dl_Rail_Fence_015_mesh),
			GEO_ANIMATED_PART(2, 2351, -9995, -8778, jrb_dl_Road_001_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(6, 25499, -7419, -16299, 0, 0, 0, jrb_dl_ShyGuyMetals_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -23211, -9563, -13445, 0, 0, 0, jrb_dl_Skate_Ramp_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -27058, -9563, -18817, 0, 0, 0, jrb_dl_Skate_Ramp_001_mesh),
			GEO_TRANSLATE_ROTATE(1, -45, -9489, 10265, 0, 0, 0),
			GEO_OPEN_NODE(),
				GEO_RENDER_RANGE(-4096, 8192),
				GEO_OPEN_NODE(),
					GEO_DISPLAY_LIST(1, jrb_dl_Statue_LOD_mesh),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
			GEO_TRANSLATE_ROTATE(1, 27, -9740, 10439, 0, 0, 0),
			GEO_OPEN_NODE(),
				GEO_SHADOW(1, 179, 100),
				GEO_OPEN_NODE(),
					GEO_DISPLAY_LIST(1, jrb_dl_Statue_mesh),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, 0, -10272, 10362, 0, 0, 0, jrb_dl_Statue_001_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -11569, -9985, 23300, 0, 0, 0, jrb_dl_Stick_007_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -11806, -9976, 23536, 0, 0, 0, jrb_dl_Stick_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -11541, -9966, 23442, 0, 0, 0, jrb_dl_Stick_001_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -11854, -9982, 23393, 0, 0, 0, jrb_dl_Stick_002_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -11768, -9985, 23319, 0, 0, 0, jrb_dl_Stick_003_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -11562, -9985, 23539, 0, 0, 0, jrb_dl_Stick_004_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -11675, -9968, 23331, 0, 0, 0, jrb_dl_Stick_005_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -11708, -9985, 23572, 0, 0, 0, jrb_dl_Stick_006_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(6, 23025, -7587, -18723, 0, 0, 0, jrb_dl_subway_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(6, 17762, -7535, -18722, 0, 0, 0, jrb_dl_ToadsToyStore_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(4, -3226, -5062, 4602, 0, 0, 0, jrb_dl_Window_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(4, -3228, 1771, 477, 0, 0, 0, jrb_dl_Window_001_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(4, 10856, -3350, 4148, 0, 0, 0, jrb_dl_Window_002_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(4, 19101, 4076, 7699, 0, 0, 0, jrb_dl_Window_003_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(4, 10828, 1631, -10552, 0, 0, 0, jrb_dl_Window_005_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(4, 13987, 1631, -8274, 0, 0, 0, jrb_dl_Window_004_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(4, 8361, 1431, -11152, 0, 0, 0, jrb_dl_Window_007_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(4, -16081, -1998, 4602, 0, 0, 0, jrb_dl_Window_006_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(4, 12649, -9046, 2577, 0, 0, 0, jrb_dl_Window_008_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(4, 22576, 3405, 11418, 0, 0, 0, jrb_dl_Window_009_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(4, 21628, 6732, -12121, 0, 0, 0, jrb_dl_Window_010_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(6, 12529, -7604, -18722, 0, 0, 0, jrb_dl_YoshiCookies_mesh),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout jrb_area_1[] = {
	GEO_NODE_SCREEN_AREA(10, SCREEN_WIDTH/2, SCREEN_HEIGHT/2, SCREEN_WIDTH/2, SCREEN_HEIGHT/2),
	GEO_OPEN_NODE(),
		GEO_ZBUFFER(0),
		GEO_OPEN_NODE(),
			GEO_NODE_ORTHO(100.0000),
			GEO_OPEN_NODE(),
				GEO_BACKGROUND(BACKGROUND_HAUNTED, geo_skybox_main),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_ZBUFFER(1),
		GEO_OPEN_NODE(),
			GEO_CAMERA_FRUSTUM_WITH_FUNC(45.0000, 100, 30000, geo_camera_fov),
			GEO_OPEN_NODE(),
				GEO_CAMERA(1, 0, 0, 0, 0, -500, 0, geo_camera_main),
				GEO_OPEN_NODE(),
					GEO_BRANCH(1, jrb_area_1_geo),
					GEO_RENDER_OBJ(),
					GEO_ASM(ENVFX_MODE_NONE, geo_enfvx_main),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(0, jrb_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(1, jrb_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(2, jrb_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(3, jrb_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(4, jrb_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(5, jrb_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(6, jrb_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(7, jrb_dl_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
