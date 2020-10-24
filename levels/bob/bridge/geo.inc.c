#include "src/game/envfx_snow.h"

/*const GeoLayout bridge_BridgeUp[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bridge_switchoption_BridgeUp_mesh),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};*/
const GeoLayout bridge_geo[] = {
	GEO_CULLING_RADIUS(0x2800),
	GEO_OPEN_NODE(),
		GEO_SWITCH_CASE(2, geo_switch_anim_state),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, bridge_BridgeDown_mesh),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, bridge_switchoption_BridgeUp_mesh),
			//GEO_BRANCH(1, bridge_BridgeUp),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bridge_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
