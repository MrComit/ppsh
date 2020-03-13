const GeoLayout bob_area_2_Level[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ANIMATED_PART(1, 0, 0, 0, NULL),
		GEO_OPEN_NODE(),
			GEO_ANIMATED_PART(1, 0, 0, 0, NULL),
			GEO_OPEN_NODE(),
				GEO_ANIMATED_PART(1, -7828, -745, -11419, Chair_mesh),
				GEO_ANIMATED_PART(1, 716, -151, -6097, Chair_001_mesh),
				GEO_ANIMATED_PART(1, 6945, -643, -4728, Chair_002_mesh),
				GEO_ANIMATED_PART(1, 8485, -643, -7088, Chair_003_mesh),
				GEO_ANIMATED_PART(1, 10180, -643, -9208, Chair_004_mesh),
				GEO_ANIMATED_PART(1, -5930, -775, -13068, Clock_mesh),
				GEO_ANIMATED_PART(1, -7767, -607, -11514, Computer_mesh),
				GEO_ANIMATED_PART(1, 826, -13, -6123, Computer_001_mesh),
				GEO_ANIMATED_PART(1, 6988, -505, -4624, Computer_002_mesh),
				GEO_ANIMATED_PART(1, 8526, -505, -7193, Computer_003_mesh),
				GEO_ANIMATED_PART(1, 10190, -505, -9095, Computer_004_mesh),
				GEO_ANIMATED_PART(1, -5593, -599, -12290, Computer_005_mesh),
				GEO_ANIMATED_PART(1, -4628, -938, -11972, HouseInside1_mesh),
				GEO_ANIMATED_PART(1, -6690, -938, -12382, HouseInside2_mesh),
				GEO_ANIMATED_PART(1, -190, -673, -4654, HouseInside3_mesh),
				GEO_ANIMATED_PART(1, 9726, -673, -9891, HouseInside4_mesh),
				GEO_ANIMATED_PART(1, 7496, -673, -5510, HouseInside5_mesh),
				GEO_ANIMATED_PART(1, 6380, -673, -4193, HouseInside6_mesh),
				GEO_ANIMATED_PART(1, -7759, -745, -11527, Table_mesh),
				GEO_ANIMATED_PART(1, 840, -151, -6127, Table_001_mesh),
				GEO_ANIMATED_PART(1, 6994, -643, -4610, Table_002_mesh),
				GEO_ANIMATED_PART(1, 8531, -643, -7207, Table_003_mesh),
				GEO_ANIMATED_PART(1, 10191, -643, -9081, Table_004_mesh),
				GEO_ANIMATED_PART(1, -5558, -745, -12292, Table_005_mesh),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bob_area_2_level[] = {
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
					GEO_BRANCH(1, bob_area_2_Level),
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