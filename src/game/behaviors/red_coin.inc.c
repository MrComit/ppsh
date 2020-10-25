/**
 * This file contains the initialization and behavior for red coins.
 * Behavior controls audio and the orange number spawned, as well as interacting with
 * the course's red coin star.
 */

/**
 * Red coin's hitbox details.
 */

s8 gSpinCoinCollected = 0;

static struct ObjectHitbox sRedCoinHitbox = {
    /* interactType:      */ INTERACT_COIN,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 2,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 100,
    /* height:            */ 64,
    /* hurtboxRadius:     */ 0,
    /* hurtboxHeight:     */ 0,
};

/**
 * Red coin initialization function. Sets the coin's hitbox and parent object.
 */
void bhv_red_coin_init(void) {
    // This floor and floor height are unused. Perhaps for orange number spawns originally?
    struct Surface *dummyFloor;
    UNUSED f32 floorHeight = find_floor(o->oPosX, o->oPosY, o->oPosZ, &dummyFloor);

    struct Object *hiddenRedCoinStar;

    // Set the red coins to have a parent of the closest red coin star.
    hiddenRedCoinStar = obj_nearest_object_with_behavior(bhvHiddenRedCoinStar);
    if (hiddenRedCoinStar != NULL)
        o->parentObj = hiddenRedCoinStar;
    else {
        hiddenRedCoinStar = obj_nearest_object_with_behavior(bhvBowserCourseRedCoinStar);
        if (hiddenRedCoinStar != NULL) {
            o->parentObj = hiddenRedCoinStar;
        } else {
            o->parentObj = NULL;
        }
    }

    set_object_hitbox(o, &sRedCoinHitbox);
}

/**
 * Main behavior for red coins. Primarily controls coin collection noise and spawning
 * the orange number counter.
 */
void bhv_red_coin_loop(void) {
    // If Mario interacted with the object...
    if (o->oInteractStatus & INT_STATUS_INTERACTED) {
        // ...and there is a red coin star in the level...
        //if (o->parentObj != NULL) {
            // ...increment the star's counter.
            //o->parentObj->oHiddenStarTriggerCounter++;
            gRedCoinsCollected++;

            // For JP version, play an identical sound for all coins.
#ifdef VERSION_JP
            create_sound_spawner(SOUND_GENERAL_RED_COIN);
#endif
            // Spawn the orange number counter, as long as it isn't the last coin.
            if (gRedCoinsCollected != 6) {
                spawn_orange_number(gRedCoinsCollected, 0, 0, 0);
            }

            // On all versions but the JP version, each coin collected plays a higher noise.
#ifndef VERSION_JP
            play_sound(SOUND_MENU_COLLECT_RED_COIN
                           + (((u8) gRedCoinsCollected - 1) << 16),
                       gDefaultSoundArgs);
#endif
        //}

        CoinCollected();
        // Despawn the coin.
        o->oInteractStatus = 0;
    }
}


void bhv_spinning_rcoin_loop(void) {
    obj_set_behavior(bhvRedCoin);

    if (o->oInteractStatus & INT_STATUS_INTERACTED) {
        gSpinCoinCollected = 1;
        //if (o->parentObj != NULL) {
            //o->parentObj->oHiddenStarTriggerCounter++;
            gRedCoinsCollected++;
            if (gRedCoinsCollected != 6) {
                spawn_orange_number(gRedCoinsCollected, 0, 0, 0);
            }
            play_sound(SOUND_MENU_COLLECT_RED_COIN
                           + (((u8) gRedCoinsCollected - 1) << 16),
                       gDefaultSoundArgs);
        //}
        CoinCollected();
        o->oInteractStatus = 0;
    }

    o->oCoinDir += o->oCoinDirAdd;
    o->oPosX = o->oHomeX + (sins((s16)o->oCoinDir) * o->oCoinMag);
    o->oPosZ = o->oHomeZ + (coss((s16)o->oCoinDir) * o->oCoinMag);
}
