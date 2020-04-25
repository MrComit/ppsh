const GeoLayout canyon_button_geo[] = {
	GEO_CULLING_RADIUS(0x800),
		GEO_OPEN_NODE(),
		    GEO_SWITCH_CASE(2, geo_switch_anim_state),
            GEO_OPEN_NODE(),
               GEO_BRANCH(1, grey_canyon_button_geo),
               GEO_BRANCH(1, blue_canyon_button_geo),
            GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(0, canyon_button_material_revert_render_settings),
		GEO_DISPLAY_LIST(1, canyon_button_material_revert_render_settings),
		GEO_DISPLAY_LIST(2, canyon_button_material_revert_render_settings),
		GEO_DISPLAY_LIST(3, canyon_button_material_revert_render_settings),
		GEO_DISPLAY_LIST(4, canyon_button_material_revert_render_settings),
		GEO_DISPLAY_LIST(5, canyon_button_material_revert_render_settings),
		GEO_DISPLAY_LIST(6, canyon_button_material_revert_render_settings),
		GEO_DISPLAY_LIST(7, canyon_button_material_revert_render_settings),
	GEO_END(),
};


const GeoLayout grey_canyon_button_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(1, canyon_button_layer1button_mesh),
		GEO_DISPLAY_LIST(2, canyon_button_layer2button_mesh),
		GEO_CLOSE_NODE(),
	GEO_RETURN(),
};

const GeoLayout blue_canyon_button_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(1, canyon_button_layer1button_mesh_2),
		GEO_DISPLAY_LIST(2, canyon_button_layer2button_mesh_2),
		GEO_CLOSE_NODE(),
	GEO_RETURN(),
};