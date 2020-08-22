/*s32 bounce_box_oscillate(f32 *value, f32 *vel, f32 target, f32 threshold, f32 *accel, f32 deccel, f32 accelthresh) {
    if (*value < target - threshold) {
        *vel += *accel;
    } else if (*value > target + threshold) {
        *vel -= *accel * 1.05f;;
    } 
    if (*value > target - threshold && *value < target + threshold && *accel < accelthresh)
        return TRUE;
    *value += *vel;
    *accel *= deccel;
    return FALSE;
}*/

void bhv_bounce_box_loop(void) {
    struct MarioState *m = gMarioState;
    switch (o->oAction) {
        case 0:
            if (gMarioObject->platform == o) {
                o->oAction = 1;
            }
            break;
        case 1:
            if (approach_f32_ptr(&o->header.gfx.scale[1], 0.5f, 0.25f)) {
                set_mario_action(m, ACT_CUTSCENE_JUMP, 1);
                m->vel[1] = 10.0f * o->oBehParams2ndByte;
                m->faceAngle[1] = (m->angleVel[1] = o->oFaceAngleYaw + 0xC000);
                mario_set_forward_vel(m, 15.0f);
                o->oAction = 2;
                //o->oFloatF4 = 0.02f;
                //o->oFloatF8 = 0.05f;
            }
            break;
        case 2:
            if (approach_f32_ptr(&o->header.gfx.scale[1], 1.25f, 0.2f)) {
                o->oAction = 3;
            }

            if (gMarioObject->platform == o) {
                o->header.gfx.scale[1] = 1.0f;
                o->oAction = 1;
            }
            break;
        case 3:
            if (approach_f32_ptr(&o->header.gfx.scale[1], 1.0f, 0.2f)) {
                o->header.gfx.scale[1] = 1.0f;
                o->oAction = 0;
            }

            if (gMarioObject->platform == o) {
                o->header.gfx.scale[1] = 1.0f;
                o->oAction = 1;
            }
            break;
    }
}