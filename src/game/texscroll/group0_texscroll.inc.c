#include "actors/group0.h"
#include "actors/subway_k/texscroll.inc.c"
#include "actors/hint_toad/texscroll.inc.c"
#include "actors/mario_lowpoly/texscroll.inc.c"
#include "actors/mario/texscroll.inc.c"
#include "actors/arrow_head/texscroll.inc.c"
void scroll_textures_group0() {
	scroll_actor_geo_subway_k();

	scroll_actor_geo_hint_toad();

	scroll_actor_geo_mario_lowpoly();

	scroll_actor_geo_mario();

	scroll_actor_geo_arrow_head();

}
