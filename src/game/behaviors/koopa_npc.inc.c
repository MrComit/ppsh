#include "game/camera.h"
#include "include/sm64.h"

s8 gKoopaSaved = 0;


void bhv_koopa_npc_init(void) {
    if ((o->oBehParams >> 24 & 0xFF) == 3) {
        o->oKoopaRunAngleZ = 930;
    }
    o->oKoopaAction = 0;
    o->oInteractType = 0x00800000;

}


void bhv_koopa_npc_loop(void) {
struct Object *pswitch;
s8 koopaType = o->oBehParams >> 24 & 0xFF;

    switch(koopaType) {
        case 0:
            bhv_bobomb_buddy_loop();
            break;
        case 1:
            pswitch = obj_nearest_object_with_behavior(bhvFloorSwitchGrills);
            if (pswitch == NULL){
                o->activeFlags = 0;
            } else if (pswitch->oAction == 2) {
                o->oBehParams2ndByte = 2;
            }
            bhv_bobomb_buddy_loop();
            break;
        case 2:
            koopa_the_wimp_loop();
            break;
        case 3:
            koopa_the_sick_loop();
            break;
        case 4:
            koopa_the_mechanic_loop();
            break;
        case 5:
            break;
    }

}


void koopa_the_wimp_loop(void) {
    struct Object *obj;
    s32 numPorcupuffers;
    switch (o->oKoopaAction) {
        case 0:
            o->oInteractType = 0x40000000;
            if (gKoopaSaved == 1) {
                o->oKoopaAction = 1;
                break;
            }
            set_obj_animation_and_sound_state(3);
            o->oPosX = o->oHomeX + sins(o->oKoopaRunAngleX) * 200.0f;
            o->oPosZ = o->oHomeZ + coss(o->oKoopaRunAngleX) * 400.0f;
            o->oMoveAngleYaw = o->oKoopaRunAngleX + 0x4000;
            o->oKoopaRunAngleX += 0x300;
            numPorcupuffers = count_objects_with_behavior(bhvPorcupuffer);
            if (numPorcupuffers == 0) {
                gKoopaSaved = 1;
                o->oKoopaAction = 1;
                //play_puzzle_jingle();
                obj = create_star(-775.0f, -2091.0f, -8958.0f);
                obj->oBehParams = 0x05 << 24;
                o->oInteractType = 0x00800000;
                set_obj_animation_and_sound_state(7);
            }
            break;
        case 1:
            bhv_bobomb_buddy_loop();
            //if (o->oAction == 2) {
            //    o->oKoopaAction = 2;
            //}

            break;
        case 2:
            if (o->oAction == 0) {
                o->oInteractType = 0x40000000;
                o->oKoopaAction = 3;
            }
            bhv_bobomb_buddy_loop();
            break;
        case 3:
            break;
    }
    o->oDrawingDistance = 0x1000;
}

void koopa_the_sick_loop(void) {
    s32 dialogResponse;
    struct Object *arrow;
    ObjRandomBlink(&o->oBobombBuddyBlinkTimer);

    switch (o->oAction) {
        case 0:
            BobombBuddyIdleLoop();
            o->oKoopaAction = 0;
            break;
        case 2:
            //BobombBuddyTurnToTalkLoop();
            PlaySound2(SOUND_ACTION_READ_SIGN);
            o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x1000);
            if ((s16) o->oMoveAngleYaw == (s16) o->oAngleToMario) {
                o->oAction = 1;
            }
            o->oKoopaAction = 0;
            break;
        case 1:
            o->oKoopaAction = 0;
            dialogResponse = obj_update_dialog_with_cutscene(1, DIALOG_UNK2_LEAVE_TIME_STOP_ENABLED, CUTSCENE_RACE_DIALOG, o->oBehParams2ndByte);
            // 1 = yes, 2 = no
            if (dialogResponse == 2) {
                set_mario_npc_dialog(0);
                disable_time_stop_including_mario();
                o->oAction = 0;
            } else if (dialogResponse == 1) {
                play_transition(1, 0x14, 0, 0, 0);
                o->oAction = 3;
            }
            break;
        case 3:
            if (o->oTimer > 20) {
                o->oKoopaAction = 1;
                gMarioState->pos[0] = 12934.0f;
                gMarioState->pos[1] = -1554.0f;
                gMarioState->pos[2] = 621.0f;
                gMarioState->faceAngle[1] = 0;
                gMarioState->action = ACT_WATER_IDLE;
                //gCamera->pos[0] = 12866.0f;
                set_r_button_camera(gCamera);
                gCamera->pos[1] = -1754.0f;
                //gCamera->pos[2] = 621.0f;
                s8DirModeYawOffset = 0x7000;
                //gUnderwaterCam = TRUE;
            }
            if (o->oTimer > 30) {
                play_transition(0, 0x5, 0, 0, 0);
                spawn_object(o, MODEL_ARROW_HEAD, bhvArrowForWaterRings);
                //gUnderwaterCam = TRUE;
                o->oAction = 4;
                o->oInteractType = 0x40000000;
            }
            break;
        case 4:
            gMarioState->pos[0] = 12934.0f;
            gMarioState->pos[1] = -1554.0f;
            gMarioState->pos[2] = 621.0f;

            if (o->oTimer == 25 || o->oTimer == 50 || o->oTimer == 75) {
                play_sound(SOUND_GENERAL2_SWITCH_TICK_SLOW, gDefaultSoundArgs);
            }

            if (o->oTimer > 100) {
                play_sound(SOUND_GENERAL2_RIGHT_ANSWER, gDefaultSoundArgs);
                o->oAction = 5;
            }      
            break;

        case 5:
            print_text_fmt_int(120, 210, "%d", o->oKoopaRunAngleZ / 30);
            if (o->oKoopaRunAngleZ < 1) {
                gMarioState->hurtCounter = 0xFF;
                //o->activeFlags = 0;
                o->oAction = 0;
                o->oInteractType = 0x00800000;
                o->oKoopaRunAngleZ = 930;
                o->oKoopaRunAngleX = 0;
                arrow = obj_nearest_object_with_behavior(bhvArrowForWaterRings);
                if (arrow != NULL)
                    arrow->activeFlags = 0;
                break;
            }
            if (o->oKoopaRunAngleX > 19/*count_objects_with_behavior(bhvMantaRayWaterRing) == 0*/) {
                o->oBehParams = (o->oBehParams << 8) >> 8;
                o->oBehParams |= 0x09 << 24;
                create_star(11797.0f, -369.0f, 3952.0f);
                o->oBehParams = (o->oBehParams << 8) >> 8;
                o->oBehParams |= 0x03 << 24;
                o->oKoopaAction = 0;
                o->oAction = 6;
                arrow = obj_nearest_object_with_behavior(bhvArrowForWaterRings);
                if (arrow != NULL)
                    arrow->activeFlags = 0;
            }
            o->oKoopaRunAngleZ--;
            break;
        case 6:
            break;
    }
o->oInteractStatus = 0;
    
}

void koopa_the_mechanic_loop(void) {

    switch (o->oKoopaAction) {
        case 0:
            bhv_bobomb_buddy_loop();
            if (o->oAction == 2) {
                o->oKoopaAction = 1;
            }
            break;
        case 1:
            bhv_bobomb_buddy_loop();
            if (o->oAction == 0) {
                o->oBehParams = (o->oBehParams << 8) >> 8;
                create_star(4019.0f, 2749.0f, -5656.0f);
                o->oBehParams |= 0x04 << 24;
                o->oInteractType = 0x40000000;
                o->oKoopaAction = 2;
            }
            break;
        case 2:
            break;
    }
}