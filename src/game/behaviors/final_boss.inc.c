struct ObjectHitbox sPeachBossHitbox = {
    /* interactType:      */ INTERACT_DAMAGE,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 2,
    /* health:            */ 1,
    /* numLootCoins:      */ 0,
    /* radius:            */ 200,
    /* height:            */ 200,
    /* hurtboxRadius:     */ 200,
    /* hurtboxHeight:     */ 200,
};

struct ObjectHitbox sToadMinionHitbox = {
    /* interactType:      */ INTERACT_DAMAGE,
    /* downOffset:        */ 20,
    /* damageOrCoinValue: */ 2,
    /* health:            */ 1,
    /* numLootCoins:      */ 0,
    /* radius:            */ 80,
    /* height:            */ 100,
    /* hurtboxRadius:     */ 80,
    /* hurtboxHeight:     */ 100,
};

struct ObjectHitbox sBossFlameHitbox = {
    /* interactType:      */ INTERACT_FLAME,
    /* downOffset:        */ 10,
    /* damageOrCoinValue: */ 0,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 10,
    /* height:            */ 20,
    /* hurtboxRadius:     */ 10,
    /* hurtboxHeight:     */ 20,
};


f32 sGatePosition[2] = {1462.11f, 417.249f};


void boss_spawn_simps(void) {
    s32 i;
    struct Object *obj;
    for (i = 0; i < 3; i++) {
        obj = spawn_object(o, MODEL_SIMP_TOAD, bhvSimpToadMinion);
        obj->oBehParams = i << 16; 

        obj = spawn_object(o, MODEL_SIMP_TOAD, bhvSimpToadMinion);
        obj->oBehParams = 0x01000000 + (i << 16); 

        obj = spawn_object(o, MODEL_SIMP_TOAD, bhvSimpToadMinion);
        obj->oBehParams = 0x02000000 + (i << 16); 

        obj = spawn_object(o, MODEL_SIMP_TOAD, bhvSimpToadMinion);
        obj->oBehParams = 0x03000000 + (i << 16); 

        obj = spawn_object(o, MODEL_SIMP_TOAD, bhvSimpToadMinion);
        obj->oBehParams = 0x04000000 + (i << 16); 
    }

}



void bhv_peach_boss_init(void) {
    o->oFriction = 1.0f;
    o->oOpacity = 0xFF;
    obj_become_intangible();
    set_object_hitbox(o, &sPeachBossHitbox);
}

void bhv_peach_boss_loop(void) {
    struct Object *obj;
    switch (o->oAction) {
        case 0:
            if (o->oDistanceToMario < 500.0f) {
                o->oAction = 1;
            }
            break;
        case 1:
            set_mario_npc_dialog(1);
            if (o->oTimer > 30) {
                boss_spawn_simps();
                o->oAction = 2;
                o->oFloatF4 = 1.0f;
                PlaySound2(SOUND_GENERAL_VANISH_SFX);
                obj = obj_nearest_object_with_behavior(bhvBossGate);
                obj->oAction = 1;
            }
            break;
        case 2:
            o->oFloatF4 = approach_f32(o->oFloatF4, 0.8f, 0.01f, 0.01f);
            obj_scale(o->oFloatF4);
            if (o->oTimer > 30) {
                o->oAction = 3;
            }
            break;
        case 3:
            if (CL_NPC_Dialog(103)) {
                obj_become_tangible();
                o->oAction = 4;
                set_obj_animation_and_sound_state(4);
            }
            break;
        case 4:
            if (o->oTimer > 30) {
                o->oAction = 5;
                o->oF8 = CL_RandomMinMaxU16(60, 120);
                o->o100 = CL_RandomMinMaxU16(3, 6);
                o->oFC = 0;
                o->oForwardVel = 20.0f;
            }
            break;
        case 5:
            obj_update_floor_and_walls();
            obj_move_standard(-78);
            o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x200);
            if (o->oTimer > o->oF8) {
                //obj_spit_fire(
                //    /*relativePos*/ 0, 200, 0,
                //    /*scale      */ 3.5f,
                //    /*model      */ MODEL_RED_FLAME_SHADOW,
                //    /*startSpeed */ 45.0f,
                //    /*endSpeed   */ 30.0f,
                //    /*movePitch  */ 0x1000);
                spawn_object(o, MODEL_RED_FLAME_SHADOW, bhvBossFlame);
                o->oF8 = CL_RandomMinMaxU16(60, 120);
                o->oTimer = 0;
                o->oFC++;
            }
            if (o->oFC > o->o100) {
                o->oAction = 6;
                o->oFC = 0;
                o->o100 = CL_RandomMinMaxU16(3, 6);
                o->oForwardVel = 0;
            }
            break;
        case 6:
            if (o->oTimer < 45) {
                o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x600);
            } else if (o->oTimer > 50) {
                obj_update_floor_and_walls();
                obj_move_standard(-78);
                approach_f32_asymptotic_bool(&o->oForwardVel, 100.0f, 0.2f);

                if (o->oInteractStatus & INT_STATUS_INTERACTED) {
                    o->oAction = 5;
                    o->oForwardVel = 20.0f;
                } else if (o->oMoveFlags & OBJ_MOVE_HIT_WALL) {
                    o->oAction = 7;
                    ShakeScreen(SHAKE_POS_MEDIUM);
                }
            }
            break;
        case 7:
            break;
    }
    o->oInteractStatus = 0;
}


void bhv_toad_minion_init(void) {
    set_object_hitbox(o, &sToadMinionHitbox);
    obj_become_intangible();
    o->oF8 = (0x10000 / 5) * (o->oBehParams >> 24);
    o->oPosY = o->parentObj->oPosY + (((o->oBehParams >> 16) & 0xFF) * 80.0f);
    o->oPosX = o->parentObj->oPosX + ((50.0f + (((o->oBehParams >> 16) & 0xFF) * 25.0f)) * sins(o->oF8));
    o->oPosZ = o->parentObj->oPosZ + ((50.0f + (((o->oBehParams >> 16) & 0xFF) * 25.0f)) * coss(o->oF8));
    o->oMoveAngleYaw = o->oF8 - 0x1555;
}


void bhv_toad_minion_loop(void) {
    switch (o->oAction) {
        case 0:
            o->oOpacity = approach_s16_symmetric(o->oOpacity, 255, 20);
            if (o->oOpacity == 255) {
                o->oAction = 1;
            }
            break;
        case 1:
            if (o->parentObj->oAction == 4)
                o->oAction = 2;
            break;
        case 2:
            if (o->parentObj->oAction == 6)
                o->oF4 = 0xC00;
            else
                o->oF4 = 0x300;
            o->oF8 += o->oF4;
            o->oMoveAngleYaw = o->oF8 - 0x1555;
            o->oPosX = o->parentObj->oPosX + ((50.0f + (((o->oBehParams >> 16) & 0xFF) * 25.0f)) * sins(o->oF8));
            o->oPosZ = o->parentObj->oPosZ + ((50.0f + (((o->oBehParams >> 16) & 0xFF) * 25.0f)) * coss(o->oF8));
            break;

    }
    o->oInteractStatus = 0;
}



void bhv_boss_gate_loop(void) {
    o->oPosY = approach_f32(o->oPosY, sGatePosition[o->oAction], 50.0f, 50.0f);
}



void bhv_boss_flame_init(void) {
    o->oForwardVel = 40.0f;
    o->oMoveAngleYaw = o->oAngleToMario;
    set_object_hitbox(o, &sBossFlameHitbox);
}


void bhv_boss_flame_loop(void) {
    CL_Move();
    obj_rotate_yaw_toward(o->oAngleToMario, 0x300);
    approach_f32_ptr(&o->oForwardVel, 30.0f, 0.07f);
    if (o->oForwardVel == 30.0f) {
        o->activeFlags = 0;
        func_802A3034(SOUND_OBJ_DEFAULT_DEATH);
    }
    o->oGraphYOffset = 15.0f * o->header.gfx.scale[1];
}