#include "src/game/envfx_snow.h"

const GeoLayout jrb_area_2_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_SWITCH_CASE(10, geo_switch_area),
		GEO_OPEN_NODE(),
			GEO_BRANCH(1, jrb_dl_Room10B_geo),
			GEO_BRANCH(1, jrb_dl_Room1B_geo),
			GEO_BRANCH(1, jrb_dl_Room2B_geo),
			GEO_BRANCH(1, jrb_dl_Room3B_geo),
			GEO_BRANCH(1, jrb_dl_Room4B_geo),
			GEO_BRANCH(1, jrb_dl_Room5B_geo),
			GEO_BRANCH(1, jrb_dl_Room6B_geo),
			GEO_BRANCH(1, jrb_dl_Room7B_geo),
			GEO_BRANCH(1, jrb_dl_Room8B_geo),
			GEO_BRANCH(1, jrb_dl_Room9B_geo),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout jrb_dl_Room10B_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_ROTATE(1, 0, 0, 0, 0, 0, 0),
		GEO_OPEN_NODE(),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -2159, -2502, -20200, 0, 0, 0, jrb_dl_Bookshelf_006_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -3193, -2851, -20195, 0, 0, 0, jrb_dl_Box_034_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -1929, -1955, -20195, 0, 0, 0, jrb_dl_Box_035_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -2169, -1955, -20195, 0, 0, 0, jrb_dl_Box_036_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -1929, -1731, -20195, 0, 0, 0, jrb_dl_Box_037_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -1929, -1507, -20195, 0, 0, 0, jrb_dl_Box_038_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, 0, 5323, -19798, 0, 0, 0, jrb_dl_Building_179_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(5, 0, 5323, -19798, 0, 0, 0, jrb_dl_Building_184_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(5, 0, 5114, -19798, 0, 0, 0, jrb_dl_Building_185_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(5, 0, 5323, -19798, 0, 0, 0, jrb_dl_Building_186_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(5, 0, 5323, -19798, 0, 0, 0, jrb_dl_Building_187_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -3341, -2784, -21545, 0, 0, 0, jrb_dl_Couch_008_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -2801, -2664, -20242, 0, 0, 0, jrb_dl_Couch_010_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -2417, -2843, -20726, 0, 0, 0, jrb_dl_Cube_092_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -4062, -2843, -20725, 0, 0, 0, jrb_dl_Cube_093_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -3895, -919, -21019, 0, 0, 0, jrb_dl_Cube_094_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(5, -3895, -959, -21019, 0, 0, 0, jrb_dl_Cube_095_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, 4050, -2713, -19125, 0, 0, 0, jrb_dl_Door_002_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, 2550, -2713, -19125, 0, 0, 0, jrb_dl_Door_003_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -2197, -2713, -20021, 0, 0, 0, jrb_dl_Door_004_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -3856, -2713, -19901, 0, 0, 0, jrb_dl_Door_005_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -2197, -2713, -19125, 0, 0, 0, jrb_dl_Door_006_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -3697, -2713, -19125, 0, 0, 0, jrb_dl_Door_007_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, 4050, -804, -20021, 0, 0, 0, jrb_dl_Door_008_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, 2550, -804, -20021, 0, 0, 0, jrb_dl_Door_009_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, 4050, -804, -19125, 0, 0, 0, jrb_dl_Door_010_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, 2550, -804, -19125, 0, 0, 0, jrb_dl_Door_011_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -2197, -804, -20021, 0, 0, 0, jrb_dl_Door_012_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -2197, -804, -19125, 0, 0, 0, jrb_dl_Door_013_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -3697, -804, -19125, 0, 0, 0, jrb_dl_Door_014_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, 3236, -458, -20277, 0, 0, 0, jrb_dl_Mesh_0220_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(6, -3384, -2540, -20021, 0, 0, 0, jrb_dl_OnlyFans_004_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(6, -3307, -2677, -20021, 0, 0, 0, jrb_dl_OnlyFans_005_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -4481, -2962, -21430, 0, 0, 0, jrb_dl_Plane_007_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -4498, -2962, -20462, 0, 0, 0, jrb_dl_Plane_008_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -3839, -2962, -20333, 0, 0, 0, jrb_dl_Plane_009_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -3692, -2962, -21371, 0, 0, 0, jrb_dl_Plane_010_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -2583, -2962, -21389, 0, 0, 0, jrb_dl_Plane_027_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -2268, -949, -21110, 0, 0, 0, jrb_dl_material_0_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -2799, -1020, -21124, 0, 0, 0, jrb_dl_material_0_002_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(5, -2799, -1019, -21124, 0, 0, 0, jrb_dl_material_0_003_mesh),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout jrb_dl_Room1B_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_ROTATE(1, 0, 0, 0, 0, 0, 0),
		GEO_OPEN_NODE(),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -17007, -9539, 3756, 0, 0, 0, jrb_dl_Bookshelf_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -15149, -9701, 3749, 0, 0, 0, jrb_dl_Box_005_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -16537, -9664, 3761, 0, 0, 0, jrb_dl_Box_018_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -17257, -9440, 3103, 0, 0, 0, jrb_dl_Box_021_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -17257, -9328, 2665, 0, 0, 0, jrb_dl_Box_026_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -17257, -9216, 2139, 0, 0, 0, jrb_dl_Box_032_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -16042, -8044, 2629, 0, 0, 0, jrb_dl_Building_038_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -17280, -8242, 1571, 0, 0, 0, jrb_dl_Building_101_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -15932, -9822, 3502, 0, 0, 0, jrb_dl_Couch_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -15032, -9935, 2413, 0, 0, 0, jrb_dl_Cube_005_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -15269, -9927, 2413, 0, 0, 0, jrb_dl_Cube_006_mesh),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout jrb_dl_Room2B_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_ROTATE(1, 0, 0, 0, 0, 0, 0),
		GEO_OPEN_NODE(),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -2305, -4569, 1397, 0, 0, 0, jrb_dl_Bookshelf_004_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -4162, -4731, 1405, 0, 0, 0, jrb_dl_Box_006_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -2774, -4693, 1393, 0, 0, 0, jrb_dl_Box_007_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -2054, -4469, 2050, 0, 0, 0, jrb_dl_Box_008_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -2054, -4357, 2489, 0, 0, 0, jrb_dl_Box_009_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -2054, -4245, 3015, 0, 0, 0, jrb_dl_Box_010_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -3269, -3073, 2525, 0, 0, 0, jrb_dl_Building_037_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -2031, -3271, 3583, 0, 0, 0, jrb_dl_Building_110_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -3380, -4851, 1652, 0, 0, 0, jrb_dl_Couch_004_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -4280, -4965, 2741, 0, 0, 0, jrb_dl_Cube_013_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -4042, -4957, 2741, 0, 0, 0, jrb_dl_Cube_014_mesh),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout jrb_dl_Room3B_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_ROTATE(1, 0, 0, 0, 0, 0, 0),
		GEO_OPEN_NODE(),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -8745, -8287, 6607, 0, 0, 0, jrb_dl_Building_066_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -5634, -7666, 6119, 0, 0, 0, jrb_dl_Building_067_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -6691, -6989, 6771, 0, 0, 0, jrb_dl_Building_096_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -7196, -9572, 5446, 0, 0, 0, jrb_dl_Building_112_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -5634, -9131, 6607, 0, 0, 0, jrb_dl_Building_113_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -7182, -8743, 7810, 0, 0, 0, jrb_dl_Building_114_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -7196, -7930, 5446, 0, 0, 0, jrb_dl_Building_115_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -7196, -7226, 7810, 0, 0, 0, jrb_dl_Building_116_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -7196, -6622, 5446, 0, 0, 0, jrb_dl_Building_117_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -8745, -8287, 6607, 0, 0, 0, jrb_dl_Building_120_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -5634, -6237, 6607, 0, 0, 0, jrb_dl_Building_121_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -8780, -6925, 6607, 0, 0, 0, jrb_dl_Building_122_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -5634, -7514, 6607, 0, 0, 0, jrb_dl_Building_123_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -5637, -9822, 6081, 0, 0, 0, jrb_dl_Couch_002_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -8741, -9822, 6203, 0, 0, 0, jrb_dl_Couch_003_mesh),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout jrb_dl_Room4B_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_ROTATE(1, 0, 0, 0, 0, 0, 0),
		GEO_OPEN_NODE(),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -13207, -1869, 12914, 0, 0, 0, jrb_dl_Bookshelf_002_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -10821, -2797, 13045, 0, 0, 0, jrb_dl_Box_000_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -10853, -2797, 15168, 0, 0, 0, jrb_dl_Box_001_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -9613, -691, 14042, 0, 0, 0, jrb_dl_Building_099_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -13481, -2031, 13449, 0, 0, 0, jrb_dl_Building_119_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -9725, 8, 14897, 0, 0, 0, jrb_dl_Cube_010_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -9725, 16, 14625, 0, 0, 0, jrb_dl_Cube_011_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -9600, -2930, 14090, 0, 0, 0, jrb_dl_Cube_017_mesh),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout jrb_dl_Room5B_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_ROTATE(1, 0, 0, 0, 0, 0, 0),
		GEO_OPEN_NODE(),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -20021, -8741, 23391, 0, 0, 0, jrb_dl_Box_002_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -20001, -8965, 22492, 0, 0, 0, jrb_dl_Box_003_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -19653, -8853, 23121, 0, 0, 0, jrb_dl_Box_004_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -19506, -8741, 22518, 0, 0, 0, jrb_dl_Box_011_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -19416, -8703, 23603, 0, 0, 0, jrb_dl_Box_012_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -19864, -8853, 23886, 0, 0, 0, jrb_dl_Box_013_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -20026, -8703, 24256, 0, 0, 0, jrb_dl_Box_014_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -19474, -8965, 24179, 0, 0, 0, jrb_dl_Box_015_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -16498, -7559, 24499, 0, 0, 0, jrb_dl_Building_127_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -17621, -8051, 26526, 0, 0, 0, jrb_dl_Cube_002_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, -17621, -8042, 26798, 0, 0, 0, jrb_dl_Cube_003_mesh),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout jrb_dl_Room6B_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_ROTATE(1, 0, 0, 0, 0, 0, 0),
		GEO_OPEN_NODE(),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, 11011, -798, 23633, 0, 0, 0, jrb_dl_Building_034_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, 9903, -3022, 23650, 0, 0, 0, jrb_dl_Computer_002_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, 10054, -3129, 23651, 0, 0, 0, jrb_dl_Cube_027_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, 9834, -3122, 23651, 0, 0, 0, jrb_dl_Cube_028_mesh),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout jrb_dl_Room7B_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_ROTATE(1, 0, 0, 0, 0, 0, 0),
		GEO_OPEN_NODE(),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, 13601, -798, 26519, 0, 0, 0, jrb_dl_Building_035_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, 14535, -3022, 26872, 0, 0, 0, jrb_dl_Computer_005_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, 14561, -3122, 26874, 0, 0, 0, jrb_dl_Cube_032_mesh),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout jrb_dl_Room8B_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_ROTATE(1, 0, 0, 0, 0, 0, 0),
		GEO_OPEN_NODE(),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, 17166, -798, 18150, 0, 0, 0, jrb_dl_Building_130_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, 17171, -3022, 17090, 0, 0, 0, jrb_dl_Computer_000_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, 17175, -3129, 17242, 0, 0, 0, jrb_dl_Cube_023_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, 17175, -3122, 17022, 0, 0, 0, jrb_dl_Cube_024_mesh),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout jrb_dl_Room9B_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_ROTATE(1, 0, 0, 0, 0, 0, 0),
		GEO_OPEN_NODE(),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, 16462, -277, 26776, 0, 0, 0, jrb_dl_Box_016_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, 16483, -501, 25877, 0, 0, 0, jrb_dl_Box_017_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, 16831, -389, 26505, 0, 0, 0, jrb_dl_Box_019_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, 16978, -277, 25903, 0, 0, 0, jrb_dl_Box_020_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, 17067, -239, 26987, 0, 0, 0, jrb_dl_Box_022_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, 16620, -389, 27271, 0, 0, 0, jrb_dl_Box_023_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, 16457, -239, 27641, 0, 0, 0, jrb_dl_Box_024_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, 17010, -501, 27564, 0, 0, 0, jrb_dl_Box_025_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, 18166, -165, 26493, 0, 0, 0, jrb_dl_Box_027_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, 18203, -165, 27054, 0, 0, 0, jrb_dl_Box_028_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, 17695, -239, 26762, 0, 0, 0, jrb_dl_Box_029_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, 17625, -389, 27319, 0, 0, 0, jrb_dl_Box_030_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, 17923, -501, 26066, 0, 0, 0, jrb_dl_Box_031_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, 17282, -277, 26398, 0, 0, 0, jrb_dl_Box_033_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, 18186, -153, 26712, 0, 0, 0, jrb_dl_Building_134_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, 16266, -3022, 26825, 0, 0, 0, jrb_dl_Computer_001_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, 16409, -3129, 26826, 0, 0, 0, jrb_dl_Cube_033_mesh),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, 16188, -3122, 26826, 0, 0, 0, jrb_dl_Cube_034_mesh),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout jrb_area_2[] = {
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
					GEO_BRANCH(1, jrb_area_2_geo),
					GEO_RENDER_OBJ(),
					GEO_ASM(ENVFX_MODE_NONE, geo_enfvx_main),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(1, jrb_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(5, jrb_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(6, jrb_dl_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
