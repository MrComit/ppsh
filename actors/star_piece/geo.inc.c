const GeoLayout star_piece_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ANIMATED_PART(1, 0, 0, 0, Cube_mesh),
		GEO_DISPLAY_LIST(0, material_revert_render_settings),
		GEO_DISPLAY_LIST(1, material_revert_render_settings),
		GEO_DISPLAY_LIST(2, material_revert_render_settings),
		GEO_DISPLAY_LIST(3, material_revert_render_settings),
		GEO_DISPLAY_LIST(4, material_revert_render_settings),
		GEO_DISPLAY_LIST(5, material_revert_render_settings),
		GEO_DISPLAY_LIST(6, material_revert_render_settings),
		GEO_DISPLAY_LIST(7, material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
