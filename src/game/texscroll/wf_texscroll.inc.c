#include "levels/wf/header.h"
#include "levels/wf/texscroll.inc.c"
#include "levels/wf/quicksand_platforming/texscroll.inc.c"
#include "levels/wf/floating_rock/texscroll.inc.c"
#include "levels/wf/rock_door/texscroll.inc.c"
void scroll_textures_wf() {
	scroll_wf();

	scroll_wf_level_geo_quicksand_platforming();

	scroll_wf_level_geo_floating_rock();

	scroll_wf_level_geo_rock_door();

}
