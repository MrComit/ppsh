#include "src/game/envfx_snow.h"

const GeoLayout colored_cube_geo[] = {
	GEO_CULLING_RADIUS(0x800),
	GEO_OPEN_NODE(),
		GEO_SWITCH_CASE(4, geo_switch_anim_state),
		GEO_OPEN_NODE(),
			GEO_ANIMATED_PART(1, 0, 0, 0, red_colored_cube_colored_cube_mesh),
			GEO_ANIMATED_PART(1, 0, 0, 0, blue_colored_cube_colored_cube_mesh),
			GEO_ANIMATED_PART(1, 0, 0, 0, teal_colored_cube_colored_cube_mesh),
			GEO_ANIMATED_PART(1, 0, 0, 0, green_colored_cube_colored_cube_mesh),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(0, colored_cube_material_revert_render_settings),
		GEO_DISPLAY_LIST(1, colored_cube_material_revert_render_settings),
		GEO_DISPLAY_LIST(2, colored_cube_material_revert_render_settings),
		GEO_DISPLAY_LIST(3, colored_cube_material_revert_render_settings),
		GEO_DISPLAY_LIST(4, colored_cube_material_revert_render_settings),
		GEO_DISPLAY_LIST(5, colored_cube_material_revert_render_settings),
		GEO_DISPLAY_LIST(6, colored_cube_material_revert_render_settings),
		GEO_DISPLAY_LIST(7, colored_cube_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
