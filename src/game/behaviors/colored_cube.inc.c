struct ObjectHitbox sCubeHitbox = {
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

f32 sCubeXPos[4] = {-617.015f, -339.7285f, -62.441f, 214.8465f};
s32 sCubesActive = 0; 


void bhv_colored_cube_init(void) {
    o->oAnimState = o->oBehParams2ndByte;
    o->oGravity = 2.5f;
    o->oFriction = 0.99f;
    o->oBuoyancy = 1.4f;
    set_object_hitbox(o, &sCubeHitbox);
    o->activeFlags |= 0x200;
}

void handle_boos(void) {
    struct Object *spawner;
    s32 bits = CL_count_bits(sCubesActive);
    if (!o->oCubeFlag) {
        struct Object *boo = spawn_object(o, MODEL_BOO, bhvColoredBoo);
        boo->oCubeFlag = bits;
        boo->oBehParams = o->oBehParams;
        switch (bits) {
            case 0:
                break;
            case 1:
            case 2:
            case 3:
                spawner = spawn_object(o, MODEL_NONE, bhvDashBooSpawner);
                spawner->oCubeFlag = bits;
                spawner->oBehParams2ndByte = o->oBehParams2ndByte;
                break;
        }
        o->oCubeFlag = 1;
        PlaySound2(SOUND_OBJ_BOO_LAUGH_LONG);
    }
}


void cube_released_loop(void) {
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
        create_respawner(MODEL_CUBE, bhvColoredCube, 3000);
        o->activeFlags = 0;
    }
}


void cube_idle_loop(void) {
    if (!o->oAction) {
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
        if (o->oBreakableBoxSmallReleased == 1)
            cube_released_loop();

    }
}


void cube_dropped_loop(void) {
    s32 bits;
    struct Object *star;
    struct Surface *floor;
    f32 floorHeight = find_floor(o->oPosX, o->oPosY, o->oPosZ, &floor);
        if (floor->type == SURFACE_COLORED_CUBE && floor->force == o->oBehParams2ndByte) {
            o->oInteractType = 0x00000000;
            sCubesActive |= 1 << o->oBehParams2ndByte;
            o->oPosX = sCubeXPos[o->oBehParams2ndByte];
            o->oPosY = -10064.7f;
            o->oPosZ = 5975.8f;
            o->oFaceAngleYaw = 0;
            o->oMoveAngleYaw = 0;
            o->oAction = 1;
            bits = CL_count_bits(sCubesActive);
            play_sound(SOUND_MENU_COLLECT_SECRET + (((u8) bits  - 1) << 16), gDefaultSoundArgs);
            if (bits != 4) {
                spawn_orange_number(bits, 0, 0, 0);
            } else {
                star = create_star(-198.3855f, -9695.4f, 5639.65f);
                star->oBehParams = 0x00 << 24;
            }

        }
    obj_become_tangible();
    obj_enable_rendering();
    o->header.gfx.node.flags &= ~0x10;
    o->oHeldState = 0;
    o->oBreakableBoxSmallReleased = 1;
    o->oBreakableBoxSmallFramesSinceReleased = 0;
}


void bhv_colored_cube_loop(void) {
    switch (o->oHeldState) {
        case HELD_FREE:
            wrench_idle_loop();
            break;

        case HELD_HELD:
            obj_disable_rendering();
            obj_become_intangible();
            handle_boos();
            break;

        case HELD_THROWN:
            cube_dropped_loop();
            break;

        case HELD_DROPPED:
            cube_dropped_loop();
            break;
    }

    o->oInteractStatus = 0;    
}