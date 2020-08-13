#include "src/game/envfx_snow.h"

const GeoLayout jrb_area_5_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, -8000, 0, jrb_dl_Bounds_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -19094, -4804, 12377, jrb_dl_Ground_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -6260, -4804, 7832, jrb_dl_Ground_001_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_ALPHA, -21706, -2086, 15684, jrb_dl_Hangable_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -9035, -3131, 8220, jrb_dl_RockPlats_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 3309, -3131, 1004, jrb_dl_RockPlats_001_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -14353, 1117, 15202, jrb_dl_maro_mesh),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout jrb_area_5[] = {
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
					GEO_BRANCH(1, jrb_area_5_geo),
					GEO_RENDER_OBJ(),
					GEO_ASM(ENVFX_MODE_NONE, geo_enfvx_main),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, jrb_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_ALPHA, jrb_dl_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
