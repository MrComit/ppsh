// warp.c.inc
#define INCEL_1 0

#define CUCK_1 1
#define CUCK_2 2
#define CUCK_3 3
#define CUCK_4 4

#define SIMP_1 5
#define SIMP_2 6
#define SIMP_3 7
#define SIMP_4 8
#define SIMP_5 9


Vec3f sDeathII1[3] = {
{-5270.55f, -400.0f, -8138.85f},
{6788.95f, -123.058f, -10970.35f},
{13184.85f, -331.8695f, -6299.35f},
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

Vec3f *sDeaths[] = {
sDeathII1, sDeathCC1, sDeathCC2, sDeathCC3, sDeathCC1, sDeathCC1, sDeathCC1, sDeathCC1, sDeathCC1, sDeathCC1,
};

s16 sDeathCounts[] = {
3, 3, 5, 2, 2, 2, 2, 2, 2, 2,
};

s8 deathwarp_get_list(void) {
    switch (gCurrLevelNum) {
        case LEVEL_BOB:
            if (gCurrAreaIndex == 1)
                return INCEL_1;
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
                    return -1; //MAKE ROOM BASED
                default:
                    return -1;
            }
            break;
        case LEVEL_JRB:
            switch (gCurrAreaIndex) {
                case 1:
                    return -1;
                case 2:
                    return -1;
                case 3:
                    return -1;
                default:
                    return -1;
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
        list = deathwarp_get_list();
        if (list >= 0) {
            point = CL_nearest_point(sDeaths[list], gMarioState->pos, sDeathCounts[list]);
            vec3f_copy(&o->oPosX, point);
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