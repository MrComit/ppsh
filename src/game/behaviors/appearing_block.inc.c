#define SECOND_PATH 0xE
#define SECOND_END 0x17

Vec3f sAppearingPos[] = {
{-500.0f, 50.0f, 0.0f},
{0.0f, -100.0f, -750.0f},
{-500.0f, 0.0f, 500.0f},
{500.0f, 100.0f, 250.0f},
{500.0f, -50.0f, -600.0f},
{0.0f, 0.0f, -650.0f},
{-500.0f, -50.0f, 0.0f},
{500.0f, -25.0f, -500.0f},
{-500.0f, -50.0f, 0.0f},
{-500.0f, 0.0f, -500.0f},
{1000.0f, 0.0f, 0.0f},
{-500.0f, 0.0f, 0.0f},
{250.0f, -75.0f, -750.0f},
//second path
{750.0f, 0.0f, 250.0f},
{0.0f, -50.0f, 1000.0f},
{500.0f, -50.0f, -250.0f},
{0.0f, -50.0f, 1000.0f},
{500.0f, 0.0f, 500.0f},
{750.0f, -25.0f, 0.0f},
{-1000.0f, -75.0f, 500.0f},
{250.0f, -50.0f, 1000.0f},
{-750.0f, 0.0f, 750.0f},
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
            if (o->oTimer > 150 && o->oBehParams2ndByte != 0 && o->oBehParams2ndByte != SECOND_PATH)
                o->activeFlags = 0;
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