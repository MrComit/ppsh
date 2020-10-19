#include <ultra64.h>
#include "PR/gbi.h"
#include "sm64.h"
#include "rendering_graph_node.h"
#include "mario_misc.h"
#include "skybox.h"
#include "engine/math_util.h"
#include "camera.h"
#include "envfx_snow.h"
#include "level_geo.h"
#include "levels/bob/header.h"
#include "level_update.h"
#include "audio/external.h"
#include "audio/data.h"

/**
 * Geo function that generates a displaylist for environment effects such as
 * snow or jetstream bubbles.
 */
Gfx *geo_enfvx_main(s32 callContext, struct GraphNode *node, f32 c[4][4]) {
    Vec3s marioPos;
    Vec3s camFrom;
    Vec3s camTo;
    void *particleList;
    Gfx *gfx = NULL;

    if (callContext == GEO_CONTEXT_RENDER && gCurGraphNodeCamera != NULL) {
        struct GraphNodeGenerated *execNode = (struct GraphNodeGenerated *) node;
        u32 *params = &execNode->parameter; // accessed a s32 as 2 u16s by pointing to the variable and
                                            // casting to a local struct as necessary.

        if (GET_HIGH_U16_OF_32(*params) != gAreaUpdateCounter) {
            UNUSED struct Camera *sp2C = gCurGraphNodeCamera->config.camera;
            s32 snowMode = GET_LOW_U16_OF_32(*params);

            vec3f_to_vec3s(camTo, gCurGraphNodeCamera->focus);
            vec3f_to_vec3s(camFrom, gCurGraphNodeCamera->pos);
            vec3f_to_vec3s(marioPos, gPlayerCameraState->pos);
            particleList = envfx_update_particles(snowMode, marioPos, camTo, camFrom);
            if (particleList != NULL) {
                Mtx *mtx = alloc_display_list(sizeof(*mtx));

                gfx = alloc_display_list(2 * sizeof(*gfx));
                mtxf_to_mtx(mtx, c);
                gSPMatrix(&gfx[0], VIRTUAL_TO_PHYSICAL(mtx), G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
                gSPBranchList(&gfx[1], VIRTUAL_TO_PHYSICAL(particleList));
                execNode->fnNode.node.flags = (execNode->fnNode.node.flags & 0xFF) | 0x400;
            }
            SET_HIGH_U16_OF_32(*params, gAreaUpdateCounter);
        }
    } else if (callContext == GEO_CONTEXT_AREA_INIT) {
        // Give these arguments some dummy values. Not used in ENVFX_MODE_NONE
        vec3s_copy(camTo, gVec3sZero);
        vec3s_copy(camFrom, gVec3sZero);
        vec3s_copy(marioPos, gVec3sZero);
        envfx_update_particles(ENVFX_MODE_NONE, marioPos, camTo, camFrom);
    }
    return gfx;
}

/**
 * Geo function that generates a displaylist for the skybox. Can be assigned
 * as the function of a GraphNodeBackground.
 */
Gfx *geo_skybox_main(s32 callContext, struct GraphNode *node, UNUSED Mat4 *mtx) {
    Gfx *gfx = NULL;
    struct GraphNodeBackground *backgroundNode = (struct GraphNodeBackground *) node;

    if (callContext == GEO_CONTEXT_AREA_LOAD) {
        backgroundNode->unused = 0;
    } else if (callContext == GEO_CONTEXT_RENDER) {
        struct GraphNodeCamera *camNode = (struct GraphNodeCamera *) gCurGraphNodeRoot->views[0];
        struct GraphNodePerspective *camFrustum =
            (struct GraphNodePerspective *) camNode->fnNode.node.parent;

        gfx = create_skybox_facing_camera(0, backgroundNode->background, camFrustum->fov, gLakituState.pos[0],
                            gLakituState.pos[1], gLakituState.pos[2], gLakituState.focus[0],
                            gLakituState.focus[1], gLakituState.focus[2]);
    }
    return gfx;
}



u8 gLightColor = 0xEF;
u8 gLightAction = 0x00;
u8 gLightApproach = 0x00;
u8 gLightSpeed = 0x00;
u32 gLightTimer = 0x00;


//#define COL gColColor

//#define gdSPChangeLights0(ar,ag,ab) gdSPDefLights0(ar, ag, ab);

Gfx *geo_update_bob_light(s32 callContext, struct GraphNode *node) {
    Lights1 *light;
    Lights1 *light2;
    Lights1 newLight = gdSPDefLights1(
        0xEF, 0xEF, 0xEF,
        0xEF, 0xEF, 0xEF, 0x0, 0x0, 0x0
    );

    if (sCurrPlayMode == 0) {
        newLight.a.l.col[0] = gLightColor;
        newLight.a.l.col[1] = gLightColor;
        newLight.a.l.col[2] = gLightColor;
        newLight.l[0].l.col[0] = gLightColor;
        newLight.l[0].l.col[1] = gLightColor;
        newLight.l[0].l.col[2] = gLightColor;
        light = segmented_to_virtual(&bob_dl_Rocks_v2_lights);
        *light = newLight;
        light2 = segmented_to_virtual(&bob_dl_Rocks2_v2_lights);
        *light2 = newLight;

        gLightColor = approach_s16_symmetric(gLightColor, gLightApproach, gLightSpeed);
        /*switch (gLightAction) {
            case 0:
                gLightApproach = 0xB;
                gLightSpeed = 0x4;   
                if ((gAudioFrameCount & 0xFF) % 240 == 0) {
                    gLightAction = 1;
                }
                break;
            case 1:
                gLightApproach = 0xEF;
                gLightSpeed = 0x40;
            
                if (gLightTimer > 2) {
                    gLightTimer = 0;
                    gLightAction = 0;
                }
                gLightTimer++;
                break;
        }*/



        switch (gLightAction) {
            case 0:
                gLightApproach = 0xB;
                gLightSpeed = 0x4;
                if (gLightTimer > 60) { //74 at 120 BPM, 60 at 144 BPM
                    gLightAction++;
                    gLightTimer = 0;
                    play_sound(SOUND_LIGHT_TICK, gDefaultSoundArgs);
                }
                break;
            case 1:
            case 2:
            case 3:
                if (gLightTimer > 12) { // 14 at 120 BPM, 12 at 144 BPM
                    play_sound(SOUND_LIGHT_TICK, gDefaultSoundArgs);
                    gLightTimer = 0;
                    gLightAction++;
                }
                break;
            case 4:
                gLightApproach = 0xEF;
                gLightSpeed = 0x40;
            
                if (gLightTimer > 2) {
                    //gLightTimer = 0;
                    gLightAction = 0;
                }
                break;

        }

    gLightTimer++;
    }
    return NULL;
}





/*Gfx *geo_sc_cam_pos(s32 callContext, struct GraphNode *node) {
    struct GraphNodeGenerated *sp30;
    sp30 = (struct GraphNodeGenerated *) node;

    switch (sp30->parameter) {
        case 0:
            if (gMarioState->pos[2] > -20361.1f && gMarioState->pos[1] < -7500.0f) {
                gComitSpecialCutscene = 1;
                gLakituState.curPos[2] = -18800.0f;
                gLakituState.curPos[1] = -8000.0f;
                //gLakituState.curFocus[2] = -20000.0f;
                //gLakituState.curFocus[1] = -9382.0f;
                gLakituState.goalPos[2] = -18800.0f;
                gLakituState.goalPos[1] = -8000.0f;
                gLakituState.goalFocus[2] = -20000.0f;
                gLakituState.goalFocus[1] = -9382.0f;
            }
            break;
        case 1:
            if (gMarioState->pos[2] > -20361.1f && gMarioState->pos[1] < -7500.0f) {
                gComitSpecialCutscene = 1;
                gLakituState.pos[2] = -18800.0f;
                gLakituState.pos[1] = -8000.0f;
                gLakituState.focus[2] = -20000.0f;
                gLakituState.focus[1] = -9382.0f;  
            }
            break;
        case 2:
            if (gMarioState->pos[2] > -20361.1f && gMarioState->pos[1] < -7500.0f) {
                gComitSpecialCutscene = 1;
                gLakituState.pos[2] = -18800.0f;
                gLakituState.pos[1] = -8000.0f;
                gLakituState.focus[2] = -20000.0f;
                gLakituState.focus[1] = -9382.0f;  
            }
            break;
    }
    return NULL;
}*/