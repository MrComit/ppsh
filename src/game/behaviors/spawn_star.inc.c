#include "game/level_update.h"

// spawn_star.c.inc

static struct ObjectHitbox sCollectStarHitbox = {
    /* interactType:      */ INTERACT_STAR_OR_KEY,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 0,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 80,
    /* height:            */ 50,
    /* hurtboxRadius:     */ 0,
    /* hurtboxHeight:     */ 0,
};

static struct ObjectHitbox sCollectStarHitbox2 = {
    /* interactType:      */ INTERACT_STAR_OR_KEY,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 0,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 40,
    /* height:            */ 10,
    /* hurtboxRadius:     */ 0,
    /* hurtboxHeight:     */ 0,
};

void bhv_collect_star_init(void) {
    s8 sp1F;
    u8 sp1E;
    s32 CourseId = 1;

    sp1F = (o->oBehParams >> 24) & 0xFF;

    while (sp1F >= 8) {
        sp1F -= 8;
        CourseId++;;
    }

    sp1E = save_file_get_star_flags(gCurrSaveFileNum - 1, CourseId - 1);
    if (sp1E & (1 << sp1F)) {
        o->header.gfx.sharedChild = gLoadedGraphNodes[MODEL_TRANSPARENT_STAR];
    } else {
        o->header.gfx.sharedChild = gLoadedGraphNodes[MODEL_STAR];
    }

    if (!(obj_has_behavior(bhvStarNoRotate))) {
        set_object_hitbox(o, &sCollectStarHitbox);
    } else {
        set_object_hitbox(o, &sCollectStarHitbox2);
    }
}

void bhv_collect_star_loop(void) {
    if (!(obj_has_behavior(bhvStarNoRotate))) {
        o->oFaceAngleYaw += 0x800;
    }

    if (o->oInteractStatus & INT_STATUS_INTERACTED) {
        mark_obj_for_deletion(o);
        o->oInteractStatus = 0;
    }
}

void bhv_star_spawn_init(void) {
    o->oMoveAngleYaw = atan2s(o->oHomeZ - o->oPosZ, o->oHomeX - o->oPosX);
    o->oStarSpawnDisFromHome = sqrtf(sqr(o->oHomeX - o->oPosX) + sqr(o->oHomeZ - o->oPosZ));
    o->oVelY = (o->oHomeY - o->oPosY) / 30.0f;
    o->oForwardVel = o->oStarSpawnDisFromHome / 30.0f;
    o->oStarSpawnUnkFC = o->oPosY;
    if (o->oBehParams2ndByte == 0 || gCurrCourseNum == COURSE_BBH)
        cutscene_object(CUTSCENE_STAR_SPAWN, o);
    else
        cutscene_object(CUTSCENE_RED_COIN_STAR_SPAWN, o);

    set_time_stop_flags(TIME_STOP_ENABLED | TIME_STOP_MARIO_AND_DOORS);
    o->activeFlags |= 0x20;
    obj_become_intangible();
}

void bhv_star_spawn_loop(void) {
    switch (o->oAction) {
        case 0:
            o->oFaceAngleYaw += 0x1000;
            if (o->oTimer > 20)
                o->oAction = 1;
            break;

        case 1:
            obj_move_xyz_using_fvel_and_yaw(o);
            o->oStarSpawnUnkFC += o->oVelY;
            o->oPosY = o->oStarSpawnUnkFC + sins((o->oTimer * 0x8000) / 30) * 400.0f;
            o->oFaceAngleYaw += 0x1000;
            spawn_object(o, MODEL_NONE, bhvSparkleSpawn);
            PlaySound(SOUND_ENV_STAR);
            if (o->oTimer == 30) {
                o->oAction = 2;
                o->oForwardVel = 0;
                play_power_star_jingle(TRUE);
            }
            break;

        case 2:
            if (o->oTimer < 20)
                o->oVelY = 20 - o->oTimer;
            else
                o->oVelY = -10.0f;

            spawn_object(o, MODEL_NONE, bhvSparkleSpawn);
            obj_move_xyz_using_fvel_and_yaw(o);
            o->oFaceAngleYaw = o->oFaceAngleYaw - o->oTimer * 0x10 + 0x1000;
            PlaySound(SOUND_ENV_STAR);

            if (o->oPosY < o->oHomeY) {
                PlaySound2(SOUND_GENERAL_STAR_APPEARS);
                obj_become_tangible();
                o->oPosY = o->oHomeY;
                o->oAction = 3;
            }
            break;

        case 3:
            o->oFaceAngleYaw += 0x800;
            if (o->oTimer == 20) {
                gObjCutsceneDone = TRUE;
                clear_time_stop_flags(TIME_STOP_ENABLED | TIME_STOP_MARIO_AND_DOORS);
                o->activeFlags &= ~0x20;
            }

            if (o->oInteractStatus & INT_STATUS_INTERACTED) {
                mark_obj_for_deletion(o);
                o->oInteractStatus = 0;
            }
            break;
    }
}

struct Object *func_802F1A50(struct Object *sp30, f32 sp34, f32 sp38, f32 sp3C) {
    sp30 = spawn_object_abs_with_rot(o, 0, MODEL_STAR, bhvStarSpawnCoordinates, o->oPosX, o->oPosY,
                                     o->oPosZ, 0, 0, 0);
    sp30->oBehParams = o->oBehParams;
    sp30->oHomeX = sp34;
    sp30->oHomeY = sp38;
    sp30->oHomeZ = sp3C;
    sp30->oFaceAnglePitch = 0;
    sp30->oFaceAngleRoll = 0;
    return sp30;
}

struct Object *create_star(f32 sp20, f32 sp24, f32 sp28) {
    struct Object *sp1C;
    sp1C = func_802F1A50(sp1C, sp20, sp24, sp28);
    sp1C->oBehParams2ndByte = 0;
    return sp1C;
}

void func_802F1B84(f32 sp20, f32 sp24, f32 sp28) {
    struct Object *sp1C;
    sp1C = func_802F1A50(sp1C, sp20, sp24, sp28);
    sp1C->oBehParams2ndByte = 1;
}

void func_802F1BD4(f32 sp20, f32 sp24, f32 sp28) {
    struct Object *sp1C;
    sp1C = func_802F1A50(sp1C, sp20, sp24, sp28);
    sp1C->oBehParams2ndByte = 1;
    sp1C->oInteractionSubtype |= INT_SUBTYPE_NO_EXIT;
}

void bhv_hidden_red_coin_star_init(void) {
    s16 sp36;
    s16 sp362;
    struct Object *sp30;

    //if (gCurrCourseNum != 3)
    spawn_object(o, MODEL_TRANSPARENT_STAR, bhvRedCoinStarMarker);

    sp36 = count_objects_with_behavior(bhvRedCoin);
    sp362 = count_objects_with_behavior(bhvSpinningRCoin);
    sp36 += sp362;
    if (sp36 == 0) {
        sp30 =
            spawn_object_abs_with_rot(o, 0, MODEL_STAR, bhvStar, o->oPosX, o->oPosY, o->oPosZ, 0, 0, 0);
        sp30->oBehParams = o->oBehParams;
        o->activeFlags = 0;
    }

    o->oHiddenStarTriggerCounter = 10 - sp36;
}

void bhv_hidden_red_coin_star_loop(void) {
    //gRedCoinsCollected = o->oHiddenStarTriggerCounter;
    struct Object *sp1C;
    if (gCoinStarCollected) {
        o->activeFlags = 0;
        return;
    }

    /*if (gRedCoinsCollected != 8) {
        o->oTimer = 0;
    }
    if (o->oTimer > 2) {
        //func_802F1B84(o->oPosX, o->oPosY, o->oPosZ);
        sp1C = func_802F1A50(sp1C, o->oPosX, o->oPosY, o->oPosZ);
        sp1C->oBehParams2ndByte = 1;
        func_802A3004();
        //o->activeFlags = 0; 
    }*/

    switch (o->oAction) {
        case 0:
            if (gRedCoinsCollected == 8)
                o->oAction = 1;
            break;

        case 1:
            if (o->oTimer > 2) {
                sp1C = func_802F1A50(sp1C, o->oPosX, o->oPosY, o->oPosZ);
                sp1C->oBehParams2ndByte = 1;
                //o->activeFlags = 0;
                o->oAction = 2;
            }
            break;
        case 2:
            if (sp1C == NULL || sp1C->activeFlags == 0) {
                o->activeFlags = 0;
            }
            break;
    }
}



void bhv_bonus_star_loop(void) {
    u8 course0 = save_file_get_star_flags(gCurrSaveFileNum - 1, 0);
    u8 course1 = save_file_get_star_flags(gCurrSaveFileNum - 1, 1);
    u8 course2 = save_file_get_star_flags(gCurrSaveFileNum - 1, 2);
    u8 course3 = save_file_get_star_flags(gCurrSaveFileNum - 1, 3);
    u8 course4 = save_file_get_star_flags(gCurrSaveFileNum - 1, 4);
    if (course4 & 1 << ((o->oBehParams >> 24) - 32)) {
        o->activeFlags = 0;
        return;
    }
    switch (o->oBehParams2ndByte) {
        case 0:
            if (course0 == 0xFF && course1 & 0xF == 0xF) {
                create_star(o->oPosX, o->oPosY, o->oPosZ);
            }
            break;
        case 1:
            if (course1 & 0xF0 == 0xF0 && course2 == 0xFF) {
                create_star(o->oPosX, o->oPosY, o->oPosZ);
            }
            break;
        case 2:
            if (course3 & 0xFF == 0xFF && course4 & 0xF == 0xF) {
                    create_star(o->oPosX, o->oPosY, o->oPosZ);
            }
            break;
        case 3:
            if (course0 == 0xFF && course1 == 0xFF && course2 == 0xFF && course3 == 0xFF && course4 & 0xF == 0xF) {
                create_star(o->oPosX, o->oPosY, o->oPosZ);
            }
            break;
    }
    o->activeFlags = 0;
}