void mole_npc_act7(void) {
    if (o->oTimer == 0) {
        sDelayedWarpOp = 0x10;
        sDelayedWarpTimer = 12;
        sSourceWarpNodeId = 0xAB;
        func_8024A48C(sSourceWarpNodeId);
        play_transition(1, 0xC, 0x00, 0x00, 0x00);
    }
}


void mole_npc_act5_alt(void) {
    s32 response;
    if (set_mario_npc_dialog(1) == 2) {
        o->activeFlags |= 0x20; /* bit 5 */
        response = cutscene_object_with_dialog(CUTSCENE_RACE_DIALOG, o, o->oBehParams2ndByte);
        if (response != 0)
            set_mario_npc_dialog(0);
        if (response == 1) {
            o->oAction = 7;
            o->activeFlags &= ~0x20; /* bit 5 */
            o->oInteractStatus = 0;
        }
        if (response == 2) {
            o->oAction = 2;
            o->activeFlags &= ~0x20; /* bit 5 */
            o->oInteractStatus = 0;
        }
    }
}



void bhv_mole_npc_loop(void) {

    switch (o->oBehParams >> 24) {
        case 3:
            if (save_file_get_star_flags(gCurrSaveFileNum - 1, 2) & 0x10/* queen mole fight id*/)
                o->activeFlags = 0;
        case 4:
            if (o->oBehParams >> 24 == 4) {
                if (save_file_get_star_flags(gCurrSaveFileNum - 1, 2) & 0x10/* queen mole fight id*/)
                    obj_enable();
                else
                    obj_disable();
            }
        case 0:
        case 1:
        case 2:
            //bhv_bobomb_buddy_loop();
            mole_npc_default_loop();
            break;
    }
}





void mole_spawn_star(f32 x, f32 y, f32 z, s16 param) {
    o->oBehParams = (o->oBehParams << 8) >> 8;
    o->oBehParams |= param << 24;
    create_star(x, y, z);
    o->oBehParams = (o->oBehParams << 8) >> 8;
    o->oBehParams |= 0x10 << 24;
    o->oInteractType = 0x40000000;
    o->oAction = 2;
}


void mole_npc_act6(void) {
    switch (o->oBehParams >> 24) {
        case 1:
            mole_spawn_star(3384.0f, 226.0f, 14622.0f, 0x12);
            break;
        case 2:
            mole_spawn_star(-20353.0f, -239.0f, 2883.0f, 0x10);
            break;

    }
}

void mole_npc_default_loop(void) {
    switch (o->oAction) {
        case 0:
            mole_npc_act0();
            o->oFaceAnglePitch = 0x4000;
            break;
        case 1:
            mole_npc_act1();
            o->oFaceAnglePitch = 0;
            break;
        case 2:
            mole_npc_act2();
            break;
        case 3:
            mole_npc_act3();
            break;
        case 4:
            mole_npc_act4();
            break;
        case 5:
            if (o->oBehParams >> 24 == 4)
                mole_npc_act5_alt();
            else
                mole_npc_act5();
            break;
        case 6:
            mole_npc_act6();
            break;
        case 7:
            mole_npc_act7();
            break;
    }
}


void mole_npc_act0(void) {
    set_obj_animation_and_sound_state(3);
    o->oGraphYOffset = -60.0f;
    if (o->oDistanceToMario < 1500.0f) {
        o->oAction = 1;
        o->oGraphYOffset = 0;
        o->oVelY = 15.0f;
        o->oGravity = -2.0f;
    }
}

void mole_npc_act1(void) {
    obj_move_using_vel_and_gravity();
    if (o->oVelY <= 0.0f) {
        //set_obj_animation_and_sound_state(7);
        //if ((o->header.gfx.unk38.animFrame + 1) == o->header.gfx.unk38.curAnim->unk08) {
        if (o->oPosY <= o->oHomeY) {
            o->oPosY = o->oHomeY;
            o->oAction = 2;
            //set_obj_animation_and_sound_state(3);
        }
    }
}


void mole_npc_act2(void) {
    if (o->oDistanceToMario > 2000.0f) {
        o->oAction = 3;
        o->oVelY = 40.0f;
        o->oGravity = -6.0f;
    }

    o->oBobombBuddyPosXCopy = o->oPosX;
    o->oBobombBuddyPosYCopy = o->oPosY;
    o->oBobombBuddyPosZCopy = o->oPosZ;

    if (o->oDistanceToMario < 1000.0f)
        o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x140);

    if (o->oInteractStatus == INT_STATUS_INTERACTED)
        o->oAction = 4;

}

void mole_npc_act3(void) {
    obj_move_using_vel_and_gravity();
    set_obj_animation_and_sound_state(0);

    o->oFaceAnglePitch = -atan2s(o->oVelY, -4.0f);

    if (o->oPosY <= o->oHomeY) {
        o->oPosY = o->oHomeY;
        o->oAction = 0;
        o->oGravity = 0.0f;
    }
}

void mole_npc_act4(void) {
    s16 sp1e = o->header.gfx.unk38.animFrame;
    if ((sp1e == 5) || (sp1e == 16))
        PlaySound2(SOUND_OBJ_BOBOMB_WALK);

    o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x1000);
    if ((s16) o->oMoveAngleYaw == (s16) o->oAngleToMario) {
        o->oAction = 5;
    }

    PlaySound2(SOUND_ACTION_READ_SIGN);
}

void mole_npc_act5(void) {
    if (set_mario_npc_dialog(1) == 2) {
        o->activeFlags |= 0x20; /* bit 5 */
        if (cutscene_object_with_dialog(CUTSCENE_DIALOG, o, o->oBehParams2ndByte)
        != BOBOMB_BUDDY_BP_STYPE_GENERIC) {
        set_mario_npc_dialog(0);

        o->activeFlags &= ~0x20; /* bit 5 */
        //o->oBobombBuddyHasTalkedToMario = BOBOMB_BUDDY_HAS_TALKED;
        o->oInteractStatus = 0;

        if (o->oBehParams >> 24 == 1 || o->oBehParams >> 24 == 2)
            o->oAction = 6;
        else
            o->oAction = 2;
        }
    }
}