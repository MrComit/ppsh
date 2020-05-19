#include "src/game/envfx_snow.h"

const GeoLayout truck_high[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(1, cc_truck_001_3d_tires_mesh),
		GEO_DISPLAY_LIST(4, cc_truck_004_normal_tires_mesh),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};


const GeoLayout truck_low[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(4, cc_truck_004_budget_tires_mesh),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),	
};

const GeoLayout truck_console[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_RENDER_RANGE(-2048, 3000),
    	GEO_OPEN_NODE(),
			GEO_BRANCH(1, truck_high),
    	GEO_CLOSE_NODE(),
		GEO_RENDER_RANGE(3000, 32767),
    	GEO_OPEN_NODE(),
			GEO_BRANCH(1, truck_low),
    	GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};


const GeoLayout cc_truck_geo[] = {
	GEO_CULLING_RADIUS(3072),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(1, cc_truck_001_truck_mesh),
			GEO_SWITCH_CASE(2, geo_switch_console_mode),
            GEO_OPEN_NODE(),
               GEO_BRANCH(1, truck_high),
               GEO_BRANCH(1, truck_console),
            GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(0, cc_truck_material_revert_render_settings),
		GEO_DISPLAY_LIST(1, cc_truck_material_revert_render_settings),
		GEO_DISPLAY_LIST(2, cc_truck_material_revert_render_settings),
		GEO_DISPLAY_LIST(3, cc_truck_material_revert_render_settings),
		GEO_DISPLAY_LIST(4, cc_truck_material_revert_render_settings),
		GEO_DISPLAY_LIST(5, cc_truck_material_revert_render_settings),
		GEO_DISPLAY_LIST(6, cc_truck_material_revert_render_settings),
		GEO_DISPLAY_LIST(7, cc_truck_material_revert_render_settings),
	GEO_END(),
};
