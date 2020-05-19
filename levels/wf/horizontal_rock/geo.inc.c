#include "src/game/envfx_snow.h"

const GeoLayout horizontal_rock_geo[] = {
	GEO_CULLING_RADIUS(0x800),
	GEO_OPEN_NODE(),
		GEO_ANIMATED_PART(1, 0, 0, 0, horizontal_rock_Horizontal_Rock_mesh),
		GEO_DISPLAY_LIST(0, horizontal_rock_material_revert_render_settings),
		GEO_DISPLAY_LIST(1, horizontal_rock_material_revert_render_settings),
		GEO_DISPLAY_LIST(2, horizontal_rock_material_revert_render_settings),
		GEO_DISPLAY_LIST(3, horizontal_rock_material_revert_render_settings),
		GEO_DISPLAY_LIST(4, horizontal_rock_material_revert_render_settings),
		GEO_DISPLAY_LIST(5, horizontal_rock_material_revert_render_settings),
		GEO_DISPLAY_LIST(6, horizontal_rock_material_revert_render_settings),
		GEO_DISPLAY_LIST(7, horizontal_rock_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
