#include "src/game/envfx_snow.h"

const GeoLayout sc_mine_geo[] = {
	GEO_CULLING_RADIUS(0x800),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_ROTATE_WITH_DL(1, 0, 0, 0, 0, 0, 0, sc_mine_Mine_mesh),
		GEO_DISPLAY_LIST(0, sc_mine_material_revert_render_settings),
		GEO_DISPLAY_LIST(1, sc_mine_material_revert_render_settings),
		GEO_DISPLAY_LIST(2, sc_mine_material_revert_render_settings),
		GEO_DISPLAY_LIST(3, sc_mine_material_revert_render_settings),
		GEO_DISPLAY_LIST(4, sc_mine_material_revert_render_settings),
		GEO_DISPLAY_LIST(5, sc_mine_material_revert_render_settings),
		GEO_DISPLAY_LIST(6, sc_mine_material_revert_render_settings),
		GEO_DISPLAY_LIST(7, sc_mine_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
