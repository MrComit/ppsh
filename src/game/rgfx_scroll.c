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

static void shift_st(Gfx *dl, u32 cmd, u16 s, u16 t) {
    SetTileSize *tile = segmented_to_virtual(dl);
    tile += cmd;
    tile->s += s;
    tile->u += s;
    tile->t += t;
    tile->v += t;
}


u16 sTimers[2] = {0, 0};

static void shift_uv(Vtx *vert, u16 vertcount, s16 speed, s8 u, s8 v, u16 timer) {
    u32 i;
    Vtx *verts = segmented_to_virtual(vert);
    for (i = 0; i < vertcount; i++) {
        if (u)
            verts[i].n.tc[0] += speed;
        if (v)
            verts[i].n.tc[1] += speed;
    }

    if (sTimers[timer] * absi(speed) > 4096) {
        for (i = 0; i < vertcount; i++) {
            if (u)
                verts[i].n.tc[0] -= 4096 * signum_positive(speed);
            if (v)
                verts[i].n.tc[1] -= 4096 * signum_positive(speed);
        }
        sTimers[timer] = 0;
    }
    sTimers[timer]++;
}

/**
 * Main scrolling texture function. Call this every frame.
 * Add an entry to the switch (and make sure it's appropiate for the area you want it
 * to be active in, using another switch).
 */


extern bob_a1_Sandfloor_001_mesh_vtx;
extern bob_A3_Water_mesh_vtx;

void rgfx_update_scroll() {
    switch(gCurrLevelNum) {
        case LEVEL_BOB:
            switch(gCurrAreaIndex) {
                case 1:
                    //shift_st(&mat_bob_sm64_material_water, 19, 1, 1);
                    shift_uv(&bob_a1_Sandfloor_001_mesh_vtx, 4, 5, TRUE, FALSE, 0);
                    break;
                case 3:
                    shift_uv(&bob_A3_Water_mesh_vtx, 8, -5, FALSE, TRUE, 1);
                    break;
        }
        break;
    }
}
