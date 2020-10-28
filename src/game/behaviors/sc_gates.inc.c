Vec3f sTruckPos = {-12644.55f, -10000.0f, -8602.74f};


void spawn_truck_smoke(s16 model, const BehaviorScript *behavior) {
    struct Object *particle;
    particle = spawn_object_at_origin(o, 0, model, behavior);
    copy_object_pos_and_angle(particle, o);
    particle->oPosX -= 875.0f;
    particle->oPosZ -= 200.0f;

    particle = spawn_object_at_origin(o, 0, model, behavior);
    copy_object_pos_and_angle(particle, o);
    particle->oPosX -= 875.0f;
    particle->oPosZ += 200.0f;
}

void bhv_car_gate(void) {
    struct Object *bswitch = obj_nearest_object_with_behavior(bhvTimedCarSwitch);
    if (bswitch == NULL)
        o->activeFlags = 0;
    switch (o->oAction) {
        case 0:
            if (bswitch->oAction == PURPLE_SWITCH_TICKING) {
                o->oAction = 1;
                SetComitCutscene(60, 1, 3);
            }
            o->oPosY = approach_f32(o->oPosY, -10000.0f, 100.0f, 100.0f);
            break;
        case 1:
            if (o->oTimer < 70) {
                o->header.gfx.node.flags |= GRAPH_RENDER_ACTIVE;
            } else if (o->oTimer == 71) {
                spawn_object(o, MODEL_SC_TRUCK, bhvSimpTruck);
                spawn_object(o, MODEL_ARROW_HEAD, bhvArrowForSimpCar);
            }
            if (bswitch->oAction != PURPLE_SWITCH_TICKING)
                o->oAction = 0;
            if (o->oTimer > 10) {
                o->oPosY = approach_f32(o->oPosY, -8500.0f, 55.0f, 55.0f);
                if (o->oPosY < -8500.0f)
                    PlaySound(SOUND_ENV_METAL_BOX_PUSH);
            }
            break;
    }
}


void bhv_end_gate(void) {
    if (save_file_get_star_flags(gCurrSaveFileNum - 1, 4) & 0x8)
        o->activeFlags = 0;
    switch (o->oAction) {
        case 0:
            if (gRedSwitchesPushed >= 5) {
                o->oAction = 1;
                SetComitCutscene(60, 1, 4);
            }
            break;
        case 1:
            if (o->oTimer < 70)
                o->header.gfx.node.flags |= GRAPH_RENDER_ACTIVE;
            if (o->oTimer > 10) {
                o->oPosY = approach_f32(o->oPosY, -8500.0f, 55.0f, 55.0f);
                if (o->oPosY < -8500.0f)
                    PlaySound(SOUND_ENV_METAL_BOX_PUSH);
            }
            if (o->oTimer > 150)
                o->activeFlags = 0;
            break;
    }
}



void bhv_timed_gate_loop(void) {
    switch (o->oBehParams2ndByte) {
        case 0:
            bhv_car_gate();
            break;
        case 1: 
            bhv_end_gate();
            break;
    }
}


void bhv_simp_truck_init(void) {
    func_802A3004();
    vec3f_copy(&o->oPosX, sTruckPos);
}

void bhv_simp_truck_loop(void) {
    struct Object *obj;
    switch (o->oAction) {
        case 0:
            if (gMarioObject->platform == o) {
                o->oAction = 1;
                o->oForwardVel = 90.0f;
                obj = obj_nearest_object_with_behavior(bhvArrowForSimpCar);
                if (obj != NULL)
                    obj->activeFlags = 0;
            }
            break;
        case 1:
            CL_Move();
            if (o->oPosZ > -2540.0f) {
                o->oFaceAngleYaw = (o->oMoveAngleYaw = approach_s16_symmetric((s16)o->oFaceAngleYaw, 0x4000, 0x200));
                o->oAngleVelYaw = 0x200;
                if (o->oFaceAngleYaw == 0x4000) {
                    o->oMoveAngleYaw = 0x4000;
                    o->oAngleVelYaw = 0;
                    o->oAction = 2;
                }
            }
            break;
        case 2:
            CL_Move();
            if (o->oPosX > 23500.0f && gMarioObject->platform == o) {
                o->oAction = 3;
                sDelayedWarpOp = 0x10;
                sDelayedWarpTimer = 1;
                sSourceWarpNodeId = 0xAB;
                func_8024A48C(sSourceWarpNodeId);
            }
            break;
        case 3:
            CL_Move();
            break;
    }
    if (o->parentObj != NULL && o->parentObj->oAction == 0 && o->parentObj->oTimer > 30)
        o->activeFlags = 0;
}

void bhv_simp_big_truck_init(void) {
    o->oBobombBlinkTimer = CL_RandomMinMaxU16(65, 115);
    o->oAnimState = CL_RandomMinMaxU16(0, 3);
    o->oRoom = 2;
    if (o->oBehParams >> 24)
        o->oAction = 1;
}

void bhv_simp_big_truck_loop(void) {
    if (o->oBehParams2ndByte == 0) {
        if (o->oTimer % 0x2D == 0) {
            if (o->oDistanceToMario < 8000.0f)
                spawn_truck_smoke(MODEL_BURN_SMOKE, bhvBlackSmokeObject);
        }
        switch (o->oAction) {
            case 0:
                o->oBobombBuddyPosXCopy = o->oPosX;
                o->oPosX = approach_f32_asymptotic(o->oPosX, o->oHomeX + 1000.0f, 0.05f);
                o->oVelX = o->oPosX - o->oBobombBuddyPosXCopy;
                if (o->oTimer > o->oBobombBlinkTimer) {
                    o->oBobombBlinkTimer = CL_RandomMinMaxU16(65, 115);
                    o->oAction = 1;
                }
                break;
            case 1:
                o->oBobombBuddyPosXCopy = o->oPosX;
                o->oPosX = approach_f32_asymptotic(o->oPosX, o->oHomeX, 0.05f);
                o->oVelX = o->oPosX - o->oBobombBuddyPosXCopy;
                if (o->oTimer > o->oBobombBlinkTimer) {
                    o->oBobombBlinkTimer = CL_RandomMinMaxU16(65, 115);
                    o->oAction = 0;
                }
                break;
        }
    }
}


void bhv_arrow_simp_car_loop(void) {
    f32 dist;
    s16 pitch, yaw;
    struct Object *obj = obj_nearest_object_with_behavior(bhvSimpTruck);
    if (obj == NULL) {
        o->activeFlags = 0;
    } else {
        o->oPosX = gMarioState->pos[0];
        o->oPosY = gMarioState->pos[1] + 180.0f;
        o->oPosZ = gMarioState->pos[2];
        vec3f_get_dist_and_angle(&o->oPosX, &obj->oPosX, &dist, &pitch, &yaw);

        o->oFaceAngleYaw = yaw + 0x8000;
        o->oFaceAnglePitch = pitch;
    }
}