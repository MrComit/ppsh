#define SECOND_PATH 0xE
#define SECOND_END 0x17

Vec3s sAppearingPos[] = {
{-500, 50, 0},
{0, -100, -750},
{-500, 0, 500},
{500, 100, 250},
{500, -50, -600},
{0, 0, -650},
{-500, -50, 0},
{500, -25, -500},
{-500, -50, 0},
{-500, 0, -500},
{1000, 0, 0},
{-500, 0, 0},
{250, -75, -750},
//second path
{750, 0, 250},
{0, -50, 1000},
{500, -50, -250},
{0, -50, 1000},
{500, 0, 500},
{750, -25, 0},
{-1000, -75, 500},
{250, -50, 1000},
{-750, 0, 750},
};

void bhv_appearing_block_loop(void) {
    struct Object *block;
    //Vec3f *array = sAppearingPos;
    Vec3f additive;
    if (o->oBehParams2ndByte < SECOND_PATH) {
        o->oF4 = 0;
    } else {
        o->oF4 = SECOND_PATH;
    }

    //if (o->oBehParams2ndByte != 0 && o->oBehParams2ndByte != SECOND_PATH) {
    //    if (o->oTimer > 300)
    //        o->activeFlags = 0;
    //}
    switch (o->oAction) {
        case 0:
            if (gMarioObject->platform == o) {
                o->oAction = 1;
                if (o->oBehParams2ndByte != SECOND_PATH - 1 && o->oBehParams2ndByte != SECOND_END) {
                    spawn_object_relative(o->oBehParams2ndByte + 1, sAppearingPos[o->oBehParams2ndByte][0], 
                    sAppearingPos[o->oBehParams2ndByte][1], sAppearingPos[o->oBehParams2ndByte][2], 
                    o, MODEL_SIMP_MAROON_BLOCK, bhvAppearingBlock);
                } else {
                    play_sound(SOUND_GENERAL2_RIGHT_ANSWER, gDefaultSoundArgs);
                }
                if (o->parentObj != NULL && o->parentObj->oBehParams2ndByte != 0 && o->parentObj->oBehParams2ndByte != SECOND_PATH 
                && object_has_behavior(o->parentObj, bhvAppearingBlock))
                    o->parentObj->activeFlags = 0;
            }
            if (o->oTimer > 150 && o->oBehParams2ndByte != 0 && o->oBehParams2ndByte != SECOND_PATH) {
                block = CL_obj_nearest_object_behavior_params(bhvAppearingBlock, o->oF4 << 16);
                block->oAction = 0;
                o->activeFlags = 0;
            }
            break;
        case 1:
            if (o->oTimer > 150 && o->oBehParams2ndByte != 0 && o->oBehParams2ndByte != SECOND_PATH) {
                block = CL_obj_nearest_object_behavior_params(bhvAppearingBlock, o->oF4 << 16);
                block->oAction = 0;
                o->activeFlags = 0;
            }
            break;
    }

}