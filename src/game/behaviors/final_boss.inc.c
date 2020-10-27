//#include "game/object_helpers2.h"
#include "game/save_file.h"
#include "game/camera.h"
void generate_yellow_sparkles(s16 x, s16 y, s16 z, f32 radius);

struct ObjectHitbox sSubwayKoopaHitbox = {
    /* interactType:      */ INTERACT_DAMAGE,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 8,
    /* health:            */ 1,
    /* numLootCoins:      */ 0,
    /* radius:            */ 80,
    /* height:            */ 100,
    /* hurtboxRadius:     */ 80,
    /* hurtboxHeight:     */ 100,
};



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
    /* radius:            */ 130,
    /* height:            */ 100,
    /* hurtboxRadius:     */ 130,
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




s32 gBossReset = 0;

f32 sGatePosition[2] = {1462.11f, 417.249f};

f32 sMoveSpeeds[3] = {20.0f, 20.0f, 30.0f};
s16 sRotateSpeeds[3] = {0x200, 0x280, 0x300};
s32 sToadsDead = 0;

extern Vtx ccm_dl_ArenaRedCircle_001_mesh_vtx_0;

s16 sVertexList[] = {0, 3, 6, 9, 12, 15, 16, 17, 18, 19, 20, 21, 24, 25, 28, 29, 32, 33, 36, 37};

//struct MusicDynamic {
//    /*0x0*/ s16 bits1;
//    /*0x2*/ u16 volScale1;
//    /*0x4*/ s16 dur1;
//    /*0x6*/ s16 bits2;
//    /*0x8*/ u16 volScale2;
//    /*0xA*/ s16 dur2;
//}; // size = 0xC

struct MusicDynamic sFinalBossDynamics[6] = {
    { 0x009B, 127, 5, 0x0064, 0, 5 }, // phase 3
    { 0x00FB, 127, 5, 0x0004, 0, 5 }, // phase 3 (chaos)
};


void final_boss_dynamics(s16 number) {
    s32 i;
    u16 bit = 1;
    for (i = 0; i < 16; i++) {
        if (sFinalBossDynamics[number].bits1 & bit) {
            fade_channel_volume_scale(0, i, sFinalBossDynamics[number].volScale1, sFinalBossDynamics[number].dur1);
        }
        if (sFinalBossDynamics[number].bits2 & bit) {
            fade_channel_volume_scale(0, i, sFinalBossDynamics[number].volScale2, sFinalBossDynamics[number].dur2);
        }
        bit <<= 1;
    }
}





void boss_change_circle_color(u8 r, u8 g, u8 b, s16 speed) {
    s16 i;
    u8 dr, dg, db;
    Vtx *verts = segmented_to_virtual(&ccm_dl_ArenaRedCircle_001_mesh_vtx_0);
    if (verts[0].v.cn[0] == r && verts[0].v.cn[1] == g && verts[0].v.cn[2] == b)
        return;
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
    s32 dialogId;
    switch (o->oAction) {
        case 0:
            boss_change_circle_color(255, 0, 35, 0x10);
            if (o->oDistanceToMario < 500.0f) {
                o->oAction = 1;
                sToadsDead = 0;
                gBossReset = 0;
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
            set_mario_npc_dialog(1);
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
            sequence_player_unlower(0, 60);
            play_music(0, SEQUENCE_ARGS(4, SEQ_FINAL), 0);
            final_boss_dynamics(0);
            if (o->oTimer > 30) {
                o->oAction = 5;
                o->oF8 = 45;
                o->o100 = CL_RandomMinMaxU16(2, 3);
                o->oFC = 0;
                o->oForwardVel = 20.0f;
                o->o104 = 0x200;
            }
            break;
        case 5:
            final_boss_dynamics(0);
            boss_change_circle_color(0, 0, 255, 0x20);
            obj_update_floor_and_walls();
            obj_move_standard(-78);
            o->oMoveAngleYaw = (o->oFaceAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, o->o104));
            if (o->oTimer > o->oF8) {
                spawn_object(o, MODEL_RED_FLAME_SHADOW, bhvBossFlame);
                o->oF8 = CL_RandomMinMaxU16(50, 100);
                o->oTimer = 0;
                o->oFC++;
            }
            if (o->oFC > o->o100) {
                o->oAction = 6;
                o->oFC = 0;
                o->o100 = 4;
                o->oForwardVel = 0;
            }
            break;
        case 6:
            if (sToadsDead == 15)
                o->oAction = 9;
            o->oFaceAngleYaw += 0x2000;
            PlaySound2(SOUND_OBJ_UNKNOWN6_2);
            boss_change_circle_color(255, 80, 0, 0x10);
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
                    o->o108 = 465 - (10 * sToadsDead);
                    o->oFaceAngleYaw = o->oWallAngle + 0x8000;
                    PlaySound2(SOUND_GENERAL_METAL_POUND);
                    PlaySound2(SOUND_OBJ2_KING_BOBOMB_DAMAGE);
                    ShakeScreen(SHAKE_POS_MEDIUM);
                    obj_become_intangible();
                }
            }
            break;
        case 7:
            if (sToadsDead == 15)
                o->oAction = 9;
            final_boss_dynamics(1);
            boss_change_circle_color(0, 255, 0, 0x10);
            o->oOpacity = approach_s16_symmetric(o->oOpacity, 30, 20);
            if (o->oTimer > o->o108) {
                o->oAction = 8;
                obj_become_tangible();
            }
            break;
        case 8:
            if (sToadsDead == 15)
                o->oAction = 9;
            final_boss_dynamics(0);
            boss_change_circle_color(0, 0, 255, 0x10);
            o->oOpacity = approach_s16_symmetric(o->oOpacity, 255, 20);
            if (o->oTimer > 60) {
                o->oAction = 5;
                o->oForwardVel = sMoveSpeeds[sToadsDead / 5];
                o->o104 = sRotateSpeeds[sToadsDead / 5];
                o->oMoveAngleYaw = (o->oFaceAngleYaw = o->oAngleToMario);
            }
            break;
        case 9:
            o->oInteractType = 0x40000000;
            stop_background_music(SEQUENCE_ARGS(4, SEQ_FINAL));
            boss_change_circle_color(0, 255, 220, 0x18);
            o->oOpacity = approach_s16_symmetric(o->oOpacity, 0, 30);
            if (o->oTimer > 60) {
                o->oFaceAngleYaw = 0;
                o->oAction = 10;
                o->oMoveAngleYaw = 0;
                o->oPosX = o->oHomeX;
                o->oPosZ = o->oHomeZ;
                o->oPosY = 1000.0f;
                SetComitCutscene(45, 1, 6);
            }
            break;
        case 10:
            generate_yellow_sparkles(o->oHomeX, o->oPosY, o->oHomeZ, 150.0f);
            PlaySound2(SOUND_AIR_PEACH_TWINKLE);
            o->oOpacity = approach_s16_symmetric(o->oOpacity, 255, 5);
            o->oPosY = approach_f32(o->oPosY, o->oHomeY, 12.0f, 12.0f);
            if (o->oTimer > 100 && o->oDistanceToMario < 300.0f) {
                o->oAction = 11;
            }
            break;
        case 11:
            o->oFaceAngleYaw = approach_s16_symmetric(o->oFaceAngleYaw, o->oAngleToMario, 0x1000);
            if ((s16) o->oFaceAngleYaw == (s16) o->oAngleToMario) {
                if (save_file_get_total_star_count(gCurrSaveFileNum - 1, COURSE_MIN - 1, COURSE_MAX - 1) >= 40)
                    o->oAction = 12;//12;
                else
                    o->oAction = 13;
            }
            break;
        case 12: //good ending
            if(CL_NPC_Dialog(DIALOG_167)) {
                o->oAction = 14;
                level_trigger_warp(gMarioState, WARP_OP_CREDITS_END);
            }
            break;
        case 13: //bad ending
            if(CL_NPC_Dialog(DIALOG_166)) {
                o->oAction = 15;
                obj = spawn_object(o, MODEL_SUBWAY_KOOPA, bhvEndingSubwayKoopa);
                obj->oPosX = 0;
                obj->oPosY = 1000.0f;
                obj->oPosZ = 3000.0f;
                SetComitCutscene(45, 1, 7);
                set_mario_npc_dialog(1);
            }
            break;
        case 14:
            break;
        case 15:
            break;
    }
    o->oInteractStatus = 0;

    if (gBossReset == 1) {
        o->oAction = 0;
        vec3f_copy(&o->oPosX, &o->oHomeX);
        o->oF4 = 0;
        o->oF8 = 0;
        o->oFC = 0;
        o->o100 = 0;
        o->o104 = 0;
        o->o108 = 0;
        o->oOpacity = 255;
        o->oMoveAngleYaw = (o->oFaceAngleYaw = 0);
        sToadsDead = 0;
        set_obj_animation_and_sound_state(11);
        obj_scale(1.0f);
        obj_become_intangible();
    }
}


void bhv_toad_minion_init(void) {
    set_object_hitbox(o, &sToadMinionHitbox);
    obj_become_intangible();
    o->oFriction = 1.0f;
    o->oF8 = (0x10000 / 5) * (o->oBehParams >> 24);
    o->oPosY = o->parentObj->oPosY + (((o->oBehParams >> 16) & 0xFF) * 80.0f);
    o->oPosX = o->parentObj->oPosX + ((50.0f + (((o->oBehParams >> 16) & 0xFF) * 25.0f)) * sins(o->oF8));
    o->oPosZ = o->parentObj->oPosZ + ((50.0f + (((o->oBehParams >> 16) & 0xFF) * 25.0f)) * coss(o->oF8));
    o->oMoveAngleYaw = o->oF8 - 0x1555;

    if (save_file_get_console_mode()) {
        obj_set_model(MODEL_LOD_SIMP_TOAD);
    } else {
        obj_set_model(MODEL_SIMP_TOAD);
    }

}


void bhv_toad_minion_loop(void) {
    if (gBossReset == 1)
        o->activeFlags = 0;
    if (sToadsDead == 15)
        o->activeFlags = 0;
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
            if (save_file_get_console_mode() && sToadsDead < 10) {
                if (absi((s16)(o->oMoveAngleYaw - 0x1555) - (s8DirModeYawOffset + 0x4000)) < 0x3000) {
                    obj_hide();
                } else {
                    obj_unhide();
                }
            }
            if (o->parentObj->oAction == 6)
                o->oF4 = 0xC00;
            else
                o->oF4 = 0x300;
            o->oF8 += o->oF4;
            o->oMoveAngleYaw = o->oF8 - 0x1555;
            o->oPosX = o->parentObj->oPosX + ((50.0f + (((o->oBehParams >> 16) & 0xFF) * 25.0f)) * sins(o->oF8));
            o->oPosZ = o->parentObj->oPosZ + ((50.0f + (((o->oBehParams >> 16) & 0xFF) * 25.0f)) * coss(o->oF8));

            if (o->parentObj->oAction == 7) {
                obj_unhide();
                o->oAction = 3;
                o->oForwardVel = 40.0f;
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
                o->oForwardVel = 10.0f;
                PlaySound2(SOUND_GENERAL_BOING2_LOWPRIO);
            }
            if (o->oMoveFlags & OBJ_MOVE_HIT_WALL) {
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
                o->oInteractType = INTERACT_DAMAGE;
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
                    //o->oAction = 7;
                    o->oFaceAnglePitch = 0;
                    o->oF4 = 0x80;
                    o->oFC = CL_RandomMinMaxU16(0x90, 0x300);
                    o->o100 = 0;
                }
            }
            break;
        case 5:
            o->oF8 += o->oF4;
            o->oMoveAngleYaw = o->oF8 + 0x6AAB;
            o->oPosX = (2500.0f + (((o->oBehParams >> 16) & 0xFF) * 25.0f)) * sins(o->oF8);
            o->oPosZ = 274.0f + ((2500.0f + (((o->oBehParams >> 16) & 0xFF) * 25.0f)) * coss(o->oF8));
            if (o->oTimer > o->oFC) {
                spawn_object(o, MODEL_RED_FLAME_SHADOW, bhvBossFlame);
                o->oTimer = 0;
                o->oFC = CL_RandomMinMaxU16(0x100, 0x380);
            }
            break;
        case 6:
            o->oF8 += o->oF4;
            o->oMoveAngleYaw = o->oF8 + 0x6AAB;
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
                o->oOpacity = approach_s16_symmetric(o->oOpacity, 80, 20);
                o->oF8 += o->oF4;
                o->oMoveAngleYaw = o->oF8 + 0x6AAB;
                o->oPosX = 2550.0f * sins(o->oF8);
                o->oPosZ = 274.0f + (2550.0f * coss(o->oF8));
            } else {
                o->oOpacity = approach_s16_symmetric(o->oOpacity, 200, 20);
                obj_become_tangible();
                o->o100 += 0x200;
                o->oPosY = 30.0f + (330.0f * absf(coss(o->o100)));
                o->oPosX += 80.0f * sins(o->oMoveAngleYaw + 0x1555);
                o->oPosZ += 80.0f * coss(o->oMoveAngleYaw + 0x1555);
                if (o->o100 > 0x8000) {
                    o->oTimer = 0;
                    o->o100 = 0;
                    o->oF8 += 0x8000;
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

    if (gBossReset == 1)
        o->oAction = 0;
}



void bhv_boss_flame_init(void) {
    o->oForwardVel = 32.0f;
    o->oMoveAngleYaw = angle_to_object(o, gMarioObject);
    set_object_hitbox(o, &sBossFlameHitbox);
    o->oGraphYOffset = 15.0f * o->header.gfx.scale[1];
}


void bhv_boss_flame_loop(void) {
    CL_Move();
    o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x300);
    o->oForwardVel -= 0.04f;
    if (o->oForwardVel <= 27.0f || o->oInteractStatus & INT_STATUS_INTERACTED) {
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

s32 subway_anim_ended(s32 arg0) {
    set_obj_animation_and_sound_state(arg0);
    return func_8029F788();
}


void bhv_subway_ending_init(void) {
    set_object_hitbox(o, &sSubwayKoopaHitbox);
    o->oMoveAngleYaw = 0x8000;
}



void bhv_subway_ending_loop(void) {
    switch(o->oAction) {
        case 0:
            o->oPosY = approach_f32(o->oPosY, 0, 35.0f, 35.0f);
            if (o->oPosY <= 60.0f) {
                if(subway_anim_ended(13)) {
                    set_obj_animation_and_sound_state(7);
                    o->oPosY = 0;
                    o->oAction = 1;
                }
            }
            break;
        case 1:
            if (o->oTimer > 25) {
                if (CL_NPC_Dialog(DIALOG_126)) {
                    o->oAction = 2;
                    o->oForwardVel = 55.0f;
                    set_obj_animation_and_sound_state(1);
                    sequence_player_unlower(0, 60);
                    play_music(0, SEQUENCE_ARGS(4, SEQ_EVENT_BOSS), 0);
                    gBossReset = 2;
                }
            }
            break;
        case 2:
            CL_Move();
            o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x400);
            break;
    }
    o->oInteractStatus = 0;
}