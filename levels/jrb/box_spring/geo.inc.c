#include "src/game/envfx_snow.h"

const GeoLayout box_spring_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_ALPHA, box_spring_CutoutDL_mesh),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, box_spring_CutoutDecalDL_mesh),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, box_spring_SolidDL_mesh),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, box_spring_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_ALPHA, box_spring_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, box_spring_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
