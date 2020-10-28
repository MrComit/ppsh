// warp.c.inc
#define INCEL_1 0

#define CUCK_1 1
#define CUCK_2 2
#define CUCK_3 3
#define CUCK_4 4
#define CUCK_5 5
#define CUCK_6 6

#define SIMP_1 7
#define SIMP_2 8
#define SIMP_3 9
#define SIMP_4 10

#define BOSS_1 11
#define BOSS_2 12

Vec3f sDeathII1[4] = {
{-5270.55f, -400.0f, -8138.85f},
{6788.95f, -123.058f, -10970.35f},
{13184.85f, -331.8695f, -6299.35f},
{11411.65f, -421.18f, 296.6155f},
};

Vec3f sDeathCC1[3] = {
{-12488.0f, 680.0f, 12345.0f},
{9443.1f, 680.0f, -4789.11f},
{-14252.05f, 680.0f, -8461.6f},
};

Vec3f sDeathCC2[5] = {
{-15270.3f, 2514.51f, 2636.835f},
{-9002.0f, 2514.51f, -12019.7f},
{-811.485f, 2514.51f, 11894.55f},
{153.1105f, 2514.51f, 1173.525f},
{10932.7f, 2514.51f, 6671.9f},
};

Vec3f sDeathCC3[2] = {
{1822.81f, 4496.175f, 8413.2f},
{768.32f, 4496.175f, -6436.3f},
};

Vec3f sDeathCC4 = {-3970.88f, 300.0f, 5394.95f};

Vec3f sDeathCC5 = {-10127.3f, 300.0f, -7320.6f};

Vec3f sDeathCC6 = {13788.05f, 300.0f, 4825.755f};

Vec3f sDeathSC1[10] = {
{0.0f, -9040.85f, 26663.3f},
{0.0f, -9596.6f, 12792.9f},
{0.0f, -9596.6f, -4116.185f},
{-7080.05f, -9596.6f, 10365.55f},
{7299.05f, -9596.6f, 13629.25f},
{-21637.45f, -9596.6f, -4277.165f},
{17902.6f, -9057.9f, -8308.05f},
{15364.9f, -2640.305f, 21893.15f},
{-11427.95f, 441.284f, 2449.365f},
{5380.0f, 1430.255f, -4067.47f},
};

Vec3f sDeathSC2 = {-12326.1f, 16339.35f, 22082.35f};

Vec3f sDeathSC3 = {-25153.45f, -5709.25f, -17227.8f};

Vec3f sDeathSC4 = {576.245f, 13322.1f, -14205.7f};

Vec3f sDeathB1 = {-8.8677f, 1916.0f, 17267.5f};

Vec3f sDeathB2 = {0.0f, 300.0f, 4000.0f};


Vec3f sCheckpointSC[3] = {
{-21702.15f, -1674.04f, 19317.15f},
{-12833.8f, -1674.04f, 8403.75f},
{-1634.05f, -1674.04f, 2137.22f},
};

s16 sCheckPointAngleSC[3] = {0x8000, 0x4000, 0x4000};



Vec3f *sDeaths[] = {
sDeathII1, sDeathCC1, sDeathCC2, sDeathCC3, sDeathCC4, sDeathCC5, sDeathCC6, sDeathSC1, sDeathSC2, sDeathSC3, sDeathSC4,
sDeathB1, sDeathB2,
};

s16 sDeathCounts[] = {
4, 3, 5, 2, 1, 1, 1, 10, 1, 1, 1, 1, 1,
};

s8 deathwarp_get_list(void) {
    switch (gCurrLevelNum) {
        case LEVEL_BOB:
            if (gCurrAreaIndex == 1) {
                return INCEL_1;
            }
            return -1;
            break;
        case LEVEL_WF:
            switch (gCurrAreaIndex) {
                case 1:
                    if (gMarioState->pos[1] < 1800.0f)
                        return CUCK_1;
                    if (gMarioState->pos[1] < 3650.0f)
                        return CUCK_2;
                    return CUCK_3;
                case 2:
                    return CUCK_3 + gMarioCurrentRoom;
                default:
                    return -1;
            }
            break;
        case LEVEL_JRB:
            switch (gCurrAreaIndex) {
                case 1:
                    if (gMarioState->pos[1] < 4200.0f)
                        return SIMP_1;
                    else
                        return SIMP_4;
                case 3:
                    if (gMarioState->pos[2] > 0.0f)
                        return SIMP_2;
                    else
                        return SIMP_3;
                default:
                    return -1;
            }
            break;
        case LEVEL_CCM:
            if (gMarioState->pos[2] < 4500.0f) {
                return BOSS_2;
            } else {
                return BOSS_1;
            }
            break;
        default:
            return -1;
            break;
    }
}


void bhv_deathwarp_loop(void) {
    s8 list;
    Vec3f *point;
    if (gMarioState->pos[1] <= gMarioState->floorHeight) {
        if (gCurrLevelNum == LEVEL_JRB && gCurrAreaIndex == 5) {
            switch (o->oAction) {
                case 0:
                    vec3f_copy(&o->oPosX, sCheckpointSC[0]);
                    o->oFaceAngleYaw = sCheckPointAngleSC[0];

                    if (gMarioState->pos[2] < 9500.0f && gMarioState->pos[0] > -14000.0f) {
                        o->oAction = 1;
                    }
                    break;
                case 1:
                    vec3f_copy(&o->oPosX, sCheckpointSC[1]);
                    o->oFaceAngleYaw = sCheckPointAngleSC[1];

                    if (gMarioState->pos[2] < 4000.0f && gMarioState->pos[0] > -3000.0f) {
                        o->oAction = 2;
                    }
                    break;
                case 2:
                    vec3f_copy(&o->oPosX, sCheckpointSC[2]);
                    o->oFaceAngleYaw = sCheckPointAngleSC[2];


                    break;
            }
        } else {
            list = deathwarp_get_list();
            if (list >= 0) {
                if (sDeathCounts[list] > 1)
                    point = CL_nearest_point(sDeaths[list], gMarioState->pos, sDeathCounts[list]);
                else
                    point = sDeaths[list][0];
                vec3f_copy(&o->oPosX, point);
            }
        }
    }
}



void bhv_warp_loop(void) {
    u16 sp6;
    if (o->oTimer == 0) {
        sp6 = (o->oBehParams >> 24) & 0xFF;
        if (sp6 == 0)
            o->hitboxRadius = 50.0f;
        else if (sp6 == 0xFF)
            o->hitboxRadius = 10000.0f;
        else
            o->hitboxRadius = sp6 * 10.0;
        o->hitboxHeight = 50.0f;
    }
    o->oInteractStatus = 0;

    if ((((o->oBehParams >> 8) & 0xFF) != 0) && obj_has_behavior(bhvWarpPipe)) {
        if ((o->oTimer > 20) && o->oPosY > o->oHomeY - 250.0f) {
            o->oPosY -= 10.0f;
        }
    }
}

void BehFadingWarpLoop() // identical to the above function except for o->hitboxRadius
{
    u16 sp6;
    if (o->oTimer == 0) {
        sp6 = (o->oBehParams >> 24) & 0xFF;
        if (sp6 == 0)
            o->hitboxRadius = 85.0f;
        else if (sp6 == 0xFF)
            o->hitboxRadius = 10000.0f;
        else
            o->hitboxRadius = sp6 * 10.0;
        o->hitboxHeight = 50.0f;
    }
    o->oInteractStatus = 0;
}