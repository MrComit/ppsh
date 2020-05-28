#include "src/game/envfx_snow.h"

const GeoLayout wf_area_3_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ANIMATED_PART(1, 0, 0, 0, NULL),
		GEO_OPEN_NODE(),
			GEO_ANIMATED_PART(1, 0, 0, 0, NULL),
			GEO_OPEN_NODE(),
				GEO_ANIMATED_PART(1, -1551, 1006, 14529, wf_dl_BaseGround_006_mesh),
				GEO_ANIMATED_PART(6, -1551, 1759, 14529, wf_dl_BaseGround_007_mesh),
				GEO_ANIMATED_PART(6, -1551, 1120, 14529, wf_dl_BaseGround_008_mesh),
				GEO_ANIMATED_PART(1, 894, 327, 14529, wf_dl_BaseGround_009_mesh),
				GEO_ANIMATED_PART(1, 894, 327, 16974, wf_dl_BaseGround_010_mesh),
				GEO_ANIMATED_PART(1, 3339, 327, 16974, wf_dl_BaseGround_011_mesh),
				GEO_ANIMATED_PART(1, 3339, 327, 14529, wf_dl_BaseGround_012_mesh),
				GEO_ANIMATED_PART(6, -704, 232, 14529, wf_dl_MolePainting_001_mesh),
				GEO_ANIMATED_PART(6, -1551, 232, 13682, wf_dl_MolePainting_002_mesh),
				GEO_ANIMATED_PART(6, -1551, 232, 15377, wf_dl_MolePainting_003_mesh),
				GEO_ANIMATED_PART(6, 1741, 232, 14529, wf_dl_MolePainting_000_mesh),
				GEO_ANIMATED_PART(6, 894, 232, 13682, wf_dl_MolePainting_004_mesh),
				GEO_ANIMATED_PART(6, 894, 232, 15377, wf_dl_MolePainting_005_mesh),
				GEO_ANIMATED_PART(6, 1741, 232, 16974, wf_dl_MolePainting_006_mesh),
				GEO_ANIMATED_PART(6, 894, 232, 17822, wf_dl_MolePainting_008_mesh),
				GEO_ANIMATED_PART(6, 4186, 232, 16974, wf_dl_MolePainting_009_mesh),
				GEO_ANIMATED_PART(6, 3339, 232, 16127, wf_dl_MolePainting_010_mesh),
				GEO_ANIMATED_PART(6, 3339, 232, 17822, wf_dl_MolePainting_011_mesh),
				GEO_ANIMATED_PART(6, 4186, 232, 14529, wf_dl_MolePainting_012_mesh),
				GEO_ANIMATED_PART(6, 3339, 232, 13682, wf_dl_MolePainting_013_mesh),
				GEO_ANIMATED_PART(6, 3339, 232, 15377, wf_dl_MolePainting_014_mesh),
				GEO_ANIMATED_PART(6, 46, 232, 16974, wf_dl_MolePainting_015_mesh),
				GEO_ANIMATED_PART(6, 2491, 232, 14529, wf_dl_MolePainting_007_mesh),
				GEO_ANIMATED_PART(6, 4186, 232, 12084, wf_dl_MolePainting_016_mesh),
				GEO_ANIMATED_PART(6, 3339, 232, 11237, wf_dl_MolePainting_017_mesh),
				GEO_ANIMATED_PART(6, 3339, 232, 12932, wf_dl_MolePainting_018_mesh),
				GEO_ANIMATED_PART(6, 2491, 232, 12084, wf_dl_MolePainting_019_mesh),
				GEO_ANIMATED_PART(6, 1741, 232, 12084, wf_dl_MolePainting_020_mesh),
				GEO_ANIMATED_PART(6, 894, 232, 11237, wf_dl_MolePainting_021_mesh),
				GEO_ANIMATED_PART(6, 46, 232, 12084, wf_dl_MolePainting_022_mesh),
				GEO_ANIMATED_PART(6, -704, 200, 12084, wf_dl_MolePainting_023_mesh),
				GEO_ANIMATED_PART(6, -1551, 200, 11237, wf_dl_MolePainting_024_mesh),
				GEO_ANIMATED_PART(6, -2399, 200, 12084, wf_dl_MolePainting_025_mesh),
				GEO_ANIMATED_PART(6, -3149, 200, 12084, wf_dl_MolePainting_026_mesh),
				GEO_ANIMATED_PART(6, -3996, 200, 11237, wf_dl_MolePainting_027_mesh),
				GEO_ANIMATED_PART(6, -4844, 200, 12084, wf_dl_MolePainting_028_mesh),
				GEO_ANIMATED_PART(6, -3149, 200, 14529, wf_dl_MolePainting_029_mesh),
				GEO_ANIMATED_PART(6, -3996, 200, 13682, wf_dl_MolePainting_030_mesh),
				GEO_ANIMATED_PART(6, -4844, 200, 14529, wf_dl_MolePainting_031_mesh),
				GEO_ANIMATED_PART(6, -3149, 200, 16974, wf_dl_MolePainting_032_mesh),
				GEO_ANIMATED_PART(6, -3996, 200, 16127, wf_dl_MolePainting_033_mesh),
				GEO_ANIMATED_PART(6, -4844, 200, 16974, wf_dl_MolePainting_034_mesh),
				GEO_ANIMATED_PART(6, -704, 200, 16974, wf_dl_MolePainting_035_mesh),
				GEO_ANIMATED_PART(6, -1551, 200, 16127, wf_dl_MolePainting_036_mesh),
				GEO_ANIMATED_PART(6, -2399, 200, 16974, wf_dl_MolePainting_037_mesh),
				GEO_ANIMATED_PART(6, 4186, 232, 19419, wf_dl_MolePainting_038_mesh),
				GEO_ANIMATED_PART(6, 3339, 232, 18572, wf_dl_MolePainting_039_mesh),
				GEO_ANIMATED_PART(6, 2491, 232, 19419, wf_dl_MolePainting_040_mesh),
				GEO_ANIMATED_PART(6, 1741, 232, 19419, wf_dl_MolePainting_041_mesh),
				GEO_ANIMATED_PART(6, 894, 232, 18572, wf_dl_MolePainting_042_mesh),
				GEO_ANIMATED_PART(6, 46, 232, 19419, wf_dl_MolePainting_043_mesh),
				GEO_ANIMATED_PART(6, -704, 200, 19419, wf_dl_MolePainting_044_mesh),
				GEO_ANIMATED_PART(6, -1551, 200, 18572, wf_dl_MolePainting_045_mesh),
				GEO_ANIMATED_PART(6, -2399, 200, 19419, wf_dl_MolePainting_046_mesh),
				GEO_ANIMATED_PART(6, -3149, 200, 19419, wf_dl_MolePainting_047_mesh),
				GEO_ANIMATED_PART(6, -3996, 200, 18572, wf_dl_MolePainting_048_mesh),
				GEO_ANIMATED_PART(6, -4844, 200, 19419, wf_dl_MolePainting_049_mesh),
				GEO_ANIMATED_PART(6, 6631, 232, 16974, wf_dl_MolePainting_050_mesh),
				GEO_ANIMATED_PART(6, 5784, 232, 16127, wf_dl_MolePainting_051_mesh),
				GEO_ANIMATED_PART(6, 5784, 232, 17822, wf_dl_MolePainting_052_mesh),
				GEO_ANIMATED_PART(6, 4936, 232, 16974, wf_dl_MolePainting_053_mesh),
				GEO_ANIMATED_PART(1, -1552, 327, 14529, wf_dl_Walls_Collision_001_mesh),
				GEO_ANIMATED_PART(1, 893, 329, 14529, wf_dl_Walls_Collision_002_mesh),
				GEO_ANIMATED_PART(1, 3338, 329, 14529, wf_dl_Walls_Collision_003_mesh),
				GEO_ANIMATED_PART(1, 3338, 329, 16974, wf_dl_Walls_Collision_004_mesh),
				GEO_ANIMATED_PART(1, 893, 329, 16974, wf_dl_Walls_Collision_005_mesh),
				GEO_ANIMATED_PART(1, 3338, 329, 12084, wf_dl_Walls_Collision_006_mesh),
				GEO_ANIMATED_PART(1, 893, 329, 12084, wf_dl_Walls_Collision_007_mesh),
				GEO_ANIMATED_PART(1, -1552, 296, 12084, wf_dl_Walls_Collision_008_mesh),
				GEO_ANIMATED_PART(1, -3997, 296, 12084, wf_dl_Walls_Collision_009_mesh),
				GEO_ANIMATED_PART(1, -3997, 296, 14529, wf_dl_Walls_Collision_010_mesh),
				GEO_ANIMATED_PART(1, -3997, 296, 16974, wf_dl_Walls_Collision_011_mesh),
				GEO_ANIMATED_PART(1, -1552, 296, 16974, wf_dl_Walls_Collision_012_mesh),
				GEO_ANIMATED_PART(1, 3338, 329, 19419, wf_dl_Walls_Collision_013_mesh),
				GEO_ANIMATED_PART(1, 893, 329, 19419, wf_dl_Walls_Collision_014_mesh),
				GEO_ANIMATED_PART(1, -1552, 296, 19419, wf_dl_Walls_Collision_015_mesh),
				GEO_ANIMATED_PART(1, -3997, 296, 19419, wf_dl_Walls_Collision_016_mesh),
				GEO_ANIMATED_PART(1, 5783, 329, 16974, wf_dl_Walls_Collision_017_mesh),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout wf_area_3[] = {
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
					GEO_BRANCH(1, wf_area_3_geo),
					GEO_RENDER_OBJ(),
					GEO_ASM(ENVFX_MODE_NONE, geo_enfvx_main),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(0, wf_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(1, wf_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(2, wf_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(3, wf_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(4, wf_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(5, wf_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(6, wf_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(7, wf_dl_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};