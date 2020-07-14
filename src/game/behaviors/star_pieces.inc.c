


void bhv_star_piece_switch_loop(void) {
    struct Object *star;
    star = obj_nearest_object_with_behavior(bhvStarPieceStar);
    if (star == NULL) {
        mark_object_for_deletion(o);
    }
    o->oHiddenStarTriggerCounter  = (s32)((o->oBehParams >> 24) & 0xFF) * 30;
    o->oStarSelectorTimer  = (s32)((o->oBehParams >> 16) & 0xFF) * 15;

    switch (o->oAction) {
        case 0:
            // If Mario is on the switch and has ground-pounded,
            // recede and get ready to start ticking.
            if (gMarioObject->platform == o) {
                if (gMarioStates->action == ACT_GROUND_POUND_LAND) {
                    o->oAction = 1;

                    // Recede at a rate of 20 units/frame.
                    o->oVelY = -20.0f;
                    // Set gravity to 0 so it doesn't accelerate when receding.
                    o->oGravity = 0.0f;

                    PlaySound2(SOUND_GENERAL_SWITCH_DOOR_OPEN);
                }
            }

            // Have collision
            load_object_collision_model();

            break;
        case 1:
            // Recede for 6 frames before going invisible and ticking.
            // This is probably an off-by-one error, since the switch is 100 units tall
            // and recedes at 20 units/frame, which means it will fully recede after 5 frames.
            if (o->oTimer > 5) {
                obj_hide();
                o->oAction = 2;
                // ???
                o->oPosY = gMarioObject->oPosY - 40.0f;

                // Spawn particles. There's a function that calls this same function
                // with the same arguments, func_802A3004, why didn't they just call that?
                func_802AA618(0, 0, 46.0f);
            } else {
                // Have collision while receding
                load_object_collision_model();
                // Recede
                obj_move_using_fvel_and_gravity();
            }

            break;
        case 2:
            // Tick faster when the blue coins start blinking
            /*if (star->oHiddenStarTriggerCounter == 5) {
                mark_object_for_deletion(o);
                break;
            }*/

            if (o->oTimer < o->oHiddenStarTriggerCounter ) { // 200
                play_sound(SOUND_GENERAL2_SWITCH_TICK_FAST, gDefaultSoundArgs);
            } else {
                play_sound(SOUND_GENERAL2_SWITCH_TICK_SLOW, gDefaultSoundArgs);
            }

            // Delete the switch (which stops the sound) after the last coin is collected,
            // or after the coins unload after the 240-frame timer expires.
            if (obj_nearest_object_with_behavior(bhvStarPiece) == NULL) {
                mark_object_for_deletion(o);
            } 
            if (o->oTimer > o->oStarSelectorTimer * 2 + o->oHiddenStarTriggerCounter) {
                o->oVelY = 20.0f;
                o->oGravity = 0.0f;
                o->oAction++;
            }

            break;
        case 3:
            if (o->oTimer > 5) {
                obj_unhide();

                o->oAction = 0;
                // ???
                //o->oPosY = gMarioObject->oPosY - 40.0f;
                o->oPosY = o->oHomeY;
                o->oVelY = 0;

                func_802AA618(0, 0, 46.0f);
            } else {
                obj_move_using_fvel_and_gravity();
            }
            load_object_collision_model();
            break;
    }
}



void bhv_star_piece_loop(void) {
struct Object *star;
    star = obj_nearest_object_with_behavior(bhvStarPieceStar);
    if (star == NULL) {
        mark_object_for_deletion(o);
    }

    if (o->parentObj != NULL && virtual_to_segmented(0x13, o->parentObj->behavior) == bhvSPlat) {
        o->oPosX = o->parentObj->oPosX;
        o->oPosY = o->parentObj->oPosY + 100.0f;
        o->oPosZ = o->parentObj->oPosZ;
    } else if (o->oBehParams2ndByte == 1) {
        o->oPosY = o->oHomeY + (sins(o->oBobombBlinkTimer) * 150.0f);
        o->oBobombBlinkTimer += 0x400;
    }

    o->oFaceAngleYaw += 0x600;

    switch (o->oAction) {
        case 0:
            // Become invisible and intangible
            //obj_disable_rendering();
            //obj_become_intangible();

            obj_disable_rendering_and_become_intangible(o);

            // Set action to 1 after the blue coin switch is found.
            o->oHiddenBlueCoinSwitch = obj_nearest_object_with_behavior(bhvStarPieceSwitch);

            if (o->oHiddenBlueCoinSwitch != NULL) {
                o->oAction++;
            }

            break;
        case 1:
            if (o->oHiddenBlueCoinSwitch->oAction == 2) {
                o->oAction++; // Set to 2
                obj_enable_rendering_and_become_tangible(o);
                obj_unhide();
            }

            break;
        case 2:
            // Become tangible
            //obj_enable_rendering();
            //obj_become_tangible();

            // Delete the coin once collected
            if (are_objects_collided(o, gMarioObject) == 1) {
                star->oHiddenStarTriggerCounter++;
                if (star->oHiddenStarTriggerCounter != 5) {
                    spawn_orange_number(star->oHiddenStarTriggerCounter , 0, 0, 0);
                } else {
                    //mark_object_for_deletion(o);
                }
                spawn_object(o, MODEL_SPARKLES, bhvGoldenCoinSparkles);
                play_sound(SOUND_MENU_COLLECT_SECRET + (((u8) star->oHiddenStarTriggerCounter  - 1) << 16), gDefaultSoundArgs);
                o->oAction++;
                //mark_object_for_deletion(o);
                break;
            }

            if (obj_wait_then_blink(o->oHiddenBlueCoinSwitch->oHiddenStarTriggerCounter, o->oHiddenBlueCoinSwitch->oStarSelectorTimer)) {
                //mark_object_for_deletion(o);
                o->oAction = 0;
                obj_hide();
                obj_become_intangible();
            }

            break;
        case 3:
            //obj_disable_rendering();
            //obj_become_intangible();
            obj_disable_rendering_and_become_intangible(o);

            if (obj_nearest_object_with_behavior(bhvStarPieceSwitch) == NULL){
                mark_object_for_deletion(o);
                break;
            }

            if (o->oHiddenBlueCoinSwitch->oAction != 2) {
                o->oAction = 0;
            }

            if(star->oHiddenStarTriggerCounter >= 5) {
                //mark_object_for_deletion(o);
            }

        break;
    }

    o->oInteractStatus = 0;
}


void bhv_star_piece_star_loop(void) {
struct Object *starSwitch;
    starSwitch = obj_nearest_object_with_behavior(bhvStarPieceSwitch);
    if (starSwitch == NULL) {
        mark_object_for_deletion(o);
    }

    if (starSwitch->oAction != 2) {
        o->oHiddenStarTriggerCounter = 0;
    }

    if (o->oHiddenStarTriggerCounter  == 5) {
        create_star(o->oPosX, o->oPosY, o->oPosZ);
        mark_object_for_deletion(o);
        //mark_object_for_deletion(starSwitch);
    }

}