#include <ultra64.h>
#include "game/level_update.h"
#include "game/area.h"
#include "game/memory.h"
#include "game/display.h"
#include "levels/bob/header.h"
#include "game/camera.h"

#define PACK_TILESIZE(w, d) ((w << 2) + d)

typedef struct {
    int cmd:8;
    int s:12;
    int t:12;
    int pad:4;
    int i:4;
    int u:12;
    int v:12;
} SetTileSize;

//extern Gfx bob_seg7_dl_07004390;

/*
 * Scrolling texture system by red.
 * This file comes with Bob-Omb Battlefield as an example.
 */

/*
 * Parameters:
 * dl - Which display list to modify (make sure it's passed by reference).
 *
 * cmd - Location of the gsDPSetTileSize command in the display list.
 * In Bob-Omb Battlefield, it is 12.
 *
 * s/t - How much to scroll.
 */

static void shift_s(Gfx *dl, u32 cmd, u16 s) {
    SetTileSize *tile = segmented_to_virtual(dl);
    tile += cmd;
    tile->s += s;
    tile->u += s;
}

static void shift_t(Gfx *dl, u32 cmd, u16 t) {
    SetTileSize *tile = segmented_to_virtual(dl);
    tile += cmd;
    tile->t += t;
    tile->v += t;
}

/**
 * Main scrolling texture function. Call this every frame.
 * Add an entry to the switch (and make sure it's appropiate for the area you want it
 * to be active in, using another switch).
 */

void rgfx_update_scroll() {
    switch(gCurrLevelNum) {
        case LEVEL_BOB:
            switch(gCurrAreaIndex) {
                case 1:
                    shift_s(&mat_bob_sm64_material_water, 19, 1);
                    shift_t(&mat_bob_sm64_material_water, 19, 1);
                    break;
                case 3:
                    shift_s(&mat_bob_sm64_material_water, 19, 0);
                    shift_t(&mat_bob_sm64_material_water, 19, -1);
                    break;
        }
        break;
    }
}
