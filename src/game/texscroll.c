#include "types.h"
#include "include/segment_symbols.h"
#include "memory.h"
#include "engine/math_util.h"
#include "src/engine/behavior_script.h"
#include "texscroll.h"


#include "src/game/texscroll/wf_texscroll.inc.c"
void scroll_textures() {
	if(sSegmentROMTable[0x7] == (uintptr_t)_wf_segment_7SegmentRomStart) {
		scroll_textures_wf();
	}

}
