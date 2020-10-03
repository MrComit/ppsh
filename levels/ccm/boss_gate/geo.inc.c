#include "src/game/envfx_snow.h"

const GeoLayout boss_gate_geo[] = {
	GEO_CULLING_RADIUS(0x800),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_ALPHA, boss_gate_Bar_mesh),
		GEO_DISPLAY_LIST(LAYER_ALPHA, boss_gate_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
