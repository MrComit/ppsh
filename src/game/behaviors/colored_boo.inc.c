struct ObjectHitbox sBooHitbox = {
    /* interactType:      */ INTERACT_DAMAGE,
    /* downOffset:        */ 20,
    /* damageOrCoinValue: */ 2,
    /* health:            */ 1,
    /* numLootCoins:      */ 0,
    /* radius:            */ 120,
    /* height:            */ 100,
    /* hurtboxRadius:     */ 120,
    /* hurtboxHeight:     */ 100,
};

extern s32 sCubesActive;

f32 sBooSpeeds[4] = {9.0f, 11.0f, 14.0f, 15.0f};
s32 sBooSpawnFrames[3] = {45, 35, 20};

void bhv_colored_boo_init(void) {
    set_object_hitbox(o, &sBooHitbox);
    if (o->parentObj != NULL) {
        o->oAnimState = o->parentObj->oBehParams2ndByte;
    }
    o->oPosX -= 1000.0f * sins(gMarioState->faceAngle[1]);
    o->oPosZ -= 1000.0f * coss(gMarioState->faceAngle[1]);
    o->oBehParams2ndByte = (o->oBehParams >> 16) & 0xFF;
}

void bhv_colored_boo_loop(void) {
    f32 dist;
    struct Object *cube;
    switch (o->oAction) {
        case 0:
            CL_Move();
            o->oMoveAngleYaw = o->oAngleToMario;
            approach_f32_ptr(&o->oPosY, gMarioState->pos[1], 5.0f);
            o->oForwardVel = sBooSpeeds[o->oCubeFlag] + (o->oDistanceToMario / 50);
            o->oInteractStatus = 0;
            if (gMarioState->heldObj != o->parentObj) {
                obj_become_intangible();
                o->oAction = 1;
            }
            break;
        case 1:
            CL_Move();
            if (gMarioState->heldObj == o->parentObj) {
                obj_become_tangible();
                o->oAction = 0;
            }
            o->oMoveAngleYaw = angle_to_object(o, o->parentObj);
            dist = CL_dist_between_points(&o->oPosX, &o->parentObj->oPosX, &dist);
            if (dist < 10.0f) {
                o->oAction = 2;
                o->parentObj->oInteractType = 0;
                PlaySound2(SOUND_OBJ_BOO_LAUGH_LONG);
            }
            break;
        case 2:
            vec3f_copy(&o->oPosX, &o->parentObj->oPosX);
            approach_f32_ptr(&o->header.gfx.scale[0], 0, 0.03f);
            approach_f32_ptr(&o->header.gfx.scale[1], 0, 0.03f);
            approach_f32_ptr(&o->header.gfx.scale[2], 0, 0.03f);
            if (o->header.gfx.scale[0] < 0.05f) {
                cube = spawn_object(o, MODEL_CUBE, bhvColoredCube);
                cube->oBehParams = o->oBehParams;
                cube->oBehParams2ndByte = o->oBehParams2ndByte;
                cube->oAnimState = o->oBehParams2ndByte;
                cube->oFaceAngleYaw = (o->oMoveAngleYaw = 0);
                vec3f_copy(&cube->oPosX, &o->parentObj->oHomeX);
                o->parentObj->activeFlags = 0;
                o->activeFlags = 0;
            }
            break;
    }
    if (o->parentObj->oAction == 1)
        o->activeFlags = 0;
}

void bhv_colored_dash_boo_init(void) {
    s16 cringe = RandomSign();
    set_object_hitbox(o, &sBooHitbox);
    if (o->parentObj != NULL) {
        o->oAnimState = o->parentObj->oBehParams2ndByte;
    }
    o->oPosX = gMarioState->pos[0] + (1500.0f * sins(gMarioState->faceAngle[1] + (0x4000 * cringe)));
    o->oPosZ = gMarioState->pos[2] + (1500.0f * coss(gMarioState->faceAngle[1] + (0x4000 * cringe)));
    o->oMoveAngleYaw = angle_to_object(o, gMarioState->marioObj);
    o->oForwardVel = 50.0f;
    o->oBehParams2ndByte = (o->oBehParams >> 16) & 0xFF;

    o->oPosX += 600.0f * sins(gMarioState->faceAngle[1]);
    o->oPosZ += 600.0f * coss(gMarioState->faceAngle[1]);

    //o->oPosX += 750.0f * sins(gMarioState->faceAngle[1]);
    //o->oPosZ += 750.0f * coss(gMarioState->faceAngle[1]);
}


void bhv_colored_dash_boo_loop(void) {
    CL_Move();
    //o->oMoveAngleYaw = o->oAngleToMario;
    //approach_f32_ptr(&o->oPosY, gMarioState->pos[1], 7.5f);
    o->oInteractStatus = 0;
    if (o->oTimer > 60)
        o->activeFlags = 0;
}


void bhv_dash_boo_spawner_loop(void) {
    o->oPosY = gMarioState->pos[1];
    if (gMarioState->heldObj != NULL && gMarioState->heldObj == o->parentObj) {
        if (o->oTimer > sBooSpawnFrames[o->oCubeFlag - 1]) {
            o->oTimer = 0;
            spawn_object(o, MODEL_BOO, bhvColoredDashBoo);
        }
    } else
        o->oTimer = 0;
    if (o->parentObj->oAction == 1 || gMarioState->heldObj != o->parentObj)
        o->activeFlags = 0;
}