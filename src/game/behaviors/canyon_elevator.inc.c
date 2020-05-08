extern u16 gRedSwitchesPushed;

void bhv_canyon_elevator_loop(void) {
struct Object *gswitch = obj_nearest_object_with_behavior(bhvCanyonButton);
    o->oPosY += o->oVelY;
    switch(o->oAction) {
        case 0:
            obj_hide();
            o->oMoveAngleYaw = o->oFaceAngleYaw + 0x12B9;
            if (o->oBehParams2ndByte == 0) {
                //if (save_file_get_star_flags(gCurrSaveFileNum - 1, 1) & 0x10/* grey button star id*/)
                    o->oAction = 1;
                    o->oForwardVel = 10.0f;
                if (gswitch != NULL && gswitch->oAction == 1) {
                    o->oAction = 1;
                    o->oForwardVel = 10.0f;
                }
            } else {
                //if (save_file_get_star_flags(gCurrSaveFileNum - 1, 2) & 0x4/* red button star id*/)
                    o->oAction = 1;
                    o->oForwardVel = 10.0f;
                if (gRedSwitchesPushed >= 5) {
                    o->oAction = 1;
                    o->oForwardVel = 10.0f;
                }
            }
            break;
        case 1:
            obj_unhide();
            CL_Move();
            PlaySound(SOUND_ENV_METAL_BOX_PUSH);
            if (o->oTimer > 100) {
                //play_puzzle_jingle();
                o->oAction = 2;
                o->oForwardVel = 0;
                o->oVelX = 0;
                o->oVelY = 0;
                o->oVelZ = 0;
                //o->oMoveAngleYaw = 0;
            }
            break;
        case 2:
            o->oPosY = o->oHomeY;
            if (o->oDistanceToMario < 4000.0f) {
                if (gMarioObject->platform == o || 
                    absi(o->oHomeY - gMarioObject->oPosY) > absi((o->oHomeY + 1852.0f) - gMarioObject->oPosY)) {
                    o->oAction = 3;
                    o->oVelY = 20.0f;
                }
            }
            break;
        case 3:
            PlaySound(SOUND_ENV_ELEVATOR1);
            if (o->oPosY > o->oHomeY + 1852.0f) {
                o->oPosY = o->oHomeY + 1852.0f;
                o->oAction = 4;
                o->oVelY = 0;
                ShakeScreen(SHAKE_POS_SMALL);
                PlaySound2(SOUND_GENERAL_METAL_POUND);
            }
            break;
        case 4:
            if (gMarioObject->platform != o)
                o->oAction = 5;
            break;
        case 5:
            o->oPosY = o->oHomeY + 1852.0f;
            if (o->oDistanceToMario < 4000.0f) {
                if (gMarioObject->platform == o || 
                    absi(o->oHomeY - gMarioObject->oPosY) < absi((o->oHomeY + 1852.0f) - gMarioObject->oPosY)) {
                    o->oAction = 6;
                    o->oVelY = -20.0f;
                }
            }
            break;
        case 6:
            PlaySound(SOUND_ENV_ELEVATOR1);
            if (o->oPosY < o->oHomeY) {
                o->oPosY = o->oHomeY;
                o->oAction = 7;
                o->oVelY = 0;
                ShakeScreen(SHAKE_POS_SMALL);
                PlaySound2(SOUND_GENERAL_METAL_POUND);
            }
            break;
        case 7:
            if (gMarioObject->platform != o)
                o->oAction = 2;
            break;
    }
}