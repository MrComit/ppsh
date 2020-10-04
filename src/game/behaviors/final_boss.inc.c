//#include "game/object_helpers2.h"

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
    /* interactType:      */ INTERACT_BOUNCE_TOP,
    /* downOffset:        */ 20,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 2,
    /* numLootCoins:      */ 1,
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
    /* radius:            */ 25,
    /* height:            */ 30,
    /* hurtboxRadius:     */ 25,
    /* hurtboxHeight:     */ 30,
};


f32 sGatePosition[2] = {1462.11f, 417.249f};

f32 sMoveSpeeds[3] = {20.0f, 20.0f, 30.0f};
s16 sRotateSpeeds[3] = {0x200, 0x280, 0x300};
s32 sToadsDead = 0;

extern Vtx ccm_dl_ArenaRedCircle_001_mesh_vtx_0;

s16 sVertexList[] = {0, 3, 6, 9, 12, 15, 16, 17, 18, 19, 20, 21, 24, 25, 28, 29, 32, 33, 36, 37};

void boss_change_circle_color(u8 r, u8 g, u8 b, s16 speed) {
    s16 i;
    u8 dr, dg, db;
    Vtx *verts = segmented_to_virtual(&ccm_dl_ArenaRedCircle_001_mesh_vtx_0);
    dr = approach_s16_symmetric(verts[0].v.cn[0], r, speed);
    dg = approach_s16_symmetric(verts[0].v.cn[1], g, speed);
    db = approach_s16_symmetric(verts[0].v.cn[2], b, speed);

    for (i = 0; i < 20; i++) {
        verts[sVertexList[i]].v.cn[0] = dr;
        verts[sVertexList[i]].v.cn[1] = dg;
        verts[sVertexList[i]].v.cn[2] = db;
    }

}



void boss_rotate_yaw_and_bounce_off_walls(s16 turnAmount) {
    s16 targetYaw;
    if (o->oMoveFlags & OBJ_MOVE_HIT_WALL) {
        targetYaw = obj_reflect_move_angle_off_wall();
    }
    obj_rotate_yaw_toward(targetYaw, turnAmount);
}


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
                sToadsDead = 0;
            }
            break;
        case 1:
            boss_change_circle_color(0, 0, 255, 0x10);
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
                o->o100 = 0;//CL_RandomMinMaxU16(3, 6);
                o->oFC = 0;
                o->oForwardVel = 20.0f;
                o->o104 = 0x200;
            }
            break;
        case 5:
            obj_update_floor_and_walls();
            obj_move_standard(-78);
            o->oMoveAngleYaw = (o->oFaceAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, o->o104));
            if (o->oTimer > o->oF8) {
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
                o->oMoveAngleYaw = o->oAngleToMario;
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
                    obj_become_intangible();
                }
            }
            o->oFaceAngleYaw += 0x1000;
            break;
        case 7:
            o->oOpacity = approach_s16_symmetric(o->oOpacity, 30, 20);
            if (o->oTimer > 450) {
                o->oAction = 8;
                obj_become_tangible();
            }
            break;
        case 8:
            o->oOpacity = approach_s16_symmetric(o->oOpacity, 255, 20);
            if (o->oTimer > 60) {
                o->oAction = 5;
                o->oForwardVel = sMoveSpeeds[sToadsDead / 5];
                o->o104 = sRotateSpeeds[sToadsDead / 5];
                o->oMoveAngleYaw = (o->oFaceAngleYaw = o->oAngleToMario);
            }
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

            if (o->parentObj->oAction == 7) {
                o->oAction = 3;
                o->oForwardVel = 15.0f;
                o->oVelY = 30.0f;
                o->oGravity = -1.5f;
                obj_become_tangible();
                o->oPosX = o->parentObj->oPosX + ((5.0f + (((o->oBehParams >> 16) & 0xFF) * 25.0f)) * sins(o->oF8));
                o->oPosZ = o->parentObj->oPosZ + ((5.0f + (((o->oBehParams >> 16) & 0xFF) * 25.0f)) * coss(o->oF8));
                o->oFC = CL_RandomMinMaxU16(0x80, 0x300) * RandomSign();
                o->o104 = CL_RandomMinMaxU16(15, 90);
            }
            break;
        case 3:
            obj_update_floor_and_walls();
            obj_move_standard(-78);
            if (o->oMoveFlags & OBJ_MOVE_LANDED) {
                o->oVelY = 20.0f;
            }
            //boss_rotate_yaw_and_bounce_off_walls(0x1000);
            if (o->oMoveFlags & OBJ_MOVE_HIT_WALL) {
                //o->oMoveAngleYaw = o->oWallAngle;
                //o->oPosX += 50.0f * sins(o->oWallAngle);
                //o->oPosZ += 50.0f * coss(o->oWallAngle);
                o->oMoveAngleYaw = obj_angle_to_home();
            }
            o->oMoveAngleYaw += o->oFC;
            o->oFaceAnglePitch += 0x400;
            o->oGraphYOffset = 100.0f * (absi((s16)o->oFaceAnglePitch) / 32768.0f);
            if (o->oTimer > o->o104) {
                o->oTimer = 0;
                o->oFC = CL_RandomMinMaxU16(0x80, 0x300) * RandomSign();
                o->o104 = CL_RandomMinMaxU16(15, 90);
            }
            if (o->oInteractStatus & INT_STATUS_INTERACTED && o->oInteractStatus & INT_STATUS_WAS_ATTACKED) {
                o->oAction = 4;
                obj_become_intangible();
                //o->oFloat108 = 0.9f;
                spawn_object_loot_yellow_coins(o, o->oNumLootCoins, 15.0f);
                o->oFloat100 = (2500.0f + (((o->oBehParams >> 16) & 0xFF) * 25.0f)) * sins(o->oF8);
                o->oFloat108 = 274.0f + ((2500.0f + (((o->oBehParams >> 16) & 0xFF) * 25.0f)) * coss(o->oF8));
                sToadsDead++;
            }
            if (o->parentObj->oAction == 8) {
                o->oAction = 8;
                o->oF4 = 0x300;
                o->oForwardVel = 0;
                o->oVelY = 0;
                o->oFaceAnglePitch = 0;
                o->oOpacity = 200;
                obj_become_intangible();
                o->oFloat100 = o->parentObj->oPosX + (50.0f + (((o->oBehParams >> 16) & 0xFF) * 25.0f)) * sins(o->oF8);
                o->oFloat104 = o->parentObj->oPosY + (((o->oBehParams >> 16) & 0xFF) * 80.0f);
                o->oFloat108 = o->parentObj->oPosZ + ((50.0f + (((o->oBehParams >> 16) & 0xFF) * 25.0f)) * coss(o->oF8));
            }
            break;
        case 4:
            if (o->oTimer < 15) {
                //o->oFloat108 = approach_f32(o->oFloat108, 0.6f, 0.03f, 0.03f);
                //obj_scale(o->oFloat108);
                o->oOpacity = approach_s16_symmetric(o->oOpacity, 80, 20);
            } else {
                o->oPosY = approach_f32(o->oPosY, (100.0f * ((o->oBehParams >> 16) & 0xFF)) + 300.0f, 10.0f, 10.0f);
                o->oPosX = approach_f32(o->oPosX, o->oFloat100, 50.0f, 50.0f);
                o->oPosZ = approach_f32(o->oPosZ, o->oFloat108, 50.0f, 50.0f);
                if (o->oPosX == o->oFloat100 && o->oPosZ == o->oFloat108) {
                    o->oAction = 5 + ((o->oBehParams >> 16) & 0xFF);
                    //o->oAction = 5;
                    o->oFaceAnglePitch = 0;
                    o->oF4 = 0x80;
                    o->oFC = CL_RandomMinMaxU16(0x90, 0x300);
                    o->o100 = 0;
                }
            }
            break;
        case 5:
            o->oF8 += o->oF4;
            o->oMoveAngleYaw = (o->oF8 - 0x1555) + 0x8000;
            o->oPosX = (2500.0f + (((o->oBehParams >> 16) & 0xFF) * 25.0f)) * sins(o->oF8);
            o->oPosZ = 274.0f + ((2500.0f + (((o->oBehParams >> 16) & 0xFF) * 25.0f)) * coss(o->oF8));
            if (o->oTimer > o->oFC) {
                spawn_object(o, MODEL_RED_FLAME_SHADOW, bhvBossFlame);
                o->oTimer = 0;
                o->oFC = CL_RandomMinMaxU16(0x90, 0x300);
            }
            break;
        case 6:
            o->oF8 += o->oF4;
            o->oMoveAngleYaw = -(o->oF8 - 0x1555);
            o->oPosX = (2500.0f + (((o->oBehParams >> 16) & 0xFF) * 25.0f)) * sins(o->oF8);
            o->oPosZ = 274.0f + ((2500.0f + (((o->oBehParams >> 16) & 0xFF) * 25.0f)) * coss(o->oF8));
            if (o->oTimer > o->oFC) {
                spawn_object(o, MODEL_BLACK_BOBOMB, bhvBossBomb);
                o->oTimer = 0;
                o->oFC = CL_RandomMinMaxU16(0x90, 0x300);
            }
            break;
        case 7:
            if (o->oTimer < o->oFC) {
                o->oOpacity = approach_s16_symmetric(o->oOpacity, 80, 30);
                o->oF8 += o->oF4;
                o->oMoveAngleYaw = -(o->oF8 + 0x1555);
                o->oPosX = (2500.0f + (((o->oBehParams >> 16) & 0xFF) * 25.0f)) * sins(o->oF8);
                o->oPosZ = 274.0f + ((2500.0f + (((o->oBehParams >> 16) & 0xFF) * 25.0f)) * coss(o->oF8));
            } else {
                obj_become_tangible();
                o->oOpacity = approach_s16_symmetric(o->oOpacity, 255, 30);
                o->o100 += 0x500;
                //o->oMoveAngleYaw = -(o->oF8 - 0x1555);
                o->oPosY = -(280.0f + (((o->oBehParams >> 16) & 0xFF) * 25.0f)) * sins(o->o100 * 2);
                o->oPosX = (2500.0f + (((o->oBehParams >> 16) & 0xFF) * 25.0f)) * sins(o->oMoveAngleYaw) * sins(o->o100);
                o->oPosZ = 274.0f + ((2500.0f + (((o->oBehParams >> 16) & 0xFF) * 25.0f)) * coss(o->oMoveAngleYaw) * sins(o->o100)); 
                if (o->o100 > 0x8000) {
                    o->oTimer = 0;
                    o->o100 = 0;
                    o->oFC = CL_RandomMinMaxU16(0x90, 0x300);
                    obj_become_intangible();
                }
            }

            break;
        case 8:
            o->oF8 += o->oF4;
            o->oPosX = approach_f32(o->oPosX, o->oFloat100, 80.0f, 80.0f);
            o->oPosY = approach_f32(o->oPosY, o->oFloat104, 80.0f, 80.0f);
            o->oPosZ = approach_f32(o->oPosZ, o->oFloat108, 80.0f, 80.0f);
            if (o->oPosX == o->oFloat100 && o->oPosY == o->oFloat104 && o->oPosZ == o->oFloat108) {
                o->oOpacity = 255;
                o->oAction = 2;
            }
            break;

    }
    o->oInteractStatus = 0;
}



void bhv_boss_gate_loop(void) {
    o->oPosY = approach_f32(o->oPosY, sGatePosition[o->oAction], 50.0f, 50.0f);
}



void bhv_boss_flame_init(void) {
    o->oForwardVel = 40.0f;
    o->oMoveAngleYaw = angle_to_object(o, gMarioObject);
    set_object_hitbox(o, &sBossFlameHitbox);
    o->oGraphYOffset = 15.0f * o->header.gfx.scale[1];
}


void bhv_boss_flame_loop(void) {
    CL_Move();
    o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x300);
    o->oForwardVel -= 0.07f;
    if (o->oForwardVel <= 30.0f || o->oInteractStatus & INT_STATUS_INTERACTED) {
        o->activeFlags = 0;
        create_sound_spawner(SOUND_OBJ_DEFAULT_DEATH);
    }
    if (o->oPosY < 0)
        o->oPosY = 0;
}

void BossBombExplode(void) {
    struct Object *explosion;
    if (o->oTimer < 5)
        obj_scale(1.0 + (f32) o->oTimer / 5.0);
    else {
        explosion = spawn_object(o, MODEL_EXPLOSION, bhvExplosion);
        explosion->oGraphYOffset += 100.0f;
        o->activeFlags = 0;
    }
}


void bhv_boss_bomb_init(void) {
    o->oMoveAngleYaw = angle_to_object(o, gMarioObject);
    o->oForwardVel  = 50.0f;
    o->oVelY = -15.0f;
}


void bhv_boss_bomb_loop(void) {
    CL_Move();
    o->oFaceAnglePitch += 0xC00;
    if (o->oPosY <= 0) {
        BossBombExplode();
    }

}