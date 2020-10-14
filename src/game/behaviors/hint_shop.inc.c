#include "buffers/buffers.h"

u8 sVacantHints[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,};

void hint_toad_set_hint(s16 hint) {
    u16 hintFlags;
    switch (gCurrLevelNum) {
        case LEVEL_BOB:
            hintFlags = save_file_get_course_coin_score(gCurrSaveFileNum - 1, 2)
             + ((save_file_get_course_coin_score(gCurrSaveFileNum - 1, 3) & 0xF) << 8);

            hintFlags |= 1 << hint;
            gSaveBuffer.files[gCurrSaveFileNum - 1][0].courseCoinScores[2] = hintFlags & 0xFF;
            gSaveBuffer.files[gCurrSaveFileNum - 1][0].courseCoinScores[3] |= (hintFlags >> 8) & 0xF;
            gSaveFileModified = TRUE;
            break;
        case LEVEL_WF:
            hintFlags = ((save_file_get_course_coin_score(gCurrSaveFileNum - 1, 3) & 0xF0) >> 4)
             + (save_file_get_course_coin_score(gCurrSaveFileNum - 1, 4) << 4);

            hintFlags |= 1 << hint;
            gSaveBuffer.files[gCurrSaveFileNum - 1][0].courseCoinScores[3] |= (hintFlags & 0xF) << 4;
            gSaveBuffer.files[gCurrSaveFileNum - 1][0].courseCoinScores[4] = (hintFlags >> 4) & 0xFF;
            gSaveFileModified = TRUE;
            break;
        case LEVEL_JRB:
            hintFlags = save_file_get_course_coin_score(gCurrSaveFileNum - 1, 5)
             + ((save_file_get_course_coin_score(gCurrSaveFileNum - 1, 6) & 0xF) << 8);
            
            hintFlags |= 1 << hint;
            gSaveBuffer.files[gCurrSaveFileNum - 1][0].courseCoinScores[5] = hintFlags & 0xFF;
            gSaveBuffer.files[gCurrSaveFileNum - 1][0].courseCoinScores[6] |= (hintFlags >> 8) & 0xF;
            gSaveFileModified = TRUE;
            break;
    }
}


s32 hint_toad_dialog(s32 dialogId) {
    s16 dialogResponse;
    if (set_mario_npc_dialog(1) == 2) {
        dialogResponse = cutscene_object_with_dialog(CUTSCENE_RACE_DIALOG, o, dialogId);
        o->activeFlags |= 0x20; /* bit 5 */
        if (dialogResponse) {
            set_mario_npc_dialog(0);
            o->activeFlags &= ~0x20; /* bit 5 */
            o->oInteractStatus = 0;
        }
    }
    return dialogResponse;
}


void bhv_hint_shop_init(void) {
    u16 starFlags, hintFlags;
    switch (gCurrLevelNum) {
        case LEVEL_BOB:
            starFlags = save_file_get_star_flags(gCurrSaveFileNum - 1, 0)
             + ((save_file_get_star_flags(gCurrSaveFileNum - 1, 1) & 0xF) << 8);

            hintFlags = save_file_get_course_coin_score(gCurrSaveFileNum - 1, 2)
             + ((save_file_get_course_coin_score(gCurrSaveFileNum - 1, 3) & 0xF) << 8);
            break;
        case LEVEL_WF:
            starFlags = ((save_file_get_star_flags(gCurrSaveFileNum - 1, 1) & 0xF0) >> 4)
             + (save_file_get_star_flags(gCurrSaveFileNum - 1, 2) << 4);

            hintFlags = ((save_file_get_course_coin_score(gCurrSaveFileNum - 1, 3) & 0xF0) >> 4)
             + (save_file_get_course_coin_score(gCurrSaveFileNum - 1, 4) << 4);
            break;
        case LEVEL_JRB:
            starFlags = save_file_get_star_flags(gCurrSaveFileNum - 1, 3)
             + ((save_file_get_star_flags(gCurrSaveFileNum - 1, 4) & 0xF) << 8);

            hintFlags = save_file_get_course_coin_score(gCurrSaveFileNum - 1, 5)
             + ((save_file_get_course_coin_score(gCurrSaveFileNum - 1, 6) & 0xF) << 8);
            break;
    }
    o->oF4 = starFlags;
    o->oF8 = hintFlags;
    sVacantHints[0] = 0;
    sVacantHints[1] = 0;
    sVacantHints[2] = 0;
    sVacantHints[3] = 0;
    sVacantHints[4] = 0;
    sVacantHints[5] = 0;
    sVacantHints[6] = 0;
    sVacantHints[7] = 0;
    sVacantHints[8] = 0;
    sVacantHints[9] = 0;
    sVacantHints[10] = 0;
    sVacantHints[11] = 0;
}


void bhv_hint_shop_loop(void) {
    s16 i, dialogResponse, numHints, randomHint;
    switch (o->oAction) {
        case 0:
            if (o->oDistanceToMario < 1000.0f)
                o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x140);
            if (o->oInteractStatus == INT_STATUS_INTERACTED)
                o->oAction = 1;
            break;
        case 1:
            o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x1000);
            if ((s16) o->oMoveAngleYaw == (s16) o->oAngleToMario)
                o->oAction = 2;

            PlaySound2(SOUND_ACTION_READ_SIGN);
            break;
        case 2:
            dialogResponse = hint_toad_dialog(DIALOG_013);
            if (dialogResponse) {
                if (dialogResponse == 1) {
                    if (gMarioState->numCoins < 20) {
                        o->oAction = 3;
                    } else {
                        bhv_hint_shop_init();
                        for (i = 0, numHints = 0; i < 12; i++) {
                            if (!(o->oF4 & (1 << i)) && !(o->oF8 & (1 << i))) {
                                sVacantHints[numHints] = i;
                                numHints++;
                            }
                        }
                        if (numHints == 0) {
                            o->oAction = 4;
                        } else {
                            randomHint = CL_RandomMinMaxU16(0, numHints - 1);
                            hint_toad_set_hint(sVacantHints[randomHint]);
                            gMarioState->numCoins -= 20;
                            o->oAction = 5;

                        }
                    }
                } else if (dialogResponse == 2) {
                    o->oAction = 0;
                }
            }
            break;
        case 3:
            if (CL_NPC_Dialog(DIALOG_010)) {
                o->oAction = 0;
            }
            break;
        case 4:
            if (CL_NPC_Dialog(DIALOG_011)) {
                o->oAction = 0;
            }
            break;
        case 5:
            if (CL_NPC_Dialog(DIALOG_012)) {
                o->oAction = 0;
                bhv_hint_shop_init();
            }
            break;
    }
}


/*
    if you talk to him
        -bring up dialog
        -run the init to make sure its up to date
    if dialog response is yes
        -assemble list of all vacant star ids in current level (hint already bought = non vacant)
        -if you dont have 20 coins "sorry you cant afford this"
        -if you dont have any vacant star ids "there are no hints for you to buy!"
    if you can purchase a hint
        -"ok thank you for doing business"
        -subtracts 20 coins
        -set bit for hint bought (randomly selected from list)
        -run the init again to update stuff
*/