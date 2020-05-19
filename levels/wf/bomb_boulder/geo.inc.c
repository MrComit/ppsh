#include "src/game/envfx_snow.h"

const GeoLayout bomb_boulder_geo[] = {
	GEO_CULLING_RADIUS(0x800),
	GEO_OPEN_NODE(),
		GEO_ANIMATED_PART(1, 0, 0, 0, bomb_boulder_Boulder_mesh),
		GEO_DISPLAY_LIST(0, bomb_boulder_material_revert_render_settings),
		GEO_DISPLAY_LIST(1, bomb_boulder_material_revert_render_settings),
		GEO_DISPLAY_LIST(2, bomb_boulder_material_revert_render_settings),
		GEO_DISPLAY_LIST(3, bomb_boulder_material_revert_render_settings),
		GEO_DISPLAY_LIST(4, bomb_boulder_material_revert_render_settings),
		GEO_DISPLAY_LIST(5, bomb_boulder_material_revert_render_settings),
		GEO_DISPLAY_LIST(6, bomb_boulder_material_revert_render_settings),
		GEO_DISPLAY_LIST(7, bomb_boulder_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
