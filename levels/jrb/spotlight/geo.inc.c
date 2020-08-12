#include "src/game/envfx_snow.h"

const GeoLayout spotlight_geo[] = {
	GEO_CULLING_RADIUS(0x2000),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_ROTATE_WITH_DL(5, 0, 0, 0, 0, 0, 0, spotlight_Spotlight_mesh),
		GEO_DISPLAY_LIST(5, spotlight_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
