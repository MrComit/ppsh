#include <ultra64.h>
#include "game/level_update.h"
#include "game/area.h"
#include "game/memory.h"
#include "game/display.h"
#include "levels/bob/header.h"
#include "game/camera.h"
#include "engine/math_util.h"
#include "levels/jrb/header.inc.h"

#define SCROLL_UV 0
#define SCROLL_X 1
#define SCROLL_Y 2
#define SCROLL_Z 3
#define SCROLL_UV_SINE 4
#define SCROLL_X_SINE 5
#define SCROLL_Y_SINE 6
#define SCROLL_Z_SINE 7

static void shift_u(Vtx *vert, u16 vertcount, u16 width, s16 speed) {
    u16 overflownum;
    u32 i;
    Vtx *verts = segmented_to_virtual(vert);
    if (width)
        overflownum = 0x20 * width;
    else
        overflownum = 0x1000;
    for (i = 0; i < vertcount; i++) {
        verts[i].n.tc[0] += speed;
    }

    if (verts[0].n.flag * absi(speed) > overflownum) {
        for (i = 0; i < vertcount; i++) {
            verts[i].n.tc[0] -= overflownum * signum_positive(speed);
        }
        verts[0].n.flag = 0;
    }
    verts[0].n.flag++;
}

static void shift_v(Vtx *vert, u16 vertcount, u16 height, s16 speed) {
    u16 overflownum;
    u32 i;
    Vtx *verts = segmented_to_virtual(vert);
    if (height)
        overflownum = 0x20 * height;
    else
        overflownum = 0x1000;
    for (i = 0; i < vertcount; i++) {
        verts[i].n.tc[1] += speed;
    }

    if (verts[1].n.flag * absi(speed) > overflownum) {
        for (i = 0; i < vertcount; i++) {
            verts[i].n.tc[1] -= overflownum * signum_positive(speed);
        }
        verts[1].n.flag = 0;
    }
    verts[1].n.flag++;
}

static void shift_u_sine(Vtx *vert, u16 vertcount, s16 speed, s16 cycle) {
    u32 i;
    Vtx *verts = segmented_to_virtual(vert);
    for (i = 0; i < vertcount; i++) {
        verts[i].n.tc[0] += sins(verts[0].n.flag) * speed;
    }
    verts[0].n.flag += cycle * 0x20;
}

static void shift_v_sine(Vtx *vert, u16 vertcount, s16 speed, s16 cycle) {
    u32 i;
    Vtx *verts = segmented_to_virtual(vert);
    for (i = 0; i < vertcount; i++) {
        verts[i].n.tc[1] += coss(verts[1].n.flag) * speed;
    }
    verts[1].n.flag += cycle * 0x20;
}

static void shift_xyz(Vtx *vert, u16 vertcount, s16 speed, s16 cycle, u8 xyz) {
    u32 i;
    Vtx *verts = segmented_to_virtual(vert);
    for (i = 0; i < vertcount; i++) {
        verts[i].n.ob[xyz] += speed;
        if (verts[i].n.ob[xyz] > cycle * signum_positive(speed)) {
            for (i = 0; i < vertcount; i++)
                verts[i].n.ob[xyz] -= cycle * signum_positive(speed);
            break;
        }
    }

    //if (verts[0].n.ob[xyz] > cycle * signum_positive(speed)) {
    //    for (i = 0; i < vertcount; i++)
    //        verts[i].n.ob[xyz] -= cycle * signum_positive(speed);
    //}
    /*if (!cycle) {
        if (verts[i].n.ob[xyz] > 32767 || verts[i].n.ob[xyz] < -32768)

    }
    else if (verts[xyz].n.flag > cycle) {
        for (i = 0; i < vertcount; i++) {
            verts[i].n.ob[xyz] -= cycle * signum_positive(speed);
        }
        verts[xyz].n.flag = 0;
    }
    verts[xyz].n.flag += absi(speed);*/
}

static void shift_xyz_sine(Vtx *vert, u16 vertcount, s16 speed, s16 cycle, u8 xyz) {
    u32 i;
    Vtx *verts = segmented_to_virtual(vert);
    for (i = 0; i < vertcount; i++) {
        verts[i].n.ob[xyz] += sins(verts[xyz].n.flag) * speed;
    }
    verts[xyz].n.flag += cycle * 0x20;
}


static void shift_uv(u8 scrolltype, Vtx *vert, u16 vertcount, u16 width, u16 height, s16 u, s16 v) {
    switch (scrolltype) {
        case SCROLL_UV:
            if (u)
                shift_u(vert, vertcount, width, u);
            if (v)
                shift_v(vert, vertcount, height, v);
            break;
        case SCROLL_X:
        case SCROLL_Y:
        case SCROLL_Z:
            shift_xyz(vert, vertcount, u, v, scrolltype - 1);
            break;
        case SCROLL_UV_SINE:
            if (u)
                shift_u_sine(vert, vertcount, u, u);
            if (v)
                shift_v_sine(vert, vertcount, v, v);
            break;
        case SCROLL_X_SINE:
        case SCROLL_Y_SINE:
        case SCROLL_Z_SINE:
            shift_xyz_sine(vert, vertcount, u, v, scrolltype - 5);
            break;
    }
}

//extern bob_a1_Sandfloor_001_mesh_vtx;
//extern bob_A3_Water_mesh_vtx;
extern wf_Quicksand_mesh_vtx;
extern wf_dl_Clouds1_mesh_vtx_0;
extern wf_dl_Clouds2_mesh_vtx_0;
extern wf_dl_Clouds3_mesh_vtx_0;
extern wf_dl_Clouds4_mesh_vtx_0;
//extern ccm_dl_Mist_mesh_vtx_0;



static void shift_traffic(Vtx *vert1, Vtx *vert2, s16 speed) {
    u32 i;
    Vtx *verts1 = segmented_to_virtual(vert1);
    Vtx *verts2 = segmented_to_virtual(vert2);
    for (i = 0; i < 104; i++) {
        verts1[i].n.ob[0] -= speed;
        if (i < 18) {
            verts2[i].n.ob[0] -= speed;
        }

    }
    if (verts1[0].n.ob[0] < -10000) {
        for (i = 0; i < 104; i++)
            verts1[i].n.ob[0] += 28000;
        for (i = 0; i < 18; i++)
            verts2[i].n.ob[0] += 28000;
            //break;
    }
    /*for (i = 0; i < 18; i++) {
        verts2[i].n.ob[0] += speed;
        if (verts2[i].n.ob[0] > cycle * signum_positive(speed)) {
            for (i = 0; i < vertcount; i++)
                verts2[i].n.ob[0] -= cycle * signum_positive(speed);
            break;
        }
    }*/


    //verts1[0].n.flag += absi(speed);
}



//jrb_dl_TraffLight_001_mesh_vtx_0 18
//jrb_dl_TraffPost_mesh_vtx_0 90



// Call this function inside play_mode_normal() in level_update.c
void uv_update_scroll() {
    switch(gCurrLevelNum) {
        case LEVEL_BOB:
            switch(gCurrAreaIndex) {
                case 1:
                    //shift_uv(SCROLL_UV, &bob_a1_Sandfloor_001_mesh_vtx, 4, 32, 32, 5, 0);
                    break;
                case 3:
                    //shift_uv(SCROLL_UV, &bob_A3_Water_mesh_vtx, 8, 32, 32, -5, 0);
                    break;
        }   
            break;
        case LEVEL_WF:
            if (gCurrAreaIndex == 1) {
                shift_uv(SCROLL_X, &wf_dl_Clouds1_mesh_vtx_0, 24, 64, 32, -20, -32000);
                shift_uv(SCROLL_X, &wf_dl_Clouds2_mesh_vtx_0, 24, 64, 32, -20, -32000);
                shift_uv(SCROLL_X, &wf_dl_Clouds3_mesh_vtx_0, 24, 64, 32, -20, -32000);
                shift_uv(SCROLL_X, &wf_dl_Clouds4_mesh_vtx_0, 24, 64, 32, -20, -32000);
            }
        case LEVEL_JRB:
            if (gCurrAreaIndex == 3 && gMarioState->pos[2] < 0.0f) {
                shift_traffic(&jrb_dl_TraffPost_mesh_vtx_0, &jrb_dl_red_mesh_vtx_0, 68);
                shift_traffic(&jrb_dl_TraffPost_001_mesh_vtx_0, &jrb_dl_TraffLight_001_mesh_vtx_0, 68);
                shift_traffic(&jrb_dl_TraffPost_002_mesh_vtx_0, &jrb_dl_TraffLight_002_mesh_vtx_0, 68);
            }
            //shift_uv(SCROLL_Y_SINE, &ccm_dl_Mist_mesh_vtx_0, 22, 64, 64, 20, 50);
            break;
        /*case LEVEL_WF:
            if (gCurrAreaIndex == 1)
                shift_uv(SCROLL_UV, &wf_Quicksand_mesh_vtx, 24, 32, 32, 0, -16);
            break;*/
    }
}