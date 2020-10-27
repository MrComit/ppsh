#include "levels/ccm/header.h"
#include "levels/ccm/texscroll.inc.c"
#include "levels/ccm/boss_gate/texscroll.inc.c"
#include "levels/ccm/simp_toad_lod/texscroll.inc.c"
#include "levels/ccm/peach_lod/texscroll.inc.c"
void scroll_textures_ccm() {
	scroll_ccm();

	scroll_ccm_level_geo_boss_gate();

	scroll_ccm_level_geo_simp_toad_lod();

	scroll_ccm_level_geo_peach_lod();

}
