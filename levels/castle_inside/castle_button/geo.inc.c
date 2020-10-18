#include "src/game/envfx_snow.h"

const GeoLayout castle_button_Bone_opt0_Switch_opt1[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, castle_button_Switch_Option_DL1_mesh),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout castle_button_Bone_opt0_Switch_opt2[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE_DECAL, castle_button_Switch_Option_DL1_mesh),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout castle_button_B1_001[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_SWITCH_CASE(2, geo_switch_anim_state),
		GEO_OPEN_NODE(),
			GEO_NODE_START(),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_OPAQUE, castle_button_Switch_Option_DL1_mesh),
			GEO_CLOSE_NODE(),
			GEO_BRANCH(1, castle_button_Bone_opt0_Switch_opt1),
			GEO_BRANCH(1, castle_button_Bone_opt0_Switch_opt2),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout castle_button_Bone_opt1_Bone_opt1[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, castle_button_Option_DL2_mesh),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout castle_button_Bone_opt1_Bone_opt2[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE_DECAL, castle_button_Option_DL2_mesh),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout castle_button_B2_001[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_SWITCH_CASE(2, geo_switch_anim_state),
		GEO_OPEN_NODE(),
			GEO_NODE_START(),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_OPAQUE, castle_button_Option_DL2_mesh),
			GEO_CLOSE_NODE(),
			GEO_BRANCH(1, castle_button_Bone_opt1_Bone_opt1),
			GEO_BRANCH(1, castle_button_Bone_opt1_Bone_opt2),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout castle_button_Bone_opt2_Bone_opt1[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, castle_button_Option_DL3_mesh),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout castle_button_Bone_opt2_Bone_opt2[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE_DECAL, castle_button_Option_DL3_mesh),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout castle_button_B3_001[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_SWITCH_CASE(2, geo_switch_anim_state),
		GEO_OPEN_NODE(),
			GEO_NODE_START(),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_OPAQUE, castle_button_Option_DL3_mesh),
			GEO_CLOSE_NODE(),
			GEO_BRANCH(1, castle_button_Bone_opt2_Bone_opt1),
			GEO_BRANCH(1, castle_button_Bone_opt2_Bone_opt2),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout castle_button_Bone_opt3_Bone_opt1[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, castle_button_Option_DL4_mesh),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout castle_button_Bone_opt3_Bone_opt2[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE_DECAL, castle_button_Option_DL4_mesh),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout castle_button_B4_002[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_SWITCH_CASE(2, geo_switch_anim_state),
		GEO_OPEN_NODE(),
			GEO_NODE_START(),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_OPAQUE, castle_button_Option_DL4_mesh),
			GEO_CLOSE_NODE(),
			GEO_BRANCH(1, castle_button_Bone_opt3_Bone_opt1),
			GEO_BRANCH(1, castle_button_Bone_opt3_Bone_opt2),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout castle_button_geo[] = {
	GEO_CULLING_RADIUS(0x2000),
	GEO_OPEN_NODE(),
		GEO_SWITCH_CASE(4, geo_switch_param_two),
		GEO_OPEN_NODE(),
			GEO_BRANCH(1, castle_button_B1_001),
			GEO_BRANCH(1, castle_button_B2_001),
			GEO_BRANCH(1, castle_button_B3_001),
			GEO_BRANCH(1, castle_button_B4_002),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, castle_button_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_OPAQUE_DECAL, castle_button_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
