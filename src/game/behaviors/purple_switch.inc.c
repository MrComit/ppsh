/**
 * Behavior for bhvFloorSwitchHardcodedModel, bhvFloorSwitchGrills, and
 * bhvFloorSwitchAnimatesObject.
 *
 * This controls the purple switches that Mario can step on to affect parts of
 * the environment.
 */

u16 gRedSwitchesPushed = 0;

void bhv_purple_switch_init(void) {
    gRedSwitchesPushed = 0;
}


void bhv_purple_switch_loop(void) {
    switch (o->oAction) {
        /**
         * Set the switch's model and scale. If Mario is standing near the
         * switch's middle section, transition to the pressed state.
         */
        case PURPLE_SWITCH_IDLE:
            if (!obj_has_behavior(bhvCanyonButton) && !obj_has_behavior(bhvBlueCanyonButton) 
                && !obj_has_behavior(bhvRedCanyonButton) && !obj_has_behavior(bhvSimpSmallSwitch)) {
                //obj_set_model(MODEL_PURPLE_SWITCH);
                obj_scale(1.5f);
                if (gMarioObject->platform == o && !(gMarioStates->action & MARIO_UNKNOWN_13)) {
                    if (lateral_dist_between_objects(o, gMarioObject) < 127.5) {
                        o->oAction = PURPLE_SWITCH_PRESSED;
                    }
                }
            } else {
                if (gMarioObject->platform == o && !(gMarioStates->action & MARIO_UNKNOWN_13)) {
                    o->oAction = PURPLE_SWITCH_PRESSED;
                }
            }
            break;
        /**
         * Collapse the switch downward, play a sound, and shake the screen.
         * Immediately transition to the ticking state.
         */
        case PURPLE_SWITCH_PRESSED:
            func_802A3398(2, 3, 1.5f, 0.2f);
            if (o->oTimer == 3) {
                if (obj_has_behavior(bhvCanyonButton))
                    SetComitCutscene(180, 1, 1);
                if (obj_has_behavior(bhvRedCanyonButton) || obj_has_behavior(bhvSimpSmallSwitch)) {
                    gRedSwitchesPushed++;
                    play_sound(SOUND_MENU_COLLECT_SECRET + (((u8) gRedSwitchesPushed - 1) << 16), gDefaultSoundArgs);
                    if (gRedSwitchesPushed >=5) {
                        if (obj_has_behavior(bhvRedCanyonButton))
                            SetComitCutscene(180, 1, 2);
                        //else
                        //    SetComitCutscene(60, 1, 4);
                    }
                    else
                        spawn_orange_number(gRedSwitchesPushed, 0, 0, 0);
                }
                PlaySound2(SOUND_GENERAL2_PURPLE_SWITCH);
                o->oAction = PURPLE_SWITCH_TICKING;
                ShakeScreen(SHAKE_POS_SMALL);
            }
            break;
        /**
         * Play a continuous ticking sound that gets faster when time is almost
         * up. When time is up, move to a waiting-while-pressed state.
         */
        case PURPLE_SWITCH_TICKING:
            if (o->oTimer > 180) {
                if (obj_has_behavior(bhvCanyonButton)) {
                    create_star(o->oPosX, o->oPosY + 300.0f, o->oPosZ);
                    o->oAction = 5;
                }
            }
            if (obj_has_behavior(bhvRedCanyonButton)) {
                if (gRedSwitchesPushed >= 5)
                    o->oAction = 6;
                else
                    o->oAction = 5;

            } else if (obj_has_behavior(bhvSimpSmallSwitch)) {
                if (gRedSwitchesPushed >= 5) {
                    gRedSwitchesPushed = 0;
                }
                    o->oAction = 5;
            }

            if (obj_has_behavior(bhvTimedCarSwitch)) {
                if (o->oTimer < 750) {
                    if (o->oTimer > 60)
                        play_sound(SOUND_GENERAL2_SWITCH_TICK_FAST, gDefaultSoundArgs);
                } else {
                    play_sound(SOUND_GENERAL2_SWITCH_TICK_SLOW, gDefaultSoundArgs);
                }
                if (o->oTimer > 810) {
                    o->oAction = PURPLE_SWITCH_WAIT_FOR_MARIO_TO_GET_OFF;
                }
            } else if (o->oBehParams2ndByte != 0) {
                if (o->oBehParams2ndByte == 1 && gMarioObject->platform != o) {
                    o->oAction++;
                } else {
                    if (o->oTimer < 1010) {
                        play_sound(SOUND_GENERAL2_SWITCH_TICK_FAST, gDefaultSoundArgs);
                    } else {
                        play_sound(SOUND_GENERAL2_SWITCH_TICK_SLOW, gDefaultSoundArgs);
                    }
                    if (o->oTimer > 1050) {
                        o->oAction = PURPLE_SWITCH_WAIT_FOR_MARIO_TO_GET_OFF;
                    }
                }
            }
            break;
        /**
         * Make the switch look unpressed again, and transition back to the
         * idle state.
         */
        case PURPLE_SWITCH_UNPRESSED:
            func_802A3398(2, 3, 0.2f, 1.5f);
            if (o->oTimer == 3) {
                o->oAction = PURPLE_SWITCH_IDLE;
            }
            break;
        /**
         * Mario is standing on the switch, but time has expired. Wait for
         * him to get off the switch, and when he does so, transition to the
         * unpressed state.
         */
        case PURPLE_SWITCH_WAIT_FOR_MARIO_TO_GET_OFF:
            if (!obj_is_mario_on_platform()) {
                o->oAction = PURPLE_SWITCH_UNPRESSED;
            }
            break;
        case 5:
            break;
        case 6:
            if (o->oTimer > 180) {
                create_star(o->oPosX, o->oPosY + 300.0f, o->oPosZ);
                gRedSwitchesPushed = 0;
                o->oAction = 5;
            }
            break;
    }
}