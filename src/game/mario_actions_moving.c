#include <ultra64.h>

#include "sm64.h"
#include "mario.h"
#include "audio/external.h"
#include "engine/math_util.h"
#include "engine/surface_collision.h"
#include "mario_step.h"
#include "area.h"
#include "interaction.h"
#include "mario_actions_object.h"
#include "memory.h"
#include "behavior_data.h"
#include "game.h"
#include "display.h"
#include "obj_behaviors.h"
#include "object_helpers2.h"

s32 grindInitTriggered = 0;
s32 grindForward;
struct GrindPoints {
    Vec3f pos;
    s16 pointNext;
    s16 pointPrev;
    u16 forwardAngle;
};

struct GrindPoints sCurrentPoint;

//temp: offset = -7.17469 = -3587.345 on X

struct GrindPoints grind0[2] = {
    {{0, -9911.5f, 25040.95f}, -1, -1, 0x8000}, //0000
    {{0, -9911.5f, 14399.2f}, -1, -1, 0x8000},  
};

struct GrindPoints grind1[6] = {
    {{4518.685f, -9911.5f, 1101.535f}, -1, -1, 0xC000},
    {{1739.82f, -9363.175f, 1101.535f}, 2, 0, 0xC000},
    {{1739.82f, -8452.27f, 4976.85f}, 3, 1, 0x0000},
    {{4666.065f, -6836.99f, 4976.85f}, 4, 2, 0x4000},
    {{4676.86f, -5667.82f, 2015.165f}, 5, 3, 0x8000},
    {{4521.715f, -5643.425f, 2015.165f}, -2, -2, 0xC000},
};

struct GrindPoints grind2[4] = {
    {{1834.385f, -5643.425f, 6614.85f}, -2, -2, 0xC000},
    {{-600.0f, -5643.425f, 6614.85f}, -1, -1, 0xC000},
    {{-1131.74f, -5397.285f, 6614.85f}, -1, -1, 0xC000},
    {{-1834.395f, -5077.02f, 6614.85f}, -2, -2, 0xC000},
};

struct GrindPoints grind3[2] = {
    {{-13814.1f, -10000.0f, 23253.05f}, -2, -2, 0xC000},
    {{-14757.8f, -9474.905f, 23253.05f}, -1, -1, 0xC000},
};

struct GrindPoints grind4[14] = {
    {{9561.855f, -9911.5f, 5281.65f}, 1, 1, 0xC000},
    {{9720.705f, -9911.5f, 5281.65f}, 2, 2, 0xC000},
    {{11944.355f, -8595.245f, 5281.65f}, 3, 3, 0xC000},
    {{12149.205f, -8595.245f, 5281.65f}, -1, -1, 0xC000},
    {{13149.205f, -8595.245f, 5281.65f}, 5, 5, 0xC000},
    {{13308.055f, -8595.245f, 5281.65f}, 6, 6, 0xC000},
    {{15791.505f, -7278.965f, 5281.65f}, 7, 7, 0x0000},
    {{15791.505f, -5962.715f, 7762.6f}, 8, 8, 0x0000},
    {{15791.505f, -5962.715f, 7967.45f}, -1, -1, 0x0000},
    {{15791.505f, -6051.22f, 8921.45f}, 10, 10, 0x0000},
    {{15791.505f, -6051.22f, 9080.3f}, 11, 11, 0x0000},
    {{15791.505f, -4734.95f, 11561.2f}, 12, 12, 0x4000},
    {{13308.055f, -3418.7f,  11561.2f}, 13, 13, 0x4000},
    {{13103.205f, -3418.7f, 11561.2f}, -1, -1, 0x4000},
};

struct GrindPoints grind5[2] = {
    {{10850.605f, -3189.65f, 12472.4f}, 1, -2, 0x0000},
    {{10850.605f, -3189.65f, 15596.1f}, -2, 0, 0x0000},
};

struct GrindPoints grind6[2] = {
    {{-3232.54f, 1780.9f, -180.4395f}, -2, -2, 0x8000},
    {{-3232.54f, 1780.9f, -2585.625f}, -2, -2, 0x8000},
};

struct GrindPoints grind7[4] = {
    {{-1934.4f, 1785.35f, -3897.255f}, -2, -2, 0x4000},
    {{-644.805f, 1785.35f, -3897.255f}, -1, -1, 0x4000},
    {{1934.4f, 1220.2f, -3897.255f}, -2, -2, 0xC000},
    {{375.558f, 1220.2f, -3897.255f}, -1, -1, 0xC000},
};

struct GrindPoints grind8[2] = {
    {{10575.055f, -3189.65, 8171.45f}, -1, -1, 0x8000},
    {{10575.055f, -3189.65f, 4934.1f}, -1, -1, 0x8000},
};

struct GrindPoints grind9[2] = {
    {{11136.005f, -3189.65f, 8171.45f}, -1, -1, 0x8000},
    {{11136.005f, -3189.65, 4934.1f}, -1, -1, 0x8000},
};

struct GrindPoints grindA[3] = {
    {{16062.555f, 4348.55f, 7976.4f}, 1, 1, 0xC000},
    {{15736.555f, 4348.55f, 7976.4f}, 2, 2, 0xC000},
    {{11211.105f, 6049.85f, 7976.4f}, -1, -1, 0xC000},
};

struct GrindPoints grindB[3] = {
    {{9506.95f, 8929.3f, 3898.02f}, 1, 1, 0x8000},
    {{9506.95f, 8929.3f, 2571.32f}, 2, 2, 0x8000}, 
    {{9149.7f, 8929.3f, 2571.32f}, -2, -2, 0xC000},
};

struct GrindPoints grindC[5] = {
    {{16681.6f, 4348.545f, 4502.34f}, 1, -1, 0x8000},
    {{16681.6f, 4348.545f, 4176.34f}, 2, 0, 0x8000},
    {{16681.6f, 6765.7f, -5227.75f}, 3, 1, 0x8000},
    {{21575.95f, 6765.7f, -5227.75f}, 4, 2, 0xC000},
    {{21575.95f, 6765.7f, -8801.95f}, -2, 3, 0x8000},
};

struct GrindPoints grindD[2] = {
    {{7263.55f, 1220.2f, -2585.62f}, 1, -2, 0x0000},
    {{7263.55f, 1220.2f, 1283.16f}, -2, 0, 0x0000}, 
};

struct GrindPoints grindE[3] = {
    {{9311.9f, 1308.71f, -2530.67f}, 1, -1, 0x4000},
    {{12204.15f, 1437.87f, -2530.67f}, 2, 0, 0x4000},
    {{12204.15f, 1641.515f, -5818.5f}, -1, 1, 0x8000},
};

struct GrindPoints grindF[2] = {
    {{-3218.09f, -5029.45f, 7921.45f}, 1, -2, 0x0000},
    {{-3218.09f, -3184.18f, 12800.1f}, -2, 0, 0x0000},

};

struct GrindPoints grind10[2] = {
    {{-16085.55f, -20.2725f, -2585.62f}, 1, -2, 0x0000},
    {{-16085.55f, -20.2725f, 1283.16f}, -2, 0, 0x0000},
};

struct GrindPoints grind11[3] = {
    {{-14650.45f, -1859.27f, 7969.35f}, 1, -1, 0x4000},
    {{-10992.95f, -175.774f, 7969.35f}, 2, 0, 0x4000},
    {{-10202.3f, -25.9445f, 7866.5f}, -1, 1, 0x4000},
};

struct GrindPoints grind12[4] = {
    {{12823.2f, -3101.19f, 8866.5f}, 1, -1, 0x4000},
    {{13149.2f, -3101.19f, 8866.5f}, 2, 0, 0x4000},
    {{22966.15f, 2490.455f, 8866.5f}, 3, 1, 0x4000},
    {{22966.15f, 3470.665f, 10671.6f}, -2, 4, 0x0000},

};


struct GrindPoints grind13[5] = {
    {{19915.5f, 543.4f, 24851.75f}, 1, -1, 0x8000},
    {{19915.5f, 543.4f, 23627.85f}, 2, 0, 0x8000},
    {{19915.5f, 2184.545f, 16544.7f}, 3, 1, 0x8000},
    {{21251.05f, 2184.545f, 16544.7f}, 4, 2, 0x4000},
    {{21251.05f, 3620.66f, 11508.9f}, -2, 3, 0x8000},

};

struct GrindPoints grind14[11] = {
    {{-27645.85f, -10177.65f, -8366.19f}, 1, 1, 0x0000},
    {{-27886.6f, -10103.7f, -8375.04f}, 2, 2, 0x0000},
    {{-29856.85f, -10103.7f, -8447.59f}, 3, 3, 0x0000},
    {{-30745.0f, -10103.7f, -9817.79f}, 4, 4, 0x0000},
    {{-31142.1f, -10103.7f, -11647.74f}, 5, 5, 0x0000},
    {{-31422.3f, -10103.7f, -14455.34f}, 6, 6, 0x0000},
    {{-31537.9f, -10103.7f, -16695.44f}, 7, 7, 0x0000},
    {{-31019.05f, -10103.7f, -18698.19f}, 8, 8, 0x0000},
    {{-29526.7f, -10103.7f, -19196.64f}, 9, 9, 0x0000},
    {{-28997.2f, -10103.7f, -19196.64f}, 10, 10, 0x0000},
    {{-28838.6f, -10152.65f, -19196.64f}, -2, -2, 0x0000},
};

struct GrindPoints grind15[5] = {
    {{-28316.3f, -10177.65f, -19196.64f}, 1, -2, 0x4000},
    {{-28066.3f, -10103.7f, -19196.64f}, 2, 0, 0x4000},
    {{-26639.85f, -9365.2f, -19196.64f}, 3, 1, 0x4000},
    {{-24776.75f, -9365.2f, -19196.64f}, 4, 2, 0x4000},
    {{-23350.3f, -10103.7f, -19196.64f}, -1, 3, 0x4000},
};

struct GrindPoints grind16[20] = {
    {{-22546.25f, -10099.65f, -19197.09f}, 1, -1, 0x4000},
    {{-22055.75f, -10099.65f, -19197.09f}, 2, 0, 0x4000},
    {{-22055.75f, -10099.65f, -18782.89f}, 3, 1, 0x0000},
    {{-22055.75f, -10362.5f, -17652.74f}, 4, 2, 0x0000},
    {{-22055.75f, -10099.65f, -16522.59f}, 5, 3, 0x0000},
    {{-22055.75f, -9827.45f, -15957.54f}, 6, 4, 0x0000},
    {{-22055.75f, -9641.6f, -15392.44f}, 7, 5, 0x0000},
    {{-22055.75f, -9782.8f, -14832.29f}, 8, 6, 0x0000},
    {{-22055.75f, -10099.65f, -14262.29f}, 9, 7, 0x0000},
    {{-22055.75f, -10265.2f, -13697.19f}, 10, 8, 0x0000},
    {{-22055.75f, -10388.05f, -13132.14f}, 11, 9, 0x0000},
    {{-22055.75f, -10456.0f, -12567.04f}, 12, 10, 0x0000},
    {{-22055.75f, -10315.1f, -12001.99f}, 13, 11, 0x0000},
    {{-22055.75f, -10099.65f, -11436.89f}, 14, 12, 0x0000},
    {{-22055.75f, -9827.1f, -10871.84f}, 15, 13, 0x0000},
    {{-22055.75f, -9900.85f, -10306.74f}, 16, 14, 0x0000},
    {{-22055.75f, -10099.65f, -9308.99f}, 17, 15, 0x0000},
    {{-22055.75f, -10099.65f, -8502.19f}, 18, 16, 0x0000},
    {{-22386.0f, -10099.65f, -8502.19f}, 19, 17, 0xC000},
    {{-23265.5f, -9507.9f, -8502.19f}, -1, 18, 0xC000},
};

struct GrindPoints grind17[6] = {
    {{-24174.7f, -9035.15f, -8502.19f}, 1, -1, 0xC000},
    {{-24562.65f, -9035.15f, -8502.19f}, 2, 0, 0xC000},
    {{-25013.35f, -8668.35f, -8502.19f}, 3, 1, 0xC000},
    {{-25464.1f, -8668.35f, -8502.19f}, 4, 2, 0xC000},
    {{-25914.8f, -9035.15f, -8502.19f}, 5, 3, 0xC000},
    {{-26302.75f, -9035.15f, -8502.19f}, -1, 4, 0xC000},
};

struct GrindPoints grind18[21] = {
    {{-24807.95f, -10103.7f, -16365.14f}, 1, 1, 0x0000},
    {{-24807.95f, -10103.7f, -15281.24f}, 2, 2, 0x0000},
    {{-25191.75f, -10103.7f, -14561.69f}, -2, -2, 0x0000},

    {{-25421.75f, -10103.7f, -14143.04f}, 4, 4, 0x0000},
    {{-25638.55f, -10103.7f, -13917.99f}, 5, 5, 0x0000},
    {{-25725.35f, -10103.7f, -13468.79f}, 6, 6, 0x0000},
    {{-25547.2f, -10103.7f, -13130.99f}, 7, 7, 0x0000},
    {{-25067.9f, -10103.7f, -12942.29f}, -2, -2, 0x0000},

    {{-24653.55f, -10103.7f, -12798.54f}, 9, 9, 0x0000},
    {{-24185.55f, -10103.7f, -12640.49f}, 10, 10, 0x0000},
    {{-24070.6f, -10103.7f, -12068.54f}, 11, 11, 0x0000},
    {{-24216.9f, -10103.7f, -11666.49f}, 12, 12, 0x0000},
    {{-23955.3f, -10103.7f, -11403.54f}, -2, -2, 0x0000},

    {{-23719.9f, -10103.7f, -11170.94f}, 14, 14, 0x0000},
    {{-23106.25f, -10103.7f, -10763.69f}, 15, 15, 0x0000},
    {{-23167.65f, -10103.7f, -10119.74f}, 16, 16, 0x0000},
    {{-23877.95f, -10103.7f, -9917.14f}, 17, 17, 0x0000},
    {{-24371.8f, -10103.7f, -9978.49f}, -2, -2, 0x0000},

    {{-24715.45f, -10103.7f, -10011.99f}, 19, 19, 0x0000},
    {{-25309.35f, -10103.7f, -10293.44f}, 20, 20, 0x0000},
    {{-25816.2f, -10103.7f, -10584.89f}, -2, -2, 0x0000},
};


struct GrindPoints grind19[3] = {
    {{14439.75f, -3189.67f, 1283.145f}, 1, -1, 0x8000},
    {{14439.75f, -1880.55f, -1012.75f}, 2, 0, 0x8000},
    {{14439.75f, -1880.55f, -2586.15f}, -1, 1, 0x8000},

};


struct GrindPoints *grindTrajectories[] = {
    grind0, grind1, grind2, grind3, grind4, grind5, grind6, grind7, grind8, grind9, grindA, grindB, grindC, grindD, grindE,
    grindF, grind10, grind11, grind12, grind13, grind14, grind15, grind16, grind17, grind18, grind19,
};

u16 grindLengths[] = {
    2, 6, 4, 2, 14, 2, 2, 4, 2, 2, 3, 3, 5, 2, 3, 2, 2, 3, 4, 5, 11, 5, 20, 6, 21, 3,
};

struct LandingAction {
    s16 numFrames;
    s16 unk02;
    u32 verySteepAction;
    u32 endAction;
    u32 aPressedAction;
    u32 offFloorAction;
    u32 slideAction;
};

struct LandingAction sJumpLandAction = {
    4, 5, ACT_FREEFALL, ACT_JUMP_LAND_STOP, ACT_DOUBLE_JUMP, ACT_FREEFALL, ACT_BEGIN_SLIDING,
};

struct LandingAction sFreefallLandAction = {
    4, 5, ACT_FREEFALL, ACT_FREEFALL_LAND_STOP, ACT_DOUBLE_JUMP, ACT_FREEFALL, ACT_BEGIN_SLIDING,
};

struct LandingAction sSideFlipLandAction = {
    4, 5, ACT_FREEFALL, ACT_SIDE_FLIP_LAND_STOP, ACT_DOUBLE_JUMP, ACT_FREEFALL, ACT_BEGIN_SLIDING,
};

struct LandingAction sHoldJumpLandAction = {
    4, 5, ACT_HOLD_FREEFALL, ACT_UNKNOWN_034, ACT_HOLD_JUMP, ACT_HOLD_FREEFALL, ACT_HOLD_BEGIN_SLIDING,
};

struct LandingAction sHoldFreefallLandAction = {
    4, 5, ACT_HOLD_FREEFALL, ACT_UNKNOWN_035, ACT_HOLD_JUMP, ACT_HOLD_FREEFALL, ACT_HOLD_BEGIN_SLIDING,
};

struct LandingAction sLongJumpLandAction = {
    6, 5, ACT_FREEFALL, ACT_LONG_JUMP_LAND_STOP, ACT_LONG_JUMP, ACT_FREEFALL, ACT_BEGIN_SLIDING,
};

struct LandingAction sDoubleJumpLandAction = {
    4, 5, ACT_FREEFALL, ACT_DOUBLE_JUMP_LAND_STOP, ACT_JUMP, ACT_FREEFALL, ACT_BEGIN_SLIDING,
};

struct LandingAction sTripleJumpLandAction = {
    4, 0, ACT_FREEFALL, ACT_TRIPLE_JUMP_LAND_STOP, ACT_UNINITIALIZED, ACT_FREEFALL, ACT_BEGIN_SLIDING,
};

struct LandingAction sBackflipLandAction = {
    4, 0, ACT_FREEFALL, ACT_BACKFLIP_LAND_STOP, ACT_BACKFLIP, ACT_FREEFALL, ACT_BEGIN_SLIDING,
};

Mat4 D_80339F50[2];

s16 func_80263A50(struct MarioState *m) {
    s16 pitch = find_floor_slope(m, 0);
    pitch = pitch * m->forwardVel / 40.0f;
    return -pitch;
}

void func_80263AD4(struct MarioState *m, s16 frame1, s16 frame2) {
    if (is_anim_past_frame(m, frame1) || is_anim_past_frame(m, frame2)) {
        if (m->flags & MARIO_METAL_CAP) {
            if (m->marioObj->header.gfx.unk38.animID == MARIO_ANIM_TIPTOE) {
                play_sound_and_spawn_particles(m, SOUND_ACTION_METAL_STEP_TIPTOE, 0);
            } else {
                play_sound_and_spawn_particles(m, SOUND_ACTION_METAL_STEP, 0);
            }
        } else if (m->quicksandDepth > 50.0f) {
            play_sound(SOUND_ACTION_QUICKSAND_STEP, m->marioObj->header.gfx.cameraToObject);
        } else if (m->marioObj->header.gfx.unk38.animID == MARIO_ANIM_TIPTOE) {
            play_sound_and_spawn_particles(m, SOUND_ACTION_TERRAIN_STEP_TIPTOE, 0);
        } else {
            play_sound_and_spawn_particles(m, SOUND_ACTION_TERRAIN_STEP, 0);
        }
    }
}

void func_80263C14(struct MarioState *m) {
    m->pos[1] = m->floorHeight;
    mtxf_align_terrain_triangle(D_80339F50[m->unk00], m->pos, m->faceAngle[1], 40.0f);
    m->marioObj->header.gfx.throwMatrix = &D_80339F50[m->unk00];
}

s32 begin_walking_action(struct MarioState *m, f32 forwardVel, u32 action, u32 actionArg) {
    m->faceAngle[1] = m->intendedYaw;
    mario_set_forward_vel(m, forwardVel);
    return set_mario_action(m, action, actionArg);
}

void check_ledge_climb_down(struct MarioState *m) {
    struct WallCollisionData wallCols;
    struct Surface *floor;
    f32 floorHeight;
    struct Surface *wall;
    s16 wallAngle;
    s16 wallDYaw;

    if (m->forwardVel < 10.0f) {
        wallCols.x = m->pos[0];
        wallCols.y = m->pos[1];
        wallCols.z = m->pos[2];
        wallCols.radius = 10.0f;
        wallCols.offsetY = -10.0f;

        if (find_wall_collisions(&wallCols) != 0) {
            floorHeight = find_floor(wallCols.x, wallCols.y, wallCols.z, &floor);
            if (floor != NULL) {
                if (wallCols.y - floorHeight > 160.0f) {
                    wall = wallCols.walls[wallCols.numWalls - 1];
                    wallAngle = atan2s(wall->normal.z, wall->normal.x);
                    wallDYaw = wallAngle - m->faceAngle[1];

                    if (wallDYaw > -0x4000 && wallDYaw < 0x4000) {
                        m->pos[0] = wallCols.x - 20.0f * wall->normal.x;
                        m->pos[2] = wallCols.z - 20.0f * wall->normal.z;

                        m->faceAngle[0] = 0;
                        m->faceAngle[1] = wallAngle + 0x8000;

                        set_mario_action(m, ACT_LEDGE_CLIMB_DOWN, 0);
                        set_mario_animation(m, MARIO_ANIM_CLIMB_DOWN_LEDGE);
                    }
                }
            }
        }
    }
}

void slide_bonk(struct MarioState *m, u32 fastAction, u32 slowAction) {
    if (m->forwardVel > 16.0f) {
        mario_bonk_reflection(m, TRUE);
        drop_and_set_mario_action(m, fastAction, 0);
    } else {
        mario_set_forward_vel(m, 0.0f);
        set_mario_action(m, slowAction, 0);
    }
}

s32 set_triple_jump_action(struct MarioState *m, UNUSED u32 action, UNUSED u32 actionArg) {
    if (m->flags & MARIO_WING_CAP) {
        return set_mario_action(m, ACT_FLYING_TRIPLE_JUMP, 0);
    } else if (m->forwardVel > 20.0f) {
        return set_mario_action(m, ACT_TRIPLE_JUMP, 0);
    } else {
        return set_mario_action(m, ACT_JUMP, 0);
    }

    return 0;
}

void update_sliding_angle(struct MarioState *m, f32 accel, f32 lossFactor) {
    s32 newFacingDYaw;
    s16 facingDYaw;

    struct Surface *floor = m->floor;
    s16 slopeAngle = atan2s(floor->normal.z, floor->normal.x);
    f32 steepness = sqrtf(floor->normal.x * floor->normal.x + floor->normal.z * floor->normal.z);
    UNUSED f32 normalY = floor->normal.y;

    m->slideVelX += accel * steepness * sins(slopeAngle);
    m->slideVelZ += accel * steepness * coss(slopeAngle);

    m->slideVelX *= lossFactor;
    m->slideVelZ *= lossFactor;

    m->slideYaw = atan2s(m->slideVelZ, m->slideVelX);

    facingDYaw = m->faceAngle[1] - m->slideYaw;
    newFacingDYaw = facingDYaw;

    //! -0x4000 not handled - can slide down a slope while facing perpendicular to it
    if (newFacingDYaw > 0 && newFacingDYaw <= 0x4000) {
        if ((newFacingDYaw -= 0x200) < 0) {
            newFacingDYaw = 0;
        }
    } else if (newFacingDYaw > -0x4000 && newFacingDYaw < 0) {
        if ((newFacingDYaw += 0x200) > 0) {
            newFacingDYaw = 0;
        }
    } else if (newFacingDYaw > 0x4000 && newFacingDYaw < 0x8000) {
        if ((newFacingDYaw += 0x200) > 0x8000) {
            newFacingDYaw = 0x8000;
        }
    } else if (newFacingDYaw > -0x8000 && newFacingDYaw < -0x4000) {
        if ((newFacingDYaw -= 0x200) < -0x8000) {
            newFacingDYaw = -0x8000;
        }
    }

    m->faceAngle[1] = m->slideYaw + newFacingDYaw;

    m->vel[0] = m->slideVelX;
    m->vel[1] = 0.0f;
    m->vel[2] = m->slideVelZ;

    mario_update_moving_sand(m);
    mario_update_windy_ground(m);

    //! Speed is capped a frame late (butt slide HSG)
    m->forwardVel = sqrtf(m->slideVelX * m->slideVelX + m->slideVelZ * m->slideVelZ);
    if (m->forwardVel > 100.0f) {
        m->slideVelX = m->slideVelX * 100.0f / m->forwardVel;
        m->slideVelZ = m->slideVelZ * 100.0f / m->forwardVel;
    }

    if (newFacingDYaw < -0x4000 || newFacingDYaw > 0x4000) {
        m->forwardVel *= -1.0f;
    }
}

s32 update_sliding(struct MarioState *m, f32 stopSpeed) {
    f32 lossFactor;
    f32 accel;
    f32 oldSpeed;
    f32 newSpeed;

    s32 stopped = FALSE;

    s16 intendedDYaw = m->intendedYaw - m->slideYaw;
    f32 forward = coss(intendedDYaw);
    f32 sideward = sins(intendedDYaw);

    //! 10k glitch
    if (forward < 0.0f && m->forwardVel >= 0.0f) {
        forward *= 0.5f + 0.5f * m->forwardVel / 100.0f;
    }

    switch (mario_get_floor_class(m)) {
        case SURFACE_CLASS_VERY_SLIPPERY:
            accel = 10.0f;
            lossFactor = m->intendedMag / 32.0f * forward * 0.02f + 0.98f;
            break;

        case SURFACE_CLASS_SLIPPERY:
            accel = 8.0f;
            lossFactor = m->intendedMag / 32.0f * forward * 0.02f + 0.96f;
            break;

        default:
            accel = 7.0f;
            lossFactor = m->intendedMag / 32.0f * forward * 0.02f + 0.92f;
            break;

        case SURFACE_CLASS_NOT_SLIPPERY:
            accel = 5.0f;
            lossFactor = m->intendedMag / 32.0f * forward * 0.02f + 0.92f;
            break;
    }

    oldSpeed = sqrtf(m->slideVelX * m->slideVelX + m->slideVelZ * m->slideVelZ);

    //! This is attempting to use trig derivatives to rotate mario's speed.
    // It is slightly off/asymmetric since it uses the new X speed, but the old
    // Z speed.
    m->slideVelX += m->slideVelZ * (m->intendedMag / 32.0f) * sideward * 0.05f;
    m->slideVelZ -= m->slideVelX * (m->intendedMag / 32.0f) * sideward * 0.05f;

    newSpeed = sqrtf(m->slideVelX * m->slideVelX + m->slideVelZ * m->slideVelZ);

    if (oldSpeed > 0.0f && newSpeed > 0.0f) {
        m->slideVelX = m->slideVelX * oldSpeed / newSpeed;
        m->slideVelZ = m->slideVelZ * oldSpeed / newSpeed;
    }

    update_sliding_angle(m, accel, lossFactor);

    if (!mario_floor_is_slope(m) && m->forwardVel * m->forwardVel < stopSpeed * stopSpeed) {
        mario_set_forward_vel(m, 0.0f);
        stopped = TRUE;
    }

    return stopped;
}

void apply_slope_accel(struct MarioState *m) {
    f32 slopeAccel;

    struct Surface *floor = m->floor;
    f32 steepness = sqrtf(floor->normal.x * floor->normal.x + floor->normal.z * floor->normal.z);

    UNUSED f32 normalY = floor->normal.y;
    s16 floorDYaw = m->floorAngle - m->faceAngle[1];

    if (mario_floor_is_slope(m)) {
        s16 slopeClass = 0;

        if (m->action != ACT_SOFT_BACKWARD_GROUND_KB && m->action != ACT_SOFT_FORWARD_GROUND_KB) {
            slopeClass = mario_get_floor_class(m);
        }

        switch (slopeClass) {
            case SURFACE_CLASS_VERY_SLIPPERY:
                slopeAccel = 5.3f;
                break;
            case SURFACE_CLASS_SLIPPERY:
                slopeAccel = 2.7f;
                break;
            default:
                slopeAccel = 1.7f;
                break;
            case SURFACE_CLASS_NOT_SLIPPERY:
                slopeAccel = 0.0f;
                break;
        }

        if (floorDYaw > -0x4000 && floorDYaw < 0x4000) {
            m->forwardVel += slopeAccel * steepness;
        } else {
            m->forwardVel -= slopeAccel * steepness;
        }
    }

    m->slideYaw = m->faceAngle[1];

    m->slideVelX = m->forwardVel * sins(m->faceAngle[1]);
    m->slideVelZ = m->forwardVel * coss(m->faceAngle[1]);

    m->vel[0] = m->slideVelX;
    m->vel[1] = 0.0f;
    m->vel[2] = m->slideVelZ;

    mario_update_moving_sand(m);
    mario_update_windy_ground(m);
}

s32 apply_landing_accel(struct MarioState *m, f32 frictionFactor) {
    s32 stopped = FALSE;

    apply_slope_accel(m);

    if (!mario_floor_is_slope(m)) {
        m->forwardVel *= frictionFactor;
        if (m->forwardVel * m->forwardVel < 1.0f) {
            mario_set_forward_vel(m, 0.0f);
            stopped = TRUE;
        }
    }

    return stopped;
}

void update_shell_speed(struct MarioState *m) {
    f32 maxTargetSpeed;
    f32 targetSpeed;

    if (m->floorHeight < m->waterLevel) {
        m->floorHeight = m->waterLevel;
        m->floor = &gWaterSurfacePseudoFloor;
        m->floor->originOffset = m->waterLevel; //! Negative origin offset
    }

    if (m->floor != NULL && m->floor->type == SURFACE_SLOW) {
        maxTargetSpeed = 48.0f;
    } else {
        maxTargetSpeed = 64.0f;
    }

    targetSpeed = m->intendedMag * 2.0f;
    if (targetSpeed > maxTargetSpeed) {
        targetSpeed = maxTargetSpeed;
    }
    if (targetSpeed < 24.0f) {
        targetSpeed = 24.0f;
    }

    if (m->forwardVel <= 0.0f) {
        m->forwardVel += 1.1f;
    } else if (m->forwardVel <= targetSpeed) {
        m->forwardVel += 1.1f - m->forwardVel / 58.0f;
    } else if (m->floor->normal.y >= 0.95f) {
        m->forwardVel -= 1.0f;
    }

    //! No backward speed cap (shell hyperspeed)
    if (m->forwardVel > 64.0f) {
        m->forwardVel = 64.0f;
    }

    m->faceAngle[1] =
        m->intendedYaw - approach_s32((s16)(m->intendedYaw - m->faceAngle[1]), 0, 0x800, 0x800);

    apply_slope_accel(m);
}

s32 apply_slope_decel(struct MarioState *m, f32 decelCoef) {
    f32 decel;
    s32 stopped = FALSE;

    switch (mario_get_floor_class(m)) {
        case SURFACE_CLASS_VERY_SLIPPERY:
            decel = decelCoef * 0.2f;
            break;
        case SURFACE_CLASS_SLIPPERY:
            decel = decelCoef * 0.7f;
            break;
        default:
            decel = decelCoef * 2.0f;
            break;
        case SURFACE_CLASS_NOT_SLIPPERY:
            decel = decelCoef * 3.0f;
            break;
    }

    if ((m->forwardVel = approach_f32(m->forwardVel, 0.0f, decel, decel)) == 0.0f) {
        stopped = TRUE;
    }

    apply_slope_accel(m);
    return stopped;
}

s32 update_decelerating_speed(struct MarioState *m) {
    s32 stopped = FALSE;

    if ((m->forwardVel = approach_f32(m->forwardVel, 0.0f, 1.0f, 1.0f)) == 0.0f) {
        stopped = TRUE;
    }

    mario_set_forward_vel(m, m->forwardVel);
    mario_update_moving_sand(m);
    mario_update_windy_ground(m);

    return stopped;
}

void update_walking_speed(struct MarioState *m) {
    f32 maxTargetSpeed;
    f32 targetSpeed;

    if (m->floor != NULL && m->floor->type == SURFACE_SLOW) {
        maxTargetSpeed = 24.0f;
    } else {
        maxTargetSpeed = 32.0f;
    }

    targetSpeed = m->intendedMag < maxTargetSpeed ? m->intendedMag : maxTargetSpeed;

    if (m->quicksandDepth > 10.0f) {
        targetSpeed *= 8.0 / m->quicksandDepth;
    }

    if (m->forwardVel <= 0.0f) {
        m->forwardVel += 1.1f;
    } else if (m->forwardVel <= targetSpeed) {
        m->forwardVel += 1.1f - m->forwardVel / 43.0f;
    } else if (m->floor->normal.y >= 0.95f) {
        m->forwardVel -= 1.0f;
    }

    if (m->forwardVel > 48.0f) {
        m->forwardVel = 48.0f;
    }

    if(m->action == ACT_GRIND) {
        m->faceAngle[1] =
            m->intendedYaw - approach_s32((s16)(m->intendedYaw - m->faceAngle[1]), 0, 0, 0);
    } else {
        m->faceAngle[1] =
            m->intendedYaw - approach_s32((s16)(m->intendedYaw - m->faceAngle[1]), 0, 0x800, 0x800);
    }
    apply_slope_accel(m);
}

s32 should_begin_sliding(struct MarioState *m) {
    if (m->input & INPUT_ABOVE_SLIDE) {
        s32 slideLevel = (m->area->terrainType & TERRAIN_MASK) == TERRAIN_SLIDE;
        s32 movingBackward = m->forwardVel <= -1.0f;

        if (slideLevel || movingBackward || mario_facing_downhill(m, FALSE)) {
            return TRUE;
        }
    }

    return FALSE;
}

s32 analog_stick_held_back(struct MarioState *m) {
    s16 intendedDYaw = m->intendedYaw - m->faceAngle[1];
    return intendedDYaw < -0x471C || intendedDYaw > 0x471C;
}

s32 check_ground_dive_or_punch(struct MarioState *m) {
    UNUSED s32 unused;

    if (m->input & INPUT_B_PRESSED) {
        //! Speed kick (shoutouts to SimpleFlips)
        if (m->forwardVel >= 29.0f && m->controller->stickMag > 48.0f) {
            m->vel[1] = 20.0f;
            return set_mario_action(m, ACT_DIVE, 1);
        }

        return set_mario_action(m, ACT_MOVE_PUNCHING, 0);
    }

    return FALSE;
}

s32 begin_braking_action(struct MarioState *m) {
    mario_drop_held_object(m);

    if (m->actionState == 1) {
        m->faceAngle[1] = m->actionArg;
        return set_mario_action(m, ACT_STANDING_AGAINST_WALL, 0);
    }

    if (m->forwardVel >= 16.0f && m->floor->normal.y >= 0.17364818f) {
        return set_mario_action(m, ACT_BRAKING, 0);
    }

    return set_mario_action(m, ACT_DECELERATING, 0);
}

void func_802652F0(struct MarioState *m) {
    s32 val14;
    struct Object *marioObj = m->marioObj;
    s32 val0C = TRUE;
    s16 targetPitch = 0;
    f32 val04;

    val04 = m->intendedMag > m->forwardVel ? m->intendedMag : m->forwardVel;

    if (val04 < 4.0f) {
        val04 = 4.0f;
    }

    if (m->quicksandDepth > 50.0f) {
        val14 = (s32)(val04 / 4.0f * 0x10000);
        set_mario_anim_with_accel(m, MARIO_ANIM_MOVE_IN_QUICKSAND, val14);
        func_80263AD4(m, 19, 93);
        m->actionTimer = 0;
    } else {
        while (val0C) {
            switch (m->actionTimer) {
                case 0:
                    if (val04 > 8.0f) {
                        m->actionTimer = 2;
                    } else {
                        //! (Speed Crash) If Mario's speed is more than 2^17.
                        if ((val14 = (s32)(val04 / 4.0f * 0x10000)) < 0x1000) {
                            val14 = 0x1000;
                        }
                        set_mario_anim_with_accel(m, MARIO_ANIM_START_TIPTOE, val14);
                        func_80263AD4(m, 7, 22);
                        if (is_anim_past_frame(m, 23)) {
                            m->actionTimer = 2;
                        }

                        val0C = FALSE;
                    }
                    break;

                case 1:
                    if (val04 > 8.0f) {
                        m->actionTimer = 2;
                    } else {
                        //! (Speed Crash) If Mario's speed is more than 2^17.
                        if ((val14 = (s32)(val04 * 0x10000)) < 0x1000) {
                            val14 = 0x1000;
                        }
                        set_mario_anim_with_accel(m, MARIO_ANIM_TIPTOE, val14);
                        func_80263AD4(m, 14, 72);

                        val0C = FALSE;
                    }
                    break;

                case 2:
                    if (val04 < 5.0f) {
                        m->actionTimer = 1;
                    } else if (val04 > 22.0f) {
                        m->actionTimer = 3;
                    } else {
                        //! (Speed Crash) If Mario's speed is more than 2^17.
                        val14 = (s32)(val04 / 4.0f * 0x10000);
                        set_mario_anim_with_accel(m, MARIO_ANIM_WALKING, val14);
                        func_80263AD4(m, 10, 49);

                        val0C = FALSE;
                    }
                    break;

                case 3:
                    if (val04 < 18.0f) {
                        m->actionTimer = 2;
                    } else {
                        //! (Speed Crash) If Mario's speed is more than 2^17.
                        val14 = (s32)(val04 / 4.0f * 0x10000);
                        set_mario_anim_with_accel(m, MARIO_ANIM_RUNNING, val14);
                        func_80263AD4(m, 9, 45);
                        targetPitch = func_80263A50(m);

                        val0C = FALSE;
                    }
                    break;
            }
        }
    }

    marioObj->oMarioWalkingPitch =
        (s16) approach_s32(marioObj->oMarioWalkingPitch, targetPitch, 0x800, 0x800);
    marioObj->header.gfx.angle[0] = marioObj->oMarioWalkingPitch;
}

void func_8026570C(struct MarioState *m) {
    s32 val0C;
    s32 val08 = TRUE;
    f32 val04;

    val04 = m->intendedMag > m->forwardVel ? m->intendedMag : m->forwardVel;

    if (val04 < 2.0f) {
        val04 = 2.0f;
    }

    while (val08) {
        switch (m->actionTimer) {
            case 0:
                if (val04 > 6.0f) {
                    m->actionTimer = 1;
                } else {
                    //! (Speed Crash) Crashes if Mario's speed exceeds or equals 2^15.
                    val0C = (s32)(val04 * 0x10000);
                    set_mario_anim_with_accel(m, MARIO_ANIM_SLOW_WALK_WITH_LIGHT_OBJ, val0C);
                    func_80263AD4(m, 12, 62);

                    val08 = FALSE;
                }
                break;

            case 1:
                if (val04 < 3.0f) {
                    m->actionTimer = 0;
                } else if (val04 > 11.0f) {
                    m->actionTimer = 2;
                } else {
                    //! (Speed Crash) Crashes if Mario's speed exceeds or equals 2^15.
                    val0C = (s32)(val04 * 0x10000);
                    set_mario_anim_with_accel(m, MARIO_ANIM_WALK_WITH_LIGHT_OBJ, val0C);
                    func_80263AD4(m, 12, 62);

                    val08 = FALSE;
                }
                break;

            case 2:
                if (val04 < 8.0f) {
                    m->actionTimer = 1;
                } else {
                    //! (Speed Crash) Crashes if Mario's speed exceeds or equals 2^16.
                    val0C = (s32)(val04 / 2.0f * 0x10000);
                    set_mario_anim_with_accel(m, MARIO_ANIM_RUN_WITH_LIGHT_OBJ, val0C);
                    func_80263AD4(m, 10, 49);

                    val08 = FALSE;
                }
                break;
        }
    }
}

void func_80265980(struct MarioState *m) {
    s32 val04 = (s32)(m->intendedMag * 0x10000);
    set_mario_anim_with_accel(m, MARIO_ANIM_WALK_WITH_HEAVY_OBJ, val04);
    func_80263AD4(m, 26, 79);
}

void func_802659E8(struct MarioState *m, Vec3f startPos) {
    s16 wallAngle;
    s16 dWallAngle;
    f32 dx = m->pos[0] - startPos[0];
    f32 dz = m->pos[2] - startPos[2];
    f32 movedDistance = sqrtf(dx * dx + dz * dz);
    //! (Speed Crash) If a wall is after moving 16384 distance, this crashes.
    s32 val04 = (s32)(movedDistance * 2.0f * 0x10000);

    if (m->forwardVel > 6.0f) {
        mario_set_forward_vel(m, 6.0f);
    }

    if (m->wall != NULL) {
        wallAngle = atan2s(m->wall->normal.z, m->wall->normal.x);
        dWallAngle = wallAngle - m->faceAngle[1];
    }

    if (m->wall == NULL || dWallAngle <= -0x71C8 || dWallAngle >= 0x71C8) {
        m->flags |= MARIO_UNKNOWN_31;
        set_mario_animation(m, MARIO_ANIM_PUSHING);
        func_80263AD4(m, 6, 18);
    } else {
        if (dWallAngle < 0) {
            set_mario_anim_with_accel(m, MARIO_ANIM_SIDESTEP_RIGHT, val04);
        } else {
            set_mario_anim_with_accel(m, MARIO_ANIM_SIDESTEP_LEFT, val04);
        }

        if (m->marioObj->header.gfx.unk38.animFrame < 20) {
            play_sound(SOUND_MOVING_TERRAIN_SLIDE + m->terrainSoundAddend, m->marioObj->header.gfx.cameraToObject);
            m->particleFlags |= PARTICLE_DUST;
        }

        m->actionState = 1;
        m->actionArg = wallAngle + 0x8000;
        m->marioObj->header.gfx.angle[1] = wallAngle + 0x8000;
        m->marioObj->header.gfx.angle[2] = find_floor_slope(m, 0x4000);
    }
}

void func_80265C28(struct MarioState *m, s16 startYaw) {
    struct MarioBodyState *val0C = m->marioBodyState;
    UNUSED struct Object *marioObj = m->marioObj;
    s16 animID = m->marioObj->header.gfx.unk38.animID;
    s16 dYaw;
    s16 val02;
    s16 val00;

    if (animID == MARIO_ANIM_WALKING || animID == MARIO_ANIM_RUNNING) {
        dYaw = m->faceAngle[1] - startYaw;
        //! (Speed Crash) These casts can cause a crash if (dYaw * forwardVel / 12) or
        //! (forwardVel * 170) exceed or equal 2^31.
        val02 = -(s16)(dYaw * m->forwardVel / 12.0f);
        val00 = (s16)(m->forwardVel * 170.0f);

        if (val02 > 0x1555) {
            val02 = 0x1555;
        }
        if (val02 < -0x1555) {
            val02 = -0x1555;
        }

        if (val00 > 0x1555) {
            val00 = 0x1555;
        }
        if (val00 < 0) {
            val00 = 0;
        }

        val0C->torsoAngle[2] = approach_s32(val0C->torsoAngle[2], val02, 0x400, 0x400);
        val0C->torsoAngle[0] = approach_s32(val0C->torsoAngle[0], val00, 0x400, 0x400);
        ;
    } else {
        val0C->torsoAngle[2] = 0;
        val0C->torsoAngle[0] = 0;
    }
}

void func_80265DBC(struct MarioState *m, s16 startYaw) {
    struct MarioBodyState *val0C = m->marioBodyState;
    struct Object *marioObj = m->marioObj;
    s16 dYaw = m->faceAngle[1] - startYaw;
    //! (Speed Crash) These casts can cause a crash if (dYaw * forwardVel / 12) or
    //! (forwardVel * 170) exceed or equal 2^31. Harder (if not impossible to do)
    //! while on a Koopa Shell making this less of an issue.
    s16 val04 = -(s16)(dYaw * m->forwardVel / 12.0f);
    s16 val02 = (s16)(m->forwardVel * 170.0f);

    if (val04 > 0x1800) {
        val04 = 0x1800;
    }
    if (val04 < -0x1800) {
        val04 = -0x1800;
    }

    if (val02 > 0x1000) {
        val02 = 0x1000;
    }
    if (val02 < 0) {
        val02 = 0;
    }

    val0C->torsoAngle[2] = approach_s32(val0C->torsoAngle[2], val04, 0x200, 0x200);
    val0C->torsoAngle[0] = approach_s32(val0C->torsoAngle[0], val02, 0x200, 0x200);
    val0C->headAngle[2] = -val0C->torsoAngle[2];

    marioObj->header.gfx.angle[2] = val0C->torsoAngle[2];
    marioObj->header.gfx.pos[1] += 45.0f;
}

s32 act_walking(struct MarioState *m) {
    Vec3f startPos;
    s16 startYaw = m->faceAngle[1];

    mario_drop_held_object(m);

    if (should_begin_sliding(m)) {
        return set_mario_action(m, ACT_BEGIN_SLIDING, 0);
    }

    if (m->input & INPUT_FIRST_PERSON) {
        return begin_braking_action(m);
    }

    if (m->input & INPUT_A_PRESSED) {
        return set_jump_from_landing(m);
    }

    if (check_ground_dive_or_punch(m)) {
        return TRUE;
    }

    if (m->input & INPUT_UNKNOWN_5) {
        return begin_braking_action(m);
    }

    if (analog_stick_held_back(m) && m->forwardVel >= 16.0f) {
        return set_mario_action(m, ACT_TURNING_AROUND, 0);
    }

    if (m->input & INPUT_Z_PRESSED) {
        return set_mario_action(m, ACT_CROUCH_SLIDE, 0);
    }

    m->actionState = 0;

    vec3f_copy(startPos, m->pos);
    update_walking_speed(m);

    switch (perform_ground_step(m)) {
        case GROUND_STEP_LEFT_GROUND:
            set_mario_action(m, ACT_FREEFALL, 0);
            set_mario_animation(m, MARIO_ANIM_GENERAL_FALL);
            break;

        case GROUND_STEP_NONE:
            func_802652F0(m);
            if (m->intendedMag - m->forwardVel > 16.0f) {
                m->particleFlags |= PARTICLE_DUST;
            }
            break;

        case GROUND_STEP_HIT_WALL:
            func_802659E8(m, startPos);
            m->actionTimer = 0;
            break;
    }

    check_ledge_climb_down(m);
    func_80265C28(m, startYaw);
    return FALSE;
}

s32 act_move_punching(struct MarioState *m) {
    if (should_begin_sliding(m)) {
        return set_mario_action(m, ACT_BEGIN_SLIDING, 0);
    }

    if (m->actionState == 0 && (m->input & INPUT_A_DOWN)) {
        return set_mario_action(m, ACT_JUMP_KICK, 0);
    }

    m->actionState = 1;

    mario_update_punch_sequence(m);

    if (m->forwardVel >= 0.0f) {
        apply_slope_decel(m, 0.5f);
    } else {
        if ((m->forwardVel += 8.0f) >= 0.0f) {
            m->forwardVel = 0.0f;
        }
        apply_slope_accel(m);
    }

    switch (perform_ground_step(m)) {
        case GROUND_STEP_LEFT_GROUND:
            set_mario_action(m, ACT_FREEFALL, 0);
            break;

        case GROUND_STEP_NONE:
            m->particleFlags |= PARTICLE_DUST;
            break;
    }

    return FALSE;
}

s32 act_hold_walking(struct MarioState *m) {
    if (m->heldObj->behavior == segmented_to_virtual(bhvJumpingBox)) {
        return set_mario_action(m, ACT_CRAZY_BOX_BOUNCE, 0);
    }

    if (m->marioObj->oInteractStatus & INT_STATUS_MARIO_DROP_OBJECT) {
        return drop_and_set_mario_action(m, ACT_WALKING, 0);
    }

    if (should_begin_sliding(m)) {
        return set_mario_action(m, ACT_HOLD_BEGIN_SLIDING, 0);
    }

    if (m->input & INPUT_B_PRESSED) {
        return set_mario_action(m, ACT_THROWING, 0);
    }

    if (m->input & INPUT_A_PRESSED) {
        return set_jumping_action(m, ACT_HOLD_JUMP, 0);
    }

    if (m->input & INPUT_UNKNOWN_5) {
        return set_mario_action(m, ACT_HOLD_DECELERATING, 0);
    }

    if (m->input & INPUT_Z_PRESSED) {
        return drop_and_set_mario_action(m, ACT_CROUCH_SLIDE, 0);
    }

    //m->intendedMag *= 0.4f;
    m->intendedMag *= 0.65f;

    update_walking_speed(m);

    switch (perform_ground_step(m)) {
        case GROUND_STEP_LEFT_GROUND:
            set_mario_action(m, ACT_HOLD_FREEFALL, 0);
            break;

        case GROUND_STEP_HIT_WALL:
            if (m->forwardVel > 16.0f) {
                mario_set_forward_vel(m, 16.0f);
            }
            break;
    }

    func_8026570C(m);

    if (0.65f * m->intendedMag - m->forwardVel > 10.0f) {
        m->particleFlags |= PARTICLE_DUST;
    }

    return FALSE;
}

s32 act_hold_heavy_walking(struct MarioState *m) {
    if (m->input & INPUT_B_PRESSED) {
        return set_mario_action(m, ACT_HEAVY_THROW, 0);
    }

    if (should_begin_sliding(m)) {
        return drop_and_set_mario_action(m, ACT_BEGIN_SLIDING, 0);
    }

    if (m->input & INPUT_UNKNOWN_5) {
        return set_mario_action(m, ACT_HOLD_HEAVY_IDLE, 0);
    }

    m->intendedMag *= 0.1f;

    update_walking_speed(m);

    switch (perform_ground_step(m)) {
        case GROUND_STEP_LEFT_GROUND:
            drop_and_set_mario_action(m, ACT_FREEFALL, 0);
            break;

        case GROUND_STEP_HIT_WALL:
            if (m->forwardVel > 10.0f) {
                mario_set_forward_vel(m, 10.0f);
            }
            break;
    }

    func_80265980(m);
    return FALSE;
}

s32 act_turning_around(struct MarioState *m) {
    if (m->input & INPUT_ABOVE_SLIDE) {
        return set_mario_action(m, ACT_BEGIN_SLIDING, 0);
    }

    if (m->input & INPUT_A_PRESSED) {
        return set_jumping_action(m, ACT_SIDE_FLIP, 0);
    }

    if (m->input & INPUT_UNKNOWN_5) {
        return set_mario_action(m, ACT_BRAKING, 0);
    }

    if (!analog_stick_held_back(m)) {
        return set_mario_action(m, ACT_WALKING, 0);
    }

    if (apply_slope_decel(m, 2.0f)) {
        return begin_walking_action(m, 8.0f, ACT_FINISH_TURNING_AROUND, 0);
    }

    play_sound(SOUND_MOVING_TERRAIN_SLIDE + m->terrainSoundAddend, m->marioObj->header.gfx.cameraToObject);

    adjust_sound_for_speed(m);

    switch (perform_ground_step(m)) {
        case GROUND_STEP_LEFT_GROUND:
            set_mario_action(m, ACT_FREEFALL, 0);
            break;

        case GROUND_STEP_NONE:
            m->particleFlags |= PARTICLE_DUST;
            break;
    }

    if (m->forwardVel >= 18.0f) {
        set_mario_animation(m, MARIO_ANIM_TURNING_PART1);
    } else {
        set_mario_animation(m, MARIO_ANIM_TURNING_PART2);
        if (is_anim_at_end(m)) {
            if (m->forwardVel > 0.0f) {
                begin_walking_action(m, -m->forwardVel, ACT_WALKING, 0);
            } else {
                begin_walking_action(m, 8.0f, ACT_WALKING, 0);
            }
        }
    }

    return FALSE;
}

s32 act_finish_turning_around(struct MarioState *m) {
    if (m->input & INPUT_ABOVE_SLIDE) {
        return set_mario_action(m, ACT_BEGIN_SLIDING, 0);
    }

    if (m->input & INPUT_A_PRESSED) {
        return set_jumping_action(m, ACT_SIDE_FLIP, 0);
    }

    update_walking_speed(m);
    set_mario_animation(m, MARIO_ANIM_TURNING_PART2);

    if (perform_ground_step(m) == GROUND_STEP_LEFT_GROUND) {
        set_mario_action(m, ACT_FREEFALL, 0);
    }

    if (is_anim_at_end(m)) {
        set_mario_action(m, ACT_WALKING, 0);
    }

    m->marioObj->header.gfx.angle[1] += 0x8000;
    return FALSE;
}

s32 act_braking(struct MarioState *m) {
    if (!(m->input & INPUT_FIRST_PERSON)
        && (m->input
            & (INPUT_NONZERO_ANALOG | INPUT_A_PRESSED | INPUT_OFF_FLOOR | INPUT_ABOVE_SLIDE))) {
        return check_common_action_exits(m);
    }

    if (apply_slope_decel(m, 2.0f)) {
        return set_mario_action(m, ACT_BRAKING_STOP, 0);
    }

    if (m->input & INPUT_B_PRESSED) {
        return set_mario_action(m, ACT_MOVE_PUNCHING, 0);
    }

    switch (perform_ground_step(m)) {
        case GROUND_STEP_LEFT_GROUND:
            set_mario_action(m, ACT_FREEFALL, 0);
            break;

        case GROUND_STEP_NONE:
            m->particleFlags |= PARTICLE_DUST;
            break;

        case GROUND_STEP_HIT_WALL:
            slide_bonk(m, ACT_BACKWARD_GROUND_KB, ACT_BRAKING_STOP);
            break;
    }

    play_sound(SOUND_MOVING_TERRAIN_SLIDE + m->terrainSoundAddend, m->marioObj->header.gfx.cameraToObject);
    adjust_sound_for_speed(m);
    set_mario_animation(m, MARIO_ANIM_SKID_ON_GROUND);
    return FALSE;
}

s32 act_decelerating(struct MarioState *m) {
    s32 val0C;
    s16 slopeClass = mario_get_floor_class(m);

    if (!(m->input & INPUT_FIRST_PERSON)) {
        if (should_begin_sliding(m)) {
            return set_mario_action(m, ACT_BEGIN_SLIDING, 0);
        }

        if (m->input & INPUT_A_PRESSED) {
            return set_jump_from_landing(m);
        }

        if (check_ground_dive_or_punch(m)) {
            return TRUE;
        }

        if (m->input & INPUT_NONZERO_ANALOG) {
            return set_mario_action(m, ACT_WALKING, 0);
        }

        if (m->input & INPUT_Z_PRESSED) {
            return set_mario_action(m, ACT_CROUCH_SLIDE, 0);
        }
    }

    if (update_decelerating_speed(m)) {
        return set_mario_action(m, ACT_IDLE, 0);
    }

    switch (perform_ground_step(m)) {
        case GROUND_STEP_LEFT_GROUND:
            set_mario_action(m, ACT_FREEFALL, 0);
            break;

        case GROUND_STEP_HIT_WALL:
            if (slopeClass == SURFACE_CLASS_VERY_SLIPPERY) {
                mario_bonk_reflection(m, TRUE);
            } else {
                mario_set_forward_vel(m, 0.0f);
            }
            break;
    }

    if (slopeClass == SURFACE_CLASS_VERY_SLIPPERY) {
        set_mario_animation(m, MARIO_ANIM_IDLE_HEAD_LEFT);
        play_sound(SOUND_MOVING_TERRAIN_SLIDE + m->terrainSoundAddend, m->marioObj->header.gfx.cameraToObject);
        adjust_sound_for_speed(m);
        m->particleFlags |= PARTICLE_DUST;
    } else {
        // (Speed Crash) Crashes if speed exceeds 2^17.
        if ((val0C = (s32)(m->forwardVel / 4.0f * 0x10000)) < 0x1000) {
            val0C = 0x1000;
        }

        set_mario_anim_with_accel(m, MARIO_ANIM_WALKING, val0C);
        func_80263AD4(m, 10, 49);
    }

    return FALSE;
}

s32 act_hold_decelerating(struct MarioState *m) {
    s32 val0C;
    s16 slopeClass = mario_get_floor_class(m);

    if (m->marioObj->oInteractStatus & INT_STATUS_MARIO_DROP_OBJECT) {
        return drop_and_set_mario_action(m, ACT_WALKING, 0);
    }

    if (should_begin_sliding(m)) {
        return set_mario_action(m, ACT_HOLD_BEGIN_SLIDING, 0);
    }

    if (m->input & INPUT_B_PRESSED) {
        return set_mario_action(m, ACT_THROWING, 0);
    }

    if (m->input & INPUT_A_PRESSED) {
        return set_jumping_action(m, ACT_HOLD_JUMP, 0);
    }

    if (m->input & INPUT_Z_PRESSED) {
        return drop_and_set_mario_action(m, ACT_CROUCH_SLIDE, 0);
    }

    if (m->input & INPUT_NONZERO_ANALOG) {
        return set_mario_action(m, ACT_HOLD_WALKING, 0);
    }

    if (update_decelerating_speed(m)) {
        return set_mario_action(m, ACT_HOLD_IDLE, 0);
    }

    m->intendedMag *= 0.4f;

    switch (perform_ground_step(m)) {
        case GROUND_STEP_LEFT_GROUND:
            set_mario_action(m, ACT_HOLD_FREEFALL, 0);
            break;

        case GROUND_STEP_HIT_WALL:
            if (slopeClass == SURFACE_CLASS_VERY_SLIPPERY) {
                mario_bonk_reflection(m, TRUE);
            } else {
                mario_set_forward_vel(m, 0.0f);
            }
            break;
    }

    if (slopeClass == SURFACE_CLASS_VERY_SLIPPERY) {
        set_mario_animation(m, MARIO_ANIM_IDLE_WITH_LIGHT_OBJ);
        play_sound(SOUND_MOVING_TERRAIN_SLIDE + m->terrainSoundAddend, m->marioObj->header.gfx.cameraToObject);
        adjust_sound_for_speed(m);
        m->particleFlags |= PARTICLE_DUST;
    } else {
        //! (Speed Crash) This crashes if Mario has more speed than 2^15 speed.
        if ((val0C = (s32)(m->forwardVel * 0x10000)) < 0x1000) {
            val0C = 0x1000;
        }

        set_mario_anim_with_accel(m, MARIO_ANIM_WALK_WITH_LIGHT_OBJ, val0C);
        func_80263AD4(m, 12, 62);
    }

    return FALSE;
}

s32 act_riding_shell_ground(struct MarioState *m) {
    /*06*/ s16 startYaw = m->faceAngle[1];

    if (m->input & INPUT_A_PRESSED) {
        return set_mario_action(m, ACT_RIDING_SHELL_JUMP, 0);
    }

    if (m->input & INPUT_Z_PRESSED) {
        mario_stop_riding_object(m);
        if (m->forwardVel < 24.0f) {
            mario_set_forward_vel(m, 24.0f);
        }
        return set_mario_action(m, ACT_CROUCH_SLIDE, 0);
    }

    update_shell_speed(m);
    set_mario_animation(m, m->actionArg == 0 ? MARIO_ANIM_START_RIDING_SHELL : MARIO_ANIM_RIDING_SHELL);

    switch (perform_ground_step(m)) {
        case GROUND_STEP_LEFT_GROUND:
            set_mario_action(m, ACT_RIDING_SHELL_FALL, 0);
            break;

        case GROUND_STEP_HIT_WALL:
            mario_stop_riding_object(m);
            play_sound(m->flags & MARIO_METAL_CAP ? SOUND_ACTION_METAL_BONK : SOUND_ACTION_BONK,
                       m->marioObj->header.gfx.cameraToObject);
            m->particleFlags |= PARTICLE_1;
            set_mario_action(m, ACT_BACKWARD_GROUND_KB, 0);
            break;
    }

    func_80265DBC(m, startYaw);
    if (m->floor->type == SURFACE_BURNING) {
        play_sound(SOUND_MOVING_RIDING_SHELL_LAVA, m->marioObj->header.gfx.cameraToObject);
    } else {
        play_sound(SOUND_MOVING_TERRAIN_RIDING_SHELL + m->terrainSoundAddend,
                   m->marioObj->header.gfx.cameraToObject);
    }

    adjust_sound_for_speed(m);
    return FALSE;
}

s32 act_crawling(struct MarioState *m) {
    s32 val04;

    if (should_begin_sliding(m)) {
        return set_mario_action(m, ACT_BEGIN_SLIDING, 0);
    }

    if (m->input & INPUT_FIRST_PERSON) {
        return set_mario_action(m, ACT_UNKNOWN_024, 0);
    }

    if (m->input & INPUT_A_PRESSED) {
        return set_jumping_action(m, ACT_JUMP, 0);
    }

    if (check_ground_dive_or_punch(m)) {
        return TRUE;
    }

    if (m->input & INPUT_UNKNOWN_5) {
        return set_mario_action(m, ACT_UNKNOWN_024, 0);
    }

    if (!(m->input & INPUT_Z_DOWN)) {
        return set_mario_action(m, ACT_UNKNOWN_024, 0);
    }

    m->intendedMag *= 0.1f;

    update_walking_speed(m);

    switch (perform_ground_step(m)) {
        case GROUND_STEP_LEFT_GROUND:
            set_mario_action(m, ACT_FREEFALL, 0);
            break;

        case GROUND_STEP_HIT_WALL:
            if (m->forwardVel > 10.0f) {
                mario_set_forward_vel(m, 10.0f);
            }
            //! Possibly unintended missing break

        case GROUND_STEP_NONE:
            func_80263C14(m);
            break;
    }

    val04 = (s32)(m->intendedMag * 2.0f * 0x10000);
    set_mario_anim_with_accel(m, MARIO_ANIM_CRAWLING, val04);
    func_80263AD4(m, 26, 79);
    return FALSE;
}

s32 act_burning_ground(struct MarioState *m) {
    if (m->input & INPUT_A_PRESSED) {
        return set_mario_action(m, ACT_BURNING_JUMP, 0);
    }

    m->marioObj->oMarioBurnTimer += 2;
    if (m->marioObj->oMarioBurnTimer > 160) {
        return set_mario_action(m, ACT_WALKING, 0);
    }

    if (m->waterLevel - m->floorHeight > 50.0f) {
        play_sound(SOUND_GENERAL_FLAME_OUT, m->marioObj->header.gfx.cameraToObject);
        return set_mario_action(m, ACT_WALKING, 0);
    }

    if (m->forwardVel < 8.0f) {
        m->forwardVel = 8.0f;
    }
    if (m->forwardVel > 48.0f) {
        m->forwardVel = 48.0f;
    }

    m->forwardVel = approach_f32(m->forwardVel, 32.0f, 4.0f, 1.0f);

    if (m->input & INPUT_NONZERO_ANALOG) {
        m->faceAngle[1] =
            m->intendedYaw - approach_s32((s16)(m->intendedYaw - m->faceAngle[1]), 0, 0x600, 0x600);
    }

    apply_slope_accel(m);

    if (perform_ground_step(m) == GROUND_STEP_LEFT_GROUND) {
        set_mario_action(m, ACT_BURNING_FALL, 0);
    }

    set_mario_anim_with_accel(m, MARIO_ANIM_RUNNING, (s32)(m->forwardVel / 2.0f * 0x10000));
    func_80263AD4(m, 9, 45);

    m->particleFlags |= PARTICLE_11;
    play_sound(SOUND_MOVING_LAVA_BURN, m->marioObj->header.gfx.cameraToObject);

    m->health -= 10;
    if (m->health < 0x100) {
        set_mario_action(m, ACT_STANDING_DEATH, 0);
    }

    m->marioBodyState->eyeState = MARIO_EYES_DEAD;
    return FALSE;
}

void func_80267814(struct MarioState *m) {
    s16 intendedDYaw = m->intendedYaw - m->faceAngle[1];
    m->marioBodyState->torsoAngle[0] = (s32)(5461.3335f * m->intendedMag / 32.0f * coss(intendedDYaw));
    m->marioBodyState->torsoAngle[2] = (s32)(-(5461.3335f * m->intendedMag / 32.0f * sins(intendedDYaw)));
}

void common_slide_action(struct MarioState *m, u32 endAction, u32 airAction, s32 animation) {
    Vec3f val14;

    vec3f_copy(val14, m->pos);
    play_sound(SOUND_MOVING_TERRAIN_SLIDE + m->terrainSoundAddend, m->marioObj->header.gfx.cameraToObject);

    adjust_sound_for_speed(m);

    switch (perform_ground_step(m)) {
        case GROUND_STEP_LEFT_GROUND:
            set_mario_action(m, airAction, 0);
            if (m->forwardVel < -50.0f || 50.0f < m->forwardVel) {
                play_sound(SOUND_MARIO_HOOHOO, m->marioObj->header.gfx.cameraToObject);
            }
            break;

        case GROUND_STEP_NONE:
            set_mario_animation(m, animation);
            func_80263C14(m);
            m->particleFlags |= PARTICLE_DUST;
            break;

        case GROUND_STEP_HIT_WALL:
            if (!mario_floor_is_slippery(m)) {
#ifdef VERSION_JP
                m->particleFlags |= PARTICLE_1;
#else
                if (m->forwardVel > 16.0f) {
                    m->particleFlags |= PARTICLE_1;
                }
#endif
                slide_bonk(m, ACT_GROUND_BONK, endAction);
            } else if (m->wall != NULL) {
                s16 wallAngle = atan2s(m->wall->normal.z, m->wall->normal.x);
                f32 slideSpeed = sqrtf(m->slideVelX * m->slideVelX + m->slideVelZ * m->slideVelZ);

                if ((slideSpeed *= 0.9) < 4.0f) {
                    slideSpeed = 4.0f;
                }

                m->slideYaw = wallAngle - (s16)(m->slideYaw - wallAngle) + 0x8000;

                m->vel[0] = m->slideVelX = slideSpeed * sins(m->slideYaw);
                m->vel[2] = m->slideVelZ = slideSpeed * coss(m->slideYaw);
            }

            func_80263C14(m);
            break;
    }
}

s32 common_slide_action_with_jump(struct MarioState *m, u32 stopAction, u32 jumpAction, u32 airAction,
                                  s32 animation) {
    if (m->actionTimer == 5) {
        if (m->input & INPUT_A_PRESSED) {
            return set_jumping_action(m, jumpAction, 0);
        }
    } else {
        m->actionTimer++;
    }

    if (update_sliding(m, 4.0f)) {
        return set_mario_action(m, stopAction, 0);
    }

    common_slide_action(m, stopAction, airAction, animation);
    return FALSE;
}

s32 act_butt_slide(struct MarioState *m) {
    s32 cancel = common_slide_action_with_jump(m, ACT_BUTT_SLIDE_STOP, ACT_JUMP, ACT_BUTT_SLIDE_AIR,
                                               MARIO_ANIM_SLIDE);
    func_80267814(m);
    return cancel;
}

s32 act_hold_butt_slide(struct MarioState *m) {
    s32 cancel;

    if (m->marioObj->oInteractStatus & INT_STATUS_MARIO_DROP_OBJECT) {
        return drop_and_set_mario_action(m, ACT_BUTT_SLIDE, 0);
    }

    cancel = common_slide_action_with_jump(m, ACT_UNKNOWN_03F, ACT_HOLD_JUMP, ACT_HOLD_BUTT_SLIDE_AIR,
                                           MARIO_ANIM_SLIDING_ON_BOTTOM_WITH_LIGHT_OBJ);
    func_80267814(m);
    return cancel;
}

s32 act_crouch_slide(struct MarioState *m) {
    s32 cancel;

    if (m->input & INPUT_ABOVE_SLIDE) {
        return set_mario_action(m, ACT_BUTT_SLIDE, 0);
    }

    if (m->actionTimer < 30) {
        m->actionTimer++;
        if (m->input & INPUT_A_PRESSED) {
            if (m->forwardVel > 10.0f) {
                return set_jumping_action(m, ACT_LONG_JUMP, 0);
            }
        }
    }

    if (m->input & INPUT_B_PRESSED) {
        if (m->forwardVel >= 10.0f) {
            return set_mario_action(m, ACT_SLIDE_KICK, 0);
        } else {
            return set_mario_action(m, ACT_MOVE_PUNCHING, 0x0009);
        }
    }

    if (m->input & INPUT_A_PRESSED) {
        return set_jumping_action(m, ACT_JUMP, 0);
    }

    if (m->input & INPUT_FIRST_PERSON) {
        return set_mario_action(m, ACT_BRAKING, 0);
    }

    cancel = common_slide_action_with_jump(m, ACT_CROUCHING, ACT_JUMP, ACT_FREEFALL,
                                           MARIO_ANIM_START_CROUCHING);
    return cancel;
}

s32 act_slide_kick_slide(struct MarioState *m) {
    if (m->input & INPUT_A_PRESSED) {
        return set_jumping_action(m, ACT_FORWARD_ROLLOUT, 0);
    }

    set_mario_animation(m, MARIO_ANIM_SLIDE_KICK);
    if (is_anim_at_end(m) && m->forwardVel < 1.0f) {
        return set_mario_action(m, ACT_SLIDE_KICK_SLIDE_STOP, 0);
    }

    update_sliding(m, 1.0f);
    switch (perform_ground_step(m)) {
        case GROUND_STEP_LEFT_GROUND:
            set_mario_action(m, ACT_FREEFALL, 2);
            break;

        case GROUND_STEP_HIT_WALL:
            mario_bonk_reflection(m, TRUE);
            m->particleFlags |= PARTICLE_1;
            set_mario_action(m, ACT_BACKWARD_GROUND_KB, 0);
            break;
    }

    play_sound(SOUND_MOVING_TERRAIN_SLIDE + m->terrainSoundAddend, m->marioObj->header.gfx.cameraToObject);
    m->particleFlags |= PARTICLE_DUST;
    return FALSE;
}

s32 stomach_slide_action(struct MarioState *m, u32 stopAction, u32 airAction, s32 animation) {
    if (m->actionTimer == 5) {
        if (!(m->input & INPUT_ABOVE_SLIDE) && (m->input & (INPUT_A_PRESSED | INPUT_B_PRESSED))) {
            return drop_and_set_mario_action(
                m, m->forwardVel >= 0.0f ? ACT_FORWARD_ROLLOUT : ACT_BACKWARD_ROLLOUT, 0);
        }
    } else {
        m->actionTimer++;
    }

    if (update_sliding(m, 4.0f)) {
        return set_mario_action(m, stopAction, 0);
    }

    common_slide_action(m, stopAction, airAction, animation);
    return FALSE;
}

s32 act_stomach_slide(struct MarioState *m) {
    s32 cancel = stomach_slide_action(m, ACT_STOMACH_SLIDE_STOP, ACT_FREEFALL, MARIO_ANIM_SLIDE_DIVE);
    return cancel;
}

s32 act_hold_stomach_slide(struct MarioState *m) {
    s32 cancel;

    if (m->marioObj->oInteractStatus & INT_STATUS_MARIO_DROP_OBJECT) {
        return drop_and_set_mario_action(m, ACT_STOMACH_SLIDE, 0);
    }

    cancel = stomach_slide_action(m, ACT_DIVE_PICKING_UP, ACT_HOLD_FREEFALL, MARIO_ANIM_SLIDE_DIVE);
    return cancel;
}

s32 act_dive_slide(struct MarioState *m) {
    if (!(m->input & INPUT_ABOVE_SLIDE) && (m->input & (INPUT_A_PRESSED | INPUT_B_PRESSED))) {
        return set_mario_action(m, m->forwardVel > 0.0f ? ACT_FORWARD_ROLLOUT : ACT_BACKWARD_ROLLOUT,
                                0);
    }

    play_mario_landing_sound_once(m, SOUND_ACTION_TERRAIN_BODY_HIT_GROUND);

    //! If the dive slide ends on the same frame that we pick up on object,
    // mario will not be in the dive slide action for the call to
    // mario_check_object_grab, and so will end up in the regular picking action,
    // rather than the picking up after dive action.

    if (update_sliding(m, 8.0f) && is_anim_at_end(m)) {
        mario_set_forward_vel(m, 0.0f);
        set_mario_action(m, ACT_STOMACH_SLIDE_STOP, 0);
    }

    if (mario_check_object_grab(m)) {
        mario_grab_used_object(m);
        m->marioBodyState->grabPos = GRAB_POS_LIGHT_OBJ;
        return TRUE;
    }

    common_slide_action(m, ACT_STOMACH_SLIDE_STOP, ACT_FREEFALL, MARIO_ANIM_DIVE);
    return FALSE;
}

s32 common_ground_knockback_action(struct MarioState *m, s32 animation, s32 arg2, s32 arg3, s32 arg4) {
    s32 val04;

    if (arg3) {
        play_mario_heavy_landing_sound_once(m, SOUND_ACTION_TERRAIN_BODY_HIT_GROUND);
    }

    if (arg4 > 0) {
        play_sound_if_no_flag(m, SOUND_MARIO_ATTACKED, MARIO_MARIO_SOUND_PLAYED);
    } else {
#ifdef VERSION_JP
        play_sound_if_no_flag(m, SOUND_MARIO_OOOF, MARIO_MARIO_SOUND_PLAYED);
#else
        play_sound_if_no_flag(m, SOUND_MARIO_OOOF2, MARIO_MARIO_SOUND_PLAYED);
#endif
    }

    if (m->forwardVel > 32.0f) {
        m->forwardVel = 32.0f;
    }
    if (m->forwardVel < -32.0f) {
        m->forwardVel = -32.0f;
    }

    val04 = set_mario_animation(m, animation);
    if (val04 < arg2) {
        apply_landing_accel(m, 0.9f);
    } else if (m->forwardVel >= 0.0f) {
        mario_set_forward_vel(m, 0.1f);
    } else {
        mario_set_forward_vel(m, -0.1f);
    }

    if (perform_ground_step(m) == GROUND_STEP_LEFT_GROUND) {
        if (m->forwardVel >= 0.0f) {
            set_mario_action(m, ACT_FORWARD_AIR_KB, arg4);
        } else {
            set_mario_action(m, ACT_BACKWARD_AIR_KB, arg4);
        }
    } else if (is_anim_at_end(m)) {
        if (m->health < 0x100) {
            set_mario_action(m, ACT_STANDING_DEATH, 0);
        } else {
            if (arg4 > 0) {
                m->invincTimer = 30;
            }
            set_mario_action(m, ACT_IDLE, 0);
        }
    }

    return val04;
}

s32 act_hard_backward_ground_kb(struct MarioState *m) {
    s32 val04 =
        common_ground_knockback_action(m, MARIO_ANIM_FALL_OVER_BACKWARDS, 0x2B, TRUE, m->actionArg);
    if (val04 == 0x2B && m->health < 0x100) {
        set_mario_action(m, ACT_DEATH_ON_BACK, 0);
    }

#ifndef VERSION_JP
    if (val04 == 0x36 && m->prevAction == ACT_SPECIAL_DEATH_EXIT) {
        play_sound(SOUND_MARIO_MAMA_MIA, m->marioObj->header.gfx.cameraToObject);
    }
#endif

    if (val04 == 0x45) {
        play_mario_landing_sound_once(m, SOUND_ACTION_TERRAIN_LANDING);
    }

    return FALSE;
}

s32 act_hard_forward_ground_kb(struct MarioState *m) {
    s32 val04 = common_ground_knockback_action(m, MARIO_ANIM_LAND_ON_STOMACH, 0x15, TRUE, m->actionArg);
    if (val04 == 0x17 && m->health < 0x100) {
        set_mario_action(m, ACT_DEATH_ON_STOMACH, 0);
    }

    return FALSE;
}

s32 act_backward_ground_kb(struct MarioState *m) {
    common_ground_knockback_action(m, MARIO_ANIM_BACKWARD_KB, 0x16, TRUE, m->actionArg);
    return FALSE;
}

s32 act_forward_ground_kb(struct MarioState *m) {
    common_ground_knockback_action(m, MARIO_ANIM_FORWARD_KB, 0x14, TRUE, m->actionArg);
    return FALSE;
}

s32 act_soft_backward_ground_kb(struct MarioState *m) {
    common_ground_knockback_action(m, MARIO_ANIM_SOFT_BACK_KB, 0x64, FALSE, m->actionArg);
    return FALSE;
}

s32 act_soft_forward_ground_kb(struct MarioState *m) {
    common_ground_knockback_action(m, MARIO_ANIM_SOFT_FRONT_KB, 0x64, FALSE, m->actionArg);
    return FALSE;
}

s32 act_ground_bonk(struct MarioState *m) {
    s32 val04 = common_ground_knockback_action(m, MARIO_ANIM_GROUND_BONK, 0x20, TRUE, m->actionArg);
    if (val04 == 0x20) {
        play_mario_landing_sound(m, SOUND_ACTION_TERRAIN_LANDING);
    }
    return FALSE;
}

s32 act_death_exit_land(struct MarioState *m) {
    s32 val04;

    apply_landing_accel(m, 0.9f);
    play_mario_heavy_landing_sound_once(m, SOUND_ACTION_TERRAIN_BODY_HIT_GROUND);

    val04 = set_mario_animation(m, MARIO_ANIM_FALL_OVER_BACKWARDS);

    if (val04 == 0x36) {
        play_sound(SOUND_MARIO_MAMA_MIA, m->marioObj->header.gfx.cameraToObject);
    }
    if (val04 == 0x44) {
        play_mario_landing_sound(m, SOUND_ACTION_TERRAIN_LANDING);
    }

    if (is_anim_at_end(m)) {
        set_mario_action(m, ACT_IDLE, 0);
    }

    return FALSE;
}

u32 common_landing_action(struct MarioState *m, s16 animation, u32 airAction) {
    u32 stepResult;

    if (m->input & INPUT_NONZERO_ANALOG) {
        apply_landing_accel(m, 0.98f);
    } else if (m->forwardVel >= 16.0f) {
        apply_slope_decel(m, 2.0f);
    } else {
        m->vel[1] = 0.0f;
    }

    stepResult = perform_ground_step(m);
    switch (stepResult) {
        case GROUND_STEP_LEFT_GROUND:
            set_mario_action(m, airAction, 0);
            break;

        case GROUND_STEP_HIT_WALL:
            set_mario_animation(m, MARIO_ANIM_PUSHING);
            break;
    }

    if (m->forwardVel > 16.0f) {
        m->particleFlags |= PARTICLE_DUST;
    }

    set_mario_animation(m, animation);
    play_mario_landing_sound_once(m, SOUND_ACTION_TERRAIN_LANDING);

    if (m->floor->type >= SURFACE_SHALLOW_QUICKSAND && m->floor->type <= SURFACE_MOVING_QUICKSAND) {
        m->quicksandDepth += (4 - m->actionTimer) * 3.5f - 0.5f;
    }

    return stepResult;
}

s32 common_landing_cancels(struct MarioState *m, struct LandingAction *landingAction,
                           s32 (*setAPressAction)(struct MarioState *, u32, u32)) {
    //! Everything here, incuding floor steepness, is checked before checking
    // if mario is actually on the floor. This leads to e.g. remote sliding.

    if (m->floor->normal.y < 0.2923717f) {
        return mario_push_off_steep_floor(m, landingAction->verySteepAction, 0);
    }

    m->doubleJumpTimer = landingAction->unk02;

    if (should_begin_sliding(m)) {
        return set_mario_action(m, landingAction->slideAction, 0);
    }

    if (m->input & INPUT_FIRST_PERSON) {
        return set_mario_action(m, landingAction->endAction, 0);
    }

    if (++m->actionTimer >= landingAction->numFrames) {
        return set_mario_action(m, landingAction->endAction, 0);
    }

    if (m->input & INPUT_A_PRESSED) {
        return setAPressAction(m, landingAction->aPressedAction, 0);
    }

    if (m->input & INPUT_OFF_FLOOR) {
        return set_mario_action(m, landingAction->offFloorAction, 0);
    }

    return FALSE;
}

s32 act_jump_land(struct MarioState *m) {

    if (common_landing_cancels(m, &sJumpLandAction, set_jumping_action)) {
        return TRUE;
    }

    common_landing_action(m, MARIO_ANIM_LAND_FROM_SINGLE_JUMP, ACT_FREEFALL);
    return FALSE;
}

s32 act_freefall_land(struct MarioState *m) {
    if (common_landing_cancels(m, &sFreefallLandAction, set_jumping_action)) {
        return TRUE;
    }

    common_landing_action(m, MARIO_ANIM_GENERAL_LAND, ACT_FREEFALL);
    return FALSE;
}

s32 act_side_flip_land(struct MarioState *m) {
    if (common_landing_cancels(m, &sSideFlipLandAction, set_jumping_action)) {
        return TRUE;
    }

    if (common_landing_action(m, MARIO_ANIM_SLIDEFLIP_LAND, ACT_FREEFALL) != GROUND_STEP_HIT_WALL) {
        m->marioObj->header.gfx.angle[1] += 0x8000;
    }
    return FALSE;
}

s32 act_hold_jump_land(struct MarioState *m) {
    if (m->marioObj->oInteractStatus & INT_STATUS_MARIO_DROP_OBJECT) {
        return drop_and_set_mario_action(m, ACT_JUMP_LAND_STOP, 0);
    }

    if (common_landing_cancels(m, &sHoldJumpLandAction, set_jumping_action)) {
        return TRUE;
    }

    common_landing_action(m, MARIO_ANIM_JUMP_LAND_WITH_LIGHT_OBJ, ACT_HOLD_FREEFALL);
    return FALSE;
}

s32 act_hold_freefall_land(struct MarioState *m) {
    if (m->marioObj->oInteractStatus & INT_STATUS_MARIO_DROP_OBJECT) {
        return drop_and_set_mario_action(m, ACT_FREEFALL_LAND_STOP, 0);
    }

    if (common_landing_cancels(m, &sHoldFreefallLandAction, set_jumping_action)) {
        return TRUE;
    }

    common_landing_action(m, MARIO_ANIM_FALL_LAND_WITH_LIGHT_OBJ, ACT_HOLD_FREEFALL);
    return FALSE;
}

s32 act_long_jump_land(struct MarioState *m) {
    if (!(m->input & INPUT_Z_DOWN)) {
        m->input &= ~INPUT_A_PRESSED;
    }

    if (common_landing_cancels(m, &sLongJumpLandAction, set_jumping_action)) {
        return TRUE;
    }

    if (!(m->input & INPUT_NONZERO_ANALOG)) {
        play_sound_if_no_flag(m, SOUND_MARIO_UH2_2, MARIO_MARIO_SOUND_PLAYED);
    }

    common_landing_action(m,
                          !m->marioObj->oMarioLongJumpIsSlow ? MARIO_ANIM_CROUCH_FROM_FAST_LONGJUMP
                                                             : MARIO_ANIM_CROUCH_FROM_SLOW_LONGJUMP,
                          ACT_FREEFALL);
    return FALSE;
}

s32 act_double_jump_land(struct MarioState *m) {
    if (common_landing_cancels(m, &sDoubleJumpLandAction, set_triple_jump_action)) {
        return TRUE;
    }
    common_landing_action(m, MARIO_ANIM_LAND_FROM_DOUBLE_JUMP, ACT_FREEFALL);
    return FALSE;
}

s32 act_triple_jump_land(struct MarioState *m) {
    m->input &= ~INPUT_A_PRESSED;

    if (common_landing_cancels(m, &sTripleJumpLandAction, set_jumping_action)) {
        return TRUE;
    }

    if (!(m->input & INPUT_NONZERO_ANALOG)) {
        play_sound_if_no_flag(m, SOUND_MARIO_HAHA, MARIO_MARIO_SOUND_PLAYED);
    }

    common_landing_action(m, MARIO_ANIM_TRIPLE_JUMP_LAND, ACT_FREEFALL);
    return FALSE;
}

s32 act_backflip_land(struct MarioState *m) {
    if (!(m->input & INPUT_Z_DOWN)) {
        m->input &= ~INPUT_A_PRESSED;
    }

    if (common_landing_cancels(m, &sBackflipLandAction, set_jumping_action)) {
        return TRUE;
    }

    if (!(m->input & INPUT_NONZERO_ANALOG)) {
        play_sound_if_no_flag(m, SOUND_MARIO_HAHA, MARIO_MARIO_SOUND_PLAYED);
    }

    common_landing_action(m, MARIO_ANIM_TRIPLE_JUMP_LAND, ACT_FREEFALL);
    return FALSE;
}

s32 quicksand_jump_land_action(struct MarioState *m, s32 animation1, s32 animation2, u32 endAction,
                               u32 airAction) {
    if (m->actionTimer++ < 6) {
        //m->quicksandDepth -= (7 - m->actionTimer) * 2.2f;
        m->quicksandDepth -= m->quicksandDepth / (7 - m->actionTimer);
        //if (m->quicksandDepth < 1.0f) {
        //    m->quicksandDepth = 1.1f;
        //}

        play_mario_jump_sound(m);
        set_mario_animation(m, animation1);
    } else {
        m->quicksandDepth = 0;
        if (m->actionTimer >= 13) {
            return set_mario_action(m, endAction, 0);
        }

        set_mario_animation(m, animation2);
    }

    apply_landing_accel(m, 0.95f);
    if (perform_ground_step(m) == GROUND_STEP_LEFT_GROUND) {
        set_mario_action(m, airAction, 0);
    }

    return FALSE;
}

s32 act_quicksand_jump_land(struct MarioState *m) {
    s32 cancel = quicksand_jump_land_action(m, MARIO_ANIM_SINGLE_JUMP, MARIO_ANIM_LAND_FROM_SINGLE_JUMP,
                                            ACT_JUMP_LAND_STOP, ACT_FREEFALL);
    return cancel;
}

s32 act_hold_quicksand_jump_land(struct MarioState *m) {
    s32 cancel = quicksand_jump_land_action(m, MARIO_ANIM_JUMP_WITH_LIGHT_OBJ,
                                            MARIO_ANIM_JUMP_LAND_WITH_LIGHT_OBJ, ACT_UNKNOWN_034,
                                            ACT_HOLD_FREEFALL);
    return cancel;
}


void moveTowardsPoint(struct MarioState *m) {
    Vec3f startPos;
    s16 startYaw = m->faceAngle[1];
    f32 z1, z2, x1, x2;
    z1 = m->pos[2]; z2 = sCurrentPoint.pos[2];
    x1 = m->pos[0]; x2 = sCurrentPoint.pos[0];

    m->faceAngle[1] = atan2s(z2 - z1, x2 - x1);
    m->intendedYaw = m->faceAngle[1];
    startYaw = m->faceAngle[1];
    m->intendedMag *= 1.0f;
    m->actionState = 0;
    vec3f_copy(startPos, m->pos);
    update_walking_speed(m);
    
    m->intendedYaw = m->faceAngle;

    switch (perform_ground_step(m)) {
        case GROUND_STEP_LEFT_GROUND:
            set_mario_action(m, ACT_FREEFALL, 0);
            set_mario_animation(m, MARIO_ANIM_GENERAL_FALL);
            grindInitTriggered = 0;
            break;

        case GROUND_STEP_NONE:
            func_802652F0(m);
            if(m->input & INPUT_Z_DOWN) {
                if(!(gGlobalTimer % 8)) {
                    m->particleFlags |= PARTICLE_1;
                } 
            }
            m->particleFlags |= PARTICLE_DUST;
            set_mario_animation(m, MARIO_ANIM_RIDING_SHELL);
            break;

        case GROUND_STEP_HIT_WALL:
            func_802659E8(m, startPos);
            m->actionTimer = 0;
            break;
    }

    perform_ground_step(m);
}

void setNextPoint(struct MarioState *m, s16 currentPath) {
    s16 grindTrajectoryRow;
    s16 compareAngle;
    f32 z1, z2, x1, x2;
    f32 smallestDist = 64000.0;
    sCurrentPoint = grindTrajectories[currentPath][0];
    
    for (grindTrajectoryRow = 0; grindTrajectoryRow < grindLengths[currentPath]; grindTrajectoryRow++) {
        f32 distBetweenTrajectories;
            CL_dist_between_points(m->pos, grindTrajectories[currentPath][grindTrajectoryRow].pos, &distBetweenTrajectories);
            if (distBetweenTrajectories < smallestDist && 
            (f32)(absf_2(m->pos[1] - grindTrajectories[currentPath][grindTrajectoryRow].pos[1]) / distBetweenTrajectories) < 1.0f) {
                f32 dx = grindTrajectories[currentPath][grindTrajectoryRow].pos[0] - m->pos[0];
                f32 dz = grindTrajectories[currentPath][grindTrajectoryRow].pos[2] - m->pos[2];
                compareAngle = atan2s(dz, dx);
                compareAngle = compareAngle - m->faceAngle[1];
                if (absi((s32)compareAngle) <= 0x6000) {
                    sCurrentPoint = grindTrajectories[currentPath][grindTrajectoryRow];
                    if (distBetweenTrajectories < 100.0f) {
                        vec3f_copy(m->pos, grindTrajectories[currentPath][grindTrajectoryRow].pos);
                        m->faceAngle[1] = grindTrajectories[currentPath][grindTrajectoryRow].forwardAngle;
                    } else
                        smallestDist = distBetweenTrajectories;
                }
            }
        }
    //moveTowardsPoint(m);
    z1 = m->pos[2]; z2 = sCurrentPoint.pos[2];
    x1 = m->pos[0]; x2 = sCurrentPoint.pos[0];
    if (absi((s16)sCurrentPoint.forwardAngle - (s16)atan2s(z2 - z1, x2 - x1)) >= 0x2000)
        grindForward = FALSE;
    else
        grindForward = TRUE;
}

s32 act_grind(struct MarioState *m) {
    s16 grindTrajectoryRow;
    f32 smallestDist;
    if (grindInitTriggered == 0) {
        setNextPoint(m, m->floor->force);
        grindInitTriggered = 1;
    }

    CL_dist_between_points(m->pos, sCurrentPoint.pos, &smallestDist);
    if (smallestDist < 50.0f) {
            if(!grindForward) {
                grindTrajectoryRow = sCurrentPoint.pointPrev;
                if (sCurrentPoint.pointPrev < 0) {
                    m->forwardVel *= 2;
                    grindInitTriggered = 0;
                    if (m->input & INPUT_Z_DOWN && sCurrentPoint.pointPrev != -2)
                        return set_mario_action(m, ACT_TRIPLE_JUMP, 0);
                    else
                        return set_mario_action(m, ACT_JUMP, 0);
                }
            } else {
                grindTrajectoryRow = sCurrentPoint.pointNext;
                if (sCurrentPoint.pointNext < 0) {
                    m->forwardVel *= 2;
                    grindInitTriggered = 0;
                    if (m->input & INPUT_Z_DOWN && sCurrentPoint.pointNext != -2)
                        return set_mario_action(m, ACT_TRIPLE_JUMP, 0);
                    else
                        return set_mario_action(m, ACT_JUMP, 0);
                }
            }
        vec3f_copy(m->pos, sCurrentPoint.pos);
        sCurrentPoint = grindTrajectories[m->floor->force][grindTrajectoryRow];
    }

    if (m->input & INPUT_Z_DOWN) {
        m->forwardVel = 35;
    } else {
        m->forwardVel = 25;
    }

    moveTowardsPoint(m);

    if (m->action == ACT_FREEFALL) {
        return FALSE;
    }
    if(gPlayer1Controller->buttonPressed & A_BUTTON) {
        m->forwardVel = m->forwardVel * 2;
        grindInitTriggered = 0;
        if (m->input & INPUT_Z_DOWN)
            return set_mario_action(m, ACT_TRIPLE_JUMP, 0);
        else
            return set_mario_action(m, ACT_JUMP, 0);
    }


    return FALSE;
}




s32 check_common_moving_cancels(struct MarioState *m) {
    if (m->pos[1] < m->waterLevel - 100) {
        return set_water_plunge_action(m);
    }

    if (!(m->action & ACT_FLAG_INVULNERABLE) && (m->input & INPUT_UNKNOWN_10)) {
        return drop_and_set_mario_action(m, ACT_UNKNOWN_026, 0);
    }

    if (m->input & INPUT_SQUISHED) {
        return drop_and_set_mario_action(m, ACT_SQUISHED, 0);
    }

    if (!(m->action & ACT_FLAG_INVULNERABLE)) {
        if (m->health < 0x100) {
            return drop_and_set_mario_action(m, ACT_STANDING_DEATH, 0);
        }
    }

    return FALSE;
}

s32 mario_execute_moving_action(struct MarioState *m) {
    s32 cancel;

    if (check_common_moving_cancels(m)) {
        return TRUE;
    }

    if (mario_update_quicksand(m, 0.75f)) {
        return TRUE;
    }

    if (m->action != ACT_GRIND && m->floor->type == SURFACE_FLOWING_WATER && m->floorHeight == m->pos[1]) {
        return set_mario_action(m, ACT_GRIND, 0);
    }

    /* clang-format off */
    switch (m->action) {
        case ACT_WALKING:                  cancel = act_walking(m);                  break;
        case ACT_HOLD_WALKING:             cancel = act_hold_walking(m);             break;
        case ACT_HOLD_HEAVY_WALKING:       cancel = act_hold_heavy_walking(m);       break;
        case ACT_TURNING_AROUND:           cancel = act_turning_around(m);           break;
        case ACT_FINISH_TURNING_AROUND:    cancel = act_finish_turning_around(m);    break;
        case ACT_BRAKING:                  cancel = act_braking(m);                  break;
        case ACT_RIDING_SHELL_GROUND:      cancel = act_riding_shell_ground(m);      break;
        case ACT_CRAWLING:                 cancel = act_crawling(m);                 break;
        case ACT_BURNING_GROUND:           cancel = act_burning_ground(m);           break;
        case ACT_DECELERATING:             cancel = act_decelerating(m);             break;
        case ACT_HOLD_DECELERATING:        cancel = act_hold_decelerating(m);        break;
        case ACT_BUTT_SLIDE:               cancel = act_butt_slide(m);               break;
        case ACT_STOMACH_SLIDE:            cancel = act_stomach_slide(m);            break;
        case ACT_HOLD_BUTT_SLIDE:          cancel = act_hold_butt_slide(m);          break;
        case ACT_HOLD_STOMACH_SLIDE:       cancel = act_hold_stomach_slide(m);       break;
        case ACT_DIVE_SLIDE:               cancel = act_dive_slide(m);               break;
        case ACT_MOVE_PUNCHING:            cancel = act_move_punching(m);            break;
        case ACT_CROUCH_SLIDE:             cancel = act_crouch_slide(m);             break;
        case ACT_SLIDE_KICK_SLIDE:         cancel = act_slide_kick_slide(m);         break;
        case ACT_HARD_BACKWARD_GROUND_KB:  cancel = act_hard_backward_ground_kb(m);  break;
        case ACT_HARD_FORWARD_GROUND_KB:   cancel = act_hard_forward_ground_kb(m);   break;
        case ACT_BACKWARD_GROUND_KB:       cancel = act_backward_ground_kb(m);       break;
        case ACT_FORWARD_GROUND_KB:        cancel = act_forward_ground_kb(m);        break;
        case ACT_SOFT_BACKWARD_GROUND_KB:  cancel = act_soft_backward_ground_kb(m);  break;
        case ACT_SOFT_FORWARD_GROUND_KB:   cancel = act_soft_forward_ground_kb(m);   break;
        case ACT_GROUND_BONK:              cancel = act_ground_bonk(m);              break;
        case ACT_DEATH_EXIT_LAND:          cancel = act_death_exit_land(m);          break;
        case ACT_JUMP_LAND:                cancel = act_jump_land(m);                break;
        case ACT_FREEFALL_LAND:            cancel = act_freefall_land(m);            break;
        case ACT_DOUBLE_JUMP_LAND:         cancel = act_double_jump_land(m);         break;
        case ACT_SIDE_FLIP_LAND:           cancel = act_side_flip_land(m);           break;
        case ACT_HOLD_JUMP_LAND:           cancel = act_hold_jump_land(m);           break;
        case ACT_HOLD_FREEFALL_LAND:       cancel = act_hold_freefall_land(m);       break;
        case ACT_TRIPLE_JUMP_LAND:         cancel = act_triple_jump_land(m);         break;
        case ACT_BACKFLIP_LAND:            cancel = act_backflip_land(m);            break;
        case ACT_QUICKSAND_JUMP_LAND:      cancel = act_quicksand_jump_land(m);      break;
        case ACT_HOLD_QUICKSAND_JUMP_LAND: cancel = act_hold_quicksand_jump_land(m); break;
        case ACT_LONG_JUMP_LAND:           cancel = act_long_jump_land(m);           break;
        case ACT_GRIND:                    cancel = act_grind(m);                    break;
    }
    /* clang-format on */

    if (!cancel && (m->input & INPUT_IN_WATER)) {
        m->particleFlags |= PARTICLE_10;
        m->particleFlags &= ~PARTICLE_DUST;
    }

    return cancel;
}
