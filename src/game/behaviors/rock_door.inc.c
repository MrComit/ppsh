void bhv_rock_door_init(void) {
    o->header.gfx.scale[1] = 0;
}


void bhv_rock_door_loop(void) {
    struct Object *bswitch = obj_nearest_object_with_behavior(bhvBlueCanyonButton);
    if (bswitch == NULL)
        o->activeFlags = 0;
    switch (o->oAction) {
        case 0:
            if (bswitch->oAction == PURPLE_SWITCH_TICKING)
                o->oAction = 1;
            o->header.gfx.scale[1] = approach_f32(o->header.gfx.scale[1], 1.0, 0.08, 0.08);
            if (o->header.gfx.scale[1] != 1.0)
                PlaySound(SOUND_ENV_METAL_BOX_PUSH);
            break;
        case 1:
            if (bswitch->oAction != PURPLE_SWITCH_TICKING)
                o->oAction = 0;
            o->header.gfx.scale[1] = approach_f32(o->header.gfx.scale[1], 0, 0.08, 0.08);
            if (o->header.gfx.scale[1] != 0)
                PlaySound(SOUND_ENV_METAL_BOX_PUSH);
            break;
    }
}