void bhv_hint_shop_init(void) {
    u16 starFlags, hintFlags;
    switch (gCurrLevelNum) {
        case LEVEL_BOB:
            starFlags = save_file_get_star_flags(gCurrSaveFileNum - 1, 0)
             + ((save_file_get_star_flags(gCurrSaveFileNum - 1, 1) & 0xF) << 8);

            hintFlags = save_file_get_course_coin_score(gCurrSaveFileNum - 1, 0)
             + ((save_file_get_course_coin_score(gCurrSaveFileNum - 1, 1) & 0xF) << 8);
            break;
        case LEVEL_WF:
            starFlags = ((save_file_get_star_flags(gCurrSaveFileNum - 1, 1) & 0xF0) >> 4)
             + (save_file_get_star_flags(gCurrSaveFileNum - 1, 2) << 4);

            hintFlags = ((save_file_get_course_coin_score(gCurrSaveFileNum - 1, 1) & 0xF0) >> 4)
             + (save_file_get_course_coin_score(gCurrSaveFileNum - 1, 2) << 4);
            break;
        case LEVEL_JRB:
            starFlags = save_file_get_star_flags(gCurrSaveFileNum - 1, 3)
             + ((save_file_get_star_flags(gCurrSaveFileNum - 1, 4) & 0xF) << 8);

            hintFlags = save_file_get_course_coin_score(gCurrSaveFileNum - 1, 3)
             + ((save_file_get_course_coin_score(gCurrSaveFileNum - 1, 4) & 0xF) << 8);
            break;
    }
    o->oF4 = starFlags;
    o->oF8 = hintFlags;
}


void bhv_hint_shop_loop(void) {



}


/*
    if dialog response is yes
        -assemble list of all vacant star ids in current level (hint already bought = non vacant)
        -if you dont have 20 coins "sorry you cant afford this"
        -if you dont have any vacant star ids "there are no hints for you to buy!"
    if you can purchase a hint
        -"ok thank you for doing business"
        -subtracts 20 coins
        -set bit for hint bought (randomly selected from list)
*/