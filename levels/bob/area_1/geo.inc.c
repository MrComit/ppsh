const GeoLayout bob_area_1_Level[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ANIMATED_PART(1, 0, 0, 0, NULL),
		GEO_OPEN_NODE(),
			GEO_ANIMATED_PART(1, 0, 0, 0, NULL),
			GEO_OPEN_NODE(),
				GEO_ANIMATED_PART(1, 0, -1834, 0, Sandfloor_mesh),
				GEO_ANIMATED_PART(5, 0, -824, 0, Sandfloor_001_mesh),
				GEO_ANIMATED_PART(1, -2119, -1834, -2247, Start_Island_mesh),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bob_area_1_level[] = {
	GEO_NODE_SCREEN_AREA(10, SCREEN_WIDTH/2, SCREEN_HEIGHT/2, SCREEN_WIDTH/2, SCREEN_HEIGHT/2),
	GEO_OPEN_NODE(),
		GEO_ZBUFFER(0),
		GEO_OPEN_NODE(),
			GEO_NODE_ORTHO(100.0000),
			GEO_OPEN_NODE(),
				GEO_BACKGROUND(BACKGROUND_OCEAN_SKY, geo_skybox_main),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_ZBUFFER(1),
		GEO_OPEN_NODE(),
			GEO_CAMERA_FRUSTUM_WITH_FUNC(45.0000, 100, 30000, geo_camera_fov),
			GEO_OPEN_NODE(),
				GEO_CAMERA(1, 0, 0, 0, 0, -500, 0, geo_camera_main),
				GEO_OPEN_NODE(),
					GEO_BRANCH(1, bob_area_1_Level),
					GEO_RENDER_OBJ(),
					GEO_ASM(0, geo_enfvx_main),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
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
