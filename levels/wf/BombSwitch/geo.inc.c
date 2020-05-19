#include "src/game/envfx_snow.h"

const GeoLayout BombSwitch_geo[] = {
	GEO_CULLING_RADIUS(0x800),
	GEO_OPEN_NODE(),
		GEO_ANIMATED_PART(1, 0, 0, 0, BombSwitch_Bomb_Switch_mesh),
		GEO_DISPLAY_LIST(0, BombSwitch_material_revert_render_settings),
		GEO_DISPLAY_LIST(1, BombSwitch_material_revert_render_settings),
		GEO_DISPLAY_LIST(2, BombSwitch_material_revert_render_settings),
		GEO_DISPLAY_LIST(3, BombSwitch_material_revert_render_settings),
		GEO_DISPLAY_LIST(4, BombSwitch_material_revert_render_settings),
		GEO_DISPLAY_LIST(5, BombSwitch_material_revert_render_settings),
		GEO_DISPLAY_LIST(6, BombSwitch_material_revert_render_settings),
		GEO_DISPLAY_LIST(7, BombSwitch_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
