#include "src/game/envfx_snow.h"

const GeoLayout pillar_switch_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, pillar_switch_Switch_001_mesh),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, pillar_switch_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
