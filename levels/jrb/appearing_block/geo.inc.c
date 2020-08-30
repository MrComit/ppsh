#include "src/game/envfx_snow.h"

const GeoLayout appearing_block_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, appearing_block_MaroonBlock_mesh),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, appearing_block_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
