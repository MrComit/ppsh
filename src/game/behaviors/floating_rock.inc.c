void bhv_float_rock_loop(void) {
    s32 i;
    f32 oldPos = o->oPosY;
    //CL_Move();
    //o->oAngleVelYaw = (((o->oBehParams >> 16) & 0xFF00) / 12);
    o->oHomingAmpLockedOn += 0x200;
    o->oPosY = o->oHomeY + (sins((s16)o->oHomingAmpLockedOn + (o->oBehParams2ndByte << 8)) * 200.0);
    o->oVelY = o->oPosY - oldPos;
    if (o->oDistanceToMario < 1500.0f) {
        for (i = 0; i < 3; i++) {
            struct Object *wind = spawn_object(o, MODEL_MIST, bhvWind);
            wind->oMoveAngleYaw = 0;
            wind->oMoveAnglePitch = 1;
            wind->oPosY = o->oHomeY - 200.0f;
    }
    }
}