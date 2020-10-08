#include "src/game/envfx_snow.h"

const GeoLayout jrb_area_1_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ANIMATED_PART(LAYER_TRANSPARENT_DECAL, 24617, -3190, 20867, jrb_dl_Arrow_002_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT_DECAL, 604, -9274, 20556, jrb_dl_AssImpact_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT_DECAL, 25498, -8334, -8507, jrb_dl_BBK_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT_DECAL, 14385, -2769, -1122, jrb_dl_BBK_002_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -1121, -9275, 22417, jrb_dl_Billboard_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -1121, -9275, 18612, jrb_dl_Billboard_001_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 999, -9275, 20514, jrb_dl_Billboard_002_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -7964, -9944, -3888, jrb_dl_BounceBox_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 7286, -9944, 4020, jrb_dl_BounceBox_001_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 12662, -9944, 3646, jrb_dl_BounceBox_002_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -11052, -9938, 10354, jrb_dl_BounceBox_003_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 9412, -9938, 10707, jrb_dl_BounceBox_004_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -23, -9134, -6899, jrb_dl_Bounds_001_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 18008, -9722, -5743, jrb_dl_Bounds_003_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, -10170, 10362, jrb_dl_Bounds_005_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, -10002, 23418, jrb_dl_Bounds_007_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 7257, -6244, -10474, jrb_dl_Bounds_009_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -30101, -10143, -13779, jrb_dl_Bounds_010_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -25708, -9771, -19197, jrb_dl_Bounds_011_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -22154, -10100, -13292, jrb_dl_Bounds_012_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -25439, -8952, -8502, jrb_dl_Bounds_013_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -24808, -10141, -15434, jrb_dl_Bounds_014_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 20284, 1155, 20906, jrb_dl_Bounds_015_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 21264, 215, 22334, jrb_dl_Building_000_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 18030, -2870, 6628, jrb_dl_Building_001_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -7359, -7919, 23689, jrb_dl_Building_002_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 13473, 215, 6628, jrb_dl_Building_003_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 17950, 133, 26737, jrb_dl_Building_006_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -3228, -1537, 2577, jrb_dl_Building_007_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 26025, 215, 19110, jrb_dl_Building_008_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 5323, -17202, jrb_dl_Building_009_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 17166, -798, 18007, jrb_dl_Building_010_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 21347, 216, -10863, jrb_dl_Building_012_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 14443, -3795, -7500, jrb_dl_Building_013_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 13601, 215, 17893, jrb_dl_Building_014_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 21264, 215, 17893, jrb_dl_Building_015_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 7562, -3341, -9246, jrb_dl_Building_016_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -647, -3190, 22326, jrb_dl_Building_017_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 10868, -798, 23633, jrb_dl_Building_018_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, -5800, 30145, jrb_dl_Building_019_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 10856, 215, -3879, jrb_dl_Building_021_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 21618, 216, -12087, jrb_dl_Building_022_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -3228, -4107, -3879, jrb_dl_Building_023_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 14443, -6595, 2577, jrb_dl_Building_026_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 14443, -5940, -3879, jrb_dl_Building_027_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 3228, -7822, 3059, jrb_dl_Building_028_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 10856, -6595, 2577, jrb_dl_Building_029_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -9407, -4392, -3879, jrb_dl_Building_030_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 5248, -4390, -3879, jrb_dl_Building_031_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -12635, -5800, -10381, jrb_dl_Building_032_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 18030, 143, 2577, jrb_dl_Building_033_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -5438, 1619, -3879, jrb_dl_Building_036_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -3881, 1918, -10165, jrb_dl_Building_039_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_ALPHA, -7968, 1241, -3879, jrb_dl_Building_040_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -14179, 198, -3879, jrb_dl_Building_041_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -16730, -5010, -3879, jrb_dl_Building_042_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -16083, -4770, 2577, jrb_dl_Building_043_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -25311, 7453, -7532, jrb_dl_Building_044_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -11449, -5013, 2577, jrb_dl_Building_046_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -12496, 215, 6628, jrb_dl_Building_047_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -6545, -3070, 6684, jrb_dl_Building_048_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 21618, 216, -7500, jrb_dl_Building_050_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -6815, 215, 2577, jrb_dl_Building_051_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 7562, -3341, -13333, jrb_dl_Building_052_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 7562, -3341, -17421, jrb_dl_Building_054_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_ALPHA, -14179, 198, -3879, jrb_dl_Building_056_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 3228, -7822, 6628, jrb_dl_Building_057_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -3228, -7515, 6628, jrb_dl_Building_059_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 3662, -7694, 2712, jrb_dl_Building_060_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 13601, -798, 26662, jrb_dl_Building_061_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -16083, -5974, 6628, jrb_dl_Building_062_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -9031, -1773, 14047, jrb_dl_Building_063_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 24205, -6595, -651, jrb_dl_Building_064_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -18803, -6187, 19015, jrb_dl_Building_069_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 8238, -2885, 6628, jrb_dl_Building_070_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 14443, -5341, 10215, jrb_dl_Building_075_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 10856, -6595, 10697, jrb_dl_Building_077_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 21618, -3190, 10215, jrb_dl_Building_078_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 7268, -4390, 2577, jrb_dl_Building_079_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -12525, -5007, 10361, jrb_dl_Building_083_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_ALPHA, 10851, -6639, 14034, jrb_dl_Building_124_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT, -15369, -8601, 23258, jrb_dl_Building_125_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 14443, -3795, -12087, jrb_dl_Building_140_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 22824, -5800, -651, jrb_dl_Building_141_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 21802, -5976, -14925, jrb_dl_Building_148_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -1733, -9862, 7745, jrb_dl_Cone_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 5232, -9863, 14632, jrb_dl_Cone_001_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 5861, -9863, 14180, jrb_dl_Cone_002_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 6432, -9863, 14708, jrb_dl_Cone_003_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 6916, -9863, 14238, jrb_dl_Cone_004_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 7917, -9863, 14759, jrb_dl_Cone_005_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 9746, -9863, 14774, jrb_dl_Cone_006_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 9049, -9863, 13919, jrb_dl_Cone_007_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -1733, -9862, 6883, jrb_dl_Cone_008_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -1733, -9862, 5674, jrb_dl_Cone_009_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 1697, -9862, 5525, jrb_dl_Cone_010_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 1697, -9862, 6386, jrb_dl_Cone_011_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 1697, -9862, 7596, jrb_dl_Cone_012_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -4025, -9862, 9451, jrb_dl_Cone_013_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -5712, -9862, 10059, jrb_dl_Cone_014_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -3925, -9862, 11055, jrb_dl_Cone_015_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -1298, -9862, 3457, jrb_dl_Cone_016_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -411, -9862, 2424, jrb_dl_Cone_017_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -1498, -9862, 1745, jrb_dl_Cone_018_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -9333, -9862, 12071, jrb_dl_Cone_019_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -15870, -9857, 12191, jrb_dl_Cone_020_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -18522, -9857, 10577, jrb_dl_Cone_021_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -16353, -9857, 9011, jrb_dl_Cone_022_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 19806, -9245, -10230, jrb_dl_Cone_023_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 17353, -9245, -11483, jrb_dl_Cone_024_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 17154, -9245, -9053, jrb_dl_Cone_025_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 18216, -9863, 10234, jrb_dl_Cone_026_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 19506, -9863, 13388, jrb_dl_Cone_027_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 14952, -9863, 12647, jrb_dl_Cone_028_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 17282, -9863, 14151, jrb_dl_Cone_029_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 18799, -9863, 12212, jrb_dl_Cone_030_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 21628, -9863, 13564, jrb_dl_Cone_031_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -13833, -883, 14877, jrb_dl_Crate_002_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 20494, 3791, 9092, jrb_dl_Crate_003_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -6862, 144, 5845, jrb_dl_Crate_004_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -10347, -7955, 24722, jrb_dl_Crate_005_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -10347, -7955, 25776, jrb_dl_Crate_008_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -5004, 12304, -11289, jrb_dl_Crate_011_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 3303, 13335, -14429, jrb_dl_Cube_076_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 3303, 13164, -14929, jrb_dl_Cube_077_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT_DECAL, -7372, -9533, 9570, jrb_dl_Gex_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT_DECAL, -3288, -9661, 3900, jrb_dl_GreenCumet_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT_DECAL, -8183, -9750, 9570, jrb_dl_NPG_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -3234, -9448, 3870, jrb_dl_Neon_001_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -7527, -9616, 9540, jrb_dl_Neon_002_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -13199, -9610, 5332, jrb_dl_Neon_003_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT_DECAL, -13199, -9610, 5323, jrb_dl_Neon_004_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -3234, -9596, 7921, jrb_dl_Neon_005_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 8233, -9495, 5334, jrb_dl_Neon_006_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT_DECAL, 8233, -9495, 5334, jrb_dl_Neon_008_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT_DECAL, 214, -6015, 6678, jrb_dl_OnlyFans_000_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT_DECAL, 586, -6678, 6678, jrb_dl_OnlyFans_001_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 510, -6015, 6615, jrb_dl_OnlyFans_002_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -14443, -9825, 23253, jrb_dl_OnlyFans_003_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -201, -10026, 5976, jrb_dl_Plane_001_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -9969, -9921, 8080, jrb_dl_Pot_003_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_ALPHA, 0, -9956, 19720, jrb_dl_Rail_Fence_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_ALPHA, 14337, 4871, 7976, jrb_dl_Rail_Fence_001_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_ALPHA, 10851, -3234, 14034, jrb_dl_Rail_Fence_002_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_ALPHA, -3233, 1737, -1383, jrb_dl_Rail_Fence_003_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_ALPHA, -67, 1459, -3897, jrb_dl_Rail_Fence_004_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_ALPHA, 11160, -3201, 6553, jrb_dl_Rail_Fence_005_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_ALPHA, 10551, -3201, 6553, jrb_dl_Rail_Fence_006_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_ALPHA, 16681, 5460, 1031, jrb_dl_Rail_Fence_007_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_ALPHA, 13966, -6800, 7758, jrb_dl_Rail_Fence_008_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_ALPHA, 7264, 1176, -651, jrb_dl_Rail_Fence_009_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_ALPHA, 11240, 1418, -3627, jrb_dl_Rail_Fence_010_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_ALPHA, -3222, -4151, 10361, jrb_dl_Rail_Fence_011_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_ALPHA, -16086, -65, -651, jrb_dl_Rail_Fence_012_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_ALPHA, -11949, -731, 7937, jrb_dl_Rail_Fence_013_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_ALPHA, 17976, -105, 9318, jrb_dl_Rail_Fence_014_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_ALPHA, 20450, 1771, 18616, jrb_dl_Rail_Fence_015_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_ALPHA, 14439, -2056, -2241, jrb_dl_Rail_Fence_016_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_ALPHA, -5479, 12089, -9592, jrb_dl_Rail_Fence_017_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_ALPHA, -7862, -9956, 5299, jrb_dl_Rail_Fence_018_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_ALPHA, 197, -9956, -2534, jrb_dl_Rail_Fence_019_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_ALPHA, -7164, -9956, 1232, jrb_dl_Rail_Fence_020_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_ALPHA, 10507, -9956, 1232, jrb_dl_Rail_Fence_021_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_ALPHA, -23165, -9956, 1212, jrb_dl_Rail_Fence_022_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_ALPHA, -17428, -9956, 6628, jrb_dl_Rail_Fence_023_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_ALPHA, -8403, -9950, 12749, jrb_dl_Rail_Fence_024_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_ALPHA, -8403, -9950, 15439, jrb_dl_Rail_Fence_025_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_ALPHA, -4467, 365, 9329, jrb_dl_Rail_Fence_026_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT_DECAL, 25499, -8023, -13703, jrb_dl_ShyGuyMetals_mesh),
		GEO_TRANSLATE_NODE(LAYER_TRANSPARENT, 4623, -10089, 9395),
		GEO_OPEN_NODE(),
			GEO_RENDER_RANGE(-4096, 8192),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_TRANSPARENT, jrb_dl_Sprinkler_mesh),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE(LAYER_TRANSPARENT, 7123, -10089, 9395),
		GEO_OPEN_NODE(),
			GEO_RENDER_RANGE(-4096, 8192),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_TRANSPARENT, jrb_dl_Sprinkler_001_mesh),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT_DECAL, -678, -9246, 22459, jrb_dl_StarChode_mesh),
		GEO_TRANSLATE_NODE(LAYER_OPAQUE, 27, -9740, 10439),
		GEO_OPEN_NODE(),
			GEO_SHADOW(1, 179, 100),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_OPAQUE, jrb_dl_Statue_mesh),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE(LAYER_OPAQUE, -45, -9489, 10265),
		GEO_OPEN_NODE(),
			GEO_RENDER_RANGE(-4096, 8192),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_OPAQUE, jrb_dl_Statue_LOD_mesh),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, -10272, 10362, jrb_dl_Statue_001_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -11806, -9976, 23536, jrb_dl_Stick_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -11541, -9966, 23442, jrb_dl_Stick_001_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -11854, -9982, 23393, jrb_dl_Stick_002_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -11768, -9985, 23319, jrb_dl_Stick_003_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -11562, -9985, 23539, jrb_dl_Stick_004_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -11675, -9968, 23331, jrb_dl_Stick_005_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -11708, -9985, 23572, jrb_dl_Stick_006_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -11569, -9985, 23300, jrb_dl_Stick_007_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -5666, -10000, 8199, jrb_dl_StreetLight_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT, -5666, -10000, 8199, jrb_dl_StreetLight_001_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -1730, -9999, 6237, jrb_dl_StreetLight_002_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT, -1730, -9999, 6237, jrb_dl_StreetLight_003_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 1693, -9999, 7032, jrb_dl_StreetLight2_002_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT, 1693, -9999, 7032, jrb_dl_StreetLight2_003_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT_DECAL, 17762, -7941, -16127, jrb_dl_ToadsToyStore_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT_DECAL, -3330, -9208, 7951, jrb_dl_Venmo_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_ALPHA, -3226, -5062, 4602, jrb_dl_Window_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_ALPHA, -3228, 1771, 477, jrb_dl_Window_001_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_ALPHA, 10856, -3350, 4148, jrb_dl_Window_002_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_ALPHA, 19101, 4076, 7699, jrb_dl_Window_003_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_ALPHA, -3228, 1771, 477, jrb_dl_Window_004_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_ALPHA, 10828, 1631, -7956, jrb_dl_Window_005_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_ALPHA, -16081, -1998, 4602, jrb_dl_Window_006_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_ALPHA, 8361, 1431, -8556, jrb_dl_Window_007_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_ALPHA, 12649, -9046, 2577, jrb_dl_Window_008_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_ALPHA, 22576, 3405, 11418, jrb_dl_Window_009_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_ALPHA, 21628, 6732, -9525, jrb_dl_Window_010_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_ALPHA, 7549, 1582, -11272, jrb_dl_Window_011_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_ALPHA, 7549, 1582, -15359, jrb_dl_Window_012_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_ALPHA, 5943, 1582, -17762, jrb_dl_Window_013_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT_DECAL, -717, -9379, 18654, jrb_dl_YCTF64_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT_DECAL, 12529, -8010, -16127, jrb_dl_YoshiCookies_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -1162, -7405, -2093, jrb_dl_ZZZZZZZZZZZ_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -1162, -7405, -2093, jrb_dl_ZZZZZZZZZZZ_001_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -12803, 11232, -7200, jrb_dl_ZZZZZZZZZZZ_002_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT, 5873, -10025, 10362, jrb_dl_ZZZZZZZZZZZ_003_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT_DECAL, 23025, -8321, -16127, jrb_dl_subway_mesh),
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
			GEO_CAMERA_FRUSTUM_WITH_FUNC(45.0000, 100, 32767, geo_camera_fov),
			GEO_OPEN_NODE(),
				GEO_CAMERA(1, 0, 0, 0, 0, -500, 0, geo_camera_main),
				GEO_OPEN_NODE(),
					GEO_BRANCH(1, jrb_area_1_geo),
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
