void bhv_construction_loop(void) {

    o->oFaceAngleYaw = o->oFaceAngleYaw & 0xFFFF;
    o->oHiddenStarTriggerCounter = o->oHiddenStarTriggerCounter & 0xFFFF;


    switch (o->oAction) {
        case 0:
            PlaySound(SOUND_ENV_ELEVATOR1);
            o->oAngleVelYaw = 0xE0;
            o->oFaceAngleYaw = approach_s16_symmetric((s16)o->oFaceAngleYaw, (s16)o->oHiddenStarTriggerCounter, 0xE0);
            //o->oFaceAngleYaw = (approach_s32((s16)o->oFaceAngleYaw, (s16)o->oHiddenStarTriggerCounter, 0x200, -0x200));
            if ((s16)o->oFaceAngleYaw == (s16)o->oHiddenStarTriggerCounter) {
                o->oAction = 1;
                o->oAngleVelYaw = 0;
            }
            break;
        case 1:
            if (o->oTimer > 30) {
                o->oAction = 0;
                o->oHiddenStarTriggerCounter = (o->oFaceAngleYaw + 0x4000) & 0xFFFF;
            }
            break;
    }



//PlaySound(SOUND_ENV_METAL_BOX_PUSH);
}