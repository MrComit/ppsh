const GeoLayout floating_rock_geo[] = {
	GEO_CULLING_RADIUS(0x800),
	GEO_OPEN_NODE(),
		GEO_ANIMATED_PART(1, 0, 0, 0, floating_rock_Pillar2_005_mesh),
		GEO_DISPLAY_LIST(0, floating_rock_material_revert_render_settings),
		GEO_DISPLAY_LIST(1, floating_rock_material_revert_render_settings),
		GEO_DISPLAY_LIST(2, floating_rock_material_revert_render_settings),
		GEO_DISPLAY_LIST(3, floating_rock_material_revert_render_settings),
		GEO_DISPLAY_LIST(4, floating_rock_material_revert_render_settings),
		GEO_DISPLAY_LIST(5, floating_rock_material_revert_render_settings),
		GEO_DISPLAY_LIST(6, floating_rock_material_revert_render_settings),
		GEO_DISPLAY_LIST(7, floating_rock_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};