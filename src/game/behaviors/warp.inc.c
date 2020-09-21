// warp.c.inc
#define INCEL_1 0
#define INCEL_2 1
#define INCEL_3 2
#define INCEL_4 3

#define CUCK_1 4
#define CUCK_2 5
#define CUCK_3 6
#define CUCK_4 7

#define SIMP_1 8
#define SIMP_2 9
#define SIMP_3 10
#define SIMP_4 11
#define SIMP_5 12


Vec3f sDeathCC1[2] = {
{-12488.0f, 680.0f, 12345.0f},
{9443.1f, 680.0f, -4789.11f},
};

Vec3f *sDeaths[] = {
sDeathCC1, sDeathCC1, sDeathCC1, sDeathCC1, sDeathCC1, sDeathCC1, sDeathCC1, 
sDeathCC1, sDeathCC1, sDeathCC1, sDeathCC1, sDeathCC1, sDeathCC1,
};

s16 sDeathCounts[] = {
2, 2, 2, 2, 2, 2, 2,
2, 2, 2, 2, 2, 2,
};

s8 deathwarp_get_list(void) {
    switch (gCurrLevelNum) {
        case LEVEL_BOB:
            return -1;
            break;
        case LEVEL_WF:
            switch (gCurrAreaIndex) {
                case 1:
                    return CUCK_1;
                default:
                    return -1;
            }
            break;
        case LEVEL_JRB:
            return -1;
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