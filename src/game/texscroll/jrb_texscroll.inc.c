#include "levels/jrb/header.h"
#include "levels/jrb/texscroll.inc.c"
#include "levels/jrb/colored_cube/texscroll.inc.c"
#include "levels/jrb/sc_gate1/texscroll.inc.c"
#include "levels/jrb/sc_truck/texscroll.inc.c"
#include "levels/jrb/sc_big_truck/texscroll.inc.c"
#include "levels/jrb/sc_mine/texscroll.inc.c"
void scroll_textures_jrb() {
	scroll_jrb();

	scroll_jrb_level_geo_colored_cube();

	scroll_jrb_level_geo_sc_gate1();

	scroll_jrb_level_geo_sc_truck();

	scroll_jrb_level_geo_sc_big_truck();

	scroll_jrb_level_geo_sc_mine();

}
