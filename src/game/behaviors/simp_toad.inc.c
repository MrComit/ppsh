#include "game/camera.h"
#include "game/mario_actions_moving.h"

struct ObjectHitbox sChaseHitbox = {
    /* interactType:      */ INTERACT_DAMAGE,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 0,
    /* health:            */ 1,
    /* numLootCoins:      */ 0,
    /* radius:            */ 80,
    /* height:            */ 100,
    /* hurtboxRadius:     */ 80,
    /* hurtboxHeight:     */ 100,
};

Vec3f sMGStartingPos = {-28152.0f, -9700.0f, -8384.34f};
Vec3f sMGMinePos[7] = {
{-31247.85f, -9743.7f, -12724.79f},
{-31459.8f, -9743.7f, -15274.94f},
{-28518.55f, -9768.7f, -19209.34f},
{-22059.8f, -10002.5f, -17652.74f},
{-22059.8f, -9289.6f, -15391.99f},
{-22059.8f, -10002.5f, -12567.04f},
{-22059.8f, -9569.65f, -10306.74f},
};
Vec3f sMGMinePosHorizontal[2] = {
{-25172.85f, -9265.2f, -19225.79f},
{-25355.1f, -8568.35f, -8496.39f},
};

Vec3f sChaseRespawn[6] = {
{567.935f, 12834.6f, -15723.65f},
{-18051.6f, 10343.95f, -6433.55f},
{-19614.9f, 9468.2f, -16441.85f},
{-22738.35f, 8566.7f, -16615.35f},
{-24692.8f, 6866.9f, -8938.5f},
{-25830.3f, 4295.285f, -2237.575f},
};

f32 sDeathHeights[5] = {7843.95f, 7825.2f, 7223.1f, 5528.8f, 1780.41f};

u16 sAngleTable[5] = {0x0000, 0xC000, 0xC000, 0xC000, 0x0000};

struct ShadowCopy {
    Vec3f pos;
    u16 faceAngle;
    u16 filler;
};

#define CHASE_SIZE 50
struct ShadowCopy toadChase[CHASE_SIZE] = {
0, /*{{0, 0, 0}, 0, 0}, {{0, 0, 0}, 0, 0}, {{0, 0, 0}, 0, 0},
{{0, 0, 0}, 0, 0}, {{0, 0, 0}, 0, 0}, {{0, 0, 0}, 0, 0},
{{0, 0, 0}, 0, 0}, {{0, 0, 0}, 0, 0}, {{0, 0, 0}, 0, 0},
{{0, 0, 0}, 0, 0}, {{0, 0, 0}, 0, 0}, {{0, 0, 0}, 0, 0},
{{0, 0, 0}, 0, 0}, {{0, 0, 0}, 0, 0}, {{0, 0, 0}, 0, 0},
{{0, 0, 0}, 0, 0}, {{0, 0, 0}, 0, 0}, {{0, 0, 0}, 0, 0},
{{0, 0, 0}, 0, 0}, {{0, 0, 0}, 0, 0}, {{0, 0, 0}, 0, 0},
{{0, 0, 0}, 0, 0}, {{0, 0, 0}, 0, 0}, {{0, 0, 0}, 0, 0},
{{0, 0, 0}, 0, 0}, {{0, 0, 0}, 0, 0}, {{0, 0, 0}, 0, 0},
{{0, 0, 0}, 0, 0}, {{0, 0, 0}, 0, 0}, {{0, 0, 0}, 0, 0},
{{0, 0, 0}, 0, 0}, {{0, 0, 0}, 0, 0}, {{0, 0, 0}, 0, 0},
{{0, 0, 0}, 0, 0}, {{0, 0, 0}, 0, 0}, {{0, 0, 0}, 0, 0},
{{0, 0, 0}, 0, 0}, {{0, 0, 0}, 0, 0}, {{0, 0, 0}, 0, 0},
{{0, 0, 0}, 0, 0}, {{0, 0, 0}, 0, 0}, {{0, 0, 0}, 0, 0},
{{0, 0, 0}, 0, 0}, {{0, 0, 0}, 0, 0}, {{0, 0, 0}, 0, 0},*/
};


void gang_toad_npc(void) {
    switch (o->oAction) {
        case 0:
            BobombBuddyIdleLoop();
            break;

        case 2:
            BobombBuddyTurnToTalkLoop();
            break;

        case 3:
            if (CL_NPC_Dialog(o->oBehParams >> 24)) {
                o->oAction = 4;   
            }
            break;

        case 4:
            o->oOpacity = approach_s16_symmetric(o->oOpacity, 0, 15);
            if (o->oOpacity < 10)
                o->activeFlags = 0;
            break;
    }
}




void gang_toad_introduction(void) {
    struct MarioState *m = gMarioState;
    u32 flags;
    switch (o->oAction) {
        case 0:
            flags = save_file_get_flags();
            if (flags & 0x100)
                o->activeFlags = 0;
            if (m->pos[2] < 12800.0f && mario_ready_to_speak()) {
                save_file_set_flags(flags |= 0x100);
                o->oAction = 1;
                if (o->oDistanceToMario < 5000.0f)
                    o->oForwardVel = 50.0f;
                else
                    o->oForwardVel = 150.0f;
            }
            break;
        case 1:
            o->oPosY = find_floor_height(o->oPosX, o->oPosY + 200.0f, o->oPosZ);
            o->oMoveFlags |= OBJ_MOVE_ON_GROUND;
            set_mario_npc_dialog(1);
            CL_Move();
            o->oFaceAngleYaw = (o->oMoveAngleYaw = o->oAngleToMario);
            if (o->oDistanceToMario < 200.0f)  {
                o->oForwardVel = 0;
                o->oAction = 2;
            }
            break;
        case 2:
            if (set_mario_npc_dialog(1) == 2) {
                o->activeFlags |= 0x20; /* bit 5 */
                if (cutscene_object_with_dialog(CUTSCENE_DIALOG, o, DIALOG_065)
                    != 0) {
                    set_mario_npc_dialog(0);
                    o->activeFlags &= ~0x20; /* bit 5 */
                    o->oInteractStatus = 0;
                    o->oAction = 3;
                }
            }
            break;
        case 3:
            o->oOpacity = approach_s16_symmetric(o->oOpacity, 0, 25);
            if (o->oOpacity < 10)
                o->activeFlags = 0;
            break;
    }

    
}

void gang_toad_spawn_switches(void) {
    struct Object *obj;
    s32 i;
    for (i = 1; i < 6; i++) {
        obj = spawn_object(o, MODEL_SIMP_SMALL_SwITCH, bhvSimpSmallSwitch);
        vec3f_copy(&obj->oPosX, sChaseRespawn[i]);
    }
}

void gang_toad_perform_chase(void) {
    if (o->oFC != gRedSwitchesPushed) {
        o->oF4 -= 9;
        if (o->oF4 < 0)
            o->oF4 += CHASE_SIZE;
    }
    o->oFC = gRedSwitchesPushed;
    vec3f_copy(toadChase[o->oF4].pos, gMarioState->pos);
    toadChase[o->oF4].faceAngle = gMarioState->faceAngle[1];

    if (o->oTimer > CHASE_SIZE) {
        vec3f_copy(&o->oPosX, toadChase[o->oF8].pos);
        o->oFaceAngleYaw = toadChase[o->oF8].faceAngle;
    }

    if (++o->oF4 > CHASE_SIZE - 1)
        o->oF4 = 0;
    if (++o->oF8 > CHASE_SIZE - 1)
        o->oF8 = 0;

}

void gang_toad_chase(void) {
    struct Object *obj;
    s32 respawn;
    switch (o->oAction) {
        case 0:
            o->oInteractType = 0x40000000;
            o->oInteractStatus = 0;
            obj = obj_nearest_object_with_behavior(bhvChaseSwitch);
            if (obj != NULL && obj->oAction == 1) {
                o->oAction = 6;
                SetComitCutscene(60, 1, 5);
            }
            break;
        case 1:
            set_object_hitbox(o, &sChaseHitbox);
            o->oMoveAngleYaw = (o->oFaceAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x1000));
            if ((s16) o->oMoveAngleYaw == (s16) o->oAngleToMario)
                o->oAction = 2;
            break;
        case 2:
            if (CL_NPC_Dialog(o->oBehParams >> 24)) {
                o->oAction = 3;
                //vec3f_copy(toadChase[sizeof(toadChase)].pos, &o->oPosX);
            }
            break;
        case 3:
            o->oOpacity = approach_s16_symmetric(o->oOpacity, 0, 25);
            if (o->oOpacity < 10) {
                obj_disable();
                o->oF4 = 0;
                o->oF8 = 1;
                o->oFC = gRedSwitchesPushed;
                o->oAction = 4;
                vec3f_copy(&o->oPosX, gMarioState->pos);
                o->oFaceAngleYaw = gMarioState->faceAngle[1];
            }    
            break;
        case 4:
            gang_toad_perform_chase();
            if (o->oTimer > 30 && o->oOpacity < 255) {
                obj_enable();
                o->oOpacity = approach_s16_symmetric(o->oOpacity, 255, 25);
            }
            if (o->oTimer > sizeof(toadChase) / sizeof(toadChase[0]) && o->oInteractStatus & 0x8000) {
                o->oInteractStatus = 0;
                o->oAction = 5;
            }

            if (gMarioState->pos[1] < sDeathHeights[gRedSwitchesPushed])
                o->oAction = 5;
            break;
        case 5:
            if (gMarioState->health <= 0x280) {
                level_trigger_warp(gMarioState, WARP_OP_WARP_FLOOR);
                o->oAction = 0;
                vec3f_copy(&o->oPosX, &o->oHomeX);
                o->oFaceAngleYaw = 0x4000;
                obj = obj_nearest_object_with_behavior(bhvChaseSwitch);
                obj->header.gfx.scale[1] = 1.5f;
                obj->oAction = 0;
                while ((obj = obj_nearest_object_with_behavior(bhvSimpSmallSwitch)) != NULL)
                    obj->activeFlags = 0;
            } else {
                switch (o->oTimer) {
                    case 0:
                        play_transition(WARP_TRANSITION_FADE_INTO_CIRCLE, 0xC, 0x00, 0x00, 0x00);
                        break;
                    case 9:
                        vec3f_copy(gMarioState->pos, sChaseRespawn[gRedSwitchesPushed]);
                        CL_set_camera_pos(sChaseRespawn[gRedSwitchesPushed]);
                        gMarioState->faceAngle[1] = sAngleTable[gRedSwitchesPushed];
                        s8DirModeYawOffset = (s16)(sAngleTable[gRedSwitchesPushed] & 0xC000) - 0x8000;
                        set_mario_action(gMarioState, ACT_JUMP_LAND_STOP, 0);
                        break;
                    case 12:
                        play_transition(WARP_TRANSITION_FADE_FROM_COLOR, 5, 0x00, 0x00, 0x00);
                        gMarioState->hurtCounter = 8;
                        o->oAction = 3;
                        break;
                }
            }
            break;
        case 6:
            if (CheckComitCutsceneEnd())
                o->oAction = 1;
            if (o->oTimer == 30) {
                gang_toad_spawn_switches();
                play_puzzle_jingle();
            }
            break;
    }
    if (gRedSwitchesPushed >= 5) {
        o->activeFlags = 0;
        obj = obj_nearest_object_with_behavior(bhvFadingWarp);
        vec3f_copy(&obj->oPosX, gMarioState->pos);
    }
}

void bhv_gang_toad_init(void) {
    o->oOpacity = 255;
    o->oInteractionSubtype = INT_SUBTYPE_NPC;
}


void bhv_gang_toad_loop(void) {
    switch (o->oBehParams2ndByte) {
        case 0:
            gang_toad_npc();
            break;
        case 1:
            gang_toad_introduction();
            break;
        case 2:
            gang_toad_chase();
            break;
    }
}


void spawn_simp_mines(void) {
    s32 i;
    struct Object *mine;
    for (i = 0; i < 7; i++) {
        mine = spawn_object(o, MODEL_SIMP_MINE, bhvSimpBomb);
        vec3f_copy(&mine->oPosX, sMGMinePos[i]);
    }
    for (i = 0; i < 2; i++) {
        mine = spawn_object(o, MODEL_SIMP_MINE, bhvSimpBomb);
        vec3f_copy(&mine->oPosX, sMGMinePosHorizontal[i]);
        mine->oBehParams2ndByte = 1;
    }
}


void bhv_simp_mg_toad_loop(void) {
s32 dialogResponse;
struct MarioState *m = gMarioState;
struct Object *star;

    switch (o->oAction) {
        case 0:
            BobombBuddyIdleLoop();
            break;
        case 1:
            dialogResponse = obj_update_dialog_with_cutscene(1, DIALOG_UNK2_LEAVE_TIME_STOP_ENABLED, 
                                                            CUTSCENE_RACE_DIALOG, o->oBehParams2ndByte);
            // 1 = yes, 2 = no
            if (dialogResponse == 2) {
                set_mario_npc_dialog(0);
                disable_time_stop_including_mario();
                o->oAction = 0;
            } else if (dialogResponse == 1) {
                set_mario_npc_dialog(0);
                disable_time_stop_including_mario();
                play_transition(1, 0xA, 0, 0, 0);
                spawn_simp_mines();
                m->healCounter = 32;
                o->oAction = 3;
                o->oInteractType = 0x40000000;
            }
            break;
        case 2:
            //BobombBuddyTurnToTalkLoop();
            PlaySound2(SOUND_ACTION_READ_SIGN);
            o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x1000);
            if ((s16) o->oMoveAngleYaw == (s16) o->oAngleToMario) {
                o->oAction = 1;
            }
            break;
        case 3:
            if (o->oTimer > 10) {
                vec3f_copy(m->pos, sMGStartingPos);
                m->faceAngle[1] = 0xC000;
                m->forwardVel = 0;
                m->vel[0] = 0;
                m->vel[1] = 0;
                m->vel[2] = 0;
                s8DirModeYawOffset = 0x4000;
                set_mario_action(m, ACT_CUTSCENE_JUMP, 0);
            }
            if (o->oTimer > 15) {
                play_transition(0, 0x5, 0, 0, 0);
                o->oAction = 4;
            }
            break;
        case 4:
            grindForward = TRUE;
            switch (o->oKoopaAction) {
                case 0:
                    if (m->floor != NULL && m->floor->force == 0x14 && m->action == ACT_GRIND) {
                        o->oKoopaRunAngleX++;
                        o->oKoopaAction = 1;
                        play_sound(SOUND_GENERAL2_RIGHT_ANSWER, gDefaultSoundArgs);
                    }
                    break;
                case 1:
                    if (m->floor != NULL && m->floor->force == 0x15 && m->action == ACT_GRIND)
                        o->oKoopaAction = 2;
                    break;
                case 2:
                    if (m->floor != NULL && m->floor->force == 0x16 && m->action == ACT_GRIND)
                        o->oKoopaAction = 3;
                    break;
                case 3:
                    if (m->floor != NULL && m->floor->force == 0x17 && m->action == ACT_GRIND) {
                        o->oKoopaAction = 0;
                    }
                    break;
            }
            print_text_fmt_int(20, 20, "LAP %d", o->oKoopaRunAngleX);
            if (o->oKoopaRunAngleX > 3) {
                o->oAction = 5;
            }
            if (m->floorHeight >= m->pos[1] && m->floor->type != SURFACE_FLOWING_WATER)
                o->oAction = 7;
            break;
        case 5:
            o->oKoopaRunAngleX = 0;
            m->healCounter = 32;
            star = create_star(-29950.6f, -10421.55f, -16314.35f);
            star->oBehParams = 0x1F << 24;
            o->oAction = 6;
            break;
        case 6:
            break;
        case 7:
            print_text_fmt_int(20, 20, "LAP %d", o->oKoopaRunAngleX);
            if (m->health <= 0x180) {
                level_trigger_warp(m, WARP_OP_WARP_FLOOR);
                o->oAction = 0;
                o->oInteractType = 0x00800000;
                o->oKoopaRunAngleX = 0;
                o->oKoopaAction = 0;
            } else {
                o->oAction = 8;
            }
            break;
        case 8:
            print_text_fmt_int(20, 20, "LAP %d", o->oKoopaRunAngleX);
            switch (o->oTimer) {
                case 0:
                    play_transition(WARP_TRANSITION_FADE_INTO_CIRCLE, 0xC, 0x00, 0x00, 0x00);
                    break;
                case 9:
                    grindInitTriggered = 0;
                    o->oKoopaAction = 1;
                    vec3f_copy(m->pos, sMGStartingPos);
                    s8DirModeYawOffset = 0x4000;
                    m->faceAngle[1] = 0xC000;
                    m->forwardVel = 0;
                    m->vel[0] = 0;
                    m->vel[1] = 0;
                    m->vel[2] = 0;
                    set_mario_action(m, ACT_CUTSCENE_JUMP, 0);
                    break;
                case 12:
                    play_transition(WARP_TRANSITION_FADE_FROM_COLOR, 5, 0x00, 0x00, 0x00);
                    m->hurtCounter = 4;
                    o->oAction = 4;
                    break;
            }
            break;
    }

o->oInteractStatus = 0;
}



void bhv_simp_mine_loop(void) {
    struct Object *toad;
    toad = obj_nearest_object_with_behavior(bhvSimpMGToad);
    if (are_objects_collided(o, gMarioObject)) {
        toad->oAction = 7;
        o->oInteractStatus &= ~INT_STATUS_INTERACTED; /* bit 15 */
        spawn_object(o, MODEL_EXPLOSION, bhvExplosion);
        o->activeFlags = 0;
    }
    if (toad->oAction == 6 || toad->oAction == 0)
        o->activeFlags = 0;

    if (o->oBehParams2ndByte == 0)
        o->oPosY = o->oHomeY + (sins(o->oHomingAmpLockedOn) * 300.0f);
    else
        o->oPosZ = o->oHomeZ + (sins(o->oHomingAmpLockedOn) * 300.0f);
    o->oHomingAmpLockedOn += 0x300;
    o->oFaceAngleYaw += o->oAngleVelYaw;
    o->oFaceAngleRoll += o->oAngleVelRoll;
    o->oFaceAnglePitch += o->oAngleVelPitch;
    switch (o->oAction) {
        case 0:
            o->oAmpYPhase = CL_RandomMinMaxU16(20, 80);
            o->oAngleVelYaw = CL_RandomMinMaxU16(0x40, 0x100);
            o->oAngleVelRoll = CL_RandomMinMaxU16(0x40, 0x100);
            o->oAngleVelPitch = CL_RandomMinMaxU16(0x40, 0x100);
            o->oAction = 1;
            break;
        case 1:
            if (o->oTimer > o->oAmpYPhase)
                o->oAction = 0;
            break;
    }
}