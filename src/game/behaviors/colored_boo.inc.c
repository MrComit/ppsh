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

f32 sBooSpeeds[4] = {11.0f, 13.0f, 14.0f, 15.0f};
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
    struct Object *obj;
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
                //cube = spawn_object(o, MODEL_CUBE, bhvColoredCube);
                //cube->oBehParams = o->oBehParams;
                //cube->oBehParams2ndByte = o->oBehParams2ndByte;
                //cube->oAnimState = o->oBehParams2ndByte;
                //cube->oFaceAngleYaw = (cube->oMoveAngleYaw = 0);
                //vec3f_copy(&cube->oPosX, &o->parentObj->oHomeX);
                //o->parentObj->activeFlags = 0;
                vec3f_copy(&o->parentObj->oPosX, &o->parentObj->oHomeX);
                o->parentObj->oFaceAngleYaw = (o->parentObj->oMoveAngleYaw = 0);
                o->parentObj->oFaceAngleRoll = (o->parentObj->oMoveAngleRoll = 0);
                o->parentObj->oFaceAnglePitch = (o->parentObj->oMoveAnglePitch = 0);
                o->parentObj->oHeldState = 2;
                o->parentObj->oIntangibleTimer = 0;
                o->parentObj->oInteractStatus = 0;
                o->parentObj->oInteractType = INTERACT_GRABBABLE;
                o->parentObj->oCubeFlag = 0;
                //o->parentObj->oBreakableBoxSmallReleased = 0;
                o->activeFlags = 0;

                obj = spawn_object(o, MODEL_ARROW_HEAD, bhvArrowForCubes);
                obj->parentObj = o->parentObj;
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

    o->oPosX += o->oFloatF4 * sins(gMarioState->faceAngle[1]);
    o->oPosZ += o->oFloatF4 * coss(gMarioState->faceAngle[1]);

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
    struct Object *obj;
    o->oPosY = gMarioState->pos[1];
    if (gMarioState->heldObj != NULL && gMarioState->heldObj == o->parentObj) {
        if (o->oTimer > sBooSpawnFrames[o->oCubeFlag - 1]) {
            o->oTimer = 0;
            obj = spawn_object(o, MODEL_BOO, bhvColoredDashBoo);
            obj->oFloatF4 = 600.0f;
        }
    } else
        o->oTimer = 0;
    if (o->parentObj->oAction == 1 || gMarioState->heldObj != o->parentObj)
        o->activeFlags = 0;
}


void bhv_dash_boo_spawner_2_loop(void) {
    struct Object *obj;
    o->oPosY = gMarioState->pos[1];
    if (gMarioState->heldObj != NULL && gMarioState->heldObj == o->parentObj) {
        if (o->oTimer > (sBooSpawnFrames[o->oCubeFlag - 1] * 3)) {
            o->oTimer = 0;
            obj = spawn_object(o, MODEL_BOO, bhvColoredDashBoo);
            obj->oFloatF4 = (f32)(CL_RandomMinMaxU16(1200, 1300));
        }
    } else
        o->oTimer = 0;
    if (o->parentObj->oAction == 1 || gMarioState->heldObj != o->parentObj)
        o->activeFlags = 0;
}