#include "levels/wf/header.h"
#include "levels/wf/texscroll.inc.c"
#include "levels/wf/quicksand_platforming/texscroll.inc.c"
#include "levels/wf/floating_rock/texscroll.inc.c"
#include "levels/wf/rock_door/texscroll.inc.c"
#include "levels/wf/horizontal_rock/texscroll.inc.c"
#include "levels/wf/BombSwitch/texscroll.inc.c"
#include "levels/wf/bomb_boulder/texscroll.inc.c"
#include "levels/wf/cc_truck/texscroll.inc.c"
void scroll_textures_wf() {
	scroll_wf();

	scroll_wf_level_geo_quicksand_platforming();

	scroll_wf_level_geo_floating_rock();

	scroll_wf_level_geo_rock_door();

	scroll_wf_level_geo_horizontal_rock();

	scroll_wf_level_geo_BombSwitch();

	scroll_wf_level_geo_bomb_boulder();

	scroll_wf_level_geo_cc_truck();

}
