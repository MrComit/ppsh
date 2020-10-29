#include "src/game/envfx_snow.h"

const GeoLayout sc_truck_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_CULLING_RADIUS(0x1000),
		GEO_OPEN_NODE(),
			GEO_ANIMATED_PART(4, 0, 0, 0, sc_truck_alphaDL_mesh),
			GEO_ANIMATED_PART(1, 0, 0, 0, sc_truck_solidDL_mesh),
		GEO_CLOSE_NODE(),
		//GEO_DISPLAY_LIST(0, sc_truck_material_revert_render_settings),
		GEO_DISPLAY_LIST(1, sc_truck_material_revert_render_settings),
		//GEO_DISPLAY_LIST(2, sc_truck_material_revert_render_settings),
		//GEO_DISPLAY_LIST(3, sc_truck_material_revert_render_settings),
		GEO_DISPLAY_LIST(4, sc_truck_material_revert_render_settings),
		//GEO_DISPLAY_LIST(5, sc_truck_material_revert_render_settings),
		//GEO_DISPLAY_LIST(6, sc_truck_material_revert_render_settings),
		//GEO_DISPLAY_LIST(7, sc_truck_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
