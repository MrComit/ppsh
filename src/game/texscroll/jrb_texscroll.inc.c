#include "levels/jrb/header.h"
#include "levels/jrb/texscroll.inc.c"
#include "levels/jrb/colored_cube/texscroll.inc.c"
#include "levels/jrb/sc_gate1/texscroll.inc.c"
#include "levels/jrb/sc_truck/texscroll.inc.c"
#include "levels/jrb/sc_big_truck/texscroll.inc.c"
#include "levels/jrb/sc_mine/texscroll.inc.c"
#include "levels/jrb/SC_Elevator/texscroll.inc.c"
#include "levels/jrb/spotlight/texscroll.inc.c"
#include "levels/jrb/box_spring/texscroll.inc.c"
#include "levels/jrb/small_switch/texscroll.inc.c"
void scroll_textures_jrb() {
	scroll_jrb();

	scroll_jrb_level_geo_colored_cube();

	scroll_jrb_level_geo_sc_gate1();

	scroll_jrb_level_geo_sc_truck();

	scroll_jrb_level_geo_sc_big_truck();

	scroll_jrb_level_geo_sc_mine();

	scroll_jrb_level_geo_SC_Elevator();

	scroll_jrb_level_geo_spotlight();

	scroll_jrb_level_geo_box_spring();

	scroll_jrb_level_geo_small_switch();

}
