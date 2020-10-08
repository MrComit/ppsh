#include "src/game/envfx_snow.h"

const GeoLayout simp_door_geo[] = {
	GEO_CULLING_RADIUS(0x1000),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, simp_door_Cube_027_mesh),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, simp_door_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
