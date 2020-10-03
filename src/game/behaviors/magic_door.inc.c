s16 sDoorStarCounts[3] = {5, 12, 20};
u32 sDoorUnlocks[3] = {SAVE_FLAG_UNLOCKED_PSS_DOOR, SAVE_FLAG_UNLOCKED_WF_DOOR, SAVE_FLAG_UNLOCKED_CCM_DOOR};

void bhv_magic_door_init(void) {
    u32 flags = save_file_get_flags();
    if (flags & sDoorUnlocks[o->oBehParams2ndByte])
        o->activeFlags = 0;
    o->oOpacity = 0xFF;
    o->oF4 = sDoorStarCounts[o->oBehParams2ndByte];
}


void bhv_magic_door_loop(void) {
    switch (o->oAction) {
        case 0:
            if (o->oDistanceToMario < 500.0f) {
                if (save_file_get_total_star_count(gCurrSaveFileNum - 1, COURSE_MIN - 1, COURSE_MAX - 1) >= o->oF4) {
                    play_sound(SOUND_GENERAL2_RIGHT_ANSWER, gDefaultSoundArgs);
                    save_file_set_flags(sDoorUnlocks[o->oBehParams2ndByte]);
                    o->oAction = 2;
                } else {
                    play_sound(SOUND_MENU_CAMERA_BUZZ, gDefaultSoundArgs);
                    o->oAction = 1;
                }
            }
            break;
        case 1:
            if (o->oDistanceToMario > 750.0f)
                o->oAction = 0;
            break;
        case 2:
            o->oOpacity = approach_s16_symmetric(o->oOpacity, 0, 10);
            if (o->oOpacity < 0x20)
                o->activeFlags = 0;
            break;
    }
}