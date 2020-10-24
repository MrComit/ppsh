#include "levels/bob/header.h"
#include "levels/bob/texscroll.inc.c"
#include "levels/bob/pillar_switch/texscroll.inc.c"
#include "levels/bob/bridge/texscroll.inc.c"
#include "levels/bob/palmtree/texscroll.inc.c"
void scroll_textures_bob() {
	scroll_bob();

	scroll_bob_level_geo_pillar_switch();

	scroll_bob_level_geo_bridge();

	scroll_bob_level_geo_palmtree();

}
