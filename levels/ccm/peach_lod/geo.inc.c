#include "src/game/envfx_snow.h"

const GeoLayout peach_lod_geo_opaque[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, peach_lod_skinned_mesh),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};


const GeoLayout peach_lod_geo_trans[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, peach_lod_skinned_mesh),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};



const GeoLayout peach_lod_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_SCALE(0x00, 16384),
		GEO_OPEN_NODE(),
			GEO_ASM(10, Geo18_8029D924),
			GEO_SWITCH_CASE(2, geo_switch_anim_state),
			GEO_OPEN_NODE(),
                GEO_BRANCH(1, peach_lod_geo_opaque),
               	GEO_BRANCH(1, peach_lod_geo_trans),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, simp_toad_lod_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, simp_toad_lod_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};