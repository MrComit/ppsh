#include "src/game/envfx_snow.h"

const GeoLayout palmtree_PalmTreeLOD[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_RENDER_RANGE(-4096, 5500),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, palmtree_000_DL_Base_mesh),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, palmtree_000_DL_Leaves_mesh),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, palmtree_000_DL_Shadow_mesh),
		GEO_CLOSE_NODE(),
        GEO_RENDER_RANGE(5500, 32767),
           GEO_OPEN_NODE(),
              GEO_DISPLAY_LIST(LAYER_OPAQUE, palmtree_renderarea_000_DL_Base_mesh),
           GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};

const GeoLayout palmtree_PalmTreeNoLOD[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, palmtree_000_DL_Base_mesh),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, palmtree_000_DL_Leaves_mesh),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, palmtree_000_DL_Shadow_mesh),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};



const GeoLayout palmtree_geo[] = {
	GEO_CULLING_RADIUS(0x800),
	GEO_OPEN_NODE(),
		GEO_SWITCH_CASE(2, geo_switch_console_mode),
		GEO_OPEN_NODE(),
			GEO_BRANCH(1, palmtree_PalmTreeNoLOD),
			GEO_BRANCH(1, palmtree_PalmTreeLOD),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, palmtree_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, palmtree_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};