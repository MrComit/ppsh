#include "src/game/envfx_snow.h"

const GeoLayout SC_Elevator_geo[] = {
	GEO_CULLING_RADIUS(0x800),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_ROTATE_WITH_DL(1, 0, 0, 0, 0, 0, 0, SC_Elevator_SC_Elevator_mesh),
		GEO_DISPLAY_LIST(1, SC_Elevator_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
