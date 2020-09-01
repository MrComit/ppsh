#include "src/game/envfx_snow.h"

const GeoLayout small_switch_geo[] = {
	GEO_CULLING_RADIUS(0x1000),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, small_switch_SolidDL_mesh),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, small_switch_TransDL_mesh),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, small_switch_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, small_switch_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
