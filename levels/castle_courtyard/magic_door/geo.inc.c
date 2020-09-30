#include "src/game/envfx_snow.h"
#include "src/game/segment2.h"

const GeoLayout magic_door_one[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ANIMATED_PART(LAYER_ALPHA, 0, -140, 20, dl_billboard_num_5),
		GEO_CLOSE_NODE(),
	GEO_RETURN(),
};

const GeoLayout magic_door_two[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ANIMATED_PART(LAYER_ALPHA, -30, -140, 20, dl_billboard_num_1),
		GEO_ANIMATED_PART(LAYER_ALPHA, 30, -140, 20, dl_billboard_num_2),
		GEO_CLOSE_NODE(),
	GEO_RETURN(),
};

const GeoLayout magic_door_three[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ANIMATED_PART(LAYER_ALPHA, -30, -140, 20, dl_billboard_num_2),
		GEO_ANIMATED_PART(LAYER_ALPHA, 30, -140, 20, dl_billboard_num_0),
		GEO_CLOSE_NODE(),
	GEO_RETURN(),
};


const GeoLayout magic_door_geo[] = {
	GEO_CULLING_RADIUS(0x1000),
	GEO_OPEN_NODE(),
		GEO_ASM(0, Geo18_8029D924),
		GEO_OPEN_NODE(),
			GEO_ANIMATED_PART(LAYER_TRANSPARENT_DECAL, 0, 0, 0, magic_door_Decal_mesh),
			GEO_ANIMATED_PART(LAYER_TRANSPARENT, 0, 0, 0, magic_door_Trans_mesh),
		GEO_CLOSE_NODE(),
		GEO_OPEN_NODE(),
			GEO_SWITCH_CASE(3, geo_switch_param_two),
			GEO_OPEN_NODE(),
				GEO_BRANCH(1, magic_door_one),
				GEO_BRANCH(1, magic_door_two),
				GEO_BRANCH(1, magic_door_three),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, magic_door_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, magic_door_material_revert_render_settings),
		GEO_CLOSE_NODE(),
	GEO_END(),
};
