struct ObjectHitbox sWrenchHitbox = {
    /* interactType:      */ INTERACT_GRABBABLE,
    /* downOffset:        */ 20,
    /* damageOrCoinValue: */ 0,
    /* health:            */ 1,
    /* numLootCoins:      */ 0,
    /* radius:            */ 60,
    /* height:            */ 100,
    /* hurtboxRadius:     */ 60,
    /* hurtboxHeight:     */ 100,
};

void bhv_wrench_init(void) {
    o->oGravity = 2.5f;
    o->oFriction = 0.99f;
    o->oBuoyancy = 1.4f;
    set_object_hitbox(o, &sWrenchHitbox);
    o->activeFlags |= 0x200;
}

void wrench_released_loop(void) {
    o->oBreakableBoxSmallFramesSinceReleased++;

    // Begin flashing
    if (o->oBreakableBoxSmallFramesSinceReleased > 810) {
        if (o->oBreakableBoxSmallFramesSinceReleased & 1)
            o->header.gfx.node.flags |= 0x10;
        else
            o->header.gfx.node.flags &= ~0x10;
    }

    // Despawn, and create a corkbox respawner
    if (o->oBreakableBoxSmallFramesSinceReleased > 900) {
        //create_respawner(MODEL_WRENCH, bhvWrenchCollect, 3000);
        //o->activeFlags = 0;
        vec3f_copy(&o->oPosX, &o->oHomeX);
        o->oFaceAngleYaw = (o->oMoveAngleYaw = 0);
        o->oFaceAngleRoll = (o->oMoveAngleRoll = 0);
        o->oFaceAnglePitch = (o->oMoveAnglePitch = 0);
        o->oHeldState = 2;
        o->oIntangibleTimer = 0;
        o->oInteractStatus = 0;
        o->oInteractType = INTERACT_GRABBABLE;
        o->oBreakableBoxSmallFramesSinceReleased = 0;
        o->oBreakableBoxSmallReleased = 0;
    }
}


void wrench_act0(void) {
    s16 sp1E = object_step();

    attack_collided_non_mario_object(o);
    if (sp1E == 1)
        PlaySound2(SOUND_GENERAL_BOX_LANDING_2);
    if (sp1E & 1) {
        if (o->oForwardVel > 20.0f) {
            PlaySound2(SOUND_ENV_SLIDING);
            func_802F4CE8();
        }
    }

    if (o->oTimer > 60) {
        o->oTimer = 0;
        spawn_object(o, MODEL_NONE, bhvSparkleSpawn);
    }
}

void wrench_idle_loop(void) {
    switch(o->oAction) {
        case 0:
            wrench_act0();
            if (o->oBreakableBoxSmallReleased == 1)
                wrench_released_loop();
            break;
        case 1:
            break;
    }
}

void wrench_dropped_loop(void) {
    struct Surface *floor;
    struct Object *star;
    f32 floorHeight = find_floor(o->oPosX, o->oPosY, o->oPosZ, &floor);
    star = obj_nearest_object_with_behavior(bhvWrenchStar);
    if (star != NULL) {
        if (floor->type == SURFACE_THI3_WALLKICK) {
            o->oInteractType = 0x00000000;
            obj_scale(0.6);
            o->oPosY = floorHeight;
            o->oAction = 1;
            star->oHiddenStarTriggerCounter++;
            star->oAction = 1;
            play_sound(SOUND_MENU_COLLECT_SECRET + (((u8) star->oHiddenStarTriggerCounter  - 1) << 16), gDefaultSoundArgs);
            if (star->oHiddenStarTriggerCounter != 5) {
                spawn_orange_number(star->oHiddenStarTriggerCounter, 0, 0, 0);
            }
        }
    }
    obj_become_tangible();
    obj_enable_rendering();
    obj_get_dropped();
    o->header.gfx.node.flags &= ~0x10;
    o->oHeldState = 0;
    o->oBreakableBoxSmallReleased = 1;
    o->oBreakableBoxSmallFramesSinceReleased = 0;
}

void bhv_wrench_loop(void) {
    switch (o->oHeldState) {
        case HELD_FREE:
            wrench_idle_loop();
            break;

        case HELD_HELD:
            obj_disable_rendering();
            obj_become_intangible();
            break;

        case HELD_THROWN:
            wrench_dropped_loop();
            break;

        case HELD_DROPPED:
            wrench_dropped_loop();
            break;
    }

    o->oInteractStatus = 0;
}