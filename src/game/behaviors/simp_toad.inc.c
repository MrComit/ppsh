#include "game/camera.h"
#include "game/mario_actions_moving.h"

Vec3f sMGStartingPos = {-28152.0f, -9700.0f, -10980.0f};
Vec3f sMGMinePos[7] = {
{-31247.85f, -9743.7f, -15320.45f},
{-31459.8f, -9743.7f, -17870.6f},
{-28518.55f, -9768.7f, -21805.0f},
{-22059.8f, -10002.5f, -20248.4f},
{-22059.8f, -9289.6f, -17987.65f},
{-22059.8f, -10002.5f, -15162.7f},
{-22059.8f, -9569.65f, -12902.4f},
};
Vec3f sMGMinePosHorizontal[2] = {
{-25172.85f, -9265.2f, -21821.45f},
{-25355.1f, -8568.35f, -11092.05f},
};

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
            o->oAction = 6;
            break;
        case 6:
            break;
        case 7:
            print_text_fmt_int(20, 20, "LAP %d", o->oKoopaRunAngleX);
            if (m->health <= 0x180) {
                level_trigger_warp(m, WARP_OP_WARP_FLOOR);
                o->oAction = 0;
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
    if (toad->oAction == 6)
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