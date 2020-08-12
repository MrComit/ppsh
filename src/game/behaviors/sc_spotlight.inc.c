void bhv_spotlight_loop(void) {
    struct MarioState *m = gMarioState;
    f32 mag = ((o->oBehParams >> 24) & 0xFF) * 16.0f;
    f32 dist;
    s32 variable = (o->oBehParams >> 8) & 0xFF;

    switch (o->oAction) {
        case 0:
            if (variable != 1)
                o->oMoveAngleYaw = o->oFaceAngleYaw + 0x4000;
            o->oHomingAmpLockedOn += 0x200;
            o->oPosX = o->oHomeX + (sins((s16)o->oHomingAmpLockedOn + (o->oBehParams2ndByte << 8)) * mag) * sins(o->oMoveAngleYaw);
            o->oPosZ = o->oHomeZ + (sins((s16)o->oHomingAmpLockedOn + (o->oBehParams2ndByte << 8)) * mag) * coss(o->oMoveAngleYaw);
            dist = lateral_dist_between_objects(o, gMarioObject);
            if (dist < 320.0f && absf(m->pos[1] - o->oPosY) < 500.0f) {
                if (variable != 1)
                    o->oAction = 1;
                else
                    o->oAction = 2;
                m->floorHeight = m->pos[1];
                check_lava_boost(m);
            }
            break;
        case 1:
            if (o->oTimer > 60)
                o->oAction = 0;
            break;
        case 2:
            o->oHomingAmpLockedOn += 0x200;
            o->oPosX = o->oHomeX + (sins((s16)o->oHomingAmpLockedOn + (o->oBehParams2ndByte << 8)) * mag) * sins(o->oMoveAngleYaw);
            o->oPosZ = o->oHomeZ + (sins((s16)o->oHomingAmpLockedOn + (o->oBehParams2ndByte << 8)) * mag) * coss(o->oMoveAngleYaw);
            if (o->oTimer > 60)
                o->oAction = 0;
            break;
    }
}