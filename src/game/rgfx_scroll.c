#include <ultra64.h>
#include "game/level_update.h"
#include "game/area.h"
#include "game/memory.h"
#include "game/display.h"
#include "levels/bob/header.h"
#include "game/camera.h"
#include "engine/math_util.h"

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


#define SCROLL_UV 0
#define SCROLL_X 1
#define SCROLL_Y 2
#define SCROLL_Z 3
#define SCROLL_UV_SINE 4
#define SCROLL_X_SINE 5
#define SCROLL_Y_SINE 6
#define SCROLL_Z_SINE 7



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

static void shift_u(Vtx *vert, u16 vertcount, s16 speed) {
    u32 i;
    Vtx *verts = segmented_to_virtual(vert);
    for (i = 0; i < vertcount; i++) {
        verts[i].n.tc[0] += speed;
    }

    if (verts[0].n.flag * absi(speed) > 4096) {
        for (i = 0; i < vertcount; i++) {
            verts[i].n.tc[0] -= 4096 * signum_positive(speed);
        }
        verts[0].n.flag = 0;
    }
    verts[0].n.flag++;
}

static void shift_v(Vtx *vert, u16 vertcount, s16 speed) {
    u32 i;
    Vtx *verts = segmented_to_virtual(vert);
    for (i = 0; i < vertcount; i++) {
        verts[i].n.tc[1] += speed;
    }

    if (verts[1].n.flag * absi(speed) > 4096) {
        for (i = 0; i < vertcount; i++) {
            verts[i].n.tc[1] -= 4096 * signum_positive(speed);
        }
        verts[1].n.flag = 0;
    }
    verts[1].n.flag++;
}

static void shift_u_sine(Vtx *vert, u16 vertcount, s16 speed) {
    u32 i;
    Vtx *verts = segmented_to_virtual(vert);
    for (i = 0; i < vertcount; i++) {
        verts[i].n.tc[0] += sins(verts[0].n.flag) * speed;
    }
    verts[0].n.flag += speed * 0x20;
}

static void shift_v_sine(Vtx *vert, u16 vertcount, s16 speed) {
    u32 i;
    Vtx *verts = segmented_to_virtual(vert);
    for (i = 0; i < vertcount; i++) {
        verts[i].n.tc[1] += coss(verts[1].n.flag) * speed;
    }
    verts[1].n.flag += speed * 0x20;
}

static void shift_xyz(Vtx *vert, u16 vertcount, s16 speed, s16 cycle, u8 xyz) {
    u32 i;
    Vtx *verts = segmented_to_virtual(vert);
    for (i = 0; i < vertcount; i++) {
        verts[i].n.ob[xyz] += speed;
    }

    if (verts[xyz].n.flag > cycle) {
        for (i = 0; i < vertcount; i++) {
            verts[i].n.ob[xyz] -= cycle;
        }
        verts[xyz].n.flag = 0;
    }
    verts[xyz].n.flag += speed;
}

static void shift_xyz_sine(Vtx *vert, u16 vertcount, s16 speed, s16 cycle, u8 xyz) {
    u32 i;
    Vtx *verts = segmented_to_virtual(vert);
    for (i = 0; i < vertcount; i++) {
        verts[i].n.ob[xyz] += sins(verts[xyz].n.flag) * speed;
    }
    verts[xyz].n.flag += cycle * 0x20;
}


static void shift_uv(u8 scrolltype, Vtx *vert, u16 vertcount, s16 u, s16 v) {
    switch (scrolltype) {
        case SCROLL_UV:
            if (u)
                shift_u(vert, vertcount, u);
            if (v)
                shift_v(vert, vertcount, v);
            break;
        case SCROLL_X:
            shift_xyz(vert, vertcount, u, v, 0);
            break;
        case SCROLL_Y:
            shift_xyz(vert, vertcount, u, v, 1);
            break;
        case SCROLL_Z:
            shift_xyz(vert, vertcount, u, v, 2);
            break;
        case SCROLL_UV_SINE:
            if (u)
                shift_u_sine(vert, vertcount, u);
            if (v)
                shift_v_sine(vert, vertcount, v);
            break;
        case SCROLL_X_SINE:
            shift_xyz_sine(vert, vertcount, u, v, 0);
            break;
        case SCROLL_Y_SINE:
            shift_xyz_sine(vert, vertcount, u, v, 1);
            break;
        case SCROLL_Z_SINE:
            shift_xyz_sine(vert, vertcount, u, v, 2);
            break;
    }
}

/**
 * Main scrolling texture function. Call this every frame.
 * Add an entry to the switch (and make sure it's appropiate for the area you want it
 * to be active in, using another switch).
 */


//extern bob_a1_Sandfloor_001_mesh_vtx;
//extern bob_A3_Water_mesh_vtx;

void rgfx_update_scroll() {
    switch(gCurrLevelNum) {
        case LEVEL_BOB:
            switch(gCurrAreaIndex) {
                case 1:
                    //shift_st(&mat_bob_sm64_material_water, 19, 0.25, 0.75);
                    //shift_uv(SCROLL_UV, &bob_a1_Sandfloor_001_mesh_vtx, 4, 5, 0);
                    break;
                case 3:
                    //shift_uv(SCROLL_UV, &bob_A3_Water_mesh_vtx, 8, -5, 0);
                    break;
        }
        break;
    }
}
