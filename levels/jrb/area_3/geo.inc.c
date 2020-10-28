#include "src/game/envfx_snow.h"

const GeoLayout jrb_area_3_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_SWITCH_CASE(2, geo_switch_area),
		GEO_OPEN_NODE(),
			GEO_BRANCH(1, jrb_dl_Room1C_geo),
			GEO_BRANCH(1, jrb_dl_Room2C_geo),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout jrb_dl_Room1C_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -585, 4719, 15995, jrb_dl_MetalSlide_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -18447, -10678, 23443, jrb_dl_MetalSlide_001_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT, -576, -363, 27114, jrb_dl_X_mesh),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout jrb_dl_Room2C_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, -15000, 0, jrb_dl_DeathPlane_001_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -13647, -5856, -17237, jrb_dl_MetalSlide_002_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT_DECAL, -13647, -5856, -17237, jrb_dl_MetalSlide_004_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT_DECAL, -15868, -4725, -16908, jrb_dl_TraffLight_001_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT_DECAL, -10577, -4725, -16912, jrb_dl_TraffLight_002_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -20191, -4915, -18064, jrb_dl_TraffPost_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -15848, -4915, -17109, jrb_dl_TraffPost_001_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -10556, -4915, -17112, jrb_dl_TraffPost_002_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_ALPHA, -24897, -5848, -17237, jrb_dl_Truck_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT_DECAL, -20211, -4725, -17864, jrb_dl_red_mesh),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout jrb_area_3[] = {
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
					GEO_BRANCH(1, jrb_area_3_geo),
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
